<?php

/**
 * FORMS
 */


/**
 * Implements hook_form_FORM_ID_alter().
 */
function bxdev_project_form_project_node_form_alter(&$form, $form_state){
	
	global $user;
	// set the author value, if sales/add/project
	if(arg(0) == 'sales'){
		// hide the payment notes field
		unset($form['field_payment_notes']);
		// hide the videographer agreed payment field
		unset($form['field_vid_agreed_payment']);
		// hide the video file upload field
		unset($form['field_project_video_file']);
		// hide the approved field
		unset($form['field_approved']);
		// hide the disable download field
		unset($form['field_disable_file_download']);

		$form['field_author']['und']['#type'] = 'hidden';
		// only pre-populate if sales user
		if(bxdev_user_get_role($user->uid) == 'sales'){
			$form['field_author']['und']['#default_value'] = $user->uid;		
		}else if(bxdev_user_get_role($user->uid) == 'pc'){
			$form['field_author']['und']['#default_value'] = '_none';
		}
	}
	
	// add a dollar sign before the charge amount field
	$form['field_charge_amount']['und'][0]['value']['#field_prefix'] = t('$');

	// remove the N/A options from video type, voice over, voice over gender, and owner interview
	unset($form['field_video_type']['und']['#options']['_none']);
	unset($form['field_voice_over']['und']['#options']['_none']);
	unset($form['field_voice_over_gender']['und']['#options']['_none']);
	unset($form['field_owner_interview']['und']['#options']['_none']);
		
	// add custom validation handler
	$form['actions']['submit']['#validate'][] = 'bxdev_project_form_project_node_form_validate';
	
	$times = bxdev_get_times_array();
	
	$shoot_date_start_default = '';
	$shoot_time_start_default = '';
	$shoot_time_end_default = '';
		
	// calculate default shoot date and start time value
	if(!empty($form['field_shoot_date']['und'][0]['#default_value']['value'])){
		$shoot_date_start_default = date('m/d/Y', $form['field_shoot_date']['und'][0]['#default_value']['value']);
		$shoot_time_start_default = date('G:i', $form['field_shoot_date']['und'][0]['#default_value']['value']);
	}else if(isset($_SESSION['payment']['shoot_date']['start'])){
		$shoot_date_start_default = date('m/d/Y', $_SESSION['payment']['shoot_date']['start']);
		$shoot_time_start_default = date('G:i', $_SESSION['payment']['shoot_date']['start']);
	}
	
	// calculate default shoot time end value
	if($form['field_shoot_date']['und'][0]['#default_value']['value2'] != $form['field_shoot_date']['und'][0]['#default_value']['value']){
		$shoot_time_end_default = !is_null($form['field_shoot_date']['und'][0]['#default_value']['value2']) ? date('G:i', $form['field_shoot_date']['und'][0]['#default_value']['value2']) : '';
	}else if(isset($_SESSION['payment']['shoot_date']['end'])){
		$shoot_time_end_default = date('G:i', $_SESSION['payment']['shoot_date']['end']);
	}	
		
	// create a fieldset
	$form['bxdev_shoot_date_fieldset'] = array(
		'#type' => 'fieldset',
		'#weight' => 14,
		'#attributes' => array(
			'class' => array('clearfix'),
		),
	);
	// create a custom date field
	$form['bxdev_shoot_date_fieldset']['bxdev_shoot_date'] = array(
		'#type' => 'textfield',
		'#title' => t('Shoot date'),
		'#required' => TRUE,
		'#default_value' => $shoot_date_start_default,
	);
	// create a custom start time field
	$form['bxdev_shoot_date_fieldset']['bxdev_shoot_time1'] = array(
		'#title' => t('Start time'),
		'#type' => 'select',
		'#required' => TRUE,
		'#options' => $times,
		'#default_value' => $shoot_time_start_default,
	);
	// create a custom end time field
	$form['bxdev_shoot_date_fieldset']['bxdev_shoot_time2'] = array(
		'#title' => t('End time'),
		'#type' => 'select',
		'#options' => $times,
		'#default_value' => $shoot_time_end_default,
	);
	
	// if project type has been set, pre populate on project page
	if(isset($_SESSION['payment']['project_type'])){
		$form['field_project_type']['und']['#default_value'] = $_SESSION['payment']['project_type'];
	}
	
	// if project type has been set, pre populate on project page
	if(isset($_SESSION['payment']['cc_amount'])){
		$form['field_charge_amount']['und'][0]['value']['#default_value'] = $_SESSION['payment']['cc_amount'];
	}
	
	// if project type has been set, pre populate on project page
	if(isset($_SESSION['payment']['line_item_description'])){
		$form['field_line_item_desc']['und'][0]['value']['#default_value'] = $_SESSION['payment']['line_item_description'];
	}
	
	// do not modify on admin side
	if(arg(0) != 'node' && !is_numeric(arg(1))){
		
		// set the user reference uid
		$nid = arg(3);
		$form['field_project_business_ref']['und']['#default_value'] = $nid;
	
		// override original submit button
		$form['actions']['submit']['#value'] = t('Submit & View Profile');
	
		// add additional submit button
		$form['actions']['return'] = array(
			'#type' => 'submit',
			'#value' => t('Submit & Return to Form'),
			'#submit' => array('node_form_submit', 'bxdev_project_project_node_form_submit'),
			'#validate' => array('bxdev_project_form_project_node_form_validate'),
		);
		
		$form['field_project_business_ref']['#prefix'] = '<div class="left">';
		$form['field_owner_interview']['#suffix'] = '</div><div class="right">';
		$form['actions']['#prefix'] = '</div>';		
	}
		
}

