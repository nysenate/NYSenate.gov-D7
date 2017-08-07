<?php

/**
 * @file
 * The login history page-related code.
 */

/**
 * Page callback for the login history page.
 *
 * @param object $account
 *   Optional user object.
 *
 * @return string
 *   A string of html to be printed.
 */
function login_history_report_callback($account = NULL) {
  if (empty($account->uid) && !user_access('view all login histories')) {
    // This should never happen, but be cautious in case calling code is weak.
    global $user;
    $account = $user;
  }
  $header = array(
    array('data' => t('Date'), 'field' => 'lh.login', 'sort' => 'desc'),
    array('data' => t('Username'), 'field' => 'u.name'),
    array('data' => t('IP Address'), 'field' => 'lh.hostname'),
    array('data' => t('One-time login?'), 'field' => 'lh.one_time'),
    array('data' => t('User Agent')),
  );

  $query = db_select('login_history', 'lh')->extend('TableSort')->extend('PagerDefault');
  $query->join('users', 'u', 'lh.uid = u.uid');

  if ($account) {
    $query->condition('lh.uid', $account->uid);
  }

  $result = $query
    ->fields('lh')
    ->fields('u', array('name'))
    ->orderByHeader($header)
    ->limit(50)
    ->execute()
    ->fetchAll();

  return login_history_output($result, 'table', $header);
}

/**
 * Render login histories.
 *
 * @todo Add XML output format.
 *
 * @param array $history
 *   A list of login history objects to output.
 * @param string $format
 *   Optional format to output log entries in; 'table', 'list', or 'text'.
 * @param array $header
 *   Optional An array containing header data for $format 'table'.
 *
 * @return array|string
 *   A render array by default (for table) but a string in other cases.
 */
function login_history_output(array $history, $format = 'table', array $header = array()) {
  switch ($format) {
    case 'text':
      // Output delimiter in first line, since this may change.
      $output = '\t' . "\n";

      foreach ($history as $entry) {
        $row = array(
          format_date($entry->login, 'small'),
          check_plain(format_username($entry->uid)),
          check_plain($entry->hostname),
          empty($entry->one_time) ? t('Regular login') : t('One-time login'),
          check_plain($entry->user_agent),
        );
        $output .= implode("\t", $row) . "\n";
      }
      break;

    case 'list':
      $output = '';
      foreach ($history as $entry) {
        $one_time = empty($entry->one_time) ? t('Regular login') : t('One-time login');
        $output .= '<li>';
        $output .= '<span class="login-history-info">' . check_plain(format_username($entry)) . ' ' . format_date($entry->login, 'small') . ' ' . check_plain($entry->hostname) . ' ' . $one_time . ' ' . check_plain($entry->user_agent) . '</span>';
        $output .= '</li>';
      }
      if ($output) {
        $output = '<ul id="login-history-backlog">' . $output . '</ul>';
      }
      break;

    case 'table':
    default:
      $rows = array();
      foreach ($history as $entry) {
        $rows[] = array(
          format_date($entry->login, 'small'),
          check_plain(format_username($entry)),
          check_plain($entry->hostname),
          empty($entry->one_time) ? t('Regular login') : t('One-time login'),
          check_plain($entry->user_agent),
        );
      }
      $output['history'] = array(
        '#theme' => 'table',
        '#header' => $header,
        '#rows' => $rows,
        '#empty' => t('No login history available.'),
      );
      $output['pager'] = array(
        '#theme' => 'pager',
      );
      break;
  }

  return $output;
}
