<?php

/**
 * FORMS
 */

/**
 * Form builder: partner order form
 */
function bxdev_partner_order_form($form, &$form_state, $node){
	
	$form['#node'] = $node;
	
	$fields = field_info_fields('node', 'business');
	$time_options = bxdev_get_times_array();
	$city_options[''] = '- Select - ';
	$city_options += $fields['field_business_city']['settings']['allowed_values'];
	$city_visible = !empty($_POST['city_manual']) ? 'block' : 'none';
	
	drupal_add_library('system', 'ui.datepicker');
	drupal_add_library('date_popup', 'timeentry');
	
	$form['contact_name'] = array(
		'#type' => 'textfield',
		'#title' => t('Contact Name'),
		'#required' => TRUE,
	);
	
	$form['phone'] = array(
		'#type' => 'textfield',
		'#title' => t('Best Phone Number'),
		'#required' => TRUE,
	);
	
	$form['city'] = array(
		'#type' => 'select',
		'#options' => $city_options,
		'#title' => t('City'),
	);
	
	$form['city_manual'] = array(
		'#type' => 'textfield',
		'#title' => t('Enter your City, State'),
		'#prefix' => '<div class="manual-city-field" style="display:' . $city_visible . '">',
		'#suffix' => '</div>',
	);
	
	$form['shoot_date'] = array(
		'#type' => 'textfield',
		'#title' => t('Shoot Date'),
	);
	
	$form['business_name'] = array(
		'#type' => 'textfield',
		'#title' => t('Business Name'),
		'#required' => TRUE,
	);
	
	$form['email'] = array(
		'#type' => 'textfield',
		'#title' => t('Email'),
		'#required' => TRUE,
	);
	
	$form['street'] = array(
		'#type' => 'textfield',
		'#title' => t('Street Address'),
	);
	
	$form['shoot_time'] = array(
		'#type' => 'select',
		'#options' => $time_options,
		'#title' => t('Shoot Time'),
	);
	
	$form['notes'] = array(
		'#type' => 'textarea',
		'#title' => t('Notes for Video Shoot'),
	);
	
	if(!empty($node->field_partner_show_add_field['und'][0]['value'])){
		$form['additional_field'] = array(
			'#type' => 'textarea',
			'#title' => !empty($node->field_partner_add_field_label['und'][0]['value']) ? $node->field_partner_add_field_label['und'][0]['value'] : 'Other',
		);
	}
	
	if(!empty($node->field_partner_show_upload['und'][0]['value'])){
		$form['release_upload'] = array(
			'#type' => 'managed_file',
			'#title' => 'Signed Production Release',
			'#upload_location' => 'public://partner_signed_releases/',
			'#upload_validators' => array(
		    'file_validate_extensions' => array('pdf doc docx'),
		  ),
		);
	}
	
	if(!empty($node->field_partner_show_month['und'][0]['value'])){
		$form['subscription_month'] = array(
			'#type' => 'select',
			'#title' => t('Subscription Start Month'),
			'#options' => array(
				'' => t('- Select -'),
				1 => '01 - January',
				2 => '02 - February',
				3 => '03 - March',
				4 => '04 - April',
				5 => '05 - May',
				6 => '06 - June',
				7 => '07 - July',
				8 => '08 - August',
				9 => '09 - September',
				10 => '10 - October',
				11 => '11 - November',
				12 => '12 - December',				
			),
			'#required' => TRUE,
		);
	}	
	
	// if partner is allowed to select video type
	if($node->field_partner_select_type['und'][0]['value']){
		
		// create the options based on video types specified in the node
		$options = array();
		foreach($node->field_partner_dynamic_type['und'] as $value){
			switch($value['value']){
				case '0':
					$options[449] = 'Video with music';
					break;
				
				case '1':
					$options[549] = 'Video with interview';
					break;
					
				case '2':
					$options[599] = 'Video with voice over';
					break;
			}
		}
		
		$form['project_type'] = array(
			'#type' => 'select',
			'#title' => 'Video type',
			'#options' => $options,
		);
	}
	
	$form['submit'] = array(
		'#type' => 'submit',
		'#value' => t('Submit Order'),
	);
	
	return $form;
}

/**
 * Form validate: partner order form
 */
function bxdev_partner_order_form_validate($form, &$form_state){
	
	$values = $form_state['values'];
	
	// check for valid email address
	$email = $values['email'];
	if($email != '' && !valid_email_address($email)){
		form_set_error('email', 'Enter a valid email address');
	}
	
	// check for valid city
	$city = $values['city'];
	$city_manual = $values['city_manual'];
	
	if($city == ''){
		if($city_manual == ''){
			form_set_error('city', 'City field is required');
		}
	}
	
}

/**
 * Form submit: partner order form
 */
