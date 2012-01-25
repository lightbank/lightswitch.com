<?php

/**
 * Form builder: client, credit card, shoot date
 */
function bxdev_payment_project_client_credit_card_form($form, &$form_state){
	
	// client selection
	$form += bxdev_payment_client_selection_form_markup($form_state);
	
	$form['project_type'] = array(
		'#type' => 'select',
		'#title' => t('Project type'),
		'#options' => array(
			'299' => 'Standard video - $299',
			'399' => 'Video with interview - $399',
			'449' => 'Video with voice over - $449',
			'' => 'Custom',
		),
		'#default_value' => '299',
	);
	
	// credit card input
	$form += bxdev_payment_cc_form_markup($form_state);
	
	// shoot date
	$form += bxdev_project_shoot_date_form_markup();
	
	$form['continue'] = array(
	  '#type' => 'submit',
	  '#value' => t('Continue >'),
		'#weight' => 50,
	);
	
	return $form;
}

/**
 * Form validation: client, credit card, shoot date
 */
function bxdev_payment_project_client_credit_card_form_validate($form, &$form_state){
	$values = $form_state['values'];
	// dpm($values);
	
	// if neither an existing or new client has been entered
	if($values['existing_client'] == '_none' && empty($values['new_client_email'])){
		form_set_error('existing_email', 'You must select an existing Client or add a new one');
		
	// if a new client email has been entered
	}else if(!empty($values['new_client_email'])){
		
		// if client email is not a valid email address
		if(!valid_email_address($values['new_client_email'])){
			form_set_error('new_client_email', 'Enter a valid Client email address');
		}
		
		// if client email already exists
		if(user_load_by_name($values['new_client_email'])){
			form_set_error('new_client_email', 'Client user ' . $values['new_client_email'] . ' already exists');
		}
		
		// if client full name was not entered
		if(empty($values['new_client_name'])){
			form_set_error('new_client_name', 'When adding a new Client, the full name must be entered');
		}
		
		// if client phone was not entered
		if(empty($values['new_client_phone'])){
			form_set_error('new_client_phone', 'When adding a new Client, the phone must be entered');
		}		
		
	}
}

/**
 * Form submit: client, credit card, shoot date
 */
