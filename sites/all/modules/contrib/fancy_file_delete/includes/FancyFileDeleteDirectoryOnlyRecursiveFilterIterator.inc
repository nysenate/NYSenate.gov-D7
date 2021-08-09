<?php
/**
 * @file
 * Fancy File Delete iterator for directory traversal.
 */

class FancyFileDeleteDirectoryOnlyRecursiveFilterIterator extends RecursiveFilterIterator {

  public function __construct(RecursiveIterator $iterator, array $exclude_paths = array()) {
    $this->_exclude_paths = $exclude_paths;
    parent::__construct($iterator);
  }

  public function accept() {
    if ($this->current()->isReadable()) {
      $filename = $this->current()->getFilename();
      // Skip hidden files and directories.
      if ($filename[0] === '.') {
        return FALSE;
      }

      if (!$this->isDir()) {
        return FALSE;
      }
      $path = $this->current()->getPathname();
      foreach ($this->_exclude_paths as $exclude_path) {
        if (strpos($path, $exclude_path) === 0) {
          return FALSE;
        }
      }
      return TRUE;
    }
    return FALSE;
  }
}
