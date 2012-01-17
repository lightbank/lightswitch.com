<?php

/**
 * Form builder: client comment form
 */
function bxdev_comment_client_form($form, &$form_state){
	$form['comment'] = array(
	  '#type' => 'textarea',
		'#title' => t('Post a comment:'),
	);
	
	$form['revision_list'] = array(
		'#type' => 'checkbox',
		'#title' => t('Revision list'),
		'#access' => user_access('pc'),
	);
	
	$form['submit'] = array(
	  '#type' => 'submit',
	  '#value' => t('Post comment'),
	);
	
	return $form;	
}

/**
 * Form validation handler: client comment form
 */
function bxdev_comment_client_form_validate($form, &$form_state){
	
	$values = $form_state['values'];
	$project_nid = arg(1);
	
	// make sure comment field is not empty
	if(empty($values['comment'])){
		form_set_error('comment', 'Enter a comment');
	}
	
	// check if the project is type "spec"
	$project = new Project($project_nid);
	if($project->project->field_video_type['und'][0]['value'] == 'spec' && empty($project->project->field_author['und'][0]['uid']) && count($project->comments) == 0){
		form_set_error('title', 'A sales user must be assigned before posting a comment to a Project of type <em>Spec</em>');
	}
	
}

/**
 * Form submit handler: client comment form
 */
function bxdev_comment_client_form_submit($form, &$form_state){
	global $user;
	$values = $form_state['values'];
	$nid = arg(1);

	$node = new stdClass();
	$node->language = LANGUAGE_NONE;
	$node->uid = $user->uid;
	$node->type = 'comment';
	
	$node->title = substr($values['comment'], 0, 50);
	$node->field_comment['und'][0]['value'] = $values['comment'];	
	$node->field_project_ref['und'][0]['nid'] = $nid;
	$node->field_revision_list['und'][0]['value'] = $values['revision_list'];

	node_save($node);
	
}

/**
 * Form builder: client decline form
 */
function bxdev_comment_client_decline_form($form, &$form_state, $nid){
	// store the comment nid
	$form_state['comment_nid'] = $nid;
	
	$form['decline_reason'] = array(
		'#type' => 'textarea',
		'#title' => t('Enter the reason(s) for declining the revision list:'),
	);
	
	$form['submit'] = array(
		'#type' => 'submit',
		'#value' => t('Decline and post reason'),
	);
	
	$form['cancel'] = array(
	  '#markup' => '<a href="" class="cancel">Cancel</a>',
	  '#prefix' => '<div class="cancel">',
	  '#suffix' => '</div>',
	);	
	
	return $form;
}

/**
 * Form submit handler: client decline form
 */
function bxdev_comment_client_decline_form_submit($form, &$form_state){
	global $user;
	$values = $form_state['values'];
	$comment_node = node_load($form_state['comment_nid']);
	$comment_node->field_declined_reason['und'][0]['value'] = $values['decline_reason'];
	$comment_node->field_declined_date['und'][0]['value'] = mktime();
	node_save($comment_node);
	
	// $project_nid = arg(1);
	// $project = new Project($project_nid);
	// 
	// $node = new stdClass();
	// $node->language = LANGUAGE_NONE;
	// $node->uid = $user->uid;
	// $node->type = 'comment';
	// 
	// $node->title = $project->project->title . ' - Declined';
	// $node->field_project_ref['und'][0]['nid'] = $project_nid;
	// $node->field_declined_reason['und'][0]['value'] = $values['decline_reason'];

	// node_save($node);	
	
}




