<?php
/**
 * @file
 * File nys_school_importer.inc.
 */

/**
 * Calculates an index for each non unique legal_name for all schools.
 *
 * Stores the Number of elements to build a unique school name
 * 1 - only the legal name is required.
 * 2 - legal_name and city  are required.
 * 3 - legal_name, city and grade_organization are required.
 * 4 - legal_name, city, grade_organization and zip are required.
 */
function nys_school_importer_calculate_name_indexes() {
  // Iterate thru all the rows in the nys_school_names table.
  $result = db_query('SELECT * FROM `nys_school_names` WHERE 1');
  foreach ($result as $record) {
    nys_school_importer_calculate_name_index($record);
  }
}

/**
 * Calculates an index for each non unique legal_name of a single school.
 */
function nys_school_importer_calculate_name_index($record) {
  // Processes one row in the nys_school_names table.
  $sid = $record->sid;
  $legal_name = $record->legal_name;
  $grade_organization = $record->grade_organization;
  $city = $record->city;
  $zip = $record->zip;

  $num_keys_required = nys_school_importer_get_num_schools_one_key($legal_name);
  if ($num_keys_required == 1) {
    nys_school_importer_create_school_name_index($legal_name, 1);
    return;
  }

  $num_keys_required = nys_school_importer_get_num_schools_two_keys($legal_name, $city);
  if ($num_keys_required == 1) {
    nys_school_importer_create_school_name_index($legal_name, 2);
    return;
  }

  $num_keys_required = nys_school_importer_get_num_schools_three_keys($legal_name, $grade_organization, $city);
  if ($num_keys_required == 1) {
    nys_school_importer_create_school_name_index($legal_name, 3);
    return;
  }

  $num_keys_required = nys_school_importer_get_num_schools_four_keys($legal_name, $grade_organization, $city, $zip);
  if ($num_keys_required == 1) {
    nys_school_importer_create_school_name_index($legal_name, 4);
    return;
  }

  nys_school_importer_create_school_name_index($legal_name, 5);

}

/**
 * Fetch the number of matching rows using only the legal_name as a key.
 */
function nys_school_importer_get_num_schools_one_key($legal_name) {
  $legal_name = addslashes($legal_name);
  return db_query("SELECT count(*) FROM `nys_school_names` WHERE `legal_name` = '$legal_name';")->fetchField();
}

/**
 * Fetch the number of matching rows using just two keys.
 */
function nys_school_importer_get_num_schools_two_keys($legal_name, $city) {
  $legal_name = addslashes($legal_name);
  return db_query("SELECT count(*) FROM `nys_school_names` WHERE `legal_name` = '$legal_name' AND `city` = '$city';")->fetchField();
}

/**
 * Fetch the number of matching rows using just three keys.
 */
function nys_school_importer_get_num_schools_three_keys($legal_name, $grade_organization, $city) {
  $legal_name = addslashes($legal_name);
  return db_query("SELECT count(*) FROM `nys_school_names` WHERE `legal_name` = '$legal_name' AND `grade_organization` = '$grade_organization' AND `city` = '$city';")->fetchField();
}

/**
 * Fetch the number of matching rows using all four keys.
 */
function nys_school_importer_get_num_schools_four_keys($legal_name, $grade_organization, $city, $zip) {
  $legal_name = addslashes($legal_name);
  return db_query("SELECT count(*) FROM `nys_school_names` WHERE `legal_name` = '$legal_name' AND `grade_organization` = '$grade_organization' AND `city` = '$city' AND `zip` = '$zip';")->fetchField();
}

/**
 * Fetch the maximum number of keys needed.
 */
function nys_school_importer_get_num_max_names_index() {
  return db_query("SELECT MAX(num_keys) FROM `nys_school_names_index`")->fetchField();
}

/**
 * Insert data into the nys_school_names.
 */
