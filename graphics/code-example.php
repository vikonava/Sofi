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
			
			.nodisplay {
				display: none;
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
			var curId = 30;
		
			function replaceAll(txt, replace, with_this) {
				return txt.replace(new RegExp(replace, 'g'), with_this);
			}
		
			$(function() {
				$("ul").sortable({ revert: true });
				$("li a").live("click", function() {
					$("li.current").removeClass("current");
					$(this).parent().addClass("current");
					parent.getProperties($(this).parent().data("type"),$(this).parent().attr('data-attributes'));
				});
			});
			
			function modifyAttr(element, attr, value) {
				jsonvalue = replaceAll(value, "\"", "DOUBLECOMS");
				jsonvalue = replaceAll(jsonvalue, "'", "SINGLECOMS");
				var obj = jQuery.parseJSON($("li#"+element).attr("data-attributes"));
				obj[attr] = jsonvalue;
				$("li#"+element).attr("data-attributes",JSON.stringify(obj));
				$("li#"+element+" span#"+attr).first().html(value);
			}
			
			function setArr(element, val) {
				var obj = jQuery.parseJSON($("li#"+element).attr("data-attributes"));
				var tempVal = obj["initValue"];
				tempVal = replaceAll(tempVal,"DOUBLECOMS","\"");
				tempVal = replaceAll(tempVal,"SINGLECOMS","'");
				if (val) {
					$("li#"+element+" span#array").html("[<span id=\"arraySize\">"+obj['arraySize']+"</span>]");
					obj["array"] = "yes";
				} else {
					$("li#"+element+" span#array").html(" = <span id=\"initValue\">"+tempVal+"</span>");
					obj["array"] = "no";
				}
				$("li#"+element).attr("data-attributes",JSON.stringify(obj));
			}
			
			function createVar(element,info) {
				var obj = jQuery.parseJSON(info);
				value = "";
				obj["id"] = curId;
				curId++;
				if (obj['array'] == "no") {
					var tempVal = obj["initValue"];
					tempVal = replaceAll(tempVal,"DOUBLECOMS","\"");
					tempVal = replaceAll(tempVal,"SINGLECOMS","'");
					value = " = <span id=\"initValue\">"+obj['initValue']+"</span>";
				} else {
					value = "[<span id=\"arraySize\">"+obj['arraySize']+"</span>]";
				}
				$("<li id=\"var-"+obj['id']+"\" data-type=\"var\" data-attributes='{\"id\":\""+obj['id']+"\",\"type\":\"var\",\"name\":\""+obj['var']+"\",\"varType\":\""+obj['varType']+"\",\"array\":\""+obj['array']+"\",\"arraySize\":\""+obj['arraySize']+"\",\"initValue\":\""+obj['initValue']+"\"}'><a>VAR <span id=\"varType\">"+obj['varType']+"</span> <span id=\"name\">"+obj['name']+"</span><span id=\"array\">"+value+"</span>;</a></li>").appendTo("li#"+element+" ul:first");
			}
			
			function createOp(element, info, innercode) {
				var obj = jQuery.parseJSON(info);
				obj["id"] = curId;
				curId++;
				console.log(element);
				$('<li id="'+obj["type"]+'-'+obj["id"]+'" data-type="'+obj["type"]+'" data-attributes=\''+JSON.stringify(obj)+'\'><a>'+innercode+'</a></li>').appendTo(element);
			}
		</script>
	</head>
	<body>
		<ul class="code">
			<li id="programa-1" data-type="programa" data-attributes='{"id":"1","type":"programa","name":"viko"}'>
				<a>PROGRAMA <span id="name">viko</span>;</a>
				<ul id="programa-1-vars">
					<li id="var-2" data-type="var" data-attributes='{"id":"2","type":"var","name":"nombre","varType":"texto","array":"no","arraySize":"1","initValue":"DOUBLECOMSvikoDOUBLECOMS"}'>
						<a>VAR <span id="varType">texto</span> <span id="name">nombre</span><span id="array"> = <span id="initValue">"viko"</span></span>;</a>
					</li>
				</ul>
				<a>REALIZA</a>
				<ul id="programa-1-ops">
					<li id="para-11" data-type="para" data-attributes='{"id":"11","type":"para","varControl":"i","assign":"0","comparation":"MENOR","compareVal":"10","incr":"i + 1"}'>
						<a>PARA (<span id="varControl1">i</span> = <span id="assign">0</span>; <span id="varControl2">i</span> <span id="comparation">MENOR</span> <span id="compareVal">10</span>; <span id="varControl3">i</span> = <span id="incr">i + 1</span>;) REALIZA</a>
						<ul id="para-realiza">
							<li id="operacion-10" data-type="operacion" data-attributes='{"id":"10","type":"operacion","var":"nombre","op":"DOUBLECOMSvikoDOUBLECOMS"}'><a><span id="var">nombre</span> = <span id="op">"viko"</span>;</a></li>
						</ul>
						<a>FIN</a>
					</li>
					<li id="mientras-8" data-type="mientras" data-attributes='{"id":"8","type":"mientras","expr":"nombre IGUAL DOUBLECOMSvikoDOUBLECOMS"}'>
						<a>MIENTRAS (<span id="expr">nombre IGUAL "viko"</span>) REALIZA</a>
						<ul id="mientras-realiza">
							<li id="operacion-9" data-type="operacion" data-attributes='{"id":"9","type":"operacion","var":"nombre","op":"DOUBLECOMSvikoDOUBLECOMS"}'><a><span id="var">nombre</span> = <span id="op">"viko"</span>;</a></li>
						</ul>
						<a>FIN</a>
					</li>
					<li id="operacion-6" data-type="operacion" data-attributes='{"id":"6","type":"operacion","var":"nombre","op":"DOUBLECOMSvikoDOUBLECOMS"}'><a><span id="var">nombre</span> = <span id="op">"viko"</span>;</a></li>
					<li id="lee-3" data-type="lee" data-attributes='{"id":"3","type":"lee","var":"nombre"}'><a>LEE <span id="var">nombre;</span></a></li>
					<li id="si-7" data-type="si" data-attributes='{"id":"7","type":"si","comp1":"nombre","comp2":"DOUBLECOMSvikoDOUBLECOMS","comparator":"IGUAL"}'>
						<a>SI (<span id="comp1">nombre</span> <span id="comparator">IGUAL</span> <span id="comp2">"viko"</span>) REALIZA</a>
						<ul id="si-true">
							<li id="imprime-4" data-type="imprime" data-attributes='{"id":"4","type":"imprime","contents":"DOUBLECOMSBienvenido Viko!DOUBLECOMS"}'><a>IMPRIME(<span id="contents">"Bienvenido Viko!"</span>);</a></li>
						</ul>
						<a>SINO</a>
						<ul id="si-false">
							<li id="imprime-5" data-type="imprime" data-attributes='{"id":"5","type":"imprime","contents":"DOUBLECOMSIntenta de nuevo!!!DOUBLECOMS"}'><a>IMPRIME("Intenta de nuevo!!!");</a></li>
						</ul>
						<a>FIN</a>
					</li>
				</ul>
				<a>FIN</a>
			</li>
		</ul>
	</body>
</html>