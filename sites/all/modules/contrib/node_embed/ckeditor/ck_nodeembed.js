(function ($) {
Drupal.behaviors.node_embed = {
  attach:  function(context) {  
    $('.item-list ul li', context).click(function(){
      $('.active .views-field-nid span.field-content').attr("id", 'inactive-nid');
      $('.item-list ul li', context).removeClass('active'); 
      $(this).addClass('active'); 
      $('.active .views-field-nid span.field-content').attr("id", 'active-nid');
      window.parent.currentActiveNid = $('#active-nid').text();
    });
  }
}
})(jQuery);
