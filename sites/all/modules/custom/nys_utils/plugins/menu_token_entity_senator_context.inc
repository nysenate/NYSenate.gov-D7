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
    $entity_type = $options['_type'];
    $entity_info = entity_get_info($entity_type);

    // Taken from entity_uri() to determine the uri callback for this entity
    // type.
    // A bundle-specific callback takes precedence over the generic one for the
    // entity type.
    if (isset($entity_info['uri callback'])) {
      $uri_callback = $entity_info['uri callback'];
    }
    else {
      return NULL;
    }

    $path = @$uri_callback();
    $path = current(explode('/', $path['path']));

    if (arg(0) === $path && is_numeric(arg(1))) {
      
      $node = node_load(arg(1));

     if($node->type == 'senator') {
       $senator_nid = $node->nid;        
      } else if(!empty($node->field_senator[LANGUAGE_NONE][0]['target_id'])) {
        $senator_nid = $node->field_senator[LANGUAGE_NONE][0]['target_id'];        
      } 
      
      
      return entity_load_single('node', $senator_nid);
    }

    return FALSE;
  }
}
