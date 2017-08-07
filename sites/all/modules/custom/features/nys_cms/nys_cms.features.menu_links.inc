<?php
/**
 * @file
 * nys_cms.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function nys_cms_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-frontpage-editor-menu_create-events:node/add/event
  $menu_links['menu-frontpage-editor-menu_create-events:node/add/event'] = array(
    'menu_name' => 'menu-frontpage-editor-menu',
    'link_path' => 'node/add/event',
    'router_path' => 'node/add/event',
    'link_title' => 'Create Events',
    'options' => array(
      'attributes' => array(
        'title' => 'Create sitewide events.',
      ),
      'identifier' => 'menu-frontpage-editor-menu_create-events:node/add/event',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: menu-frontpage-editor-menu_global-ny-senate-settings:admin/settings/nysenate
  $menu_links['menu-frontpage-editor-menu_global-ny-senate-settings:admin/settings/nysenate'] = array(
    'menu_name' => 'menu-frontpage-editor-menu',
    'link_path' => 'admin/settings/nysenate',
    'router_path' => 'admin/settings/nysenate',
    'link_title' => 'Global NY Senate Settings',
    'options' => array(
      'attributes' => array(
        'title' => 'Set Senate session state, and default homepage image',
      ),
      'identifier' => 'menu-frontpage-editor-menu_global-ny-senate-settings:admin/settings/nysenate',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: menu-frontpage-editor-menu_manage-featured-stories-homepage:admin/structure/nodequeue/3/view/3
  $menu_links['menu-frontpage-editor-menu_manage-featured-stories-homepage:admin/structure/nodequeue/3/view/3'] = array(
    'menu_name' => 'menu-frontpage-editor-menu',
    'link_path' => 'admin/structure/nodequeue/3/view/3',
    'router_path' => 'admin/structure/nodequeue/%/view/%',
    'link_title' => 'Manage Featured Stories Homepage',
    'options' => array(
      'attributes' => array(
        'title' => 'Add/remove content from Featured Story block on homepage',
      ),
      'identifier' => 'menu-frontpage-editor-menu_manage-featured-stories-homepage:admin/structure/nodequeue/3/view/3',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: menu-frontpage-editor-menu_manage-homepage-hero:admin/structure/nodequeue/1/view/1
  $menu_links['menu-frontpage-editor-menu_manage-homepage-hero:admin/structure/nodequeue/1/view/1'] = array(
    'menu_name' => 'menu-frontpage-editor-menu',
    'link_path' => 'admin/structure/nodequeue/1/view/1',
    'router_path' => 'admin/structure/nodequeue/%/view/%',
    'link_title' => 'Manage Homepage Hero',
    'options' => array(
      'attributes' => array(
        'title' => 'Add/remove content from the homepage hero.',
      ),
      'identifier' => 'menu-frontpage-editor-menu_manage-homepage-hero:admin/structure/nodequeue/1/view/1',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: menu-frontpage-editor-menu_manage-sitewide-promotional-banners:admin/structure/nodequeue/2/view/2
  $menu_links['menu-frontpage-editor-menu_manage-sitewide-promotional-banners:admin/structure/nodequeue/2/view/2'] = array(
    'menu_name' => 'menu-frontpage-editor-menu',
    'link_path' => 'admin/structure/nodequeue/2/view/2',
    'router_path' => 'admin/structure/nodequeue/%/view/%',
    'link_title' => 'Manage Sitewide Promotional Banners',
    'options' => array(
      'attributes' => array(
        'title' => 'Add/remove promotional content from the Sitewide Promo areas',
      ),
      'identifier' => 'menu-frontpage-editor-menu_manage-sitewide-promotional-banners:admin/structure/nodequeue/2/view/2',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
  );
  // Exported menu link: menu-microsite-content-editor_admin-bills:admin/senator/bills
  $menu_links['menu-microsite-content-editor_admin-bills:admin/senator/bills'] = array(
    'menu_name' => 'menu-microsite-content-editor',
    'link_path' => 'admin/senator/bills',
    'router_path' => 'admin/senator/bills',
    'link_title' => 'Admin Bills',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-microsite-content-editor_admin-bills:admin/senator/bills',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
  );
  // Exported menu link: menu-microsite-content-editor_admin-committees:admin/senator/committees
  $menu_links['menu-microsite-content-editor_admin-committees:admin/senator/committees'] = array(
    'menu_name' => 'menu-microsite-content-editor',
    'link_path' => 'admin/senator/committees',
    'router_path' => 'admin/senator/committees',
    'link_title' => 'Admin Committees',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-microsite-content-editor_admin-committees:admin/senator/committees',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: menu-microsite-content-editor_admin-districts:admin/senator/districts
  $menu_links['menu-microsite-content-editor_admin-districts:admin/senator/districts'] = array(
    'menu_name' => 'menu-microsite-content-editor',
    'link_path' => 'admin/senator/districts',
    'router_path' => 'admin/senator/districts',
    'link_title' => 'Admin Districts',
    'options' => array(
      'identifier' => 'menu-microsite-content-editor_admin-districts:admin/senator/districts',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: menu-microsite-content-editor_admin-my-webforms:admin/my-webforms
  $menu_links['menu-microsite-content-editor_admin-my-webforms:admin/my-webforms'] = array(
    'menu_name' => 'menu-microsite-content-editor',
    'link_path' => 'admin/my-webforms',
    'router_path' => 'admin/my-webforms',
    'link_title' => 'Admin My Webforms',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-microsite-content-editor_admin-my-webforms:admin/my-webforms',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
  );
  // Exported menu link: menu-microsite-content-editor_admin-resolutions:admin/senator/resolutions
  $menu_links['menu-microsite-content-editor_admin-resolutions:admin/senator/resolutions'] = array(
    'menu_name' => 'menu-microsite-content-editor',
    'link_path' => 'admin/senator/resolutions',
    'router_path' => 'admin/senator/resolutions',
    'link_title' => 'Admin Resolutions',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-microsite-content-editor_admin-resolutions:admin/senator/resolutions',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
  );
  // Exported menu link: menu-microsite-content-editor_admin-senator-content:admin/media-services/meetings
  $menu_links['menu-microsite-content-editor_admin-senator-content:admin/media-services/meetings'] = array(
    'menu_name' => 'menu-microsite-content-editor',
    'link_path' => 'admin/media-services/meetings',
    'router_path' => 'admin/media-services/meetings',
    'link_title' => 'Admin Senator Content',
    'options' => array(
      'identifier' => 'menu-microsite-content-editor_admin-senator-content:admin/media-services/meetings',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Exported menu link: menu-microsite-content-editor_admin-senator-content:admin/media-services/sessions
  $menu_links['menu-microsite-content-editor_admin-senator-content:admin/media-services/sessions'] = array(
    'menu_name' => 'menu-microsite-content-editor',
    'link_path' => 'admin/media-services/sessions',
    'router_path' => 'admin/media-services/sessions',
    'link_title' => 'Admin Senator Content',
    'options' => array(
      'identifier' => 'menu-microsite-content-editor_admin-senator-content:admin/media-services/sessions',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Exported menu link: menu-microsite-content-editor_admin-senator-content:admin/senator/content
  $menu_links['menu-microsite-content-editor_admin-senator-content:admin/senator/content'] = array(
    'menu_name' => 'menu-microsite-content-editor',
    'link_path' => 'admin/senator/content',
    'router_path' => 'admin/senator/content',
    'link_title' => 'Admin Senator Content',
    'options' => array(
      'identifier' => 'menu-microsite-content-editor_admin-senator-content:admin/senator/content',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: menu-microsite-content-editor_admin-senator-content:admin/student-programs
  $menu_links['menu-microsite-content-editor_admin-senator-content:admin/student-programs'] = array(
    'menu_name' => 'menu-microsite-content-editor',
    'link_path' => 'admin/student-programs',
    'router_path' => 'admin/student-programs',
    'link_title' => 'Admin Senator Content',
    'options' => array(
      'identifier' => 'menu-microsite-content-editor_admin-senator-content:admin/student-programs',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Exported menu link: menu-microsite-content-editor_content-issue-counter:admin/senator/large-taxonomy-manager
  $menu_links['menu-microsite-content-editor_content-issue-counter:admin/senator/large-taxonomy-manager'] = array(
    'menu_name' => 'menu-microsite-content-editor',
    'link_path' => 'admin/senator/large-taxonomy-manager',
    'router_path' => 'admin/senator/large-taxonomy-manager',
    'link_title' => 'Content Issue counter',
    'options' => array(
      'attributes' => array(
        'title' => 'Find and manage content with too many issues assigned',
      ),
      'identifier' => 'menu-microsite-content-editor_content-issue-counter:admin/senator/large-taxonomy-manager',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Exported menu link: menu-microsite-content-editor_create-new-content:node/add
  $menu_links['menu-microsite-content-editor_create-new-content:node/add'] = array(
    'menu_name' => 'menu-microsite-content-editor',
    'link_path' => 'node/add',
    'router_path' => 'node/add',
    'link_title' => 'Create New Content',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-microsite-content-editor_create-new-content:node/add',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: menu-student-program-editor_create-student-program-content:node/add/student-program
  $menu_links['menu-student-program-editor_create-student-program-content:node/add/student-program'] = array(
    'menu_name' => 'menu-student-program-editor',
    'link_path' => 'node/add/student-program',
    'router_path' => 'node/add/student-program',
    'link_title' => 'Create Student Program Content',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-student-program-editor_create-student-program-content:node/add/student-program',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-student-program-editor_manage-student-programs:admin/student-programs
  $menu_links['menu-student-program-editor_manage-student-programs:admin/student-programs'] = array(
    'menu_name' => 'menu-student-program-editor',
    'link_path' => 'admin/student-programs',
    'router_path' => 'admin/student-programs',
    'link_title' => 'Manage Student Programs',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-student-program-editor_manage-student-programs:admin/student-programs',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 1,
    'customized' => 1,
  );
  // Exported menu link: menu-web-administrator-menu_administer-committees:admin/committees
  $menu_links['menu-web-administrator-menu_administer-committees:admin/committees'] = array(
    'menu_name' => 'menu-web-administrator-menu',
    'link_path' => 'admin/committees',
    'router_path' => 'admin/committees',
    'link_title' => 'Administer Committees',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-web-administrator-menu_administer-committees:admin/committees',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
  );
  // Exported menu link: menu-web-administrator-menu_administer-districts:admin/districts
  $menu_links['menu-web-administrator-menu_administer-districts:admin/districts'] = array(
    'menu_name' => 'menu-web-administrator-menu',
    'link_path' => 'admin/districts',
    'router_path' => 'admin/districts',
    'link_title' => 'Administer Districts',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-web-administrator-menu_administer-districts:admin/districts',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
  );
  // Exported menu link: menu-web-administrator-menu_administer-issues:admin/issues
  $menu_links['menu-web-administrator-menu_administer-issues:admin/issues'] = array(
    'menu_name' => 'menu-web-administrator-menu',
    'link_path' => 'admin/issues',
    'router_path' => 'admin/issues',
    'link_title' => 'Administer Issues',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-web-administrator-menu_administer-issues:admin/issues',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
  );
  // Exported menu link: menu-web-administrator-menu_administer-legislation-bills:admin/legislation/bills
  $menu_links['menu-web-administrator-menu_administer-legislation-bills:admin/legislation/bills'] = array(
    'menu_name' => 'menu-web-administrator-menu',
    'link_path' => 'admin/legislation/bills',
    'router_path' => 'admin/legislation/bills',
    'link_title' => 'Administer Legislation Bills',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-web-administrator-menu_administer-legislation-bills:admin/legislation/bills',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: menu-web-administrator-menu_administer-legislation-resolutions:admin/legislation/resolutions
  $menu_links['menu-web-administrator-menu_administer-legislation-resolutions:admin/legislation/resolutions'] = array(
    'menu_name' => 'menu-web-administrator-menu',
    'link_path' => 'admin/legislation/resolutions',
    'router_path' => 'admin/legislation/resolutions',
    'link_title' => 'Administer Legislation Resolutions',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-web-administrator-menu_administer-legislation-resolutions:admin/legislation/resolutions',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: menu-web-administrator-menu_administrator-nodequeues:admin/structure/nodequeue
  $menu_links['menu-web-administrator-menu_administrator-nodequeues:admin/structure/nodequeue'] = array(
    'menu_name' => 'menu-web-administrator-menu',
    'link_path' => 'admin/structure/nodequeue',
    'router_path' => 'admin/structure/nodequeue',
    'link_title' => 'Administrator Nodequeues',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-web-administrator-menu_administrator-nodequeues:admin/structure/nodequeue',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-web-administrator-menu_create-new-content:node/add
  $menu_links['menu-web-administrator-menu_create-new-content:node/add'] = array(
    'menu_name' => 'menu-web-administrator-menu',
    'link_path' => 'node/add',
    'router_path' => 'node/add',
    'link_title' => 'Create New Content',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-web-administrator-menu_create-new-content:node/add',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: menu-web-administrator-menu_manage-featured-stories-homepage:admin/structure/nodequeue/3/view/3
  $menu_links['menu-web-administrator-menu_manage-featured-stories-homepage:admin/structure/nodequeue/3/view/3'] = array(
    'menu_name' => 'menu-web-administrator-menu',
    'link_path' => 'admin/structure/nodequeue/3/view/3',
    'router_path' => 'admin/structure/nodequeue/%/view/%',
    'link_title' => 'Manage Featured Stories Homepage',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-web-administrator-menu_manage-featured-stories-homepage:admin/structure/nodequeue/3/view/3',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -42,
    'customized' => 1,
  );
  // Exported menu link: menu-web-administrator-menu_manage-global-ny-senate-settings:admin/settings/nysenate
  $menu_links['menu-web-administrator-menu_manage-global-ny-senate-settings:admin/settings/nysenate'] = array(
    'menu_name' => 'menu-web-administrator-menu',
    'link_path' => 'admin/settings/nysenate',
    'router_path' => 'admin/settings/nysenate',
    'link_title' => 'Manage Global NY Senate Settings',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-web-administrator-menu_manage-global-ny-senate-settings:admin/settings/nysenate',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -40,
    'customized' => 1,
  );
  // Exported menu link: menu-web-administrator-menu_manage-sitewide-promotional-banners:admin/structure/nodequeue/2/view/2
  $menu_links['menu-web-administrator-menu_manage-sitewide-promotional-banners:admin/structure/nodequeue/2/view/2'] = array(
    'menu_name' => 'menu-web-administrator-menu',
    'link_path' => 'admin/structure/nodequeue/2/view/2',
    'router_path' => 'admin/structure/nodequeue/%/view/%',
    'link_title' => 'Manage Sitewide Promotional Banners',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-web-administrator-menu_manage-sitewide-promotional-banners:admin/structure/nodequeue/2/view/2',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -41,
    'customized' => 1,
  );
  // Exported menu link: navigation_pagination-for-petitions:nys_dashboard_get_petitions
  $menu_links['navigation_pagination-for-petitions:nys_dashboard_get_petitions'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'nys_dashboard_get_petitions',
    'router_path' => 'nys_dashboard_get_petitions',
    'link_title' => 'Pagination for Petitions',
    'options' => array(
      'identifier' => 'navigation_pagination-for-petitions:nys_dashboard_get_petitions',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Exported menu link: navigation_pagination-for-questionnaires:nys_dashboard_get_questionnaires
  $menu_links['navigation_pagination-for-questionnaires:nys_dashboard_get_questionnaires'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'nys_dashboard_get_questionnaires',
    'router_path' => 'nys_dashboard_get_questionnaires',
    'link_title' => 'Pagination for Questionnaires',
    'options' => array(
      'identifier' => 'navigation_pagination-for-questionnaires:nys_dashboard_get_questionnaires',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Exported menu link: navigation_photo:node/add/photo
  $menu_links['navigation_photo:node/add/photo'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/photo',
    'router_path' => 'node/add/photo',
    'link_title' => 'Photo',
    'options' => array(
      'identifier' => 'navigation_photo:node/add/photo',
    ),
    'module' => 'system',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'navigation_add-content:node/add',
  );
  // Exported menu link: navigation_user-list:profile
  $menu_links['navigation_user-list:profile'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'profile',
    'router_path' => 'profile',
    'link_title' => 'User list',
    'options' => array(
      'identifier' => 'navigation_user-list:profile',
    ),
    'module' => 'system',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Admin Bills');
  t('Admin Committees');
  t('Admin Districts');
  t('Admin My Webforms');
  t('Admin Resolutions');
  t('Admin Senator Content');
  t('Administer Committees');
  t('Administer Districts');
  t('Administer Issues');
  t('Administer Legislation Bills');
  t('Administer Legislation Resolutions');
  t('Administrator Nodequeues');
  t('Content Issue counter');
  t('Create Events');
  t('Create New Content');
  t('Create Student Program Content');
  t('Global NY Senate Settings');
  t('Manage Featured Stories Homepage');
  t('Manage Global NY Senate Settings');
  t('Manage Homepage Hero');
  t('Manage Sitewide Promotional Banners');
  t('Manage Student Programs');
  t('Pagination for Petitions');
  t('Pagination for Questionnaires');
  t('Photo');
  t('User list');


  return $menu_links;
}
