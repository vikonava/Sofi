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
			var curId = 1;
		
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
				//if (obj['array'] == "no") {
				//	var tempVal = obj["initValue"];
				//	tempVal = replaceAll(tempVal,"DOUBLECOMS","\"");
				//	tempVal = replaceAll(tempVal,"SINGLECOMS","'");
				//	value = " = <span id=\"initValue\">"+obj['initValue']+"</span>";
				//} else {
				//	value = "[<span id=\"arraySize\">"+obj['arraySize']+"</span>]";
				//}
				$("<li id=\"var-"+obj['id']+"\" data-type=\"var\" data-attributes='{\"id\":\""+obj['id']+"\",\"type\":\"var\",\"name\":\""+obj['var']+"\",\"varType\":\""+obj['varType']+"\",\"array\":\""+obj['array']+"\",\"arraySize\":\""+obj['arraySize']+"\",\"initValue\":\""+obj['initValue']+"\"}'><a>VAR <span id=\"varType\">"+obj['varType']+"</span> <span id=\"name\">"+obj['name']+"</span><span id=\"array\">"+value+"</span>;</a></li>").appendTo("li#"+element+" ul:first");
			}
			
			function createOp(element, info, innercode) {
				var obj = jQuery.parseJSON(info);
				obj["id"] = curId;
				curId++;
				$('<li id="'+obj["type"]+'-'+obj["id"]+'" data-type="'+obj["type"]+'" data-attributes=\''+JSON.stringify(obj)+'\'><a>'+innercode+'</a></li>').appendTo(element);
			}
			
			function newFunction() {
				var objId = curId;
				curId++;
				$("ul.code").prepend("<li id=\"function-"+objId+"\" data-type=\"function\" data-attributes='{\"id\":\""+objId+"\",\"type\":\"function\",\"name\":\"nombreFuncion"+objId+"\",\"returnType\":\"numero\",\"params\":\"\"}'><a>FUNC <span id=\"returnType\">numero</span> <span id=\"name\">nombreFuncion"+objId+"</span>(<span id=\"params\"></span>)</a><ul id=\"function-"+objId+"-vars\"></ul><a>REALIZA </a><ul id=\"function-"+objId+"-ops\"><li id=\"regresa-"+objId+"\" data-type=\"regresa\" data-attributes='{\"id\":\""+objId+"\",\"type\":\"regresa\",\"ret\":\"\"}'><a>REGRESA(<span id=\"ret\"></span>);</a></li></ul><a>FIN </a></li>");
				$("ul").sortable({ revert: true });
			}
		</script>
	</head>
	<body>
		<ul class="code">
			<li id="programa-0" data-type="programa" data-attributes='{"id":"0","type":"programa","name":"miprograma"}'>
				<a>PROGRAMA <span id="name">miprograma</span>;</a>
				<ul id="programa-0-vars">
				</ul>
				<a>REALIZA</a>
				<ul id="programa-0-ops">
				</ul>
				<a>FIN</a>
			</li>
		</ul>
	</body>
</html>