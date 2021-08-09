
function select_subscriptions(fieldSetId) {
  var all_subscribe_checkbox = document.getElementById("all-" + fieldSetId).checked;
  var hostDiv = document.getElementById(fieldSetId);
  var theElements = hostDiv.getElementsByClassName("form-checkbox");
  for (var i = 0, len = theElements.length; i < len; i++) {
    theElements[i].checked = all_subscribe_checkbox;
  }
}


/*
// A $( document ).ready() block.
jQuery( document ).ready(function() {
    alert( "ready!" );
});
*/
