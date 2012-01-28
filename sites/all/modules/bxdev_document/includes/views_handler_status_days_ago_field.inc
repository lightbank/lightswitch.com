<?php

/**
 * A handler to display dates as just the time if today, otherwise as time and date.
 *
 * @ingroup views_field_handlers
 */
class views_handler_status_days_ago_field extends views_handler_field_date {
 
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['date_format']['#options']['bxdev_project_status_days_ago'] = t('Days ago');
  }  
     
  function render($values) {
		// get the status date
		$status_date = $values->field_field_status_date[0]['raw']['value'];		
		// get the date format
    $format = $this->options['date_format'];
    // check for our custom format
    if($format == 'bxdev_project_status_days_ago'){
			// if status date exists
			if(!empty($status_date)){
				// get the current time
				$now = time();
				// calculate difference in times
			  $time_ago = $now - $status_date;
				// convert to days
			  $time_ago = $time_ago / 86400;
				// return the rounded value
			  return ceil($time_ago);		  
			}
			return 0;
		}else{
			return parent::render($values);
		}		
  }
   
}