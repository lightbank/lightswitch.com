<?php //dpm($content); ?>
<?php //dpm($node); ?>

<?php print $navigation; ?>

<div class="left">
	
	<div class="left-top">
		
		<div class="section top">
			<h1><?php print $title ?></h1>
			<?php if(isset($content['field_client_category'])): ?>
				<div class="category"><?php print render($content['field_client_category']); ?></div>
			<?php endif; ?>
			<div class="symbols clearfix">
				<?php if(isset($content['field_client_rating'])): ?>				
					<div class="rating rating-<?php print $content['field_client_rating'][0]['#markup']; ?>"><?php print render($content['field_client_rating']); ?></div>
				<?php endif; ?>
				<?php if(isset($content['field_client_price'])): ?>				
					<div class="price price-<?php print $content['field_client_price']['#items'][0]['value']; ?>"><?php print render($content['field_client_price']); ?></div>
				<?php endif; ?>
			</div>		
		</div><!-- end .section.top -->
	
		<div class="section info">
			<?php if(isset($content['field_website'])): ?>
				<div class="website"><?php print render($content['field_website']); ?></div>
			<?php endif; ?>
			<?php if(isset($content['field_phone'])): ?>
				<div class="phone"><?php print render($content['field_phone']); ?></div>
			<?php endif; ?>
			<?php if(isset($content['field_email'])): ?>
				<div class="email"><?php print render($content['field_email']); ?></div>
			<?php endif; ?>
			<?php if(isset($content['field_address'])): ?>
				<div class="address"><?php print nl2br(render($content['field_address'])); ?></div>
				<?php $address = urlencode($content['field_address'][0]['#markup']); ?>
				<iframe width="200" height="200" frameborder="0" scrolling="no" marginheight="0" marginwidth="0" src="http://maps.google.com/maps?q=<?php print $address; ?>&amp;iwloc=near&amp;output=embed"></iframe>
			<?php endif; ?>			
		</div><!-- end .section.info -->
	
		<?php if(isset($content['field_hours_operation'])): ?>
			<div class="section hours">
				<div class="hours-operation"><?php print nl2br(render($content['field_hours_operation'])); ?></div>					
			</div><!-- end .section.info -->
		<?php endif; ?>	
	
		<div class="section social clearfix">
			<?php if(!empty($content['field_social_name1']) && !empty($content['field_social_url1'])): ?>
				<div class="icon"><a href="<?php print $content['field_social_url1'][0]['#markup']; ?>" target="_blank"><img src="/sites/all/themes/bms/images/icon_facebook.png" /></a></div>
			<?php endif; ?>
			<?php if(!empty($content['field_social_name2']) && !empty($content['field_social_url2'])): ?>
				<div class="icon"><a href="<?php print $content['field_social_url2'][0]['#markup']; ?>" target="_blank"><img src="/sites/all/themes/bms/images/icon_twitter.png" /></a></div>
			<?php endif; ?>
			<?php if(!empty($content['field_social_name3']) && !empty($content['field_social_url3'])): ?>
				<div class="icon"><a href="<?php print $content['field_social_url3'][0]['#markup']; ?>" target="_blank"><img src="/sites/all/themes/bms/images/icon_yelp.jpg" /></a></div>
			<?php endif; ?>
			<?php if(!empty($content['field_social_name4']) && !empty($content['field_social_url4'])): ?>
				<div class="link"><a href="<?php print $content['field_social_url4'][0]['#markup']; ?>" target="_blank"><?php print render($content['field_social_name4']) ?></a></div>
			<?php endif; ?>
		</div>
	
	</div><!-- end .left-top -->

	<?php if(isset($operations)): ?>
		<div class="left-bottom">
			<div class="block operations">
				<?php print $operations; ?>
			</div><!-- end .operations -->
		</div><!-- end .left-bottom -->
	<?php endif; ?>
	
</div><!-- end .left -->

<div class="main">
	
	<div class="block">
		
		<div class="video">
			<?php if(isset($video)): ?>
				<?php print $video; ?>
			<?php else: ?>
				<div class="no-vid">No video has been added.</div>
			<?php endif; ?>
		</div><!-- end .video -->
	
		<?php if(isset($content['field_business_overview'])): ?>
			<div class="overview">
				<h2>About <?php print $title; ?></h2>
				<?php print nl2br(render($content['field_business_overview'])); ?>
			</div>
		<?php endif; ?>
		
		<?php if(isset($content['field_business_download_label']) && isset($content['field_business_download_file'])): ?>
			<div class="download"><a href="<?php print file_create_url($content['field_business_download_file'][0]['#file']->uri); ?>"><?php print $content['field_business_download_label'][0]['#markup']; ?></a></div>
		<?php endif; ?>		
		
	</div><!-- end .block -->		
	
	<?php if(isset($client_projects)): ?>
		<?php print $client_projects; ?>
	<?php endif; ?>
	
</div><!-- end .main -->















