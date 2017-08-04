<?php foreach ($fields as $id => $field): ?>
    <?php if($id == 'field_session_calendars') $data['calendar_ids'] = $field->content; ?>
<?php endforeach; ?>

<?php
$ids = explode(',', $data['calendar_ids']);
foreach($ids as $calendar_id) {
	$calendar = node_load(trim($calendar_id));
	foreach($calendar->field_agenda_bills[LANGUAGE_NONE] as $bill) {
		$bill_ids[] = $bill['target_id'];
	}
}

print_r(implode(',', $bill_ids));
?>