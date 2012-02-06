<?php
/**
 * @file
 * feature_blocks.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function feature_blocks_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'Button: View Pricing';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'button_view_pricing';
  $fe_block_boxes->body = '<p><a class="btn" href="/video-production-services">View Pricing</a></p>
';

  $export['button_view_pricing'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'Contact: FAQs';
  $fe_block_boxes->format = 'php_code';
  $fe_block_boxes->machine_name = 'contact_faqs';
  $fe_block_boxes->body = '	<h3>Frequently Asked Questions:</h3>
	
	<div class="row">
		<span class="icon"></span>
		<h4>Can you describe the lightswitch process?</h4>
		<p>Lightswitch worked with me to customize my video and handled all of the production tasks from start to finish. The entire process was really simple, and the shoot didn’t interrupt my business.</p>
	</div>
	
	<div class="row">
		<span class="icon"></span>
		<h4>What was the best part about working with lightswitch?</h4>
		<p>I thought I’d have to pay thousands of dollars for an HD video, but lightSwitch delivered awesome quality for a great low price.</p>
	</div>
	
	<div class="row">
		<span class="icon"></span>
		<h4>What is the video delivery process?</h4>
		<p>In about a week after the shoot I had my video in a variety of formats which made it easy to put on my website and other social media sites.</p>
	</div>';

  $export['contact_faqs'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'Footer Blocks';
  $fe_block_boxes->format = 'php_code';
  $fe_block_boxes->machine_name = 'footer_blocks';
  $fe_block_boxes->body = '<div class="left">
	<h5>Sitemap</h5>
	<ul>
		<li><a href="/get-started-lightswitch">Contact Us</a></li>
		<li><a href="/need-videographers">Videographers</a></li>
		<li><a href="/jobs">Jobs</a></li>
	</ul>
</div>

<div class="left the-works">
	<ul>
		<li><a href="/local-business-videos">How it Works</a></li>
		<li><a href="/video-traffic-for-local-business">Why Lightswitch</a></li>
		<li><a href="/custom-business-videos">Gallery</a></li>
	</ul>
</div>

<div class="left social-links">
	<h5>Stay in Touch</h5>
	<ul>
		<li class="youtube"><a href="http://www.youtube.com/user/lightswitchbiz?blend=4&ob=video-mustangbase">YouTube</a></li>
		<li class="facebook"><a href="http://www.facebook.com/pages/Lightswitch/107652399341080">Facebook</a></li>
		<li class="vimeo"><a href="http://vimeo.com/user8579584">Vimeo</a></li>
		<li class="twitter"><a href="http://twitter.com/lightswitchbiz">Twitter</a></li>
	</ul>
</div>

<div class="left contact">
	<h5>Get in Touch</h5>
	<p><a href="mailto:info@lightswitch.com?cc=erik@lightswitch.com&subject=Website%20Inquiry">info@lightswitch.com</a><br />
	1-800-273-2849</p>
	<p class="small">600 W Chicago Ave,<br />
	Chicago IL, 60654</p>
</div>';

  $export['footer_blocks'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'Footer Copyright';
  $fe_block_boxes->format = 'php_code';
  $fe_block_boxes->machine_name = 'footer_copyright';
  $fe_block_boxes->body = '&copy; Lightswitch <?php echo date(\'Y\'); ?>. All Rights Reserved.';

  $export['footer_copyright'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'Front Top Video';
  $fe_block_boxes->format = 'php_code';
  $fe_block_boxes->machine_name = 'front_top_video';
  $fe_block_boxes->body = '<div class="left">
	<iframe src="http://player.vimeo.com/video/33848169?title=0&amp;byline=0&amp;portrait=0" width="600" height="338" frameborder="0" webkitAllowFullScreen mozallowfullscreen allowFullScreen></iframe>
</div>

<div class="right">
	<h1>VIDEO IS THE MOST EFFECTIVE METHOD OF ADVERTISING</h1>
	<h2>&quot;<span class="creme">41% of people</span> took action after watching a video ad.&quot;
	<span class="q-name">– Iab and Ipsos Mendelsohn, August 2011</span></h2>
	<h2>&quot;Sites with video are <span class="creme">53x more likely</span> than text to appear on the <span class="creme">front page of Google</span>.&quot;
	<span class="q-name">– Forrester Research</span></h2>
</div>';

  $export['front_top_video'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'Gallery: Great For';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'gallery_great_for';
  $fe_block_boxes->body = '<ul>
	<li>
		Testimonials</li>
	<li>
		Owner Stories</li>
	<li>
		Product Demos</li>
	<li>
		Corporate Events</li>
	<li>
		Corporate Profiles</li>
	<li>
		Virtual Tours</li>
	<li>
		How to Videos</li>
	<li>
		Training Videos</li>
</ul>
';

  $export['gallery_great_for'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'Home CTA';
  $fe_block_boxes->format = 'php_code';
  $fe_block_boxes->machine_name = 'home_cta';
  $fe_block_boxes->body = '<div class="left"><a href="/video-production-services" class="btn">View Pricing</a></div>
<div class="right"><h3>Lightswitch shoots professional videos, on location, <span>starting at $449!</span></h3></div>';

  $export['home_cta'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'Home: Map';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'home_map';
  $fe_block_boxes->body = '<h4>
	Nationwide Network</h4>
<div class="map">
	<a href="/map">Map</a></div>
<div class="join-us">
	<a href="/need-videographers">Join Us</a></div>
';

  $export['home_map'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'Home: Video Blocks';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'home_video_blocks';
  $fe_block_boxes->body = '<ul>
	<li>
		<p class="vid-thumb"><a href="http://vimeo.com/moogaloop.swf?clip_id=34030990" rel="shadowbox;height=450;width=605"><img alt="" src="/sites/default/files/home-video-1.jpg" style="width: 180px; height: 110px;" /></a></p>
		<p class="quote">&quot;With lightswitch you put yourself in the hands of professionals; they take care of you.&quot; &ndash;Jorge, Caf&eacute; Society</p>
		<p class="more-vids"><a class="btn-blue" href="/custom-business-videos">More Videos</a></p>
	</li>
	<li>
		<p class="vid-thumb"><a href="http://vimeo.com/moogaloop.swf?clip_id=33187917" rel="shadowbox;height=450;width=605"><img alt="" src="/sites/default/files/home-video-2.jpg" style="width: 180px; height: 110px;" /></a></p>
		<p class="quote">&quot;The day lightswitch came in it was perfect. They were on time, they were professional.&quot; -Annette, On Your Mark Fitness</p>
		<p class="more-vids"><a class="btn-blue" href="/custom-business-videos">More Videos</a></p>
	</li>
	<li>
		<p class="vid-thumb"><a href="http://vimeo.com/moogaloop.swf?clip_id=33172754" rel="shadowbox;height=450;width=605"><img alt="" src="/sites/default/files/home-video-3.jpg" style="width: 180px; height: 110px;" /></a></p>
		<p class="quote">&quot;Lightswitch was really good about incorporating our look and our brand in the video.&quot; &ndash;Marti, Urba Baby</p>
		<p class="more-vids"><a class="btn-blue" href="/custom-business-videos">More Videos</a></p>
	</li>
	<li>
		<p class="vid-thumb"><a href="http://vimeo.com/moogaloop.swf?clip_id=34031246" rel="shadowbox;height=450;width=605"><img alt="" src="/sites/default/files/home-video-4.jpg" style="width: 180px; height: 110px;" /></a></p>
		<p class="quote">&quot;Within 48 hours I already had my video in my hands, downloadable and able to be put up on my website.&quot; &ndash;Terris, Millenium Park Medical Spa</p>
		<p class="more-vids"><a class="btn-blue" href="/custom-business-videos">More Videos</a></p>
	</li>
</ul>
';

  $export['home_video_blocks'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'Home: Why Lightswitch';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'home_why_lightswitch';
  $fe_block_boxes->body = '<h4>
	Why Lightswitch</h4>
<p><img alt="" src="/sites/default/files/why_trust.png" style="width: 154px; height: 129px;" /></p>
<ul>
	<li>
		We edit, shoot and deliver for <strong>only $449</strong></li>
	<li>
		Professional network of Videographers</li>
	<li>
		From on location to on your website in <strong>just 10 days</strong></li>
</ul>
';

  $export['home_why_lightswitch'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'Home: Why Videos';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'home_why_videos';
  $fe_block_boxes->body = '<h4>
	Why Videos</h4>
<p><img alt="" src="/sites/default/files/why_search.png" style="width: 154px; height: 129px;" /></p>
<ul>
	<li>
		<strong>71%</strong> of Internet users watch videos</li>
	<li>
		Video landing pages engage customers <strong>5x more</strong> effectively</li>
	<li>
		YouTube has become the <strong>second largest</strong> search engine in the U.S.</li>
</ul>
';

  $export['home_why_videos'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'How / Pricing: Bottom';
  $fe_block_boxes->format = 'php_code';
  $fe_block_boxes->machine_name = 'how_pricing_bottom';
  $fe_block_boxes->body = '<div class="left">
	<h4>Customer Experience</h4>
	
	<div class="col c1">
		<span class="pic"></span>
		<p>“They want to benefit my business, and for me, who doesn’t understand anything about video, that was the best – to put it in the hands of some people who really take care of me and help me with the business.” Jorge, Cafe Society</p>
	</div>
	
	<div class="col c2">
		<span class="pic"></span>
		<p>“When we get referrals they can check us out before-hand. It’s so great because it really captures what we do as a business in action.” Annette, On Your Mark Fitness</p>
	</div>
</div>
<div class="right">
	<h4>Nationwide Network</h4>
	<a href="/map" class="map">Map</a>
</div>';

  $export['how_pricing_bottom'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'How: Steps';
  $fe_block_boxes->format = 'php_code';
  $fe_block_boxes->machine_name = 'how_steps';
  $fe_block_boxes->body = '<ul>
	<li class="s1">
		<span class="number"></span>
		<h3>Experienced videographer spends an hour on location shooting</h3>
		<span class="icon"></span>
	</li>
	<li class="s2">
		<span class="number"></span>
		<h3>Lightswitch edits video into customized, high quality video</h3>
		<span class="icon"></span>
	</li>
	<li class="s3">
		<span class="number"></span>
		<h3>Video is delivered in a convenient file format for all your marketing needs</h3>
		<span class="icon"></span>
	</li>
</ul>
<p><a href="/video-production-services" class="btn">View Pricing</a></p>';

  $export['how_steps'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'Need Videographer';
  $fe_block_boxes->format = 'php_code';
  $fe_block_boxes->machine_name = 'need_videographer';
  $fe_block_boxes->body = '<div class="need-top">
	<div class="bubble">
		<p>I love the flexibility and variety! Can’t wait for the next shoot.</p>
		<p class="name">Patrick B., Chicago</p>
	</div>
	<a href="/join-our-team" class="btn">Start Working now!</a>
</div>

<div class="ribbon-block what-you-need">
	<h3>Here\'s what you need!</h3>
	<ul>
		<li class="need-1">
			<span class="icon"></span>
			<h4>Creativity</h4>
			<p>A creative eye, steady hand & a storyteller\'s sensibility.</h4>
		</li>
		<li class="need-2">
			<span class="icon"></span>
			<h4>Equipment</h4>
			<p>Access to an HD camera, tripod & audio recording equipment.</h4>
		</li>
		<li class="need-3">
			<span class="icon"></span>
			<h4>Skills</h4>
			<p>Produce, direct & edit the video from start to finish.</h4>
		</li>
	</ul>
</div>

<div class="ribbon-block what-you-get">
	<h3>Here\'s what you get!</h3>
	<ul>
		<li class="get-1">
			<span class="icon"></span>
			<h4>Variety</h4>
			<p>Access to a variety of projects & clients from around the country.</h4>
		</li>
		<li class="get-2">
			<span class="icon"></span>
			<h4>Payment</h4>
			<p>We handle selling & billing so you get paid quickly & reliably.</h4>
		</li>
		<li class="get-3">
			<span class="icon"></span>
			<h4>Flexibility</h4>
			<p>You get to work with clients & set your own schedule.</h4>
		</li>
	</ul>
</div>
';

  $export['need_videographer'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'Pricing Blocks';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'pricing_blocks';
  $fe_block_boxes->body = '<div class="price-block">
	<h1>
		Standard Video</h1>
	<div class="vid-thumb">
		<a href="http://vimeo.com/moogaloop.swf?clip_id=34032033" rel="shadowbox;height=450;width=605"><img alt="" src="/sites/default/files/pricing-video-1.jpg" style="width: 241px; height: 133px;" /></a></div>
	<p class="the-price">$449.00</p>
	<p><a class="btn" href="#block-webform-client-block-5" rel="shadowbox;width=400;height=650;">Get Started</a></p>
	<p class="cc">no credit card required</p>
	<ul>
		<li>
			60-second</li>
		<li>
			High Definition Video</li>
		<li>
			Studio-quality Music</li>
		<li>
			Text Graphics</li>
		<li>
			Five Professional Photos</li>
		<li>
			One Free Round of Edits *</li>
	</ul>
	<p class="edits">* Additional edits are $50.00</p>
</div>
<div class="price-block">
	<h1>
		Video with Interview</h1>
	<div class="vid-thumb">
		<a href="http://vimeo.com/moogaloop.swf?clip_id=34030990" rel="shadowbox;height=450;width=605"><img alt="" src="/sites/default/files/pricing-video-2.jpg" style="width: 241px; height: 133px;" /></a></div>
	<p class="the-price">$549.00</p>
	<p><a class="btn" href="#">Get Started</a></p>
	<p class="cc">no credit card required</p>
	<ul>
		<li>
			Standard video</li>
		<li class="plus">
			+</li>
		<li>
			Sit down interview</li>
		<li>
			Professional audio equipment</li>
	</ul>
</div>
<div class="price-block">
	<h1>
		Video with Voice-over</h1>
	<div class="vid-thumb">
		<a href="http://vimeo.com/moogaloop.swf?clip_id=33172754" rel="shadowbox;height=450;width=605"><img alt="" src="/sites/default/files/pricing-video-3.jpg" style="width: 241px; height: 133px;" /></a></div>
	<p class="the-price">$599.00</p>
	<p><a class="btn" href="#">Get Started</a></p>
	<p class="cc">no credit card required</p>
	<ul>
		<li>
			Standard video</li>
		<li class="plus">
			+</li>
		<li>
			Professional video script</li>
		<li>
			Professional voice-over artist for recording</li>
	</ul>
</div>
<p>&nbsp;</p>
';

  $export['pricing_blocks'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'Why: Content';
  $fe_block_boxes->format = 'php_code';
  $fe_block_boxes->machine_name = 'why_content';
  $fe_block_boxes->body = '<h2>Lightswitch will shoot, edit and deliver a professional video customized to your business. We do it faster, better and cheaper than anyone else.</h2>
<p><a href="/video-production-services" class="btn">View Pricing</a></p>
<span class="camera"></span>';

  $export['why_content'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'Why: Screen Shots';
  $fe_block_boxes->format = 'php_code';
  $fe_block_boxes->machine_name = 'why_screen_shots';
  $fe_block_boxes->body = '<span class="screen-shots"></span>
<p>MOI Boutique is using video to engage on Facebook</p>';

  $export['why_screen_shots'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'Why: Tabs';
  $fe_block_boxes->format = 'php_code';
  $fe_block_boxes->machine_name = 'why_tabs';
  $fe_block_boxes->body = '<ul class="clearfix">
	<li><a href="block-1">Why Video</a></li>
	<li><a href="block-2">Why lightswitch</a></li>
</ul>

<div class="tab-area clearfix">
	<div id="block-1" class="tab-block">
		<h3>Why local businesses need video</h3>
		<div class="col c1">
			<h4>Search for Local Business Starts Online</h4>
			<span class="icon"></span>
			<p><strong>74%</strong> of internet users perform local searches</p>
			<p><strong>61%</strong> of those searches result in a store purchase</p>
		</div>
		<div class="col c2">
			<h4>Improve Rankings</h4>
			<span class="icon"></span>
			<p>Sites containing video are <strong>53x</strong> more likely to appear on the first page of Google results</p>
		</div>
		<div class="col c3">
			<h4>Engage Users</h4>
			<span class="icon"></span>
			<p>Video landing pages generate <strong>5x</strong> higher engagement and response rates</p>
		</div>
		<div class="col c4">
			<h4>Convert Customers</h4>
			<span class="icon"></span>
			<p><strong>41%</strong> of people take action after watching a video</p>
		</div>
	</div>
	
	<div id="block-2" class="tab-block">
		<h3>Why Lightswitch</h3>
		<div class="col c1">
			<h4>Price</h4>
			<span class="icon"></span>
			<p>We edit, shoot and deliver for only $449</p>
		</div>
		<div class="col c2">
			<h4>Nationwide Network</h4>
			<span class="icon"></span>
			<p>Professional network of Videographers</p>
		</div>
		<div class="col c3">
			<h4>Fast Delivery</h4>
			<span class="icon"></span>
			<p>From on location to on your website in just 10 days</p>
		</div>
		<div class="col c4">
			<h4>Full Rights to Video</h4>
			<span class="icon"></span>
			<p>You get full rights to the video, forever</p>
		</div>
	</div>
</div><!-- tab-area -->
';

  $export['why_tabs'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'Why: Testimonials / FAQ';
  $fe_block_boxes->format = 'php_code';
  $fe_block_boxes->machine_name = 'why_testimonials';
  $fe_block_boxes->body = '<div class="left">

	<h3>What our customers say:</h3>
	
	<div class="row r1">
		<span class="pic"></span>
		<h4>Jorge</h4>
		<h5>Cafe Society</h5>
		<p>&quot;The beauty of doing business with lightswitch is that you put yourself in the hands of professionals, they take care of you, and you don’t have to do nothing.&quot;</p>
	</div>
	
	<div class="row r2">
		<span class="pic"></span>
		<h4>Annette</h4>
		<h5>On Your Mark Fitness</h5>
		<p>&quot;The day lightswitch came in it was perfect. They were on time, they were professional, we were busy doing our thing and they jumped right in and did their thing. I can’t believe how wonderful the video turned out, it was crisp it was clean, so professional, it was perfect.&quot;</p>
	</div>
	
	<div class="row r3">
		<span class="pic"></span>
		<h4>Terris</h4>
		<h5>Millenium Park Medical Spa</h5>
		<p>&quot;I was definitely not expecting within 48 hours to have a file already sent to me with the ability for me to download it and get it on my website right away. I was impressed with its quality.&quot;</p>
	</div>
	
</div>

<div class="right">

	<h3>Frequently Asked Questions:</h3>
	
	<div class="row">
		<span class="icon"></span>
		<h4>Can you describe the lightswitch process?</h4>
		<p>Lightwwitch worked with me to customize my video and handled all of the production tasks from start to finish. The entire process was really simple, and the shoot didn’t interrupt my business.</p>
	</div>
	
	<div class="row">
		<span class="icon"></span>
		<h4>What was the best part about working with lightswitch?</h4>
		<p>I thought I’d have to pay thousands of dollars for an HD video, but lightSwitch delivered awesome quality for a great low price.</p>
	</div>
	
	<div class="row">
		<span class="icon"></span>
		<h4>What is the video delivery process?</h4>
		<p>In about a week after the shoot I had my video in a variety of formats which made it easy to put on my website and other social media sites.</p>
	</div>

</div>';

  $export['why_testimonials'] = $fe_block_boxes;

  return $export;
}
