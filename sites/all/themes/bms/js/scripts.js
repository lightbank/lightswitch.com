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
		
		// custom date fields
		$('#edit-field-shoot-date-und-0-show-todate:not(:checked)').click();
		update_date_fields();
		$('#edit-bxdev-shoot-time1, #edit-bxdev-shoot-time2, #edit-bxdev-shoot-date').change(function() {
			update_date_fields();
		});
		
		
		/**
		 * Match the hidden CCK date fields with our custom time drop-downs
		 */
		function update_date_fields(){
			var date = $('#edit-bxdev-shoot-date').val();
			var time1 = $('#edit-bxdev-shoot-time1').val();
			var time2 = $('#edit-bxdev-shoot-time2').val();
			$('#edit-field-shoot-date-und-0-value-datepicker-popup-0, #edit-field-shoot-date-und-0-value2-datepicker-popup-0').val(date);
			$('#edit-field-shoot-date-und-0-value-timeEntry-popup-1').val(time1);
			$('#edit-field-shoot-date-und-0-value2-timeEntry-popup-1').val(time2);
		}
		
		
	});


}(jQuery));