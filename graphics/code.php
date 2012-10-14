<html>
	<head>
		<link rel="stylesheet" href="main.css" type="text/css"/>
		<style>
			html, body {
				background: none;
			}
			
			body { 
				padding: 5px;
			}
		</style>
		<!--[if gte IE 9]>
			<style type="text/css">
				.gradient {
					filter: none;
				}
			</style>
		<![endif]-->
		<script src="jquery.js"></script>
		<script src="jquery-ui.js"></script>
		<script>
			$(function() {
				$("ul").sortable({ revert: true });
				$("li a").click(function() {
					$("li.current").removeClass("current");
					$(this).parent().addClass("current");
					parent.getProperties($(this).parent().data("type"),$(this).parent().attr('data-attributes'));
				});
			});
		</script>
	</head>
	<body>
		<ul class="code">
			<li data-type="programa" data-attributes='{"name":"viko"}'>
				<a>PROGRAMA viko;</a>
				<ul>
					<li><a>VAR texto nombre;</a></li>
				</ul>
				<a>REALIZA</a>
				<ul>
					<li><a>LEE nombre;</a></li>
					<li>
						<a>SI (nombre IGUAL "viko") REALIZA</a>
						<ul>
							<li><a>IMPRIME("Bienvenido viko!");</a></li>
						</ul>
						<a>SINO</a>
						<ul>
							<li><a>IMPRIME("Intenta de nuevo!!!");</a></li>
						</ul>
						<a>FIN</a>
					</li>
				</ul>
				<a>FIN</a>
			</li>
		</ul>
	</body>
</html>