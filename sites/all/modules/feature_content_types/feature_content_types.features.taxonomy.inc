<?php
/**
 * @file
 * feature_content_types.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function feature_content_types_taxonomy_default_vocabularies() {
  return array(
    'gallery_video' => array(
      'name' => 'Gallery video',
      'machine_name' => 'gallery_video',
      'description' => 'Gallery videos',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
      'metatags' => array(),
    ),
  );
}
