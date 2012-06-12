<div id="gradientBarLarge">
	<div id="innerSpotlightContainer">

		<div id="innerFormContainerLeftSide">

			<div class="greenArrowHead">
				<div class="formFieldContainer">
					<?php print render($form['contact_name']); ?>
				</div>
			</div><!--closes greenarrowbox -->

			<div class="greenArrowHead">
				<div class="formFieldContainer">
					<?php print render($form['phone']); ?>
				</div>
			</div><!--closes greenarrowbox -->

			<div class="greenArrowHead">
				<div class="formFieldContainer">
					<?php print render($form['shoot_date']); ?>
				</div>
			</div><!--closes greenarrowbox -->
			
			<div class="greenArrowHead">
				<div class="formFieldContainer">
					<?php print render($form['shoot_time']); ?>
				</div>
			</div><!--closes greenarrowbox -->
			
			<div class="greenArrowHead">
				<div class="formFieldContainer">
					<?php print render($form['notes']); ?>
				</div>
			</div><!--closes greenarrowbox -->
			
			<?php if(isset($form['subscription_month'])): ?>
				<div class="greenArrowHead">
					<div class="formFieldContainer">
						<?php print render($form['subscription_month']); ?>
					</div>
				</div><!--closes greenarrowbox -->
			<?php endif; ?>

		</div><!--closes left column form Container -->

		<div id="innerFormContainerRightSide">

			<div class="greenArrowHead">
				<div class="formFieldContainer">
					<?php print render($form['business_name']); ?>
				</div>
			</div><!--closes greenarrowbox -->
			
			<div class="greenArrowHead">
				<div class="formFieldContainer">
					<?php print render($form['street']); ?>
				</div>
			</div><!--closes greenarrowbox -->

			<div class="greenArrowHead">
				<div class="formFieldContainer">
					<?php print render($form['email']); ?>
				</div>
			</div><!--closes greenarrowbox -->
			
			<?php if(isset($form['project_type'])): ?>
				<div class="greenArrowHead">
					<div class="formFieldContainer">
						<?php print render($form['project_type']); ?>
					</div>
				</div><!--closes greenarrowbox -->
			<?php endif; ?>
			
			<div class="greenArrowHead">
				<div class="formFieldContainer">
					<?php print render($form['city']); ?>
					<a class="manual-city-link" href="">My city is not in the list</a>
					<?php print render($form['city_manual']); ?>
				</div>
			</div><!--closes greenarrowbox -->
			
			<?php if(isset($form['additional_field'])): ?>
				<div class="greenArrowHead">
					<div class="formFieldContainer">
						<?php print render($form['additional_field']); ?>
					</div>
				</div><!--closes greenarrowbox -->
			<?php endif; ?>

		</div><!--closes right column form Container -->
		
		<div class="clear"></div>

	</div><!--closes innerSpotlight Container -->
</div><!--closes large Gradient bar -->

<div id="submitContainer">	
  <?php print render($form['submit']); ?>
</div>

<?php unset($form['state']); ?>
<?php print drupal_render_children($form); ?> 
