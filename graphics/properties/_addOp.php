<?
	if (!$_GET['o']) $_GET['o'] = "operation";
?>
<input type="hidden" name="parent" value="<?=$_GET['whosParent']?>"/>
<div>
	Tipo:
	<select name="opType" onChange="showOpMenu(this.value,'<?=$_GET['o']?>');">
		<option value="basica">Funci&oacute;n B&aacute;sica</option>
		<option value="ciclos">Ciclos</option>
<!--		<option value="especial">Funci&oacute;n Especial</option> -->
	</select>
</div>
<div id="basica" class="operation">
	Operaci&oacute;n:
	<select name="operationBasic">
		<option>Lectura</option>
		<option>Escritura</option>
		<option>Operaci&oacute;n</option>
		<option>Decisi&oacute;n</option>
	</select>
</div>
<div id="ciclos" class="hidden operation">
	Operaci&oacute;n:
	<select name="operationCycle">
		<option>Mientras</option>
		<option>Para</option>
	</select>
</div>
<!--
<div id="especial" class="hidden operation">
	Tipo de Variable:
	<select name="varType" onChange="showSpecialOpMenu(this.value,'<?=$_GET['o']?>')">
		<option value="caracter">Caracter</option>
		<option value="texto">Texto</option>
		<option value="numero">N&uacute;mero</option>
		<option value="decimal">Decimal</option>
		<option value="arreglo">Arreglo</option>
	</select>
	<div class="specialOp" id="caracter">
		Operaci&oacute;n:
		<select name="operationSpecialChar">
			<option>obtenerCodigoAscii()</option>
		</select>
	</div>
	<div class="hidden specialOp" id="texto">
		Operaci&oacute;n:
		<select name="operationSpecialText">
			<option>tama&ntilde;o()</option>
			<option>caracterEn()</option>
			<option>indiceDeCaracter()</option>
		</select>
	</div>
	<div class="hidden specialOp" id="numero">
		Operaci&oacute;n:
		<select name="operationSpecialInt">
			<option>obtenerCaracter()</option>
			<option>potencia()</option>
		</select>
	</div>
	<div class="hidden specialOp" id="decimal">
		Operaci&oacute;n:
		<select name="operationSpecialFloat">
			<option>redondear()</option>
			<option>truncar()</option>
		</select>
	</div>
	<div class="hidden specialOp" id="arreglo">
		Operaci&oacute;n:
		<select name="operationSpecialArray">
			<option>contar()</option>
			<option>maximo()</option>
			<option>minimo()</option>
		</select>
	</div>
</div>
-->
<p align="center">
	<a class="btn btn-primary" onClick="submitForm('_createOp.php','<?=$_GET['o']?>','script');">Crear Operaci&oacute;n</a>
</p>