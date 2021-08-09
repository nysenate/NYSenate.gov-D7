<?php
use NYS_Looker_Integration\ScheduledPlan;

/**
 * Helper function to prepare a form submission for saving on Looker.
 *
 * @param $form_state array A Drupal form_state array.
 *
 * @return ScheduledPlan
 */
function nys_looker_integration_save_plan($form_state) {
  // Ensure we have a reference to the senator node.
  $entity = $form_state['values']['entity'];
  if (!isset($entity->senator)) {
    $entity->senator = $form_state['values']['senator'];
  }

  // Instantiate the plan and add the recipients.
  $plan = new ScheduledPlan($entity);
  $new_recipients = [];
  foreach ($form_state['values']['looker_recipient_list']['und'] as $key => $val) {
    if (is_numeric($key) && !empty($val['email'])) {
      $new_recipients[] = $val['email'];
    }
  }
  $plan->addRecipients($new_recipients, TRUE);
  $plan->title = $plan->generateTitle($entity->type, $entity->senator);

  // Save it
  $plan->saveToLooker();

  // Inform the entity of the new plan ID, if there is one.
  $entity->plan_id = (int) ($plan->plan_id ?: 0);

  return $plan;
}
