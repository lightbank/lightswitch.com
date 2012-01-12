<?php
/**
 * @file views-view.tpl.php
 * Main view template
 *
 * Variables available:
 * - $classes_array: An array of classes determined in
 *   template_preprocess_views_view(). Default classes are:
 *     .view
 *     .view-[css_name]
 *     .view-id-[view_name]
 *     .view-display-id-[display_name]
 *     .view-dom-id-[dom_id]
 * - $classes: A string version of $classes_array for use in the class attribute
 * - $css_name: A css-safe version of the view name.
 * - $css_class: The user-specified classes names, if any
 * - $header: The view header
 * - $footer: The view footer
 * - $rows: The results of the view query, if any
 * - $empty: The empty text to display if the view is empty
 * - $pager: The pager next/prev links to display, if any
 * - $exposed: Exposed widget form/info to display
 * - $feed_icon: Feed icon to display, if any
 * - $more: A link to view more, if any
 *
 * @ingroup views_templates
 */
?>
<div class="<?php print $classes; ?>">
  <?php print render($title_prefix); ?>
  <?php if ($title): ?>
    <?php print $title; ?>
  <?php endif; ?>
  <?php print render($title_suffix); ?>
  <?php if ($header): ?>
    <div class="view-header">
      <?php print $header; ?>
    </div>
  <?php endif; ?>

	<div class="search">
		<?php if ($exposed): ?>
      <?php print $exposed; ?>
	  <?php endif; ?>
	</div>

	<div class="left">
		
	  <?php if ($exposed): ?>
	    <div class="view-filters">
				<h2>Filter Results</h2>
				<a href="/videographers" class="clear">clear</a>
	      <?php print $exposed; ?>
	    </div>
	  <?php endif; ?>

	</div><!-- end .left -->
	
	<div class="main">
		
		<div class="controls clearfix">
						
			<?php print '<div class="result-count">Showing ' . ($view->query->offset + 1) . ' - ' . ($view->query->offset + count($view->result)) . ' of ' . $view->total_rows . '</div>'; ?>
			
			<div class="sort">
				<?php
					$output = '';
					$query = $_SERVER['REQUEST_URI'];
					$order = strpos($query, 'ASC') ? 'DESC' : 'ASC';
					if(($pos = strpos($query, 'sort_by=')) > 0){
						$query = substr($query, 0, $pos - 1);
					}
					$symbol = (strpos($query, '?')) ? '&' : '?';
					$output .= 'Sort by: ';
					$output .= '<a href="' . $query . $symbol . 'sort_by=field_rating_value&sort_order=' . $order . '">Rating</a> | ';
					$output .= '<a href="' . $query . $symbol . 'sort_by=field_name_value&sort_order=' . $order . '">ABC</a>'; 
					print $output;		
				?>
			</div>
			
			<?php if ($pager): ?>
		    <?php print $pager; ?>
		  <?php endif; ?>		
		
		</div><!-- end .controls -->
		
		<div class="block clearfix">
		
			<?php if ($attachment_before): ?>
		    <div class="attachment attachment-before">
		      <?php print $attachment_before; ?>
		    </div>
		  <?php endif; ?>

		  <?php if ($rows): ?>
		    <div class="view-content">
		      <?php print $rows; ?>
		    </div>
		  <?php elseif ($empty): ?>
		    <div class="view-empty">
		      <?php print $empty; ?>
		    </div>
		  <?php endif; ?>
	
		  <?php if ($attachment_after): ?>
		    <div class="attachment attachment-after">
		      <?php print $attachment_after; ?>
		    </div>
		  <?php endif; ?>

		  <?php if ($more): ?>
		    <?php print $more; ?>
		  <?php endif; ?>

		  <?php if ($footer): ?>
		    <div class="view-footer">
		      <?php print $footer; ?>
		    </div>
		  <?php endif; ?>

		  <?php if ($feed_icon): ?>
		    <div class="feed-icon">
		      <?php print $feed_icon; ?>
		    </div>
		  <?php endif; ?>	
	
		</div><!-- end block -->
		
		<?php if ($pager): ?>
	    <?php print $pager; ?>
	  <?php endif; ?>

	</div><!-- end .main -->


</div> <?php /* class view */ ?>
