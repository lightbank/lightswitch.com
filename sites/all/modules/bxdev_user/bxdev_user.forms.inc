<?php

/**
 * Form builder: user create
 */
function bxdev_user_create_user_form($form, $form_state){
	$form['email'] = array(
	  '#type' => 'textfield',
	  '#title' => t('Email'),
	  '#description' => t('<p>This will act as the username.<br />An email will automatically be sent to user with a temporary password.</p>'),
		'#required' => TRUE,
	);
	
	$form['name'] = array(
	  '#type' => 'textfield',
	  '#title' => t('Full name'),
	);
	
	$form['phone'] = array(
	  '#type' => 'textfield',
	  '#title' => t('Phone'),
	);
	
	$form['role'] = array(
	  '#type' => 'radios',
	  '#title' => t('Role'),
	  '#options' => array(
			'sales' => 'Sales',
			'pc' => 'Production coordinator',
		),
	  '#default_value' => 'sales',
	);
	
	$form['create'] = array(
	  '#type' => 'submit',
	  '#value' => t('Create user'),
	);	
	
	return $form;	
}

/**
 * Form submit handler: user create
 */
function bxdev_user_create_user_form_submit($form, &$form_state){
	$values = $form_state['values'];
	$email = $values['email'];
	$role  = $values['role'];
	$full_name = $values['name'];
	$phone = $values['phone'];
	
	// check if valid email address
	if(!valid_email_address($email)){
		drupal_set_message('Please enter a valid email address.', 'error');
		return;
	}
	
	// check if user exists
	$user = user_load_by_name($email);
	if(!$user){
		// create the user
		$user = new User($email, $role, $full_name, $phone);
		$user = $user->get_user();
		drupal_set_message('User ' . $user->name . ' has been created.');
	}else{
		drupal_set_message('User already exists. Please enter a new email address.', 'error');
	}
}

/**
 * Form builder: change password
 */
function bxdev_user_change_password_form($form, $form_state){
	drupal_set_title('This is your first time logging in. Please change your password!');
	$form['pass'] = array(
		'#type' => 'password_confirm',
	);
	$form['submit'] = array(
	  '#type' => 'submit',
	  '#value' => t('Change password'),
	);	
	return $form;
}

/**
 * Form submit handler: change password
 */
function bxdev_user_change_password_form_submit($form, &$form_state){
	global $user;
	// get the new password
	$pass = $form_state['values']['pass'];
	$edit = (array)$user;
	// save new password
	$edit['pass'] = $pass;
	// set the first time login flag to 0 (off)
	$edit['data']['first_time_login'] = 0;
	user_save($user, $edit);
	drupal_set_message('Your password has been saved!');
	watchdog('lightswitch', 'Changed password - first time login: @name, uid: @uid', array('@name' => $user->name, '@uid' => $user->uid));
	
	// check if the user has accepted the Lightswitch terms
	bxdev_user_terms_accept_check($user);
	
	// if terms accept check has not redirected user, redirect to the profile page
	drupal_goto('user');
	
}

/**
 * Form builder: accept terms
 */
function bxdev_user_accept_terms_form($form, $form_state){
	drupal_set_title('You must accept the Independent Contractor Agreement terms before proceeding.');
	$form['terms'] = array(
		'#type' => 'checkbox',
		'#title' => t('I accept the Independent Contractor Agreement'),
		'#description' => t('<a href="/get/document/document_videographer_independent_contractor_agreement" rel="shadowbox;height=800;width=600">Click here to view Lightswitch\'s Independent Contractor Agreement</a>'),
	);
	
	$form['submit'] = array(
		'#type' => 'submit',
		'#value' => t('Accept and continue'),
	);
	
	return $form;
}

/**
 * Form submit handler: accept terms
 */
function bxdev_user_accept_terms_form_submit($form, &$form_state){
	global $user;
	$account = user_load($user->uid);
	// load the user's profile
	$profile = profile2_load_by_user($account, 'videographer');
	// set the terms accepted value
	$profile->field_videographer_terms['und'][0]['value'] = 1;
	// save the profile
	profile2_save($profile);
	
	$data['full_name'] = $account->field_name['und'][0]['value'];
	$data['address'] = $profile->field_address['und'][0]['value'];
	
	$html = variable_get('document_videographer_independent_contractor_agreement', '');
	$html = $html['value'];
	$html = token_replace($html, $data);
	
	$videographer_name = bxdev_get_filename_string($account->field_name['und'][0]['value']);
	
	$filename = 'lightswitch_contractor_agreement_' . $videographer_name . '_' . $account->uid . '.pdf';
	$fid = bxdev_document_create_pdf($html, $filename, 'videographer', 'independent_contractor_agreements', 'Independent Contractor Agreement', $account->uid);	
	
	// redirect to user's landing
	drupal_goto('user');
}

/**
 * Form validation handler: accept terms
 */
function bxdev_user_accept_terms_form_validate($form, &$form_state){
	$values = $form_state['values'];
	if($values['terms'] === 0){
		form_set_error('terms', 'You must accept the Independent Contractor Agreement');
	}
}

/**
 * Implements hook_form_alter().
 */
function bxdev_user_form_user_pass_alter(&$form, &$form_state) {
	drupal_set_title('Reset password');
	$form['name']['#title'] = 'Email address';
	$form['name']['#description'] = '<a href="/user">Back to login</a>';
	$form['#submit'][0] = 'bxdev_user_user_pass_submit';
}

/**
 * Form submit handler: user password (anonymous)
 */
function bxdev_user_user_pass_submit($form, &$form_state){
	$values = $form_state['values'];
	// if the user email exists
	if($account = user_load_by_name($values['name'])){
		$user = new User();
		$user->load($account->uid);
		$user->send_password_reset();
		drupal_set_message('New password has been sent to ' . $account->mail);
	// if the email cannot be found in the system
	}else{
		drupal_set_message('Email address does not exist.', 'error');
	}
}

/**
 * Implements hook_form_alter().
 */
function bxdev_user_form_user_login_alter(&$form, &$form_state) {
	drupal_set_title('Login to lightswitch');
	$form['name']['#description'] = '';
	$form['pass']['#description'] = '<a href="/user/password">Forgot your password?</a>';
}

/**
 * Implements hook_form_alter().
 */
function bxdev_user_form_user_profile_form_alter(&$form, &$form_state) {
	global $user;
	$uid = arg(1);
	$form['account']['current_pass']['#description'] = '<a href="/user/' . $uid . '/password/forgot">Forgot your password?</a>';
	
	// if videographer profile and user is videographer
	if(arg(3) == 'videographer' && (bxdev_user_get_role($user->uid) == 'videographer' || bxdev_user_get_role($user->uid) == 'pc')){
		unset($form['profile_videographer']['field_videographer_terms']);
	}
	
}

