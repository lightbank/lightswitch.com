
<h1 class="page-title">lightswitch videographer directory</h1>
<div class="videographer-back"><a href="/videographers">&lt; Back to Videographer List</a></div>

<div class="left">
	<div class="left-top">
		<h2><?php print $title; ?></h2>
		<?php if(isset($content['field_region'])) print render($content['field_region']); ?>
		<?php if(isset($content['field_rating'])) print '<div class="videographer-rating videographer-rating-' . $content['field_rating'][0]['#markup'] . '">' . render($content['field_rating']) . '</div>'; ?>
		<?php if(isset($content['field_phone'])) print render($content['field_phone']); ?>
		<?php if(isset($content['field_email'])) print render($content['field_email']); ?>
		<?php if(isset($content['field_address'])) print render($content['field_address']); ?>
		<?php if(isset($content['field_resume'])) print render($content['field_resume']); ?>
	</div><!-- end .left-top -->
	
	<div class="left-bottom">
		<div class="controls">
			<div class="videographer-edit"><a href="/node/<?php print arg(1); ?>/edit">EDIT</a></div>
			<div class="videographer-delete"><a href="/node/<?php print arg(1); ?>/delete">DELETE</a></div>
		</div>
	</div><!-- end .left-bottom -->
</div><!-- end .left -->

<div class="right">
	<?php
		$output = '';
		$output .= (isset($content['field_notes'])) ? '<div class="videographer-item videographer-notes"><h3>NOTES:</h3>' . render($content['field_notes']) . '</div>' : '';
		$output .= (isset($content['field_skills'])) ? '<div class="videographer-item"><h3>Skills:</h3>' . render($content['field_skills']) . '</div>' : '';
		$output .= (isset($content['field_transportation'])) ? '<div class="videographer-item"><h3>Transportation:</h3>' . render($content['field_transportation']) . '</div>' : ''; 
	  $output .= (isset($content['field_equipment'])) ? '<div class="videographer-item"><h3>Equipment:</h3>' . render($content['field_equipment']) . '</div>' : '';
		$output .= (isset($content['field_links_work'])) ? '<div class="videographer-item"><h3>Links to Examples of Work:</h3>' . render($content['field_links_work']) . '</div>' : '';
		$output .= (isset($content['field_availability'])) ? '<div class="videographer-item"><h3>Availability:</h3>' . render($content['field_availability']) . '</div>' : '';
		print $output;
	?>
</div><!-- end .right -->







