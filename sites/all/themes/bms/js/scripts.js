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
				
		/**
		 * Project profile
		 */	
		
		// comment textarea focus / blur
		var $comment_textarea = $('.comments-wrap textarea');
		$comment_textarea.focus(function() {
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
		$('#edit-field-phone-und-0-value, #edit-new-client-phone').mask('999-999-9999? x99999');
		
		// lock facebok / twitter labels
		$('#edit-field-social-name1-und-0-value, #edit-field-social-name2-und-0-value, #edit-field-social-name3-und-0-value').attr('disabled', 'disabled');		
		
		// visibility toggle for new / existing client
		$('.new-client-btn').click(function(){
			$('.new-client-wrapper').toggle();
			$('#edit-field-client-ref, .existing-client-wrapper').toggle();
			$('#edit-field-client-ref-und, #edit-existing-client').val('_none');
			$('#edit-new-client-email, #edit-new-client-name, #edit-new-client-phone').val('');
			return false;
		});
		
		// Why Tabs
		$('.why-tabs li:first a').addClass('active');
		$('.why-tabs li a').click(function(){
			var panel = $(this).attr('href');
			$('.why-tabs li a').removeClass('active');
			$(this).addClass('active');
			
			$('.why-tabs .tab-block').fadeOut();
			$('.why-tabs').find("#"+panel).fadeIn();
			return false;
		});
		
		/**
		 * Video gallery
		 */
		$('.view-display-id-gallery_slideshow ul').roundabout({
			minOpacity: 1
		});
		
		/**	
		 * Pricing
		 */
		$('#block-bxdev-contact-form .close').click(function(){
			$('#block-bxdev-contact-form').fadeOut(200);
			return false;
		});
		
		$('.price-block .btn').click(function(){
			$('#block-bxdev-contact-form').fadeIn(200);
			return false;
		});
		
	});


}(jQuery));