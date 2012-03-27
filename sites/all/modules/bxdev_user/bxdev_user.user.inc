<?php

/**
 * Creates or loads a user. Contains custom role / email functionality. 
 */
class User {
	
	var $password;
	var $user;
	var $name;
	var $mail;
	var $full_name;
	var $phone;
	var $roles;
	var $role;
	
	/**
	 * Create a new User object.
	 *
	 * @param $email (string)
	 *   User email address. Will act as the username.
	 *
	 * @param $role (string)
	 *   User role (pc, sales, client, videographer).
	 *
	 * @param $full_name (string)
	 *   User full name.
	 *
	 * @param $phone (string)
	 *   User phone number.
	 */
	function __construct($email = NULL, $role = NULL, $full_name = NULL, $phone = NULL){
		$this->password = user_password();
		// if arguments have been supplied, create the user and send a notification email
		if(!is_null($email) && !is_null($role)){
			$this->set_email($email);
			$this->set_role($role);
			$this->set_full_name($full_name);
			$this->set_phone($phone);
			$this->create();
			$this->send();
			$this->log();
		}
	}
	
	/**
	 * Load a User.
	 *
	 * @param $uid (int)
	 *   User id (uid)
	 */
	function load($uid){
		$this->user = user_load($uid);
		$role = bxdev_user_get_role($uid);
		$this->set_role($role);
	}
	
	/**
	 * Create a new user.
	 */
	function create(){
		$edit = array(
			'name' => $this->name,
			'mail' => $this->name,
			'pass' => $this->password,
			'roles' => $this->roles,
			'status' => 1,
		);
		if(isset($this->full_name)){
			$edit['field_name']['und'][0]['value'] = $this->full_name;
		}
		if(isset($this->phone)){
			$edit['field_phone']['und'][0]['value'] = $this->phone;
		}		
		$this->user = user_save(NULL, $edit);
	}
	
	/**
	 * Set the User's email address.
	 *
	 * @param $email (string)
	 *   User email address. Will act as the username.
	 */
	function set_email($email){
		$this->name = $email;
		$this->mail = $email;
	}
	
	/**
	 * Set the User's full name.
	 *
	 * @param $full_name (string)
	 *   User's full name.
	 */
	function set_full_name($full_name){
		$this->full_name = $full_name;
	}
	
	/**
	 * Set the User's phone.
	 *
	 * @param $phone (string)
	 *   User's phone.
	 */
	function set_phone($phone){
		$this->phone = $phone;
	}	
	
	/**
	 * Set the User's role.
	 *
	 * @param $role (string)
	 *   User role (pc, sales, client, videographer).
	 */
	function set_role($role){
		switch($role){
			case 'sales':
				$this->roles = array(2 => 'authenticated user', 6 => 'sales');
				$this->role = 'sales';
				break;
			
			case 'client':
				$this->roles = array(2 => 'authenticated user', 7 => 'client');
				$this->role = 'client';
				break;	
				
			case 'pc':
				$this->roles = array(2 => 'authenticated user', 4 => 'production coordinator');
				$this->role = 'pc';
				break;
				
			case 'videographer':
				$this->roles = array(2 => 'authenticated user', 5 => 'videographer');
				$this->role = 'videographer';
				break;
		}	
	}
	
	/**
	 * Reset the User's password.
	 */
	function reset_password(){
		$edit = (array)$this->user;
		$edit['pass'] = $this->password;
		$edit['data']['first_time_login'] = 1;
		$this->user = user_save($this->user, $edit);
	}
	
	/**
	 * Send an email to the User contain login information.
	 */
	function send(){
		global $base_url;
		$params = array(
			'username' => $this->user->name,
			'password' => $this->password,
			'full_name' => $this->user->field_name['und'][0]['value'],
			'login_link' => '<a href="' . $base_url . '/user">' . $base_url . '/user</a>',
		);
		drupal_mail('bxdev_user', $this->role, $this->user->mail, language_default(), $params);
	}
	
	/**
	 * Send an email to the Client user containing login / project info.
	 *
	 * @param $project (object)
	 *   Full Project object.
	 */
	function send_client_project_login($project){
		
		$params['project'] = $project;
		
		$system_email = '';
		$emails = array();
		$emails[] = $this->user->mail;
		$emails[] = $this->pc->mail;
		$emails[] = 'editors@lightswitch.com';
		
		// if client has never logged in (is new)
		if($this->user->data['first_time_login'] == 1){
			// reset the password
			$this->reset_password();
			// if project is spec
			if($project->project->field_video_type['und'][0]['value'] == 'spec'){
				// drupal_mail('bxdev_user', 'first_comment_spec_new', $this->user->mail, language_default(), $params);
				$system_email = 'first_comment_spec_new';
			// if project is direct sale
			}else if($project->project->field_video_type['und'][0]['value'] == 'direct_sale'){
				// drupal_mail('bxdev_user', 'first_comment_direct_sale_new', $this->user->mail, language_default(), $params);
				$system_email = 'first_comment_direct_sale_new';
			}else{
				// drupal_mail('bxdev_user', 'first_comment_business_dev_new', $this->user->mail, language_default(), $params);
				$system_email = 'first_comment_business_dev_new';
			}
		// if client has logged in before (existing)
		}else{
			// if project is spec
			if($project->project->field_video_type['und'][0]['value'] == 'spec'){
				// drupal_mail('bxdev_user', 'first_comment_spec_existing', $this->user->mail, language_default(), $params);
				$system_email = 'first_comment_spec_existing';
			// if project is direct sale
			}else if($project->project->field_video_type['und'][0]['value'] == 'direct_sale'){
				// drupal_mail('bxdev_user', 'first_comment_direct_sale_existing', $this->user->mail, language_default(), $params);
				$system_email = 'first_comment_direct_sale_existing';
			}else{
				// drupal_mail('bxdev_user', 'first_comment_business_dev_existing', $this->user->mail, language_default(), $params);
				$system_email = 'first_comment_business_dev_existing';
			}	
		}
		
		// send all emails
		foreach($emails as $email){
			if($email != ''){
				drupal_mail('bxdev_user', $system_email, $email, language_default(), $params);
			}
		}
		
		$project->log('admin', 'Login information reset and sent to Client');
	}
	
	/**
	 * Reset a User's password and send a notification email.
	 */
	function send_password_reset(){
		global $base_url;
		$this->reset_password();
		$params = array(
			'username' => $this->user->name,
			'password' => $this->password,
			'login_link' => '<a href="' . $base_url . '/user">' . $base_url . '/user</a>',
		);
		drupal_mail('bxdev_user', 'password_reset', $this->user->mail, language_default(), $params);
	}
	
	/**
	 * Create a watchdog entry for the User.
	 */
	function log(){
		switch($this->role){
			case 'sales':
				watchdog('lightswitch', 'New sales: @name, uid: @uid', array('@name' => $this->user->name, '@uid' => $this->user->uid));
				break;
				
			case 'client':
				watchdog('lightswitch', 'New client: @name, uid: @uid', array('@name' => $this->user->name, '@uid' => $this->user->uid));
				break;
				
			case 'pc':
				watchdog('lightswitch', 'New project coordinator: @name, uid: @uid', array('@name' => $this->user->name, '@uid' => $this->user->uid));
				break;
		}		
	}
	
	/**
	 * Get the Drupal user object.
	 *
	 * @return object
	 */
	function get_user(){
		return $this->user;
	}
	
}
