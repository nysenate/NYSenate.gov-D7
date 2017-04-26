/**
 * @file
 * Password Policy JavaScript functionality.
 */

(function ($) {

/**
 * Overrides the standard password strength check.
 */
Drupal.behaviors.passwordOverride = {
  attach: function (context, settings) {
    // Set a default for our pw_status.
    pw_status = {
      strength: 0,
      message: '',
      indicatorText: ''
    }

    // We take over the keyup function on password and instead make a call to
    // the server to evaluate the password. When we get the status back we
    // update it.  Then we call focus to all the normal drupal password update.
    $('input.password-field', context).once('passwordOverride', function () {
      passwordInput = $(this);
      passwordCheck = function (e, isCallback) {
        if (typeof isCallback != 'undefined') {
          return;
        }
        cleanUrlPrefix = Drupal.settings.passwordPolicy.cleanUrl ? '' : '?q=';

        // Set parameters for password check.
        var data = { password: encodeURIComponent(passwordInput.val()) };
        // Set username value as parameter if it is present.
        var usernameInput = $('input.username');
        var username = usernameInput.val();
        if (username) {
          data.name = encodeURIComponent(username);
        }

        $.post(
          Drupal.settings.basePath + cleanUrlPrefix + Drupal.settings.pathPrefix + 'password_policy/check',
          data,
          function(data) {
            pw_status = data;
            // Trigger the event again to force the text to be updated, but
            // pass a dummy parameter to the event handler to avoid an
            // infinite loop.
            passwordInput.triggerHandler('keyup', [ true ]);
          }
        );
      };
      passwordInput.keyup(passwordCheck).focusin(passwordCheck);
    });

    // We are overriding the normal evaluatePasswordStrength and instead are
    // just returning the current status.
    Drupal.evaluatePasswordStrength = function (password, translate) {
      return pw_status;
    };
  }
};

// We are overriding the normal evaluatePasswordStrength and instead are
// just returning the current status.
Drupal.evaluatePasswordStrength = function (password, translate) {
  return Drupal.settings.pw_status;
};

/**
 * Provide the summary information for the constraint settings vertical tabs.
 */
Drupal.behaviors.passwordPolicyConstraintSettingsSummary = {
  attach: function (context) {
    $('fieldset#edit-alpha-case-fieldset', context).drupalSetSummary(function (context) {
      alpha_case = $('input[name="alpha_case"]', context).is(':checked');
      if (alpha_case) {
        return Drupal.t('Upper and lower case letters required');
      }
      else {
        return Drupal.t('Not enforced');
      }
    });

    $('fieldset#edit-alpha-count-fieldset', context).drupalSetSummary(function (context) {
      alpha_count = $('input[name="alpha_count"]', context).val();
      if (alpha_count) {
        return Drupal.t('At least @count letters', {'@count': alpha_count});
      }
      else {
        return Drupal.t('Not enforced');
      }
    });

    $('fieldset#edit-delay-fieldset', context).drupalSetSummary(function (context) {
      delay = $('input[name="delay"]', context).val();
      if (delay) {
        return Drupal.t('@delay between changes', {'@delay': delay});
      }
      else {
        return Drupal.t('Not enforced');
      }
    });

    $('fieldset#edit-blacklist-fieldset', context).drupalSetSummary(function (context) {
      blacklist = $('textarea[name="blacklist"]', context).val();
      if (blacklist) {
        blacklist_match_substrings = $('input[name="blacklist_match_substrings"]', context).is(':checked');
        if (blacklist_match_substrings) {
          return Drupal.t('Must not contain certain strings');
        }
        else {
          return Drupal.t('Certain strings disallowed');
        }
      }
      else {
        return Drupal.t('Not enforced');
      }
    });

    $('fieldset#edit-char-count-fieldset', context).drupalSetSummary(function (context) {
      char_count = $('input[name="char_count"]', context).val();
      if (char_count) {
        return Drupal.t('At least @count characters', {'@count': char_count});
      }
      else {
        return Drupal.t('Not enforced');
      }
    });

    $('fieldset#edit-consecutive-char-count-fieldset', context).drupalSetSummary(function (context) {
      consecutive_char_count = $('input[name="consecutive_char_count"]', context).val();
      if (consecutive_char_count) {
        return Drupal.t('Fewer than @count identical consecutive characters', {'@count': consecutive_char_count});
      }
      else {
        return Drupal.t('Not enforced');
      }
    });

    $('fieldset#edit-drupal-strength-fieldset', context).drupalSetSummary(function (context) {
      drupal_strength = $('input[name="drupal_strength"]', context).val();
      if (drupal_strength) {
        return Drupal.t('At least level of @level Drupal strength', {'@level': drupal_strength});
      }
      else {
        return Drupal.t('Not enforced');
      }
    });

    $('fieldset#edit-int-count-fieldset', context).drupalSetSummary(function (context) {
      int_count = $('input[name="int_count"]', context).val();
      if (int_count) {
        return Drupal.t('At least @count integers', {'@count': int_count});
      }
      else {
        return Drupal.t('Not enforced');
      }
    });

    $('fieldset#edit-past-passwords-fieldset', context).drupalSetSummary(function (context) {
      past_passwords = $('input[name="past_passwords"]', context).val();
      if (past_passwords) {
        return Drupal.t('Must not match previous @count passwords', {'@count': past_passwords});
      }
      else {
        return Drupal.t('Not enforced');
      }
    });

    $('fieldset#edit-symbol-count-fieldset', context).drupalSetSummary(function (context) {
      symbol_count = $('input[name="symbol_count"]', context).val();
      if (symbol_count) {
        return Drupal.t('At least @count symbols', {'@count': symbol_count}) + '<br/>' + Drupal.t('Symbol characters: @symbols', {'@symbols': $('input[name="symbol_count_symbols"]', context).val()});
      }
      else {
        return Drupal.t('Not enforced');
      }
    });

    $('fieldset#edit-username-fieldset', context).drupalSetSummary(function (context) {
      username = $('input[name="username"]', context).is(':checked');
      if (username) {
        return Drupal.t('Must not contain their username');
      }
      else {
        return Drupal.t('Not enforced');
      }
    });
  }
};

/**
 * Provide the summary information for the condition settings vertical tabs.
 */
Drupal.behaviors.passwordPolicyConditionSettingsSummary = {
  attach: function (context) {
    $('fieldset#edit-role-fieldset', context).drupalSetSummary(function (context) {
      var vals = [];
      $('input[type="checkbox"]:checked', context).each(function() {
        vals.push($.trim($(this).next('label').text()));
      });
      if (!vals.length) {
        vals.push(Drupal.t('Not restricted'));
      }
      return vals.join(', ');
    });

    $('fieldset#edit-authmap-fieldset', context).drupalSetSummary(function (context) {
      var vals = [];
      $('input[type="checkbox"]:checked', context).each(function() {
        vals.push($.trim($(this).next('label').text()));
      });
      if (!vals.length) {
        vals.push(Drupal.t('Not restricted'));
      }
      return vals.join(', ');
    });

    $('fieldset#edit-global-fieldset', context).drupalSetSummary(function (context) {
      var global = $('input[name="global"]:checked', context);
      if (global.val()) {
        return global.next('label').text();
      }
    });
  }
};

})(jQuery);
