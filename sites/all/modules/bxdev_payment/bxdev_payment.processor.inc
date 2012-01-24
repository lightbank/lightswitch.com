<?php

class Processor {
	
	var $api_login_id = '2hQT4t8ua';
	var $transaction_key = '3bNDCu4r334K9327';
	var $merchant_authentication;
	var $api_post_url = 'https://apitest.authorize.net/xml/v1/request.api';
	var $xmlns = 'AnetApi/xml/v1/schema/AnetApiSchema.xsd';
	var $xml_header = '<?xml version="1.0" encoding="utf-8"?>';
	
	function __construct(){
		$this->merchant_authentication = '
			<merchantAuthentication>
				<name>' . $this->api_login_id . '</name>
				<transactionKey>' . $this->transaction_key . '</transactionKey>
			</merchantAuthentication>';
	}
	
	function add_client($account){
		$xml_tag = 'createCustomerProfileRequest';
		$xml = $this->xml_header;
		$xml .= '<createCustomerProfileRequest xmlns="' . $this->$xmlns . '">';
		$xml .= $this->merchant_authentication;
		$xml .= '
		<profile>
			<merchantCustomerId>' . $account->uid . '</merchantCustomerId>
			<email>' . $account->mail . '</email>
			<paymentProfiles>
				<payment>
					<creditCard>
						<cardNumber>' . $cc_number . '</cardNumber>
						<expirationDate>' . $cc_expiry . '</expirationDate>
					</creditCard>
				</payment>
			</paymentProfiles>
		</profile>';
		$xml .= '</createCustomerProfileRequest>';
		
		$response = $this->send_xml_request($xml);
		
		return $response;
	}
	
	function send_xml_request($content){
		$ch = curl_init();
		curl_setopt($ch, CURLOPT_URL, $this->api_post_url);
		curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
		curl_setopt($ch, CURLOPT_HTTPHEADER, Array("Content-Type: text/xml"));
		curl_setopt($ch, CURLOPT_HEADER, 1);
		curl_setopt($ch, CURLOPT_POSTFIELDS, $content);
		curl_setopt($ch, CURLOPT_POST, 1);
		curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, 0);
		$response = curl_exec($ch);
		return $response;
	}
	
	
}