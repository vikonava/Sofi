<?php
	$_GET['compareVal'] = str_replace("DOUBLECOMS","&#034;",$_GET['compareVal']);
	$_GET['compareVal'] = str_replace("SINGLECOMS","&#039;",$_GET['compareVal']);
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
		<h2>Para</h2>
		<h3 onClick="showMenu('div#attributes');">
			Atributos
			<img src="../images/arrow-right.png"/>
		</h3>
		<div id="attributes" class="group">
			Variable de Control: <input type="text" name="varControl" value="<?=$_GET['varControl']?>" onKeyUp="window.parent.frames['code'].modifyAttr('<?=$_GET['type']."-".$_GET['id']?>','varControl1',this.value);window.parent.frames['code'].modifyAttr('<?=$_GET['type']."-".$_GET['id']?>','varControl2',this.value);window.parent.frames['code'].modifyAttr('<?=$_GET['type']."-".$_GET['id']?>','varControl3',this.value);"/>
			<br>
			Comparador:
			<select name="comparation" onChange="window.parent.frames['code'].modifyAttr('<?=$_GET['type']."-".$_GET['id']?>','comparation',this.value);">
				<option <?if($_GET['comparation']=="IGUAL") echo "selected='selected'"?>>IGUAL</option>
				<option <?if($_GET['comparation']=="DIFERENTE") echo "selected='selected'"?>>DIFERENTE</option>
				<option <?if($_GET['comparation']=="MAYOR") echo "selected='selected'"?>>MAYOR</option>
				<option <?if($_GET['comparation']=="MENOR") echo "selected='selected'"?>>MENOR</option>
			</select>
			<br/>
			Comparaci&oacute;n: <input type="text" name="compareVal" value="<?=$_GET['compareVal']?>" onKeyUp="window.parent.frames['code'].modifyAttr('<?=$_GET['type']."-".$_GET['id']?>','compareVal',this.value);"/>
			<br/>
			Modificador: <input type="text" name="incr" value="<?=$_GET['incr']?>" onKeyUp="window.parent.frames['code'].modifyAttr('<?=$_GET['type']."-".$_GET['id']?>','incr',this.value);"/>
		</div>
		<h3 onClick="showMenu('form#operation');">
			Agregar Operaci&oacute;n
			<img src="../images/arrow-right.png"/>
		</h3>
		<form id="operation" class="group hidden">
<?php
			$_GET['whosParent'] = "li#".$_GET['type']."-".$_GET['id']." ul#para-realiza:first";
			include("_addOp.php"); 
?>
		</form>
		<div id="script"></div>
	</body>
</html>
