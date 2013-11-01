<?php
	$qryResultSet	= mysql_query("SELECT * FROM tblcustomer");
	$numRows 		= mysql_numrows(mysql_query("SELECT * FROM tblcustomer"));
	 
	//has to check if no record has been returned
	
	$xml_Content = "";
	
	/*$xml_HeaderAndRoot_OpenTag = "<?xml version=\"1.0\"?><laptops>"; */
	//no need to add header have used SimpleXMLElement below to convert to xml file
	
	$xml_HeaderAndRoot_OpenTag = "<customers>\n";	//  \n new line		\t horizontal tab
	$xml_HeaderAndRoot_CloseTag = "\n</customers>";
	
	$xml_Content .= $xml_HeaderAndRoot_OpenTag;	//Adding xml version and opening tag for Laptops

	//$xml_Content .= $numRows;

	for($j=0;$j<$numRows;$j++){
		 
		$cid				= mysql_result($qryResultSet,$j,'C_Id');
		$firstName			= mysql_result($qryResultSet,$j,'FName');
		$lastName			= mysql_result($qryResultSet,$j,'Lname');
		$gender				= mysql_result($qryResultSet,$j,'Gender');
		$dobDay				= mysql_result($qryResultSet,$j,'DOBday');
		$dobMonth			= mysql_result($qryResultSet,$j,'DOBmonth');
		$dobYear			= mysql_result($qryResultSet,$j,'DOByear');
		
		$postalCode			= mysql_result($qryResultSet,$j,'PostalCode');
		$addrStreet			= mysql_result($qryResultSet,$j,'StreetName');
		$addrTownVillage	= mysql_result($qryResultSet,$j,'TownVillageName');
		$addrDistrict		= mysql_result($qryResultSet,$j,'DistrictName');
		
		$phoneFix			= mysql_result($qryResultSet,$j,'Phone');
		$phoneMobile		= mysql_result($qryResultSet,$j,'Mobile');
		$addrEmail			= mysql_result($qryResultSet,$j,'EMail');
		$userName			= mysql_result($qryResultSet,$j,'Username');
		$password			= mysql_result($qryResultSet,$j,'Password');	
	
		$xml_Content .= 
			"\n\t<customer cid = \"".$cid."\">
			\n\t\t<firstName>".$firstName."</firstName>
			\n\t\t<lastName>".$lastName."</lastName>
			\n\t\t<gender>".$gender."</gender>
			\n\t\t<dob>
			\n\t\t\t<dobDay>".$dobDay."</dobDay>
			\n\t\t\t<dobMonth>".$dobMonth."</dobMonth>
			\n\t\t\t<dobYear>".$dobYear."</dobYear>
			\n\t\t</dob>
			\n\t\t<contactDetails>
			\n\t\t\t<address>
			\n\t\t\t\t<postalCode>".$postalCode."</postalCode>
			\n\t\t\t\t<addrStreet>".$addrStreet."</addrStreet>
			\n\t\t\t\t<addrTownVillage>".$addrTownVillage."</addrTownVillage>
			\n\t\t\t\t<addrDistrict>".$addrDistrict."</addrDistrict>
			\n\t\t\t</address>
			\n\t\t\t<phoneNumbers>
			\n\t\t\t\t<phoneFix>".$phoneFix."</phoneFix>
			\n\t\t\t\t<phoneMobile>".$phoneMobile."</phoneMobile>
			\n\t\t\t</phoneNumbers>
			\n\t\t\t<addrEmail>".$addrEmail."</addrEmail>
			\n\t\t</contactDetails>
			\n\t\t<userName>".$userName."</userName>
			\n\t\t<password>".$password."</password>
			\n\t</customer>\n"	
		;//END Concat $xml_Content
		
	}// END For Loop
	
	// $xml_Content --> the xml file without header(xml version = 1.0...), ONLY root node and nodes inside root node
	
	$xml_Content .= $xml_HeaderAndRoot_CloseTag;
?>