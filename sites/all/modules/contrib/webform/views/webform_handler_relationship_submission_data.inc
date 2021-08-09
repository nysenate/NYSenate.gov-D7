<?php

/**
 * Views' relationship handlers.
 */
class webform_handler_relationship_submission_data extends views_handler_relationship {

  /**
   * {@inheritdoc}
   */
  public function option_definition() {
    $options = parent::option_definition();
    $options['webform_nid'] = array('default' => NULL);
    $options['webform_cid'] = array('default' => NULL);
    $options['webform_form_key'] = array('default' => NULL);
    $options['webform_join_by'] = array('default' => 'nid_cid');
    return $options;
  }

  /**
   * {@inheritdoc}
   */
  public function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    form_load_include($form_state, 'inc', 'webform', 'views/webform.views');

    $nid = (int) $this->options['webform_nid'];
    $cid = (int) $this->options['webform_cid'];

    // Helper function provides webform_nid and webform_cid options.
    _webform_views_options_form($form, $form_state, $nid, $cid);

    $form['webform_join_by'] = array(
      '#type' => 'select',
      '#title' => t('Relate using'),
      '#default_value' => $this->options['webform_join_by'],
      '#options' => array(
        'nid_cid' => t('Node and Component ID'),
        'cid' => t('Component ID'),
        'form_key' => t('Component Form Key'),
      ),
      '#description' => t('Choose <em>Node and Component ID</em> when this view will display data from only this webform.</br>Choose <em>Component ID</em> when this view will display data from other webforms and where the Component ID is identical.</br>Choose <em>Component Form Key</em> when this view will display data from other webforms with varying Component IDs.'),
    );

  }

  /**
   * {@inheritdoc}
   */
  public function options_validate(&$form, &$form_state) {
    parent::options_validate($form, $form_state);
    _webform_views_options_validate($form, $form_state);
  }

  /**
   * {@inheritdoc}
   */
  public function options_submit(&$form, &$form_state) {
    parent::options_submit($form, $form_state);
    _webform_views_options_submit($form, $form_state);
    $options =& $form_state['values']['options'];
    $options['webform_form_key'] = $options['webform_join_by'] == 'form_key' && ($node = node_load($options['webform_nid']))
                                        ? $node->webform['components'][$options['webform_cid']]['form_key']
                                        : NULL;
    // Drop PHP reference.
    unset($options);
  }

  /**
   * Called to implement a relationship in a query.
   *
   * It respects the given component ids, provided via options form.
   */
  public function query() {
    // When defining extra clauses, the 'table' key can be used to specify the
    // alias of another table. If NULL is specified, then the field is not
    // qualified with a table. Therefore, do NOT specify "'table' => NULL".
    switch ($this->options['webform_join_by']) {
      case 'form_key':
        $form_key = $this->options['webform_form_key'];
        $join_type = $this->options['required'] ? 'INNER' : 'LEFT';

        $this->ensure_my_table();
        $join = new views_join();

        $join->construct(
          // The table to be joined.
          'webform_component',
          // The left table (i.e. this table, webform_submission).
          $this->table,
          // The left field (i.e. the webform node id).
          'nid',
          // The field (i.e. webform_components.nid).
          'nid',
          // Extra array of additional conditions.
          array(
            array(
              // Extra join of form_key.
              'field' => 'form_key',
              // ...    = $form_key (operator '=' is default)
              'value' => $form_key,
            ),
          ),
          // Join type is the same as this relationship's join type.
          $join_type);

        $alias = $this->query->add_relationship(
          // Requested alias for new reliationship.
          'webform_component_' . $form_key,
          // Addition join to be added to this relatinship.
          $join,
          // Base table (i.e. drivingevals_submission)
          $this->table_alias,
          // Add the view to this relationship.
          $this->relationship);

        // The actual alias for this relationship's join is not known yet. Becasue
        // of name conflicts, it may have a number appended to the end. %alias is
        // substitued when the query is build with the actual alias name.
        $this->definition['extra'][] = "%alias.cid = {$alias}.cid";
        break;

      case 'nid_cid':
        $this->definition['extra'][] = array(
          'field' => "nid",
          'value' => $this->options['webform_nid'],
        );
        // FALL THROUGH.
      case 'cid':
        $this->definition['extra'][] = array(
          'field' => "cid",
          'value' => $this->options['webform_cid'],
        );
        break;
    }

    // The rest of building the join is performed by the parent.
    parent::query();
  }

}
