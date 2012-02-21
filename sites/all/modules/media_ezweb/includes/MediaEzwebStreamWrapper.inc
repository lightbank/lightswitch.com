<?php

/**
 *  @file
 *  Create a Vimeo Stream Wrapper class for the Media/Resource module.
 */

/**
 *  Create an instance like this:
 *  $vimeo = new ResourceVimeoStreamWrapper('vimeo://v/[video-code]');
 */
class MediaEzwebStreamWrapper extends MediaReadOnlyStreamWrapper {

  function getTarget($f) {
    return FALSE;
  }

  static function getMimeType($uri, $mapping = NULL) {
    return 'video/ezweb';
  }

  function getOriginalThumbnailPath() {
		return 'http://lightswitch.com/sites/default/files/mail_logo.jpg';		
  }
  
  function getLocalThumbnailPath() {
		$parts = $this->get_parameters();
    $local_path = 'public://media-ezweb/' . check_plain($parts['ez']) . '.jpg';
    if (!file_exists($local_path)) {
      $dirname = drupal_dirname($local_path);
      file_prepare_directory($dirname, FILE_CREATE_DIRECTORY | FILE_MODIFY_PERMISSIONS);
      @copy($this->getOriginalThumbnailPath(), $local_path);
    }
    return $local_path;
  }
  
}
