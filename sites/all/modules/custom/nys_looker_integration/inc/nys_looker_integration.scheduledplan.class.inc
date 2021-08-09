<?php
/**
 * @file nys_looker_integration.scheduledplan.class.inc
 */

namespace NYS_Looker_Integration;


use SendGrid\Client;

/**
 * Class ScheduledPlan
 *
 * Represents a bridge between Drupal and Looker for managing a scheduled
 * plan.  It can be instantiated empty, or initialized via an ECK Bundle
 * or an API call to Looker.  The primary function is to create or update
 * a scheduled plan through Looker's API.  It is concerned only with a
 * subset of available API fields.
 *
 * The minimum requirement for looker to create:
 * {
 *  "name": "TEST REPORT",
 *  "dashboard_id": 28,
 *  "crontab" : "0 6 * * *",
 *  "scheduled_plan_destination": [
 *    {
 *      "address": "blaggity@blah.com",
 *      "looker_recipient": false,
 *      "type": "email",
 *      "format": "wysiwyg_pdf"
 *    }
 *  ]
 * }
 *
 * Additionally, id and filters_string are used.
 *
 *   id:
 *   The Looker Scheduled Plan ID.  This will only be populated if
 *   the class is initialized via API call or Entity, or on successful
 *   writing a new plan to Looker.
 *
 *   name:
 *   This is exposed in the email's subject line.  The generateTitle()
 *   method will construct a standard-format title if given a Bundle
 *   object and senator's node id.
 *
 *   dashboard_id:
 *   The Looker Dashboard ID.  Can be populated via a Bundle, or from
 *   an existing plan's settings.
 *
 *   crontab:
 *   A standard crontab-formatted string indicating the schedule on
 *   which the email is sent out.  This class manages the value of
 *   this field, with the possible keys of "daily" or "weekly".
 *
 *   filters_string:
 *   A string used as the query string portion of the API call's URL,
 *   including the '?' prefix.  This class manages the construction of
 *   this value with the getFilterString() method.  See the setFilter(),
 *   getFilter(), and clearFilter() methods.
 *
 *   scheduled_plan_destination:
 *   An array of destination objects.  This class manages the construction
 *   of this value, and all destinations will be *overwritten* when a plan
 *   is saved.  See the getRecipients() and addRecipients() methods.
 *
 * @see https://docs.looker.com/reference/api-and-integration/api-reference/v3.1/scheduled-plan#get_scheduled_plan
 * @see https://docs.looker.com/reference/api-and-integration/api-reference/v3.1/scheduled-plan#create_scheduled_plan
 */
class ScheduledPlan {

  /**
   * @var int
   * The Looker Scheduled Plan ID.
   */
  public $plan_id = 0;

  /**
   * @var int
   * The Looker Dashboard ID on which this plan is based.
   */
  public $dashboard_id = 0;

  /**
   * @var string
   * The title of the report.  This is exposed to users as the email's
   * subject line.  Use generateTitle() to create a standard format title.
   */
  public $title = '';

  /**
   * @var string
   * The crontab string for this plan's schedule.
   */
  protected $crontab = '';

  /**
   * @var array
   * Array of email addresses to receive the plan's email.
   */
  protected $recipients = [];

  /**
   * @var array
   * Array of filter items, in the form ['filter_name' => 'filter_value', ...].
   * The filter name should be same name expected by Looker when viewing the
   * dashboard.  Key and value should both be plain, unencoded text.
   */
  protected $filters = [];

  /**
   * @var string
   * The last message returned by the API.  Set to 'OK' if the call was
   * successful.  Otherwise, set to the body's message field.
   */
  protected $last_msg = '';

  /**
   * ScheduledPlan constructor.
   *
   * @param ?int|\Entity $plan
   * If plan is an Entity, or an integer indicating a Looker Scheduled
   * Plan ID, the object will be initialized from that source.
   */
  public function __construct($plan = NULL) {
    if ($plan instanceof \Entity) {
      $this->populateFromEntity($plan);
    }
    elseif ((int) $plan) {
      $this->populateFromLooker($plan);
    }
  }

