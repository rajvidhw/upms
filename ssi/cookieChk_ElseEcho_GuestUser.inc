<?php
	if (isset($_COOKIE["user"]))
	  echo "<i><font style=\"font-family:'Trebuchet MS', Arial, Helvetica, sans-serif\" size=\"-1\" color=\"#006699\">
	  		Welcome " . $_COOKIE["user"] . "!<br/><hr/>".
			"</i></font>";
	else
	  echo "<i><font style=\"font-family:'Trebuchet MS', Arial, Helvetica, sans-serif\" size=\"-1\" color=\"#006699\">
	  		Welcome guest!<br>Login to access page<br/><hr/>".
			"</i></font>";	  
?>