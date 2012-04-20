<?php

/**
 * Contains all information related to a single project
 */
class Project {
	
	var $project;
	var $project_path;
	var $business;
	var $client;
	var $videographer;
	var $pc;
	var $sales;
	var $comments;
	var $overridden;
	var $approved;
	var $hash;
	
	/**
	 * Load a new Project and set all initial variables.
	 *
	 * @param $nid (int)
	 *   The nid of the project node
	 */
	function __construct($nid){
		// load the users
		$project = node_load($nid);
		$business = node_load($project->field_project_business_ref['und'][0]['nid']);
		$client = user_load($business->field_client_ref['und'][0]['uid']);
		$sales = '';
		$pc = '';
		$videographer = '';
		// if pc has been assigned to the project
		if(!empty($project->field_pc_ref)){
			$pc = user_load($project->field_pc_ref['und'][0]['uid']);
		}
		// if videographer has been assigned to the project
		if(!empty($project->field_videog_ref)){
			$videographer = user_load($project->field_videog_ref['und'][0]['uid']);
		}
		// if sales has been assigned to the project
		if(!empty($project->field_author['und'][0]['uid'])){
			$sales = user_load($project->field_author['und'][0]['uid']);
		}
		// assign all intitial properties
		$this->project = $project;
		$this->project_path = drupal_lookup_path('alias', 'node/' . $this->project->nid);
		$this->business = $business;
		$this->client = $client;
		$this->sales = $sales;		
		$this->pc = $pc;
		$this->videographer = $videographer;		
		$this->comments = $this->get_comments();
		$this->overridden = $project->field_status_override['und'][0]['value'];
		$this->approved = $project->field_approved['und'][0]['value'];
	}
	
	/**
	 * Log an action performed on or by the Project.
	 *
	 * @param $type (string)
	 *   The type of action to log
	 *
	 * @param $message (string)
	 *   The message to log with the action.
	 */
	function log($type, $message){
		global $user;
		// get the user role
		$role = bxdev_user_get_role($user->uid);
		// store in db
		db_insert('production_log')
			->fields(array(
				'project_nid' => $this->project->nid,
				'business_nid' => $this->business->nid,
				'client_uid' => $this->client->uid,
				'user_uid' => $user->uid,
				'user_role' => $role,
				'type' => $type,
				'message' => $message,
			))
			->execute();
	}
	
	/**
	 * Set the status of the Project.
	 *
	 * @param $id (int)
	 *   The id of the status (1 - 7)
	 */
	function set_status($id){
		$this->project->field_status['und'][0]['value'] = $id;
		$this->project->field_status_date['und'][0]['value'] = time();
		node_save($this->project);
	}
	
	/**
	 * Get the current status of a Project.
	 *
	 * @return int
	 */
	function get_status(){
		return $this->project->field_status['und'][0]['value'];
	}
	
	/**
	 * Get all users associated with a Project.
	 *
	 * @return array
	 */	
	function get_users(){
		$users = array();
		if(!empty($this->client)){
			$users[$this->client->uid] = $this->client;
		}
		if(!empty($this->pc)){
			$users[$this->pc->uid] = $this->pc;
		}
		if(!empty($this->videographer)){
			$users[$this->videographer->uid] = $this->videographer;
		}
		if(!empty($this->sales)){
			$users[$this->sales->uid] = $this->sales;
		}
		return $users;		
	}
	
	/**
	 * Notify all appropriate users when a comment has been posted.
	 *
	 * @param $cid (int)
	 *   The nid of the comment node
	 */
	function comment_notify($cid){
		global $base_url;
		// construct the project link
		$project_link = $base_url . '/' . $this->project_path;
		// load the comment node object
		$comment = node_load($cid);
		// get the comment type
		$comment_type = $comment->field_comment_type['und'][0]['value'];
		// get the poster's uid
		$owner_uid = $comment->uid;
		$users = array();
		$users[$this->pc->uid] = $this->pc;
		if($comment_type == 'client'){
			$users[$this->client->uid] = $this->client;
		}else if($comment_type == 'videographer'){
			$users[$this->videographer->uid] = $this->videographer;
		}
		// remove the poster
		unset($users[$owner_uid]);
		$comment_author = user_load($comment->uid);
		$comment_author = $comment_author->field_name['und'][0]['value'];
		// set all params to pass to the email message
		$params = array();
		$params['project'] = $this;
		$params['comment_author'] = $comment_author;
		$params['comment_date'] = date('m-d-Y', $comment->created);
		$params['comment'] = nl2br($comment->field_comment['und'][0]['value']);
		foreach($users as $uid => $user){
			drupal_mail('bxdev_project', 'comment', $user->mail, language_default(), $params);
		}

		if($comment->uid == $this->client->uid){
			drupal_mail('bxdev_project', 'comment', 'editors@lightswitch.com', language_default(), $params);
		}
		
	}

