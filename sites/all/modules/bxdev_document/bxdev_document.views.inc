<?php

/**
 * Implements hook_views_data_alter().
 */
function bxdev_document_views_data() {
	
	$data['users_documents']['table']['group'] = t('Documents');
	
	$data['users_documents']['table']['base'] = array(
		'field' => 'fid',
		'title' => t('Documents'),
		'help' => t('Documents'),
		'weight' => 10,
	);
	
	$data['users_documents']['nid'] = array(
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
	
	$data['users_documents']['uid'] = array(
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
	
	$data['users_documents']['fid'] = array(
		'title' => t('File'),
		'help' => t('File'),
		'field' => array(
			'handler' => 'views_handler_field_file',
			'click_sortable' => TRUE,
		),
		'filter' => array(
	    'handler' => 'views_handler_filter_file',
	  ),
	  'argument' => array(
	    'handler' => 'views_handler_argument_file',
	  ),
	  'sort' => array(
	    'handler' => 'views_handler_sort',
	  ),
	'relationship' => array(
    'base' => 'file_managed', 
    'base field' => 'fid', 
    'handler' => 'views_handler_relationship', 
    'label' => t('File'),
  ),	
	
	);
		
	$data['users_documents']['date'] = array(
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
	
	$data['users_documents']['description'] = array(
		'title' => t('Description'),
		'help' => t('Description'),
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
		
	
	return $data;
	
}