  /**
   * Translates a schedule type into a crontab string and textual
   * representation for use as a filter.  The only types recognized
   * are 'daily' and 'weekly'.
   *
   * @param string $type ('daily'|'weekly')
   *
   * @return string[] In the form ['crontab' => string, 'filter' => string].
   */
  public static function parseTimeConfig($type) {
    // Transcribe a schedule type to a crontab.
    switch ($type) {
      case 'daily':
        $ret = ['crontab' => '0 6 * * *', 'filter' => '1 day',];
        break;
      case 'weekly':
        $ret = ['crontab' => '0 18 * * 6', 'filter' => '7 days',];
        break;
      default:
        $ret = ['crontab' => '', 'filter' => ''];
        break;
    }

    return $ret;
  }

  /**
   * Generates a standard-format title for a Scheduled Plan.  The title
   * is exposed as the email's subject line.
   *
   * @param \Bundle $bundle The Bundle object representing the report type.
   * @param integer $senator_nid The nid of the senator receiving the report.
   *
   * @return string
   */
  public function generateTitle($bundle, $senator_nid) {
    // If a bundle name was passed, load it.
    if (!($bundle instanceof \Bundle)) {
      $bundle = bundle_load('looker_plans', (string) $bundle);
    }

    // Discover the label, schedule, senator, and district.
    // If any of these are bad, throw an exception.
    $label = $bundle->label ?? '';
    $schedule = ucwords($bundle->config['schedule'] ?? NULL);
    $name = (node_load($senator_nid))
        ->field_last_name[LANGUAGE_NONE][0]['value'] ?? '';
    $district = senator_get_district_number($senator_nid);
    if (!($label && $name && $district && $schedule)) {
      watchdog('nys_looker_integration',
        'generateTitle() called without a valid bundle/senator',
        ['bundle' => $bundle, 'senator' => $senator_nid],
        WATCHDOG_ERROR);
    }

    return ($label && $district && $name && $schedule)
      ? "{$label} (SD {$district} - Sen. {$name}) ({$schedule})"
      : $this->title;
  }

  /**
   * Clears a specific filter, or all filters if no name is passed.
   *
   * @param ?string $name The filter to clear.  If not passed, all
   *                      filters will be removed.
   */
  public function clearFilter($name = NULL) {
    if ($name) {
      unset($this->filters[$name]);
    }
    else {
      $this->filters = [];
    }
  }

  /**
   * Returns either the value of an individual filter (specified by
   * name), or an array of all current filters ['name' => 'value', ...].
   * If a specific filter is requested, and it does not exist, a
   * NULL value will be returned.
   *
   * @param string $name Optional specific filter to get.
   *
   * @return array|string|null
   */
  public function getFilter($name = '') {
    return $name
      ? ($this->filters[$name] ?? NULL)
      : $this->filters;
  }

  /**
   * Sets a filter.  Filters appear in the API call's query string,
   * and both names and values must be representable as strings.
   *
   * @param string $name
   * @param string $value
   */
  public function setFilter($name, $value = '') {
    $this->filters[(string) $name] = (string) $value;
  }

  /**
   * Constructs the query string to be used for the API call using
   * drupal_http_build_query().  Blank filters will be dropped, as well
   * as any filter named "filter_config".
   *
   * @return string
   */
  public function getFilterString() {
    $filters = array_filter($this->filters);
    unset($filters['filter_config']);
    $string = drupal_http_build_query($filters);

    return $string ? '?' . $string : '';
  }

