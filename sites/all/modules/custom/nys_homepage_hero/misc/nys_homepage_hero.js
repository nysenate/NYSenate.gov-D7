(function ($) {
  Drupal.behaviors.reloadHomepageHero = {
    attach: function(context, settings) {
      var active = settings.nys_homepage_hero.session_active;
      var interval = settings.nys_homepage_hero.poll_int;
      var intervalID = window.setInterval(compareCallback, interval);

      function compareCallback() {
          var request = new XMLHttpRequest();
          request.open('GET', '/ajax/homepage_hero.json', true);
          request.onload = function () {
              // Begin accessing JSON data here
              var session_in_progress = JSON.parse(this.response);
              // When a session is started or ended reload the page to add
              // or remove the video stream embed respectively.
              if (active ^ session_in_progress) {
                  window.location.reload(true);
              }
          }

          request.send();
      }
    }
  }
}) (jQuery);