function nys_school_importer_create_school_name($legal_name, $grade_organization, $city, $zip) {
  // Check for special ascii characters.
  $legal_name = addslashes($legal_name);
  // Insert columns into nys_school_names.
  db_query("INSERT INTO `nys_school_names` (`sid`, `legal_name`, `grade_organization`, `city`, `zip`) VALUES (NULL, '$legal_name', '$grade_organization', '$city', '$zip')");
}

/**
 * Stores the school name index (num_keys) for a school.
 */
function nys_school_importer_create_school_name_index($legal_name, $num_keys) {
  if ($num_keys > 1) {
    // Check for special ascii characters.
    $legal_name = addslashes($legal_name);
  }
  // Insert or update the data in in the num_keys comumn.
  if ($num_keys > 1) {
    db_query("INSERT INTO `nys_school_names_index` (`snid`, `legal_name`, `num_keys`) VALUES (NULL, '$legal_name', $num_keys) ON DUPLICATE KEY UPDATE `num_keys` = $num_keys");
  }
}

/**
 * Returns school_name_index num_keys that needed to form a unique school name.
 */
function nys_school_importer_get_school_name_index_num_keys($legal_name) {
  $legal_name = addslashes($legal_name);

  // Get the num_keys column.
  $sql = "SELECT `num_keys` FROM nys_school_names_index WHERE legal_name = '$legal_name'";
  $num_keys = db_query($sql)->fetchField();

  if ($num_keys === FALSE) {
    // Return the default value 1 indicating no changes are needed.
    return 1;
  }
  else {
    // Return the number of elements required in the name to make it unique.
    return $num_keys;
  }
}

/**
 * Clear The nys_school_names table.
 */
function nys_school_importer_clear_nys_school_names() {
  // Truncate the nys_school_names.
  db_query("truncate nys_school_names");
}

/**
 * Clear The nys_school_names table.
 */
function nys_school_importer_clear_nys_school_names_index() {
  // Truncate the nys_school_names.
  db_query("truncate nys_school_names_index");
}

/**
 * Returns wether the columns in the data file match the schema.
 *
 * Argument $data is an array of column names.
 */
function nys_school_importer_validate_file($data) {

  // Get the mappings.
  $data_mappings = nys_school_importer_get_mappings();

  foreach ($data as $key => $value) {
    $index = $key + 1;

    if ($value != $data_mappings->$index->csv_colname) {
      return FALSE;
    }

  }
  return TRUE;
}

/**
 * Returns the mapping json as an array.
 */
function nys_school_importer_get_mappings() {
  static $cache = NULL;

  if ($cache === NULL) {
    $mapping_file_path = drupal_get_path('module', 'nys_school_importer') . '/nys_school_importer_mapping.json';
    $cache = json_decode(file_get_contents($mapping_file_path));
  }

  return $cache;
}

/**
 * Returns the column number of a field.
 */
function nys_school_importer_get_column_number($column_name) {
  $file_mappings = nys_school_importer_get_mappings();
  foreach ($file_mappings as $key => $value) {
    if ($column_name == $value->csv_colname) {
      return $key;
    }
  }
  return FALSE;
}

/**
 * Returns the csv_colname of a column.
 */
function nys_school_importer_get_csv_colname($column_number) {
  $file_mappings = nys_school_importer_get_mappings();
  return $file_mappings->$column_number->csv_colname;
}

/**
 * Returns the drupal_colname of a column.
 */
function nys_school_importer_get_drupal_colname($column_number) {
  $file_mappings = nys_school_importer_get_mappings();
  return $file_mappings->$column_number->drupal_colname;
}

/**
 * Returns the drupal_coltype of a column.
 */
function nys_school_importer_get_drupal_coltype($column_number) {
  $file_mappings = nys_school_importer_get_mappings();
  return $file_mappings->$column_number->drupal_coltype;
}

/**
 * Returns the drupal_coltitle of a column.
 */
function nys_school_importer_get_drupal_coltitle($column_number) {
  $file_mappings = nys_school_importer_get_mappings();
  return $file_mappings->$column_number->drupal_coltitle;
}

