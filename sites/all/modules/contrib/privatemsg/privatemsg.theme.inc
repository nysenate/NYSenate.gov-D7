<?php

/**
 * @file
 * Theme functions for privatemsg.
 */

/**
 * @defgroup theming Theming documentation
 *
 * It is possible to theme many aspect of privatemsg with theme functions.
 *
 * For the thread list, so called theme patterns are used to allow flexible
 * theming of the table and its columns (including columns added by other
 * modules).
 *
 * Columns are defined with hook_privatemsg_header_info(). The default weight
 * and if they are enabled or not can by set by default but can be overridden in
 * the admin user interface.
 *
 * Additionally, a theme function needs to be defined that defaults to the name
 * 'privatemsg_list_field__$key', where $key is the name of the header/column.
 *
 * Every theme function will receive the $thread array as single argument, which
 * is everything that has been returned by the query built in
 * privatemsg_sql_list(). The theme function should return either a string or a
 * theme_table() compatible array.
 *
 * To change what information is available in that array, it is possible to
 * either implement hook_privatemsg_sql_list_alter() or alter $form['#data'] of
 * privatemsg_list(). See privatemsg_filter_form_privatemsg_list_alter() for an
 * example.
 *
 * To override an already existing theme function, use the following structure:
 * themename_privatemsg_list_field_fieldname. It is possible to change the
 * header definition with hook_privatemsg_header_info_alter() but that is often
 * not necessary.
 *
 */

/**
 * @addtogroup theming
 * @{
 */

/**
 * Theme the participants field.
 */
function theme_privatemsg_list_field__participants($variables) {
  $thread = $variables['thread'];
  $participants = _privatemsg_generate_user_array($thread['participants'], -4);
  $field = array();
  $field['data'] = _privatemsg_format_participants($participants, 3, TRUE);
  $field['class'][] = 'privatemsg-list-participants';
  return $field;
}

/**
 * Theme the subject of the thread.
 */
function theme_privatemsg_list_field__subject($variables) {
  $thread = $variables['thread'];
  $field = array();
  $options = array();
  $is_new = '';
  if (!empty($thread['is_new'])) {
    $is_new = theme('mark', array('type' => MARK_NEW));
    $options['fragment'] = 'new';
  }
  $subject = $thread['subject'];
  if ($thread['has_tokens']) {
    $message = privatemsg_message_load($thread['thread_id']);
    $subject = privatemsg_token_replace($subject, array('privatemsg_message' => $message), array('sanitize' => TRUE, 'privatemsg-show-span' => FALSE));
  }
  $field['data'] = l($subject, 'messages/view/' . $thread['thread_id'], $options) . $is_new;
  $field['class'][] = 'privatemsg-list-subject';
  return $field;
}

/**
 * Theme the replies field.
 */
function theme_privatemsg_list_field__count($variables) {
  $thread = $variables['thread'];
  $field = array();
  $field['data'] = $thread['count'];
  $options = array();
  if (!empty($thread['is_new']) && $thread['is_new'] < $thread['count']) {
    $options['fragment'] = 'new';
    $field['data'] .= '<br />' . l((format_plural($thread['is_new'], '(1 new)', '(@count new)')), 'messages/view/' . $thread['thread_id'], $options);
  }
  $field['class'][] = 'privatemsg-list-count';
  return $field;
}

/**
 * Theme the last updated column.
 */
function theme_privatemsg_list_field__last_updated($variables) {
  $thread = $variables['thread'];
  $field['data'] = privatemsg_format_date($thread['last_updated']);
  $field['class'][] = 'privatemsg-list-date';
  return $field;
}

/**
 * Theme the thread started column.
 */
function theme_privatemsg_list_field__thread_started($variables) {
  $thread = $variables['thread'];
  $field = array();
  $field['data'] = privatemsg_format_date($thread['thread_started']);
  $field['class'][] = 'privatemsg-list-date-started';
  return $field;
}

/**
 * Theme a block which displays the number of unread messages a user has.
 */
function theme_privatemsg_new_block($count) {
  $count = $count['count'];
  if ($count == 0) {
    $text = t('Click here to go to your messages.');
  }
  else {
    $text = format_plural($count, 'You have an unread message! Click here to read it.',
                        'You have @count unread messages! Click here to read them.');
  }

  return l($text, 'messages', array('attributes' => array('id' => 'privatemsg-new-link')));
}

/**
 * Used to theme and display user recipients.
 *
 * Wrapper for theme_username() with a few additional options.
 */
function theme_privatemsg_username($variables) {
  $recipient = $variables['recipient'];
  $options = $variables['options'];
  if (!isset($recipient->uid)) {
    $recipient->uid = $recipient->recipient;
  }
  if (!empty($options['plain'])) {
    $name = strip_tags(format_username($recipient));
    if (!empty($options['unique'])) {
      $name .= ' [user]';
    }
    return $name;
  }
  else {
    return theme('username', array('account' => $recipient));
  }
}

/**
 * Output the admin settings display fields and weight settings as a
 * drag and drop sortable table.
 */
function theme_privatemsg_admin_settings_display_fields($variables) {
  $element = $variables['element'];
  $header = array(
    array('data' => t('Field'), 'class' => array('field')),
    array('data' => t('Enable'), 'class' => array('enable')),
    array('data' => t('Weight'), 'class' => array('weight')),
  );
  $rows = array();
  foreach (element_children($element['privatemsg_display_fields']) as $child) {
    $row = array();

    // Title.
    $row[] = array('data' => $element['privatemsg_display_fields'][$child]['#title'], 'class' => array('field'));
    unset($element['privatemsg_display_fields'][$child]['#title']);

    // Enable checkbox.
    $row[] = array('data' => drupal_render($element['privatemsg_display_fields'][$child]), 'class' => array('enable'));

    // Weight selector.
    unset($element['privatemsg_display_fields_weights'][$child]['#title']);
    $element['privatemsg_display_fields_weights'][$child]['#attributes']['class'] = array('privatemsg-display-fields-weight');
    $row[] = array(
      'data' => drupal_render($element['privatemsg_display_fields_weights'][$child]),
      'class' => array('weight'),
    );

    $rows[] = array('data' => $row, 'class' => array('draggable'));
  }
  if (!empty($rows)) {
    drupal_add_tabledrag('privatemsg-list-display-fields', 'order', 'sibling', 'privatemsg-display-fields-weight');
    return theme('table', array('header' => $header, 'rows' => $rows, 'attributes' => array('id' => 'privatemsg-list-display-fields'))) . drupal_render_children($element);
  }
  else {
    return drupal_render_children($element);
  }
}

/**
 * @}
 */