	/**
	 * Get all comments that belong to a Project.
	 *
	 * @return array
	 */
	function get_comments(){
		$comments = array();
		$results = db_query("SELECT entity_id FROM {field_data_field_project_ref} WHERE field_project_ref_nid = :nid", array(':nid' => $this->project->nid));
		if($results->rowCount() > 0){
			foreach($results as $result){
				$comment = node_load($result->entity_id);
				$comments[$comment->nid] = $comment;
			}
		}
		return $comments;
	}
	
	/**
	 * Send an email to the PC and Sales when a Project has been claimed.
	 */
	function send_claim($uid){
		$account = user_load($uid);
		// build params to pass to the email message
		$params = array('project' => $this);		
		drupal_mail('bxdev_project', 'project_claimed', $account->mail, language_default(), $params);
	}
	
	/**
	 * Notify all appropriate users when a Project has been approved.
	 */
	function send_approved(){
		global $base_url;
		$params['project'] = $this;
		// build a list of email addresses (pc, sales, and client)
		$emails[] = $this->pc->mail;
		$emails[] = $this->sales->mail;
		$emails[] = $this->client->mail;
		$emails[] = 'editors@lightswitch.com';
		foreach($emails as $email){
			if($email != ''){
				drupal_mail('bxdev_project', 'approved', $email, language_default(), $params);
			}
		}
	}
	
	/**
	 * Notify all appropriate users when a Project has been manually approved.
	 */
	function send_approved_manual(){
		global $base_url;
		$system_email;
		$params['project'] = $this;
		$bcc = !empty($this->pc->mail) ? $this->pc->mail . ', editors@lightswitch' : 'editors@lightswitch';
		$params['headers']['bcc'] = $bcc;
		
		$user = user_load($this->client->uid);
		
		if($user->data['first_time_login'] == 1){
			$system_email = 'project_approved_pc_new';
		}else{
			$system_email = 'project_approved_pc_existing';
		}
		
		drupal_mail('bxdev_project', $system_email, $this->client->mail, language_default(), $params);
	}
	
	/**
	 * Send email to pc notifying of a declined revision list
	 */
	function send_revision_declined($cid){
		global $base_url;
		$comment = node_load($cid);
		// build params to pass to the email message		
		$params = array(
			'project' => $this,
			'declined_reason' => nl2br($comment->field_declined_reason['und'][0]['value']),
		);		
		drupal_mail('bxdev_project', 'revision_declined', $this->pc->mail, language_default(), $params);		
	}
	
	/**
	 * Send email to pc and videographer notifying of an approved revision list
	 */
	function send_revision_approved($cid){
		global $base_url;
		$comment = node_load($cid);
		$emails = $this->pc->mail;
		// build params to pass to the email message
		$params = array(
			'project' => $this,
			'comment' => nl2br($comment->field_comment['und'][0]['value']),
		);		
		drupal_mail('bxdev_project', 'revision_approved', $emails, language_default(), $params);		
	}
	
	/**
	 * Send email to newly assigned sales user
	 */
	function send_sales_assigned($uid){
		global $base_url;
		$account = user_load($uid);
		// build params to pass to the email message
		$params = array('project' => $this);		
		drupal_mail('bxdev_project', 'sales_assigned', $account->mail, language_default(), $params);
	}
	
	/**
	 * Send notification of new Project to all PCs
	 */
	function send_new_project_notify(){
		global $base_url;
		// build the project link
		module_load_include('inc', 'pathauto');
		$path = pathauto_create_alias('node', 'return', 'node/' . $this->project->nid, array('node' => $this->project), $this->project->type);
		$project_link = $base_url . '/' . $path;
		// get all pc users
		$results = db_query("SELECT DISTINCT uid FROM users_roles WHERE rid = 4");
		if($results->rowCount() > 0){
			$emails = array();
			foreach($results as $row){
				$account = user_load($row->uid);
				$emails[] = $account->mail;
			}
			// $emails = implode(',', $emails);
			$emails = 'wandoledzep@gmail.com';
			$params = array('project' => $this, 'project_link' => $project_link);		
			drupal_mail('bxdev_project', 'project_added', $emails, language_default(), $params);
		}
	}
	