/**
 * Loads a school node by $legal_name, $grade_organization, $city, and $zip.
 */
function nys_school_importer_load_school_node($legal_name, $grade_organization, $city, $zip) {

  $sql = "
	SELECT `field_data_field_school_address`.`entity_id` FROM `field_data_field_school_address`, `field_data_field_school_legal_name`, `field_data_field_school_grade_organization`, `location`
	WHERE field_data_field_school_legal_name.entity_id = field_data_field_school_grade_organization.entity_id
	AND field_data_field_school_legal_name.entity_id = field_data_field_school_address.entity_id
	AND `field_data_field_school_address`.`field_school_address_lid` = `location`.`lid`
	AND `field_school_legal_name_value` = :legal_name
	AND `field_school_grade_organization_value` = :grade_org_desc
	AND `city` = :city
	AND `postal_code` = :zip";

  $result = db_query($sql, array(
    ':legal_name' => $legal_name,
    ':grade_org_desc' => $grade_organization,
    ':city' => $city,
    ':zip' => $zip,
  )
  );

  if ($result->rowCount() == 1) {
    $entity_id = $result->fetchObject()->entity_id;
  }

  if (empty($entity_id) == FALSE && is_numeric($entity_id) == TRUE) {
    $node_array = node_load_multiple(array($entity_id), array(), TRUE);
    if (is_array($node_array) === TRUE && count($node_array) > 0) {
      return $node_array[$entity_id];
    }
  }

  return FALSE;
}

/**
 * Creates a new empty school node.
 */
function nys_school_importer_create_school_node($data) {
  // Create a new empty node.
  $node = new StdClass();
  $node->type = variable_get(NYS_SCHOOL_IMPORTER_CONTENT_TYPE, NYS_SCHOOL_IMPORTER_CONTENT_TYPE_DEFAULT);
  $node->status = 1;
  $node->language = LANGUAGE_NONE;
  node_object_prepare($node);

  return $node;
}

/**
 * Compares the node to the data.
 *
 * If they compare returns TRUE.
 * If they don't compare returns FALSE.
 */
function nys_school_importer_compare_school_node(&$node, $data) {

  $return_value = TRUE;
  $location_array = array();

  if (empty($node) == FALSE && is_array($data) == TRUE && count($data) > 0) {

    foreach ($data as $col_index => $col_value) {
      // Set a drupal field.
      $column_number = $col_index + 1;
      $drupal_colname = nys_school_importer_get_drupal_colname($column_number);
      $drupal_coltype = nys_school_importer_get_drupal_coltype($column_number);

      if (empty($drupal_colname) == FALSE) {
        // Only add columns with field names in them some are unused.
        if ($drupal_colname == 'field_school_address') {
          // Build the address array.
          $location_array[$drupal_coltype] = $col_value;
        }
        elseif ($drupal_colname == 'field_school_legal_name') {

          $school_name = nys_school_importer_cleanup_name($col_value);
          if (strcmp(html_entity_decode($node->{$drupal_colname}[LANGUAGE_NONE][0]['value']), $school_name) != 0) {
            return FALSE;
          }
        }
        else {
          // Do comparison here for regular fields.
          if (strcmp(html_entity_decode($node->{$drupal_colname}[LANGUAGE_NONE][0]['value']), $col_value) != 0) {
            return FALSE;
          }

        }

      } // Column Name Was not Empty

    }// of each col

    if (count($location_array) > 0) {
      // Do comparison here for address fields.
      if (html_entity_decode($node->field_school_address[LANGUAGE_NONE][0]['sub_administrative_area']) == $data[nys_school_importer_get_column_number('COUNTY')]) {
        return FALSE;
      }

      if (html_entity_decode($node->field_school_address[LANGUAGE_NONE][0]['thoroughfare']) == $data[nys_school_importer_get_column_number('MAILING ADDRESS')]) {
        return FALSE;
      }

      if (html_entity_decode($node->field_school_address[LANGUAGE_NONE][0]['locality']) == $data[nys_school_importer_get_column_number('CITY')]) {
        return FALSE;
      }

      if (html_entity_decode($node->field_school_address[LANGUAGE_NONE][0]['administrative_area']) == $data[nys_school_importer_get_column_number('STATE')]) {
        return FALSE;
      }

      if (html_entity_decode($node->field_school_address[LANGUAGE_NONE][0]['postal_code']) == $data[nys_school_importer_get_column_number('ZIP')]) {
        return FALSE;
      }

    }

  }

  if (is_array($node->field_district) && count($node->field_district) == 0) {
    // If the district is not set, force an update so a fresh sage lookup can be done.
    return FALSE;
  }

  return TRUE;
}

