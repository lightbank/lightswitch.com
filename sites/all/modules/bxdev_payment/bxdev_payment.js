(function ($) {
  
	// gets called after all AJAX commands
	Drupal.behaviors.bxdev_payment = {
    attach: function(context, settings) {
			// populate the charge amount field
			populate_cc_amount();
			
			// populate the charge amount field on drop-down change
			$('select[name="project_type"]').change(function() {
				populate_cc_amount();
			});
			
			// apply phone mask
			$('input[name="new_client_phone"]').mask('999-999-9999? x99999');
			
			// apply date popup
			if($('input[name="bxdev_shoot_date"]').length > 0){
				$('input[name="bxdev_shoot_date"]').datepicker();
			}			
    }
  };
	

	$(function(){
				
	});
	
	// populate the charge amount field based on project type drop-down
	function populate_cc_amount(){
		var value = $('select[name="project_type"]').val();
		$('input[name="cc_amount"]').val(value == 'custom' ? '' : value);
	}

}(jQuery));

