<?php

/**
 * Implements hook_css_alter().
 * @TODO: Once http://drupal.org/node/901062 is resolved, determine whether
 * this can be implemented in the .info file instead.
 *
 * Omitted:
 * - color.css
 * - contextual.css
 * - dashboard.css
 * - field_ui.css
 * - image.css
 * - locale.css
 * - shortcut.css
 * - simpletest.css
 * - toolbar.css
 */
function bms_css_alter(&$css) {
  $exclude = array(
    'misc/vertical-tabs.css' => FALSE,
    'modules/aggregator/aggregator.css' => FALSE,
    'modules/block/block.css' => FALSE,
    'modules/book/book.css' => FALSE,
    'modules/comment/comment.css' => FALSE,
    'modules/dblog/dblog.css' => FALSE,
    'modules/file/file.css' => FALSE,
    'modules/filter/filter.css' => FALSE,
    'modules/forum/forum.css' => FALSE,
    'modules/help/help.css' => FALSE,
    'modules/menu/menu.css' => FALSE,
    'modules/node/node.css' => FALSE,
    'modules/openid/openid.css' => FALSE,
    'modules/poll/poll.css' => FALSE,
    'modules/profile/profile.css' => FALSE,
    'modules/search/search.css' => FALSE,
    'modules/statistics/statistics.css' => FALSE,
    'modules/syslog/syslog.css' => FALSE,
    'modules/system/admin.css' => FALSE,
    'modules/system/maintenance.css' => FALSE,
    'modules/system/system.css' => FALSE,
    'modules/system/system.admin.css' => FALSE,
    'modules/system/system.base.css' => FALSE,
    'modules/system/system.maintenance.css' => FALSE,
    'modules/system/system.menus.css' => FALSE,
    'modules/system/system.messages.css' => FALSE,
    'modules/system/system.theme.css' => FALSE,
    'modules/taxonomy/taxonomy.css' => FALSE,
    'modules/tracker/tracker.css' => FALSE,
    'modules/update/update.css' => FALSE,
    'modules/user/user.css' => FALSE,
  );
  $css = array_diff_key($css, $exclude);
}

/**
 * Implementation of hook_theme().
 */
function bms_theme() {
  $items = array();

  // Consolidate a variety of theme functions under a single template type.
  $items['block'] = array(
    'arguments' => array('block' => NULL),
    'template' => 'object',
    'path' => drupal_get_path('theme', 'bms') .'/templates',
  );
  $items['comment'] = array(
    'arguments' => array('comment' => NULL, 'node' => NULL, 'links' => array()),
    'template' => 'object',
    'path' => drupal_get_path('theme', 'bms') .'/templates',
  );
  $items['node'] = array(
    'arguments' => array('node' => NULL, 'teaser' => FALSE, 'page' => FALSE),
    'template' => 'node',
    'path' => drupal_get_path('theme', 'bms') .'/templates',
  );
  $items['fieldset'] = array(
    'arguments' => array('element' => array()),
    'template' => 'fieldset',
    'path' => drupal_get_path('theme', 'bms') .'/templates',
  );

  // Split out pager list into separate theme function.
  $items['pager_list'] = array('arguments' => array(
    'tags' => array(),
    'limit' => 10,
    'element' => 0,
    'parameters' => array(),
    'quantity' => 9,
  ));

  return $items;
}

/**
 * Preprocess functions ===============================================
 */
function bms_preprocess_html(&$vars) {
  $vars['classes_array'][] = 'bms';
}

/**
 * Implementation of preprocess_page().
 */
function bms_preprocess_page(&$vars) {
  // Split primary and secondary local tasks
  $vars['primary_local_tasks'] = menu_primary_local_tasks();
  $vars['secondary_local_tasks'] = menu_secondary_local_tasks();

  // Link site name to frontpage
  $vars['site_name'] = l($vars['site_name'], '<front>');
}

/**
 * Implementation of preprocess_block().
 */
function bms_preprocess_block(&$vars) {
  $vars['hook'] = 'block';

  $vars['attributes_array']['id'] = $vars['block_html_id'];

  $vars['title_attributes_array']['class'][] = 'block-title';
  $vars['title_attributes_array']['class'][] = 'clearfix';

  $vars['content_attributes_array']['class'][] = 'block-content';
  $vars['content_attributes_array']['class'][] = 'clearfix';
  if ($vars['block']->module == 'block') {
    $vars['content_attributes_array']['class'][] = 'prose';
  }

  $vars['title'] = !empty($vars['block']->subject) ? $vars['block']->subject : '';

  // In D7 the page content may be served as a block. Replace the generic
  // 'block' class from the page content with a more specific class that can
  // be used to distinguish this block from others.
  // Subthemes can easily override this behavior in an implementation of
  // preprocess_block().
  if ($vars['block']->module === 'system' && $vars['block']->delta === 'main') {
    $vars['classes_array'] = array_diff($vars['classes_array'], array('block'));
    $vars['classes_array'][] = 'block-page-content';
  }
}

