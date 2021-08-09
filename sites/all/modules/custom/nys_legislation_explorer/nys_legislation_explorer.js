function advanced_search_module($) {

  /**
   * Toggle the current form view based on the content type selected
   * via the type select menu.
   */
   function updateTypeFilter($typeFilter, $submitBtn) {
    var type = $typeFilter.val();
    $(".adv-search-ctrls").hide();
    if (type) {
      $(".adv-search-ctrls." + type).show();
      $submitBtn.show();
    }
    else {
      $submitBtn.hide();
    }
  }

  $(document).ready(function() {
    var $typeFilter   = $("#adv-search-leg-type");    
    var $submitBtn    = $("#adv-search-submit");
    var $form         = $("#adv-search-form");
    var $searchingLbl = $(".c-adv-search--searching");
    // Initialize the form
    updateTypeFilter($typeFilter, $submitBtn);
    // Watch for changes
    $typeFilter.change(function(e) {
      updateTypeFilter($typeFilter, $submitBtn);  
    });
    // Handle form submits
    $form.submit(function(e) {
      // Disable any inputs that are not applicable to the current search request;
      // prevents them from showing up in the url upon submitting.
      $form.find('.adv-search-ctrls').each(function(i, searchCtrl) {
        $searchCtrl = $(searchCtrl);
        var currType = $typeFilter.val();
        $searchCtrl.find('input, select').each(function(j, input) {
          $input = $(input);
          if (!$searchCtrl.hasClass(currType) || !$input.val()) {
            $(input).attr('disabled', 'disabled');  
          }
        });
      });
      $submitBtn.hide();
      $searchingLbl.show();
    });
  });
}

function law_viewer_module($) {

  var $searchResultContainer = $('#law-global-search-results');
  var $searchResults = $('#law-global-search-results');
  var $lawSearchForm = $("#law-search-form");
  var $lawSearch = $("#law-search");
  var $ajaxLoader = $('.c-law--search-loader');
  
  // Initialize search fields.
  var term = $lawSearch.val(); 
  var lawId = $lawSearch.attr('data-law-id');
  var offsetStart = 1;

  $searchResultContainer.on('click', '.c-law--show-more', null, function(){
    $(".c-law--show-more").remove();
    law_search(false); 
  });

  function law_search(reset) {
    $searchResults.addClass('c-law--searching');
    if (term) {
      // Adjust the term so that each word is prefixed with +, resulting in an inclusive search.
      term = term.trim().replace('+', '').split(' ').map(function(t) {return '+' + t}).join(' ');
      $searchResultContainer.show();
      $ajaxLoader.show();
      if (reset) {
        offsetStart = 1;
      }
      $.ajax('/legislation/laws/ajax/search', {data: {'term': term, 'lawId': lawId, 'limit': 25, 'offset': offsetStart}})
        .done(function(data) {
          var resp = JSON.parse(data);
          if (reset) {
            $searchResults.empty();  
          }
          offsetStart = resp.offsetEnd + 1;
          if (resp.result.size == 0) {
            $searchResults.append('<h4 class="c-law--search-result-warnmsg">' + 
              'No matching documents were found.</h4>');
          }
          else {
            $searchResults.append('<h4 class="c-law--search-result-msg">Showing results ' + 
              resp.offsetStart + '-' + resp.offsetEnd + ' of ' + resp.total +
              ' matching law document(s)</h4>');
          }
          $.each(resp.result.items, function(i, v) {                    
            $searchResults.append(create_search_result_elem(v));
          });
          $searchResults.removeClass('c-law--searching');
          if (resp.offsetEnd < resp.total) {
            $searchResults.append('<p class="c-law--show-more"><a>Show More<a></p>');  
          }
        })
        .fail(function(){console.log('error')})
        .always(function(){
         $ajaxLoader.hide();
       });
    }
    else {
      $searchResults.empty();
      $searchResultContainer.hide();
    }
  }

  $(document).ready(function() {
    // Trigger law search on form submit
    $lawSearchForm.submit(function(e) {
      term = $lawSearch.val();
      lawId = $lawSearch.data('lawId');
      law_search(true);  
      e.preventDefault();
    });
    // and on document load
    if ($lawSearch.val()) {
      law_search(true);
    }
  });

  function create_search_result_elem(v) {
    var r = v.result;
    var $resultEl = $("<div class='c-law--search-result-container'></div>");
    $resultEl.append($("<p><a target='_blank' href='" + '/legislation/laws/' + r.lawId + '/' + r.locationId
      + "' class='c-law--search-result-location'>"
      + r.docType.toLowerCase() + " " + r.docLevelId + " - " + r.lawName
      + "</a></p>"));
    $resultEl.append($("<p class='c-law--search-result-title'>" + r.title + "</p>"));
    var highlightText = (v.highlights.text)
      ? v.highlights.text.reduce(function(a,b) { return a + ' ' + b; })
      : '';
    highlightText = highlightText.replace(/\\n/g, ' ');
    $resultEl.append($("<span class='c-law--search-result-highlight'>" + highlightText + "</p>"));
    return $resultEl;
  }
}

(function ($) {
  Drupal.behaviors.nys_legislation_explorer = {
    attach: function (context, settings) {
      advanced_search_module($);
      law_viewer_module($);
    }
  };
})(jQuery);