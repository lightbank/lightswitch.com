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
			
			// click the "Charge" button - launch confirm
			$('#bxdev-payment-project-payment-form .form-submit').click(function(){
				$('.charge-popup').fadeIn(200);
				return false;
			});
			
			// click the "Cancel" button - close confirm
			$('#bxdev-payment-project-payment-form .btn-cancel').click(function(){
				$('.charge-popup').fadeOut(200);
				return false;
			});
			
			// click "Charge credit card" - submit form
			$('#bxdev-payment-project-payment-form .btn-approve').click(function(){
				$('#bxdev-payment-project-payment-form').submit();
				return false;
			});
			
			// click the "Pay" button - launch confirm
			$('#bxdev-payment-videographer-payment-form .form-submit').click(function(){
				$('.videographer-charge-popup').fadeIn(200);
				return false;
			});
			
			// click the "Cancel" button - close confirm
			$('#bxdev-payment-videographer-payment-form .btn-cancel').click(function(){
				$('.videographer-charge-popup').fadeOut(200);
				return false;
			});
			
			// click "Send payment" - submit form
			$('#bxdev-payment-videographer-payment-form .btn-approve').click(function(){
				$('#bxdev-payment-videographer-payment-form').submit();
				return false;
			});
			
			// click "remove" credit card
			$('.credit-card-wrap .payment-profile a').click(function(){
				$('.remove-popup').fadeOut(200);
				var payment_profile_id = $(this).attr('data-payment-profile');
				$('.remove-popup[data-payment-profile="' + payment_profile_id + '"]').fadeIn(200);
				return false;
			});
			
			$('.credit-card-wrap .btn-cancel').click(function(){
				$('.remove-popup').fadeOut(200);
				return false;
			});
					
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

