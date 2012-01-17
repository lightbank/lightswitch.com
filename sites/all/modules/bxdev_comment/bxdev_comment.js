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
		
		// check for a url hash, add appropriate class
		if(window.location.hash == '#videographer'){
			$('.comment-switch a').removeClass('active');
			$('.videographer-switch').addClass('active');
			$('.client-comments-wrap').hide();
			$('.videographer-comments-wrap').show();
		}
		
		// click a comment switch link
		$('.comment-switch a').click(function(){
			// initially remove active classes from the switch links
			$('.comment-switch a').removeClass('active');
			// check which link was clicked and add a url hash
			if($(this).hasClass('client-switch')){
				$('.client-comments-wrap').show();
				$('.videographer-comments-wrap').hide();
				window.location.hash = '#client';
			}else if($(this).hasClass('videographer-switch')){
				$('.client-comments-wrap').hide();
				$('.videographer-comments-wrap').show();
				window.location.hash = '#videographer';
			}
			// add the active class
			$(this).addClass('active');
			return false;
		});
		
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