/**
 * Implementation of preprocess_node().
 */
function bms_preprocess_node(&$vars) {
  $vars['hook'] = 'node';

  $vars['attributes_array']['id'] = "node-{$vars['node']->nid}";

  $vars['title_attributes_array']['class'][] = 'node-title';
  $vars['title_attributes_array']['class'][] = 'clearfix';

  $vars['content_attributes_array']['class'][] = 'node-content';
  $vars['content_attributes_array']['class'][] = 'clearfix';
  $vars['content_attributes_array']['class'][] = 'prose';

  if (isset($vars['content']['links'])) {
    $vars['links'] = $vars['content']['links'];
    unset($vars['content']['links']);
  }

  if (isset($vars['content']['comments'])) {
    $vars['post_object']['comments'] = $vars['content']['comments'];
    unset($vars['content']['comments']);
  }

  if ($vars['display_submitted']) {
    $vars['submitted'] = t('Submitted by !username on !datetime', array(
      '!username' => $vars['name'],
      '!datetime' => $vars['date'],
    ));
  }
}

/**
 * Implementation of preprocess_comment().
 */
function bms_preprocess_comment(&$vars) {
  $vars['hook'] = 'comment';

  $vars['title_attributes_array']['class'][] = 'comment-title';
  $vars['title_attributes_array']['class'][] = 'clearfix';

  $vars['content_attributes_array']['class'][] = 'comment-content';
  $vars['content_attributes_array']['class'][] = 'clearfix';

  $vars['submitted'] = t('Submitted by !username on !datetime', array(
    '!username' => $vars['author'],
    '!datetime' => $vars['created'],
  ));

  if (isset($vars['content']['links'])) {
    $vars['links'] = $vars['content']['links'];
    unset($vars['content']['links']);
  }
}

/**
 * Implementation of preprocess_fieldset().
 */
function bms_preprocess_fieldset(&$vars) {
  $element = $vars['element'];
  _form_set_class($element, array('form-wrapper'));
  $vars['attributes'] = isset($element['#attributes']) ? $element['#attributes'] : array();
  $vars['attributes']['class'][] = 'fieldset';
  if (!empty($element['#title'])) {
    $vars['attributes']['class'][] = 'titled';
  }
  if (!empty($element['#id'])) {
    $vars['attributes']['id'] = $element['#id'];
  }

  $description = !empty($element['#description']) ? "<div class='description'>{$element['#description']}</div>" : '';
  $children = !empty($element['#children']) ? $element['#children'] : '';
  $value = !empty($element['#value']) ? $element['#value'] : '';
  $vars['content'] = $description . $children . $value;
  $vars['title'] = !empty($element['#title']) ? $element['#title'] : '';
  $vars['hook'] = 'fieldset';
}

/**
 * Implementation of preprocess_field().
 */
function bms_preprocess_field(&$vars) {
  // Add prose class to long text fields.
  if ($vars['element']['#field_type'] === 'text_with_summary') {
    $vars['classes_array'][] = 'prose';
  }
}

/**
 * Function overrides =================================================
 */

/**
 * Override of theme('textarea').
 * Deprecate misc/textarea.js in favor of using the 'resize' CSS3 property.
 */
function bms_textarea($variables) {
  $element = $variables['element'];
  $element['#attributes']['name'] = $element['#name'];
  $element['#attributes']['id'] = $element['#id'];
  $element['#attributes']['cols'] = $element['#cols'];
  $element['#attributes']['rows'] = $element['#rows'];
  _form_set_class($element, array('form-textarea'));

  $wrapper_attributes = array(
    'class' => array('form-textarea-wrapper'),
  );

  // Add resizable behavior.
  if (!empty($element['#resizable'])) {
    $wrapper_attributes['class'][] = 'resizable';
  }

  $output = '<div' . drupal_attributes($wrapper_attributes) . '>';
  $output .= '<textarea' . drupal_attributes($element['#attributes']) . '>' . check_plain($element['#value']) . '</textarea>';
  $output .= '</div>';
  return $output;
}

