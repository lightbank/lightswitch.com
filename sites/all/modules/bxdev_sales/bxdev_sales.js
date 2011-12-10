(function ($) {
  
	$(function(){
		
		if(window.location.hash == '#existing'){
			$('.client-add-form').hide();
			$('.client-existing-form').show();
		}
		
		$('.show-client-add-form').click(function(){
			$('.client-add-form').show();
			$('.client-existing-form').hide();
		});
		
		$('.show-client-existing-form').click(function(){
			$('.client-add-form').hide();
			$('.client-existing-form').show();
		});
		
		Drupal.jsAC.prototype.hidePopup = function (keycode) {
			var selected_value = $(this.selected).text();
			var nid = $(this.selected).data('autocompleteValue');
			$('input[name="existing_client_nid"]').val(nid);
			$('#edit-existing-client').val(selected_value);
			
			// Hide popup.
			var popup = this.popup;
			if (popup) {
			  this.popup = null;
			  $(popup).fadeOut('fast', function () { $(popup).remove(); });
			}
			this.selected = false;
			$(this.ariaLive).empty();			
		}
		
	});	

}(jQuery));

