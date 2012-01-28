<?php

/**
 * FORMS
 */

/**
 * Form submit: client terms
 */
function bxdev_document_client_terms_form_submit($form, &$form_state){
	
	$nid = arg(2);
	$project = new Project($nid);
	$data['project'] = $project;
	
	// get the client service agreement html
	$content = variable_get('document_client_service_agreement', array());
	
	$html = token_replace($content['value'], $data);
	$filename = 'client_service_agreement_' . $project->project->nid . '.pdf';
	
	$fid = bxdev_document_create_pdf($html, $filename, 'client', 'Client Service Agreement', $project->client->uid, $project->project->nid);
	
	if($fid){
		$project->send_client_service_agreement($fid);
		drupal_goto('node/1244');
	}
	
}

/**
 * Form builder: document settings
 */
function bxdev_document_settings_form($form, &$form_state){
		
	$client_service_agreement = variable_get('document_client_service_agreement', array());
	
	$form['client_service_agreement_fieldset'] = array(
		'#type' => 'fieldset',
		'#title' => t('Client Service Agreement'),
		'#collapsible' => TRUE,
		'#collapsed' => FALSE,
	);
	
	$form['client_service_agreement_fieldset']['document_client_service_agreement'] = array(
		'#type' => 'text_format',
		'#default_value' => !empty($client_service_agreement) ? $client_service_agreement['value'] : '',
	);
	
	return system_settings_form($form);
}