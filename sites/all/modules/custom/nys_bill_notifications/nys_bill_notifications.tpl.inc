<?php
/**
 * @file
 * nys_bill_notifications.tpl.
 * 
 * Provides formatting functions for the title/headline of bill
 * update events.  Each function implements hook_ol_update_format_<name>.
 * 
 * @see hook_ol_update_format_<name>()
 */

/**
 * Implements hook_ol_update_format_<name>().
 *
 * @param $item object An OpenLeg update block as JSON object
 *
 * @return string
 */
function nys_bill_notifications_ol_update_format_in_senate_comm($item) {
  $comm = ucwords(strtolower($item->fields->{'Committee Name'}));
  return "Bill " . $item->id->basePrintNoStr . " was referred to " .
    $comm . " Senate committee.";
}

/**
 * Implements hook_ol_update_format_<name>().
 *
 * @param $item object An OpenLeg update block as JSON object
 *
 * @return string
 */
function nys_bill_notifications_ol_update_format_in_assembly_comm($item) {
  $comm = ucwords(strtolower($item->fields->{'Committee Name'}));
  return "Bill " . $item->id->basePrintNoStr . " was referred to " .
    $comm . " Assembly committee.";
}

/**
 * Implements hook_ol_update_format_<name>().
 *
 * @param $item object An OpenLeg update block as JSON object
 *
 * @return string
 */
function nys_bill_notifications_ol_update_format_new_same_as($item) {
  $same_as = $item->fields->{'Same As Session Year'} . '-' .
    $item->fields->{'Same As Bill Print No'};
  if (trim($item->fields->{'Same As Amend Version'})) {
    $same_as .= $item->fields->{'Same As Amend Version'};
  }
  return $item->id->basePrintNoStr . " has a new Same As bill: $same_as";
}

/**
 * Implements hook_ol_update_format_<name>().
 *
 * @param $item object An OpenLeg update block as JSON object
 *
 * @return string
 */
function nys_bill_notifications_ol_update_format_new_prev_ver($item) {
  $prev = $item->fields->{'Prev Bill Session Year'} . '-' .
    $item->fields->{'Prev Bill Print No'};
  if (trim($item->fields->{'Prev Amend Version'})) {
    $prev .= $item->fields->{'Prev Amend Version'};
  }
  return "Bill " . $item->id->basePrintNoStr . " was assigned $prev as a previous version.";
}

/**
 * Implements hook_ol_update_format_<name>().
 *
 * @param $item object An OpenLeg update block as JSON object
 *
 * @return string
 */
function nys_bill_notifications_ol_update_format_remove_prev_ver($item) {
  $prev = $item->fields->{'Prev Bill Session Year'} . '-' .
    $item->fields->{'Prev Bill Print No'};
  if (trim($item->fields->{'Prev Amend Version'})) {
    $prev .= $item->fields->{'Prev Amend Version'};
  }
  return "Bill " . $item->id->basePrintNoStr . " had $prev removed as a previous version.";
}

/**
 * Implements hook_ol_update_format_<name>().
 *
 * @param $item object An OpenLeg update block as JSON object
 *
 * @return string
 */
function nys_bill_notifications_ol_update_format_new_active_ver($item) {
  $amend = trim($item->fields->{'Active Version'});
  $amend = ($amend) ? "amendment $amend" : "the original version";
  return "Bill " . $item->id->basePrintNoStr . "'s active version is now $amend.";
}

/**
 * Implements hook_ol_update_format_<name>().
 *
 * @param $item object An OpenLeg update block as JSON object
 *
 * @return string
 */
function nys_bill_notifications_ol_update_format_new_amendment($item) {
  $amend = trim($item->fields->{'Bill Amend Version'});
  $amend = ($amend) ? "amendment $amend" : "the original version";
  return "Bill " . $item->id->basePrintNoStr . " has a new amendment ($amend).";
}

