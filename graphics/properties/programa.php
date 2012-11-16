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
		<h2>Programa</h2>
		<h3 onClick="showMenu('div#attributes');">
			Atributos
			<img src="../images/arrow-right.png"/>
		</h3>
		<div id="attributes" class="group">
			Nombre: <input type="text" name="name" value="<?=$_GET['name']?>"/>
		</div>
		<h3 onClick="showMenu('form#variables');">
			Crear Variable
			<img src="../images/arrow-right.png"/>
		</h3>
		<form id="variables" class="group hidden">
			<? include("_addVar.php"); ?>
		</form>
		<h3 onClick="showMenu('form#operation');">
			Agregar Operaci&oacute;n
			<img src="../images/arrow-right.png"/>
		</h3>
		<form id="operation" class="group hidden">
			<? include("_addOp.php"); ?>
		</form>
	</body>
</html>
