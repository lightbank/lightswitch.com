<?php

require('AuthnetCIM.class.php');

/**
 * Form builder: client, credit card, shoot date
 */
function bxdev_payment_project_client_credit_card_form($form, &$form_state){
	
	// add wrapper markup
	$form['#prefix'] = '<div id="client-form-wrapper">';
	$form['#suffix'] = '</div>';
	
	// if a fresh form, set the default state to "new"
	if(empty($form_state['client_state'])){
		$form_state['client_state'] = 'new';
	}
	
	// client selection
	$form += bxdev_payment_client_selection_form_markup($form_state);
	
	// payment notes
	$form['payment_notes'] = array(
		'#type' => 'textarea',
		'#title' => t('Payment notes'),
		'#default_value' => !empty($form_state['values']['payment_notes']) ? $form_state['values']['payment_notes'] : '',
	);
	
	// project type
	$form['project_type'] = array(
		'#type' => 'select',
		'#title' => t('Project type'),
		'#options' => array(
			'449' => 'Standard video',
			'549' => 'Video with interview',
			'599' => 'Video with voice over',
			'50' => 'Monthly Subscription',
			'custom' => 'Custom Services',
		),
		'#default_value' => '449',
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
	
	$form['#validate'][] = 'bxdev_payment_project_client_credit_card_form_validate';
	
	return $form;
}

/**
 * Form validation: client, credit card, shoot date
 */
function bxdev_payment_project_client_credit_card_form_validate($form, &$form_state){
	$values = $form_state['values'];
	
	// validate email value
	if(!empty($values['new_client_email'])){

		// if client email is not a valid email address
		if(!valid_email_address($values['new_client_email'])){
			form_set_error('new_client_email', 'Enter a valid Client email address');
		}
	
		// if client email already exists
		if(user_load_by_name($values['new_client_email'])){
			form_set_error('new_client_email', 'Client user ' . $values['new_client_email'] . ' already exists');
		}
	
	}
	
	// charge amount
	if(!is_numeric($values['cc_amount'])){
		form_set_error('cc_amount', 'Enter a numeric value for charge amount');
	}
	
	// if new credit card
	if($values['cc_select'] == 'new'){
		
		// credit card number
		if(strlen($values['cc_number']) < 13){
			form_set_error('cc_number', 'Enter a credit card number between 13 and 16 digits');
		}
		
		// credit card expiration month
		if(empty($values['cc_expiry_month'])){
			form_set_error('cc_expiry_month', 'Select a credit card expiration month');
		}
		
		// credit card expiration year
		if(empty($values['cc_expiry_year'])){
			form_set_error('cc_expiry_year', 'Select a credit card expiration year');
		}
		
		// credit card security code
		if(empty($values['cc_code'])){
			form_set_error('cc_code', 'Enter a credit card security code');
		}		
		
	}
		
}

/**
 * Form submit: client, credit card, shoot date
 */
function bxdev_payment_project_client_credit_card_form_submit($form, &$form_state){
	
	global $api_login_id;
	global $transaction_key;
	global $auth_test_mode;
	
	$cim = new AuthnetCIM($api_login_id, $transaction_key, $auth_test_mode);
	
	$values = $form_state['values'];
	$cc_number = $values['cc_number'];
	$cc_expiry = $values['cc_expiry_year'] . '-' . $values['cc_expiry_month'];
	$cc_code = $values['cc_code'];		
	$cc_amount = $values['cc_amount'];
	$shoot_date_start = strtotime($values['bxdev_shoot_date'] . ' ' . $values['bxdev_shoot_time1']);
	$shoot_date_end = !empty($values['bxdev_shoot_time2']) ? strtotime($values['bxdev_shoot_date'] . ' ' . $values['bxdev_shoot_time2']) : '';
	$project_type = $values['project_type'];
	$payment_notes = $values['payment_notes'];
	$line_item_description = $values['cc_description'];
		
	// check if existing user
	if(!empty($values['existing_client'])){
		
		$account = user_load($values['existing_client']);
		$profile_id = '';
		
		$form_state['client_state'] = 'existing';
		$form_state['existing_client'] = $account->uid;
		$form_state['rebuild'] = TRUE;
		
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
			}else{				
				drupal_set_message($cim->getResponse(), 'error');
				return;		
			}			
			
		// if user has token
		}else{
			$profile_id = $result->auth_token;
		}
		
		/**
		 * STEP 2: Store the credit card
		 */
		
		// if new credit card
		if($values['cc_select'] == 'new'){
		
			$cim->setParameter('customerProfileId', $profile_id);
			$cim->setParameter('cardNumber', $cc_number);
			$cim->setParameter('expirationDate', $cc_expiry);
			$cim->setParameter('cardCode', $cc_code);
			$cim->setParameter('validationMode', 'testMode');
			$cim->createCustomerPaymentProfile();
		
			if($cim->isSuccessful()){
			
				$payment_id = $cim->getPaymentProfileId();
				drupal_set_message('Payment ID: ' . $cim->getPaymentProfileId());
				
				$_SESSION['payment']['payment_notes'] = $payment_notes;
				$_SESSION['payment']['shoot_date']['start'] = $shoot_date_start;
				$_SESSION['payment']['shoot_date']['end'] = $shoot_date_end;
				$_SESSION['payment']['payment_id'] = $payment_id;
				$_SESSION['payment']['project_type'] = $project_type;
				$_SESSION['payment']['line_item_description'] = $line_item_description;
				$_SESSION['payment']['cc_amount'] = $cc_amount;
				
				drupal_goto('sales/add/business/' . $values['existing_client']);

				// /**
				//  * STEP 3: Authorize the credit card
				//  */
				// 			
				// $cim->setParameter('customerPaymentProfileId', $payment_id);
				// $cim->setParameter('amount', $cc_amount);
				// $cim->setParameter('invoiceNumber', 'authorization');
				// $cim->setParameter('description', 'Client: ' . $account->field_name['und'][0]['value']);
				// $cim->setParameter('refId', date('m/d/y-G:i:s'));
				// $cim->createCustomerProfileTransaction('profileTransAuthOnly');
				// 			
				// // if authorization was successful
				// if($cim->isSuccessful()){
				// 	drupal_set_message('Card is good! Auth code: ' . $cim->getAuthCode());
				// 	$_SESSION['payment']['payment_notes'] = $payment_notes;
				// 	$_SESSION['payment']['shoot_date']['start'] = $shoot_date_start;
				// 	$_SESSION['payment']['shoot_date']['end'] = $shoot_date_end;
				// 	$_SESSION['payment']['payment_id'] = $payment_id;
				// 	$_SESSION['payment']['project_type'] = $project_type;
				// 	$_SESSION['payment']['line_item_description'] = $line_item_description;
				// 	$_SESSION['payment']['cc_amount'] = $cc_amount;
				// 	drupal_goto('sales/add/business/' . $values['existing_client']);
				// 	
				// 			
				// // if authorization failed
				// }else{
				// 	drupal_set_message($cim->getResponse(), 'error');
				// }
		
			// if adding the card failed				
			}else{
				drupal_set_message($cim->getResponse(), 'error');		
			}
		
		// if existing credit card
		}else if($values['cc_select'] == 'existing'){
			$_SESSION['payment']['payment_notes'] = $payment_notes;
			$_SESSION['payment']['shoot_date']['start'] = $shoot_date_start;
			$_SESSION['payment']['shoot_date']['end'] = $shoot_date_end;
			$_SESSION['payment']['payment_id'] = $values['payment_id'];
			$_SESSION['payment']['project_type'] = $project_type;
			$_SESSION['payment']['line_item_description'] = $line_item_description;
			$_SESSION['payment']['cc_amount'] = $cc_amount;
			drupal_goto('sales/add/business/' . $values['existing_client']);
			
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
		$account->field_phone['und'][0]['value'] = $values['new_client_phone'];
		$account->roles = array(2 => 'authenticated user', 7 => 'client');
		
		$account = user_save($account);
		
		$form_state['client_state'] = 'existing';
		$form_state['existing_client'] = $account->uid;
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
			$cim->setParameter('validationMode', 'testMode');
			$cim->createCustomerPaymentProfile();
			
			// if the credit was successfully added, get the Payment ID used to authorize funds
			if($cim->isSuccessful()){
				
				$payment_id = $cim->getPaymentProfileId();
				drupal_set_message('Payment ID: ' . $payment_id);
				
				$_SESSION['payment']['payment_notes'] = $payment_notes;
				$_SESSION['payment']['shoot_date']['start'] = $shoot_date_start;
				$_SESSION['payment']['shoot_date']['end'] = $shoot_date_end;
				$_SESSION['payment']['payment_id'] = $payment_id;
				$_SESSION['payment']['project_type'] = $project_type;
				$_SESSION['payment']['line_item_description'] = $line_item_description;
				$_SESSION['payment']['cc_amount'] = $cc_amount;				

				drupal_goto('sales/add/business/' . $account->uid);

				// /**
				//  * Step 4: Authorize the credit card
				//  */
				// 
				// $cim->setParameter('customerPaymentProfileId', $payment_id);
				// $cim->setParameter('amount', $cc_amount);
				// $cim->setParameter('invoiceNumber', 'authorization');
				// $cim->setParameter('description', 'Client: ' . $account->field_name['und'][0]['value']);
				// $cim->setParameter('refId', date('m/d/y-G:i:s'));
				// $cim->createCustomerProfileTransaction('profileTransAuthOnly');
				// 
				// // if authorization was successful
				// if($cim->isSuccessful()){
				// 	drupal_set_message('Card is good! Auth code: ' . $cim->getAuthCode());
				// 	$_SESSION['payment']['payment_notes'] = $payment_notes;
				// 	$_SESSION['payment']['shoot_date']['start'] = $shoot_date_start;
				// 	$_SESSION['payment']['shoot_date']['end'] = $shoot_date_end;
				// 	$_SESSION['payment']['payment_id'] = $payment_id;
				// 	$_SESSION['payment']['project_type'] = $project_type;
				// 	$_SESSION['payment']['line_item_description'] = $line_item_description;
				// 	$_SESSION['payment']['cc_amount'] = $cc_amount;
				// 	drupal_goto('sales/add/business/' . $account->uid);
				// 
				// // if authorization failed
				// }else{
				// 	drupal_set_message($cim->getResponse(), 'error');				
				// }
				
			// if the credit card could not be added, display the error and return to the form, prepopulating
			// the Drupal user created in step 1			
			}else{
				drupal_set_message($cim->getResponse(), 'error');				
			}
		
		// if the Authorize.net Profile was not successfully created	
		}else{				
			drupal_set_message($cim->getResponse(), 'error');			
		}		
				
	}	
}