function bxdev_partner_order_form_submit($form, &$form_state){
	
	$partner = node_load(arg(1));
	$values = $form_state['values'];
	$email = $values['email'];
	$contact_name = $values['contact_name'];
	$phone = $values['phone'];
	$business_name = $values['business_name'];
	$street = $values['street'];
	$city = $values['city'];
	$city_manual = $values['city_manual'];
	$shoot_date = $values['shoot_date'];
	$shoot_time = $values['shoot_time'];
	$shoot_timestamp = $shoot_date != '' ? strtotime($shoot_date . ' ' . $shoot_time) : NULL;
	$notes = $values['notes'];
	$additional_field = $values['additional_field'];
	$subscription_month = $values['subscription_month'];
	$release_upload = $values['release_upload'];
	
	// determine video type
	$project_type = '';
	// if partner has selected video type
	if($partner->field_partner_select_type['und'][0]['value']){
		$project_type = $values['project_type'];
	// if admin has assigned a static video type
	}else{
		$project_type = $partner->field_partner_static_type['und'][0]['value'];
	}
	
	/**
	 * Generate the client
	 */
	
	// check if client exists
	$account = user_load_by_name($email);
	if(!$account){
		$account = new stdClass();
		$account->status = 1;
		$account->name = $email;
		$account->mail = $email;
		$account->pass = user_password();
		$account->field_name['und'][0]['value'] = $contact_name;
		$account->field_phone['und'][0]['value'] = $phone;
		$account->roles = array(
			2 => 'authenticated user',
			7 => 'client',
		);
		$account = user_save($account);
	}
	// check if a default partner theme should be applied to the client
	if(!empty($partner->field_partner_default_theme['und'][0]['nid'])){
		// load the profile for the user
		$profile = profile2_load_by_user($account->uid, 'client');
		// if a profile does not exist, create one
		if(!$profile){
			$profile = profile_create(array('user' => $account, 'type' => 'client'));
		}
		// assign the default partner theme
		$profile->field_client_partner_theme['und'][0]['nid'] = $partner->field_partner_default_theme['und'][0]['nid'];
		// save the profile
		profile2_save($profile);
	}
	
	/**
	 * Create the business
	 */
	
	// check if partner business already exists for client
	$query = new EntityFieldQuery;
	$result = $query
	  ->entityCondition('entity_type', 'node')
		->entityCondition('bundle', 'business')
		->propertyCondition('title', $partner->title)
	  ->fieldCondition('field_client_ref', 'uid', $account->uid, '=')
	  ->execute();
	
	$business = '';
	
	// if partner business already exists for client, use existing business
	if(!empty($result)){
		$business_node = reset($result['node']);
		$business = node_load($business_node->nid);
	// if partner business does not exist for client, create a new business
	}else{	
		$business = new stdClass();
		$business->language = LANGUAGE_NONE;
		$business->type = 'business';	
		$business->title = $partner->title . ' - ' . $business_name;
		$business->field_business_city['und'][0]['value'] = $city;
		$business->field_client_ref['und'][0]['uid'] = $account->uid;
		$business->field_address['und'][0]['value'] = !empty($street) ? $street : '';
		node_save($business);
	}
	
	/**
	 * Create the project
	 */
	$project = new stdClass();
	$project->language = LANGUAGE_NONE;
	$project->type = 'project';
	$project->title = $business_name;
	$project->field_project_business_ref['und'][0]['nid'] = $business->nid;
	$project->field_shoot_date['und'][0]['value'] = $shoot_timestamp;
	$project->field_project_type['und'][0]['value'] = $project_type;
	$project->field_charge_amount['und'][0]['value'] = $project_type;
	$project->field_video_type['und'][0]['value'] = 'bd';
	// if notes have been entered
	$project->field_pc_notes['und'][0]['value'] = !empty($notes) ? $notes . "\n\n" : '';
	// if an additional field has been entered
	$project->field_pc_notes['und'][0]['value'] .= !empty($additional_field) ? $additional_field . "\n\n" : '';
	// if a subscription start date has been entered
	if($subscription_month != ''){
		$project->field_pc_notes['und'][0]['value'] .= 'Subscription start month: ' . date('F', mktime(0, 0, 0, $subscription_month)) . "\n\n";
	}
	$project->field_voice_over['und'][0]['value'] = $project_type == '599' ? '1' : '0';
	if($project_type == '449' || $project_type == '549'){
		$project->field_voice_over_gender['und'][0]['value'] = 'no_preference';
	}
	$project->field_owner_interview['und'][0]['value'] = $project_type == '549' ? '1' : '0';
	
	// if a Tribune project, make "disable video download" TRUE
	if(!empty($partner->field_partner_default_theme['und'][0]['nid'])){
		$partner_theme = node_load($partner->field_partner_default_theme['und'][0]['nid']);
		if($partner_theme->title == 'Tribune LocalTrack'){
			$project->field_disable_file_download['und'][0]['value'] = "1";
		}
	}
	
	// if a partner signed release was uploaded
	if($release_upload != ''){
		$file = file_load($release_upload);
		$file->display = 1;
		$file->description = '';
		$project->field_partner_release['und'][0] = (array) $file;
	}
	
	node_save($project);
		
	drupal_set_message('Your order has been successfully submitted. Thank you!');
	
	// send the notification email
	global $base_url;
	$emails = 'jason@lightswitch.com, brittany@lightswitch.com, kelly@lightswitch.com';
	// $emails = 'accounting@bxcreative.com';
	$params['project_link'] = $base_url . '/' . drupal_lookup_path('alias', 'node/' . $project->nid);
	$params['partner'] = $partner;
	$params['city_manual'] = $city_manual;
	drupal_mail('bxdev_project', 'partner_order_submit', $emails, language_default(), $params);
	
	// log the action
	watchdog('partner', $partner->title . ' has added a new order');
}

















