<?php
require_once 'Processor.inc';

/**
 * Class NysTranscriptImportPublicHearingProcessor
 */
class NysTranscriptImportPublicHearingProcessor extends NysTranscriptImportProcessor {

  /**
   * @inherit_doc
   */
  protected static $type_info = [
    'url_id' => 'hearings',
    'type_index' => 'public_hearing',
  ];


  /**
   * @return string|null
   */
  public function getUpdateId() {
    return $this->update_block->publicHearingId->filename ?? NULL;
  }

  /**
   * @return string|null
   */
  public function getId() {
    return $this->transcript->filename ?? $this->getUpdateId();
  }

  /**
   * Transcribe a public hearing transcript block into a public hearing transcript node.
   */
  public function transcribeToNode() {
    $node = &$this->node;
    $transcript = &$this->transcript;

    if ($node && $transcript) {
      $node->field_ol_filename = ['und' => [['value' => $this->getId()]]];
      $node->field_ol_transcript_type = ['und' => [['value' => static::$type_info['type_index']]]];

      $node->field_ol_publish_date = ['und' => [['value' => strtotime($transcript->date)]]];

      $node->field_ol_location = ['und' => [['value' => $transcript->location]]];
      $node->field_ol_text = ['und' => [['value' => $transcript->text]]];

      if (is_array($transcript->committees) && count($transcript->committees)) {
        $names = array_map(function($v){return $v->name;}, $transcript->committees ?? []);
        $query = new EntityFieldQuery();
        $query->entityCondition('entity_type', 'taxonomy_term')
          ->entityCondition('bundle', 'committees')
          ->propertyCondition('name', $names, 'IN');
        $result = $query->execute();
        $field = [];
        foreach (array_keys($result['taxonomy_term'] ?? []) as $val) {
          $field[] = ['target_id' => $val];
        }
        $node->field_ol_committee['und'] = $field;
        $node->field_ol_committee_names = ['und' => [['value' => json_encode($transcript->committees)]]];
      }
    }
  }

}
