<?php
	$qryResultSet	= mysql_query("SELECT * FROM tbllaptop");
	$numRows = mysql_numrows(mysql_query("SELECT * FROM tbllaptop"));
	 
	//has to check if no record has been returned
	
	$xml_Content = "";
	
	/*$xml_HeaderAndRoot_OpenTag = "<?xml version=\"1.0\"?><laptops>"; */
	//no need to add header have used SimpleXMLElement below to convert to xml file
	
	$xml_HeaderAndRoot_OpenTag = "<laptops>\n";	//  \n new line		\t horizontal tab
	$xml_HeaderAndRoot_CloseTag = "\n</laptops>";
	
	$xml_Content .= $xml_HeaderAndRoot_OpenTag;	//Adding xml version and opening tag for Laptops
	 
	for($i=0;$i<$numRows;$i++){
		 
		$lid				    = mysql_result($qryResultSet,$i,'L_Id');
		$lName					= mysql_result($qryResultSet,$i,'L_Name');
		$lModel					= mysql_result($qryResultSet,$i,'L_Model');
		$lProcessor				= mysql_result($qryResultSet,$i,'L_Processor');
		$lProcessorSpeed		= mysql_result($qryResultSet,$i,'L_ProcessorSpeed');
		$lRam					= mysql_result($qryResultSet,$i,'L_Ram');
		$lHDD					= mysql_result($qryResultSet,$i,'L_HDD');
		$lScreenSize			= mysql_result($qryResultSet,$i,'L_ScreenSize');
		$lScreenDescription		= mysql_result($qryResultSet,$i,'L_ScreenDescription');
		$lMoreDescription		= mysql_result($qryResultSet,$i,'L_MoreDescription');
		$lPrice					= mysql_result($qryResultSet,$i,'L_Price');
		$lImageURL				= mysql_result($qryResultSet,$i,'L_ImageURL');
	
	
		$xml_Content .= 
		
			"\n\t<laptop lid = \"".$lid."\">
			\n\t\t<name>".$lName."</name>
			\n\t\t<model>".$lModel."</model>
			\n\t\t<technicalDetails>
			\n\t\t\t<processorDetails>
			\n\t\t\t\t<processorType>".$lProcessor."</processorType>
			\n\t\t\t\t<processorSpeed>".$lProcessorSpeed."</processorSpeed>
			\n\t\t\t</processorDetails>
			\n\t\t\t<ramSize>".$lRam."</ramSize>
			\n\t\t\t<hddSize>".$lHDD."</hddSize>
			\n\t\t\t<screenSize>".$lScreenSize."</screenSize>
			\n\t\t\t<screenType>".$lScreenDescription."</screenType>
			\n\t\t</technicalDetails>
			\n\t\t<additionalDescription>".$lMoreDescription."</additionalDescription>
			\n\t\t<price>".$lPrice."</price>
			\n\t\t<imgUrl>".$lImageURL."</imgUrl>
			\n\t</laptop>\n"	
		;//END Concat $xml_Content
		
	}// END For Loop
	
	// $xml_Content --> the xml file without header, ONLY root node and nodes inside root node
	
	$xml_Content .= $xml_HeaderAndRoot_CloseTag;
?>