	/**
	 * For direct sales Projects, send email to Clients prompting the acceptance of terms
	 */
	function send_client_terms(){
		$params = array('project' => $this);
		drupal_mail('bxdev_project', 'client_terms', $this->client->mail, language_default(), $params);
	}
	
	/**
	 * Creates a hash value used to match a user with a Project (for accepting the client service agreement)
	 */
	function create_client_terms_hash(){
		// generate a random hash to associate with the client / project
		$hash = md5(user_password());
		// delete any existing hashes
		db_delete('users_project_terms')
			->condition('nid', $this->project->nid)
			->execute();
		// store the new value
		db_insert('users_project_terms')
			->fields(array(
				'nid' => $this->project->nid,
				'hash' => $hash,
			))
			->execute();
		$this->hash = $hash;		
	}
	
	/**
	 * Send confirm message and pdf Client Service Agreement after Client accepts terms
	 */
	function send_client_service_agreement($fid){
		// generate the mail to string
		$emails[] = $this->client->mail;
		// $emails[] = $this->sales->mail;
		
		$params['project'] = $this;
		
		// attach the pdf file
		$file = file_load($fid);
		$params['attachments'] = array(
			0 => array(
				'filepath' => $file->uri,
				'filename' => $file->filename,
			),
		);
		
		foreach($emails as $email){
			drupal_mail('bxdev_project', 'client_service_agreement_accepted', $email, language_default(), $params);
		}
	}
	
	/**
	 * Generate a pdf receipt and send to client
	 *
	 * @param $line_items (array)
	 *   $line_items['qty'] = Line quantity
	 *   $line_items['description'] = Line description
	 *   $line_items['unit_price'] = Line unit_price
	 *   $line_items['line_total'] = Line total
	 */
	function send_client_receipt($line_items, $payment_id){
		
		// generate the invoice number
		$invoice_num = variable_get('client_invoice_num', 101);
		variable_set('client_invoice_num', ++$invoice_num);
		
		// get the invoice html
		$html = theme('invoice_client', array('project' => $this, 'line_items' => $line_items, 'invoice_num' => $invoice_num));
		
		// generate a clean client name used in the file name
		$client_name = bxdev_get_filename_string($this->client->field_name['und'][0]['value']);
		
		// generate the filename
		$filename = 'lightswitch_receipt_' . $client_name . '_' . $invoice_num . '.pdf';
		
		// create the pdf and get the fid
		$fid = bxdev_document_create_pdf($html, $filename, 'client', 'invoices', 'Client Invoice', $this->client->uid, $this->project->nid);
		
		if($fid){
			
			$emails[] = $this->client->mail;
			// $emails[] = 'accounting@bxcreative.com';
			// $emails[] = 'tom@lightbank.com';
			$emails[] = 'jason@lightswitch.com';
			
			$params = array(
				'project' => $this,
				'cc' => bxdev_payment_get_cc_last_four($payment_id, $this->client->uid),
				'amount' => $line_items['total'],
			);
			
			$file = file_load($fid);
			$params['attachments'] = array(
				0 => array(
					'filepath' => $file->uri,
					'filename' => $file->filename,
				),
			);
			
			// send the email to each recipient
			foreach($emails as $email){
				drupal_mail('bxdev_project', 'client_invoice_receipt', $email, language_default(), $params);
			}
			
			// log the action
			watchdog('document', 'Client invoice generated for: ' . $this->client->field_name['und'][0]['value']);
			
		}
		
	}
	
	/**
	 * Send reminder to videographer to upload a W9 form
	 */
	function send_videographer_w9_reminder($amount, $description){
		global $base_url;
		$params = array(
			'project' => $this,
			'full_name' => $this->videographer->field_name['und'][0]['value'],
			'login_link' => '<a href="' . $base_url . '/user">' . $base_url . '/user</a>',
		);
		drupal_mail('bxdev_project', 'videographer_missing_w9', $this->videographer->mail, language_default(), $params);
		
		// delete any existing reminders for the videographer and project
		db_delete('users_w9_reminders')
			->condition('uid', $this->videographer->uid)
			->condition('nid', $this->project->nid)
			->execute();
		
		db_insert('users_w9_reminders')
			->fields(array(
				'uid' => $this->videographer->uid,
				'nid' => $this->project->nid,
				'amount' => $amount,
				'description' => $description,
			))
			->execute();
	}
	
