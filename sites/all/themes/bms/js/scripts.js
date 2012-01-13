(function ($) {
	
	/**
	 * Silly Safari hack to prevent file upload hanging
	 */
	Drupal.behaviors.safari_upload = {
		attach: function(context) {
			if (/AppleWebKit|MSIE/.test(navigator.userAgent)) {
		  	$("input.form-submit").bind('mousedown', function(){
					$.get("/ping/close");
				});
			}
		}
	};
		
	Drupal.behaviors.bxdev_project = {
    attach: function(context, settings) {
			// set file inputs to size 15
			$('#edit-business-logo-upload').attr('size', 15);
			$('#edit-signed-production-release-upload').attr('size', 15);
			$('#edit-videographer-invoice-upload').attr('size', 15);
			$('.left input[type="file"]').attr('size', 15);
    }
  };
  
	$(function(){
		
		Shadowbox.init();		
		
		/**
		 * Business profile
		 */
				
		// thumb video / image slider init
		$('.main .photo-thumbs-wrap-inner').bxSlider({
			displaySlideQty: 4,
			moveSlideQty: 4
		});
		
		/** INSTEAD OF FADING THE VIDEO INTO IMAGES, USING SHADOWBOX INSTEAD
		/** BELOW IS THE FADE CODE
		
		// // video / image slider init
		// var business_slider = $('.main .video-wrap-inner').bxSlider({
		// 	mode: 'fade',
		// 	controls: false
		// });
		
		// // click an image thumb
		// $('.video-thumbs-wrap .slide.pager').click(function(){
		// 	var index = $('.video-thumbs-wrap .slide.pager').index(this) + 1;
		// 	business_slider.goToSlide(index);
		// 	setTimeout(function(){
		// 		var video_content = $('#media-vimeo-1').clone().html();
		// 		$('#media-vimeo-1').html(video_content);
		// 	}, 500);
		// });
		// 
		// // click the video thumb
		// $('.field-name-field-project-video img').click(function(){
		// 	business_slider.goToSlide(0);
		// });
				
		
		/**
		 * Project profile
		 */	
		
		// comment textarea focus / blur
		$('#edit-field-comment-und-0-value').focus(function() {
			var value = $(this).val();
			if(value == 'Type your comments here...'){
				$(this).val('');
			}
		}).blur(function() {
			var value = $(this).val();
			if(value == ''){
				$(this).val('Type your comments here...');
			}
		});
		
		// approve button click
		$('.approve-btn').click(function(){
			$('.approve-confirm').fadeIn(200);
			return false;
		});
		
		// approve cancel click
		$('.approve-cancel').click(function(){
			$('.approve-confirm').fadeOut(200);
			return false;
		});
		
		// Production Details / History Toggle
		$('.trigger').click(function(){
			$(this).parent().find('.trigger-list').slideToggle();
			$(this).toggleClass('active');
		});
		
		$('.client-select a:first').addClass('active');
		$('.client-select a').click(function(){
			$(this).parent().find('.active').removeClass('active');
			$(this).addClass('active');
		});
		
		// datepicker
		if($('#edit-bxdev-shoot-date').length > 0){
			$('#edit-bxdev-shoot-date').datepicker();
		}
				
		/**
		 * Add a business
		 */
		
		// phone number formatting
		$('#edit-field-phone-und-0-value, #edit-new-client-phone').mask('999-999-9999');
		
		// lock facebok / twitter labels
		$('#edit-field-social-name1-und-0-value, #edit-field-social-name2-und-0-value, #edit-field-social-name3-und-0-value').attr('disabled', 'disabled');		
		
	});


}(jQuery));