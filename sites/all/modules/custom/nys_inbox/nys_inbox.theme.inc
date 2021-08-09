<?php

/**
 * @file
 * Theme processing for user's message inbox.
 */

/**
 * Add a doc comment here.
 */
function theme_privatemsg_list_field__nys_inbox_subject($variables) {
  $is_new = '';

  if (empty($variables['message'])) {
    if (isset($variables['thread'])) {
      $thread = $variables['thread'];
      if (isset($thread['thread_id'])) {
        $thread_id = $thread['thread_id'];
      }
      else {
        $thread_id = '';
      }
      $message = privatemsg_message_load($thread['thread_id']);
    }
  }
  else {
    $message = $variables['message'];
    $thread_id = '';
  }

  $items = array();

  if (is_numeric(arg(1))) {
    $account = user_load(arg(1));
  }
  elseif (!empty($variables['thread']['dash_uid']) && is_numeric($variables['thread']['dash_uid'])) {
    $account = user_load($variables['thread']['dash_uid']);
  }

  if (isset($message->field_issues[LANGUAGE_NONE])) {
    foreach ($message->field_issues[LANGUAGE_NONE] as $issue) {
      $term = taxonomy_term_load($issue['tid']);
      $items[] = $term->name;
    }
  }

  if (empty($items)) {
    array_unshift($items, $message->subject);
  }

  $subject = implode(', ', $items);
  $options = array('html' => TRUE);
  $subject_themed = '<div class="subject">' . l($subject, 'user/' . $account->uid . '/dashboard/inbox/reply/' . $thread_id, $options) . $is_new . '</div>';

  $field = array(
    'data' => $subject_themed,
    'class' => 'privatemsg-list-subject-item',
  );

  return $field;
}

/**
 * Add a doc comment here.
 */
function theme_privatemsg_list_field__downarrow($variables) {

  $thread = $variables['thread'];

  $message = privatemsg_message_load($thread['thread_id']);

  if (is_numeric(arg(1))) {
    $account = user_load(arg(1));
  }
  elseif (!empty($variables['thread']['dash_uid']) && is_numeric($variables['thread']['dash_uid'])) {
    $account = user_load($variables['thread']['dash_uid']);
  }

  $dashboard_link = url('user/' . $account->uid . '/dashboard');

  $output = '<div class="message-body-toggle" data-thread_id="' . $thread['thread_id'] . '">&#x2304</div>';
  $output .= '<div class="message-action-buttons">';

  if (user_access('dashboard inbox forward messages', $account)) {
    $output .= '<a class="forward-button" id="forward-button-' . $thread['thread_id'] . '" href="' . $dashboard_link . '/inbox/forward/' . $thread['thread_id'] . '">Forward</a>';
  }
  $output .= '<a class="reply-button" id="reply-button-' . $thread['thread_id'] . '" href="' . $dashboard_link . '/inbox/reply/' . $thread['thread_id'] . '">Reply</a>';

  $output .= '</div>';

  $field = array(
    'data' => $output,
    'class' => 'privatemsg-list-issue',
  );
  return $field;
}

/**
 * Theme the subject of the thread.
 */
