<?php
/**
 * @file
 * feature_blocks.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function feature_blocks_default_fe_block_settings() {
  $export = array();

  // bms
  $theme = array();

  $theme['block-button_view_pricing'] = array(
    'module' => 'block',
    'theme' => 'bms',
    'status' => '1',
    'weight' => '-35',
    'region' => 'left',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1413',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'button_view_pricing',
  );

  $theme['block-contact_faqs'] = array(
    'module' => 'block',
    'theme' => 'bms',
    'status' => '1',
    'weight' => '-20',
    'region' => 'content',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1442',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'contact_faqs',
  );

  $theme['block-footer_blocks'] = array(
    'module' => 'block',
    'theme' => 'bms',
    'status' => '1',
    'weight' => '-35',
    'region' => 'footer',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'footer_blocks',
  );

  $theme['block-footer_copyright'] = array(
    'module' => 'block',
    'theme' => 'bms',
    'status' => '1',
    'weight' => '-34',
    'region' => 'footer',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'footer_copyright',
  );

  $theme['block-front_top_video'] = array(
    'module' => 'block',
    'theme' => 'bms',
    'status' => '1',
    'weight' => '-35',
    'region' => 'content_top',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1422',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'front_top_video',
  );

  $theme['block-gallery_great_for'] = array(
    'module' => 'block',
    'theme' => 'bms',
    'status' => '1',
    'weight' => '-33',
    'region' => 'left',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1413',
    'title' => 'Great for...',
    'cache' => -1,
    'machine_name' => 'gallery_great_for',
  );

  $theme['block-home_cta'] = array(
    'module' => 'block',
    'theme' => 'bms',
    'status' => '1',
    'weight' => '-35',
    'region' => 'content',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1422',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'home_cta',
  );

  $theme['block-home_map'] = array(
    'module' => 'block',
    'theme' => 'bms',
    'status' => '1',
    'weight' => '-29',
    'region' => 'content',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1422',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'home_map',
  );

  $theme['block-home_video_blocks'] = array(
    'module' => 'block',
    'theme' => 'bms',
    'status' => '1',
    'weight' => '-34',
    'region' => 'content',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1422',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'home_video_blocks',
  );

  $theme['block-home_why_lightswitch'] = array(
    'module' => 'block',
    'theme' => 'bms',
    'status' => '1',
    'weight' => '-30',
    'region' => 'content',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1422',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'home_why_lightswitch',
  );

  $theme['block-home_why_videos'] = array(
    'module' => 'block',
    'theme' => 'bms',
    'status' => '1',
    'weight' => '-31',
    'region' => 'content',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1422',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'home_why_videos',
  );

  $theme['block-how_pricing_bottom'] = array(
    'module' => 'block',
    'theme' => 'bms',
    'status' => '1',
    'weight' => '-23',
    'region' => 'content',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1417
node/1414',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'how_pricing_bottom',
  );

  $theme['block-how_steps'] = array(
    'module' => 'block',
    'theme' => 'bms',
    'status' => '1',
    'weight' => '-24',
    'region' => 'content',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1417',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'how_steps',
  );

  $theme['block-pricing_blocks'] = array(
    'module' => 'block',
    'theme' => 'bms',
    'status' => '1',
    'weight' => '-32',
    'region' => 'content',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1414',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'pricing_blocks',
  );

  $theme['block-why_content'] = array(
    'module' => 'block',
    'theme' => 'bms',
    'status' => '1',
    'weight' => '-27',
    'region' => 'content',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1418',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'why_content',
  );

  $theme['block-why_screen_shots'] = array(
    'module' => 'block',
    'theme' => 'bms',
    'status' => '1',
    'weight' => '-28',
    'region' => 'content',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1418',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'why_screen_shots',
  );

  $theme['block-why_tabs'] = array(
    'module' => 'block',
    'theme' => 'bms',
    'status' => '1',
    'weight' => '-26',
    'region' => 'content',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1418',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'why_tabs',
  );

  $theme['block-why_testimonials'] = array(
    'module' => 'block',
    'theme' => 'bms',
    'status' => '1',
    'weight' => '-25',
    'region' => 'content',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1418',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'why_testimonials',
  );

  $theme['bxdev-contact_form'] = array(
    'module' => 'bxdev',
    'delta' => 'contact_form',
    'theme' => 'bms',
    'status' => '1',
    'weight' => '-19',
    'region' => 'content',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1414',
    'title' => '',
    'cache' => '1',
  );

  $theme['bxdev_business-client_sort'] = array(
    'module' => 'bxdev_business',
    'delta' => 'client_sort',
    'theme' => 'bms',
    'status' => 0,
    'weight' => '-34',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'clients',
    'title' => '',
    'cache' => '1',
  );

  $theme['bxdev_user-user_info'] = array(
    'module' => 'bxdev_user',
    'delta' => 'user_info',
    'theme' => 'bms',
    'status' => '1',
    'weight' => '-17',
    'region' => 'header',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['bxdev_vid-vid_sort'] = array(
    'module' => 'bxdev_vid',
    'delta' => 'vid_sort',
    'theme' => 'bms',
    'status' => 0,
    'weight' => '-8',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'videographers*',
    'title' => '<none>',
    'cache' => '1',
  );

  $theme['menu_block-1'] = array(
    'module' => 'menu_block',
    'delta' => '1',
    'theme' => 'bms',
    'status' => '1',
    'weight' => '-18',
    'region' => 'header',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '<none>',
    'cache' => -1,
  );

  $theme['views-9a71587fb6fd23ec332e1eee11bae083'] = array(
    'module' => 'views',
    'delta' => '9a71587fb6fd23ec332e1eee11bae083',
    'theme' => 'bms',
    'status' => '1',
    'weight' => '-34',
    'region' => 'content_top',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1413',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-categories-block'] = array(
    'module' => 'views',
    'delta' => 'categories-block',
    'theme' => 'bms',
    'status' => '1',
    'weight' => '-34',
    'region' => 'left',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1413',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-gallery_videos-block'] = array(
    'module' => 'views',
    'delta' => 'gallery_videos-block',
    'theme' => 'bms',
    'status' => '1',
    'weight' => '-21',
    'region' => 'content',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1413',
    'title' => '',
    'cache' => -1,
  );

  $export['bms'] = $theme;

  // lightswitch
  $theme = array();

  $theme['block-button_view_pricing'] = array(
    'module' => 'block',
    'theme' => 'lightswitch',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1413',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'button_view_pricing',
  );

  $theme['block-contact_faqs'] = array(
    'module' => 'block',
    'theme' => 'lightswitch',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1442',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'contact_faqs',
  );

  $theme['block-footer_blocks'] = array(
    'module' => 'block',
    'theme' => 'lightswitch',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'footer_blocks',
  );

  $theme['block-footer_copyright'] = array(
    'module' => 'block',
    'theme' => 'lightswitch',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'footer_copyright',
  );

  $theme['block-front_top_video'] = array(
    'module' => 'block',
    'theme' => 'lightswitch',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1422',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'front_top_video',
  );

  $theme['block-gallery_great_for'] = array(
    'module' => 'block',
    'theme' => 'lightswitch',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1413',
    'title' => 'Great for...',
    'cache' => -1,
    'machine_name' => 'gallery_great_for',
  );

  $theme['block-home_cta'] = array(
    'module' => 'block',
    'theme' => 'lightswitch',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1422',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'home_cta',
  );

  $theme['block-home_map'] = array(
    'module' => 'block',
    'theme' => 'lightswitch',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1422',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'home_map',
  );

  $theme['block-home_video_blocks'] = array(
    'module' => 'block',
    'theme' => 'lightswitch',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1422',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'home_video_blocks',
  );

  $theme['block-home_why_lightswitch'] = array(
    'module' => 'block',
    'theme' => 'lightswitch',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1422',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'home_why_lightswitch',
  );

  $theme['block-home_why_videos'] = array(
    'module' => 'block',
    'theme' => 'lightswitch',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1422',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'home_why_videos',
  );

  $theme['block-how_pricing_bottom'] = array(
    'module' => 'block',
    'theme' => 'lightswitch',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1417
node/1414',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'how_pricing_bottom',
  );

  $theme['block-how_steps'] = array(
    'module' => 'block',
    'theme' => 'lightswitch',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1417',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'how_steps',
  );

  $theme['block-pricing_blocks'] = array(
    'module' => 'block',
    'theme' => 'lightswitch',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1414',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'pricing_blocks',
  );

  $theme['block-why_content'] = array(
    'module' => 'block',
    'theme' => 'lightswitch',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1418',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'why_content',
  );

  $theme['block-why_screen_shots'] = array(
    'module' => 'block',
    'theme' => 'lightswitch',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1418',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'why_screen_shots',
  );

  $theme['block-why_tabs'] = array(
    'module' => 'block',
    'theme' => 'lightswitch',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1418',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'why_tabs',
  );

  $theme['block-why_testimonials'] = array(
    'module' => 'block',
    'theme' => 'lightswitch',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1418',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'why_testimonials',
  );

  $theme['bxdev-contact_form'] = array(
    'module' => 'bxdev',
    'delta' => 'contact_form',
    'theme' => 'lightswitch',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1414',
    'title' => '',
    'cache' => '1',
  );

  $theme['bxdev_business-client_sort'] = array(
    'module' => 'bxdev_business',
    'delta' => 'client_sort',
    'theme' => 'lightswitch',
    'status' => '1',
    'weight' => '-21',
    'region' => 'content',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'clients',
    'title' => '',
    'cache' => '1',
  );

  $theme['bxdev_user-user_info'] = array(
    'module' => 'bxdev_user',
    'delta' => 'user_info',
    'theme' => 'lightswitch',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['bxdev_vid-vid_sort'] = array(
    'module' => 'bxdev_vid',
    'delta' => 'vid_sort',
    'theme' => 'lightswitch',
    'status' => 0,
    'weight' => '5',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'videographers*',
    'title' => '<none>',
    'cache' => '1',
  );

  $theme['menu_block-1'] = array(
    'module' => 'menu_block',
    'delta' => '1',
    'theme' => 'lightswitch',
    'status' => 0,
    'weight' => '-8',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '<none>',
    'cache' => -1,
  );

  $theme['views-9a71587fb6fd23ec332e1eee11bae083'] = array(
    'module' => 'views',
    'delta' => '9a71587fb6fd23ec332e1eee11bae083',
    'theme' => 'lightswitch',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1413',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-categories-block'] = array(
    'module' => 'views',
    'delta' => 'categories-block',
    'theme' => 'lightswitch',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1413',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-gallery_videos-block'] = array(
    'module' => 'views',
    'delta' => 'gallery_videos-block',
    'theme' => 'lightswitch',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1413',
    'title' => '',
    'cache' => -1,
  );

  $export['lightswitch'] = $theme;

  // partner
  $theme = array();

  $theme['block-button_view_pricing'] = array(
    'module' => 'block',
    'theme' => 'partner',
    'status' => 0,
    'weight' => '-10',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1413',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'button_view_pricing',
  );

  $theme['block-contact_faqs'] = array(
    'module' => 'block',
    'theme' => 'partner',
    'status' => 0,
    'weight' => '-33',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1442',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'contact_faqs',
  );

  $theme['block-footer_blocks'] = array(
    'module' => 'block',
    'theme' => 'partner',
    'status' => 0,
    'weight' => '-35',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'footer_blocks',
  );

  $theme['block-footer_copyright'] = array(
    'module' => 'block',
    'theme' => 'partner',
    'status' => 0,
    'weight' => '-34',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'footer_copyright',
  );

  $theme['block-front_top_video'] = array(
    'module' => 'block',
    'theme' => 'partner',
    'status' => 0,
    'weight' => '-11',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1422',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'front_top_video',
  );

  $theme['block-gallery_great_for'] = array(
    'module' => 'block',
    'theme' => 'partner',
    'status' => 0,
    'weight' => '-14',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1413',
    'title' => 'Great for...',
    'cache' => -1,
    'machine_name' => 'gallery_great_for',
  );

  $theme['block-home_cta'] = array(
    'module' => 'block',
    'theme' => 'partner',
    'status' => 0,
    'weight' => '-18',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1422',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'home_cta',
  );

  $theme['block-home_map'] = array(
    'module' => 'block',
    'theme' => 'partner',
    'status' => 0,
    'weight' => '-24',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1422',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'home_map',
  );

  $theme['block-home_video_blocks'] = array(
    'module' => 'block',
    'theme' => 'partner',
    'status' => 0,
    'weight' => '-19',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1422',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'home_video_blocks',
  );

  $theme['block-home_why_lightswitch'] = array(
    'module' => 'block',
    'theme' => 'partner',
    'status' => 0,
    'weight' => '-23',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1422',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'home_why_lightswitch',
  );

  $theme['block-home_why_videos'] = array(
    'module' => 'block',
    'theme' => 'partner',
    'status' => 0,
    'weight' => '-22',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1422',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'home_why_videos',
  );

  $theme['block-how_pricing_bottom'] = array(
    'module' => 'block',
    'theme' => 'partner',
    'status' => 0,
    'weight' => '-30',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1417
node/1414',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'how_pricing_bottom',
  );

  $theme['block-how_steps'] = array(
    'module' => 'block',
    'theme' => 'partner',
    'status' => 0,
    'weight' => '-29',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1417',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'how_steps',
  );

  $theme['block-pricing_blocks'] = array(
    'module' => 'block',
    'theme' => 'partner',
    'status' => 0,
    'weight' => '-21',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1414',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'pricing_blocks',
  );

  $theme['block-why_content'] = array(
    'module' => 'block',
    'theme' => 'partner',
    'status' => 0,
    'weight' => '-26',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1418',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'why_content',
  );

  $theme['block-why_screen_shots'] = array(
    'module' => 'block',
    'theme' => 'partner',
    'status' => 0,
    'weight' => '-25',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1418',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'why_screen_shots',
  );

  $theme['block-why_tabs'] = array(
    'module' => 'block',
    'theme' => 'partner',
    'status' => 0,
    'weight' => '-27',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1418',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'why_tabs',
  );

  $theme['block-why_testimonials'] = array(
    'module' => 'block',
    'theme' => 'partner',
    'status' => 0,
    'weight' => '-28',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1418',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'why_testimonials',
  );

  $theme['bxdev-contact_form'] = array(
    'module' => 'bxdev',
    'delta' => 'contact_form',
    'theme' => 'partner',
    'status' => 0,
    'weight' => '-34',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1414',
    'title' => '',
    'cache' => '1',
  );

  $theme['bxdev_business-client_sort'] = array(
    'module' => 'bxdev_business',
    'delta' => 'client_sort',
    'theme' => 'partner',
    'status' => 0,
    'weight' => '-8',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'clients',
    'title' => '',
    'cache' => '1',
  );

  $theme['bxdev_user-user_info'] = array(
    'module' => 'bxdev_user',
    'delta' => 'user_info',
    'theme' => 'partner',
    'status' => 0,
    'weight' => '-17',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['bxdev_vid-vid_sort'] = array(
    'module' => 'bxdev_vid',
    'delta' => 'vid_sort',
    'theme' => 'partner',
    'status' => 0,
    'weight' => '17',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'videographers*',
    'title' => '<none>',
    'cache' => '1',
  );

  $theme['menu_block-1'] = array(
    'module' => 'menu_block',
    'delta' => '1',
    'theme' => 'partner',
    'status' => 0,
    'weight' => '-16',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '<none>',
    'cache' => -1,
  );

  $theme['views-9a71587fb6fd23ec332e1eee11bae083'] = array(
    'module' => 'views',
    'delta' => '9a71587fb6fd23ec332e1eee11bae083',
    'theme' => 'partner',
    'status' => 0,
    'weight' => '-13',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1413',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-categories-block'] = array(
    'module' => 'views',
    'delta' => 'categories-block',
    'theme' => 'partner',
    'status' => 0,
    'weight' => '-12',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1413',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-gallery_videos-block'] = array(
    'module' => 'views',
    'delta' => 'gallery_videos-block',
    'theme' => 'partner',
    'status' => 0,
    'weight' => '-32',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1413',
    'title' => '',
    'cache' => -1,
  );

  $export['partner'] = $theme;

  // seven
  $theme = array();

  $theme['block-button_view_pricing'] = array(
    'module' => 'block',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1413',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'button_view_pricing',
  );

  $theme['block-contact_faqs'] = array(
    'module' => 'block',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1442',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'contact_faqs',
  );

  $theme['block-footer_blocks'] = array(
    'module' => 'block',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'footer_blocks',
  );

  $theme['block-footer_copyright'] = array(
    'module' => 'block',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'footer_copyright',
  );

  $theme['block-front_top_video'] = array(
    'module' => 'block',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1422',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'front_top_video',
  );

  $theme['block-gallery_great_for'] = array(
    'module' => 'block',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1413',
    'title' => 'Great for...',
    'cache' => -1,
    'machine_name' => 'gallery_great_for',
  );

  $theme['block-home_cta'] = array(
    'module' => 'block',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1422',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'home_cta',
  );

  $theme['block-home_map'] = array(
    'module' => 'block',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1422',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'home_map',
  );

  $theme['block-home_video_blocks'] = array(
    'module' => 'block',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1422',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'home_video_blocks',
  );

  $theme['block-home_why_lightswitch'] = array(
    'module' => 'block',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1422',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'home_why_lightswitch',
  );

  $theme['block-home_why_videos'] = array(
    'module' => 'block',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1422',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'home_why_videos',
  );

  $theme['block-how_pricing_bottom'] = array(
    'module' => 'block',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1417
node/1414',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'how_pricing_bottom',
  );

  $theme['block-how_steps'] = array(
    'module' => 'block',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1417',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'how_steps',
  );

  $theme['block-pricing_blocks'] = array(
    'module' => 'block',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1414',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'pricing_blocks',
  );

  $theme['block-why_content'] = array(
    'module' => 'block',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1418',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'why_content',
  );

  $theme['block-why_screen_shots'] = array(
    'module' => 'block',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1418',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'why_screen_shots',
  );

  $theme['block-why_tabs'] = array(
    'module' => 'block',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1418',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'why_tabs',
  );

  $theme['block-why_testimonials'] = array(
    'module' => 'block',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1418',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'why_testimonials',
  );

  $theme['bxdev-contact_form'] = array(
    'module' => 'bxdev',
    'delta' => 'contact_form',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1414',
    'title' => '',
    'cache' => '1',
  );

  $theme['bxdev_business-client_sort'] = array(
    'module' => 'bxdev_business',
    'delta' => 'client_sort',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => 'clients',
    'title' => '',
    'cache' => '1',
  );

  $theme['bxdev_user-user_info'] = array(
    'module' => 'bxdev_user',
    'delta' => 'user_info',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['bxdev_vid-vid_sort'] = array(
    'module' => 'bxdev_vid',
    'delta' => 'vid_sort',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'videographers*',
    'title' => '<none>',
    'cache' => '1',
  );

  $theme['menu_block-1'] = array(
    'module' => 'menu_block',
    'delta' => '1',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '<none>',
    'cache' => -1,
  );

  $theme['views-9a71587fb6fd23ec332e1eee11bae083'] = array(
    'module' => 'views',
    'delta' => '9a71587fb6fd23ec332e1eee11bae083',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1413',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-categories-block'] = array(
    'module' => 'views',
    'delta' => 'categories-block',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1413',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-gallery_videos-block'] = array(
    'module' => 'views',
    'delta' => 'gallery_videos-block',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1413',
    'title' => '',
    'cache' => -1,
  );

  $export['seven'] = $theme;

  $theme_default = variable_get('theme_default', 'garland');
  $themes = list_themes();
  foreach ($export as $theme_key => $settings) {
    if ($theme_key != $theme_default && empty($themes[$theme_key]->status)) {
      unset($export[$theme_key]);
    }
  }
  return $export;
}
