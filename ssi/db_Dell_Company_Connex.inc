<?php
	$con=mysql_connect("localhost","root","");
	
	if (!$con){
		die('Could not connect:'.mysql_error());
	}
	
	mysql_select_db("dell_company_db",$con) or die('Could not select database');
?>