/**
 * Implements hook_ol_update_format_<name>().
 *
 * @param $item object An OpenLeg update block as JSON object
 *
 * @return string
 */
function nys_bill_notifications_ol_update_format_passed_assembly($item) {
  return "Bill " . $item->id->basePrintNoStr . " has passed the Assembly.";
}

/**
 * Implements hook_ol_update_format_<name>().
 *
 * @param $item object An OpenLeg update block as JSON object
 *
 * @return string
 */
function nys_bill_notifications_ol_update_format_passed_senate($item) {
  return "Bill " . $item->id->basePrintNoStr . " has passed the Senate.";
}

/**
 * Implements hook_ol_update_format_<name>().
 *
 * @param $item object An OpenLeg update block as JSON object
 *
 * @return string
 */
function nys_bill_notifications_ol_update_format_senate_floor($item) {
  return "Bill " . $item->id->basePrintNoStr . " has gone to the Senate Floor.";
}

/**
 * Implements hook_ol_update_format_<name>().
 *
 * @param $item object An OpenLeg update block as JSON object
 *
 * @return string
 */
function nys_bill_notifications_ol_update_format_assembly_floor($item) {
  return "Bill " . $item->id->basePrintNoStr . " has gone to the Assembly Floor.";
}

/**
 * Implements hook_ol_update_format_<name>().
 *
 * @param $item object An OpenLeg update block as JSON object
 *
 * @return string
 */
function nys_bill_notifications_ol_update_format_delivered_to_gov($item) {
  return "Bill " . $item->id->basePrintNoStr . " has been delivered to the Governor.";
}

/**
 * Implements hook_ol_update_format_<name>().
 *
 * @param $item object An OpenLeg update block as JSON object
 *
 * @return string
 */
function nys_bill_notifications_ol_update_format_signed_by_gov($item) {
  return "Bill " . $item->id->basePrintNoStr . " has been signed by the Governor.";
}

/**
 * Implements hook_ol_update_format_<name>().
 *
 * @param $item object An OpenLeg update block as JSON object
 *
 * @return string
 */
function nys_bill_notifications_ol_update_format_vetoed($item) {
  return "Bill " . $item->id->basePrintNoStr . " has been vetoed.";
}

/**
 * Implements hook_ol_update_format_<name>().
 *
 * @param $item object An OpenLeg update block as JSON object
 *
 * @return string
 */
function nys_bill_notifications_ol_update_format_adopted($item) {
  return "Bill " . $item->id->basePrintNoStr . " has been adopted.";
}

/**
 * Implements hook_ol_update_format_<name>().
 *
 * @param $item object An OpenLeg update block as JSON object
 *
 * @return string
 */
function nys_bill_notifications_ol_update_format_substitute_for($item) {
  $pn = str_replace('SUBSTITUTED FOR ', '', $item->fields->Text);
  return $item->id->basePrintNoStr . " was substituted for $pn.";
}

/**
 * Implements hook_ol_update_format_<name>().
 *
 * @param $item object An OpenLeg update block as JSON object
 *
 * @return string
 */
function nys_bill_notifications_ol_update_format_substitute_by($item) {
  $pn = str_replace('SUBSTITUTED BY ', '', $item->fields->Text);
  return "Bill " . $item->id->basePrintNoStr . " was substituted by $pn.";
}

/**
 * Implements hook_ol_update_format_<name>().
 *
 * @param $item object An OpenLeg update block as JSON object
 *
 * @return string
 */
function nys_bill_notifications_ol_update_committee_vote($item) {
  $pn = $item->fields->{'Committee Name'};
  return "Bill " . $item->id->basePrintNoStr . " came up for voting in the " .
    "$pn committee.";
}

/**
 * Implements hook_ol_update_format_<name>().
 *
 * @param $item object An OpenLeg update block as JSON object
 *
 * @return string
 */
function nys_bill_notifications_ol_update_floor_vote($item) {
  return "Bill " . $item->id->basePrintNoStr . " came up for voting on the floor.";
}
