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
		});;
		
	});


}(jQuery));