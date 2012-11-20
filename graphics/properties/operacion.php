<?php
	$_GET['op'] = str_replace("DOUBLECOMS","&#034;",$_GET['op']);
	$_GET['op'] = str_replace("SINGLECOMS","&#039;",$_GET['op']);
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
		<h2>Operaci&oacute;n</h2>
		<h3 onClick="showMenu('div#attributes');">
			Atributos
			<img src="../images/arrow-right.png"/>
		</h3>
		<div id="attributes" class="group">
			Variable: <input type="text" name="var" value="<?=$_GET['var']?>" onKeyUp="window.parent.frames['code'].modifyAttr('<?=$_GET['type']."-".$_GET['id']?>','var',this.value);"/><br/>
			Operaci&oacute;n: <input type="text" name="op" value="<?=$_GET['op']?>" onKeyUp="window.parent.frames['code'].modifyAttr('<?=$_GET['type']."-".$_GET['id']?>','op',this.value);"/>
		</div>
	</body>
</html>
