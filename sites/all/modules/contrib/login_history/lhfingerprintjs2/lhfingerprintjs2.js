(function ($, Drupal, window, document, undefined) {
    'use strict';

    Drupal.behaviors.lhFingerprintjs2DeviceId = {
        attach: function (context, settings) {
            new Fingerprint2().get(function (result, components) {
                $('input[name="lhfingerprintjs"]').val(JSON.stringify(components));
            });
        }
    };
})(jQuery, Drupal, this, this.document);
