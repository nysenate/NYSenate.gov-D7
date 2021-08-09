<?php

/**
 * @file
 * Hooks provided by the NYS Bill Notifications module.
 */

/**
 * @defgroup nys_subscriptions_api_hooks NYS Bill Subscriptions API Hooks
 * @{
 * Used to hook into subscription creation and handling.
 *
 * @}
 */

/**
 * hook_nys_subscriptions_queue_list()
 *
 * Define a notification queue name, with associated meta data.  The
 * queue name must be globally unique to avoid collisions.
 *
 * Meta data keys understood by the subscription system:
 *
 * #priority
 *   Informs the order in which a queue will be processed if called
 *   in a batch.  Lower numbers are processed first.  Default is 0.
 *
 * #subject
 *   Sets a default subject line for emails sent on behalf of this
 *   queue.  This subject may be overwritten during later processing.
 *
 * @return array An array of test definitions, keyed by test name.
 */
function hook_nys_subscriptions_queue_list() {
  return [
    'my_subscription_queue' => [
      '#subject' => 'A default subject line for my subscriptions',
      '#priority' => 0,
    ],
  ];
}

/**
 * hook_queueitem_reference_<queue_name>_alter()
 *
 * Allows for modules to load their own references during the processing of
 * a subscription queue item.
 *
 * References can be any data point, array, or object.  New reference keys
 * should be globally unique.  Note that $item will always have three
 * references already available when this hook execute:
 *
 *  node: The node object through which the user subscribed.
 *  source: The taxonomy term object to which the user subscribed.
 *  source_vocabulary: The taxonomy vocabulary object which owns the source.
 *
 * @param \NYSSubscriptionQueueItem $item A queue item.
 */
function hook_queueitem_reference_my_subscription_queue_alter($item) {
  // Add the node reference as an EMW object.
  $item->references['node_emw'] = entity_metadata_wrapper('node', $item->references['node']);
}

/**
 * hook_queueitem_item_tokens_<queue_name>_alter()
 *
 * Allows for modules to add or modify item tokens for a queue item, e.g.,
 * a bill's print number or session year, the template ID to use, etc.  Item
 * tokens are used for every subscriber, and should target the 'common' index
 * of the item's substitution array.
 *
 * If any implementation throws an Exception/Throwable, the queue item will
 * be marked to "fail" sending, but processing will continue.
 *
 * @param \NYSSubscriptionQueueItem $item The queue item
 *
 * @throws \Throwable
 */
function hook_queueitem_item_tokens_my_subscription_queue_alter($item) {
  // Set the template ID to use
  $item->substitutions['common']['template_id'] = 'sendgrid template id';

  // Set a global substitution for the governor's name
  $item->substitutions['common']['%governor.full_name%'] = variable_get('governor_full_name');
}

/**
 * hook_queueitem_user_tokens_<queue_name>_alter()
 *
 * Allows for modules to add or modify user tokens for a queue item's
 * subscribers.  Tokens should be prepared as Personalization objects,
 * and added to the 'subscribers' index of the item's substitution
 * array.
 *
 * If any implementation throws an Exception/Throwable, the queue item will
 * be marked to "fail" sending, but processing will continue.
 *
 * @param \NYSSubscriptionQueueItem $item
 *
 * @throws \Throwable
 */
function hook_queueitem_user_tokens_my_subscription_queue_alter($item) {
  // Add each user's name as a personalization
  $subs = $item->data['recipients'] ?? [];
  foreach ($subs as $sub_key => $one_sub) {
    // Create a personalization for this subscriber.
    $person = new \SendGrid\Mail\Personalization();
    $user = user_load($one_sub->uid);
    $person->addSubstitution("%user.name%", $user->name);
    $item->substitutions['subscribers'][] = $person;
  }
}

/**
 * @} End of "addtogroup hooks".
 */
