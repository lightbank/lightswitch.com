<?php
/**
 * @file
 * feature_content_types.features.inc
 */

/**
 * Implements hook_node_info().
 */
function feature_content_types_node_info() {
  $items = array(
    'business' => array(
      'name' => t('Business'),
      'base' => 'node_content',
      'description' => t('Business information relating to a Client (user).'),
      'has_title' => '1',
      'title_label' => t('Business name'),
      'help' => '',
    ),
    'comment' => array(
      'name' => t('Comment'),
      'base' => 'node_content',
      'description' => t('Project specific comment.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'project' => array(
      'name' => t('Project'),
      'base' => 'node_content',
      'description' => t('Video project relating to one Client.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
