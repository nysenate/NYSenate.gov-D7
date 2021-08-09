<?php

/**
 * @file
 * Include file for the NYS SendGrid module.
 *
 * Provides additional utility functions.
 */

/**
 * A wrapper around NYSSendGridMailSystem::get_sg_client().
 *
 * @param array $options
 *
 * @return bool|\SendGrid
 */
function nys_sendgrid_instantiate_client(Array $options = []) {
  return NYSSendGridMailSystem::get_sg_client($options);
}

/**
 * A wrapper around nys_utils_send_slack_notification().
 * TODO: This should move into a dedicated module for Slack.
 *
 * @param array $fields
 * @param string $title
 * @param string $message
 */
function nys_sendgrid_report_to_slack($fields = [], $title = '', $message = '') {
  $title = $title ?: "Call to SendGrid API was not successful!";
  $message = $message ?: "The NYS Sendgrid module initiated a call to the " .
    "SendGrid API, but did not receive a success result code.";
  $f = [];
  foreach ($fields as $key => $val) {
    $f[] = ['title' => $key, 'value' => var_export($val, 1), 'short' => FALSE];
  }

  nys_utils_send_slack_notification($message, $f, NULL, $title);
}

/**
 * Calls the SendGrid API for a list of all available templates.
 *
 * @param bool $refresh TRUE to force a new call.
 *
 * @return array In the form ['template title' => 'template id', ...]
 */
function nys_sendgrid_get_templates($refresh = FALSE) {
  static $all_templates = [];

  // If templates are not populated yet, populate them from an API call.
  if (!count($all_templates) || $refresh) {
    if ($sg = nys_sendgrid_instantiate_client()) {
      $response = $sg->client->templates()
        ->get(NULL, ['generations' => 'legacy,dynamic']);

      // If the call is good, parse the return.  Otherwise, report the failure.
      if ($response->statusCode() == '200') {
        $templates = json_decode($response->body())->templates;
        foreach ($templates as $key => $val) {
          $all_templates[$val->id] = [
            'name' => $val->name,
            'generation' => $val->generation,
          ];
        }
      }
      else {
        // The call to SG failed.  Report.
        $fields = [
          'status' => $response->statusCode(),
          'body' => $response->body(),
          'headers' => $response->headers(),
        ];
        nys_sendgrid_report_to_slack(
          $fields,
          'Call to SendGrid templates() failed',
          "A call to SendGrid API to enumerate available templates has failed."
        );
      }
    }
  }

  // Return the templates
  return $all_templates;
}

/**
 * Detects if a template is part of a specific generation.  Allowed
 * generations, per SendGrid docs, are "legacy" and "dynamic".
 *
 * @param string $id  The ID of the template.
 * @param string $generation  The generation to test against.
 *
 * @return null|boolean Returns NULL if generation is invalid, or if the
 *   template is not found/has no generation marker.  Otherwise, boolean.
 */
function nys_sendgrid_check_template_generation($id, $generation) {
  // If $id is not populated, or if generation is not valid, return NULL.
  if (!(in_array($generation, ['legacy', 'dynamic']) && $id)) {
    return NULL;
  }

  // Get the templates from SendGrid.
  $all_templates = nys_sendgrid_get_templates();
  // Check for the passed ID.
  $this_template = $all_templates[$id] ?? [];
  // Detect the generation for the targeted template.
  $this_generation = $this_template['generation'] ?? FALSE;

  return $this_generation ? ($this_generation == $generation) : NULL;
}

/**
 * Wrapper around nys_sendgrid_check_template_generation() for dynamic templates.
 * @see nys_sendgrid_check_template_generation()
 *
 * @param string $id The ID of the template.
 *
 * @return null|boolean
 */
function nys_sendgrid_is_template_dynamic($id) {
  return nys_sendgrid_check_template_generation($id, 'dynamic');
}

/**
 * Wrapper around nys_sendgrid_check_template_generation() for legacy templates.
 * @see nys_sendgrid_check_template_generation()
 *
 * @param string $id The ID of the template.
 *
 * @return null|boolean
 */
function nys_sendgrid_is_template_legacy($id) {
  return nys_sendgrid_check_template_generation($id, 'legacy');
}
