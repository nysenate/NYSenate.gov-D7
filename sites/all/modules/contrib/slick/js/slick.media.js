/**
 * @file
 * Provides Media module integration.
 */

(function ($, Drupal) {

  "use strict";

  Drupal.behaviors.slickMedia = {
    attach: function (context) {

      $(".media--switch--player", context).once("slick-media", function () {
        var t = $(this),
          $slider = t.closest(".slick__slider"),
          $slick = $slider.closest(".slick"),
          iframe = t.find("iframe"),
          newIframe = iframe.clone(),
          media = newIframe.data("media"),
          url = newIframe.data("lazy"),
          $nester = '';

          if ($slick.closest(".slick__slider").length) {
            $nester = $slick.closest(".slick__slider");
          }

        // Remove iframe to avoid browser requesting them till clicked.
        iframe.remove();

        t.on("click.media-play", ".media-icon--play", function () {
          // Soundcloud needs internet, fails on disconnected local.
          if (url === "") {
            return false;
          }
          var auto_play = url.indexOf("auto_play"),
          autoplay = url.indexOf("autoplay"),
          param = url.indexOf("?");

          // Force autoplay, if not provided, which should not.
          if (media.scheme === "soundcloud") {
            if (auto_play < 0 || auto_play === false) {
              url = param < 0 ? url + "?auto_play=true" : url + "&amp;auto_play=true";
            }
          } else if (autoplay < 0 || autoplay === 0) {
            url = param < 0 ? url + "?autoplay=1" : url + "&amp;autoplay=1";
          }

          // First, reset any video to avoid multiple videos from playing.
          t.removeClass("is-playing");

          // Clean up any pause marker at slider container.
          $(".is-paused").removeClass("is-paused");

          // Last, pause the slide, for just in case autoplay is on, and
          // pauseOnHover is disabled, and then trigger autoplay.
          if ($slider.length) {
            $slider.addClass("is-paused").slick("slickPause");
          }

          if ($nester) {
            $nester.addClass("is-paused").slick("slickPause");
          }

          t.addClass("is-playing").append(newIframe);
          newIframe.attr("src", url);

          return false;
        });
        // Closes the video.
        t.on("click.media-close", ".media-icon--close", function () {
          t.removeClass("is-playing").find("iframe").remove();
          $(".is-paused").removeClass("is-paused");
          return false;
        });

        // Turns off any video if any change to the slider.
        $slider.on("afterChange", function () {
          $slider.find(".is-playing .media-icon--close")
            .trigger("click.media-close");
        });

        if ($nester) {
          $nester.on("afterChange", function () {
            $nester.find(".is-playing .media-icon--close")
              .trigger("click.media-close");
          });
        }
      });
    }
  };

})(jQuery, Drupal);
