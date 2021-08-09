<?php
/**
 * @file nys_opendata.csv.class.inc
 */

class NysOpenDataCsv {

  /**
   * @var array
   * Default settings for datatables initialization.
   */
  public static $js_settings = [
    'paging' => TRUE,
    'pageLength' => 100,
    'scrollY' => 400,
    'scrollX' => TRUE,
    'searching' => FALSE,
  ];

  /**
   * @var object The managed file object loaded by Drupal.
   * @see file_load()
   */
  private $managed_file = FALSE;

  /**
   * @var string The physical path to the file
   * @see \drupal_realpath()
   */
  private $physical_path = '';

  /**
   * @var array Array of header cells
   */
  private $header = [];

  /**
   * @var array Array of data rows.  Each row is an array of data cells.
   */
  private $data = [];

  /**
   * @var array Array of "extra" rows.
   * It was someone's brilliant idea to put plain-text notes at the top of the
   * CSV files.  We need to remove this "data", to use the word loosely, but
   * still retain it for possible display.  This is where it goes.
   *
   * To the person who made this necessary, may you live in interesting times.
   */
  private $extra = [];

  /**
   * NysOpenDataCsv constructor.
   *
   * @param int $fid a file id to load
   */
  public function __construct($fid = 0) {
    $this->loadFile($fid);
  }

  /**
   * Rewrite an opendata report file with proper date and currency
   * formatting.  This is necessary to reduce processing time for
   * server-side paging.
   *
   * @param int $fid A file id
   *
   * @return bool
   */
  public static function rewriteFile($fid) {
    if (!((int) $fid)) {
      throw new UnexpectedValueException("Expected an integer file id");
    }
    $csv = new NysOpenDataCsv();
    $csv->setFile($fid);
    if (!$csv->getPhysicalPath() || !file_exists($csv->getPhysicalPath())) {
      throw new RuntimeException("Could not locate file for fid $fid");
    }
    $file = file($csv->getPhysicalPath());
    if (!count($file)) {
      return FALSE;
    }
    $fp = fopen($csv->getPhysicalPath(), 'c');
    $lock = flock($fp, LOCK_EX);
    if (!$lock) {
      fclose($fp);
      throw new RuntimeException("Could not lock file {$csv->getPhysicalPath()}");
    }
    if (!ftruncate($fp, 0)) {
      throw new RuntimeException("Could not truncate file {$csv->getPhysicalPath()}");
    }
    foreach ($file as $line) {
      $output = [];
      foreach (str_getcsv($line) as $field) {
        // detect field and format
        // Need to remove commas for proper numeric detection
        $number_check = str_replace(',', '', $field);
        if (is_numeric($number_check)) {
          $field = number_format($number_check, 2, '.', '');
        }
        elseif (trim($field) && ($ts = strtotime($field)) > 0) {
          $field = date("Y-m-d", $ts);
        }
        else {
          $field = trim($field, '" ');
        }
        $output[] = $field;
      }
      // Special exception for payroll reports, field 6 (PAY PERIOD)
      if (preg_match('/prpress/', $csv->get('filename'))) {
        $output[6] = (int) $output[6];
      }
      if (!fputcsv($fp, $output)) {
        fclose($fp);
        flock($fp, LOCK_UN);
        throw new RuntimeException("COULD NOT WRITE TO TRUNCATED FILE {$csv->getPhysicalPath()}");
      }
    }
    flock($fp, LOCK_UN);
    fclose($fp);
    return TRUE;
  }

  /**
   * Gets the Drupal managed_file object.
   * @return object
   */
  public function getManagedFile(): object {
    return $this->managed_file;
  }

  /**
   * Gets the physical path of the file.
   * @return string
   */
  public function getPhysicalPath(): string {
    return $this->physical_path;
  }

  /**
   * Counts the total rows in the file.  If $all_rows is true,
   * the total will include header/extra rows.
   * @param bool $all_rows
   *
   * @return int
   */
  public function countRows($all_rows = FALSE) {
    $extra = ($all_rows ? count($this->header + $this->extra) : 0);
    return count($this->data) + $extra;
  }

  /**
   * Fetches a property.  Either a row property (header|data|extra),
   * or a property from Drupal's managed_file object.
   *
   * @param null $field
   *
   * @return mixed
   */
  public function get($field = NULL) {
    $ret = FALSE;
    if (in_array($field, ['header', 'data', 'extra'])) {
      $ret = $this->{$field};
    }
    elseif ($this->managed_file->{$field} ?? FALSE) {
      $ret = $this->managed_file->{$field};
    }

    return $ret;
  }

