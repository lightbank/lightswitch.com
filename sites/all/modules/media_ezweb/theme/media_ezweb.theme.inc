<?php

/**
 * Preprocess function for theme('media_vimeo_video').
 */
function media_ezweb_preprocess_media_ezweb_video(&$variables) {
	// Build the URL for display.
  $uri = $variables['uri'];
  $wrapper = file_stream_wrapper_get_instance_by_uri($uri);
  $parts = $wrapper->get_parameters();
  $variables['video_id'] = check_plain($parts['ez']);
	$variables['output'] = '<iframe src="http://cloud.ezwebplayer.com/iframe.htm?v=' . $variables['video_id'] . '&w=' . $variables['width'] . '&h=' . $variables['height'] . '" style="border-width:0;width:' . $variables['width'] . 'px;height:' . $variables['height'] . 'px" scrolling="no"></iframe>';
}
