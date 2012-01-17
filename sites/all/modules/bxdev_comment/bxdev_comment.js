(function ($) {
			
	// Drupal.behaviors.bxdev_project = {
	//     attach: function(context, settings) {
	// 		// set file inputs to size 15
	// 		$('#edit-business-logo-upload').attr('size', 15);
	// 		$('#edit-signed-production-release-upload').attr('size', 15);
	// 		$('#edit-videographer-invoice-upload').attr('size', 15);
	// 		$('.left input[type="file"]').attr('size', 15);
	//     }
	//   };
  
	$(function(){				
		
		// click 'I decline'
		$('.revision-decline-client').click(function(){
			$('.revision-decline-client-form').fadeIn(200);
			return false;
		});
		
		// click 'Cancel' on decline form
		$('.revision-decline-client-form .cancel').click(function(){
			$('.revision-decline-client-form').fadeOut(200);
			return false;
		});
		
		// validate decline form
		$('#bxdev-comment-client-decline-form').validate({
			rules: {
				decline_reason: 'required'
			},
			messages: {
				decline_reason: 'Enter a reason for declining'
			}
		});
		
	});

}(jQuery));