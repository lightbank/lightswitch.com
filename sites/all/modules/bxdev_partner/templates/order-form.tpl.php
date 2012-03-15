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
					<?php print render($form['city']); ?>
				</div>
			</div><!--closes greenarrowbox -->

			<div class="greenArrowHead">
				<div class="formFieldContainer">
					<?php print render($form['shoot_date']); ?>
				</div>
			</div><!--closes greenarrowbox -->

		</div><!--closes left column form Container -->

		<div id="innerFormContainerRightSide">

			<div class="greenArrowHead">
				<div class="formFieldContainer">
					<?php print render($form['business_name']); ?>
				</div>
			</div><!--closes greenarrowbox -->

			<div class="greenArrowHead">
				<div class="formFieldContainer">
					<?php print render($form['email']); ?>
				</div>
			</div><!--closes greenarrowbox -->

			<div class="greenArrowHead">
				<div class="formFieldContainer">
					<?php print render($form['state']); ?>
				</div>
			</div><!--closes greenarrowbox -->

			<div class="greenArrowHead">
				<div class="formFieldContainer">
					<?php print render($form['shoot_time']); ?>
				</div>
			</div><!--closes greenarrowbox -->

		</div><!--closes right column form Container -->

	</div><!--closes innerSpotlight Container -->
</div><!--closes large Gradient bar -->

<div id="submitContainer">	
  <?php print render($form['submit']); ?>
</div>

<?php print drupal_render_children($form); ?> 
