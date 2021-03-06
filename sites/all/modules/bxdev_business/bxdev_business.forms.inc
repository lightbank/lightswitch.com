<?php

/**
 * Implements hook_form_FORM_ID_alter().
 * Form: business node form
 */
function bxdev_business_form_business_node_form_alter(&$form, $form_state){
	
	$form['#attributes']['class'][] = 'clearfix';
	$form['actions']['submit']['#submit'][] = 'bxdev_business_form_business_node_form_submit';
	$form['#validate'][] = 'bxdev_business_form_business_node_form_validate';
	$form['actions']['submit']['#value'] = t('Continue');
	$form['field_social_name3']['und'][0]['value']['#value'] = 'Yelp';
	
	// if sales/add/business
	if(arg(2) !== 'edit'){
		$form['title']['#prefix'] = '<div class="left">';
		$form['field_hours_operation']['#suffix'] = '</div><div class="right">';
		$form['field_business_download_file']['#suffix'] = '</div>';
	}
		
	// remove labels and set input values for social media inputs
	$form['field_social_name1']['und'][0]['value']['#title'] = t('Social Name');
	$form['field_social_name2']['und'][0]['value']['#title'] = '';
	$form['field_social_name3']['und'][0]['value']['#title'] = '';
	$form['field_social_name4']['und'][0]['value']['#title'] = '';
	$form['field_social_name1']['und'][0]['value']['#value'] = t('Facebook');
	$form['field_social_name2']['und'][0]['value']['#value'] = t('Twitter');
	$form['field_social_url1']['und'][0]['value']['#title'] =  t('Social URL');
	$form['field_social_url2']['und'][0]['value']['#title'] =  '';
	$form['field_social_url3']['und'][0]['value']['#title'] =  '';
	$form['field_social_url4']['und'][0]['value']['#title'] =  '';
	
	// if arg 3 is set, that means we have added a new client / credit card in a previous step
	$arg3 = arg(3);
	
	if(!empty($arg3)){
		
		$account = user_load($arg3);
		
		$form['field_client_ref']['und']['#type'] = 'hidden';
		$form['field_client_ref']['und']['#value'] = $arg3;
		$form['field_client_ref']['und']['#prefix'] = t('<h3><strong>Client: @name</strong></h2>', array('@name' => $account->field_name['und'][0]['value']));
	
	// if arg 3 is not set, that means we have not added a new client / credit card in a previous step
	}else if(arg(2) != 'edit'){
	
		$form['field_client_ref']['und']['#description'] = t('<a href="" class="new-client-btn">+ Add new Client</a>');
		$form['field_client_ref']['#attributes']['style'][] = 'display:none;';

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
	
	}
	
	// dpm($form_state);
	
}

/**
 * Form submit handler: add business
 */
function bxdev_business_form_business_node_form_submit($form, &$form_state){
		
		$values = $form_state['values'];
		
		// if a new client email is supplied
		if($values['new_client_email'] != ''){
			// create a new client user
			$user = new User();
			$user->set_email($values['new_client_email']);
			$user->set_role('client');
			$user->set_full_name($values['new_client_name']);
			$user->set_phone($values['new_client_phone']);
			$user->create();
			$user = $user->get_user();
			
			// load the business node that was just submitted
			$node = node_load($values['nid']);
			// set the client value
			$node->field_client_ref['und'][0]['uid'] = $user->uid;
			node_save($node);
		}
		
		// only if adding new business, not editing
		if(arg(2) != 'edit'){		
			$form_state['redirect'] = 'sales/add/project/' . $values['nid'];
		}
		
}

/**
 * Form validation handler: add business
 */
function bxdev_business_form_business_node_form_validate($form, &$form_state){
	$values = $form_state['values'];
	
	// if neither an existing or new client has been entered
	if(is_null($values['field_client_ref']['und'][0]['uid']) && empty($values['new_client_email'])){
		form_set_error('field_client_ref[und]', 'You must select an existing Client or add a new one');
		
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
 * Form builder: existing client
 */
function bxdev_business_existing_business_form($form, $form_state){
	
	// check if a client uid exists
	$arg3 = arg(3);
	$uri = $_SERVER['REQUEST_URI'];
	
	$form['#action'] = $uri . '#existing';
	
	$form['existing_business'] = array(
		'#type' => 'textfield',
		'#title' => t('Existing business'),
		'#autocomplete_path' => !empty($arg3) ? 'sales/autocomplete/businesses/' . $arg3 : 'sales/autocomplete/businesses',
		'#required' => TRUE,
	);
	
	$form['existing_business_nid'] = array(
	  '#type' => 'hidden',
		'#title' => t('A vaild existing business'),
		'#required' => TRUE,
	  '#default_value' => '',
	);	
	
	$form['submit'] = array(
	  '#type' => 'submit',
	  '#value' => t('Continue'),
	);
	
	return $form;	
}

/**
 * Form submit handler: existing client
 */
function bxdev_business_existing_business_form_submit($form, &$form_state){
	$values = $form_state['values'];
	// redirect to the add project page
	$form_state['redirect'] = 'sales/add/project/' . $values['existing_business_nid'];
}








