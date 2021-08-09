<?php


/**
 * Implements hook_token_info().
 */
function imagecache_token_token_info() {
  $styles = image_styles();
  $styles_tokens = array();
  $image_style = array();

  foreach ($styles as $style => $desc) {
    $styles_tokens[$style] = array(
      'name' => $style,
      'description' => t("@s image style", array("@s" => $style)),
      'type' => 'image-style',
    );
    foreach (_imagegecache_token_image_attributes() as $attribute => $none) {
      $image_style[$attribute] = array(
        'name' => $attribute,
        'description' => t("@s image style attribute: @a", array("@s" => $style, "@a" => $attribute)),
      );
    }
  }

  return array(
    'types' => array(
      'image-field' => array(
        'name' => 'Image Field',
        'description' => 'Image Field',
        'needs-data' => 'image-field',
      ),
      'image-style' => array(
        'name' => 'Image Style',
        'description' => 'Image Style',
        'needs-data' => 'image-style',
      ),
    ),
    'tokens' => array(
      'image-field' => $styles_tokens,
      'image-style' => $image_style,
    ),
  );
}

/**
 * Implements hook_tokens().
 */
function imagecache_token_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $replacements = array();
  if ($type == 'entity' && !empty($data['entity'])) {
    $fields = field_info_field_map();

    // Check to see which fields are supported.
    $supported = variable_get('imagecache_token_fields', array());
    $supported = array_filter($supported);

    foreach ($fields as $field_name => $field) {
      $field['field_name'] = $field_name;
      if ($field['type'] == 'image' || $field['type'] == 'file' || $field['type'] == 'media') {
        // All image fields are supported.
        if ($field['type'] == 'image') {
          $is_supported = TRUE;
        }

        // Only support "file" and "media" fields if they're enabled. If no
        // fields are enabled, just skip this entirely.
        elseif (empty($supported)) {
          continue;
        }

        // Check through each field bundle to see if it was enabled. If no
        // copies of this field are enabled then skip it.
        else {
          $is_supported = FALSE;
          foreach ($field['bundles'] as $entity_type => $bundles) {
            foreach ($bundles as $bundle) {
              $key = $field['type'] . ':' . $field['field_name'] . ':' . $entity_type . ':' . $bundle;
              if (!empty($supported[$key])) {
                $is_supported = TRUE;
                // Exit both foreach() loops.
                break 2;
              }
            }
          }
          if (!$is_supported) {
            continue;
          }
        }

        if (($image_field_tokens = token_find_with_prefix($tokens, $field['field_name'])) && $field_object = field_get_items($data['entity_type'], $data['entity'], $field['field_name'])) {
          $replacements += token_generate('image-field', $image_field_tokens, array('image-field' => $field_object), $options);
        }
      }
    }
  }

  $images_style_data = &drupal_static(__FUNCTION__);

  if ($type == 'image-field' && !empty($data['image-field'])) {
    foreach ($tokens as $token => $original) {
      $output = array();

      // The token will be in the format "[imagestyle]:[attribute]" so split
      // into the individual pieces.
      $explode = explode(':', $token);
      $type = isset($explode[0]) ? $explode[0] : FALSE;
      $attribute = isset($explode[1]) ? $explode[1] : FALSE;

      // Special handling for the 'first', 'second', 'third', and 'last' tokens.
      // Support for index of multi-value fields.
      if (in_array($attribute, array('first', 'second', 'third', 'last')) || is_numeric($attribute)) {
        switch ($attribute) {
          case 'first':
            $index = 0;
            break;

          case 'second':
            $index = 1;
            break;

          case 'third':
            $index = 2;
            break;

          case 'last':
            $index = sizeof($data['image-field']) - 1;
            break;

          default:
            $index = $attribute;
        }

        if (isset($data['image-field'][$index]) && !empty($data['image-field'][$index]['uri'])) {
          if (isset($explode[3]) && $explode[3] === 'relative') {
            $url  = parse_url(image_style_url($type, $data['image-field'][$index]['uri']));
            $output[] = $url['path'];
          }
          else {
            $output[] = image_style_url($type, $data['image-field'][$index]['uri']);
          }

          // Generate image if does not exist.
          $styled_uri = image_style_path($type, $data['image-field'][$index]['uri']);
          _imagecache_token_generate_image($styled_uri, $type, $data['image-field'][$index]['uri']);
        }

        $replacements[$original] = implode('', $output);
      }

      // Other tokens.
      else {
        foreach ($data['image-field'] as $field) {
          if (isset($attribute) && !empty($attribute)) {
            // Generate image if does not exist.
            $styled_uri = image_style_path($type, $field['uri']);
            _imagecache_token_generate_image($styled_uri, $type, $field['uri']);

            switch ($attribute) {
              case 'render':
                $output[] = theme('image_formatter', array('item' => $field, 'image_style' => $type));
                break;

              case 'mimetype':
              case 'width':
              case 'height':
              case 'extension':
              case 'filesize':
                // If the styled image's information wasn't loaded before then
                // load it now; as this process is a little heavy, the
                // information will be statically cached to avoid needing to
                // reload the details for another token.
                if (empty($images_style_data[$styled_uri])) {
                  $images_style_data[$styled_uri] = image_get_info($styled_uri);
                }

                switch ($attribute) {
                  case 'width':
                    $output[] = $images_style_data[$styled_uri]['width'];
                    break;

                  case 'height':
                    $output[] = $images_style_data[$styled_uri]['height'];
                    break;

                  case 'mimetype':
                    $output[] = $images_style_data[$styled_uri]['mime_type'];
                    break;

                  case 'extension':
                    $output[] = $images_style_data[$styled_uri]['extension'];
                    break;

                  case 'filesize':
                    $output[] = $images_style_data[$styled_uri]['file_size'];
                    break;
                }
                break;

              case 'path':
                if (isset($explode[2]) && $explode[2] === 'relative') {
                  $url  = parse_url(image_style_url($type, $field['uri']));
                  $output[] = $url['path'];
                }
                else {
                  $output[] = image_style_url($type, $field['uri']);
                }
                break;

              default:
                if (isset($field[$attribute])) {
                  $output[] = $field[$attribute];
                }
            }
          }
          else {
            $output[] = image_style_url($type, $field['uri']);
          }
        }

        // Compile each of the elements into a comma separated list, per
        // standard Token practice.
        $replacements[$original] = implode(', ', $output);
      }
    }
  }

  return $replacements;
}

/**
 * Helper function for getting all available image attributes.
 *
 * @return array
 *   All of the available image attributes.
 */
function _imagegecache_token_image_attributes() {
  return array(
    'style_name' => NULL,
    'path' => NULL,
    'path:relative' => NULL,
    'width' => NULL,
    'height' => NULL,
    'extension' => NULL,
    'filesize' => NULL,
    'alt' => '',
    'title' => NULL,
    'mimetype' => NULL,
    'render' => '',
    'first' => '',
    'second' => '',
    'third' => '',
    'last' => '',
    'uri' => '',
  );
}

/**
 * Helper function to generate image style if does not exist.
 *
 * @param string $styled_uri
 *   URI for image style.
 * @param string $type
 *   Machine name for image style.
 * @param string $field_uri
 *   URI of field to be styled.
 */
function _imagecache_token_generate_image($styled_uri, $type, $field_uri) {
  // Only generate the image if it doesn't already exist.
  if (!file_exists($styled_uri)) {
    $style = image_style_load($type);
    // Imagecrop module support.
    global $imagecrop_style;
    $imagecrop_style = $type;
    // Create a derivative of the image for this style.
    image_style_create_derivative($style, $field_uri, $styled_uri);
  }
}
