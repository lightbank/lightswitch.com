<?php

class views_handler_field_currency extends views_handler_field {

  function render($values) {
    $value = $this->get_value($values);
		if($value){
    	return bxdev_format_currency($this->sanitize_value($value));
		}
  }

}

