<?php
if (empty($current_status)):
  $current_status = '';
endif;

if ($title):
  // Grab the print no and session year to construct the path.
  $base_print_no = !empty($field_ol_base_print_no[LANGUAGE_NONE][0]['value'])
    ? $field_ol_base_print_no[LANGUAGE_NONE][0]['value']
    : NULL;
  $session_year = !empty($field_ol_session[0]['value'])
    ? $field_ol_session[0]['value']
    : NULL;

  // Check to see if user searched explicitly for an amended version.
  if (!empty($_GET['q'])):
    $search = array_pop(explode('/', filter_xss($_GET['q'])));
  endif;
  if (!empty($search) && strtolower($search) == strtolower($title)):
    $base_print_no = $title;
  endif;

  // Create path from session year and print no, otherwise use drupal_get_path().
  if (!empty($base_print_no) && is_numeric($session_year)):
    $path = 'legislation/bills/' . $session_year . '/' . $base_print_no;
  elseif (!empty($node->nid)):
    $path = drupal_get_path_alias('node/' . $node->nid);
  endif;
  ?>
    <div class="c-block c-list-item c-legislation-block">
        <div class="c-bill-meta">
            <h3 class="c-bill-num">
                <a href="/<?php echo $path; ?>"
                   title="<?php echo $title; ?>">Bill <?php echo $title; ?></a>
            </h3>
            <h4 class="c-bill-topic"><?php echo render($content['field_issues']); ?></h4>
        </div>
        <div class="c-bill-body">
            <p class="c-bill-descript"><a
                        href="/<?php echo $path; ?>"><?php echo render($content['field_ol_name']); ?></a>
            </p>
          <?php echo $variables['graph_html']; ?>
            <div class="c-bill-update">
                <p class="c-bill-update--date">
                  <?php echo render($content['field_ol_last_status_date']); ?>
                  <?php
                  if (isset($content['field_ol_session']) && ($node->field_ol_session[LANGUAGE_NONE][0]['value'] == date('Y'))
                    || ($node->field_ol_last_status[LANGUAGE_NONE][0]['value'] == 'SIGNED_BY_GOV' || $node->field_ol_last_status[LANGUAGE_NONE][0]['value'] == 'VETOED')):
                    echo '&nbsp;&nbsp;|&nbsp;&nbsp;' . $bill_display_status;
                  endif; ?>
                </p>
              <?php if (!empty($node->field_ol_sponsor[LANGUAGE_NONE][0]['target_id'])): ?>
                  <p class="c-bill-update--sponsor">
                      Sponsor: <?php echo render($content['field_ol_sponsor']); ?>
                  </p>
              <?php endif; ?>
              <?php if (
                !empty($node->field_ol_sponsor_name[LANGUAGE_NONE][0]['value'])
                && !empty($node->field_ol_sponsor[LANGUAGE_NONE][0]['target_id'])
              ): ?>
              <?php endif; ?>
            </div>
        </div>
    </div>
<?php endif; ?>