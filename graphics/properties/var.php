<?php
	$_GET['initValue'] = str_replace("DOUBLECOMS","&#034;",$_GET['initValue']);
	$_GET['initValue'] = str_replace("SINGLECOMS","&#039;",$_GET['initValue']);
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
		<h2>Variable</h2>
		<h3 onClick="showMenu('div#attributes');">
			Atributos
			<img src="../images/arrow-right.png"/>
		</h3>
		<div id="attributes" class="group">
			<div>
				Nombre: <input type="text" name="name" value="<?=$_GET['name']?>" onKeyUp="window.parent.frames['code'].modifyAttr('<?=$_GET['type']."-".$_GET['id']?>','name',this.value);"/><br/>
			</div>
			<div>
				Tipo:
				<select onChange="window.parent.frames['code'].modifyAttr('<?=$_GET['type']."-".$_GET['id']?>','varType',this.value);">
					<option value="caracter" <?if($_GET['varType']=="caracter") echo"selected='selected'";?>>Caracter</option>
					<option value="texto" <?if($_GET['varType']=="texto") echo"selected='selected'";?>>Texto</option>
					<option value="numero" <?if($_GET['varType']=="numero") echo"selected='selected'";?>>N&uacute;mero</option>
					<option value="decimal" <?if($_GET['varType']=="decimal") echo"selected='selected'";?>>Decimal</option>
					<option value="booleano" <?if($_GET['varType']=="booleano") echo"selected='selected'";?>>Booleano</option>
				</select>
			</div>
			<!--
			<div>
				Es Arreglo?
				<input type="checkbox" name="isArray" onChange="toggleDivs('addvar-initial','addvar-array');window.parent.frames['code'].setArr('<?=$_GET['type']."-".$_GET['id']?>', this.checked);" <?if ($_GET['array']=="yes") echo "checked=\"checked\"";?>/>
			</div>
			<div id="addvar-initial" <?if ($_GET['array']=="yes") echo "class=\"hidden\"";?>>
				Valor Inicial:
				<input type="text" name="value" size="17" value="<?=$_GET['initValue']?>" onKeyUp="window.parent.frames['code'].modifyAttr('<?=$_GET['type']."-".$_GET['id']?>','initValue',this.value);"/>
			</div>
			<div id="addvar-array" <?if ($_GET['array']!="yes") echo "class=\"hidden\"";?>>
				Tama&ntilde;o de Arreglo:
				<input type="text" name="arraySize" size="2" value="<?=$_GET['arraySize']?>" onKeyUp="window.parent.frames['code'].modifyAttr('<?=$_GET['type']."-".$_GET['id']?>','arraySize',this.value);"/>
			</div>
			-->
		</div>
	</body>
</html>
