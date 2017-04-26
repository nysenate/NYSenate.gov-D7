<?php
/**
 * @file
 * Fancy File Delete Unmanaged Directory Views Settings.
 */

class FancyFileDeleteUnmanagedDirectoryFilter extends views_handler_filter {

  var $always_multiple = TRUE;

  /**
   * Options form subform for setting options.
   *
   * This should be overridden by all child classes and it must
   * define $form['value']
   *
   * @see options_form()
   */
  function value_form(&$form, &$form_state) {
    $directories = fancy_file_delete_unmanaged_get_directories();
    $chosen_dirs = fancy_file_delete_unmanaged_get_chosen_dirs();

    $form['value'] = array(
      '#type' => 'checkboxes',
      '#options' => array_combine($directories, $directories),
      '#default_value' => array_values($chosen_dirs),
      '#no_convert' => TRUE,
    );
    $form['ffd_submitted'] = array(
      '#type' => 'hidden',
      '#value' => 'true',
    );
    drupal_add_css(drupal_get_path('module', 'fancy_file_delete') . '/css/fancy_file_delete.css');

    // Set our initial value to be our saved preference.
    if (empty($form_state['input']['ffd_submitted'])) {
      $form['value']['#value'] = array_values($chosen_dirs);
      $form_state['input']['unmanaged_directories'] = array_combine($chosen_dirs, $chosen_dirs);
    }
    // Store our preference on submit.
    else {
      if (is_array($form_state['input']['unmanaged_directories'])) {
        fancy_file_delete_unmanaged_set_chosen_dirs(array_keys($form_state['input']['unmanaged_directories']));
      }
      // clear the values.
      else {
        fancy_file_delete_unmanaged_set_chosen_dirs(array());
      }

    }
  }

  function query() { }
}
