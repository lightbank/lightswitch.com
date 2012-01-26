(function ($) {
  
	// gets called after all AJAX commands
	Drupal.behaviors.bxdev_payment = {
    attach: function(context, settings) {
			// populate the charge amount field
			populate_cc_amount();
			
			// populate the charge amount field on drop-down change
			$('#edit-project-type').change(function() {
				populate_cc_amount();
			});
			
			// apply phone mask
			$('#edit-field-phone-und-0-value, #edit-new-client-phone').mask('999-999-9999? x99999');
			
			// apply date popup
			$('input[name="bxdev_shoot_date"]').datepicker();
			
    }
  };
	

	$(function(){
				
	});
	
	// populate the charge amount field based on project type drop-down
	function populate_cc_amount(){
		var value = $('#edit-project-type').val();
		$('#edit-cc-amount').val(value);
	}

}(jQuery));

