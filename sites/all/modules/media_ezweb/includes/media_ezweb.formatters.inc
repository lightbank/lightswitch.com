<?php

/**
 * Implements hook_file_formatter_info().
 */
function media_ezweb_file_formatter_info() {
  $formatters['media_ezweb_video'] = array(
    'label' => t('EZWeb Video'),
    'file types' => array('video'),
    'default settings' => array(
      'width' => 600,
      'height' => 350,
    ),
    'view callback' => 'media_ezweb_file_formatter_video_view',
    'settings callback' => 'media_ezweb_file_formatter_video_settings',
  );
  $formatters['media_ezweb_image'] = array(
    'label' => t('EZWeb Preview Image'),
    'file types' => array('video'),
    'default settings' => array(
      'image_style' => '',
    ),
    'view callback' => 'media_ezweb_file_formatter_image_view',
    'settings callback' => 'media_ezweb_file_formatter_image_settings',
  );
  return $formatters;
}

/**
 * Implements hook_file_formatter_FORMATTER_view().
 */
function media_ezweb_file_formatter_video_view($file, $display, $langcode) {
  $scheme = file_uri_scheme($file->uri);
  // WYSIWYG does not yet support video inside a running editor instance.
  if ($scheme == 'ezweb') {
		$response = drupal_http_request('http://www.ezwebplayer.com/webservices/v5/videoservice.asmx/GetVideo?format=json&videoID="' . $file->filename . '"&userID="a150be4a-c40e-480a-97e9-9aab0ce47de9"');
		$json = drupal_json_decode(preg_replace('/[\(\)]/', '', $response->data));
    $element = array(
      '#theme' => 'media_ezweb_video',
      '#uri' => $file->uri,
			'#file_download' => $json['d']['VideoFileUrl'],
    );
    foreach (array('width', 'height', 'autoplay') as $setting) {
      $element['#' . $setting] = isset($file->override[$setting]) ? $file->override[$setting] : $display['settings'][$setting];
    }
    return $element;
  }
}

/**
 * Implements hook_file_formatter_FORMATTER_settings().
 */
function media_ezweb_file_formatter_video_settings($form, &$form_state, $settings) {
  $element = array();
  $element['width'] = array(
    '#title' => t('Width'),
    '#type' => 'textfield',
    '#default_value' => $settings['width'],
  );
  $element['height'] = array(
    '#title' => t('Height'),
    '#type' => 'textfield',
    '#default_value' => $settings['height'],
  );
  $element['autoplay'] = array(
    '#title' => t('Autoplay'),
    '#type' => 'checkbox',
    '#default_value' => $settings['autoplay'],
  );
  return $element;
}

/**
 * Implements hook_file_formatter_FORMATTER_view().
 */
function media_ezweb_file_formatter_image_view($file, $display, $langcode) {
  $scheme = file_uri_scheme($file->uri);
  if ($scheme == 'ezweb') {
    $wrapper = file_stream_wrapper_get_instance_by_uri($file->uri);
    $image_style = $display['settings']['image_style'];
    $valid_image_styles = image_style_options(FALSE);
    if (empty($image_style) || !isset($valid_image_styles[$image_style])) {
      $element = array(
        '#theme' => 'image',
        '#path' => $wrapper->getOriginalThumbnailPath(),
      );
    }
    else {
      $element = array(
        '#theme' => 'image_style',
        '#style_name' => $image_style,
        '#path' => $wrapper->getLocalThumbnailPath(),
      );
    }
    return $element;
  }
}

/**
 * Implements hook_file_formatter_FORMATTER_settings().
 */
function media_ezweb_file_formatter_image_settings($form, &$form_state, $settings) {
  $element = array();
  $element['image_style'] = array(
    '#title' => t('Image style'),
    '#type' => 'select',
    '#options' => image_style_options(FALSE),
    '#default_value' => $settings['image_style'],
    '#empty_option' => t('None (original image)'),
  );
  return $element;
}





