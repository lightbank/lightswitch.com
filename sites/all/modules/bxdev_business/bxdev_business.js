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
			
			// Select item if the right key or mousebutton was pressed.
		  if (this.selected && ((keycode && keycode != 46 && keycode != 8 && keycode != 27) || !keycode)) {
		    // this.input.value = $(this.selected).data('autocompleteValue');
				var selected_value = $(this.selected).text();
				var nid = $(this.selected).data('autocompleteValue');
				$('input[name="existing_business_nid"]').val(nid);
				this.input.value = selected_value;
		  }
			
			// Hide popup.
			var popup = this.popup;
			if (popup) {
			  this.popup = null;
			  $(popup).fadeOut('fast', function () { $(popup).remove(); });
			}
			this.selected = false;
			$(this.ariaLive).empty();			
		}
				
		// visibility toggle for new / existing client
		$('.new-client-btn').click(function(){
			$('.new-client-wrapper').toggle();
			$('#edit-field-client-ref').toggle();
			$('#edit-field-client-ref-und').val('_none');
			$('#edit-new-client-email, #edit-new-client-name, #edit-new-client-phone').val('');
			return false;
		});
		
	});	

}(jQuery));

