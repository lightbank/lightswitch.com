<?php

/**
 * FORMS
 */

/**
 * Form builder: partner order form
 */
function bxdev_partner_order_form($form, &$form_state){
	
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
		'#type' => 'textfield',
		'#title' => t('City'),
		'#required' => TRUE,
	);
	
	$form['shoot_date'] = array(
		'#type' => 'textfield',
		'#title' => t('Shoot Date'),
		'#required' => TRUE,
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
	
	$form['state'] = array(
		'#type' => 'select',
		'#options' => array(
			'AL'=>'Alabama',  
			'AK'=>'Alaska',  
			'AZ'=>'Arizona',  
			'AR'=>'Arkansas',  
			'CA'=>'California',  
			'CO'=>'Colorado',  
			'CT'=>'Connecticut',  
			'DE'=>'Delaware',  
			'DC'=>'District Of Columbia',  
			'FL'=>'Florida',  
			'GA'=>'Georgia',  
			'HI'=>'Hawaii',  
			'ID'=>'Idaho',  
			'IL'=>'Illinois',  
			'IN'=>'Indiana',  
			'IA'=>'Iowa',  
			'KS'=>'Kansas',  
			'KY'=>'Kentucky',  
			'LA'=>'Louisiana',  
			'ME'=>'Maine',  
			'MD'=>'Maryland',  
			'MA'=>'Massachusetts',  
			'MI'=>'Michigan',  
			'MN'=>'Minnesota',  
			'MS'=>'Mississippi',  
			'MO'=>'Missouri',  
			'MT'=>'Montana',
			'NE'=>'Nebraska',
			'NV'=>'Nevada',
			'NH'=>'New Hampshire',
			'NJ'=>'New Jersey',
			'NM'=>'New Mexico',
			'NY'=>'New York',
			'NC'=>'North Carolina',
			'ND'=>'North Dakota',
			'OH'=>'Ohio',  
			'OK'=>'Oklahoma',  
			'OR'=>'Oregon',  
			'PA'=>'Pennsylvania',  
			'RI'=>'Rhode Island',  
			'SC'=>'South Carolina',  
			'SD'=>'South Dakota',
			'TN'=>'Tennessee',  
			'TX'=>'Texas',  
			'UT'=>'Utah',  
			'VT'=>'Vermont',  
			'VA'=>'Virginia',  
			'WA'=>'Washington',  
			'WV'=>'West Virginia',  
			'WI'=>'Wisconsin',  
			'WY'=>'Wyoming'),
		'#title' => t('State'),
		'#required' => TRUE,
	);
	
	$times = bxdev_get_times_array();
	
	$form['shoot_time'] = array(
		'#type' => 'select',
		'#options' => $times,
		'#title' => t('Shoot Time'),
		'#required' => TRUE,
	);
	
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
	
}

/**
 * Form submit: partner order form
 */
function bxdev_partner_order_form_submit($form, &$form_state){
	drupal_set_message('Your order has been successfully submitted. Thank you!');
}