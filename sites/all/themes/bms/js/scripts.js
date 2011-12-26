(function ($) {
  
	$(function(){
		
		Shadowbox.init();
		
		/**
		 * Business profile
		 */
		
		// video / image slider init
		var business_slider = $('.main .video-wrap-inner').bxSlider({
			mode: 'fade',
			controls: false
		});
		
		// thumb video / image slider init
		$('.main .photo-thumbs-wrap-inner').bxSlider({
			displaySlideQty: 4,
			moveSlideQty: 4
		});
		
		// click an image thumb
		$('.video-thumbs-wrap .slide.pager').click(function(){
			var index = $('.video-thumbs-wrap .slide.pager').index(this) + 1;
			business_slider.goToSlide(index);
			setTimeout(function(){
				var video_content = $('#media-vimeo-1').clone().html();
				$('#media-vimeo-1').html(video_content);
			}, 500);
		});
		
		// click the video thumb
		$('.field-name-field-project-video img').click(function(){
			business_slider.goToSlide(0);
		});
		
		
		/**
		 * Add buisiness
		 */
		
		// social media name input value / label manipulation
		$('#edit-field-social-name1-und-0-value, #edit-field-social-name2-und-0-value, #edit-field-social-name3-und-0-value, #edit-field-social-name4-und-0-value').focus(function() {
			var value = $(this).val();
			if(value == 'site name'){
				$(this).val('');
			}
		}).blur(function() {
			var value = $(this).val();
			if(value == ''){
				$(this).val('site name');
			}
		});
		
		// social media url input value / label manipulation
		$('#edit-field-social-url1-und-0-value, #edit-field-social-url2-und-0-value, #edit-field-social-url3-und-0-value, #edit-field-social-url4-und-0-value').focus(function() {
			var value = $(this).val();
			if(value == 'url'){
				$(this).val('');
			}
		}).blur(function() {
			var value = $(this).val();
			if(value == ''){
				$(this).val('url');
			}
		});
		
		
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
		}) 	;
		
	});


}(jQuery));