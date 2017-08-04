/**
 *  @file
 *  Refresh the thumbnail if configured.
 *  TODO: finish this up and/or ax it and implement cron.
 * (it's now just an idea)
 */

(function ($) {

Drupal.behaviors.MediaLivestreamLiveThumbnail = {
  attach: function (context) {

    function updateThumb() {
      thumbnail = document.getElementById('thumbnail');
      thumbnail.src = "http://thumbnail.api.livestream.com/thumbnail?name=" + Drupal.MediaLivestreamLiveThumbnail.channel + "&t=" + new Date().valueOf();
    }
    setInterval("updateThumb()", Drupal.MediaLivestreamLiveThumbnail.timeout);
  }
};

})(jQuery);