/**
 * Sets the node members with the data and saves the node.
 */
function nys_school_importer_update_school_node(&$node, $data) {

  $location_array = array();
  $location_array["country"] = "us";
  $location_array["province"] = "NY";

  if (empty($node) == FALSE && is_array($data) == TRUE && count($data) > 0) {
    // For each item map columns to fields in`nys_school_importer_mapping.json`.
    foreach ($data as $col_index => $col_value) {
      // Set a drupal field.
      $column_number = $col_index + 1;
      $drupal_colname = nys_school_importer_get_drupal_colname($column_number);
      $drupal_coltype = nys_school_importer_get_drupal_coltype($column_number);

      if (empty($drupal_colname) == FALSE) {
        // Only add columns with field names in them some are unused.
        if ($drupal_colname == 'field_school_address') {
          // Build the address array.
          $location_array[$drupal_coltype] = $col_value;
        }
        else {
          $node->$drupal_colname = array(
            LANGUAGE_NONE => array(
            array(
              $drupal_coltype => $col_value,
              'format' => 'plain_text',
              'safe_value' => $col_value,
            ),
            ),
          );
        }

      } // Of column not empty.

    } // Of for each column.

    // Final overrides and cleanup.
    nys_school_importer_cleanup($node, $data, $location_array);

    // Add the $location_array to field_school_address in the node.
    if (count($location_array) > 0) {
      $node->field_school_address[LANGUAGE_NONE][0] = $location_array;
    }

  }

  $node = node_submit($node);
  node_save($node);

  return $node->nid;
}

/**
 * The nys_school_importer_cleanup.
 */
