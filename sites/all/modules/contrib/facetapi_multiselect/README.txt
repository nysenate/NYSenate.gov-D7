INTRODUCTION
------------

This module provides a multiselect widget plugin for the Facet API module
(http://drupal.org/project/facetapi).

It allows faceted searches (for example, those performed with Apache Solr) to
use a multiple select dropdown for drilling down into the search results.  It
automatically supports optgroups (for data with a hierarchy) as well.

JAVASCRIPT PLUGIN INTEGRATION
-----------------------------

Although this module can be used on its own, the standard HTML multiple select
element which it outputs is generally considered to have poor usability. Thus,
this module's primary use case is to allow easy integration of faceted search
with JavaScript plugins that provided an enhanced experience for multiple
select dropdowns. For example:
- jQuery UI MultiSelect Widget (http://www.erichynds.com/jquery/jquery-ui-multiselect-widget/)
- jQuery UI Multiselect (http://quasipartikel.at/multiselect/)
- Chosen (http://harvesthq.github.com/chosen/)

Integration can be accomplished relatively easily using hook_form_alter(). A
basic example is shown below, specifically targeted to the jQuery UI
MultiSelect Widget although similar code will likely work for other JavaScript
plugins too.

<?php
/**
 * Implements hook_form_BASE_FORM_ID_alter().
 */
function MYMODULE_form_facetapi_multiselect_form_alter(&$form, &$form_state) {
  // Add the JavaScript and CSS for the library itself. This assumes you are
  // using the Libraries module (http://drupal.org/project/libraries) and that
  // you've put the external library in sites/all/libraries/jquery.multiselect.
  // Note: Rather than adding each JS and CSS file individually as is done
  // below, hook_library() and $form['#attached']['library'][] could be used
  // instead.
  $path = libraries_get_path('jquery.multiselect');
  $form['#attached']['js'][] = $path . '/jquery.multiselect.min.js';
  $form['#attached']['css'][] = $path . '/jquery.multiselect.css';

  // Add a custom JavaScript file which will trigger the jQuery MultiSelect
  // widget on the correct form elements.
  $form['#attached']['js'][] = drupal_get_path('module', 'MYMODULE') . '/MYMODULE.facetapi.multiselect.js';
}
?>

The content of the above custom JavaScript file could be as simple as:

Drupal.behaviors.MYMODULEFacetApiMultiselectWidget = {
  attach: function (context, settings) {
    // Go through each facet API multiselect element that is being displayed.
    jQuery('.facetapi-multiselect', context).each(function () {
      // Attach the behavior to it.
      jQuery(this).multiselect({
        // Pass in whatever array of options you need here.
      });
    });
  }
};

Obviously, the exact content will depend on which JavaScript plugin you are
using and which options it requires.

If you need more complex functionality, note that when altering this form you
have access to a $form_state['facetapi_multiselect'] array with information
about the facet and widget (this information is also available in
$form['#facetapi_multiselect'] if for some reason you don't have access to
$form_state). This array contains the following keys:
- widget: The object used to build the multiselect Facet API widget. Any of its
  public methods are available to call.
- facet_name: The machine-readable name of the facet this widget was built for.
- facet_class: An HTML class based on facet name. All widgets will have the
  shared "facetapi-multiselect" class applied to them (used in the custom
  JavaScript example above), but this additional class allows you to uniquely
  target the widget for this particular facet; for example, you can pass it as
  a JavaScript setting and use it in order to have your custom JavaScript code
  make specific changes to this particular facet.

RELATED PROJECTS
----------------

If you are interested in this module, you might also want to take a look at the
following sandbox projects (this module also owes a debt to them for
inspiration for some of the code):
- Facetapi Select (http://drupal.org/sandbox/lynn/1311040), which provides a
  widget plugin for single selects, rather than multiselects
- Facet API Chosen (http://drupal.org/sandbox/sammyd56/1353462), which
  integrates directly with the Chosen JavaScript plugin, but currently only
  supports single selects, not multiselects.

CREDITS
-------

This project was sponsored by Advomatic (http://advomatic.com).
