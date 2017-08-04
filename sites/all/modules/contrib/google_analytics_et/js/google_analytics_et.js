Drupal.behaviors.googleAnalyticsET = {
  attach : function (context) {
    // make sure that the google analytics event tracking object or the universal analytics tracking function exists
    // if not then exit and don't track
    if(typeof _gaq == "undefined" && typeof ga == "undefined"){
      return;
    }

    var settings = Drupal.settings.googleAnalyticsETSettings;

    delete settings.selectors.debug;
    var defaultOptions = {
      label: '',
      value: 0,
      noninteraction: false,
      options: []
    };
    var s = new Array();
    for(var i = 0; i < settings.selectors.length; i++) {
      s[i] = settings.selectors[i].selector;
    }

    jQuery.each(s,
      function(i, val) {
        jQuery(settings.selectors[i].selector).once('GoogleAnalyticsET').bind(settings.selectors[i].event,
          function(event) {
            settings.selectors[i] = jQuery.extend(defaultOptions, settings.selectors[i]);
            trackEvent(jQuery(this), i, settings.selectors[i].options, settings.selectors[i].category, settings.selectors[i].action, settings.selectors[i].label, settings.selectors[i].value, settings.selectors[i].noninteraction)
          }
        );
      }

    );
  }

}

/**
 * trackEvent does the actual call to _gaq.push with the _trackEvent type.
 *
 * trackEvent calls the push method from the _gaq object. It also preforms
 * any token replacements on the category, action, and opt_label parameters.
 *
 * @param $obj
 *   The jQuery object that the click event was called on.
 * @param category
 *   The name you supply for the group of objects you want to track.
 * @param action
 *   A string that is uniquely paired with each category, and commonly used
 *   to define the type of user interaction for the web object.
 * @param opt_label
 *   An optional string to provide additional dimensions to the event data.
 * @param opt_value
 *   An integer that you can use to provide numerical data about the user
 *   event.
 * @param opt_oninteraction
 *   A boolean that when set to true, indicates that the event hit will not
 *   be used in bounce-rate calculation.
 */
function trackEvent($obj, id, options, category, action, opt_label, opt_value, opt_noninteraction) {
  var href = $obj.attr('href') == undefined ? false : String($obj.attr('href'));
  if (typeof this.options == 'undefined') {
    this.options = {};
  }
  this.options[id] = options;

  category = category == '!text' ? String($obj.text()) : (category == '!href' ? href : (category == '!currentPage' ? String(window.location.href) : String(category)));
  action = action == '!text' ? String($obj.text()) : (action == '!href' ? href : (action == '!currentPage' ? String(window.location.href) : String(action)));
  opt_label = opt_label == '!text' ? String($obj.text()) : (opt_label == '!href' ? href : (opt_label == '!currentPage' ? String(window.location.href) : String(opt_label)));

  // Google complains if category or action are not set so we fail gracefully.
  if (!category || !action) {
    console.log("Google Analytics Event Tracking: category and action must be set.")
    return;
  }

  // Only track once if the trackOnce option is set.
  if (this.options[id].trackOnce == true) {
    if (typeof this.options[id].times == 'undefined') {
      this.options[id].times = 1;
    }
    else {
      return;
    }
  }

  console.log(id);
  if (opt_label == '!test' || Drupal.settings.googleAnalyticsETSettings.settings.debug) {
    debugEvent($obj, category, action, opt_label, opt_value, opt_noninteraction);
  }
  else if( typeof _gaq != 'undefined' ){
    _gaq.push(['_trackEvent', String(category), String(action), String(opt_label), Number(opt_value), Boolean(opt_noninteraction)]);
  }
  else {
    ga('send', {
      'hitType': 'event',
      'eventCategory': String(category),
      'eventAction': String(action),
      'eventLabel': String(opt_label),
      'eventValue': Number(opt_value),
      'nonInteraction': Boolean(opt_noninteraction)
    });
  }
}

/**
 * A simple debug function that matches the trackEvent function.
 */
function debugEvent($obj, category, action, opt_label, opt_value, opt_noninteraction) {
  // Saftey First, safe use of console in IE.
  // http://blog.patspam.com/2009/the-curse-of-consolelog
  if (!("console" in window)) {
    alert(category + ' ' + action  + ' ' + opt_label + ' ' + opt_value);
  }
  else {
    var trackerObject = {
        category : category,
        action : action,
        opt_label : opt_label,
        opt_value : opt_value,
        opt_noninteraction : opt_noninteraction,
        $object : $obj
    }
    console.log(trackerObject);
  }
}
