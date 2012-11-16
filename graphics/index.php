<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Tansitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html>
	<head>
		<title>Sofi BETA</title>
		<link rel="stylesheet" href="main.css" type="text/css"/>
		<style>
			html {
				background-color: #007d34;
			}
			
			body {
				color: #111;
				background-color: #69cdf0;
				background-image: url('images/background.jpg');
				background-position: bottom center;
				background-repeat: no-repeat;
				background-size: 100%;
			}
		</style>
		<script src="main.js"></script>
		<script src="jquery.js"></script>
	</head>
	<body>
		<header>
			<? include("_header.php"); ?>
		</header>
		<nav>
			<? include("_nav.php"); ?>
		</nav>
		<div id="main">
			<div id="content">
				<iframe id="code" src="code.php"></iframe>
			</div>
			<div id="side">
				<iframe id="tools"></iframe>
			</div>
		</div>
		<div class="clear"></div>
		<footer>
			ITESM - Proyecto para la clase de Compiladores<br/>
			Desarrollado por Victor Nava y Silvia Fosado
		</footer>
	</body>
</html>