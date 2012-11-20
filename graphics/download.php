<?php
	$filename =$_POST['progname'].".sofi";
	header("Content-type: text/plain");
	header('Content-Disposition: attachment; filename='.$filename);

	echo stripslashes($_POST['code']);
?>