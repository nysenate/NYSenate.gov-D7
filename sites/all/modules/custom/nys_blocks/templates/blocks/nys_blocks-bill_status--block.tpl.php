<?php
/**
 * @file Template for Bill Actions.
 *
 * @var string $title
 *   The block title.
 * @var array $content
 *   The block content.
 *   The status block will have the following keys:
 *   - string class_list
 *   - array frontend_statuses
 *   - string display_status
 *   - string passed
 *
 */
?>
<ul class="nys-bill-status <?php print $draw_classes; ?>">
  <hr />
  <?php
  foreach ($frontend_statuses as $index => $item) {
    if ($index == 3) {
      print '<li class="nys-bill-status--assem-sen"><ul class="nys-bill-status">';
      foreach (['senate','assembly'] as $chamber) {
        $passed = ($item[$chamber]['passed']) ? ' class="passed"' : '';
        print '<li' . $passed . ' title="' . $item[$chamber]['display'] . '">';
        print '<span class="nys-bill-status--text">';
        print $item[$chamber]['display'] . '</span></li>';
      }
      print '</ul></li> ';
    }
    else {
      $passed = ($item['passed']) ? ' class="passed"' : '';
      print "<li{$passed} title=\"{$item['display']}\">";
      print "<span class=\"nys-bill-status--text\">{$item['display']}</span>";
      print "</li> ";
    }
  }
?>
  <li class="spacer"></li>
</ul>
