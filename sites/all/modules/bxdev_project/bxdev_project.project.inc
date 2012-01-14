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
		// get the poster's uid
		$owner_uid = $comment->uid;
		// get the sales user's uid
		$sales_uid = $this->sales->uid;
		// get all users associated with Project
		$users = $this->get_users();
		// remove the poster
		unset($users[$owner_uid]);
		// remove the sales user
		unset($users[$sales_uid]);
		foreach($users as $uid => $user){
			$comment_author = user_load($comment->uid);
			$comment_author = $comment_author->field_name['und'][0]['value'];
			// set all params to pass to the email message
			$params = array();
			$params['project_title'] = $this->project->title;
			$params['project_link'] = $project_link;
			$params['comment_author'] = $comment_author;
			$params['comment_date'] = date('m-d-Y', $comment->created);
			$params['comment'] = $comment->field_comment['und'][0]['value'];
			drupal_mail('bxdev_project', 'comment', $user->mail, language_default(), $params);
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
	 * Send an email to the Client containing login and project info.
	 */
	function send_client_login(){
		drupal_mail('bxdev_project', 'first_comment', $this->client->mail, language_default(), array('project_path' => $this->project_path));
		$this->log('admin', 'Client sent login information');
	}
	
	/**
	 * Send an email to the PC and Sales when a Project has been claimed.
	 */
	function send_claim(){
		global $base_url;
		// build the project link
		$project_link = $base_url . '/' . $this->project_path;
		// build a list of email addresses (pc and sales)
		$emails = $this->pc->mail . ', ' . $this->sales->mail;
		// build params to pass to the email message
		$params = array(
			'project_title' => $this->project->title,
			'project_link' => $project_link,			
			'pc' => array(
				'full_name' => $this->pc->field_name['und'][0]['value'],
				'email' => $this->pc->mail,
				'phone' => $this->pc->field_phone['und'][0]['value'],
			),
		);		
		drupal_mail('bxdev_project', 'claimed', $emails, language_default(), $params);
	}
	
	/**
	 * Notify all appropriate users when a Project has been approved.
	 */
	function send_approved(){
		global $base_url;
		// build the project link
		$project_link = $base_url . '/' . $this->project_path;
		// build a list of email addresses (pc, sales, and client)
		$emails = $this->pc->mail . ', ' . $this->sales->mail . ', ' . $this->client->mail;
		// build params to pass to the email message
		$params = array(
			'project_title' => $this->project->title,
			'project_link' => $project_link,			
			'pc' => array(
				'full_name' => $this->pc->field_name['und'][0]['value'],
				'email' => $this->pc->mail,
				'phone' => $this->pc->field_phone['und'][0]['value'],
			),
		);		
		drupal_mail('bxdev_project', 'approved', $emails, language_default(), $params);
	}
	
	/**
	 * Send email to newly assigned sales user
	 */
	function send_sales_assigned($uid){
		global $base_url;
		$account = user_load($uid);
		// build the project link
		$project_link = $base_url . '/' . $this->project_path;
		// build params to pass to the email message
		$params = array(
			'project_title' => $this->project->title,
			'project_link' => $project_link,			
		);		
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
			$emails = implode(',', $emails);
			$emails = 'wandoledzep@gmail.com';
			$params = array(
				'project_title' => $this->project->title,
				'project_link' => $project_link,
				'sales' => $this->sales->field_name['und'][0]['value'],
			);		
			drupal_mail('bxdev_project', 'project_added', $emails, language_default(), $params);
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
