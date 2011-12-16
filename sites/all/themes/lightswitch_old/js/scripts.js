(function ($) {
	$(function(){
		
		// Form Validation
		$('.webform-client-form, .node-videographer-form').each(function(){
			$(this).validate();
		});
		
		// Form Select Drop Down
		$('.node-videographer-form select').selectBox();
		
		// Facts Masonry
		var $container = $('.view-facts .view-content');
		$container.imagesLoaded( function(){
		  $container.masonry({
		    itemSelector : '.views-row'
		  });
		});
		
		/**
		 * Videos
		 */
		
		var current_video = 0;
		
		// apply image fade slider
		var slider = $('#block-views-videos-block .view-videos .view-content, #block-views-videos-block-2 .view-videos .view-content').bxSlider({
			mode: 'fade',
			controls: false
		});
		
		// add active class to the first thumb
		$('.view-videos .views-row-first').addClass('active');
		
		// click a thumb
		$('#block-views-videos-block-1 .views-row, #block-views-videos-block-3 .views-row').click(function(){
			// get the index of clicked thumb
			var index = $(this).index();
			// after the transition apply the "stop" fix
			var delay = setTimeout(function(){
				// cache the selector
				var $selector = $('#block-views-videos-block, #block-views-videos-block-2');
				// get the video content
				var video = $selector.find('.views-row').eq(current_video).find('.field-content').html();
				// replace the video with itself (this "stops" the video)
				$selector.find('.views-row').eq(current_video).find('.field-content').html(video);
				// set the new current video index
				current_video = index;
			}, 500);					
			// go to new video
			slider.goToSlide(index);
			// remove old active classes
			$('#block-views-videos-block-1 .views-row, #block-views-videos-block-3 .views-row').removeClass('active');
			// apply active class to clicked thumb
			$(this).addClass('active');
			// record current
		});
					
	});
})(jQuery);