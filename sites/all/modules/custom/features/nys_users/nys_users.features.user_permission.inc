<?php
/**
 * @file
 * nys_users.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function nys_users_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'Access Admin Link in Dashboard'.
  $permissions['Access Admin Link in Dashboard'] = array(
    'name' => 'Access Admin Link in Dashboard',
    'roles' => array(
      'Administrator' => 'Administrator',
      'FOIL Administrator' => 'FOIL Administrator',
      'Frontpage Editor' => 'Frontpage Editor',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Senator' => 'Senator',
      'Student Contest Judge' => 'Student Contest Judge',
      'Student Programs' => 'Student Programs',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'nys_blocks',
  );

  // Exported permission: 'access administration pages'.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      'Administrator' => 'Administrator',
      'FOIL Administrator' => 'FOIL Administrator',
      'Frontpage Editor' => 'Frontpage Editor',
      'Legislative Correspondent' => 'Legislative Correspondent',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Senator' => 'Senator',
      'Student Contest Judge' => 'Student Contest Judge',
      'Student Programs' => 'Student Programs',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access all views'.
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: 'access all webform results'.
  $permissions['access all webform results'] = array(
    'name' => 'access all webform results',
    'roles' => array(
      'Administrator' => 'Administrator',
      'FOIL Administrator' => 'FOIL Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Constituent' => 'Constituent',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Web Administrator' => 'Web Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access content overview'.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access contextual links'.
  $permissions['access contextual links'] = array(
    'name' => 'access contextual links',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'contextual',
  );

  // Exported permission: 'access dashboard'.
  $permissions['access dashboard'] = array(
    'name' => 'access dashboard',
    'roles' => array(
      'Administrator' => 'Administrator',
      'FOIL Administrator' => 'FOIL Administrator',
      'Frontpage Editor' => 'Frontpage Editor',
      'Legislative Correspondent' => 'Legislative Correspondent',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Senator' => 'Senator',
      'Student Contest Judge' => 'Student Contest Judge',
      'Student Programs' => 'Student Programs',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'dashboard',
  );

  // Exported permission: 'access electoral list'.
  $permissions['access electoral list'] = array(
    'name' => 'access electoral list',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'advpoll',
  );

  // Exported permission: 'access media browser'.
  $permissions['access media browser'] = array(
    'name' => 'access media browser',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Student Programs' => 'Student Programs',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'media',
  );

  // Exported permission: 'access own authorizations'.
  $permissions['access own authorizations'] = array(
    'name' => 'access own authorizations',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'oauth_common',
  );

  // Exported permission: 'access own consumers'.
  $permissions['access own consumers'] = array(
    'name' => 'access own consumers',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'oauth_common',
  );

  // Exported permission: 'access own webform results'.
  $permissions['access own webform results'] = array(
    'name' => 'access own webform results',
    'roles' => array(
      'Administrator' => 'Administrator',
      'FOIL Administrator' => 'FOIL Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Student Programs' => 'Student Programs',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'access own webform submissions'.
  $permissions['access own webform submissions'] = array(
    'name' => 'access own webform submissions',
    'roles' => array(
      'Administrator' => 'Administrator',
      'FOIL Administrator' => 'FOIL Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Student Programs' => 'Student Programs',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'access private fields'.
  $permissions['access private fields'] = array(
    'name' => 'access private fields',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'access rules debug'.
  $permissions['access rules debug'] = array(
    'name' => 'access rules debug',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'access site in maintenance mode'.
  $permissions['access site in maintenance mode'] = array(
    'name' => 'access site in maintenance mode',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access site reports'.
  $permissions['access site reports'] = array(
    'name' => 'access site reports',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access site-wide contact form'.
  $permissions['access site-wide contact form'] = array(
    'name' => 'access site-wide contact form',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Constituent' => 'Constituent',
      'Frontpage Editor' => 'Frontpage Editor',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Web Administrator' => 'Web Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'contact',
  );

  // Exported permission: 'access user contact forms'.
  $permissions['access user contact forms'] = array(
    'name' => 'access user contact forms',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Constituent' => 'Constituent',
      'Frontpage Editor' => 'Frontpage Editor',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Web Administrator' => 'Web Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'contact',
  );

  // Exported permission: 'access user profiles'.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Constituent' => 'Constituent',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'add authenticated twitter accounts'.
  $permissions['add authenticated twitter accounts'] = array(
    'name' => 'add authenticated twitter accounts',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'twitter',
  );

  // Exported permission: 'add media from remote sources'.
  $permissions['add media from remote sources'] = array(
    'name' => 'add media from remote sources',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Student Programs' => 'Student Programs',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'media_internet',
  );

  // Exported permission: 'add twitter accounts'.
  $permissions['add twitter accounts'] = array(
    'name' => 'add twitter accounts',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'twitter',
  );

  // Exported permission: 'add write-ins'.
  $permissions['add write-ins'] = array(
    'name' => 'add write-ins',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'advpoll',
  );

  // Exported permission: 'admin_display_suite'.
  $permissions['admin_display_suite'] = array(
    'name' => 'admin_display_suite',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'ds',
  );

  // Exported permission: 'administer CAPTCHA settings'.
  $permissions['administer CAPTCHA settings'] = array(
    'name' => 'administer CAPTCHA settings',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'captcha',
  );

  // Exported permission: 'administer actions'.
  $permissions['administer actions'] = array(
    'name' => 'administer actions',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer advanced pane settings'.
  $permissions['administer advanced pane settings'] = array(
    'name' => 'administer advanced pane settings',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer blocks'.
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'block',
  );

  // Exported permission: 'administer consumers'.
  $permissions['administer consumers'] = array(
    'name' => 'administer consumers',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'oauth_common',
  );

  // Exported permission: 'administer contact forms'.
  $permissions['administer contact forms'] = array(
    'name' => 'administer contact forms',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'contact',
  );

  // Exported permission: 'administer content types'.
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer custom content'.
  $permissions['administer custom content'] = array(
    'name' => 'administer custom content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'ctools_custom_content',
  );

  // Exported permission: 'administer date tools'.
  $permissions['administer date tools'] = array(
    'name' => 'administer date tools',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'date_tools',
  );

  // Exported permission: 'administer dependencies'.
  $permissions['administer dependencies'] = array(
    'name' => 'administer dependencies',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'conditional_fields',
  );

  // Exported permission: 'administer disqus'.
  $permissions['administer disqus'] = array(
    'name' => 'administer disqus',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'disqus',
  );

  // Exported permission: 'administer facets'.
  $permissions['administer facets'] = array(
    'name' => 'administer facets',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'facetapi',
  );

  // Exported permission: 'administer features'.
  $permissions['administer features'] = array(
    'name' => 'administer features',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'administer field collections'.
  $permissions['administer field collections'] = array(
    'name' => 'administer field collections',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'field_collection',
  );

  // Exported permission: 'administer field permissions'.
  $permissions['administer field permissions'] = array(
    'name' => 'administer field permissions',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'administer fieldgroups'.
  $permissions['administer fieldgroups'] = array(
    'name' => 'administer fieldgroups',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'field_group',
  );

  // Exported permission: 'administer file types'.
  $permissions['administer file types'] = array(
    'name' => 'administer file types',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'administer files'.
  $permissions['administer files'] = array(
    'name' => 'administer files',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'administer filters'.
  $permissions['administer filters'] = array(
    'name' => 'administer filters',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'administer flags'.
  $permissions['administer flags'] = array(
    'name' => 'administer flags',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'administer honeypot'.
  $permissions['administer honeypot'] = array(
    'name' => 'administer honeypot',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'honeypot',
  );

  // Exported permission: 'administer image styles'.
  $permissions['administer image styles'] = array(
    'name' => 'administer image styles',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'image',
  );

  // Exported permission: 'administer media browser'.
  $permissions['administer media browser'] = array(
    'name' => 'administer media browser',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'media',
  );

  // Exported permission: 'administer menu'.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'menu',
  );

  // Exported permission: 'administer menu_token'.
  $permissions['administer menu_token'] = array(
    'name' => 'administer menu_token',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'menu_token',
  );

  // Exported permission: 'administer meta tags'.
  $permissions['administer meta tags'] = array(
    'name' => 'administer meta tags',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'administer modules'.
  $permissions['administer modules'] = array(
    'name' => 'administer modules',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer nodequeue'.
  $permissions['administer nodequeue'] = array(
    'name' => 'administer nodequeue',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'nodequeue',
  );

  // Exported permission: 'administer nodes'.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Senator' => 'Senator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer nys access permissions settings'.
  $permissions['administer nys access permissions settings'] = array(
    'name' => 'administer nys access permissions settings',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Frontpage Editor' => 'Frontpage Editor',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'nys_access_permissions',
  );

  // Exported permission: 'administer oauth'.
  $permissions['administer oauth'] = array(
    'name' => 'administer oauth',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'oauth_common',
  );

  // Exported permission: 'administer page manager'.
  $permissions['administer page manager'] = array(
    'name' => 'administer page manager',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'page_manager',
  );

  // Exported permission: 'administer pane access'.
  $permissions['administer pane access'] = array(
    'name' => 'administer pane access',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer panels layouts'.
  $permissions['administer panels layouts'] = array(
    'name' => 'administer panels layouts',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer panels styles'.
  $permissions['administer panels styles'] = array(
    'name' => 'administer panels styles',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer pathauto'.
  $permissions['administer pathauto'] = array(
    'name' => 'administer pathauto',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: 'administer permissions'.
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer polls'.
  $permissions['administer polls'] = array(
    'name' => 'administer polls',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'advpoll',
  );

  // Exported permission: 'administer privatemsg settings'.
  $permissions['administer privatemsg settings'] = array(
    'name' => 'administer privatemsg settings',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'privatemsg',
  );

  // Exported permission: 'administer rules'.
  $permissions['administer rules'] = array(
    'name' => 'administer rules',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'administer search'.
  $permissions['administer search'] = array(
    'name' => 'administer search',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'search',
  );

  // Exported permission: 'administer sendgrid settings'.
  $permissions['administer sendgrid settings'] = array(
    'name' => 'administer sendgrid settings',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'sendgrid_integration',
  );

  // Exported permission: 'administer simplify'.
  $permissions['administer simplify'] = array(
    'name' => 'administer simplify',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'simplify',
  );

  // Exported permission: 'administer site configuration'.
  $permissions['administer site configuration'] = array(
    'name' => 'administer site configuration',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer software updates'.
  $permissions['administer software updates'] = array(
    'name' => 'administer software updates',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer taxonomy'.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'administer themes'.
  $permissions['administer themes'] = array(
    'name' => 'administer themes',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer twitter accounts'.
  $permissions['administer twitter accounts'] = array(
    'name' => 'administer twitter accounts',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'twitter',
  );

  // Exported permission: 'administer url aliases'.
  $permissions['administer url aliases'] = array(
    'name' => 'administer url aliases',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'path',
  );

  // Exported permission: 'administer user locations'.
  $permissions['administer user locations'] = array(
    'name' => 'administer user locations',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'location_user',
  );

  // Exported permission: 'administer users'.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer uuid'.
  $permissions['administer uuid'] = array(
    'name' => 'administer uuid',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'uuid',
  );

  // Exported permission: 'administer video styles'.
  $permissions['administer video styles'] = array(
    'name' => 'administer video styles',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'video_embed_field',
  );

  // Exported permission: 'administer views'.
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: 'administer voting api'.
  $permissions['administer voting api'] = array(
    'name' => 'administer voting api',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'votingapi',
  );

  // Exported permission: 'allow disabling privatemsg'.
  $permissions['allow disabling privatemsg'] = array(
    'name' => 'allow disabling privatemsg',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Constituent' => 'Constituent',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Senator' => 'Senator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'privatemsg',
  );

  // Exported permission: 'block IP addresses'.
  $permissions['block IP addresses'] = array(
    'name' => 'block IP addresses',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'bypass file access'.
  $permissions['bypass file access'] = array(
    'name' => 'bypass file access',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'bypass honeypot protection'.
  $permissions['bypass honeypot protection'] = array(
    'name' => 'bypass honeypot protection',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'honeypot',
  );

  // Exported permission: 'bypass node access'.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'bypass rules access'.
  $permissions['bypass rules access'] = array(
    'name' => 'bypass rules access',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'cancel account'.
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'cancel own vote'.
  $permissions['cancel own vote'] = array(
    'name' => 'cancel own vote',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'advpoll',
  );

  // Exported permission: 'change layouts in place editing'.
  $permissions['change layouts in place editing'] = array(
    'name' => 'change layouts in place editing',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'change own username'.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'create advpoll content'.
  $permissions['create advpoll content'] = array(
    'name' => 'create advpoll content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Frontpage Editor' => 'Frontpage Editor',
      'Microsite Content Producer' => 'Microsite Content Producer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create agenda content'.
  $permissions['create agenda content'] = array(
    'name' => 'create agenda content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create article content'.
  $permissions['create article content'] = array(
    'name' => 'create article content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Senator' => 'Senator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create bill content'.
  $permissions['create bill content'] = array(
    'name' => 'create bill content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create calendar content'.
  $permissions['create calendar content'] = array(
    'name' => 'create calendar content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create chapter content'.
  $permissions['create chapter content'] = array(
    'name' => 'create chapter content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'FOIL Administrator' => 'FOIL Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Senator' => 'Senator',
      'Student Programs' => 'Student Programs',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create event content'.
  $permissions['create event content'] = array(
    'name' => 'create event content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Frontpage Editor' => 'Frontpage Editor',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Senator' => 'Senator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create field_assemblymen_chair'.
  $permissions['create field_assemblymen_chair'] = array(
    'name' => 'create field_assemblymen_chair',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_chair'.
  $permissions['create field_chair'] = array(
    'name' => 'create field_chair',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_ldap_username'.
  $permissions['create field_ldap_username'] = array(
    'name' => 'create field_ldap_username',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_members'.
  $permissions['create field_members'] = array(
    'name' => 'create field_members',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_senator_inbox_access'.
  $permissions['create field_senator_inbox_access'] = array(
    'name' => 'create field_senator_inbox_access',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_senator_management'.
  $permissions['create field_senator_management'] = array(
    'name' => 'create field_senator_management',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create files'.
  $permissions['create files'] = array(
    'name' => 'create files',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Student Programs' => 'Student Programs',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'create in_the_news content'.
  $permissions['create in_the_news content'] = array(
    'name' => 'create in_the_news content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Senator' => 'Senator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create initiative content'.
  $permissions['create initiative content'] = array(
    'name' => 'create initiative content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Senator' => 'Senator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create meeting content'.
  $permissions['create meeting content'] = array(
    'name' => 'create meeting content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create open_data content'.
  $permissions['create open_data content'] = array(
    'name' => 'create open_data content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create page_content content'.
  $permissions['create page_content content'] = array(
    'name' => 'create page_content content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create petition content'.
  $permissions['create petition content'] = array(
    'name' => 'create petition content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Senator' => 'Senator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create photo content'.
  $permissions['create photo content'] = array(
    'name' => 'create photo content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Senator' => 'Senator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create press_release content'.
  $permissions['create press_release content'] = array(
    'name' => 'create press_release content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Frontpage Editor' => 'Frontpage Editor',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Senator' => 'Senator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create private message tags'.
  $permissions['create private message tags'] = array(
    'name' => 'create private message tags',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'privatemsg_filter',
  );

  // Exported permission: 'create promotional_banner content'.
  $permissions['create promotional_banner content'] = array(
    'name' => 'create promotional_banner content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Senator' => 'Senator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create public_hearing content'.
  $permissions['create public_hearing content'] = array(
    'name' => 'create public_hearing content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create questionnaire content'.
  $permissions['create questionnaire content'] = array(
    'name' => 'create questionnaire content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Senator' => 'Senator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create resolution content'.
  $permissions['create resolution content'] = array(
    'name' => 'create resolution content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create senator content'.
  $permissions['create senator content'] = array(
    'name' => 'create senator content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create session content'.
  $permissions['create session content'] = array(
    'name' => 'create session content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create student_program content'.
  $permissions['create student_program content'] = array(
    'name' => 'create student_program content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Student Programs' => 'Student Programs',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create timeline_item content'.
  $permissions['create timeline_item content'] = array(
    'name' => 'create timeline_item content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create transcript content'.
  $permissions['create transcript content'] = array(
    'name' => 'create transcript content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create url aliases'.
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'path',
  );

  // Exported permission: 'create video content'.
  $permissions['create video content'] = array(
    'name' => 'create video content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Senator' => 'Senator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create webform content'.
  $permissions['create webform content'] = array(
    'name' => 'create webform content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'FOIL Administrator' => 'FOIL Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'dashboard inbox check all'.
  $permissions['dashboard inbox check all'] = array(
    'name' => 'dashboard inbox check all',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senator' => 'Senator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'nys_inbox',
  );

  // Exported permission: 'dashboard inbox forward messages'.
  $permissions['dashboard inbox forward messages'] = array(
    'name' => 'dashboard inbox forward messages',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senator' => 'Senator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'nys_inbox',
  );

  // Exported permission: 'dashboard inbox search bills'.
  $permissions['dashboard inbox search bills'] = array(
    'name' => 'dashboard inbox search bills',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senator' => 'Senator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'nys_inbox',
  );

  // Exported permission: 'dashboard inbox search issues'.
  $permissions['dashboard inbox search issues'] = array(
    'name' => 'dashboard inbox search issues',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senator' => 'Senator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'nys_inbox',
  );

  // Exported permission: 'dashboard inbox search names'.
  $permissions['dashboard inbox search names'] = array(
    'name' => 'dashboard inbox search names',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Legislative Correspondent' => 'Legislative Correspondent',
      'Senator' => 'Senator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'nys_inbox',
  );

  // Exported permission: 'delete all webform submissions'.
  $permissions['delete all webform submissions'] = array(
    'name' => 'delete all webform submissions',
    'roles' => array(
      'Administrator' => 'Administrator',
      'FOIL Administrator' => 'FOIL Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'delete any advpoll content'.
  $permissions['delete any advpoll content'] = array(
    'name' => 'delete any advpoll content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any agenda content'.
  $permissions['delete any agenda content'] = array(
    'name' => 'delete any agenda content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any article content'.
  $permissions['delete any article content'] = array(
    'name' => 'delete any article content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any audio files'.
  $permissions['delete any audio files'] = array(
    'name' => 'delete any audio files',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any bill content'.
  $permissions['delete any bill content'] = array(
    'name' => 'delete any bill content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any calendar content'.
  $permissions['delete any calendar content'] = array(
    'name' => 'delete any calendar content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any chapter content'.
  $permissions['delete any chapter content'] = array(
    'name' => 'delete any chapter content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'FOIL Administrator' => 'FOIL Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any document files'.
  $permissions['delete any document files'] = array(
    'name' => 'delete any document files',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any event content'.
  $permissions['delete any event content'] = array(
    'name' => 'delete any event content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Frontpage Editor' => 'Frontpage Editor',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any image files'.
  $permissions['delete any image files'] = array(
    'name' => 'delete any image files',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any in_the_news content'.
  $permissions['delete any in_the_news content'] = array(
    'name' => 'delete any in_the_news content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any initiative content'.
  $permissions['delete any initiative content'] = array(
    'name' => 'delete any initiative content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any meeting content'.
  $permissions['delete any meeting content'] = array(
    'name' => 'delete any meeting content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any open_data content'.
  $permissions['delete any open_data content'] = array(
    'name' => 'delete any open_data content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any page_content content'.
  $permissions['delete any page_content content'] = array(
    'name' => 'delete any page_content content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any petition content'.
  $permissions['delete any petition content'] = array(
    'name' => 'delete any petition content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any photo content'.
  $permissions['delete any photo content'] = array(
    'name' => 'delete any photo content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any press_release content'.
  $permissions['delete any press_release content'] = array(
    'name' => 'delete any press_release content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any promotional_banner content'.
  $permissions['delete any promotional_banner content'] = array(
    'name' => 'delete any promotional_banner content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any public_hearing content'.
  $permissions['delete any public_hearing content'] = array(
    'name' => 'delete any public_hearing content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any questionnaire content'.
  $permissions['delete any questionnaire content'] = array(
    'name' => 'delete any questionnaire content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any resolution content'.
  $permissions['delete any resolution content'] = array(
    'name' => 'delete any resolution content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any senator content'.
  $permissions['delete any senator content'] = array(
    'name' => 'delete any senator content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any session content'.
  $permissions['delete any session content'] = array(
    'name' => 'delete any session content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any student_program content'.
  $permissions['delete any student_program content'] = array(
    'name' => 'delete any student_program content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Student Programs' => 'Student Programs',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any timeline_item content'.
  $permissions['delete any timeline_item content'] = array(
    'name' => 'delete any timeline_item content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any transcript content'.
  $permissions['delete any transcript content'] = array(
    'name' => 'delete any transcript content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any video content'.
  $permissions['delete any video content'] = array(
    'name' => 'delete any video content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any video files'.
  $permissions['delete any video files'] = array(
    'name' => 'delete any video files',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any webform content'.
  $permissions['delete any webform content'] = array(
    'name' => 'delete any webform content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own advpoll content'.
  $permissions['delete own advpoll content'] = array(
    'name' => 'delete own advpoll content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Frontpage Editor' => 'Frontpage Editor',
      'Microsite Content Producer' => 'Microsite Content Producer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own agenda content'.
  $permissions['delete own agenda content'] = array(
    'name' => 'delete own agenda content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own article content'.
  $permissions['delete own article content'] = array(
    'name' => 'delete own article content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Senator' => 'Senator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own audio files'.
  $permissions['delete own audio files'] = array(
    'name' => 'delete own audio files',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own bill content'.
  $permissions['delete own bill content'] = array(
    'name' => 'delete own bill content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own calendar content'.
  $permissions['delete own calendar content'] = array(
    'name' => 'delete own calendar content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own chapter content'.
  $permissions['delete own chapter content'] = array(
    'name' => 'delete own chapter content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'FOIL Administrator' => 'FOIL Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Senator' => 'Senator',
      'Student Programs' => 'Student Programs',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own document files'.
  $permissions['delete own document files'] = array(
    'name' => 'delete own document files',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own event content'.
  $permissions['delete own event content'] = array(
    'name' => 'delete own event content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Frontpage Editor' => 'Frontpage Editor',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own image files'.
  $permissions['delete own image files'] = array(
    'name' => 'delete own image files',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own in_the_news content'.
  $permissions['delete own in_the_news content'] = array(
    'name' => 'delete own in_the_news content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Senator' => 'Senator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own initiative content'.
  $permissions['delete own initiative content'] = array(
    'name' => 'delete own initiative content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Senator' => 'Senator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own meeting content'.
  $permissions['delete own meeting content'] = array(
    'name' => 'delete own meeting content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own open_data content'.
  $permissions['delete own open_data content'] = array(
    'name' => 'delete own open_data content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own page_content content'.
  $permissions['delete own page_content content'] = array(
    'name' => 'delete own page_content content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own petition content'.
  $permissions['delete own petition content'] = array(
    'name' => 'delete own petition content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Senator' => 'Senator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own photo content'.
  $permissions['delete own photo content'] = array(
    'name' => 'delete own photo content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Senator' => 'Senator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own press_release content'.
  $permissions['delete own press_release content'] = array(
    'name' => 'delete own press_release content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Frontpage Editor' => 'Frontpage Editor',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Senator' => 'Senator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own promotional_banner content'.
  $permissions['delete own promotional_banner content'] = array(
    'name' => 'delete own promotional_banner content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Senator' => 'Senator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own public_hearing content'.
  $permissions['delete own public_hearing content'] = array(
    'name' => 'delete own public_hearing content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own questionnaire content'.
  $permissions['delete own questionnaire content'] = array(
    'name' => 'delete own questionnaire content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Senator' => 'Senator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own resolution content'.
  $permissions['delete own resolution content'] = array(
    'name' => 'delete own resolution content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own senator content'.
  $permissions['delete own senator content'] = array(
    'name' => 'delete own senator content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own session content'.
  $permissions['delete own session content'] = array(
    'name' => 'delete own session content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own student_program content'.
  $permissions['delete own student_program content'] = array(
    'name' => 'delete own student_program content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Student Programs' => 'Student Programs',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own timeline_item content'.
  $permissions['delete own timeline_item content'] = array(
    'name' => 'delete own timeline_item content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own transcript content'.
  $permissions['delete own transcript content'] = array(
    'name' => 'delete own transcript content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own video content'.
  $permissions['delete own video content'] = array(
    'name' => 'delete own video content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Senator' => 'Senator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own video files'.
  $permissions['delete own video files'] = array(
    'name' => 'delete own video files',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own webform content'.
  $permissions['delete own webform content'] = array(
    'name' => 'delete own webform content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'FOIL Administrator' => 'FOIL Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own webform submissions'.
  $permissions['delete own webform submissions'] = array(
    'name' => 'delete own webform submissions',
    'roles' => array(
      'Administrator' => 'Administrator',
      'FOIL Administrator' => 'FOIL Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Senator' => 'Senator',
      'Student Programs' => 'Student Programs',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'delete privatemsg'.
  $permissions['delete privatemsg'] = array(
    'name' => 'delete privatemsg',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Constituent' => 'Constituent',
      'Senator' => 'Senator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'privatemsg',
  );

  // Exported permission: 'delete revisions'.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in committees'.
  $permissions['delete terms in committees'] = array(
    'name' => 'delete terms in committees',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in districts'.
  $permissions['delete terms in districts'] = array(
    'name' => 'delete terms in districts',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in issues'.
  $permissions['delete terms in issues'] = array(
    'name' => 'delete terms in issues',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'display disqus comments on profile'.
  $permissions['display disqus comments on profile'] = array(
    'name' => 'display disqus comments on profile',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Constituent' => 'Constituent',
    ),
    'module' => 'disqus',
  );

  // Exported permission: 'download any audio files'.
  $permissions['download any audio files'] = array(
    'name' => 'download any audio files',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any document files'.
  $permissions['download any document files'] = array(
    'name' => 'download any document files',
    'roles' => array(
      'Administrator' => 'Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any image files'.
  $permissions['download any image files'] = array(
    'name' => 'download any image files',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any video files'.
  $permissions['download any video files'] = array(
    'name' => 'download any video files',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own audio files'.
  $permissions['download own audio files'] = array(
    'name' => 'download own audio files',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own document files'.
  $permissions['download own document files'] = array(
    'name' => 'download own document files',
    'roles' => array(
      'Administrator' => 'Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own image files'.
  $permissions['download own image files'] = array(
    'name' => 'download own image files',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own video files'.
  $permissions['download own video files'] = array(
    'name' => 'download own video files',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit all webform submissions'.
  $permissions['edit all webform submissions'] = array(
    'name' => 'edit all webform submissions',
    'roles' => array(
      'Administrator' => 'Administrator',
      'FOIL Administrator' => 'FOIL Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'edit any advpoll content'.
  $permissions['edit any advpoll content'] = array(
    'name' => 'edit any advpoll content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any agenda content'.
  $permissions['edit any agenda content'] = array(
    'name' => 'edit any agenda content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any article content'.
  $permissions['edit any article content'] = array(
    'name' => 'edit any article content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any audio files'.
  $permissions['edit any audio files'] = array(
    'name' => 'edit any audio files',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any bill content'.
  $permissions['edit any bill content'] = array(
    'name' => 'edit any bill content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any calendar content'.
  $permissions['edit any calendar content'] = array(
    'name' => 'edit any calendar content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any chapter content'.
  $permissions['edit any chapter content'] = array(
    'name' => 'edit any chapter content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'FOIL Administrator' => 'FOIL Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any document files'.
  $permissions['edit any document files'] = array(
    'name' => 'edit any document files',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any entityform'.
  $permissions['edit any entityform'] = array(
    'name' => 'edit any entityform',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Student Contest Judge' => 'Student Contest Judge',
    ),
    'module' => 'entityform',
  );

  // Exported permission: 'edit any event content'.
  $permissions['edit any event content'] = array(
    'name' => 'edit any event content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Frontpage Editor' => 'Frontpage Editor',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any image files'.
  $permissions['edit any image files'] = array(
    'name' => 'edit any image files',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any in_the_news content'.
  $permissions['edit any in_the_news content'] = array(
    'name' => 'edit any in_the_news content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any initiative content'.
  $permissions['edit any initiative content'] = array(
    'name' => 'edit any initiative content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any meeting content'.
  $permissions['edit any meeting content'] = array(
    'name' => 'edit any meeting content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any open_data content'.
  $permissions['edit any open_data content'] = array(
    'name' => 'edit any open_data content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any page_content content'.
  $permissions['edit any page_content content'] = array(
    'name' => 'edit any page_content content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any petition content'.
  $permissions['edit any petition content'] = array(
    'name' => 'edit any petition content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any photo content'.
  $permissions['edit any photo content'] = array(
    'name' => 'edit any photo content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any press_release content'.
  $permissions['edit any press_release content'] = array(
    'name' => 'edit any press_release content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any promotional_banner content'.
  $permissions['edit any promotional_banner content'] = array(
    'name' => 'edit any promotional_banner content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any public_hearing content'.
  $permissions['edit any public_hearing content'] = array(
    'name' => 'edit any public_hearing content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any questionnaire content'.
  $permissions['edit any questionnaire content'] = array(
    'name' => 'edit any questionnaire content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any resolution content'.
  $permissions['edit any resolution content'] = array(
    'name' => 'edit any resolution content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any senator content'.
  $permissions['edit any senator content'] = array(
    'name' => 'edit any senator content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any session content'.
  $permissions['edit any session content'] = array(
    'name' => 'edit any session content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any student_program content'.
  $permissions['edit any student_program content'] = array(
    'name' => 'edit any student_program content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Student Programs' => 'Student Programs',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any timeline_item content'.
  $permissions['edit any timeline_item content'] = array(
    'name' => 'edit any timeline_item content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any transcript content'.
  $permissions['edit any transcript content'] = array(
    'name' => 'edit any transcript content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any video content'.
  $permissions['edit any video content'] = array(
    'name' => 'edit any video content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any video files'.
  $permissions['edit any video files'] = array(
    'name' => 'edit any video files',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any webform content'.
  $permissions['edit any webform content'] = array(
    'name' => 'edit any webform content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'FOIL Administrator' => 'FOIL Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit field_assemblymen_chair'.
  $permissions['edit field_assemblymen_chair'] = array(
    'name' => 'edit field_assemblymen_chair',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_chair'.
  $permissions['edit field_chair'] = array(
    'name' => 'edit field_chair',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_ldap_username'.
  $permissions['edit field_ldap_username'] = array(
    'name' => 'edit field_ldap_username',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_members'.
  $permissions['edit field_members'] = array(
    'name' => 'edit field_members',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_senator_inbox_access'.
  $permissions['edit field_senator_inbox_access'] = array(
    'name' => 'edit field_senator_inbox_access',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_senator_management'.
  $permissions['edit field_senator_management'] = array(
    'name' => 'edit field_senator_management',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit meta tags'.
  $permissions['edit meta tags'] = array(
    'name' => 'edit meta tags',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit own advpoll content'.
  $permissions['edit own advpoll content'] = array(
    'name' => 'edit own advpoll content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Frontpage Editor' => 'Frontpage Editor',
      'Microsite Content Producer' => 'Microsite Content Producer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own agenda content'.
  $permissions['edit own agenda content'] = array(
    'name' => 'edit own agenda content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own article content'.
  $permissions['edit own article content'] = array(
    'name' => 'edit own article content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Senator' => 'Senator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own audio files'.
  $permissions['edit own audio files'] = array(
    'name' => 'edit own audio files',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own bill content'.
  $permissions['edit own bill content'] = array(
    'name' => 'edit own bill content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own calendar content'.
  $permissions['edit own calendar content'] = array(
    'name' => 'edit own calendar content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own chapter content'.
  $permissions['edit own chapter content'] = array(
    'name' => 'edit own chapter content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'FOIL Administrator' => 'FOIL Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Senator' => 'Senator',
      'Student Programs' => 'Student Programs',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own document files'.
  $permissions['edit own document files'] = array(
    'name' => 'edit own document files',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own event content'.
  $permissions['edit own event content'] = array(
    'name' => 'edit own event content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Frontpage Editor' => 'Frontpage Editor',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Senator' => 'Senator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own field_assemblymen_chair'.
  $permissions['edit own field_assemblymen_chair'] = array(
    'name' => 'edit own field_assemblymen_chair',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_chair'.
  $permissions['edit own field_chair'] = array(
    'name' => 'edit own field_chair',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_ldap_username'.
  $permissions['edit own field_ldap_username'] = array(
    'name' => 'edit own field_ldap_username',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_members'.
  $permissions['edit own field_members'] = array(
    'name' => 'edit own field_members',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_senator_inbox_access'.
  $permissions['edit own field_senator_inbox_access'] = array(
    'name' => 'edit own field_senator_inbox_access',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_senator_management'.
  $permissions['edit own field_senator_management'] = array(
    'name' => 'edit own field_senator_management',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own image files'.
  $permissions['edit own image files'] = array(
    'name' => 'edit own image files',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own in_the_news content'.
  $permissions['edit own in_the_news content'] = array(
    'name' => 'edit own in_the_news content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Senator' => 'Senator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own initiative content'.
  $permissions['edit own initiative content'] = array(
    'name' => 'edit own initiative content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Senator' => 'Senator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own meeting content'.
  $permissions['edit own meeting content'] = array(
    'name' => 'edit own meeting content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own open_data content'.
  $permissions['edit own open_data content'] = array(
    'name' => 'edit own open_data content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own page_content content'.
  $permissions['edit own page_content content'] = array(
    'name' => 'edit own page_content content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own petition content'.
  $permissions['edit own petition content'] = array(
    'name' => 'edit own petition content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Senator' => 'Senator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own photo content'.
  $permissions['edit own photo content'] = array(
    'name' => 'edit own photo content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Senator' => 'Senator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own press_release content'.
  $permissions['edit own press_release content'] = array(
    'name' => 'edit own press_release content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Frontpage Editor' => 'Frontpage Editor',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Senator' => 'Senator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own promotional_banner content'.
  $permissions['edit own promotional_banner content'] = array(
    'name' => 'edit own promotional_banner content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Senator' => 'Senator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own public_hearing content'.
  $permissions['edit own public_hearing content'] = array(
    'name' => 'edit own public_hearing content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own questionnaire content'.
  $permissions['edit own questionnaire content'] = array(
    'name' => 'edit own questionnaire content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Senator' => 'Senator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own resolution content'.
  $permissions['edit own resolution content'] = array(
    'name' => 'edit own resolution content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own senator content'.
  $permissions['edit own senator content'] = array(
    'name' => 'edit own senator content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own session content'.
  $permissions['edit own session content'] = array(
    'name' => 'edit own session content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own student_program content'.
  $permissions['edit own student_program content'] = array(
    'name' => 'edit own student_program content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Student Programs' => 'Student Programs',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own timeline_item content'.
  $permissions['edit own timeline_item content'] = array(
    'name' => 'edit own timeline_item content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own transcript content'.
  $permissions['edit own transcript content'] = array(
    'name' => 'edit own transcript content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own video content'.
  $permissions['edit own video content'] = array(
    'name' => 'edit own video content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Senator' => 'Senator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own video files'.
  $permissions['edit own video files'] = array(
    'name' => 'edit own video files',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own webform content'.
  $permissions['edit own webform content'] = array(
    'name' => 'edit own webform content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'FOIL Administrator' => 'FOIL Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own webform submissions'.
  $permissions['edit own webform submissions'] = array(
    'name' => 'edit own webform submissions',
    'roles' => array(
      'Administrator' => 'Administrator',
      'FOIL Administrator' => 'FOIL Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Senator' => 'Senator',
      'Student Programs' => 'Student Programs',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'edit same role'.
  $permissions['edit same role'] = array(
    'name' => 'edit same role',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Frontpage Editor' => 'Frontpage Editor',
    ),
    'module' => 'nys_access_permissions',
  );

  // Exported permission: 'edit terms in committees'.
  $permissions['edit terms in committees'] = array(
    'name' => 'edit terms in committees',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in districts'.
  $permissions['edit terms in districts'] = array(
    'name' => 'edit terms in districts',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in issues'.
  $permissions['edit terms in issues'] = array(
    'name' => 'edit terms in issues',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit webform components'.
  $permissions['edit webform components'] = array(
    'name' => 'edit webform components',
    'roles' => array(
      'Administrator' => 'Administrator',
      'FOIL Administrator' => 'FOIL Administrator',
      'Web Administrator' => 'Web Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'execute node_assign_owner_action'.
  $permissions['execute node_assign_owner_action'] = array(
    'name' => 'execute node_assign_owner_action',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute node_make_sticky_action'.
  $permissions['execute node_make_sticky_action'] = array(
    'name' => 'execute node_make_sticky_action',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute node_make_unsticky_action'.
  $permissions['execute node_make_unsticky_action'] = array(
    'name' => 'execute node_make_unsticky_action',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute node_promote_action'.
  $permissions['execute node_promote_action'] = array(
    'name' => 'execute node_promote_action',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute node_publish_action'.
  $permissions['execute node_publish_action'] = array(
    'name' => 'execute node_publish_action',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Student Programs' => 'Student Programs',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute node_save_action'.
  $permissions['execute node_save_action'] = array(
    'name' => 'execute node_save_action',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Student Programs' => 'Student Programs',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute node_unpromote_action'.
  $permissions['execute node_unpromote_action'] = array(
    'name' => 'execute node_unpromote_action',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute node_unpublish_action'.
  $permissions['execute node_unpublish_action'] = array(
    'name' => 'execute node_unpublish_action',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Student Programs' => 'Student Programs',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute node_unpublish_by_keyword_action'.
  $permissions['execute node_unpublish_by_keyword_action'] = array(
    'name' => 'execute node_unpublish_by_keyword_action',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute nys_utils_set_accessible_sitewide'.
  $permissions['execute nys_utils_set_accessible_sitewide'] = array(
    'name' => 'execute nys_utils_set_accessible_sitewide',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Frontpage Editor' => 'Frontpage Editor',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute nys_utils_unset_accessible_sitewide'.
  $permissions['execute nys_utils_unset_accessible_sitewide'] = array(
    'name' => 'execute nys_utils_unset_accessible_sitewide',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Frontpage Editor' => 'Frontpage Editor',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute pathauto_file_update_action'.
  $permissions['execute pathauto_file_update_action'] = array(
    'name' => 'execute pathauto_file_update_action',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute pathauto_node_update_action'.
  $permissions['execute pathauto_node_update_action'] = array(
    'name' => 'execute pathauto_node_update_action',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute pathauto_taxonomy_term_update_action'.
  $permissions['execute pathauto_taxonomy_term_update_action'] = array(
    'name' => 'execute pathauto_taxonomy_term_update_action',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute pathauto_user_update_action'.
  $permissions['execute pathauto_user_update_action'] = array(
    'name' => 'execute pathauto_user_update_action',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute system_block_ip_action'.
  $permissions['execute system_block_ip_action'] = array(
    'name' => 'execute system_block_ip_action',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute system_goto_action'.
  $permissions['execute system_goto_action'] = array(
    'name' => 'execute system_goto_action',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute system_message_action'.
  $permissions['execute system_message_action'] = array(
    'name' => 'execute system_message_action',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute system_send_email_action'.
  $permissions['execute system_send_email_action'] = array(
    'name' => 'execute system_send_email_action',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute user_block_user_action'.
  $permissions['execute user_block_user_action'] = array(
    'name' => 'execute user_block_user_action',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute views_bulk_operations_argument_selector_action'.
  $permissions['execute views_bulk_operations_argument_selector_action'] = array(
    'name' => 'execute views_bulk_operations_argument_selector_action',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute views_bulk_operations_delete_item'.
  $permissions['execute views_bulk_operations_delete_item'] = array(
    'name' => 'execute views_bulk_operations_delete_item',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute views_bulk_operations_delete_revision'.
  $permissions['execute views_bulk_operations_delete_revision'] = array(
    'name' => 'execute views_bulk_operations_delete_revision',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute views_bulk_operations_modify_action'.
  $permissions['execute views_bulk_operations_modify_action'] = array(
    'name' => 'execute views_bulk_operations_modify_action',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Student Contest Judge' => 'Student Contest Judge',
      'Student Programs' => 'Student Programs',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute views_bulk_operations_script_action'.
  $permissions['execute views_bulk_operations_script_action'] = array(
    'name' => 'execute views_bulk_operations_script_action',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute views_bulk_operations_user_cancel_action'.
  $permissions['execute views_bulk_operations_user_cancel_action'] = array(
    'name' => 'execute views_bulk_operations_user_cancel_action',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute views_bulk_operations_user_roles_action'.
  $permissions['execute views_bulk_operations_user_roles_action'] = array(
    'name' => 'execute views_bulk_operations_user_roles_action',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'field hidden administer'.
  $permissions['field hidden administer'] = array(
    'name' => 'field hidden administer',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'field_hidden',
  );

  // Exported permission: 'filter private messages'.
  $permissions['filter private messages'] = array(
    'name' => 'filter private messages',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'privatemsg_filter',
  );

  // Exported permission: 'flag bookmarks'.
  $permissions['flag bookmarks'] = array(
    'name' => 'flag bookmarks',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Constituent' => 'Constituent',
      'Senator' => 'Senator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flag follow_committee'.
  $permissions['flag follow_committee'] = array(
    'name' => 'flag follow_committee',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Constituent' => 'Constituent',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Web Administrator' => 'Web Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flag follow_group'.
  $permissions['flag follow_group'] = array(
    'name' => 'flag follow_group',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flag follow_issue'.
  $permissions['flag follow_issue'] = array(
    'name' => 'flag follow_issue',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Constituent' => 'Constituent',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Senator' => 'Senator',
      'Web Administrator' => 'Web Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flag follow_this_bill'.
  $permissions['flag follow_this_bill'] = array(
    'name' => 'flag follow_this_bill',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Web Administrator' => 'Web Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flag sign_petition'.
  $permissions['flag sign_petition'] = array(
    'name' => 'flag sign_petition',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Constituent' => 'Constituent',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Senator' => 'Senator',
      'Web Administrator' => 'Web Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'generate features'.
  $permissions['generate features'] = array(
    'name' => 'generate features',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'grant per own webform permissions'.
  $permissions['grant per own webform permissions'] = array(
    'name' => 'grant per own webform permissions',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'permissions_per_webform',
  );

  // Exported permission: 'grant per webform permissions'.
  $permissions['grant per webform permissions'] = array(
    'name' => 'grant per webform permissions',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'permissions_per_webform',
  );

  // Exported permission: 'inspect all votes'.
  $permissions['inspect all votes'] = array(
    'name' => 'inspect all votes',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'advpoll',
  );

  // Exported permission: 'manage features'.
  $permissions['manage features'] = array(
    'name' => 'manage features',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'manipulate all queues'.
  $permissions['manipulate all queues'] = array(
    'name' => 'manipulate all queues',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Frontpage Editor' => 'Frontpage Editor',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'nodequeue',
  );

  // Exported permission: 'manipulate queues'.
  $permissions['manipulate queues'] = array(
    'name' => 'manipulate queues',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Frontpage Editor' => 'Frontpage Editor',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'nodequeue',
  );

  // Exported permission: 'notify of path changes'.
  $permissions['notify of path changes'] = array(
    'name' => 'notify of path changes',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: 'oauth authorize any consumers'.
  $permissions['oauth authorize any consumers'] = array(
    'name' => 'oauth authorize any consumers',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'oauth_common',
  );

  // Exported permission: 'oauth register any consumers'.
  $permissions['oauth register any consumers'] = array(
    'name' => 'oauth register any consumers',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'oauth_common',
  );

  // Exported permission: 'read all private messages'.
  $permissions['read all private messages'] = array(
    'name' => 'read all private messages',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'privatemsg',
  );

  // Exported permission: 'read privatemsg'.
  $permissions['read privatemsg'] = array(
    'name' => 'read privatemsg',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Constituent' => 'Constituent',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Senator' => 'Senator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'privatemsg',
  );

  // Exported permission: 'rename features'.
  $permissions['rename features'] = array(
    'name' => 'rename features',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'reply only privatemsg'.
  $permissions['reply only privatemsg'] = array(
    'name' => 'reply only privatemsg',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Constituent' => 'Constituent',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'privatemsg',
  );

  // Exported permission: 'report private messages to mollom'.
  $permissions['report private messages to mollom'] = array(
    'name' => 'report private messages to mollom',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'privatemsg',
  );

  // Exported permission: 'revert revisions'.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'search content'.
  $permissions['search content'] = array(
    'name' => 'search content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Constituent' => 'Constituent',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Web Administrator' => 'Web Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'search',
  );

  // Exported permission: 'select account cancellation method'.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'select text format for privatemsg'.
  $permissions['select text format for privatemsg'] = array(
    'name' => 'select text format for privatemsg',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'privatemsg',
  );

  // Exported permission: 'set own user location'.
  $permissions['set own user location'] = array(
    'name' => 'set own user location',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'location_user',
  );

  // Exported permission: 'show vote results'.
  $permissions['show vote results'] = array(
    'name' => 'show vote results',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'advpoll',
  );

  // Exported permission: 'show write-ins'.
  $permissions['show write-ins'] = array(
    'name' => 'show write-ins',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'advpoll',
  );

  // Exported permission: 'skip CAPTCHA'.
  $permissions['skip CAPTCHA'] = array(
    'name' => 'skip CAPTCHA',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Frontpage Editor' => 'Frontpage Editor',
      'Student Contest Judge' => 'Student Contest Judge',
      'Student Programs' => 'Student Programs',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'captcha',
  );

  // Exported permission: 'submit latitude/longitude'.
  $permissions['submit latitude/longitude'] = array(
    'name' => 'submit latitude/longitude',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'location',
  );

  // Exported permission: 'tag private messages'.
  $permissions['tag private messages'] = array(
    'name' => 'tag private messages',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'privatemsg_filter',
  );

  // Exported permission: 'toggle disqus comments'.
  $permissions['toggle disqus comments'] = array(
    'name' => 'toggle disqus comments',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'disqus',
  );

  // Exported permission: 'unflag bookmarks'.
  $permissions['unflag bookmarks'] = array(
    'name' => 'unflag bookmarks',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Constituent' => 'Constituent',
      'Senator' => 'Senator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag follow_committee'.
  $permissions['unflag follow_committee'] = array(
    'name' => 'unflag follow_committee',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Constituent' => 'Constituent',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Web Administrator' => 'Web Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag follow_group'.
  $permissions['unflag follow_group'] = array(
    'name' => 'unflag follow_group',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag follow_issue'.
  $permissions['unflag follow_issue'] = array(
    'name' => 'unflag follow_issue',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Constituent' => 'Constituent',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Senator' => 'Senator',
      'Web Administrator' => 'Web Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag follow_this_bill'.
  $permissions['unflag follow_this_bill'] = array(
    'name' => 'unflag follow_this_bill',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Web Administrator' => 'Web Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag sign_petition'.
  $permissions['unflag sign_petition'] = array(
    'name' => 'unflag sign_petition',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'use advanced search'.
  $permissions['use advanced search'] = array(
    'name' => 'use advanced search',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Constituent' => 'Constituent',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Web Administrator' => 'Web Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'search',
  );

  // Exported permission: 'use ctools import'.
  $permissions['use ctools import'] = array(
    'name' => 'use ctools import',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'ctools',
  );

  // Exported permission: 'use flag import'.
  $permissions['use flag import'] = array(
    'name' => 'use flag import',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'use ipe with page manager'.
  $permissions['use ipe with page manager'] = array(
    'name' => 'use ipe with page manager',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use page manager'.
  $permissions['use page manager'] = array(
    'name' => 'use page manager',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'page_manager',
  );

  // Exported permission: 'use panels caching features'.
  $permissions['use panels caching features'] = array(
    'name' => 'use panels caching features',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use panels dashboard'.
  $permissions['use panels dashboard'] = array(
    'name' => 'use panels dashboard',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use panels in place editing'.
  $permissions['use panels in place editing'] = array(
    'name' => 'use panels in place editing',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use panels locks'.
  $permissions['use panels locks'] = array(
    'name' => 'use panels locks',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use text format full_html'.
  $permissions['use text format full_html'] = array(
    'name' => 'use text format full_html',
    'roles' => array(
      'Administrator' => 'Administrator',
      'FOIL Administrator' => 'FOIL Administrator',
      'Frontpage Editor' => 'Frontpage Editor',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Senator' => 'Senator',
      'Student Programs' => 'Student Programs',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format source_html'.
  $permissions['use text format source_html'] = array(
    'name' => 'use text format source_html',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Expert MCP' => 'Expert MCP',
      'Frontpage Editor' => 'Frontpage Editor',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use tokens in privatemsg'.
  $permissions['use tokens in privatemsg'] = array(
    'name' => 'use tokens in privatemsg',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'privatemsg',
  );

  // Exported permission: 'view all user locations'.
  $permissions['view all user locations'] = array(
    'name' => 'view all user locations',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'location_user',
  );

  // Exported permission: 'view any entityform'.
  $permissions['view any entityform'] = array(
    'name' => 'view any entityform',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Student Contest Judge' => 'Student Contest Judge',
    ),
    'module' => 'entityform',
  );

  // Exported permission: 'view disqus comments'.
  $permissions['view disqus comments'] = array(
    'name' => 'view disqus comments',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Constituent' => 'Constituent',
      'Frontpage Editor' => 'Frontpage Editor',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Student Programs' => 'Student Programs',
      'Web Administrator' => 'Web Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'disqus',
  );

  // Exported permission: 'view field_assemblymen_chair'.
  $permissions['view field_assemblymen_chair'] = array(
    'name' => 'view field_assemblymen_chair',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_chair'.
  $permissions['view field_chair'] = array(
    'name' => 'view field_chair',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_ldap_username'.
  $permissions['view field_ldap_username'] = array(
    'name' => 'view field_ldap_username',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_members'.
  $permissions['view field_members'] = array(
    'name' => 'view field_members',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Frontpage Editor' => 'Frontpage Editor',
      'Legislative Correspondent' => 'Legislative Correspondent',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Senator' => 'Senator',
      'Web Administrator' => 'Web Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_senator_inbox_access'.
  $permissions['view field_senator_inbox_access'] = array(
    'name' => 'view field_senator_inbox_access',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_senator_management'.
  $permissions['view field_senator_management'] = array(
    'name' => 'view field_senator_management',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view files'.
  $permissions['view files'] = array(
    'name' => 'view files',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Constituent' => 'Constituent',
      'Web Administrator' => 'Web Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view hidden fields'.
  $permissions['view hidden fields'] = array(
    'name' => 'view hidden fields',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Expert MCP' => 'Expert MCP',
      'Frontpage Editor' => 'Frontpage Editor',
    ),
    'module' => 'simplify',
  );

  // Exported permission: 'view location directory'.
  $permissions['view location directory'] = array(
    'name' => 'view location directory',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'location',
  );

  // Exported permission: 'view node location table'.
  $permissions['view node location table'] = array(
    'name' => 'view node location table',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'location',
  );

  // Exported permission: 'view own field_assemblymen_chair'.
  $permissions['view own field_assemblymen_chair'] = array(
    'name' => 'view own field_assemblymen_chair',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_chair'.
  $permissions['view own field_chair'] = array(
    'name' => 'view own field_chair',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_ldap_username'.
  $permissions['view own field_ldap_username'] = array(
    'name' => 'view own field_ldap_username',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_members'.
  $permissions['view own field_members'] = array(
    'name' => 'view own field_members',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Frontpage Editor' => 'Frontpage Editor',
      'Legislative Correspondent' => 'Legislative Correspondent',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Senator' => 'Senator',
      'Web Administrator' => 'Web Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_senator_inbox_access'.
  $permissions['view own field_senator_inbox_access'] = array(
    'name' => 'view own field_senator_inbox_access',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_senator_management'.
  $permissions['view own field_senator_management'] = array(
    'name' => 'view own field_senator_management',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own files'.
  $permissions['view own files'] = array(
    'name' => 'view own files',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Student Programs' => 'Student Programs',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view own private files'.
  $permissions['view own private files'] = array(
    'name' => 'view own private files',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Student Programs' => 'Student Programs',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view own unpublished content'.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Constituent' => 'Constituent',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Web Administrator' => 'Web Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view own user location'.
  $permissions['view own user location'] = array(
    'name' => 'view own user location',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'location_user',
  );

  // Exported permission: 'view pane admin links'.
  $permissions['view pane admin links'] = array(
    'name' => 'view pane admin links',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'view private files'.
  $permissions['view private files'] = array(
    'name' => 'view private files',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view revisions'.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Constituent' => 'Constituent',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view the administration theme'.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      'Administrator' => 'Administrator',
      'FOIL Administrator' => 'FOIL Administrator',
      'Frontpage Editor' => 'Frontpage Editor',
      'Legislative Correspondent' => 'Legislative Correspondent',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Senator' => 'Senator',
      'Student Contest Judge' => 'Student Contest Judge',
      'Student Programs' => 'Student Programs',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'view user location table'.
  $permissions['view user location table'] = array(
    'name' => 'view user location table',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'location',
  );

  // Exported permission: 'vote on polls'.
  $permissions['vote on polls'] = array(
    'name' => 'vote on polls',
    'roles' => array(
      'Administrator' => 'Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'advpoll',
  );

  // Exported permission: 'write privatemsg'.
  $permissions['write privatemsg'] = array(
    'name' => 'write privatemsg',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Constituent' => 'Constituent',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Senator' => 'Senator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'privatemsg',
  );

  return $permissions;
}
