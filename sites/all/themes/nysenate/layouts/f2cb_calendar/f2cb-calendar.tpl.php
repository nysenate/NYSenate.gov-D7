<?php
/**
 * @file
 * Template for a 2 column panel layout.
 *
 * This template provides a two column panel display layout, with
 * each column roughly equal in width. It is 5 rows high; the top
 * middle and bottom rows contain 1 column, while the second
 * and fourth rows contain 2 columns.
 *
 * Variables:
 * - $id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   - $content['top']: Content in the top row.
 *   - $content['above_left']: Content in the left column in row 2.
 *   - $content['above_right']: Content in the right column in row 2.
 *   - $content['middle']: Content in the middle row.
 *   - $content['below_left']: Content in the left column in row 4.
 *   - $content['below_right']: Content in the right column in row 4.
 *   - $content['right']: Content in the right column.
 *   - $content['bottom']: Content in the bottom row.
 */
?>
<?php !empty($css_id) ? print '<div id="' . $css_id . '">' : ''; ?>
  <h2 class="nys-title--events nys-title">Events</h2>
  <div class="l-row">
    <?php print $content['top']; ?>
  </div><!-- .row -->

  <div class="l-row c-calendar--today">
    <h3 class="nys-title"><?php if($content['today']):?>Today, <?php print date("M jS");?><?php endif; ?></h3>
    <?php print $content['today']; ?>
  </div><!-- .row -->

  <div class="l-row c-calendar--upcoming">
    <div id='ajax-response-goes-here'>
      <?php

      $current_date = date_create();
      $next_date = date_create();
      date_add($next_date, date_interval_create_from_date_string('1 month'));
      $prev_date = date_create();
      date_add($prev_date, date_interval_create_from_date_string('-1 month'));

      $link2 = array(
          '#type' => 'link',
          '#title' => t($prev_date->format("F")),
          '#href' => 'get/ajax/events/'.$current_date->format("Y-m").'/previous/'.$display->args[0],
          '#ajax' => array(
            'effect' => 'fade',
            'progress' => array(
              'message' => '',
              ),
          ),
          '#options' => array(
            'attributes' => array('class' => 'c-upcoming--nav-item'),
          'html' => FALSE,
           ),        
        );

        $link = array(
          '#type' => 'link',
          '#title' => t($next_date->format("F")),
          '#href' => 'get/ajax/events/'.$current_date->format("Y-m").'/next/'.$display->args[0],
          '#ajax' => array(
            'effect' => 'fade',
            'progress' => array(
              'message' => '',
              ),
          ),
          '#options' => array(
            'attributes' => array('class' => 'c-upcoming--nav-item'),
          'html' => FALSE,
           ),
        );

        $view = views_get_view('senator_events');
        $view->set_arguments(array($display->args[0],$current_date->format("Y-m")));
        $table1= $view->render('upcoming_events');

        $view1 = views_get_view('senator_events');
        $view1->set_arguments(array($display->args[0],$current_date->format("Y-m")));
        $table2= $view1->render('senator_upcoming_albany');

        $view2 = views_get_view('senator_events');
        $view2->set_arguments(array($display->args[0],$current_date->format("Y-m")));
        $table3= $view2->render('senator_upcoming_district');

      ?>

      <div class="c-upcoming--header" id="tab_top_bar">
        <h3 class='c-month-title'><?php print $current_date->format("F Y"); ?></h3>
        <div class="c-upcoming--nav">
          <?php print drupal_render($link2).drupal_render($link); ?>
        </div>
      </div>

      <dl class="l-tab-bar" data-tab>
        <div class="c-tab--arrow u-mobile-only"></div>
        <dd class="c-tab active"><a class="c-tab-link first" href="#panel1">All Events</a></dd>
        <dd class="c-tab"><a class="c-tab-link" href="#panel2">In Albany</a></dd>
        <dd class="c-tab"><a class="c-tab-link" href="#panel3">In the District</a></dd>
      </dl><!-- .l-tab-bar -->


      <div class="tabs-content">
        <div class='content active' id='panel1'>
          <div id="wrapper1">
            <?php print $table1; ?>
          </div>
        </div>
        <div class='content' id='panel2'>
          <div id="wrapper2">
            <?php print $table2; ?>
          </div>
        </div>
        <div class='content' id='panel3'>
          <div id="wrapper3">
            <?php print $table3; ?>
          </div>
        </div>
      </div><!-- .tabs-content -->

    </div><!-- #ajax-response-goes-here -->
  </div><!-- .l-row -->

  <div class="row">
    <div class="large-12 columns"><?php print $content['bottom']; ?></div>
  </div>
<?php !empty($css_id) ? print '</div>' : ''; ?>
