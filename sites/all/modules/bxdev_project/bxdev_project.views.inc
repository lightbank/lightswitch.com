<?php

/**
 * Implements hook_views_data_alter().
 */
function bxdev_project_views_data_alter(&$data) {
	$data['field_data_field_status_date']['table']['group'] = t('Project');
	
	// $data['field_data_field_status_date']['table']['join'] = array(
	// 	'node' => array(
	// 		'left_field' => 'nid',
	// 		'field' => 'entity_id'
	// 	),
	// );
	
	$data['field_data_field_status_date']['field_status_date_value'] = array(
		'title' => t('Status days ago'),
		'help' => t('Displays days since last status change'),
		'field' => array(
			'handler' => 'views_handler_status_days_ago_field',
			'click sortable' => TRUE,
		),
	);
	
  // foreach ($data as $table => $config) {
  //   foreach ($config as $item => $item_config) {
  // 			if (isset($item_config['field'])){
  // 				if(isset($item_config['field']['handler']) && $item_config['field']['handler'] == 'views_handler_field_date'){
  // 					$data[$table][$item]['field']['handler'] = 'views_handler_field_bxdev_project_date';
  // 				}
  // 			}
  //   }
  // }
	return $data;
}

// /**
//  * Implementation of hook_views_handlers().
//  */
// function bxdev_project_views_handlers() {
//   return array(
//     'info' => array(
//       'path' => drupal_get_path('module', 'bxdev_project') . 'includes/views/handlers',
//     ),
//     'handlers' => array(
//       'views_handler_field_bxdev_project_date' => array(
//         'parent' => 'views_handler_field_date',
//       ),
//     ),
//   );
// }
