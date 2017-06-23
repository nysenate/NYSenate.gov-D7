/**
 * @file
 * Provides Colorbox integration for Image and Media fields.
 */

(function ($, Drupal, window) {

  "use strict";

  Drupal.slickColorbox = Drupal.slickColorbox || {};
  var $window = $(window),
    cboxResizeTimer;

  Drupal.behaviors.slickColorbox = {
    attach: function (context, settings) {
      if (!$.isFunction($.colorbox)) {
        return;
      }

      // Disable Colorbox for small screens, if so configured.
      if (settings.colorbox.mobiledetect && window.matchMedia) {
        var c = settings.colorbox.mobiledevicewidth,
          mq = window.matchMedia("(max-device-width: " + c + ")");
        if (mq.matches) {
          return;
        }
      }

      // Including slick-cloned.
      $(".slick__colorbox", context).once("slick-colorbox", function () {
        var t = $(this),
          id = t.closest(".slick").attr("id"),
          $body = $("body"),
          media = t.data("media") || {},
          $slider = t.closest(".slick__slider", "#" + id + ".slick"),
          isSlick = $slider.length,
          isMedia = media.type !== "image" ? true : false,
          curr,
          runtimeOptions = {
            iframe: isMedia,
            rel: media.rel || null,
            onOpen: function () {
              $body.addClass("colorbox-on colorbox-on--" + media.type);
              $body.data("mediaHeight", "");
              $body.data("mediaWidth", "");
              if (isSlick) {
                $slider.slick("slickPause");
              }
            },
            onLoad: function () {
              Drupal.slickColorbox.removeClasses();

              // Rebuild media data based on the current active box.
              if (isMedia) {
                $body.data("mediaHeight", media.height);
                $body.data("mediaWidth", media.width);
                $body.addClass("colorbox-on--media");
              } else {
                $body.removeClass("colorbox-on--media");
              }

              $body.addClass("colorbox-on colorbox-on--" + media.type);

              // Remove these lines to disable slider scrolling under colorbox.
              if (isSlick) {
                curr = parseInt(t.closest(".slick__slide:not(.slick-cloned)")
                  .data("slickIndex"));
                if ($slider.parent().next(".slick").length) {
                  var $thumb = $slider.parent().next(".slick")
                    .find(".slick__slider");
                  $thumb.slick("slickGoTo", curr);
                }
                $slider.slick("slickGoTo", curr);
              }
            },
            onCleanup: function () {
              Drupal.slickColorbox.removeClasses();
            },
            onComplete: function () {
              if (media.type !== "image") {
                Drupal.slickColorbox.resize(context, Drupal.settings);
              }
              // Overrides colorbox_style.js when Plain style enabled.
              $('#cboxPrevious, #cboxNext', context).removeClass('element-invisible');
            },
            onClosed: function () {
              // 120 offset is to play safe for possible fixed header.
              Drupal.slickColorbox.jumpScroll("#" + id, 120);
              Drupal.slickColorbox.removeClasses();
              $body.data("mediaHeight", "");
              $body.data("mediaWidth", "");
            }
          };

        t.colorbox($.extend({}, settings.colorbox, runtimeOptions));
      });

      $window.bind("resize", function () {
        Drupal.slickColorbox.resize(context, Drupal.settings);
      });

      $(context).bind("cbox_complete", function () {
        Drupal.attachBehaviors("#cboxLoadedContent");
      });
    }
  };

  Drupal.slickColorbox.removeClasses = function () {
    $("body").removeClass(function (index, css) {
      return (css.match(/(^|\s)colorbox-\S+/g) || []).join(' ');
    });
  };

  Drupal.slickColorbox.jumpScroll = function (id, o) {
    if ($(id).length) {
      $("html, body").stop().animate({
        scrollTop: $(id).offset().top - o
      }, 800);
    }
  };

  // Colorbox has no responsive support so far, drop them all when it does.
  Drupal.slickColorbox.resize = function (context, settings) {
    if (cboxResizeTimer) {
      clearTimeout(cboxResizeTimer);
    }

    var mw = $('body').data("mediaWidth") || settings.colorbox.maxWidth,
      mh = $('body').data("mediaHeight") || settings.colorbox.maxHeight,
      o = {
        width: settings.colorbox.maxWidth || "98%",
        height: settings.colorbox.maxHeight || "98%",
        maxWidth: mw.indexOf("px") > 0 ? parseInt(mw) : mw,
        maxHeight: mh.indexOf("px") > 0 ? parseInt(mh) : mh
      };

    cboxResizeTimer = setTimeout(function () {
      if ($("#cboxOverlay").is(":visible")) {
        var $container = $("#cboxLoadedContent");

        if ($(".cboxIframe").length) {
          $container.addClass("media");
          $(".cboxIframe", $container).attr("width", o.maxWidth).attr("height", o.maxHeight);
        } else {
          $container.removeClass("media");
        }

        $.colorbox.resize({
          innerWidth: o.maxWidth,
          innerHeight: o.maxHeight
        });
      }
    }, 0);
  };

}(jQuery, Drupal, this));
