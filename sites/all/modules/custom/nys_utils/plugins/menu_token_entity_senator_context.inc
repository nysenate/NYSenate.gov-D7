<?php

class menu_token_entity_senator_context implements menu_token_handler {
  function form_options($options) {
    // Nothing to do here.
  }

  function form_submit($form, &$form_state) {
    // Nothing to do here.
  }

  function form_validate($form, &$form_state) {
    // Nothing to do here.
  }

  function form_alter(&$form, &$form_state) {
    // Nothing to do here.
  }

  function object_load($options) {
    // Next call to menu_get_object will cause infinite
    // loop on edit menu pages with tokens. So return false.
    if (path_is_admin(current_path())) {
      return FALSE;
    }
    // Check if a node is being viewed.
    if ($node = menu_get_object()) {
      // The senator microsite menu is rendered on different node types, e.g.
      // Senator and Article.
      if ($node->type == 'senator') {
        return $node;
      }
      else if (!empty($node->field_senator[LANGUAGE_NONE][0]['target_id'])) {
        return node_load($node->field_senator[LANGUAGE_NONE][0]['target_id']);
      }
    }
    // Otherwise could be a page manager page for e.g. /node/%node/about
    elseif ($node = node_load(arg(1))) {
      return $node;
    }
    return FALSE;
  }
}
