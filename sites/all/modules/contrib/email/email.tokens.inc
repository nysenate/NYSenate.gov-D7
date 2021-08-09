<?php

/**
 * @file
 * Token callbacks for the token_example module.
 */

/**
 * Implements hook_token_info().
 *
 * @ingroup token_example
 */
function email_token_info() {

    // Node tokens.
    $info['tokens']['node']['field_contact_email:mail'] = array(
        'name' => t('Email'),
        'description' => t("Token to use for VBO email."),

    );
    return $info;
}

/**
 * Implements hook_tokens().
 *
 * @ingroup token_example
 */
function email_tokens($type, $tokens, array $data = array(), array $options = array())
{
    $replacements = array();
    $sanitize = !empty($options['sanitize']);

    // Node tokens.
    if ($type == 'node' && !empty($data['node'])) {
        $node = $data['node'];

        foreach ($tokens as $name => $original) {
            switch ($name) {
                case 'field_contact_email:mail':
                    if ($items = field_get_items('node', $node, 'field_contact_email')) {
                        $email = $data['node']->field_contact_email[LANGUAGE_NONE][0]['email'];
                        $replacements[$original] = $sanitize ? filter_xss($email) : $email;
                    }
                    break;
            }
        }

    }
    return $replacements;
}