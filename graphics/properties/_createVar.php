<?php
	if ($_POST['isArray'] == "on") {
		unset($_POST['isArray']);
		$_POST['array'] = "yes";
	} else {
		$_POST['array'] = "no";
	}
	
	$jsonString = "{";
	foreach($_POST as $key => $value) {
		if ($key != "parent") {
			//if ($key == "initValue") {
			//	$value = str_replace("\"",DOUBLECOMS,$value);
			//	$value = str_replace("'",SINGLECOMS,$value);
			//}
			$jsonString .= "\"".$key."\":\"".$value."\",";
		}
	}
	$jsonString = substr($jsonString,0,strlen($jsonString)-1)."}";
?>
<script>
	window.parent.frames['code'].createVar('<?=$_POST['parent']?>','<?=$jsonString?>');
</script>