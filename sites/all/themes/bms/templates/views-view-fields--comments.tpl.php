<?php
/**
 * @file views-view-fields.tpl.php
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to use.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */

// dpm($row);

?>
<?php

	$output = '';
	$nid = arg(1);
	$project = new Project($nid);

	// output the views fields as usual
	foreach ($fields as $id => $field){
	  if (!empty($field->separator)){
	    $output .= $field->separator;
	  }
	  $output .= $field->wrapper_prefix;
	  $output .= $field->label_html;
	  $output .= $field->content;
	  $output .= $field->wrapper_suffix;
	}

	// if comment is a revision list
	if(!empty($row->field_field_revision_list) && $row->field_field_revision_list[0]['raw']['value'] == 1){
		
		// if revision list is approved
		if(!empty($row->field_field_revision_approved) && $row->field_field_revision_approved[0]['raw']['value'] == 1){
			
			$output .= '<div class="revision-approved">' . $project->client->field_name['und'][0]['value'] . ' approved revision list on ' . $row->field_field_revision_approved_date[0]['rendered']['#markup'] . '</div>';
		
		// if revision list is declined
		}else if(!empty($row->field_field_declined_reason)){
			
			$output .= '<div class="revision-declined">DECLINED on ' . $row->field_field_declined_date[0]['rendered']['#markup'];
			$output .= '<div class="reason"><strong>Reason:</strong><br/>' . $row->field_field_declined_reason[0]['raw']['value'] . '</div>';			
			$output .= '</div>';
		
		// if revision list needs the user's response
		}else{
			
			$output .= '<div class="comment-approval">';
			$output .= '<p>Do you accept the above list to be used as your one free round of revisions?<br />';
			$output .= '<em>Note: if you decline you must specify a reason.</em></p>';
			$output .= '<div><a class="revision-approve-client btn" href="/comment/approve/client/' . $row->nid . '/' . $nid . '">I accept</a> <a class="revision-decline-client btn" href="/comment/decline/client/' . $row->nid . '/' . $nid . '">I decline</a></div>';
			$output .= '</div>';
			
		}
	
	}
	
	print $output;

?>