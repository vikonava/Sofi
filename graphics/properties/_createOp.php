<?php
	function stripAccents($stripAccents){ 
		$search = explode(",","ç,æ,œ,á,é,í,ó,ú,à,è,ì,ò,ù,ä,ë,ï,ö,ü,ÿ,â,ê,î,ô,û,å,e,i,ø,u");
		$replace = explode(",","c,ae,oe,a,e,i,o,u,a,e,i,o,u,a,e,i,o,u,y,a,e,i,o,u,a,e,i,o,u");
		return str_replace($search, $replace, $stripAccents);
	}

	switch($_POST['opType']) {
	// OPERACIONES BASICAS
		case "basica":
			switch(stripAccents($_POST['operationBasic'])) {
				case "Lectura":
					$jsonString = "{\"type\":\"lee\",\"var\":\"variable\"}";
					$innerCode = "LEE(<span id=\"var\">variable</span>); ";
					break;
				case "Escritura":
					$jsonString = "{\"type\":\"imprime\",\"contents\":\"DOUBLECOMStextoDOUBLECOMS\"}";
					$innerCode = "IMPRIME(<span id=\"contents\">\"texto\"</span>); ";
					break;
				case "Operacion":
					$jsonString = "{\"type\":\"operacion\",\"var\":\"variable1\",\"op\":\"variable2 + variable3\"}";
					$innerCode = "<span id=\"var\">variable1</span> = <span id=\"op\">variable2 + variable3</span>; ";
					break;
				case "Decision":
					$jsonString = "{\"type\":\"si\",\"comp1\":\"variable1\",\"comp2\":\"variable2\",\"comparator\":\"IGUAL\"}";
					$innerCode = "SI (<span id=\"comp1\">variable1</span> <span id=\"comparator\">IGUAL</span> <span id=\"comp2\">variable2</span>) REALIZA </a><ul id=\"si-true\"></ul><a>SINO </a><ul id=\"si-false\"></ul><a>FIN ";
					break;
			}
			break;
	// OPERCIONES CICLOS
		case "ciclos":
			switch(stripAccents($_POST['operationCycle'])) {
				case "Mientras":
					$jsonString = "{\"type\":\"mientras\",\"expr\":\"expresion\"}";
					$innerCode = "MIENTRAS (<span id=\"expr\">expresion</span>) REALIZA </a><ul id=\"mientras-realiza\"></ul><a>FIN ";
					break;
				case "Para":
					$jsonString = "{\"type\":\"para\",\"varControl\":\"i\",\"assign\":\"0\",\"comparation\":\"MENOR\",\"compareVal\":\"10\",\"incr\":\"i + 1\"}";
					$innerCode = "PARA (<span id=\"varControl1\">i</span> = <span id=\"assign\">0</span>; <span id=\"varControl2\">i</span> <span id=\"comparation\">MENOR</span> <span id=\"compareVal\">10</span>; <span id=\"varControl3\">i</span> = <span id=\"incr\">i + 1</span>;) REALIZA </a><ul id=\"para-realiza\"></ul><a>FIN ";
					break;
			}
			break;
	// OPERACIONES ESPECIALES
		case "especial":
			switch(stripAccents($_POST['varType'])) {
			// CARACTER
				case "caracter":
					switch($_POST['operationSpecialChar']) {
						case "obtenerCodigoAscii()":
							$jsonString = "{\"type\":\"obtenercodigoascii\",\"var\":\"variable\"}";
							$innerCode = "obtenerCodigoAscii(<span id=\"var\">variable</span>);";
							break;
					}
					break;
			// CARACTER
				case "texto":
					switch($_POST['operationSpecialText']) {
						case "tamaño()":
							$jsonString = "{\"type\":\"tamano\",\"var\":\"variable\"}";
							$innerCode = "tamaño(<span id=\"var\">variable</span>);";
							break;
					}
					break;
			// CARACTER
				case "numero":
					break;
			// CARACTER
				case "decimal":
					break;
			// CARACTER
				case "arreglo":
					break;
			}
			break;
	}
?>
<script>
	window.parent.frames['code'].createOp('<?=$_POST['parent']?>','<?=$jsonString?>','<?=$innerCode?>');
</script>