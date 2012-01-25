<?php //dpm($content); ?>
<?php //dpm($business); ?>
<?php //dpm($client); ?>
<?php //dpm($pc); ?>
<?php //dpm($videographer); ?>

<?php if(!empty($navigation)) print $navigation; ?>

<div class="left">
	<div class="block">
		<h1><a href="/<?php print drupal_lookup_path('alias', 'node/' . $business->nid) ?>"><?php print $business->title ?></a></h1>
		<h2><?php print $title ?></h2>
	</div>
	
	<div class="block contacts">
		
		<?php if($pc): ?>
			<div class="contact">
				<h3>Production Coordinator:</h3>
				<div class="name"><?php print $pc->field_name['und'][0]['value']; ?></div>
				<div class="email"><a href="mailto:<?php print $pc->mail; ?>"><?php print $pc->mail; ?></a></div>
				<div class="phone"><?php print $pc->field_phone['und'][0]['value']; ?></div>
			</div><!-- end .contact -->
		<?php endif; ?>
		
		<?php if($videographer): ?>
			<div class="contact">
				<h3>Videographer:</h3>
				<div class="name"><?php print $videographer->field_name['und'][0]['value']; ?></div>
				<div class="email"><a href="mailto:<?php print $videographer->mail; ?>"><?php print $videographer->mail; ?></a></div>
				<div class="phone"><?php print $videographer->field_phone['und'][0]['value']; ?></div>
			</div><!-- end .contact -->			
		<?php endif; ?>
		
		<?php if($client): ?>
			<div class="contact">
				<h3>Client:</h3>
				<div class="name"><?php print $client->field_name['und'][0]['value']; ?></div>
				<div class="email"><a href="mailto:<?php print $client->mail; ?>"><?php print $client->mail; ?></a></div>
				<div class="phone"><?php print $client->field_phone['und'][0]['value']; ?></div>
			</div><!-- end .contact -->			
		<?php endif; ?>
		
	</div><!-- end .contacts -->
	
	<?php if(isset($business_logo_upload)): ?>
		<div class="block">
			<?php print $business_logo_upload; ?>
		</div>
	<?php endif; ?>
	
	<?php if(isset($videographer_documents)): ?>
		<div class="block">
			<?php print $videographer_documents; ?>
		</div>
	<?php endif; ?>
	
	<?php if(isset($operations)): ?>
		<div class="block operations">
			<?php print $operations; ?>
		</div><!-- end .operations -->
	<?php endif; ?>
	
</div><!-- end .left -->

<div class="main">
	
	<div class="block">
		<div class="video">
			<div class="video-wrap-outer">
				<?php if(!empty($content['field_project_video']['#items'])): ?>
					<?php print render($content['field_project_video']); ?>
				<?php else: ?>
					<div class="no-vid"><img src="/sites/all/themes/bms/images/pic_coming_soon.jpg" /></div>
				<?php endif; ?>
			</div><!-- end .video-wrap-outer -->
			<?php if(isset($photos_teaser)): ?>
				<div class="project-thumb-wrapper clearfix">
					<?php print $photos_teaser; ?>
					<div><a href="/project/<?php print arg(1); ?>/photos">View photos</a></div>
				</div>
			<?php endif; ?>
		</div><!-- end .video -->
		
		<div class="comments-wrap clearfix">
			<?php if(!empty($comment_switch)) print $comment_switch; ?>
			<?php if(!empty($client_comments)) print $client_comments; ?>
			<?php if(!empty($client_comment_form)) print $client_comment_form; ?>
			<?php if(!empty($videographer_comments)) print $videographer_comments; ?>
			<?php if(!empty($videographer_comment_form)) print $videographer_comment_form; ?>
		</div>
		
	</div><!-- end .block -->
	
	<?php if(isset($production_details)): ?>
		<?php print $production_details; ?>
	<?php endif; ?>
	
	<?php if(isset($production_history)): ?>
		<div class="block prod-history-wrap">
			<div class="trigger">
				<h2>Production History</h2>
			</div>
			<div class="trigger-list prod-history">
				<?php print $production_history; ?>
			</div><!-- end .prod-history -->
		</div><!-- end .block -->	
	<?php endif; ?>
	
</div><!-- end .main -->