/**
 * Form submit: show existing clients
 */
function bxdev_payment_add_existing_client_submit($form, &$form_state){
	$form_state['client_state'] = 'existing';
	$form_state['rebuild'] = TRUE;
}

/**
 * Form submit: show new client
 */
function bxdev_payment_add_new_client_submit($form, &$form_state){
	$form_state['client_state'] = 'new';
	$form_state['rebuild'] = TRUE;
}

/**
 * Form builder: project payment
 */
function bxdev_payment_project_payment_form($form, &$form_state, $node){
	
	$project = new Project($node->nid);
	
	// project type
	$form['project_type'] = array(
		'#type' => 'select',
		'#title' => t('Project type'),
		'#options' => array(
			'449' => 'Standard video - $449',
			'549' => 'Video with interview - $549',
			'599' => 'Video with voice over - $599',
			'50' => 'Monthly subscription',
			'custom' => 'Custom',
		),
		'#default_value' => !empty($project->project->field_project_type['und'][0]['value']) ? $project->project->field_project_type['und'][0]['value'] : '299',
	);
		
	// credit card outer wrapper
	$form['cc'] = array(
		'#type' => 'fieldset',
		'#title' => t('Credit card'),
		'#prefix' => '<div id="cc-selection-wrap">',
		'#suffix' => '</div>',
	);
	
	// charge amount
	$form['cc']['cc_amount'] = array(
		'#type' => 'textfield',
		'#title' => t('Charge amount'),
		'#maxlength' => 16,
		'#required' => TRUE,
		'#default_value' => !empty($project->project->field_charge_amount['und'][0]['value']) ? $project->project->field_charge_amount['und'][0]['value'] : '',
	);
	
	// line item desc
	$form['cc']['cc_description'] = array(
		'#type' => 'textfield',
		'#title' => t('Line item description'),
		'#required' => TRUE,
		'#default_value' => !empty($project->project->field_line_item_desc['und'][0]['value']) ? $project->project->field_line_item_desc['und'][0]['value'] : '',
	);
	
	// credit new / existing selection
	$form['cc']['cc_select'] = array(
		'#type' => 'radios',
		'#options' => array('new' => 'Add new credit card'),
		'#default_value' => 'new',
	);
	
	// get existing credit cards, if any
	$payments = bxdev_payment_get_payment_profiles($project->client->uid);
	
	// credit cards exist
	if($payments){
	
		// add the option to select an existing card
		$form['cc']['cc_select']['#options'] = array('new' => 'Add new credit card', 'existing' => 'Use existing credit card');
		$form['cc']['cc_select']['#default_value'] = 'existing';

		// existing card outer wrapper
		// - disable if "new" radio button has been selected
		$form['cc']['cc_existing'] = array(
			'#type' => 'fieldset',
			'#title' => t('Existing credit card'),
			'#states' => array(
				'disabled' => array(
					':input[name="cc_select"]' => array('value' => 'new'),
				),
			),
		);
	
		// list the existing cards
		$form['cc']['cc_existing']['payment_id'] = array(
			'#type' => 'radios',
			'#options' => $payments,
			'#default_value' => $project->project->field_payment_id['und'][0]['value'],
		);		
	}else{
		$form['cc']['cc_select']['#value'] = 'new';
	}
	
	// new card outer wrapper
	// - disable is "existing" radio button is selected
	$form['cc']['cc_new'] = array(
		'#type' => 'fieldset',
		'#title' => t('New credit card'),
		'#states' => array(
			'disabled' => array(
				':input[name="cc_select"]' => array('value' => 'existing'),
			),
		),
		
	);
	
	// credit card number
	$form['cc']['cc_new']['cc_number'] = array(
		'#type' => 'textfield',
		'#title' => t('Credit card number'),
		'#maxlength' => 16,
		// '#required' => TRUE,
	);
	
	// credit card expiration month
	$form['cc']['cc_new']['cc_expiry_month'] = array(
		'#type' => 'select',
		'#title' => t('Expiration month'),
		'#options' => array(
			'' => 'Month',
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
		// '#required' => TRUE,
	);
	
	// credit card expiration year
	$form['cc']['cc_new']['cc_expiry_year'] = array(
		'#type' => 'select',
		'#title' => t('Expiration year'),
		'#options' => array(
			'' => 'Year',
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
		// '#required' => TRUE,
	);
	
	// credit card security code
	$form['cc']['cc_new']['cc_code'] = array(
		'#type' => 'textfield',
		'#title' => t('Security code'),
		// '#required' => TRUE,
	);
	
	$form['cc']['charge'] = array(
	  '#type' => 'submit',
	  '#value' => t('Charge'),
		'#suffix' => '<div class="popup charge-popup" style="display:none;">
			<h3>Are you sure you wish to charge this credit card?</h3><p>This action cannot be undone.</p>
			<div class="buttons"><a href="" class="btn-approve">Charge credit card</a>
			<a href="" class="btn-cancel">Cancel</a></div>
		</div>'
	);
	
	
	return $form;
}

/**
 * Form validate: project payment
 */
function bxdev_payment_project_payment_form_validate($form, &$form_state){
	
	$values = $form_state['values'];
	
	// charge amount
	if(!is_numeric($values['cc_amount'])){
		form_set_error('cc_amount', 'Enter a numeric value for charge amount');
	}
	
	// if new credit card
	if($values['cc_select'] == 'new'){
		
		// credit card number
		if(strlen($values['cc_number']) < 13){
			form_set_error('cc_number', 'Enter a credit card number between 13 and 16 digits');
		}
		
		// credit card expiration month
		if(empty($values['cc_expiry_month'])){
			form_set_error('cc_expiry_month', 'Select a credit card expiration month');
		}
		
		// credit card expiration year
		if(empty($values['cc_expiry_year'])){
			form_set_error('cc_expiry_year', 'Select a credit card expiration year');
		}
		
		// credit card security code
		if(empty($values['cc_code'])){
			form_set_error('cc_code', 'Enter a credit card security code');
		}		
		
	}

}

/**
 * Form submit: project payment
 */
function bxdev_payment_project_payment_form_submit($form, &$form_state){
	
	$values = $form_state['values'];
	$nid = arg(1);
	$project = new Project($nid);
	$profile_id = bxdev_payment_get_auth_token($project->client->uid);
	
	global $api_login_id;
	global $transaction_key;
	global $auth_test_mode;
	
	$cim = new AuthnetCIM($api_login_id, $transaction_key, $auth_test_mode);
	$amount = $values['cc_amount'];
	$line_item_description = $values['cc_description'];
	
	switch($values['cc_select']){
		case 'existing':
		
			$payment_id = $values['payment_id'];
			$cim->setParameter('customerPaymentProfileId', $payment_id);
			$cim->setParameter('customerProfileId', $profile_id);
			$cim->setParameter('cardCode', '000');
			$cim->setParameter('amount', $amount);
			$cim->setParameter('invoiceNumber', date('m_d_Y', mktime()) . '_' . variable_get('client_invoice_num', 101));
			$cim->setParameter('description', 'Client: ' . preg_replace('/[^0-9a-zA-Z\s]/', $project->client->field_name['und'][0]['value']) . ', Project: ' . preg_replace('/[^0-9a-zA-Z\s]/', $project->project->title));
			$cim->setParameter('refId', date('m/d/y-G:i:s'));
			$cim->createCustomerProfileTransaction();
			
			// transaction was successful
			if($cim->isSuccessful()){
				
				dpm($cim->getResponseSummary());				
				$transaction_id = $cim->getTransactionId();				
				bxdev_payment_log_payment($project->project->nid, $project->client->uid, $payment_id, $transaction_id, $amount);
				
				/**
				 * Create and send the invoice receipt
				 */				
				
				$line_items[] = array(
					'qty' => 1,
					'description' => $line_item_description,
					'unit_price' => $amount,
					'line_total' => $amount,
				);
				
				$line_items['total'] = $amount;
				
				$project->send_client_receipt($line_items, $payment_id);
			
			// transaction was not successful
			}else{
				drupal_set_message($cim->getResponseSummary(), 'error');
			}			
			break;
		
		case 'new':
		
			$cc_number = $values['cc_number'];
			$cc_expiry = $values['cc_expiry_year'] . '-' . $values['cc_expiry_month'];
			$cc_code = $values['cc_code'];
			
			// if user does not have a token
			if(!$profile_id){
				$cim->setParameter('email', $project->client->mail);
				$cim->setParameter('merchantCustomerId', $project->client->uid);			
				$cim->createCustomerProfile();

				if($cim->isSuccessful()){				
					$profile_id = $cim->getProfileID();
					db_insert('users_auth')
						->fields(array(
							'uid' => $project->client->uid,
							'auth_token' => $profile_id,
						))
						->execute();					
				}else{				
					drupal_set_message($cim->getResponse(), 'error');
					return;		
				}
				
			}	
		
			$cim->setParameter('customerProfileId', $profile_id);
			$cim->setParameter('cardNumber', $cc_number);
			$cim->setParameter('expirationDate', $cc_expiry);
			$cim->setParameter('cardCode', $cc_code);
			$cim->setParameter('validationMode', 'testMode');
			$cim->createCustomerPaymentProfile();
			
			if($cim->isSuccessful()){
			
				$payment_id = $cim->getPaymentProfileId();
				drupal_set_message('Payment ID: ' . $cim->getPaymentProfileId());
				
				$cim->setParameter('customerPaymentProfileId', $payment_id);
				$cim->setParameter('cardCode', $cc_code);
				$cim->setParameter('amount', $amount);
				$cim->setParameter('invoiceNumber', date('m_d_Y', mktime()) . '_' . variable_get('client_invoice_num', 101));
				$cim->setParameter('description', 'Client: ' . preg_replace('/[^0-9a-zA-Z\s]/', $project->client->field_name['und'][0]['value']) . ', Project: ' . preg_replace('/[^0-9a-zA-Z\s]/', $project->project->title));
				$cim->setParameter('refId', date('m/d/y-G:i:s'));
				$cim->createCustomerProfileTransaction();
				
				// transaction was successful
				if($cim->isSuccessful()){

					dpm($cim->getResponseSummary());				
					$transaction_id = $cim->getTransactionId();				
					bxdev_payment_log_payment($project->project->nid, $project->client->uid, $payment_id, $transaction_id, $amount);
					
					/**
					 * Create and send the invoice receipt
					 */				

					$line_items[] = array(
						'qty' => 1,
						'description' => $line_item_description,
						'unit_price' => $amount,
						'line_total' => $amount,
					);

					$line_items['total'] = $amount;

					$project->send_client_receipt($line_items, $payment_id);

				// transaction was not successful
				}else{
					$form_state['rebuild'] = TRUE;
					drupal_set_message($cim->getResponseSummary(), 'error');
				}			
							
			// if adding the card failed				
			}else{
				$form_state['rebuild'] = TRUE;
				drupal_set_message($cim->getResponse(), 'error');		
			}			
			
			break;
	}
	
}

/**
 * Form builder: client add new card
 */
function bxdev_payment_client_new_credit_card_form($form, &$form_state){
	
	// credit card number
	$form['cc']['cc_new']['cc_number'] = array(
		'#type' => 'textfield',
		'#title' => t('Credit card number'),
		'#maxlength' => 16,
		'#size' => 25,
		'#required' => TRUE,
	);
	
	// credit card expiration month
	$form['cc']['cc_new']['cc_expiry_month'] = array(
		'#type' => 'select',
		'#title' => t('Expiration month'),
		'#options' => array(
			'' => 'Month',
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
	
	// credit card expiration year
	$form['cc']['cc_new']['cc_expiry_year'] = array(
		'#type' => 'select',
		'#title' => t('Expiration year'),
		'#options' => array(
			'' => 'Year',
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
	
	// credit card security code
	$form['cc']['cc_new']['cc_code'] = array(
		'#type' => 'textfield',
		'#title' => t('Security code'),
		'#required' => TRUE,
		'#maxlength' => 5,
		'#size' => 10,
	);
	
	$form['submit'] = array(
	  '#type' => 'submit',
	  '#value' => t('Add credit card'),
	);	
	
	return $form;
}

/**
 * Form validate: client add new card
 */
function bxdev_payment_client_new_credit_card_form_validate($form, &$form_state){
	$values = $form_state['values'];
	
	// credit card number
	if(strlen($values['cc_number']) < 13){
		form_set_error('cc_number', 'Enter a credit card number between 13 and 16 digits');
	}
	
}

/**
 * Form submit: client add new card
 */
function bxdev_payment_client_new_credit_card_form_submit($form, &$form_state){
	
	$values = $form_state['values'];
	
	$uid = arg(2);
	$profile_id = bxdev_payment_get_auth_token($uid);
	
	// if the user does not have an auth token, stop and return
	if(!$profile_id){
		drupal_set_message('User does not have a payment profile', 'error');
		return;
	}
	
	global $api_login_id;
	global $transaction_key;
	global $auth_test_mode;
	
	$cim = new AuthnetCIM($api_login_id, $transaction_key, $auth_test_mode);
	
	$cc_number = $values['cc_number'];
	$cc_expiry = $values['cc_expiry_year'] . '-' . $values['cc_expiry_month'];
	$cc_code = $values['cc_code'];		

	$cim->setParameter('customerProfileId', $profile_id);
	$cim->setParameter('cardNumber', $cc_number);
	$cim->setParameter('expirationDate', $cc_expiry);
	$cim->setParameter('cardCode', $cc_code);
	$cim->setParameter('billToAddress', '123 Main Street');
	$cim->setParameter('billToZip', '12345');
	$cim->setParameter('validationMode', 'testMode');
	$cim->createCustomerPaymentProfile();
	
	if($cim->isSuccessful()){
	
		$payment_id = $cim->getPaymentProfileId();
		drupal_set_message('Payment ID: ' . $cim->getPaymentProfileId());
					
	// if adding the card failed				
	}else{
		$form_state['rebuild'] = TRUE;
		drupal_set_message($cim->getResponse(), 'error');		
	}	
}

/**
 * Form builder: videographer payment
 */
function bxdev_payment_videographer_payment_form($form, &$form_state){
	
	$form['amount'] = array(
		'#type' => 'textfield',
		'#title' => t('Amount'),
		'#size' => 20,
		'#maxlength' => 20,
		'#required' => TRUE,
	);
	
	$form['description'] = array(
		'#type' => 'textfield',
		'#title' => t('Line item description'),
		'#required' => TRUE,
	);
	
	$form['pay'] = array(
	  '#type' => 'submit',
	  '#value' => t('Pay'),
	);
	
	$form['popup'] = array(
		'#markup' => '<div style="display:none;" class="popup videographer-charge-popup">
			<h3>Are you sure you wish to initiate this Videographer payment?</h3><p>This action cannot be undone.</p>
			<div class="buttons"><a class="btn-approve" href="">Send payment</a>
			<a class="btn-cancel" href="">Cancel</a></div>
		</div>'
	);
	
	return $form;
}

/**
 * Form submit: videographer payment
 */
function bxdev_payment_videographer_payment_form_submit($form, &$form_state){
	
	$values = $form_state['values'];
	$amount = $values['amount'];
	$description = $values['description'];
	
	$nid = arg(1);
	$project = new Project($nid);
	
	$w9_file = bxdev_document_get_videographer_w9_file($project->videographer->uid);
	
	// videographer has uploaded a W9 form
	if($w9_file){
		
		$project->process_videographer_payment($w9_file, $amount, $description);
				
	// videographer has not uploaded a W9 form
	}else{		
		$project->send_videographer_w9_reminder($amount, $description);		
	}
	 
}


/**
 * CUSTOM
 */

/**
 * Return credit card form markup
 */
function bxdev_payment_cc_form_markup($form_state = NULL){
	
	// charge amount
	$form['cc_amount'] = array(
		'#type' => 'textfield',
		'#title' => t('Charge amount'),
		'#field_prefix' => t('$'),
		'#maxlength' => 16,
		'#required' => TRUE,
	);
	
	// charge amount
	$form['cc_description'] = array(
		'#type' => 'textfield',
		'#title' => t('Line item description'),
		'#required' => TRUE,
	);
	
	// credit card outer wrapper
	$form['cc'] = array(
		'#type' => 'fieldset',
		'#title' => t('Credit card'),
		'#prefix' => '<div id="cc-selection-wrap">',
		'#suffix' => '</div>',
	);
	
	// credit new / existing selection
	$form['cc']['cc_select'] = array(
		'#type' => 'radios',
		'#options' => array('new' => 'Add new credit card'),
		'#default_value' => 'new',
	);
	
	// if an existing client has been selected (using AJAX)
	if(!empty($form_state['values']['existing_client'])){
		
		// get existing credit cards, if any
		$payments = bxdev_payment_get_payment_profiles($form_state['values']['existing_client']);
		
		// credit cards exist
		if($payments){
		
			// add the option to select an existing card
			$form['cc']['cc_select']['#options'] = array('new' => 'Add new credit card', 'existing' => 'Use existing credit card');
	
			// existing card outer wrapper
			// - disable if "new" radio button has been selected
			$form['cc']['cc_existing'] = array(
				'#type' => 'fieldset',
				'#title' => t('Existing credit card'),
				'#states' => array(
					'disabled' => array(
						':input[name="cc_select"]' => array('value' => 'new'),
					),
				),
			);
		
			// list the existing cards
			$form['cc']['cc_existing']['payment_id'] = array(
				'#type' => 'radios',
				'#options' => $payments,
			);		
		}else{
			$form['cc']['cc_select']['#value'] = 'new';
		}
	}	
	
	// new card outer wrapper
	// - disable is "existing" radio button is selected
	$form['cc']['cc_new'] = array(
		'#type' => 'fieldset',
		'#title' => t('New credit card'),
		'#states' => array(
			'disabled' => array(
				':input[name="cc_select"]' => array('value' => 'existing'),
			),
		),
		
	);
	
	// credit card number
	$form['cc']['cc_new']['cc_number'] = array(
		'#type' => 'textfield',
		'#title' => t('Credit card number'),
		'#maxlength' => 16,
		// '#required' => TRUE,
	);
	
	// credit card expiration month
	$form['cc']['cc_new']['cc_expiry_month'] = array(
		'#type' => 'select',
		'#title' => t('Expiration month'),
		'#options' => array(
			'' => 'Month',
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
		// '#required' => TRUE,
	);
	
	// credit card expiration year
	$form['cc']['cc_new']['cc_expiry_year'] = array(
		'#type' => 'select',
		'#title' => t('Expiration year'),
		'#options' => array(
			'' => 'Year',
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
		// '#required' => TRUE,
	);
	
	// credit card security code
	$form['cc']['cc_new']['cc_code'] = array(
		'#type' => 'textfield',
		'#title' => t('Security code'),
		// '#required' => TRUE,
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
	
	$form = array();
	
	$form['client'] = array(
		'#type' => 'fieldset',
		'#title' => t('Client'),
		'#prefix' => '<div id="client-wrap">',
		'#suffix' => '</div>',
	);
	
	if($form_state['client_state'] == 'new'){
	
		$form['client']['new_client_email'] = array(
			'#type' => 'textfield',
			'#title' => t('Client email'),
			'#weight' => -50,
			'#required' => TRUE,
		);

		$form['client']['new_client_name'] = array(
			'#type' => 'textfield',
			'#title' => t('Client full name'),
			'#weight' => -49,
			'#required' => TRUE,
		);

		$form['client']['new_client_phone'] = array(
			'#type' => 'textfield',
			'#title' => t('Client phone'),
			'#weight' => -48,
			'#required' => TRUE,
		);
		
		$form['client']['client_switch_existing'] = array(
			'#type' => 'submit',
			'#value' => t('Select existing client'),
			'#limit_validation_errors' => array(),
			'#submit' => array('bxdev_payment_add_existing_client_submit'),
			'#ajax' => array(
				'callback' => 'bxdev_payment_switch_client_state',
				'wrapper' => 'client-form-wrapper',
			),
		);
	
	}else if($form_state['client_state'] == 'existing'){
		
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
		
		$form['client']['existing_client'] = array(
			'#type' => 'select',
			'#title' => t('Existing client'),
			'#options' => $options,
			'#default_value' => !empty($form_state['existing_client']) ?  $form_state['existing_client'] : '',
			'#required' => TRUE,
			'#ajax' => array(
				'callback' => 'bxdev_payment_get_existing_cc',
				'wrapper' => 'cc-selection-wrap',
			),
		);
		
		$form['client']['client_switch_new'] = array(
			'#type' => 'submit',
			'#value' => t('Add new client'),
			'#limit_validation_errors' => array(),
			'#submit' => array('bxdev_payment_add_new_client_submit'),
			'#ajax' => array(
				'callback' => 'bxdev_payment_switch_client_state',
				'wrapper' => 'client-form-wrapper',
			),
		);	
	
	}
		
	return $form;
}