/**
 * Form submit handler: add project
 */
function bxdev_project_project_node_form_submit($form, &$form_state){	
		
	// send to client add form if "return to form" button was clicked
	if($form_state['clicked_button']['#value'] == 'Submit & Return to Form'){
		$form_state['redirect'] = 'sales/add/business';
	}
}

/**
 * Form submit handler: project node form
 */
function bxdev_project_form_project_node_form_validate($form, &$form_state){
	// get all the values
	$values = $form_state['values'];
	
	// video type cannot be left blank
	if(!$values['field_video_type']['und'][0]['value']){
		form_set_error('field_video_type[und]', 'A video type must be selected');
	}
	
	// voice over cannot be left blank
	if($values['field_voice_over']['und'][0]['value'] === FALSE){
		form_set_error('field_voice_over[und]', 'Voice over option must be selected');
	}
	
	// voice over gender cannot be left blank
	if($values['field_voice_over_gender']['und'][0]['value'] === FALSE){
		form_set_error('field_voice_over_gender[und]', 'A voice over gender must be selected');
	}
	
	// owner interview cannot be left blank
	if($values['field_owner_interview']['und'][0]['value'] === FALSE){
		form_set_error('field_owner_interview[und]', 'Business owner interview must be selected');
	}
	
	// check if end time is less than start time
	if($values['bxdev_shoot_time2'] != ''){
		$shoot_time1 = (int)$values['bxdev_shoot_time1'];
		$shoot_time2 = (int)$values['bxdev_shoot_time2'];
		if($shoot_time2 < $shoot_time1){
			form_set_error('bxdev_shoot_time2', 'End time cannot be less than start time');
		}		
	}
	
}

/**
 * Form builder: photo approval
 */
