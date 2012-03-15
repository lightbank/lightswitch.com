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
    'gallery_video' => array(
      'name' => t('Gallery video'),
      'base' => 'node_content',
      'description' => t('Add a new gallery video.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'page' => array(
      'name' => t('Basic page'),
      'base' => 'node_content',
      'description' => t('Use <em>basic pages</em> for your static content, such as an \'About us\' page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'partner_portal' => array(
      'name' => t('Partner portal'),
      'base' => 'node_content',
      'description' => t('Add a new Partner Portal.'),
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

/**
 * Implements hook_default_profile2_type().
 */
function feature_content_types_default_profile2_type() {
  $items = array();
  $items['client'] = entity_import('profile2_type', '{
    "userCategory" : true,
    "userView" : true,
    "type" : "client",
    "label" : "Client",
    "weight" : "0",
    "data" : { "registration" : 0 },
    "metatags" : []
  }');
  $items['videographer'] = entity_import('profile2_type', '{
    "userCategory" : true,
    "userView" : true,
    "type" : "videographer",
    "label" : "Videographer",
    "weight" : "0",
    "data" : { "registration" : 1 },
    "metatags" : []
  }');
  return $items;
}
