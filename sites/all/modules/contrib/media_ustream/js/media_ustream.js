(function ($) {

Drupal.behaviors.player_color = {
  attach: function (context) {
    $('#edit-displays-media-ustream-video-settings').change(function () {
      if ($('#edit-displays-media-ustream-video-settings-player-color-colorpicker').attr('checked') == false) {
        if ($('#edit-displays-media-ustream-video-settings-custom-color').val() != false) {
          $('#edit-displays-media-ustream-video-settings-custom-color').attr('value', "");
          $('#edit-displays-media-ustream-video-settings-custom-color').css('background-color', '#fff');
        }
      }
    });
  }
};

Drupal.behaviors.custom_color = {
  attach: function (context) {
    var video_settings = '#edit-displays-media-ustream-video-settings';

    var form = $(video_settings, context);
    if (form.length == 0) {
      return;
    }

    var custom_color = 'edit-displays-media-ustream-video-settings-custom-color';
    var field = '#edit-displays-media-ustream-video-settings-player-color-colorpicker';

    var inputs = [];
    var focused = null;

    // Add Farbtastic.
    $('#placeholder').addClass('color-processed');
    var farb = $.farbtastic('#placeholder');

    // Show or hide the placeholder onchange.
    $(video_settings).change(function () {
      // But only if a placeholder exists.
      if ($('#placeholder').length != 0) {
        if ($(field).attr('checked')) {
          $('#placeholder').show();
        }
        if ($(field).attr('checked') == false) {
          $('#placeholder').hide();
          return;
        }
      }
    });

    // Hide the placeholder by default, but render it
    // if the custom color option is checked.
    if ($('#placeholder').length != 0 && $(field).attr('checked') == false) {
      $('#placeholder').hide();
    }

    /**
     * Callback for Farbtastic when a new color is chosen.
     */
    function callback(input, color) {
      $(input).val(color);
      // Set background/foreground colors.
      $(input).css({
        backgroundColor: color,
        'color': farb.RGBToHSL(farb.unpack(color))[2] > 0.5 ? '#000' : '#fff'
      });
    }

    /**
     * Resets the color selector.
     */
    function resetField() {
      $(custom_color).each(function () {
        this.selectedIndex = this.options.length - 1;
      });
    }

    /**
     * Focuses Farbtastic on a particular field.
     */
    function focus() {
      var input = this;
      // Remove old bindings.
      focused && $(focused).unbind('keyup', farb.updateValue)
          .parent().removeClass('item-selected');

      // Add new bindings.
      focused = this;
      farb.linkTo(function (color) { callback(input, color); });
      farb.setColor(this.value);
      $(focused).keyup(farb.updateValue).keyup(resetField)
        .parent().addClass('item-selected');
    }

    // Initialize color field.
    $('#' + custom_color, form)
    .each(function () {
      this.key = '#' + custom_color;

      // Link to color picker temporarily to initialize.
      farb.linkTo(function () {}).setColor('#ff3d23').linkTo(this);
      inputs.push(this);
    })
    .focus(focus);

    $('#' + custom_color, form);

    // Focus first color.
    focus.call(inputs[0]);
  }
};

})(jQuery);
