(function ($) {
  
	Drupal.behaviors.bxdev_payment = {
    attach: function(context, settings) {
			
			populate_cc_amount();
			
			$('#edit-project-type').change(function() {
				populate_cc_amount();
			});
			
    }
  };
	

	$(function(){
				
	});
	
	function populate_cc_amount(){
		var value = $('#edit-project-type').val();
		$('#edit-cc-amount').val(value);
	}

}(jQuery));

