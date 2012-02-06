<?php if ($page['header']): ?>
  <header id="header"><div class="limiter clearfix">
    <?php print render($page['header']); ?>
  </div></header>
<?php endif; ?>

<?php if ($page['content_top']): ?>
  <section id="content-top"><div class="limiter clearfix">
    <?php print render($page['content_top']); ?>
  </div></section>
<?php endif; ?>

<section id="page"><div class="limiter clearfix">

  <?php if ($page['left']): ?>
    <aside id="left" class="clearfix"><?php print render($page['left']) ?></aside>
  <?php endif; ?>

  <section id="main" class="clearfix">
		<?php print $messages; ?>
		<?php if($title && !$no_title) print '<h1 class="page-title">' . $title . '</h1>'; ?>
    <?php if ($primary_local_tasks): ?><ul class="links clearfix"><?php print render($primary_local_tasks) ?></ul><?php endif; ?>
		<div id="content" class="clearfix">
	    <?php if ($secondary_local_tasks): ?><ul class="links clearfix"><?php print render($secondary_local_tasks) ?></ul><?php endif; ?>
	    <?php if ($action_links): ?><ul class="links clearfix"><?php print render($action_links); ?></ul><?php endif; ?>
	    <?php print render($page['content']) ?>
		</div>
  </section>

  <?php if ($page['right']): ?>
    <aside id="right" class="clearfix"><?php print render($page['right']) ?></aside>
  <?php endif; ?>

</div></section>

<footer id="footer" class="clearfix">
  <?php print $feed_icons ?>
  <?php print render($page['footer']) ?>
</footer>
