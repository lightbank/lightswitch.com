<?php

/**
 * Implementation of MediaInternetBaseHandler.
 *
 * @see hook_media_internet_providers().
 */
class MediaInternetEzwebHandler extends MediaInternetBaseHandler {
  public function parse($embedCode) {
		if(strpos($embedCode, 'cloud.ezwebplayer') !== FALSE || strpos($embedCode, 'cloud.lightswitch') !== FALSE){
			$v_start = strpos($embedCode, '?v=') + 3;
			$v_end = strpos($embedCode, '&');
			$v_id = substr($embedCode, $v_start, $v_end - $v_start);
		}		
		return file_stream_wrapper_uri_normalize('ezweb://ez/' . $v_id);		
  }

  public function claim($embedCode) {
    if ($this->parse($embedCode)) {
      return TRUE;
    }
  }

  public function save() {
    $file = $this->getFileObject();
    file_save($file);
    return $file;
  }

  public function getFileObject() {
    $uri = $this->parse($this->embedCode);
    //@todo: this is terribly broken in some ways because the function is really
    // made for local files which are 'real'
    return file_uri_to_object($uri);
  }

}