function bxdev_project_photo_approval_form($form, $form_state){
	$form = array();
	$node = node_load(arg(1));
	$render = node_view($node, 'teaser');
	$full = node_view($node, 'full');
	
	// if photos have been assigned
	if(!empty($render['field_project_photos'])){
		
		// get stored values
		$results = db_query("SELECT fid FROM {project_photos_approval} WHERE nid = :nid", array(':nid' => $node->nid));
		$defaults = array();
		if($results->rowCount() > 0){
			foreach($results as $row){
				$defaults[] = $row->fid;
			}
		}
		
		// build the images and checkboxes
		foreach($render['field_project_photos'] as $key => $value){
			if(is_numeric($key)){
				$path = file_create_url($full['field_project_photos'][$key]['#item']['uri']);
				$form['approve'][$value['#item']['fid']] = array(
				  '#type' => 'checkbox',
				  '#title' => t('Approve'),
				  '#default_value' => in_array($value['#item']['fid'], $defaults),
					'#prefix' => '<div class="photo-wrap"><a rel="shadowbox[images]" href="' . image_style_url('approval', $full['field_project_photos'][$key]['#item']['uri']) . '">' . theme($value['#theme'], $value) . '</a>',
					'#suffix' => '</div>',
				);				
			}
		}
		
		// submit button
		$form['submit'] = array(
		  '#type' => 'submit',
		  '#value' => t('Submit'),
		);		
		
	// photos have not been assigned
	}else{
		$form['no_photos'] = array(
			'#markup' => t('No photos assigned.'),
		);
	}
	
	return $form;
}

/**
 * Form submit handler: photo approval form
 */
function bxdev_project_photo_approval_form_submit($form, &$form_state){
	$nid = arg(1);
	$values = $form_state['values'];
	// clear all values for current node
	db_delete('project_photos_approval')
		->condition('nid', $nid)
		->execute();
	// store each new value
	foreach($values as $key => $value){
		if(is_numeric($key)){
			if($value){
				db_insert('project_photos_approval')
					->fields(array(
						'nid' => $nid,
						'fid' => $key,
					))
					->execute();
			}
		}
	}
	drupal_set_message('Photo approvals have been updated.');
	$form_state['redirect'] = 'node/' . $nid;
}

/**
 * Form validation handler: photo approval form
 */
function bxdev_project_photo_approval_form_validate($form, &$form_state){
	$values = $form_state['values'];
	$count = 0;
	// cycle through each photo and allow no more than eight choices
	foreach($values as $key => $value){
		if(is_numeric($key)){
			$count += $value;
		}
	}
	// check if greater than 8
	if($count > 8){
		form_error($form, 'A maximum of 8 choices can be approved.');
		return FALSE;
	}
}

/**
 * Form builder: business logo
 */
function bxdev_project_logo_upload_form($form, &$form_state){
	$nid = arg(1);
	$node = node_load($nid);
	$count = 0;
	
	$form['#tree'] = TRUE;
	
	$form['title']['#markup'] = t('<label>Business logos and photos</label>');
	$form['title']['#prefix'] = '<div class="logo-upload-wrapper">';
	
	if(!empty($node->field_logo['und'])){
		foreach($node->field_logo['und'] as $key => $fid){
			$form['business_logo'][$key] = array(
				'#type' => 'managed_file',
				'#size' => 30,
				'#default_value' => $fid['fid'],
				'#upload_location' => 'public://business_logos',
				'#upload_validators' => array(
					'file_validate_extensions' => array('jpg jpeg gif png pdf'),
				),
			);
			$count++;	
		}
	}
	
	$form['business_logo'][$count] = array(
		'#type' => 'managed_file',
		'#size' => 30,
		'#upload_location' => 'public://business_logos',
		'#upload_validators' => array(
			'file_validate_extensions' => array('jpg jpeg gif png pdf eps'),
		),
	);
	
	$form['save'] = array(
	  '#type' => 'submit',
	  '#value' => t('Save'),
		'#suffix' => '</div>',
	);	
	
	return $form;
}

/**
 * Form submit handler: business logo
 */
function bxdev_project_logo_upload_form_submit($form, &$form_state){
	$values = $form_state['values'];
	$nid = arg(1);
	$node = node_load($nid);
	unset($node->field_logo['und']);
	foreach($values['business_logo'] as $key => $fid){
		if($fid !== 0){
			// get the file object
			$file = file_load($fid);
			$file->status = FILE_STATUS_PERMANENT;
			file_save($file);
			// create a file array to attach to the node
			$node_file = array(
				'uid' => $file->uid,
				'uri' => $file->uri,
				'fid' => $file->fid,
				'status' => 1,
				'display' => 1,
				'description' => '',
			);
			$node->field_logo['und'][$key] = $node_file;	
		}		
	}
	node_save($node);
}