  /**
   * Writes this plan to Looker.  It will use a POST or PATCH call,
   * depending on if plan_id is populated.  The object's plan_id will
   * reflect the ID returned by Looker.  If Looker did not send one
   * (e.g., an error occurred), it will be left unchanged.
   *
   * @return integer The (new) plan ID, or 0 on failure.
   */
  public function saveToLooker() {
    $id = (int) $this->plan_id;
    $type = 'scheduled_plans' . ($id ? "/{$id}" : '');

    $ret = $this->callLooker($type, ($id) ? 'patch' : 'post');
    if ($new_plan_id = ((int) ($ret->id ?? 0))) {
      $this->plan_id = $new_plan_id;
    }

    return $new_plan_id;
  }

  /**
   * Deletes a plan from Looker.  Will only act if plan_id is populated.
   *
   * @return boolean TRUE on success, FALSE on failure
   *   */
  public function deleteFromLooker() {
    $id = (int) $this->plan_id;
    if (!$id) {
      return FALSE;
    }
    $type = 'scheduled_plans/' . $id;

    // Looker returns 204 with a null body if successful.
    $ret = $this->callLooker($type, 'delete', '204');

    return is_null($ret);
  }

  /**
   * Resets all properties to their default states.
   */
  public function clearProperties() {
    $this->plan_id = 0;
    $this->title = '';
    $this->dashboard_id = 0;
    $this->setCrontab('');
    $this->addRecipients([], TRUE);
    $this->clearFilter();
  }

  /**
   * Initializes the class based on a saved ECK Entity.  All managed
   * properties will be set accordingly, including the senator last
   * name and timeframe filters.  The title will be set to the standard
   * format if it is blank.
   *
   * @param \Entity $entity An ECK entity, or an object which mimics it.
   *
   * @return $this
   */
  public function populateFromEntity(\Entity $entity) {
    $this->clearProperties();

    // Identify the bundle
    $bundle_name = $entity->type ?? '';
    $bundle = bundle_load('looker_plans', $bundle_name);

    // Populate the properties
    $this->plan_id = $entity->plan_id ?? 0;
    $this->dashboard_id = $bundle->config['dashboard_id'];
    $this->setCrontab($bundle->config['schedule']);
    $this->title = ($entity->title ?? '')
      ? $entity->title
      : $this->generateTitle($bundle, $entity->senator);

    // Set the filters for senator name and timeframe.
    $senator = node_load($entity->senator);
    $name = $senator->field_last_name[LANGUAGE_NONE][0]['value'] ?? '';
    $time = static::parseTimeConfig($bundle->config['schedule'])['filter'];
    $this->setFilter($bundle->config['senator_filter'], $name);
    $this->setFilter($bundle->config['time_filter'], $time);

    // Populate recipients.
    $recips = $entity->looker_recipient_list['und'] ?? [];
    foreach ($recips as $val) {
      if (valid_email_address($val['email'] ?? '')) {
        $this->recipients[] = $val['email'];
      }
    }

    return $this;
  }

  /**
   * Initializes the class based on an already-saved Looker Plan.  The
   * object will be cleared prior to calling the API, and will be left
   * blank if the API does not return a valid plan object.
   *
   * @param integer $plan_id The Looker Scheduled Plan ID
   *
   * @return $this
   */
  public function populateFromLooker($plan_id) {
    $this->clearProperties();

    $plan_id = (int) $plan_id;
    if ($plan_id) {
      // Make the request, and parse the body
      $ret = $this->callLooker('scheduled_plans/' . $plan_id);
      if (!is_object($ret)) {
        $ret = new \stdClass();
      }

      // Get the basic properties
      $this->plan_id = $ret->id ?? 0;
      $this->title = $ret->name ?? '';
      $this->dashboard_id = $ret->dashboard_id ?? 0;
      $this->crontab = $ret->crontab ?? '';

      // Parse the filters
      $filters = explode('&', trim($ret->filters_string ?? '', '?'));
      foreach ($filters as $val) {
        $one_filter = array_map('urldecode', explode('=', $val));

        // ignore Looker's "filter_config" property
        if ($one_filter[0] && $one_filter[0] != 'filter_config') {
          $this->setFilter($one_filter[0], $one_filter[1]);
        }
      }

      // Parse the recipients
      $recips = [];
      foreach (($ret->scheduled_plan_destination ?? []) as $val) {
        $recips[] = $val->address ?? '';
      }
      $this->recipients = array_filter($recips);
    }

    return $this;
  }

