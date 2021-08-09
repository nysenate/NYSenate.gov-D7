/**
 * @file
 * Provides Photobox integration for Image and Media fields.
 */

(function ($, Drupal) {

  "use strict";

  Drupal.slick = Drupal.slick || {};

  Drupal.behaviors.slickPhotobox = {
    attach: function (context) {
      $(".slick--photobox", context).once("slick-photobox", function () {
        $(this).photobox(".slick__photobox", {thumb: '> [data-thumb]', thumbAttr: "data-thumb"}, Drupal.slick.photobox);
      });
    }
  };

  /**
   * Callback for custom captions.
   */
  Drupal.slick.photobox = function () {
    var $caption = $(this).next(".litebox-caption");

    if ($caption.length) {
      $("#pbCaption .title").html($caption.html());
    }
  };

}(jQuery, Drupal));
