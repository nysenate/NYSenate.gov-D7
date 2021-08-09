(function($) {
  
// Updates to the Views under /admin/content/profiles  
Drupal.behaviors.manage_profiles = {
  attach: function (context, settings) {
    // Add titles to bulk operation columns.
    $('#views-form-manage-profiles-page-1 th.views-field-views-bulk-operations div.form-type-checkbox input', context).before('Bulk Edit<br>');
    $('#views-form-manage-profiles-page-1 th.views-field-views-send div.form-type-checkbox input', context).before('Email<br>');
    $('#views-form-manage-profiles-page-2 th.views-field-views-bulk-operations div.form-type-checkbox input', context).before('Bulk Edit<br>');
    $('#views-form-manage-profiles-page-2 th.views-field-views-send div.form-type-checkbox input', context).before('Email<br>');
    $('#views-form-manage-profiles-page-3 th.views-field-views-bulk-operations div.form-type-checkbox input', context).before('Bulk Edit<br>');
    $('#views-form-manage-profiles-page-3 th.views-field-views-send div.form-type-checkbox input', context).before('Email<br>');
    $('#views-form-manage-profiles-page-4 th.views-field-views-bulk-operations div.form-type-checkbox input', context).before('Bulk Edit<br>');
    $('#views-form-manage-profiles-page-4 th.views-field-views-send div.form-type-checkbox input', context).before('Email<br>');  
  }
};

})(jQuery);