/**
 * Form builder: videographer documents
 */
function bxdev_project_videographer_documents_form($form, &$form_state){
	$nid = arg(1);
	$node = node_load($nid);
	
	$form['signed_production_release'] = array(
		'#type' => 'managed_file',
		'#title' => t('Signed production release'),
		'#size' => 15,
		'#default_value' => (!empty($node->field_signed_production_release['und'][0])) ? $node->field_signed_production_release['und'][0]['fid'] : '',
		'#upload_location' => 'public://videographer_forms',
		'#upload_validators' => array(
			'file_validate_extensions' => array('jpg jpeg gif png pdf doc docx'),
		),
	);
	
	$form['videographer_invoice'] = array(
		'#type' => 'managed_file',
		'#title' => t('Videographer invoice'),
		'#size' => 15,
		'#default_value' => (!empty($node->field_videographer_invoice['und'][0])) ? $node->field_videographer_invoice['und'][0]['fid'] : '',
		'#upload_location' => 'public://videographer_forms',
		'#upload_validators' => array(
			'file_validate_extensions' => array('jpg jpeg gif png pdf doc docx'),
		),
	);
	
	$form['save'] = array(
	  '#type' => 'submit',
	  '#value' => t('Save'),
	);	
	
	return $form;
}

/**
 * Form submit handler: videographer documents
 */
function bxdev_project_videographer_documents_form_submit($form, &$form_state){
	$values = $form_state['values'];
	$nid = arg(1);
	$node = node_load($nid);
		
	// if no file, remove logo file from the node
	if(empty($values['signed_production_release'])){
		unset($node->field_signed_production_release['und'][0]);
	}else{
		// get the file object
		$file = file_load($values['signed_production_release']);
		$file->status = FILE_STATUS_PERMANENT;
		file_save($file);
		// create a file array to attach to the node
		$node_file = array(
			'uid' => $file->uid,
			'uri' => $file->uri,
			'fid' => $file->fid,
			'status' => 1,
			'display' => 1,
			'description' => '',
		);
		$node->field_signed_production_release['und'][0] = $node_file;
	}
	
	// if no file, remove logo file from the node
	if(empty($values['videographer_invoice'])){
		unset($node->field_videographer_invoice['und'][0]);
	}else{
		// get the file object
		$file = file_load($values['videographer_invoice']);
		$file->status = FILE_STATUS_PERMANENT;
		file_save($file);
		// create a file array to attach to the node
		$node_file = array(
			'uid' => $file->uid,
			'uri' => $file->uri,
			'fid' => $file->fid,
			'status' => 1,
			'display' => 1,
			'description' => '',
		);
		$node->field_videographer_invoice['und'][0] = $node_file;
	}
	
	node_save($node);
	
}

/**
 * Form builder: client terms
 */
function bxdev_project_client_terms_form($form, &$form_state, $nid, $hash){
	
	$form['markup'] = array(
		'#markup' => '<p>You made it!  Now, for the fun legal stuff.  The client service agreement specifies the terms and conditions of our work together.  Additionally, it includes a release to let us shoot video in your place.</p>
		<p>Please click the link below to read the client service agreement.  Once you’ve reviewed, you can accept the agreement by clicking the check box and submitting.</p>
		<p>We will send a copy of the accepted client service agreement to your email address.</p>
		<p><a href="/get/document/document_client_service_agreement/' . $nid . '" rel="shadowbox;height=800;width=800">Click here to view the terms</a></p>'
	);
	
	$form['terms_accept'] = array(
	  '#type' => 'checkbox',
	  '#title' => t('I accept the Client Service Agreement'),
	  '#default_value' => 0,
	);
	
	$form['submit'] = array(
	  '#type' => 'submit',
	  '#value' => t('Submit'),
	);
	
	$form['#submit'][] = 'bxdev_project_client_terms_form_submit';	
	$form['#submit'][] = 'bxdev_document_client_terms_form_submit';	
	
	return $form;
}