	/**
	 * Send a notification to the Videographer when assigned to a project
	 */
	function send_videographer_project_assign($email){
		global $base_url;
		$params = array(
			'project' => $this,
			// 'full_name' => $this->videographer->field_name['und'][0]['value'],
		);
		drupal_mail('bxdev_project', 'videographer_project_assign', $email, language_default(), $params);
	}
	
	/**
	 * Send a notification to the Sales user after a Client has clicked the "Contact Me" button on a spec video
	 */
	function send_spec_contact(){
		$params['project'] = $this;
		drupal_mail('bxdev_project', 'spec_contact_button', $this->sales->mail, language_default(), $params);
	}
	
	/**
	 * Send a notification to the Client informing of the spec video
	 */
	function send_spec_client(){
		$params['project'] = $this;
		drupal_mail('bxdev_project', 'spec_client', $this->client->mail, language_default(), $params);
	}
	
	/**
	 * Initiate a videographer payment by sending the W9 and invoice to Lightswitch accounting
	 *
	 * @param $w9 (object)
	 *   - Drupal file object
	 *
	 * @param $amount (int)
	 *   - Amount to be charged
	 */
	function process_videographer_payment($w9, $amount, $description){
		
		/**
		 * Generate the invoice
		 */
		$line_items = array();
		$line_items[] = array(
			'project' => $this,
			'qty' => 1,
			'description' => $description,
			'unit_price' => $amount,
			'line_total' => $amount,
		);
		$line_items['total'] = $amount;
		
		// get the next invoice number
		$invoice_num = variable_get('client_invoice_num', 101);
		variable_set('client_invoice_num', ++$invoice_num);
		
		// load the videographer profile
		$profile = profile2_load_by_user($this->videographer, 'videographer');
		
		// get the invoice html
		$html = theme('invoice_videographer', array('project' => $this, 'profile' => $profile, 'line_items' => $line_items, 'invoice_num' => $invoice_num));
		
		// create the filename
		$filename = 'lightswitch_videographer_invoice_' . $invoice_num . '.pdf';
		
		// create the pdf and get the fid
		$fid = bxdev_document_create_pdf($html, $filename, 'videographer', 'invoices', 'Videographer invoice', $this->videographer->uid, $this->project->nid);
		
		// if $amount is supplied, charge for that specific payment
		if($fid){
			
			$file = file_load($fid);
			
			$params = array(
				'project' => $this,
				'amount' => $amount,
				'attachments' => array(
					0 => array(
						'filepath' => $w9->uri,
						'filename' => $w9->filename,
					),
					1 => array(
						'filepath' => $file->uri,
						'filename' => $file->filename,
					),
				),
			);

			// send the email
			// $accounting_email = 'accounting@bxcreative.com';
			$accounting_email = 'jason@lightswitch.com, tom@lightbank.com';
			$params['headers']['cc'] = $this->pc->mail;
			drupal_mail('bxdev_project', 'accounting_invoice_videographer', $accounting_email, language_default(), $params);

			// log the payment
			bxdev_payment_log_payment($this->project->nid, $this->videographer->uid, NULL, $invoice_num, $amount);

			// log the email
			watchdog('document', 'W9 and invoice sent to accounting for videographer: ' . $this->videographer->uid);
			
			// remove any hanging reminders for the user
			db_delete('users_w9_reminders')
				->condition('uid', $this->videographer->uid)
				->condition('nid', $this->project->nid)
				->execute();		
		}
				
	}
	
	/**
	 * Get all approved photos associated with a Project.
	 *
	 * @return array
	 */
	function get_approved_photos(){
		$results = db_query("SELECT fid FROM {project_photos_approval} WHERE nid = :nid", array(':nid' => $this->project->nid));
		$approved_photos = array();
		if($results->rowCount() > 0){
			foreach($results as $row){
				$approved_photos[] = $row->fid;
			}
		}
		return $approved_photos;
	}
	
}
