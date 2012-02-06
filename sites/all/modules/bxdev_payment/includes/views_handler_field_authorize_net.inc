<?php

class views_handler_field_authorize_net extends views_handler_field {

  function render($values) {
			
    $value = $this->get_value($values);
		if($value){
			
			// get all payment profiles associated with the client
			// $payment_profiles = bxdev_payment_get_payment_profiles($values->payment_log_uid);
			$payment_profiles = $GLOBALS['payment_profiles'];
			
			foreach($payment_profiles as $payment_profile_id => $payment_profile_value){
				// if charged card id matches a value
				if($payment_profile_id == $values->payment_log_payment_id){
					$value = $payment_profile_value;
					return $value;
				}
			}
						
    	return '(removed card)';
		}
  }

}