function theme_privatemsg_list_field__name($variables) {
  $subject = '';

  if (is_numeric(arg(1))) {
    $account = user_load(arg(1));
  }
  elseif (!empty($variables['thread']['dash_uid']) && is_numeric($variables['thread']['dash_uid'])) {
    $account = user_load($variables['thread']['dash_uid']);
  }

  $thread = $variables['thread'];

  $field = array();
  $options = array();
  $is_new = '';
  if (!empty($thread['is_new'])) {
    $is_new = theme('mark', array('type' => MARK_NEW));
  }

  if ($thread['has_tokens']) {
    $message = privatemsg_message_load($thread['thread_id']);
    $subject = privatemsg_token_replace($subject, array('privatemsg_message' => $message), array('sanitize' => TRUE, 'privatemsg-show-span' => FALSE));
  }

  if (!empty($_GET['messagesearch'])) {
    $vars = array(':thread_id' => $thread['thread_id'], ':searchterm' => '%' . $_GET['messagesearch'] . '%');
    $query = 'SELECT MAX(pm.mid) from pm_message pm JOIN pm_index pmi ON pm.mid = pmi.mid WHERE pmi.thread_id = :thread_id AND CONCAT(pm.subject, pm.body) LIKE :searchterm';
    $most_recent_message_mid = db_query($query, $vars)->fetchField();

  }
  else {
    $params = array(
      ":thread_id" => $thread['thread_id'],
      ":inbox_user" => $account->uid,
    );

    if (isset($_GET['sent']) && $_GET['sent'] == 1) {
      $query = 'SELECT MAX(pmi.mid) FROM pm_index pmi JOIN pm_message pm ON pm.mid = pmi.mid WHERE pmi.thread_id = :thread_id AND pm.author = :inbox_user;';
      $most_recent_message_mid = (int) db_query($query, $params)->fetchField();
    }
    else {
      $query = 'SELECT MAX(pmi.mid) FROM pm_index pmi JOIN pm_message pm ON pm.mid = pmi.mid WHERE pmi.thread_id = :thread_id AND pm.author != :inbox_user;';
      $most_recent_message_mid = (int) db_query($query, $params)->fetchField();
    }
  }
  $message = privatemsg_message_load($most_recent_message_mid);

  $message_body = check_markup($message->body, $message->format);
  $message_preview = truncate_utf8(strip_tags($message_body), 50, TRUE, TRUE);

  if (!empty($_GET['messagesearch'])) {
    $message_body = str_replace($_GET['messagesearch'], '<span class="messagesearch-highlight">' . $_GET['messagesearch'] . '</span>', $message_body);
  }

  if (!empty($_GET['messagesearch'])) {
    $message_preview = str_replace($_GET['messagesearch'], '<span class="messagesearch-highlight">' . $_GET['messagesearch'] . '</span>', $message_preview);
  }

  $author_themed = theme('nys_dashboard_user_link', array('uid' => $message->author->uid));

  $participants_themed = '<div class="privatemsg-author-name">' . $author_themed . '</div>';

  $options += array('html' => TRUE);
  $message_preview = l($message_preview, 'user/' . $account->uid . '/dashboard/inbox/reply/' . $thread['thread_id'], $options) . $is_new;

  $thread_preview = '<div id="message-preview-' . $thread['thread_id'] . '" class="message-preview visible">' . $message_preview . '</div>';
  $thread_body = '<div id="message-body-' . $thread['thread_id'] . '" class="message-body">' . $message_body;

  $thread_body .= '</div>';

  $field['data'] = $participants_themed . $subject . $thread_preview . $thread_body;
  $field['class'][] = 'privatemsg-message-information';
  return $field;
}


/**
 * Used to theme and display user recipients.
 *
 * Wrapper for theme_username() with a few additional options.
 */
function theme_nys_inbox_username($variables) {
  $recipient = $variables['recipient'];
  $options = $variables['options'];
  if (!isset($recipient->uid)) {
    $recipient->uid = $recipient->recipient;
  }
  if (!empty($options['plain'])) {
    $name = 'test'; $name = strip_tags(theme('nys_dashboard_user_link', array('uid' => $recipient->uid)));
    if (!empty($options['unique'])) {
      $name .= ' [user]';
    }
    return $name;
  }
  else {
    return theme('nys_dashboard_user_link', array('uid' => $recipient->uid));
  }
}

/**
 * Themes the inbox district.
 *
 * @var $variables
 *
 * @return string
 *   Themed output.
 */
function theme_nys_inbox_district($variables) {
  if (!isset($variables['thread']['district'])) {
    return array();
  }

  $district = $variables['thread']['district'];

  $field['class'][] = 'privatemsg-list-district';
  if (isset($variables['thread']['in_district']) && $variables['thread']['in_district']) {
    $field['class'][] = 'marker';
  }

  $field['data'] = $district;

  return $field;
}