/**
 * Form validate: client terms
 */
function bxdev_project_client_terms_form_validate($form, &$form_state){
	$values = $form_state['values'];
	if($values['terms_accept'] != 1){
		form_set_error('terms_accept', 'The Client Service Agreement must be accepted');
	}
}

/**
 * Form submit: client terms
 */
function bxdev_project_client_terms_form_submit($form, &$form_state){
	$nid = arg(2);
	$node = node_load($nid);
	$node->field_client_terms_accepted['und'][0]['value'] = 1;
	node_save($node);
	
	// expire the page by removing the hash entry from the db
	db_delete('users_project_terms')
		->condition('nid', $nid)
		->execute();
}




/**
 * Implements hook_form_alter(). PC landing exposed filter alter.
 */
function bxdev_project_form_alter(&$form, &$form_state, $form_id) {
  if($form['#id'] == 'views-exposed-form-projects-pc-landing'){
		// get the business drop down options
		$options = $form['field_project_business_ref_nid']['#options'];
		global $user;
		// get all businesses associated with current user
		$results = db_query("SELECT field_data_field_project_business_ref.field_project_business_ref_nid as nid FROM {field_data_field_project_business_ref} INNER JOIN {field_data_field_pc_ref} ON field_data_field_project_business_ref.entity_id = field_data_field_pc_ref.entity_id WHERE field_data_field_pc_ref.field_pc_ref_uid = :uid", array(':uid' => $user->uid));
		// if businesses exist
		if($results->rowCount() > 0){
			// build an array of business nids
			$business_nids = array();
			foreach($results as $row){
				$business_nids[$row->nid] = $row->nid;
			}
			// get only businesses links to the current user
			$new_options = array_intersect_key($options, $business_nids);
			// add the "Any" option
			$new_options['All'] = '- Any -';
			// sort alphabetically by key
			asort($new_options);
			// assign the new options
			$form['field_project_business_ref_nid']['#options'] = $new_options;
		}
	}
}


/**
 * CUSTOM
 */

/**
 * Return shoot date form markup
 */
function bxdev_project_shoot_date_form_markup(){
	
	drupal_add_library('system', 'ui.datepicker');
  drupal_add_library('date_popup', 'timeentry');

	$times = bxdev_get_times_array();
	
	// create a fieldset
	$form['bxdev_shoot_date_fieldset'] = array(
		'#type' => 'fieldset',
		'#weight' => 13,
		'#attributes' => array(
			'class' => array('clearfix'),
		),
	);
	// create a custom date field
	$form['bxdev_shoot_date_fieldset']['bxdev_shoot_date'] = array(
		'#type' => 'textfield',
		'#title' => t('Shoot date'),
		'#required' => TRUE,
		'#default_value' => (!empty($form['field_shoot_date']['und'][0]['#default_value']['value'])) ? date('m/d/Y', $form['field_shoot_date']['und'][0]['#default_value']['value']) : '',
	);
	// create a custom start time field
	$form['bxdev_shoot_date_fieldset']['bxdev_shoot_time1'] = array(
		'#title' => t('Start time'),
		'#type' => 'select',
		'#required' => TRUE,
		'#options' => $times,
		'#default_value' => (!empty($form['field_shoot_date']['und'][0]['#default_value']['value'])) ? date('G:i', $form['field_shoot_date']['und'][0]['#default_value']['value']) : '',
	);
	// create a custom end time field
	$form['bxdev_shoot_date_fieldset']['bxdev_shoot_time2'] = array(
		'#title' => t('End time'),
		'#type' => 'select',
		'#options' => $times,
		'#default_value' => ($form['field_shoot_date']['und'][0]['#default_value']['value2'] != $form['field_shoot_date']['und'][0]['#default_value']['value']) ? date('G:i', $form['field_shoot_date']['und'][0]['#default_value']['value2']) : '',
	);
	
	return $form;
}



