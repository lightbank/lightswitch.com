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

  $theme['block-need_videographer'] = array(
    'module' => 'block',
    'theme' => 'bms',
    'status' => '1',
    'weight' => '-23',
    'region' => 'content',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/39',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'need_videographer',
  );

  $theme['block-front_top_video'] = array(
    'module' => 'block',
    'theme' => 'bms',
    'status' => '1',
    'weight' => '-32',
    'region' => 'content_top',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'front_top_video',
  );

  $theme['block-home_cta'] = array(
    'module' => 'block',
    'theme' => 'bms',
    'status' => '1',
    'weight' => '-36',
    'region' => 'content',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'home_cta',
  );

  $theme['block-home_why_videos'] = array(
    'module' => 'block',
    'theme' => 'bms',
    'status' => '1',
    'weight' => '-32',
    'region' => 'content',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'home_why_videos',
  );

  $theme['block-home_why_lightswitch'] = array(
    'module' => 'block',
    'theme' => 'bms',
    'status' => '1',
    'weight' => '-31',
    'region' => 'content',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'home_why_lightswitch',
  );

  $theme['block-footer_blocks'] = array(
    'module' => 'block',
    'theme' => 'bms',
    'status' => '1',
    'weight' => '0',
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
    'weight' => '0',
    'region' => 'footer',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'footer_copyright',
  );

  $theme['block-home_map'] = array(
    'module' => 'block',
    'theme' => 'bms',
    'status' => '1',
    'weight' => '-30',
    'region' => 'content',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'home_map',
  );

  $theme['block-why_testimonials'] = array(
    'module' => 'block',
    'theme' => 'bms',
    'status' => '1',
    'weight' => '-26',
    'region' => 'content',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/4',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'why_testimonials',
  );

  $theme['block-why_tabs'] = array(
    'module' => 'block',
    'theme' => 'bms',
    'status' => '1',
    'weight' => '-27',
    'region' => 'content',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/4',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'why_tabs',
  );

  $theme['block-why_content'] = array(
    'module' => 'block',
    'theme' => 'bms',
    'status' => '1',
    'weight' => '-28',
    'region' => 'content',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/4',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'why_content',
  );

  $theme['block-why_screen_shots'] = array(
    'module' => 'block',
    'theme' => 'bms',
    'status' => '1',
    'weight' => '-29',
    'region' => 'content',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/4',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'why_screen_shots',
  );

  $theme['block-how_steps'] = array(
    'module' => 'block',
    'theme' => 'bms',
    'status' => '1',
    'weight' => '-25',
    'region' => 'content',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/3',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'how_steps',
  );

  $theme['block-how_pricing_bottom'] = array(
    'module' => 'block',
    'theme' => 'bms',
    'status' => '1',
    'weight' => '-24',
    'region' => 'content',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/3
node/1254',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'how_pricing_bottom',
  );

  $theme['block-contact_faqs'] = array(
    'module' => 'block',
    'theme' => 'bms',
    'status' => '1',
    'weight' => '-22',
    'region' => 'content',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/5',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'contact_faqs',
  );

  $theme['block-button_view_pricing'] = array(
    'module' => 'block',
    'theme' => 'bms',
    'status' => '1',
    'weight' => '-35',
    'region' => 'left',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/2',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'button_view_pricing',
  );

  $theme['block-pricing_blocks'] = array(
    'module' => 'block',
    'theme' => 'bms',
    'status' => '1',
    'weight' => '-33',
    'region' => 'content',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1254',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'pricing_blocks',
  );

  $theme['block-gallery_great_for'] = array(
    'module' => 'block',
    'theme' => 'bms',
    'status' => '1',
    'weight' => '-33',
    'region' => 'left',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/2',
    'title' => 'Great for...',
    'cache' => -1,
    'machine_name' => 'gallery_great_for',
  );

  $theme['block-home_video_blocks'] = array(
    'module' => 'block',
    'theme' => 'bms',
    'status' => '1',
    'weight' => '-35',
    'region' => 'content',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'home_video_blocks',
  );

  $theme['bxdev-contact_form'] = array(
    'module' => 'bxdev',
    'delta' => 'contact_form',
    'theme' => 'bms',
    'status' => '1',
    'weight' => '-20',
    'region' => 'content',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1254',
    'title' => '',
    'cache' => '1',
  );

  $theme['bxdev_business-client_sort'] = array(
    'module' => 'bxdev_business',
    'delta' => 'client_sort',
    'theme' => 'bms',
    'status' => 0,
    'weight' => '-35',
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
    'weight' => '-10',
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
    'weight' => '0',
    'region' => 'content_top',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/2',
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
    'pages' => 'node/2',
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
    'pages' => 'node/2',
    'title' => '',
    'cache' => -1,
  );

  $export['bms'] = $theme;

  // lightswitch
  $theme = array();

  $theme['block-need_videographer'] = array(
    'module' => 'block',
    'theme' => 'lightswitch',
    'status' => 0,
    'weight' => '-4',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/39',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'need_videographer',
  );

  $theme['block-front_top_video'] = array(
    'module' => 'block',
    'theme' => 'lightswitch',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'front_top_video',
  );

  $theme['block-home_cta'] = array(
    'module' => 'block',
    'theme' => 'lightswitch',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'home_cta',
  );

  $theme['block-home_why_videos'] = array(
    'module' => 'block',
    'theme' => 'lightswitch',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'home_why_videos',
  );

  $theme['block-home_why_lightswitch'] = array(
    'module' => 'block',
    'theme' => 'lightswitch',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'home_why_lightswitch',
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

  $theme['block-home_map'] = array(
    'module' => 'block',
    'theme' => 'lightswitch',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'home_map',
  );

  $theme['block-why_testimonials'] = array(
    'module' => 'block',
    'theme' => 'lightswitch',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/4',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'why_testimonials',
  );

  $theme['block-why_tabs'] = array(
    'module' => 'block',
    'theme' => 'lightswitch',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/4',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'why_tabs',
  );

  $theme['block-why_content'] = array(
    'module' => 'block',
    'theme' => 'lightswitch',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/4',
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
    'pages' => 'node/4',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'why_screen_shots',
  );

  $theme['block-how_steps'] = array(
    'module' => 'block',
    'theme' => 'lightswitch',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/3',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'how_steps',
  );

  $theme['block-how_pricing_bottom'] = array(
    'module' => 'block',
    'theme' => 'lightswitch',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/3
node/1254',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'how_pricing_bottom',
  );

  $theme['block-contact_faqs'] = array(
    'module' => 'block',
    'theme' => 'lightswitch',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/5',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'contact_faqs',
  );

  $theme['block-button_view_pricing'] = array(
    'module' => 'block',
    'theme' => 'lightswitch',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/2',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'button_view_pricing',
  );

  $theme['block-pricing_blocks'] = array(
    'module' => 'block',
    'theme' => 'lightswitch',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1254',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'pricing_blocks',
  );

  $theme['block-gallery_great_for'] = array(
    'module' => 'block',
    'theme' => 'lightswitch',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/2',
    'title' => 'Great for...',
    'cache' => -1,
    'machine_name' => 'gallery_great_for',
  );

  $theme['block-home_video_blocks'] = array(
    'module' => 'block',
    'theme' => 'lightswitch',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'home_video_blocks',
  );

  $theme['bxdev-contact_form'] = array(
    'module' => 'bxdev',
    'delta' => 'contact_form',
    'theme' => 'lightswitch',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => 'node/1254',
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
    'pages' => 'node/2',
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
    'visibility' => '0',
    'pages' => 'node/2',
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
    'visibility' => '0',
    'pages' => 'node/2',
    'title' => '',
    'cache' => -1,
  );

  $export['lightswitch'] = $theme;

  // seven
  $theme = array();

  $theme['block-need_videographer'] = array(
    'module' => 'block',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/39',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'need_videographer',
  );

  $theme['block-front_top_video'] = array(
    'module' => 'block',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'front_top_video',
  );

  $theme['block-home_cta'] = array(
    'module' => 'block',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'home_cta',
  );

  $theme['block-home_why_videos'] = array(
    'module' => 'block',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'home_why_videos',
  );

  $theme['block-home_why_lightswitch'] = array(
    'module' => 'block',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'home_why_lightswitch',
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

  $theme['block-home_map'] = array(
    'module' => 'block',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'home_map',
  );

  $theme['block-why_testimonials'] = array(
    'module' => 'block',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/4',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'why_testimonials',
  );

  $theme['block-why_tabs'] = array(
    'module' => 'block',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/4',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'why_tabs',
  );

  $theme['block-why_content'] = array(
    'module' => 'block',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/4',
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
    'pages' => 'node/4',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'why_screen_shots',
  );

  $theme['block-how_steps'] = array(
    'module' => 'block',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/3',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'how_steps',
  );

  $theme['block-how_pricing_bottom'] = array(
    'module' => 'block',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/3
node/1254',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'how_pricing_bottom',
  );

  $theme['block-contact_faqs'] = array(
    'module' => 'block',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/5',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'contact_faqs',
  );

  $theme['block-button_view_pricing'] = array(
    'module' => 'block',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/2',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'button_view_pricing',
  );

  $theme['block-pricing_blocks'] = array(
    'module' => 'block',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1254',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'pricing_blocks',
  );

  $theme['block-gallery_great_for'] = array(
    'module' => 'block',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/2',
    'title' => 'Great for...',
    'cache' => -1,
    'machine_name' => 'gallery_great_for',
  );

  $theme['block-home_video_blocks'] = array(
    'module' => 'block',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/1',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'home_video_blocks',
  );

  $theme['bxdev-contact_form'] = array(
    'module' => 'bxdev',
    'delta' => 'contact_form',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => 'node/1254',
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
    'pages' => 'node/2',
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
    'visibility' => '0',
    'pages' => 'node/2',
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
    'visibility' => '0',
    'pages' => 'node/2',
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
