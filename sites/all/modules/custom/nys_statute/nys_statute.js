Drupal.behaviors.nys_statute = {
  attach: function (context, settings) {

    jQuery( "body.node-type-statute" ).keyup(function( event ) {

      var key_pressed = event.originalEvent.key;
      if (key_pressed == 'ArrowLeft') {
        var left_link = jQuery("body.node-type-statute div.row.c-law-sibling-links a.left-arrow").attr("href");
        if (left_link) {
          window.location = 'http://' + window.location.hostname + left_link;
        }
        else {
          var breadcrumb_last = jQuery( "ol.nys-associated-topics li:last-child a" ).attr("href");
          if (breadcrumb_last) {      
           window.location = 'http://' + window.location.hostname + breadcrumb_last;
          }
        }

      }
      else if (key_pressed == 'ArrowRight') {
        var right_link = jQuery("body.node-type-statute div.row.c-law-sibling-links a.right-arrow").attr("href");
        if (right_link) {
          window.location = 'http://' + window.location.hostname + right_link;
        }
        else {
          var breadcrumb_last = jQuery( "ol.nys-associated-topics li:last-child a" ).attr("href");
          if (breadcrumb_last) {
            window.location = 'http://' + window.location.hostname + breadcrumb_last;
          }
        }

      }
      else if (key_pressed == 'ArrowUp') {
        var breadcrumb_last = jQuery( "ol.nys-associated-topics li:last-child a" ).attr("href");   
        if (breadcrumb_last) {
          window.location = 'http://' + window.location.hostname + breadcrumb_last;
        }
      }

    });

  }
};