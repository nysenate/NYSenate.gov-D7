<?php

/**
 * @file
 * Contains custom SolrBaseQuery class for Apachesolr Views.
 */

class ApachesolrViewsSolrBaseQuery extends SolrBaseQuery {

  /**
   * Need to set proper base path for facets.
   */
  public function getPath($new_keywords = NULL) {
    if (isset($new_keywords)) {
      return $this->base_path . '/' . $new_keywords;
    }
    return $this->base_path;
  }
}