/**
 * Override of theme_pager().
 * Easily one of the most obnoxious theming jobs in Drupal core.
 * Goals: consolidate functionality into less than 5 functions and
 * ensure the markup will not conflict with major other styles
 * (theme_item_list() in particular).
 */
function bms_pager($vars) {
  $tags = $vars['tags'];
  $element = $vars['element'];
  $parameters = $vars['parameters'];
  $quantity = $vars['quantity'];
  $pager_list = theme('pager_list', $vars);

  $prev = array();
  $prev['pager-previous'] = theme('pager_previous', array(
    'text' => (isset($tags[1]) ? $tags[1] : t('<')),
    'element' => $element,
    'interval' => 1,
    'parameters' => $parameters
  ));
  $prev = array_filter($prev);

	$prev_pager = theme('links', array(
	  'links' => $prev,
	  'attributes' => array('class' => 'pager-prev')
	));

	$next = array();
	$next['pager-next'] = theme('pager_next', array(
	  'text' => (isset($tags[3]) ? $tags[3] : t('>')),
	  'element' => $element,
	  'interval' => 1,
	  'parameters' => $parameters
	));
	$next = array_filter($next);
	
	$next_pager = theme('links', array(
	  'links' => $next,
	  'attributes' => array('class' => 'pager-next')
	));

  if ($pager_list) {
    return "<div class='pager clearfix'>$prev_pager $pager_list $next_pager</div>";
  }
}

/**
 * Split out page list generation into its own function.
 */
function bms_pager_list($vars) {
  $tags = $vars['tags'];
  $element = $vars['element'];
  $parameters = $vars['parameters'];
  $quantity = $vars['quantity'];

  global $pager_page_array, $pager_total;
  if ($pager_total[$element] > 1) {
    // Calculate various markers within this pager piece:
    // Middle is used to "center" pages around the current page.
    $pager_middle = ceil($quantity / 2);
    // current is the page we are currently paged to
    $pager_current = $pager_page_array[$element] + 1;
    // first is the first page listed by this pager piece (re quantity)
    $pager_first = $pager_current - $pager_middle + 1;
    // last is the last page listed by this pager piece (re quantity)
    $pager_last = $pager_current + $quantity - $pager_middle;
    // max is the maximum page number
    $pager_max = $pager_total[$element];
    // End of marker calculations.

    // Prepare for generation loop.
    $i = $pager_first;
    if ($pager_last > $pager_max) {
      // Adjust "center" if at end of query.
      $i = $i + ($pager_max - $pager_last);
      $pager_last = $pager_max;
    }
    if ($i <= 0) {
      // Adjust "center" if at start of query.
      $pager_last = $pager_last + (1 - $i);
      $i = 1;
    }
    // End of generation loop preparation.

    $links = array();

    // When there is more than one page, create the pager list.
    if ($i != $pager_max) {
      // Now generate the actual pager piece.
      for ($i; $i <= $pager_last && $i <= $pager_max; $i++) {
        if ($i < $pager_current) {
          $links["$i pager-item"] = theme('pager_previous', array(
            'text' => $i,
            'element' => $element,
            'interval' => ($pager_current - $i),
            'parameters' => $parameters
          ));
        }
        if ($i == $pager_current) {
          $links["$i pager-current"] = array('title' => $i);
        }
        if ($i > $pager_current) {
          $links["$i pager-item"] = theme('pager_next', array(
            'text' => $i,
            'element' => $element,
            'interval' => ($i - $pager_current),
            'parameters' => $parameters
          ));
        }
      }
      return theme('links', array(
        'links' => $links,
        'attributes' => array('class' => 'links pager pager-list')
      ));
    }
  }
  return '';
}

/**
 * Return an array suitable for theme_links() rather than marked up HTML link.
 */
function bms_pager_link($vars) {
  $text = $vars['text'];
  $page_new = $vars['page_new'];
  $element = $vars['element'];
  $parameters = $vars['parameters'];
  $attributes = $vars['attributes'];

  $page = isset($_GET['page']) ? $_GET['page'] : '';
  if ($new_page = implode(',', pager_load_array($page_new[$element], $element, explode(',', $page)))) {
    $parameters['page'] = $new_page;
  }

  $query = array();
  if (count($parameters)) {
    $query = drupal_get_query_parameters($parameters, array());
  }
  if ($query_pager = pager_get_query_parameters()) {
    $query = array_merge($query, $query_pager);
  }

  // Set each pager link title
  if (!isset($attributes['title'])) {
    static $titles = NULL;
    if (!isset($titles)) {
      $titles = array(
        t('« first') => t('Go to first page'),
        t('‹ previous') => t('Go to previous page'),
        t('next ›') => t('Go to next page'),
        t('last »') => t('Go to last page'),
      );
    }
    if (isset($titles[$text])) {
      $attributes['title'] = $titles[$text];
    }
    else if (is_numeric($text)) {
      $attributes['title'] = t('Go to page @number', array('@number' => $text));
    }
  }

  return array(
    'title' => $text,
    'href' => $_GET['q'],
    'attributes' => $attributes,
    'query' => count($query) ? $query : NULL,
  );
}