  /**
   * Return a slice of the file data.
   *
   * @param int $start
   * @param int $length
   *
   * @return array
   */
  public function getDataSlice($start = 0, $length = 100) {
    return array_slice($this->data, $start, $length);
  }

  /**
   * Sort the file's data in place with usort().  Accounts for sorting
   * differences between text and currency.
   *
   * @param mixed $sort column index or name to use as sort key
   * @param bool $reverse if true, reverses the sort
   *
   * @return array The sorted data.
   */
  public function sortData($sort = NULL, $reverse = FALSE) {
    $columns = count($this->header);
    if (!$sort || (int) $sort < 0 || (int) $sort > ($columns - 1)) {
      $sort = 0;
    }
    $column = (int) (is_numeric($sort) ? $sort : array_search($sort, $this->header));

    // some minor special-ness to the sorting to account for currency.
    usort($this->data, function ($a, $b) use ($column) {
      $v1 = is_numeric($a[$column]) ? floatval($a[$column]) : $a[$column];
      $v2 = is_numeric($b[$column]) ? floatval($b[$column]) : $b[$column];
      return ($v1 == $v2 ? 0 : ($v1 < $v2 ? -1 : 1));
    });

    if ($reverse) {
      $this->data = array_reverse($this->data);
    }

    return $this->data;
  }

  /**
   * Builds the #attach portion of the OpenData render array for this file.
   *
   * @param array $settings Settings used to override this behavior.
   *
   * @return array the #attached portion of a Drupal render array.
   */
  public function buildAttachedArray($settings = []) {
    $key = 't_' . $this->get('fid');
    $val = $settings + [
        'ajax' => '/open-data/datasrc/' . $this->get('fid'),
        'serverSide' => TRUE,
      ] + static::$js_settings;
    return [
      'js' => [
        [
          'data' => ['opendata' => ['dt_init' => [$key => $val]]],
          'type' => 'setting',
        ],
      ],
    ];
  }

  /**
   * Builds the Drupal render array for this data file.
   *
   * @param bool $include_data If true, includes the row data in the return.
   * @param array $settings Used to override #attach settings.
   *
   * @return array
   */
  public function buildRenderArray($include_data = FALSE, $settings = []) {

    // Generate the render array for this CSV table.
    return [
      '#theme' => 'table',
      '#header' => $this->header,
      '#footer' => $this->header,
      '#rows' => $include_data ? $this->data : [],
      '#sticky' => FALSE,
      '#empty' => 'No data was loaded',
      '#attached' => $this->buildAttachedArray($settings),
      // Because tabular data in a tabular data file is no longer a thing.
      '#extra' => $this->extra,
    ];

  }

  /**
   * Reset this object to unloaded state.
   */
  public function resetData() {
    $this->header = $this->data = $this->extra = [];
  }

  /**
   * Load data for this file.  Data will only be sorted if a
   * sort key is passed.
   *
   * @param mixed $sort column index/name to use as sort key.
   */
  public function loadData($sort = NULL) {
    // Reset the arrays.
    $this->resetData();

    // If the file exists, read as array, and parse each line into fields.
    if ($this->physical_path) {
      $data = file($this->physical_path);

      // Data is any row in which the first field does not start with
      // a hash character.
      $this->data = array_filter($data, function ($v) {
        return substr($v, 0, 2) != '"#';
      });

      // Extra is any other row, because notes in CSV files are a thing now.
      $this->extra = array_filter($data, function ($v) {
        return substr($v, 0, 2) == '"#';
      });

      // Header is the first data row.  Stored weird for parsing.
      $this->header = [array_shift($this->data)];

      // Parse each part as a CSV line.
      foreach (['data', 'extra', 'header'] as $val) {
        $this->{$val} = array_map('str_getcsv', $this->{$val});
      }

      // Get the header row.
      $this->header = reset($this->header);

      // Apply a sort, if provided
      if (!is_null($sort)) {
        $this->sortData($sort);
      }
    }
  }

  /**
   * Load a data file for this object.
   *
   * @param $fid
   */
  public function loadFile($fid) {
    $this->setFile($fid);
    $this->loadData();
  }

  /**
   * Resets this object.
   */
  public function reset() {
    $this->setFile();
  }

  /**
   * Set a new data file target.
   *
   * @param $fid
   */
  public function setFile($fid = 0) {
    $this->resetData();
    $this->managed_file = (int) $fid ? file_load($fid) : FALSE;
    $this->physical_path = ($this->managed_file->uri ?? '')
      ? drupal_realpath($this->managed_file->uri)
      : '';
  }

}
