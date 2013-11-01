<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
        <title>register new system user</title>
        
        <!-- bootsrap css -->
        <link rel="stylesheet" type="text/css" href="css/bootstrap.css"/>
    <script src="../../SpryAssets/SpryValidationPassword.js" type="text/javascript"></script>
    <link href="../../SpryAssets/SpryValidationPassword.css" rel="stylesheet" type="text/css" />
    </head>
    
    <body>
    
    	<div class="container">
        
        	<div class="jumbotron">
            
            	<h1>UPMS User Registration</h1>
                <p>Please fill in the requested information to create a user account
                <br/>Users will be allowed to edit only part of the system relevant to their access rights</p>
            
            </div>
        
        	
    
            <form class="well form-horizontal">
            
            	<!-- title -->
                <div class="form-group">
                    <label class="col-md-2 control-label" for="title">Title</label>
                    <div class="col-md-4">
                        <select id="txtTitle" name="txtTitle" class="form-control">
                        
                        	<option value="0">Your title:</option>
                        
                            <option value="Mr">Mr</option>
                            <option value="Mrs">Mrs</option>
                            <option value="Miss">Miss</option>
                        </select>        
                    </div>
                </div>        
            
            	<!-- first name -->
                <div class="form-group">
                    <label class="col-md-2 control-label" for="first name">First name</label>
                    <div class="col-md-4">
                        <input id="txtFirstName" name="txtFirstName" type="text" class="form-control" placeholder="enter first name"/>            
                    </div>
                </div>
    			
                <!-- last name -->
                <div class="form-group">
                    <label class="col-md-2 control-label" for="last name">Last name</label>
                    <div class="col-md-4">
                        <input id="txtLastName" name="txtLastName" type="text" class="form-control" placeholder="enter last name">
                    </div>
                </div>                       
                
                <!-- DOB -->
                <div class="form-group"> <!-- DOB FIELD -->
                    <label class="col-md-2 control-label" for="dob">Date Of Birth</label>
                    <div class="col-md-4">
                    
                        <?php include('register_new_system_users_generate_options.php') ?>
                    
                        
                        <div class="row">
                        
                            <div class="col-md-4">
                                <select name="month" class="form-control">
                                    <option value="0">Month:</option>
                                    <?=generate_options(1,12,'callback_month')?>
                                </select>
                            </div>
                            <div class="col-md-4">
                                <select name="day" class="form-control">
                                    <option value="0">Day:</option>
                                    <?=generate_options(1,31)?>
                                </select>                            
                            </div>
                            <div class="col-md-4">
                                <select name="year" class="form-control">
                                    <option value="0">Year:</option>
                                    <?=generate_options(date('Y'),1900)?>
                                </select>                            
                            </div>
                            
                        </div> <!-- end 'row' -->
                        
                    
                    </div> <!-- end 'col-md-3' -->
                </div> <!-- end - DOB FIELD - 'form-group' --> 
                
                <!-- e-mail -->
                <div class="form-group">
                    <label class="col-md-2 control-label" for="email">Email address</label>
                    <div class="col-md-4">
                        <input id="txtEmail" name="txtEmail" type="email" class="form-control" placeholder="enter email">
                    </div>
                </div>                
                         
                <!-- department -->
                <div class="form-group">
                    <label class="col-md-2 control-label" for="department">Current Department</label>
                    <div class="col-md-4">
                        <select id="txtDepartment" name="txtDepartment" class="form-control">
                        
                        	<option value="0">Department:</option>
                                        
                            <?php
                                //creating connection to database
                                include('ssi/dbConnex.inc');
    
                                $qryResultSet	= mysql_query("SELECT * FROM tbladmin");
                                
                                $options = '';
                                
                                while($row = mysql_fetch_array($qryResultSet)){
                                    $options .= "<option value=\"" . $row['name'] . "\">" . $row['name'] . "</option>";
                                }
                                
                                echo ($options);
                            ?>
                                                                                       
                        </select>
                    </div>
                </div>            
                
                <!-- position in department -->
                <div class="form-group">
                    <label class="col-md-2 control-label" for="current position in department">Current Position</label>
                    <div class="col-md-3">
                        <select id="txtDepartment" name="txtDepartment" class="form-control">
                        
                        	<option value="0">Current Position In Department:</option>
                                        
                            <?php
                                //creating connection to database
                                include('ssi/dbConnex.inc');
    
                                $qryResultSet	= mysql_query("SELECT * FROM tbladmin");
                                
                                $options = '';
                                
                                while($row = mysql_fetch_array($qryResultSet)){
                                    $options .= "<option value=\"" . $row['name'] . "\">" . $row['name'] . "</option>";
                                }
                                
                                echo ($options);
                            ?>
                                                                                       
                        </select>
                    </div>
                    
                    <div class="col-md-1">
                    	
                        <!-- TOOLTIP - HOW TO
                        <a href="#" data-toggle="tooltip" title="Tooltip message">text initiating tooltip</a>
                    	-->
                    	<a href="#" class="btn btn-primary" data-toggle="tooltip" title="Add user previous position(s) - (in same or another department(s))">add...</a>
                    </div>
                    
                </div> 
                
               
                
            
            
            </form>
       
        </div> <!-- container all page -->
        
        <!-- bootstrap js, put at end of page to optimize page loading -->
        <script src="js/bootstrap.js"></script>
        <script src="js/register_new_system_users_tooltip_JQuery.js"></script>
    </body>
</html>