function bxdev_payment_project_client_credit_card_form_submit($form, &$form_state){

	require('AuthnetCIM.class.php');
	$cim = new AuthnetCIM('2hQT4t8ua', '3bNDCu4r334K9327', TRUE);
	
	$values = $form_state['values'];
	$cc_number = $values['cc_number'];
	$cc_expiry = $values['cc_expiry_year'] . '-' . $values['cc_expiry_month'];
	$cc_code = $values['cc_code'];		
	$cc_amount = $values['cc_amount'];
	$shoot_date_start = strtotime($values['bxdev_shoot_date'] . ' ' . $values['bxdev_shoot_time1']);
	$shoot_date_end = !empty($values['bxdev_shoot_time2']) ? strtotime($values['bxdev_shoot_date'] . ' ' . $values['bxdev_shoot_time2']) : '';
		
	// check if existing user
	if($values['existing_client'] != '_none'){
		
		$account = user_load($values['existing_client']);
		$profile_id = '';
		
		/**
		 * STEP 1: Obtain Authorize.net Profile ID.
		 *
		 * First we check if user has an existing Profile ID (stored in our database). If no db value is found, generate a new Profile.
		 */
		
		// query the database
		$result = db_select('users_auth', 'u')
			->fields('u')
			->condition('uid', $account->uid, '=')
			->execute()
			->fetchObject();
		
		// if user does not have a token
		if(empty($result)){
			$cim->setParameter('email', $account->mail);
			$cim->setParameter('merchantCustomerId', $account->uid);			
			$cim->createCustomerProfile();
			
			if($cim->isSuccessful()){				
				$profile_id = $cim->getProfileID();
				db_insert('users_auth')
					->fields(array(
						'uid' => $account->uid,
						'auth_token' => $profile_id,
					))
					->execute();					
				drupal_set_message('User has been stored: ' . $profile_id);					
			}else{				
				drupal_set_message($cim->getResponse(), 'error');				
			}			
			
		// if user has token
		}else{
			$profile_id = $result->auth_token;
		}
		
		/**
		 * STEP 2: Add a credit card
		 */
		
		$cim->setParameter('customerProfileId', $profile_id);
		$cim->setParameter('cardNumber', $cc_number);
		$cim->setParameter('expirationDate', $cc_expiry);
		$cim->setParameter('cardCode', $cc_code);
		$cim->setParameter('billToAddress', '123 Main Street');
		$cim->setParameter('billToZip', '12345');
		$cim->createCustomerPaymentProfile();
		
		if($cim->isSuccessful()){
			
			$payment_id = $cim->getPaymentProfileId();
			drupal_set_message('Payment ID: ' . $cim->getPaymentProfileId());
			
			/**
			 * STEP 3: Authorize the credit card
			 */
			
			$cim->setParameter('customerPaymentProfileId', $payment_id);
			$cim->setParameter('amount', $cc_amount);
			$cim->createCustomerProfileTransaction('profileTransAuthOnly');
			
			// if authorization was successful
			if($cim->isSuccessful()){
				drupal_set_message('Card is good! Auth code: ' . $cim->getAuthCode());
			
			// if authorization failed
			}else{
				form_set_error('cc_number', $cim->getResponse());
				// drupal_set_message($cim->getResponse(), 'error');				
				// drupal_goto('sales/add/cc/' . $account->uid);
			}
						
		}else{
			// dpm($cim->getResponseSummary());
			// drupal_set_message($cim->getResponse(), 'error');
			form_set_error('cc_number', $cim->getResponse());			
			// drupal_goto('sales/add/cc/' . $account->uid);
		}
			
		
	// if new user
	}else{		
		
		/**
		 * STEP 1: create a new Drupal user and get the uid.
		 */
		
		$account = new stdClass();
		$account->is_new = TRUE;
		$account->status = 1;
		$account->name = $values['new_client_email'];
		$account->mail = $values['new_client_email'];
		$account->field_name['und'][0]['value'] = $values['new_client_name'];
		$account->field_phone['und'][0]['value'] = $values['new_client_name'];
		$account->roles = array(2 => 'authenticated user', 7 => 'client');
		
		$account = user_save($account);
		
		$form_state['user_created'] = $account->uid;		
		$form_state['input']['new_client_email'] = '';
		$form_state['input']['new_client_name'] = '';
		$form_state['input']['new_client_phone'] = '';
		$form_state['input']['existing_client'] = $account->uid;
		
		$form_state['rebuild'] = TRUE;
				
		/**
		 * STEP 2: create an Authorize.net CIM Profile using the Drupal user uid
		 */
		
		$cim->setParameter('email', $account->mail);
		$cim->setParameter('merchantCustomerId', $account->uid);			
		$cim->createCustomerProfile();
		
		 // if the Authorize.net Profile was successfully created, store the Profile ID and add a credit card
		if($cim->isSuccessful()){
			
			// get the profile ID	
			$profile_id = $cim->getProfileID();
			// store the profile ID
			db_insert('users_auth')
				->fields(array(
					'uid' => $account->uid,
					'auth_token' => $profile_id,
				))
				->execute();
			
			/**
			 * STEP 3: Add a credit card
			 */
			
			$cim->setParameter('customerProfileId', $profile_id);
			$cim->setParameter('cardNumber', $cc_number);
			$cim->setParameter('expirationDate', $cc_expiry);
			$cim->setParameter('cardCode', $cc_code);
			$cim->setParameter('billToAddress', '123 Main Street');
			$cim->setParameter('billToZip', '12345');
			$cim->createCustomerPaymentProfile();
			
			// if the credit was successfully added, get the Payment ID used to authorize funds
			if($cim->isSuccessful()){
				
				$payment_id = $cim->getPaymentProfileId();
				drupal_set_message('Payment ID: ' . $payment_id);
				
				/**
				 * Step 4: Authorize the credit card
				 */
				
				$cim->setParameter('customerPaymentProfileId', $payment_id);
				$cim->setParameter('amount', $cc_amount);
				$cim->createCustomerProfileTransaction('profileTransAuthOnly');
				
				// if authorization was successful
				if($cim->isSuccessful()){
					drupal_set_message('Card is good! Auth code: ' . $cim->getAuthCode());
					$_SESSION['shoot_date']['start'] = $shoot_date_start;
					$_SESSION['shoot_date']['end'] = $shoot_date_end;
					drupal_goto('sales/add/business/' . $account->uid);
				
				// if authorization failed
				}else{
					drupal_set_message($cim->getResponse(), 'error');				
				}
				
			// if the credit card could not be added, display the error and return to the form, prepopulating
			// the Drupal user created in step 1			
			}else{
				drupal_set_message($cim->getResponse(), 'error');				
			}
					
		}else{				
			drupal_set_message($cim->getResponse(), 'error');			
		}		
				
	}	
}



