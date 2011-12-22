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
	
	<?php if(isset($operations)): ?>
		<div class="block operations">
			<?php print $operations; ?>
		</div><!-- end .operations -->
	<?php endif; ?>
	
</div><!-- end .left -->

<div class="main">
	
	<div class="block">
		<div class="video">
			<?php if(isset($content['field_project_video'])): ?>
				<?php print render($content['field_project_video']); ?>
			<?php else: ?>
				<div class="no-vid">No video has been added.</div>
			<?php endif; ?>
		</div><!-- end .video -->
		
		<?php print $comments; ?>
		
		<?php //dpm($approved); ?>	
		
		<?php if(!$approved): ?>
			<?php if($comment_permission): ?>
				<?php print $comment_form; ?>
			<?php endif; ?>
			<?php if(isset($approve_button)) print $approve_button; ?>
		<?php else: ?>
			<p>Project has been approved.</p>
		<?php endif; ?>
		
	</div><!-- end .block -->
	
	<?php if(user_access('view production details')): ?>
		<div class="block">
			<div class="download-doc"><a href="/project/<?php print arg(1); ?>/download/doc">Download Word Doc</a></div>
			<div class="trigger">
				<h2>Production Detials</h2>
			</div>
			<div class="trigger-list prod-details">
				<?php if(isset($content['field_shoot_date'])){print render($content['field_shoot_date']);} ?>
				<?php if(isset($content['field_voice_over'])){print render($content['field_voice_over']);} ?>
				<?php if(isset($content['field_voice_over_gender'])){print render($content['field_voice_over_gender']);} ?>
				<?php if(isset($content['field_owner_interview'])){print render($content['field_owner_interview']);} ?>
				<?php if(isset($content['field_script_notes'])){print render($content['field_script_notes']);} ?>
				<?php if(isset($content['field_logo'])){print render($content['field_logo']);} ?>
				<?php if(isset($content['field_photos'])){print render($content['field_photos']);} ?>
				<?php if(isset($content['field_features_include'])){print render($content['field_features_include']);} ?>
				<?php if(isset($content['field_features_avoid'])){print render($content['field_features_avoid']);} ?>
				<?php if(isset($content['field_unique'])){print render($content['field_unique']);} ?>
			</div><!-- end .prod-details -->
		</div><!-- end .block -->
	<?php endif; ?>
	
	<?php if(isset($production_history)): ?>
		<div class="block">
			<div class="trigger">
				<h2>Production History</h2>
			</div>
			<div class="trigger-list prod-history">
				<?php print $production_history; ?>
			</div><!-- end .prod-history -->
		</div><!-- end .block -->	
	<?php endif; ?>
	
</div><!-- end .main -->















