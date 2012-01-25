<?php

/**
 * Form builder: client, credit card, shoot date
 */
function bxdev_payment_project_client_credit_card_form($form, &$form_state){
	
	require_once(drupal_get_path('module', 'bxdev_payment') . '/anet_php_sdk/AuthorizeNet.php'); // The SDK
	require_once(drupal_get_path('module', 'bxdev_payment') . '/vars.php');
	require_once(drupal_get_path('module', 'bxdev_payment') . '/util.php');
	
	// $processor = new Processor();
	
	// dpm($processor);
	
	// 6359848, 5477083
	
	
	
	// client selection
	$form += bxdev_payment_client_selection_form_markup();
	
	// credit card input
	$form += bxdev_payment_cc_form_markup();
	
	// shoot date
	$form += bxdev_project_shoot_date_form_markup();
	
	$form['continue_>'] = array(
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
	dpm($values);
	
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
	
	// check if existing user
	if($values['existing_client'] != '_none'){
		
		$account = user_load($values['existing_client']);
		
		// check if token has previously been created
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
			$cc_number = $values['cc_number'];
			$cc_expiry = $values['cc_expiry_year'] . '-' . $values['cc_expiry_month'];					
			
			$cim->setParameter('customerProfileId', $result->auth_token);
			$cim->setParameter('cardNumber', $cc_number);
			$cim->setParameter('expirationDate', $cc_expiry);
			$cim->createCustomerPaymentProfile();
			
			if($cim->isSuccessful()){
				drupal_set_message('Payment ID: ' . $cim->getPaymentProfileId());				
			}else{
				dpm($cim->getResponseSummary());
				// drupal_set_message($cim->getResponse(), 'error');				
				drupal_goto('sales/add/cc/' . $account->uid);
			}
			
		}
		
	// if new user
	}else{
		
		// create a new user
		$account = new stdClass();
		$account->is_new = TRUE;
		$account->status = 1;
		$account->name = $values['new_client_email'];
		$account->mail = $values['new_client_email'];
		$account->field_name['und'][0]['value'] = $values['new_client_name'];
		$account->field_phone['und'][0]['value'] = $values['new_client_name'];
		$account->roles = array(2 => 'authenticated user', 7 => 'client');
		
		$account = user_save($account);
		
		$cim->setParameter('email', $account->mail);
		$cim->setParameter('merchantCustomerId', $account->uid);			
		$cim->createCustomerProfile();
		
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
				
			$cc_number = $values['cc_number'];
			$cc_expiry = $values['cc_expiry_year'] . '-' . $values['cc_expiry_month'];					
			
			// attach credit card to profile
			$cim->setParameter('customerProfileId', $profile_id);
			$cim->setParameter('cardNumber', $cc_number);
			$cim->setParameter('expirationDate', $cc_expiry);
			$cim->createCustomerPaymentProfile();
			
			if($cim->isSuccessful()){
				drupal_set_message('Payment ID: ' . $cim->getPaymentProfileId());				
			}else{
				drupal_set_message($cim->getResponse(), 'error');				
				drupal_goto('sales/add/cc/' . $account->uid);
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
function bxdev_payment_cc_form_markup(){
	
	$form['cc']['cc_amount'] = array(
		'#type' => 'textfield',
		'#title' => t('Charge amount'),
		'#maxlength' => 16,
	);
	
	$form['cc']['cc_number'] = array(
		'#type' => 'textfield',
		'#title' => t('Credit card number'),
		'#maxlength' => 16,
	);
	
	$form['cc']['cc_expiry_month'] = array(
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
	);
	
	$form['cc']['cc_expiry_year'] = array(
		'#type' => 'select',
		'#title' => t('Expiration date'),
		'#options' => array(
			'_none' => 'Year',
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
	);
	
	$form['cc']['cc_cvv'] = array(
		'#type' => 'textfield',
		'#title' => t('Security code'),
	);
	
	$form['cc']['cc_full_name'] = array(
		'#type' => 'textfield',
		'#title' => t('Full name'),
	);
	
	return $form;
	
}

/**
 * Return client information form markup
 */
function bxdev_payment_client_selection_form_markup(){
	
	$uid = arg(3);
	
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
		'#default_value' => !empty($uid) ? $uid : '_none',
		'#description' => t('<a href="" class="new-client-btn">+ Add new Client</a>'),
		'#prefix' => !empty($uid) ? '<div class="existing-client-wrapper" style="display:block;">' : '<div class="existing-client-wrapper" style="display:none;">',
		'#suffix' => '</div>',
	);
	
	return $form;
}