/**
 * CUSTOM
 */

/**
 * Return credit card form markup
 */
function bxdev_payment_cc_form_markup($form_state){
	
	$form['cc_amount'] = array(
		'#type' => 'textfield',
		'#title' => t('Charge amount'),
		'#maxlength' => 16,
		'#required' => TRUE,
	);
	
	$form['cc_number'] = array(
		'#type' => 'textfield',
		'#title' => t('Credit card number'),
		'#maxlength' => 16,
		'#required' => TRUE,
	);
	
	$form['cc_expiry_month'] = array(
		'#type' => 'select',
		'#title' => t('Expiration date'),
		'#options' => array(
			'_none' => 'Month',
			'01' => '01',
			'02' => '02',
			'03' => '03',
			'04' => '04',
			'05' => '05',
			'06' => '06',
			'07' => '07',
			'08' => '08',
			'09' => '09',
			'10' => '10',
			'11' => '11',
			'12' => '12',
		),
		'#required' => TRUE,
	);
	
	$form['cc_expiry_year'] = array(
		'#type' => 'select',
		'#title' => t('Expiration date'),
		'#options' => array(
			'_none' => 'Year',
			2011 => 2011,
			2012 => 2012,
			2013 => 2013,
			2014 => 2014,
			2015 => 2015,
			2016 => 2016,
			2017 => 2017,
			2018 => 2018,
			2019 => 2019,
			2020 => 2020,
			2021 => 2021,
			2022 => 2022,
		),
		'#required' => TRUE,
	);
	
	$form['cc_code'] = array(
		'#type' => 'textfield',
		'#title' => t('Security code'),
		'#required' => TRUE,
	);
	
	// $form['cc_full_name'] = array(
	// 	'#type' => 'textfield',
	// 	'#title' => t('Full name'),
	// );
	
	return $form;
	
}

/**
 * Return client information form markup
 */
function bxdev_payment_client_selection_form_markup($form_state){
	
	// dpm($form_state);
	
	$uid = $form_state['user_created'];
	
	$values = $form_state['values'];
	
	// generate a list of existing clients
	// get the client references view
	$clients = views_get_view('users');
	$clients->set_display('references_2');
	$clients->execute();
	$options = array();
	$options['_none'] = '- None -';
	foreach($clients->result as $value){
		 $options[$value->uid] = $value->_field_data['uid']['entity']->field_name['und'][0]['value'] . ' - ' . $value->_field_data['uid']['entity']->mail;
	}
	
	$form['new_client_email'] = array(
		'#type' => 'textfield',
		'#title' => t('Client email'),
		'#weight' => -50,
		'#prefix' => !empty($uid) ? '<div class="new-client-wrapper" style="display:none;">' : '<div class="new-client-wrapper" style="display:block;">',
		'#default_value' => !empty($values['new_client_email']) ?  $values['new_client_email'] : '',
	);

	$form['new_client_name'] = array(
		'#type' => 'textfield',
		'#title' => t('Client full name'),
		'#weight' => -49,
	);

	$form['new_client_phone'] = array(
		'#type' => 'textfield',
		'#title' => t('Client phone'),
		'#weight' => -48,
		'#suffix' => '</div>',
		'#description' => t('<a href="" class="new-client-btn">Existing Client</a>'),
	);
		
	$form['existing_client'] = array(
		'#type' => 'select',
		'#options' => $options,
		'#default_value' => ($values['existing_client'] != '_none') ?  $values['existing_client'] : '_none',
		'#description' => t('<a href="" class="new-client-btn">+ Add new Client</a>'),
		'#prefix' => !empty($uid) ? '<div class="existing-client-wrapper" style="display:block;">' : '<div class="existing-client-wrapper" style="display:none;">',
		'#suffix' => '</div>',
	);
	
	// if(!empty($uid)){
	// 	$form['new_client_email']['#value'] = '';
	// 	$form['new_client_name']['#value'] = '';
	// 	$form['new_client_phone']['#value'] = '';
	// 	$form['existing_client']['#value'] = $uid;
	// }
	
	// dpm($form);
	
	return $form;
}

