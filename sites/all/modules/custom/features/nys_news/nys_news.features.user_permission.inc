<?php
/**
 * @file
 * nys_news.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function nys_news_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create field_blog_featured'.
  $permissions['create field_blog_featured'] = array(
    'name' => 'create field_blog_featured',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Experimental Content Producer' => 'Experimental Content Producer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_feature_image'.
  $permissions['create field_feature_image'] = array(
    'name' => 'create field_feature_image',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_blog_featured'.
  $permissions['edit field_blog_featured'] = array(
    'name' => 'edit field_blog_featured',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_feature_image'.
  $permissions['edit field_feature_image'] = array(
    'name' => 'edit field_feature_image',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_blog_featured'.
  $permissions['edit own field_blog_featured'] = array(
    'name' => 'edit own field_blog_featured',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Experimental Content Producer' => 'Experimental Content Producer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_feature_image'.
  $permissions['edit own field_feature_image'] = array(
    'name' => 'edit own field_feature_image',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_blog_featured'.
  $permissions['view field_blog_featured'] = array(
    'name' => 'view field_blog_featured',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Experimental Content Producer' => 'Experimental Content Producer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_feature_image'.
  $permissions['view field_feature_image'] = array(
    'name' => 'view field_feature_image',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_blog_featured'.
  $permissions['view own field_blog_featured'] = array(
    'name' => 'view own field_blog_featured',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Experimental Content Producer' => 'Experimental Content Producer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_feature_image'.
  $permissions['view own field_feature_image'] = array(
    'name' => 'view own field_feature_image',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
