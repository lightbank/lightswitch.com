<div class="invoice-wrap">

<h1>Invoice</h1>
<p>Date: <?php print date('F d, Y'); ?></p>
<p>Invoice #: <?php print $invoice_num; ?></p>

<table class="billing-info" border="0" cellspacing="0" cellpadding="0">
	<tr>
		<td class="col-1">
			Lightswitch<br/>
			600 West Chicago Ave<br/>
			Suite 700<br/>
			312-999-3093<br/>
			Fax: 312-276-4022<br/>
			info@lightswitch.com
		</td>
		<td class="col-2">TO</td>
		<td class="col-3">
			<?php print $project->client->field_name['und'][0]['value']; ?><br/>
			<?php print $project->business->title; ?><br/>
			<?php print nl2br($project->business->field_address['und'][0]['value']); ?><br/>
			<?php print $project->business->field_phone['und'][0]['value']; ?><br/>
		</td>
	</tr>
</table>

<table class="line-items" border="0" cellspacing="0" cellpadding="0">
	<tr>
		<th class="qty">QTY</th>
		<th class="desc">DESCRIPTION</th>
		<th class="price">UNIT PRICE</th>
		<th class="price">LINE TOTAL</th>
	</tr>
	<?php foreach($line_items as $key => $line_item): ?>
		<?php if(is_numeric($key)): ?>
			<tr>
				<td><?php print $line_item['qty']; ?></td>
				<td><?php print $line_item['description']; ?></td>
				<td><?php print bxdev_format_currency($line_item['unit_price']); ?></td>
				<td><?php print bxdev_format_currency($line_item['line_total']); ?></td>
			</tr>
		<?php endif; ?>
	<?php endforeach; ?>
	<tr>
		<td class="no-border"></td>
		<td class="no-border"></td>
		<td class="no-border"><strong>SUBTOTAL</strong></td>
		<td><?php print bxdev_format_currency($line_items['total']); ?></td>
	</tr>
	<tr>
		<td class="no-border"></td>
		<td class="no-border"></td>
		<td class="no-border"><strong>TOTAL</strong></td>
		<td><?php print bxdev_format_currency($line_items['total']); ?></td>
	</tr>			
</table>

<div class="footer">
	<p>Make your check payable to <u><strong>Lightswitch Holdings, Inc</strong></u></p>
	<h2>Thank you for your business!</h2>
</div>

</div>