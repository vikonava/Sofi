function getProperties(propertyType, attributes) {
	$("iframe#tools").attr("src","properties/"+propertyType+".php?"+$.param(jQuery.parseJSON(attributes)));
}

function showMenu(id) {
	$(id).slideToggle('slow');
}

function toggleDivs(first, second) {
	$("div#"+first).toggle();
	$("div#"+second).toggle();
}

function showOpMenu(div) {
	$("form#operation div.operation").hide();
	$("form#operation div#"+div).show();
}

function showSpecialOpMenu(div) {
	$("form#operation div.operation div.specialOp").hide();
	$("form#operation div#"+div).show();
}