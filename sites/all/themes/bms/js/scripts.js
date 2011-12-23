(function ($) {
  
	$(function(){
		
		Shadowbox.init();
		
		// video / image slider
		$('.main .video-wrap-inner').bxSlider({
			mode: 'fade',
			controls: false
		});
		
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