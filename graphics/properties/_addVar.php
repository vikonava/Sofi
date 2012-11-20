<input type="hidden" name="type" value="var"/>
<input type="hidden" name="parent" value="<?=$_GET['type']."-".$_GET['id']?>"/>
<div>
	Nombre:
	<input type="text" name="name"/>
</div>
<div>
	Tipo:
	<select name="varType">
		<option value="caracter">Caracter</option>
		<option value="texto">Texto</option>
		<option value="numero">N&uacute;mero</option>
		<option value="decimal">Decimal</option>
		<option value="booleano">Booleano</option>
	</select>
</div>
<!--
<div>
	Es Arreglo?
	<input type="checkbox" name="isArray" onChange="toggleDivs('addvar-initial','addvar-array');"/>
</div>
<div id="addvar-initial">
	Valor Inicial:
	<input type="text" name="initValue"/>
</div>
<div id="addvar-array" class="hidden">
	Tama&ntilde;o de Arreglo:
	<input type="text" name="arraySize" size="2" value="1"/>
</div>
-->
<p align="center">
	<a class="btn btn-primary" onClick="submitForm('_createVar.php','variables','script');">Crear Variable</a>
</p>