function nys_school_importer_cleanup(&$node, $data, &$location_array) {
  // Get the key fields.
  $legal_name = $data[nys_school_importer_get_column_number('LEGAL NAME') - 1];
  $grade_organization = $data[nys_school_importer_get_column_number('GRADE ORGANIZATION DESCRIPTION') - 1];
  $nysed_id = $data[nys_school_importer_get_column_number('SED CODE') - 1];

  $addr1 = $data[nys_school_importer_get_column_number('MAILING ADDRESS') - 1];
  $city = $data[nys_school_importer_get_column_number('CITY') - 1];
  $county_name = $data[nys_school_importer_get_column_number('COUNTY') - 1];
  $state = 'NY';
  $zip5 = $data[nys_school_importer_get_column_number('ZIP') - 1];

  // Get the override value for the school name index.
  $default_override_num_keys = variable_get(NYS_SCHOOL_IMPORTER_DEFAULT_SCHOOL_NAMES_INDEX_NAME, '');
  if (empty($default_override_num_keys) == TRUE && $default_override_num_keys !== 0 && $default_override_num_keys !== '0') {
    // If there is no override use 4.
    $num_keys = NYS_SCHOOL_IMPORTER_DEFAULT_SCHOOL_NAMES_INDEX_VALUE;
  }
  elseif ($default_override_num_keys === 0 || $default_override_num_keys === '0') {
    // If the override is zero use the built in uniqueness calculated value.
    $num_keys = nys_school_importer_get_school_name_index_num_keys($legal_name);
  }
  elseif (empty($default_override_num_keys) == FALSE && is_numeric($default_override_num_keys) == TRUE && $default_override_num_keys > 0) {
    // Use the supplied value.
    $num_keys = nys_school_importer_get_school_name_index_num_keys($legal_name);
  }

  // Massage the name.
  if ($num_keys == 1) {
    $cleaned_up_name = nys_school_importer_cleanup_name($legal_name);
  }
  elseif ($num_keys == 2) {
    $cleaned_up_name = nys_school_importer_cleanup_name($legal_name) . ', ' . ucwords(strtolower($city));
  }
  elseif ($num_keys == 3) {
    $cleaned_up_name = nys_school_importer_cleanup_name($legal_name) . ', ' . $grade_organization . ', ' . ucwords(strtolower($city));
  }
  elseif ($num_keys == 4) {
    $cleaned_up_name = nys_school_importer_cleanup_name($legal_name) . ', ' . $grade_organization . ', ' . ucwords(strtolower($city)) . ', ' . $zip5;
  }
  else {
    $cleaned_up_name = nys_school_importer_cleanup_name($legal_name) . ', ' . $grade_organization . ', ' . ucwords(strtolower($city)) . ', ' . $zip5 . ', ' . rand(1, 9);
  }

  // Set the node title.
  $node->title = $cleaned_up_name;

  // Set the Location name.
  $location_array["name"] = $cleaned_up_name;

  // Get the NYSED data for the SED CODE.
  $nysed_data = nys_school_importer_get_nysed_data($nysed_id);
  if ($nysed_data !== FALSE) {
    // Get the data from sage based on the NYSED physical address.
    $sage_data = nys_school_importer_get_sage_district_assign_data($nysed_data->physical_address_line_1, $nysed_data->city, $nysed_data->state, $nysed_data->zip_code);
  }
  else {
    // Get the data from sage using the mailing address.
    $sage_data = nys_school_importer_get_sage_district_assign_data($addr1, $city, $state, $zip5);
  }

  // Set the district tid, latitude and longitude.
  if ($sage_data->status == 'SUCCESS') {

    // We are atempting to set the long and lat butit doesnt stick.
    $location_array['inhibit_geocode'] = TRUE;
    $location_array["longitude"] = $sage_data->geocode->lon;
    $location_array["latitude"] = $sage_data->geocode->lat;

    if ($sage_data->districtAssigned == TRUE && is_object($sage_data->districts->senate) == TRUE) {

      $district_name = 'NY Senate District ' . $sage_data->districts->senate->district;
      $district_tid = nys_school_importer_get_district_tid($district_name);
      if ($district_tid !== FALSE) {
        $node->field_district[LANGUAGE_NONE][0]['target_id'] = $district_tid;
      }
    }
    else {
      drupal_set_message("Sage could not supply district data for $cleaned_up_name.", 'status');
      watchdog('nys_school_importer_district', print_r($sage_data, TRUE));
    }
  }

  // Set the County tid.
  $county_tid = nys_school_importer_get_county_tid($county_name);
  if ($county_tid !== FALSE) {
    $node->field_county[LANGUAGE_NONE][0]['tid'] = $county_tid;
  }

  // Make the legal school name look nice.
  $node->field_school_legal_name[LANGUAGE_NONE][0]['value'] = nys_school_importer_cleanup_name($legal_name);

}

/**
 * Formats legal school names as titles & moves.
 *
 * THE to the beginning if necessary.
 */
function nys_school_importer_cleanup_name($raw_message) {
  if (nys_school_importer_name_ends_with($raw_message, ' (THE)') == FALSE) {
    // Just clean it up.
    $massaged_name = ucwords(strtolower($raw_message), " -\t\r\n\f\v");
    if (strncmp($massaged_name, 'Ps', 2) == 0) {
      return substr_replace($massaged_name, 'PS', 0, 2);
    }
    else {
      return $massaged_name;
    }
  }
  else {
    // The name ends with (THE).
    // Move 'The' to the beginning of the name and clean it up.
    return ucwords(strtolower('THE ' . substr($raw_message, 0, strlen($raw_message) - 6)), " -\t\r\n\f\v");

  }
}

