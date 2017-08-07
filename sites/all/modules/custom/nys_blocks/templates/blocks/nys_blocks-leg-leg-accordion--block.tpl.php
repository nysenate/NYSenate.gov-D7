<!-- floor_calendar Content -->
<?php 
$session = nodequeue_load_nodes(4); 
// Get current nodeque.
$session_node = current($session);
if (is_object($session_node)) {
  $session_nid = $session_node->nid;
}
else {
  $session_nid = 0;
}
?>
<?php
$view1 = views_get_view('upcoming_legislation_calendar');
if(!empty($view1)) {
  $view1->set_display('sess_floor_calendar');
  $view1->set_arguments(array($session_nid));
  $view1->pre_execute();
  $view1->execute();
}

if($view1->result != NULL) : ?>
<div class="nys-accordion--header">
  <h3 class="nys-accordion--title c-legis--accord-title">Upcoming Legislative Calendars</h3>
</div>
<?php print $view1->render(); endif; ?>
<!-- end floor calendar -->

<!-- active_list Content -->
<?php
$view2 = views_get_view('upcoming_legislation_calendar');
if(!empty($view2)) {
  $view2->set_display('sess_active_list_content');
  $view2->set_arguments(array($session_nid));
  $view2->pre_execute();
  $view2->execute();
}
if($view2->result != NULL) : ?>
<?php if($view1->result == NULL && $view2->result != NULL): ?>
<div class="nys-accordion--header">
  <h3 class="nys-accordion--title c-legis--accord-title">Upcoming Legislative Calendars</h3>
</div>
<?php endif; ?>

<?php print $view2->render(); endif; ?>
<!-- end active_list Content -->

<!-- supplemental_calendar Content -->
<?php
$view3 = views_get_view('upcoming_legislation_calendar');
if(!empty($view3)) {
  $view3->set_display('sess_supplemental_calendar');
  $view3->pre_execute();
  $view3->set_arguments(array($session_nid));
  $view3->execute();
}

if($view3->result != NULL) : ?>
<?php if(($view1->result == NULL || $view2->result == NULL) && $view3->result != NULL): ?>
<div class="nys-accordion--header">
  <h3 class="nys-accordion--title c-legis--accord-title">Upcoming Legislative Calendars</h3>
</div>
<?php endif; ?>
<?php print $view3->render(); endif; ?>
<!-- end supplemental_calendar Content -->
