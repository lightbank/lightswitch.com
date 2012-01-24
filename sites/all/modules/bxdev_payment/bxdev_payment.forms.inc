<?php

/**
 * Form builder: client, credit card, shoot date
 */
function bxdev_payment_project_client_credit_card_form($form, &$form_state){
	
	require_once(drupal_get_path('module', 'bxdev_payment') . '/anet_php_sdk/AuthorizeNet.php'); // The SDK
	require_once(drupal_get_path('module', 'bxdev_payment') . '/vars.php');
	require_once(drupal_get_path('module', 'bxdev_payment') . '/util.php');
	
	$processor = new Processor();
	
	dpm($processor);
	
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

}



/**
 * CUSTOM
 */

/**
 * Return credit card form markup
 */
function bxdev_payment_cc_form_markup(){
	
	$form['cc']['cc_number'] = array(
		'#type' => 'textfield',
		'#title' => t('Credit card number'),
	);
	
	$form['cc']['cc_expiry_month'] = array(
		'#type' => 'select',
		'#title' => t('Expiration date'),
		'#options' => array(
			'_none' => 'Month',
			1 => '01',
			2 => '02',
			3 => '03',
			4 => '04',
			5 => '05',
			6 => '06',
			7 => '07',
			8 => '08',
			9 => '09',
			10 => '10',
			11 => '11',
			12 => '12',
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
	
	// generate a list of existing clients
	// get the client references view
	$clients = views_get_view('users', 'references_2');
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
		'#prefix' => '<div class="new-client-wrapper">',
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
		'#default_value' => '_none',
		'#description' => t('<a href="" class="new-client-btn">+ Add new Client</a>'),
		'#prefix' => '<div class="existing-client-wrapper">',
		'#suffix' => '</div>',
	);
	
	return $form;
}

