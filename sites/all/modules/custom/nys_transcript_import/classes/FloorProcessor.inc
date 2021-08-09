<?php
require_once 'Processor.inc';

/**
 * Class NysTranscriptImportFloorProcessor
 */
class NysTranscriptImportFloorProcessor extends NysTranscriptImportProcessor {

  /**
   * @inherit_doc
   */
  protected static $type_info = [
    'url_id' => 'transcripts',
    'type_index' => 'floor',
  ];


  /**
   * @return string|null
   */
  public function getUpdateId() {
    return $this->update_block->transcriptId->dateTime ?? NULL;
  }

  /**
   * @return string|null
   */
  public function getId() {
    return $this->transcript->dateTime ?? $this->getUpdateId();
  }

  /**
   * Transcribe a floor transcript block into a floor transcript node.
   */
  public function transcribeToNode() {
    $node = &$this->node;
    $transcript = &$this->transcript;

    if ($node && $transcript) {
      $node->field_ol_filename = ['und' => [['value' => $this->getId()]]];
      $node->field_ol_publish_date = ['und' => [['value' => strtotime($this->getId())]]];
      $node->field_ol_transcript_type = ['und' => [['value' => static::$type_info['type_index']]]];

      if ($transcript->sessionType ?? NULL) {
        $node->field_ol_session_type = ['und' => [['value' => $transcript->sessionType]]];
      }

      $node->field_ol_location = ['und' => [['value' => $transcript->location]]];
      $node->field_ol_text = ['und' => [['value' => $transcript->text]]];
    }
  }

}