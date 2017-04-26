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
    foreach ($frontend_statuses as $index => $frontend_status):
        if ($index == 3) {
            print "<li class='nys-bill-status--assem-sen'><ul class='nys-bill-status'>";
        }
        elseif($index == 5) {
            print "</ul></li>";
        }
        $passed = "";
        if (($frontend_status['value'] != 3) && ($frontend_status['value'] <= $current_status_value)) {
            $passed = 'class="passed"';
        }
        else if ($frontend_status['value'] == 3) {
          // A higher $current_status_value means it's already passed both chambers
          if ($current_status_value > 3) {
            $passed = 'class="passed"';
          }
          else if ($chamber == 'senate' && $current_status == 'PASSED_ASSEMBLY') {
            $passed = 'class="passed"';
          }
          else if ($chamber == 'assembly' && $current_status == 'PASSED_SENATE') {
            $passed = 'class="passed"';
          }
          else {
            if ($chamber == 'senate' && $current_status == 'PASSED_SENATE' && $frontend_status['type'] == 'senate') {
              $passed = 'class="passed"';
            }
            else if ($chamber == 'assembly' && $current_status == 'PASSED_ASSEMBLY' && $frontend_status['type'] == 'assembly') {
              $passed = 'class="passed"';
            }
            else {
              $passed = '';
            }
          }
        }
        ?>
        <li <?php print $passed; ?>>
            <span class="nys-bill-status--text"><?php print  $frontend_status["name"]; ?></span>
        </li>
    <?php endforeach; ?>
    <?php if ($add_spacer): print '<li class="spacer"></li>'; endif; ?>
</ul>
