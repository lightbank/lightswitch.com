(function ($) {
	
	$(function(){
		
		$('#edit-shoot-date').datepicker();
		
		// phone number formatting
		$('#edit-phone').mask('999-999-9999? x99999');
		
		$('.manual-city-link').click(function(){
			$('.manual-city-field').slideToggle(200);
			return false;
		});
		
	});


}(jQuery));