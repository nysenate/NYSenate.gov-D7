<?php

/**
 * Webform exporter for creating CSV/TSV delimited files.
 */
class webform_exporter_delimited extends webform_exporter {
  public $line_ending;
  public $delimiter;

  /**
   * {@inheritdoc}
   */
  public function __construct($options) {
    $this->line_ending = webform_variable_get('webform_csv_line_ending');
    $this->delimiter = isset($options['delimiter']) ? $options['delimiter'] : ',';
    // Convert tabs.
    if ($this->delimiter == '\t') {
      $this->delimiter = "\t";
    }
    $options['delimiter'] = $this->delimiter;
    parent::__construct($options);
  }

  /**
   * {@inheritdoc}
   */
  public function add_row(&$file_handle, array $data, $row_count) {
    foreach ($data as $key => $value) {
      // Escape inner quotes and wrap all contents in new quotes.
      $data[$key] = '"' . str_replace('"', '""', $data[$key]) . '"';

      // Remove <script> tags, which mysteriously cause Excel not to import.
      $data[$key] = preg_replace('!<(/?script.*?)>!', '[$1]', $data[$key]);
    }
    $row = implode($this->delimiter, $data) . $this->line_ending;

    @fwrite($file_handle, $row);
  }

  /**
   * {@inheritdoc}
   */
  public function set_headers($filename) {
    parent::set_headers($filename);

    // Convert tabs.
    if ($this->delimiter == "\t") {
      $content_type = 'text/tab-separated-values';
    }
    else {
      $content_type = 'text/csv';
    }

    drupal_add_http_header('Content-Type', $content_type);
    drupal_add_http_header('Content-Disposition', 'attachment; filename=' . $this->get_filename($filename));
  }

  /**
   * {@inheritdoc}
   */
  public function get_filename($filename) {
    $extension = ($this->delimiter === "\t") ? 'tsv' : 'csv';
    return $filename . '.' . $extension;
  }

}
