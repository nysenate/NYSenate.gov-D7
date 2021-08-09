;
// Initialize all open data tables on load
Drupal.behaviors.opendata = {
  attach: function (context, settings) {
    // Each table can have custom init settings.  Try to read them.
    jQuery('.managed-csv-datatable-container').each(function (i, v) {
      let $v = jQuery(v),
          table_id = $v.data('fid'),
          settings = Drupal.settings.opendata.dt_init || {},
          this_set = settings['t_' + table_id] || settings.default || {};
      $v.children('.managed-csv-datatable').DataTable(this_set);
    });
  }
}
