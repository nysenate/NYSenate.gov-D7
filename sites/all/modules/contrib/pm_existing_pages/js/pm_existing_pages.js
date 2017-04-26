
/**
 * @file
 * Page manager existing pages - some overrides for autocomplete.
 */

(function ($) {

  /**
   * Select acts completely different than default.
   */
  Drupal.jsAC.prototype.select = function (node) {
    var $value = $(node).data('autocompleteValue');
    // Close popup.
    if ($value == 'close_pm_existing_pages_suggestions') {
      Drupal.jsAC.prototype.hidePopup('close_pm_existing_pages_suggestions');
    }
    else {
      // Get current selected paths. It's possible that it's empty
      // and in that case, we'll initialize a new array.
      $current = $('#edit-paths').val();
      if ($current.length > 0) {
        var $array = $current.split("\n");
      }
      else {
        $array = new Array;
      }
      // Add value to array.
      if ($.inArray($value, $array) == -1) {
        $array.push($value);
      }
      // Remove value.
      else {
        var $new_array = new Array;
        for (i = 0; i < $array.length; i++) {
          if ($array[i] != $value) {
            $new_array.push($array[i]);
          }
        }
        $array = $new_array;
      }
      // Add paths to textarea.
      $('#edit-paths').val($array.join("\n"));
    }
  };  
  
  /**
   * Close the popup.
   */
  Drupal.jsAC.prototype.hidePopup = function (keycode) {
    if (keycode == 'close_pm_existing_pages_suggestions') {
      this.popup = null;
      $('#autocomplete').fadeOut('fast', function () { $('#autocomplete').remove(); });    
      $(this.ariaLive).empty();
      this.selected = false;
    }
  };

  /**
   * Performs a cached and delayed search.
   */
  Drupal.ACDB.prototype.search = function (searchString) {
    var db = this;
    this.searchString = searchString;
  
    // See if this string needs to be searched for anyway.
    searchString = searchString.replace(/^\s+|\s+$/, '');
    if (searchString.length <= 0 ||
      searchString.charAt(searchString.length - 1) == ',') {
      return;
    }
  
    // See if this key has been searched for before.
    if (this.cache[searchString]) {
      return this.owner.found(this.cache[searchString]);
    }
  
    // Initiate delayed search.
    if (this.timer) {
      clearTimeout(this.timer);
    }
    this.timer = setTimeout(function () {
      db.owner.setStatus('begin');
  
      // Ajax GET request for autocompletion.
      $.ajax({
        type: 'GET',
        url: db.uri + '/' + encodeURIComponent(searchString).replace(/%2F/g, '%1B'),
        dataType: 'json',
        success: function (matches) {
          if (typeof matches.status == 'undefined' || matches.status != 0) {
            db.cache[searchString] = matches;
            // Verify if these are still the matches the user wants to see.
            if (db.searchString == searchString) {
              db.owner.found(matches);
            }
            db.owner.setStatus('found');
          }
        },
        error: function (xmlhttp) {
          alert(Drupal.ajaxError(xmlhttp, db.uri));
        }
      });
    }, this.delay);
  };

})(jQuery);