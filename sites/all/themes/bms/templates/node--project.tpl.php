<?php //dpm($content); ?>
<?php //dpm($business); ?>
<?php //dpm($client); ?>
<?php //dpm($pc); ?>
<?php //dpm($videographer); ?>

<div class="left">
	<div class="block">
		<h1><?php print $business->title ?></h1>
		<h2><?php print $title ?></h2>
	</div>
	
	<div class="block contacts">
		
		<?php if($pc): ?>
			<div class="contact">
				<h3>Production Coordinator:</h3>
				<div class="name"><?php print $pc->field_name['und'][0]['value']; ?></div>
				<div class="email"><?php print $pc->mail; ?></div>
				<div class="phone"><?php print $pc->field_phone['und'][0]['value']; ?></div>
			</div><!-- end .contact -->
		<?php endif; ?>
		
		<?php if($videographer): ?>
			<div class="contact">
				<h3>Videographer:</h3>
				<div class="name"><?php print $videographer->field_name['und'][0]['value']; ?></div>
				<div class="email"><?php print $videographer->mail; ?></div>
				<div class="phone"><?php print $videographer->field_phone['und'][0]['value']; ?></div>
			</div><!-- end .contact -->			
		<?php endif; ?>
		
		<?php if($client): ?>
			<div class="contact">
				<h3>Client:</h3>
				<div class="name"><?php print $client->field_name['und'][0]['value']; ?></div>
				<div class="email"><?php print $client->mail; ?></div>
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
				<?php if(isset($content['field_project_video'])): ?>
					<?php print render($content['field_project_video']); ?>
				<?php else: ?>
					<div class="no-vid">No video has been added.</div>
				<?php endif; ?>
			</div><!-- end .video-wrap-outer -->
			<?php if(isset($photos_teaser)): ?>
				<div class="project-thumb-wrapper clearfix">
					<?php print $photos_teaser; ?>
					<div><a href="/project/<?php print arg(1); ?>/photos">View photos</a></div>
				</div>
			<?php endif; ?>
		</div><!-- end .video -->
		
		<?php print $comments; ?>
		
		<?php if(!$approved): ?>
			<?php if($comment_permission): ?>
				<?php print $comment_form; ?>
			<?php endif; ?>
			<?php if(isset($approve_button)) print $approve_button; ?>
		<?php else: ?>
			<p>Project has been approved.</p>
		<?php endif; ?>
		
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















