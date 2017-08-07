<?php
/**
 * @file
 * Fancy File Delete Orphan Files Views Settings.
 */

class FancyFileDeleteOrphanFileFilter extends views_handler_filter {

  function value_form(&$form, &$form_state) {
    parent::value_form($form, $form_state);

    // Hide default behavoir just in case.
    $form['expose_button']['#access'] = FALSE;
    $form['more']['#access'] = FALSE;

    $form['orphan_text'] = array(
      '#type' => 'item',
      '#markup' => t('This is just a custom query filter no need for any configuration.')
    );
  }

  function query() {
    $this->ensure_my_table();

    // Check if file is used by any other module/entity.
    $join = new views_join();
    $join->construct('file_usage', 'file_managed', 'fid', 'fid');
    $this->query->add_relationship('fu', $join, 'node');

    $this->query->add_where(0, 'fu.fid', NULL, 'IS NULL');
  }
}
