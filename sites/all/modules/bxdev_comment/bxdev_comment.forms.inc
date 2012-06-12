<?php

/**
 * Form builder: client comment form
 */
function bxdev_comment_client_form($form, &$form_state){
	
	global $user;
	$nid = arg(1);
	$project = new Project($nid);
	$role = bxdev_user_get_role($user->uid);
	// determine the pre-populated first comment and approve language
	$first_comment = '';
	$approve_language = '';
	if(bxdev_user_check_partner_theme($project->client->uid) == 'Tribune LocalTrack'){
		$first_comment = "We hope you like your LocalTrack video. Included with your video is one free round of revisions. If you have any changes you would like to make, please list them all in detail here and our editors will get to work as soon as you submit your comments. If multiple people are commenting, please gather all comments first, and then submit them all in one post.\n\nIf you love your video as is and don't have any changes, simply click \"Approve\" and you will receive an email link to your final video within three business days.\n\nPlease note, if you do not submit any revisions within 7 business days, your video will be approved and you will receive an email link to your final video and photos, along with tips for all of the great places you can start using your video! Once your video is approved, you will be solely responsible for the content in your video.";
		$approve_language = '<h3>Are you sure you wish to approve this project?</h3><p>After approval, comments will no longer be able to be posted.<br />Once you approve your video, you will be solely responsible for the content.</p>';
	}else{
		$first_comment = 'Lightswitch has completed a cut of your video, and it\'s ready for you to view.  As a valued Lightswitch client, you receive one free round of video edits.  If you have changes you\'d like to make to the video, please comment below with your revision requests.  Please make all of your requests very specific so we can work to get your lightswitch video exactly how you want it!  Referencing the minutes and seconds can be helpful to pinpoint sections you\'d like revised.  If you are happy with the video in its current form, please click “approve” and we’ll send you the final video in convenient file formats. You have 5 days to submit revision requests, after which the video will be considered approved as is.';
		$approve_language = '<h3>Are you sure you wish to approve this project?</h3><p>After approval, comments will no longer be able to be posted.</p>';
	}

	$zero_comments = $role == 'pc' ? $first_comment : '';
	
	$form['comment'] = array(
	  '#type' => 'textarea',
		'#title' => t('Post a comment:'),
		'#default_value' => (count($project->comments) == 0) ? $zero_comments : t('Type your comments here...'),
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
	
	$form['approve'] = array(
		'#type' => 'submit',
		'#value' => t('Approve final video'),
		'#prefix' => '<div class="approve-or">or</div>',
		'#attributes' => array(
			'class' => array('approve-btn'),
		),
		'#access' => user_access('client'),
	);
	
	
	$form['approve_confirm'] = array(
		'#markup' => '<div class="approve-confirm" style="display:none;">' . $approve_language . '<a class="approve-yes" href="/project/' . $nid . '/approve">Approve</a> <a href="" class="approve-cancel">Cancel</a></div>',
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
	$node->field_comment_type['und'][0]['value'] = 'client';

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
	// set declined reason
	$comment_node->field_declined_reason['und'][0]['value'] = $values['decline_reason'];
	// set declined date
	$comment_node->field_declined_date['und'][0]['value'] = mktime();
	// save the comment
	node_save($comment_node);
	$project = new Project(arg(1));
	$project->send_revision_declined($comment_node->nid);
}

/**
 * Form builder: videographer comment form
 */
function bxdev_comment_videographer_form($form, &$form_state){
	
	$nid = arg(1);
	$project = new Project($nid);
	
	$form['comment'] = array(
	  '#type' => 'textarea',
		'#title' => t('Post a comment:'),
		'#default_value' => t('Type your comments here...'),
	);
	
	$form['submit'] = array(
	  '#type' => 'submit',
	  '#value' => t('Post comment'),
	);
	
	return $form;	
}

/**
 * Form validation handler: videographer comment form
 */
function bxdev_comment_videographer_form_validate($form, &$form_state){
	
	$values = $form_state['values'];
	
	// make sure comment field is not empty
	if(empty($values['comment'])){
		form_set_error('comment', 'Enter a comment');
	}
		
}

/**
 * Form submit handler: videographer comment form
 */
function bxdev_comment_videographer_form_submit($form, &$form_state){
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
	$node->field_comment_type['und'][0]['value'] = 'videographer';

	node_save($node);
	
}