/**
 * Matches string ending characters.
 */
function nys_school_importer_name_ends_with($haystack, $needle) {
  // Search forward starting from end minus needle length characters.
  return $needle === "" || (($temp = strlen($haystack) - strlen($needle)) >= 0 && strpos($haystack, $needle, $temp) !== FALSE);
}

/**
 * Restores massaged school name to a legal school name.
 */
function nys_school_importer_restore_legal_school_name($schol_name) {
  if (strncasecmp($schol_name, 'The ', 4) == 0) {
    return strtoupper(substr($schol_name, 4, strlen($schol_name) - 4)) . ' (THE)';
  }
  return strtoupper($schol_name);
}

/**
 * Gets the tid for a district from the taxonomy term.
 */
function nys_school_importer_get_district_tid($district_name) {
  // Lookup the district and it's associated Senator, if available.
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'taxonomy_term')
        ->propertyCondition('vid', NYS_SCHOOL_IMPORTER_COUNTY_TAXONOMY_VID)
        ->propertyCondition('name', $district_name);

  $result = $query->execute();

  if ($result) {
    $tid = key($result['taxonomy_term']);
    return $tid;
  }

  return FALSE;
}

/**
 * Gets the tid for a county from the taxonomy term.
 */
function nys_school_importer_get_county_tid($county_name) {
  // Lookup the district and it's associated Senator, if available.
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'taxonomy_term')
    ->propertyCondition('vid', NYS_SCHOOL_IMPORTER_DISTRICT_TAXONOMY_VID)
    ->propertyCondition('name', $county_name);

  $result = $query->execute();

  if ($result) {
    $tid = key($result['taxonomy_term']);
    return $tid;
  }

  return FALSE;
}

/**
 *  Gets the district assign data structure from sage.
 */
function nys_school_importer_get_sage_district_assign_data($addr1, $city, $state, $zip5) {

  $sage_base_url   = 'http://pubgeo.nysenate.gov/api/v2/';
  $sage_district   = 'district/assign';

  $sage_parameters =
      '?addr1=' . urlencode($addr1)
      . '&city=' . urlencode($city)
      . '&state=' . urlencode($state)
      . '&zip5=' . urlencode($zip5);

  $response = json_decode(file_get_contents($sage_base_url . $sage_district . $sage_parameters));
  if ($response->status == 'SUCCESS') {
    return $response;
  }

  return FALSE;
}


/**
 * Create or Update institution data in our SED database based on the sed_code.
 */
