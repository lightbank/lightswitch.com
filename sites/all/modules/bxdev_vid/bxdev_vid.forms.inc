<?php

/**
 * FORMS
 */

/**
 * Implements hook_form_alter().
 */
function bxdev_vid_form_alter(&$form, &$form_state, $form_id) {
	// if editing a user
	if(!empty($form['#user'])){
		global $user;
		// get the logged in user's role
		$current_user_role = bxdev_user_get_role($user->uid);
		// get the user's role being edited
		$form_role = bxdev_user_get_role($form['#user']->uid);
		// if the user profile form and logged in user is 'pc' and user being edited is a 'videographer'
		if($form_id == 'user_profile_form' && $current_user_role == 'pc' && $form_role == 'videographer'){
			$form['#submit'][] = 'bxdev_vid_edit_redirect';
		}
	}
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function bxdev_vid_form_user_register_form_alter(&$form, &$form_state) {
	if(arg(0) != 'admin'){
		// hide / reposition user fields
		$form['account']['name']['#type'] = 'hidden';
		$form['account']['name']['#value'] = NULL;
		$form['account']['mail']['#title'] = t('Email');
		$form['account']['mail']['#description'] = '';
		$form['account']['mail']['#weight'] = -50;
		$form['account']['pass']['#type'] = 'hidden';
		$form['account']['pass']['#value'] = NULL;
		$form['field_name']['#weight'] = -49;
		$form['field_phone']['#weight'] = -48;
		$form['field_name']['und'][0]['value']['#required'] = TRUE;
		
		// include the videographer profile2 fields
		$profile = profile_create(array('type' => 'videographer'));
		$form_state['profiles']['videographer'] = $profile;
	  $form['profile_videographer']['#tree'] = TRUE;
	  $form['profile_videographer']['#parents'] = array('profile_videographer');
	  field_attach_form('profile2', $profile, $form['profile_videographer'], $form_state);
	
		// modify validation / submit handlers
		array_unshift($form['#validate'], 'bxdev_vid_user_register_validate');
		$form['#validate'][] = 'profile2_form_validate_handler';
		$form['#submit'][0] = 'bxdev_vid_user_register_submit';
		// remove the standard user_register_submit drupal handler
		unset($form['#submit'][1]);
		$form['#submit'][] = 'profile2_form_submit_handler';
		$form['#submit'][] = 'bxdev_document_videographer_user_register_submit';
	
		// left / right wrappers
		$form['field_name']['#prefix'] = '<div class="left">';
		$form['profile_videographer']['field_skills']['#suffix'] = '</div><div class="right">';
		$form['profile_videographer']['field_resume']['#suffix'] = '</div>';
		$form['#attributes']['class'][] = 'clearfix';
		
	}
	
	if(arg(0) == 'join-our-team'){
		unset($form['profile_videographer']['field_videographer_w9']);
	}
	
}

/**
 * Submit handler: user register
 */
function bxdev_vid_user_register_submit($form, &$form_state){
	$values = $form_state['values'];
	// create a new user
	$user = new User($values['mail'], 'videographer', $values['field_name']['und'][0]['value'], $values['field_phone']['und'][0]['value']);
	// $user = new User();
	// $user->set_email($values['mail']);
	// $user->set_full_name($values['field_name']['und'][0]['value']);
	// $user->set_phone($values['field_phone']['und'][0]['value']);
	// $user->set_role('videographer');
	// $user->create();
	$user = $user->get_user();
	// send along the user object
	$form_state['user'] = $user;
}

/**
 * Validation handler: user register
 */
function bxdev_vid_user_register_validate($form, &$form_state){
	$values = $form_state['values'];
	if(!empty($values['mail'])){
		// populate the username and password fields
		form_set_value($form['account']['name'], $values['mail'], $form_state);
		form_set_value($form['account']['pass'], user_password(), $form_state);
	}
	// if videographer has not checked the accept box
	if($values['profile_videographer']['field_videographer_terms']['und'][0]['value'] === 0){
		form_set_error('profile_videographer[field_videographer_terms][und', 'You must accept the Independent Contractor Agreement');
	}
}

/**
 * Form builder: w9 form
 */
function bxdev_vid_w9_form($form, &$form_state){
	$uid = arg(1);
	$profile = profile2_load_by_user($uid, 'videographer');
	$form['w9_form'] = array(
	  '#type' => 'managed_file',
	  '#title' => t('W9 form'),
	  '#description' => t('Click <a href="/sites/default/files/lightswitch_w9.pdf">here</a> to download a new W9 form.'),
		'#default_value' => (!empty($profile->field_videographer_w9['und'][0]['fid'])) ? $profile->field_videographer_w9['und'][0]['fid'] : '',
	);
	
	$form['submit'] = array(
	  '#type' => 'submit',
	  '#value' => t('Save'),
	);
	
	return $form;
}

/**
 * Form submit handler: w9 form
 */
function bxdev_vid_w9_form_submit($form, &$form_state){
	$values = $form_state['values'];
	$uid = arg(1);
	// load the videographer profile
	$profile = profile2_load_by_user($uid, 'videographer');
	// remove any existing file
	unset($profile->field_videographer_w9['und']);
	// get the fid from the form
	$fid = $values['w9_form'];
	if($fid != 0){
		// get the file object
		$file = file_load($fid);
		$file->status = FILE_STATUS_PERMANENT;
		file_save($file);
		// create a file array to attach to the node
		$profile_file = array(
			'uid' => $file->uid,
			'uri' => $file->uri,
			'fid' => $file->fid,
			'status' => 1,
			'display' => 1,
			'description' => '',
		);
		$profile->field_videographer_w9['und'][0] = $profile_file;	
	}
	profile2_save($profile);
}

/**
 * Submit handler: videographer edit (by pc)
 */
function bxdev_vid_edit_redirect(&$form, &$form_state){
	$uid = arg(1);
	$form_state['redirect'] = 'user/' . $uid . '/info';
}

/**
 * Form builder: add videographer
 */
function bxdev_vid_join_form(){
	$output = render(drupal_get_form('user_register_form'));
	return $output;
}





























