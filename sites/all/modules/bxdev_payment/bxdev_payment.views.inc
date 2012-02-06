<?php

/**
 * Implements hook_views_data_alter().
 */
function bxdev_payment_views_data() {
	
	// event_order table
	$data['payment_log']['table']['group'] = t('Payments');
	
	$data['payment_log']['table']['base'] = array(
		'field' => 'pid',
		'title' => t('Payments'),
		'help' => t('Payments'),
		'weight' => 10,
	);
	
	$data['payment_log']['nid'] = array(
		'title' => t('Project ID'),
		'help' => t('Project ID'),
		'field' => array(
			'handler' => 'views_handler_field',
			'click_sortable' => TRUE,
		),
		'filter' => array(
	    'handler' => 'views_handler_filter_string',
	  ),
	  'argument' => array(
	    'handler' => 'views_handler_argument_string',
	  ),
	  'sort' => array(
	    'handler' => 'views_handler_sort',
	  ),
		'relationship' => array(
      'base' => 'node', 
      'base field' => 'nid', 
      'handler' => 'views_handler_relationship', 
      'label' => t('Project'),
    ),
	
	);
	
	$data['payment_log']['uid'] = array(
		'title' => t('User ID'),
		'help' => t('User ID'),
		'field' => array(
			'handler' => 'views_handler_field',
			'click_sortable' => TRUE,
		),
		'filter' => array(
	    'handler' => 'views_handler_filter_string',
	  ),
	  'argument' => array(
	    'handler' => 'views_handler_argument_string',
	  ),
	  'sort' => array(
	    'handler' => 'views_handler_sort',
	  ),
		'relationship' => array(
	    'base' => 'users', 
	    'base field' => 'uid', 
	    'handler' => 'views_handler_relationship', 
	    'label' => t('User'),
	  ),	
	);
	
	$data['payment_log']['amount'] = array(
		'title' => t('Payment amount'),
		'help' => t('Payment amount'),
		'field' => array(
			'handler' => 'views_handler_field_currency',
			'click_sortable' => TRUE,
		),
		'filter' => array(
	    'handler' => 'views_handler_filter_string',
	  ),
	  'argument' => array(
	    'handler' => 'views_handler_argument_string',
	  ),
	  'sort' => array(
	    'handler' => 'views_handler_sort',
	  ),
	);
	
	$data['payment_log']['transaction_id'] = array(
		'title' => t('Transaction ID'),
		'help' => t('Transaction ID'),
		'field' => array(
			'handler' => 'views_handler_field',
			'click_sortable' => TRUE,
		),
		'filter' => array(
	    'handler' => 'views_handler_filter_string',
	  ),
	  'argument' => array(
	    'handler' => 'views_handler_argument_string',
	  ),
	  'sort' => array(
	    'handler' => 'views_handler_sort',
	  ),
		
	);
	
	$data['payment_log']['payment_id'] = array(
		'title' => t('Payment profile ID'),
		'help' => t('Payment profile ID'),
		'field' => array(
			'handler' => 'views_handler_field_authorize_net',
			'click_sortable' => TRUE,
		),
		'filter' => array(
	    'handler' => 'views_handler_filter_string',
	  ),
	  'argument' => array(
	    'handler' => 'views_handler_argument_string',
	  ),
	  'sort' => array(
	    'handler' => 'views_handler_sort',
	  ),
		
	);	
	
	$data['payment_log']['date'] = array(
		'title' => t('Date'),
		'help' => t('Date'),
		'field' => array(
			'handler' => 'views_handler_field_date_bxdev_mysql',
			'click_sortable' => TRUE,
		),
		'filter' => array(
			'handler' => 'views_handler_filter_date',
	  ),
	  'argument' => array(
	    'handler' => 'views_handler_argument_date',
	  ),
	  'sort' => array(
	    'handler' => 'views_handler_sort',
	  ),
	);	
	
	return $data;
	
}