<?php
	//we need to get our variables first
	if(isset($_POST["post"])){
		$name     =   trim($_POST['name']);
		$last     =   trim($_POST['last']);
		$business     =   trim($_POST['business']);
		$email    =   trim($_POST['email']);
		$coupon  = 'FALL2011';
		$comment  =   $_POST['comment'];
		$message = "Name: $name \n Last Name: $last \n Business name: $business \n Email : $email \n ------- \n Comments: \n $comment \n Coupon: \n $coupon";
		/*the $header variable is for the additional headers in the mail function,
		we are asigning 2 values, first one is FROM and the second one is REPLY-TO.
		That way when we want to reply the email gmail(or yahoo or hotmail...) will know 
		who are we replying to. */
		$headers  = "From: $email\r\n";
		$headers .= "Reply-To: $email\r\n";

		if(mail("info@lightswitch.com", "Lightswitch contact form", $message, $headers)){
			header( 'Location: index.html' );
			//Sent
		}else{
			//Failed!
		}
	}
?>