function nys_school_importer_insert_or_update_nysed_data($institution_id,
                                                         $popular_name,
                                                         $sed_code,
                                                         $institution_type_desc,
                                                         $institution_sub_type_desc,
                                                         $physical_address_line_1,
                                                         $address_line_2,
                                                         $city,
                                                         $state,
                                                         $zip_code,
                                                         $ceo_first_name,
                                                         $ceo_last_name,
                                                         $ceo_title,
                                                         $ceo_phone_number,
                                                         $senatorial_dist_1,
                                                         $senatorial_dist_2,
                                                         $senatorial_dist_3,
                                                         $senatorial_dist_4,
                                                         $senatorial_dist_5,
                                                         $senatorial_dist_6) {

  // Insert or update UPSERT.
  $sql = "INSERT INTO `nys_school_nysed_data` (`institution_id`, `popular_name`, `sed_code`, `institution_type_desc`, `institution_sub_type_desc`, `physical_address_line_1`, `address_line_2`, `city`, `state`, `zip_code`, `ceo_first_name`, `ceo_last_name`, `ceo_title`, `ceo_phone_number`, `senatorial_dist_1`, `senatorial_dist_2`, `senatorial_dist_3`, `senatorial_dist_4`, `senatorial_dist_5`, `senatorial_dist_6`)
                             VALUES (:institution_id, :popular_name, :sed_code, :institution_type_desc, :institution_sub_type_desc, :physical_address_line_1, :address_line_2, :city, :state, :zip_code, :ceo_first_name, :ceo_last_name, :ceo_title, :ceo_phone_number, :senatorial_dist_1, :senatorial_dist_2, :senatorial_dist_3, :senatorial_dist_4, :senatorial_dist_5, :senatorial_dist_6)
          ON DUPLICATE KEY UPDATE `institution_id` = :institution_id, `popular_name` = :popular_name, `institution_type_desc` = :institution_type_desc, `institution_sub_type_desc` = :institution_sub_type_desc, `physical_address_line_1` = :physical_address_line_1, `address_line_2` = :address_line_2, `city` = :city, `state` = :state, `zip_code` = :zip_code, `ceo_first_name` = :ceo_first_name, `ceo_last_name` = :ceo_last_name, `ceo_title` = :ceo_title, `ceo_phone_number` = :ceo_phone_number, `senatorial_dist_1` = :senatorial_dist_1, `senatorial_dist_2` = :senatorial_dist_2, `senatorial_dist_3` = :senatorial_dist_3, `senatorial_dist_4` = :senatorial_dist_4, `senatorial_dist_5` = :senatorial_dist_5, `senatorial_dist_6` = :senatorial_dist_6";

  $values = array(
    ':institution_id' => $institution_id,
    ':popular_name' => $popular_name,
    ':sed_code' => $sed_code,
    ':institution_type_desc' => $institution_type_desc,
    ':institution_sub_type_desc' => $institution_sub_type_desc,
    ':physical_address_line_1' => $physical_address_line_1,
    ':address_line_2' => $address_line_2,
    ':city' => $city,
    ':state' => $state,
    ':zip_code' => $zip_code,
    ':ceo_first_name' => $ceo_first_name,
    ':ceo_last_name' => $ceo_last_name,
    ':ceo_title' => $ceo_title,
    ':ceo_phone_number' => $ceo_phone_number,
    ':senatorial_dist_1' => $senatorial_dist_1,
    ':senatorial_dist_2' => $senatorial_dist_2,
    ':senatorial_dist_3' => $senatorial_dist_3,
    ':senatorial_dist_4' => $senatorial_dist_4,
    ':senatorial_dist_5' => $senatorial_dist_5,
    ':senatorial_dist_6' => $senatorial_dist_6,
  );

  db_query($sql, $values);

}

/**
 * Get the nysed data for a school ID.
 *
 * Returns
 * stdClass Object
 * (
 *    [institution_id] => id1
 *    [popular_name] => popname
 *    [sed_code] => 122345678911
 *    [institution_type_desc] => typedesc
 *    [physical_address_line_1] => addr1
 *    [address_line_2] => addr2
 *    [city] => city
 *    [state] => NY
 *    [zip_code] => 12345
 *    [ceo_first_name] => fname
 *    [ceo_last_name] => lname
 *    [ceo_title] => mr
 *    [ceo_phone_number] => 1234567
 *    [senatorial_dist_1] => 11
 *    [senatorial_dist_2] => 22
 *    [senatorial_dist_3] => 33
 *    [senatorial_dist_4] => 44
 *    [senatorial_dist_5] => 55
 *    [senatorial_dist_6] => 67
 * ).
 */
function nys_school_importer_get_nysed_data($nysed_id) {
  $sql = 'SELECT * FROM `nys_school_nysed_data` WHERE sed_code = :nysed_id';
  $args = array(':nysed_id' => $nysed_id);
  $result = db_query($sql, $args);
  if ($result->rowCount() == 1) {
    return $result->fetchObject();
  }

  return FALSE;

}

/**
 * Get the nysed data size.
 */
function nys_school_importer_get_nysed_data_count() {
  return db_query("SELECT COUNT(*) FROM `nys_school_nysed_data`")->fetchField();
}