/**
 * Override of theme_views_mini_pager().
 */
function bms_views_mini_pager($vars) {
  $tags = $vars['tags'];
  $quantity = $vars['quantity'];
  $element = $vars['element'];
  $parameters = $vars['parameters'];

  global $pager_page_array, $pager_total;

  // Calculate various markers within this pager piece:
  // Middle is used to "center" pages around the current page.
  $pager_middle = ceil($quantity / 2);
  // current is the page we are currently paged to
  $pager_current = $pager_page_array[$element] + 1;
  // max is the maximum page number
  $pager_max = $pager_total[$element];
  // End of marker calculations.

  $links = array();
  if ($pager_total[$element] > 1) {
    $links['pager-previous'] = theme('pager_previous', array(
      'text' => (isset($tags[1]) ? $tags[1] : t('Prev')),
      'element' => $element,
      'interval' => 1,
      'parameters' => $parameters
    ));
    $links['pager-current'] = array(
      'title' => t('@current of @max', array(
        '@current' => $pager_current,
        '@max' => $pager_max)
      )
    );
    $links['pager-next'] = theme('pager_next', array(
      'text' => (isset($tags[3]) ? $tags[3] : t('Next')),
      'element' => $element,
      'interval' => 1,
      'parameters' => $parameters
    ));
    return theme('links', array('links' => $links, 'attributes' => array('class' => array('links', 'pager', 'views-mini-pager'))));
  }
}

/**
 * Add width and height to image styled images
 */
function bms_image_style($variables) {
  $style_name = $variables['style_name'];
  $path = $variables['path'];

  // theme_image() can only honor the $getsize parameter with local file paths.
  // The derivative image is not created until it has been requested so the file
  // may not yet exist, in this case we just fallback to the URL.
  $style_path = image_style_path($style_name, $path);
  if (!file_exists($style_path)) {
    $style_path = image_style_url($style_name, $path);
  }
  $variables['path'] = $style_path;

  if (is_file($style_path)) {
    if (list($width, $height, $type, $attributes) = @getimagesize($style_path)) {
      $variables['width'] = $width;
      $variables['height'] = $height;
    }
  }
  
  return theme('image', $variables);
}

/**
 * Remove the (all day) label from views
 */
function bms_date_all_day_label(){
	return t('');
}

/**
 * Override email template
 */
function bms_preprocess_mimemail_message(&$variables){
	// set the default logo
	$variables['logo'] = '<img src="http://lightswitch.com/sites/default/files/mail_logo.jpg" />';
	$recipient = $variables['recipient'];
	$role = '';
	$account = '';
	// if the recipient is a drupal user object
	if(is_object($recipient)){
		$role = bxdev_user_get_role($recipient->uid);
		$account = $recipient;
	// if the recipient is a string of emails, separated by a comma
	}else if(strpos($recipient, ',') !== FALSE){
		$email = reset(explode(',', $recipient));
		$account = user_load_by_mail($email);
		if($account){
			$role = bxdev_user_get_role($account->uid);
		}
	// if the recipient is a single email address string
	}else{
		$account = user_load_by_mail($recipient);
		if($account){
			$role = bxdev_user_get_role($account->uid);
		}
	}
	// if client (or additional email address)
	if($role == 'client' || $role == '' && is_object($account)){
		// get the profile
		$profile = profile2_load_by_user($account->uid, 'client');
		// if the profile exists and has a partner theme assigned
		if($profile && !empty($profile->field_client_partner_theme['und'][0]['nid'])){
			$theme = node_load($profile->field_client_partner_theme['und'][0]['nid']);
			if(!empty($theme->field_partner_theme_logo['und'][0]['fid'])){
				// set the custom logo
				$variables['logo'] = theme('image_style', array('path' => $theme->field_partner_theme_logo['und'][0]['uri'], 'style_name' => 'partner_theme_logo'));
			}
		}
	}
}






