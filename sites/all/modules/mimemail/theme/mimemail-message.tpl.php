<?php 

/**
 * @file
 * Default theme implementation to format an HTML mail.
 *
 * Copy this file in your default theme folder to create a custom themed mail.
 * Rename it to mimemail-message--[key].tpl.php to override it for a
 * specific mail.
 *
 * Available variables:
 * - $recipient: The recipient of the message
 * - $subject: The message subject
 * - $body: The message body
 * - $css: Internal style sheets
 * - $key: The message identifier
 *
 * @see template_preprocess_mimemail_message()
 */
?>
<html>
  <head>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
    <?php if ($css): ?>
    <style type="text/css">
			
			body {
				padding: 20px;
			}
			
			#main {
				background: #f3f3f3;
				padding: 20px 40px 30px;
				font-size: 14px;
				line-height: 18px;
			}
			
    </style>
    <?php endif; ?>
  </head>
  <body id="mimemail-body" <?php if ($key): print 'class="'. $key .'"'; endif; ?> style="padding: 20px;">
		<div id="header"><img src="http://lightswitch.com/sites/default/files/mail_logo.jpg" /></div>
    <div id="center">
      <div id="main">
        <?php print $body ?>
      </div>
    </div>
  </body>
</html>
