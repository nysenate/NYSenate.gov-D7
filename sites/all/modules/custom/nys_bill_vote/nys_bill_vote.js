/**
 * @file
 * Sets up the Aye/Nay voting widget seen on bill nodes.
 */
'use strict';
!(function ($) {
    // Custom return handler for AJAX vote submission.
    Drupal.ajax.prototype.commands.nysBillVoteUpdate = function (ajax, response, status) {
        Drupal.behaviors.nysBillVote.voteOnBill(ajax.element, response);
    };

    Drupal.theme.createConfirmationModal = function (options) {
        var defaults = {
                button_element: 'a',
                parent_element: 'div',
                data: '',
                data_element: 'p',
                default_text: 'Confirm',
                cancel_text: 'Cancel',
                default_class: '',
                cancel_class: '',
                default_callback: '',
                cancel_callback: '',
                id: '',
                auto_attach: true,
                attach_target: 'footer',
                buttons_first: false,
            },
            opts = Object.assign({}, defaults, options),
            attr = {
                'data-reveal': '',
                'aria-hidden': 'true',
                role: 'dialog',
            },
            parent = $('<' + opts.parent_element + '/>').addClass('reveal-modal small').attr(attr),
            button_a = $('<' + opts.button_element + ' href="#" class="default button"/>').html(opts.default_text),
            button_b = $('<' + opts.button_element + ' href="#" class="secondary button"/>').html(opts.cancel_text)
        ;
        if (opts.id) {
            parent.attr('id', opts.id);
        }
        if (opts.default_class) {
            button_a.addClass(opts.default_class);
        }
        if (opts.cancel_class) {
            button_b.addClass(opts.cancel_class);
        }
        var buttons = $('<' + opts.data_element + '/>').append(button_a, button_b),
            content = $('<' + opts.data_element + '/>').append(opts.data);
        if (opts.buttons_first) {
            parent.append(buttons, content)
        }
        else {
            parent.append(content, buttons);
        }
        if (opts.default_callback) {
            parent.on('click', '.default.button', opts.default_callback);
        }
        if (opts.cancel_callback) {
            parent.on('click', '.secondary.button', opts.cancel_callback);
        }
        if (opts.auto_attach && $(opts.attach_target).length) {
            $(opts.attach_target).append(parent);

            // Make sure Foundation knows about the new modal.
            parent.foundation();
            parent.foundation('reveal', 'reflow');
        }
        return parent;
    };

    Drupal.behaviors.nysBillVote = {
        attach: function (context, settings) {
            var self = this;
            // Hide the message box if the form is re-loaded.
            if ($('#nys-bills-bill-form input[name=register],', context).prop('checked') === false && !settings.is_logged_in) {
                $('.c-bill--message-form .form-item-message', context).hide();
            }

            // Add a click event handler for hiding the message form if 'Create an
            // account checkbox is unchecked. We need to delegate this event so that:
            //   - it can be added using $.once()
            //   - duplicate handlers are avoided
            $('#nys-bills-bill-form', context).once('hide-message-click-handler', function () {
                $(this).on('click', 'input[name=register]', function (e) {
                    var $func = (e.target.checked) ? 'show' : 'hide';
                    $('.c-bill--message-form .form-item-message')[$func]();
                });

                self.processIntentVote(context, settings);
            });
        },

        processIntentVote: function (context, settings) {
            var self = this,
                intentValue = self.getQueryParamValue('intent'),
                intentText = ''
            ;
            if (intentValue === 'oppose') {
                intentText = 'opposition';
            }
            if (intentValue === 'support') {
                intentText = 'support';
            }

            // If there is no intent text (i.e., a valid intent), nothing to do.
            if (!intentText) {
                return;
            }

            // Get some info on the detected intent and write it back to settings.
            var response = self.getResponseFromIntent(intentValue),
                element = self.getTriggeringElement(intentValue)
            ;
            settings.bill_vote = Object.assign(settings.bill_vote, {
                response: response,
                element: element,
                intentValue: intentValue
            });

            // If the user is not logged in, just process the selection (no modal).
            if (!settings.is_logged_in) {
                self.voteOnBill(element, response, intentValue);
                return;
            }

            // Create confirmation modal and append it to footer. It is hidden
            // by default.
            var options = {
                id: 'confirm-vote-intent-modal',
                data: 'Confirm your ' + intentText + ' for ' + settings.bill_vote.bill_name,
                default_class: 'confirmed-vote',
                cancel_class: 'canceled-vote',
                default_callback: self.callbackIntentConfirm,
                cancel_callback: self.callbackIntentCancel
            };

            var confirmationModal = Drupal.theme('createConfirmationModal', options);

            // Ask user for confirmation and then record vote.
            setTimeout(function () {
                $('#confirm-vote-intent-modal').foundation('reveal', 'open');
            }, 1000);
        },

        callbackIntentConfirm: function (e) {
            e.preventDefault();
            var settings = Drupal.settings.bill_vote;
            $.ajax({
                url: '/bill_vote_confirmation/callback/' + settings.bill_entity_id + '/' + settings.response.vote_value,
                complete: function (jqXHR, status) {
                    if (status === 'success') {
                        // Close modal.
                        $(e.target).closest('.reveal-modal').foundation('reveal', 'close');
                        // Do the after-vote necessities.
                        Drupal.behaviors.nysBillVote.voteOnBill(settings.element, settings.response, settings.intentValue);
                    }
                }
            });
        },

        callbackIntentCancel: function (e) {
            e.preventDefault();
            // Close modal.
            $(e.target).closest('.reveal-modal').foundation('reveal', 'close');
        },

        callbackAutosubHandler: function (e) {
            e.preventDefault();
            var save_val = ($(e.target).hasClass('default')) ? 1 : 0;
            $.ajax({
                url: '/bill_vote_autosub/callback/' + Drupal.settings.bill_vote.bill_entity_id + '/' + save_val,
                complete: function (jqXHR, status) {
                    // Close modal.
                    $(e.target).closest('.reveal-modal').foundation('reveal', 'close');
                }
            });
        },

        /**
         * Helper function to retrieve query params by key.
         *
         * @param {string} key
         *   The query param key whose value you want.
         *
         * @returns {string|null}
         *   Returns value of query param if found, null if not.
         */
        getQueryParamValue: function (key) {
            var match = RegExp('[?&]' + key + '=([^&]*)').exec(window.location.search);
            return match && decodeURIComponent(match[1].replace(/\+/g, ' '));
        },
        /**
         * Helper function to get (mock) a 'response' object based on an intent.
         *
         * @param {string} intent
         *   The user intent.
         *
         * @returns {object}
         *   Returns a response object with vote_value and vote_label.
         */
        getResponseFromIntent: function (intent) {
            var response;
            if (intent === 'support') {
                response = {
                    vote_value: 'yes',
                    vote_label: Drupal.settings.bill_vote.vote_options.yes
                };
            }
            else {
                response = {
                    vote_value: 'no',
                    vote_label: Drupal.settings.bill_vote.vote_options.no
                };
            }

            return response;
        },
        /**
         * Helper function to derive an 'intent' from a response object.
         *
         * @param {object} response
         *   The response object.
         *
         * @returns {string}
         *   Returns a string of user intent.
         */
        getIntentFromResponse: function (response) {
            var intent;
            if (response.vote_value === 'yes') {
                intent = 'support';
            }
            else {
                intent = 'oppose';
            }

            return intent;
        },
        /**
         * Helper function to get the triggering button for a vote.
         *
         * @param {string} intent
         *   The user intent.
         *
         * @returns {object}
         *   Returns a javascript DOM object of the vote button that corresponds to
         *   intent.
         */
        getTriggeringElement: function (intent) {
            var element;
            if (intent === 'support') {
                element = document.querySelectorAll('button.nys-bill-vote-yes')[0];
            }
            else {
                element = document.querySelectorAll('button.nys-bill-vote-no')[0];
            }

            return element;
        },
        /**
         * Functionality to trigger show/hide of elements after a Bill Vote.
         *
         * @param {string} element
         *   The element that was clicked on or 'intended'.
         * @param {string} response
         *   Response Object from ajax.
         * @param {string} userIntent
         *   User intent passed in via the url. Could be 'support' or 'oppose'.
         *
         * @returns {void}
         */
        voteOnBill: function (element, response, userIntent) {
            var self = this,
                intent = userIntent || this.getIntentFromResponse(response),
                $target = $(element)
            ;

            // Update url with historyApi to add intent query param.
            this.updateQueryStringParam('intent', intent);

            // Set the status label.
            if (Drupal.settings.is_logged_in === false) {
                var cta_language = 'Complete this form to <strong>' + intent + '</strong> this bill:';
                $('p.c-bill-polling--cta', element.form).html(cta_language);
            }

            // Set selected class for highlighting the voter's selection.
            $target.addClass('selected accent-bg');
            $target.siblings().removeClass('selected accent-bg');

            // Reset the classes to move the widget inline.
            $('.c-bill--vote-widget')
                .addClass('c-bill--vote-attach')
                .removeClass('c-bill--vote-widget');

            // Hide the subscription form controls.
            // NOTE: This doesn't exist on the page.
            $('.nys-bill-subscribe').addClass('js-hide');

            // Show the other form-centric elements.
            // NOTE: Change to using the js-hide if possible.
            // -- https://github.com/jquery/jquery.com/issues/88#issuecomment-72400007
            $('.c-bill--message-form').show();
            $('.c-bill--sentiment-update').show();

            // Set the value on the "new" form submit.
            $('input[name=vote_value]').val(response.vote_value);

            // Scroll to the top of the form area.
            if ($('.nys-bill-vote').length) {
                $('html, body').animate({scrollTop: $('.nys-bill-vote').offset().top - 250}, 'slow');
            }


            if (Drupal.settings.is_logged_in === false) {
                var buttonText = '';
                if (response.vote_value === 'yes') {
                    buttonText = Drupal.t('Support this bill');
                }
                else {
                    buttonText = Drupal.t('Oppose this bill');
                }
                $('#nys-bills-bill-form button[type="submit"]').html(buttonText);
            }

            // Handle auto-subscription process.
            if (Drupal.settings.auto_subscribe === false && Drupal.settings.is_logged_in) {
                var check_box = $('<input type="checkbox" id="autosub_remember" name="autosub_remember"/>'),
                    check_label = $('<label for="autosub_remember"><span>Remember this selection</span></label>');
                check_label.prepend(check_box);
                var options = {
                        id: 'auto-subscribe-modal',
                        data: 'Always subscribe to bill status alerts when supporting or opposing bills? <a href="/citizen-guide/bill-alerts">Learn more.</a>',
                        default_class: 'confirmed-autosub',
                        default_text: 'Yes',
                        default_callback: self.callbackAutosubHandler,
                        cancel_class: 'canceled-autosub',
                        cancel_text: 'No',
                        cancel_callback: self.callbackAutosubHandler
                    },
                    autosubModal = Drupal.theme('createConfirmationModal', options);

                // Ask user for confirmation and then record vote.
                setTimeout(function () {
                    $('#auto-subscribe-modal').foundation('reveal', 'open');
                }, 500);

            }

        },
        /**
         * Explicitly save/update a url parameter using HTML5's replaceState().
         *
         * Helper function to manage url with History API. This could potententially
         * be moved to nys_utils module so it can be accessed by a namespace that
         * may make more sense.
         *
         * @param {string} key
         *   Url param key.
         * @param {string} value
         *   Url param value.
         *
         * @returns {void}
         */
        updateQueryStringParam: function (key, value) {
            var baseUrl = [location.protocol, '//', location.host, location.pathname].join('');

            // Grab any existing query params that exist in the URL.
            var urlQueryString = location.search;
            var newParam = key + '=' + value;
            var params = '?' + newParam;

            // If an existing query param string exists, then process so we can ensure
            // that any existing keys have their values updated.
            if (urlQueryString) {
                var keyRegex = new RegExp('([\?&])' + key + '[^&]*');

                // If param exists in the URL already, update it,
                if (urlQueryString.match(keyRegex) !== null) {
                    params = urlQueryString.replace(keyRegex, '$1' + newParam);
                }
                else { // Otherwise, add it to end of query string
                    params = urlQueryString + '&' + newParam;
                }
            }
            // Update the URL.
            history.pushState({}, '', baseUrl + params);
        }
    };

})(jQuery);