  /**
   * Getter for protected property
   *
   * @return array
   */
  public function getRecipients(): array {
    return $this->recipients;
  }

  /**
   * Adds recipients to this plan's distribution.  Accepts  a single
   * email, or an array of emails.  If $replace is TRUE, the list of
   * recipients will be cleared before adding.
   *
   * @param string|array $add An email, or array of emails.
   * @param boolean $replace If the list should be cleared first.
   */
  public function addRecipients($add = [], $replace = FALSE) {
    // If replacing, clear the current.
    if ($replace) {
      $this->recipients = [];
    }

    // Make sure we have an array.
    if (!is_array($add)) {
      $add = [(string) $add];
    }

    // Set the new recipient list.
    $this->recipients = array_unique(array_filter($this->recipients + $add));
  }

  /**
   * @return string
   */
  public function getCrontab(): string {
    return $this->crontab;
  }

  /**
   * Sets the crontab property for the API call.  The passed string
   * must be one of the recognized keys ('daily' or 'weekly').
   *
   * @param string $crontab 'daily' or 'weekly'
   */
  public function setCrontab(string $crontab): void {
    $this->crontab = static::parseTimeConfig($crontab)['crontab'];
  }

  /**
   * Gets the textual result of the last API call.  Blank if no API
   * call has been made since instantiation, or 'OK' if the last
   * call was successful.
   *
   * @return string
   */
  public function getLastResult(): string {
    return $this->last_msg;
  }

  /**
   * Calls the Looker API.  If the call is 'not good', $last_msg is set
   * to the 'message' field of the response.  Returns FALSE if the method
   * is not recognized.
   *
   * @param string $type The path of the API service point relative to the API
   *   root.
   * @param string $method The HTTP request type
   * @param mixed $success_codes A string, or array of strings, of 'good' HTTP
   *   responses
   *
   * @return object|false The decoded response body
   */
  protected function callLooker($type, $method = 'get', $success_codes = '200') {
    /* @see \SendGrid\Client $methods property */
    $valid_methods = ['get', 'post', 'patch', 'put', 'delete'];
    if (!(in_array($method, $valid_methods))) {
      return FALSE;
    }

    // Validate success_codes
    if (!is_array($success_codes)) {
      $success_codes = [(string) $success_codes];
    }

    $client = new LookerAPI($type);
    $response = $client->execute($this->getLookerObj(), $method);
    $ret = json_decode($response->body());
    if (!in_array($response->statusCode(), $success_codes)) {
      $this->last_msg = $ret->message;
      watchdog('nys_looker_integration',
        'A call to Looker had an unexpected result',
        [
          'statusCode' => $response->statusCode(),
          'type' => $type,
          'message' => $this->last_msg,
        ]);
    }
    else {
      $this->last_msg = 'OK';
      $this->plan_id = $ret->id ?? 0;

    }
    return $ret;
  }

  protected function getLookerObj() {
    // Construct object payload
    $payload = (object) [
      'dashboard_id' => $this->dashboard_id,
      'name' => $this->title,
      'crontab' => $this->crontab,
      'scheduled_plan_destination' => [],
    ];

    if ($filter = $this->getFilterString()) {
      $payload->filters_string = $filter;
    }

    // Construct the recipients
    foreach ($this->recipients as $val) {
      $payload->scheduled_plan_destination[] = (object) [
        'type' => 'email',
        'address' => $val,
        'format' => 'wysiwyg_pdf',
      ];
    }

    return $payload;
  }

}
