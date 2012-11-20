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

function showOpMenu(div, formname) {
	$("form#"+formname+" div.operation").hide();
	$("form#"+formname+" div#"+div).show();
}

function showSpecialOpMenu(div, formname) {
	$("form#"+formname+" div.operation div.specialOp").hide();
	$("form#"+formname+" div#"+div).show();
}

// implement JSON.stringify serialization
JSON.stringify = JSON.stringify || function (obj) {
    var t = typeof (obj);
    if (t != "object" || obj === null) {
        // simple data type
        if (t == "string") obj = '"'+obj+'"';
        return String(obj);
    }
    else {
        // recurse array or object
        var n, v, json = [], arr = (obj && obj.constructor == Array);
        for (n in obj) {
            v = obj[n]; t = typeof(v);
            if (t == "string") v = '"'+v+'"';
            else if (t == "object" && v !== null) v = JSON.stringify(v);
            json.push((arr ? "" : '"' + n + '":') + String(v));
        }
        return (arr ? "[" : "{") + String(json) + (arr ? "]" : "}");
    }
};

function submitForm(action, formid, returnid) {
	$.ajax({type:'POST', url: action, data: $('#'+formid).serialize(), success:
				function(response) {
					$('#'+returnid).html(response);
				}
			});
}

function newProgram() {
	if (confirm("Esta seguro de crear nuevo programa? Su programa actual sera eliminado.")) {
		$('iframe#code').attr('src','code.php');	
	}
}

function downloadCode() {
	$("form#savecode input#progname").val($("iframe#code").contents().find("li#programa-0 span#name").text());
	$("form#savecode input#code").val($("iframe#code").contents().find(".code").text());
	$("form#savecode").submit();
}