<?php
	$_GET['comp1'] = str_replace("DOUBLECOMS","&#034;",$_GET['comp1']);
	$_GET['comp1'] = str_replace("SINGLECOMS","&#039;",$_GET['comp1']);
	$_GET['comp2'] = str_replace("DOUBLECOMS","&#034;",$_GET['comp2']);
	$_GET['comp2'] = str_replace("SINGLECOMS","&#039;",$_GET['comp2']);
?>
<html>
	<head>
		<link rel="stylesheet" href="../main.css" type="text/css"/>
		<script src="../main.js"></script>
		<script src="../jquery.js"></script>
		<style>		
			body, html {
				font-size: 12px;
			}
			h2 {
				margin: 0 0 10px 0;
				text-align: center;
				text-shadow: 0px 1px 2px #FFF;
			}
			
			h3 {
				margin: 0;
				cursor: pointer;
				line-height: 20px;
			}
			
			h3:hover {
				background-color: #EFFFFF;
			}
			
			h3 img {
				float: right;
				width: 18px;
				vertical-align: middle;
			}
			
			div.group, form.group {
				border-top: 1px solid #333;
				padding-top: 5px;
				margin-bottom: 15px;
			}
			
			h3.hidden-form {
				border-bottom: none;
			}
			
			.hidden {
				display: none;
			}
		</style>
	</head>
	<body>
		<h2>Decisi&oacute;n</h2>
		<h3 onClick="showMenu('div#attributes');">
			Atributos
			<img src="../images/arrow-right.png"/>
		</h3>
		<div id="attributes" class="group">
			Variable1: <input type="text" name="comp1" value="<?=$_GET['comp1']?>" onKeyUp="window.parent.frames['code'].modifyAttr('<?=$_GET['type']."-".$_GET['id']?>','comp1',this.value);"/>
			<br/>
			Comparador: 
			<select name="comparator" onChange="window.parent.frames['code'].modifyAttr('<?=$_GET['type']."-".$_GET['id']?>','comparator',this.value);">
				<option <?if($_GET['comparator']=="IGUAL") echo "selected='selected'"?>>IGUAL</option>
				<option <?if($_GET['comparator']=="DIFERENTE") echo "selected='selected'"?>>DIFERENTE</option>
				<option <?if($_GET['comparator']=="MAYOR") echo "selected='selected'"?>>MAYOR</option>
				<option <?if($_GET['comparator']=="MENOR") echo "selected='selected'"?>>MENOR</option>
			</select>
			<br/>
			Variable2: <input type="text" name="comp2" value="<?=$_GET['comp2']?>" onKeyUp="window.parent.frames['code'].modifyAttr('<?=$_GET['type']."-".$_GET['id']?>','comp2',this.value);"/>
		</div>
		<h3 onClick="showMenu('form#operationt');">
			Operaci&oacute;n en Verdadero
			<img src="../images/arrow-right.png"/>
		</h3>
		<form id="operationt" class="group hidden">
<?php
			$_GET['whosParent'] = "li#".$_GET['type']."-".$_GET['id']." ul#".$_GET['type']."-true";
			$_GET['o'] = "operationt";
			include("_addOp.php"); 
?>
		</form>
		<h3 onClick="showMenu('form#operationf');">
			Operaci&oacute;n en Falso
			<img src="../images/arrow-right.png"/>
		</h3>
		<form id="operationf" class="group hidden">
<?php
			$_GET['whosParent'] = "li#".$_GET['type']."-".$_GET['id']." ul#".$_GET['type']."-false";
			$_GET['o'] = "operationf";
			include("_addOp.php"); 
?>
		</form>
		<div id="script"></div>
	</body>
</html>
