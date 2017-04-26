; Drush Make Patch File.

; Run `drush make --no-core --no-patch-txt <full-file-path>/patches/patches.make`
;   to apply all patches.
; Run `drush make --no-core --no-patch-txt --projects=<projectname> <full-file-patch>/patches/patches.make`
;   to only apply specified module patches.
core = 7.x
api = 2

; Core
; Pantheon Pressflow 7 for DROPs.
; https://github.com/pantheon-systems/drops-7.
; Run patches-core.sh from the webroot to process core patches.

; Contrib

; Apache Solr Search
projects[apachesolr][type] = module
projects[apachesolr][subdir] = contrib
projects[apachesolr][version] = 1.8
projects[apachesolr][patch][] = https://www.drupal.org/files/issues/apachesolr-1688150-64.patch

; CAPTCHA
projects[captcha][type] = module
projects[captcha][subdir] = contrib
projects[captcha][version] = 1.3
projects[captcha][patch][] = https://www.drupal.org/files/issues/captcha-feature_is_overridden_always-2552279-1.patch
projects[captcha][patch][] = https://www.drupal.org/files/issues/captcha-placement-fix-for-multiple-button-forms.patch

; Date
projects[date][type] = module
projects[date][subdir] = contrib
projects[date][version] = 2.8
projects[date][patch][] = https://www.drupal.org/files/issues/date-migrate-undefined-timezone-2451027-1.patch

; Disqus
projects[disqus][type] = module
projects[disqus][subdir] = contrib
projects[disqus][version] = 1.10
projects[disqus][patch][] = https://www.drupal.org/files/issues/1821146_13.patch

; Entity API
projects[entity][type] = module
projects[entity][subdir] = contrib
projects[entity][version] = 1.6
projects[entity][patch][] = https://www.drupal.org/files/issues/entity-stop-assuming-you-may-find-array-1414428-12-D7.patch

; Entity Reference
projects[entityreference][type] = module
projects[entityreference][subdir] = contrib
projects[entityreference][version] = 1.1
projects[entityreference][patch][] = ../patches/contrib/entity_reference__restrict_access_label_fix.patch

; Feeds XPath Parser
projects[feeds_xpathparser][type] = module
projects[feeds_xpathparser][subdir] = contrib
projects[feeds_xpathparser][version] = 1.0-beta4
projects[feeds_xpathparser][patch][] = https://www.drupal.org/files/feeds_xpath_parser_undefined_index_unique-1998194-2.patch

; Field collection feeds
projects[field_collection_feeds][type] = module
projects[field_collection_feeds][subdir] = contrib
projects[field_collection_feeds][version] = 1.0-alpha3
projects[field_collection_feeds][patch][] = https://www.drupal.org/files/issues/FeedsUpdateIssue-1921128-12.patch

; Global Redirect
projects[globalredirect][type] = module
projects[globalredirect][subdir] = contrib
projects[globalredirect][version] = 1.5
projects[globalredirect][patch][] = ../patches/contrib/globalredirect-suppress-bills-nys.patch

; Media: Ustream
; Patch filename has the wrong issue node. See: https://www.drupal.org/node/2776817.
projects[media_ustream][type] = module
projects[media_ustream][subdir] = contrib
projects[media_ustream][version] = 1.0-beta1
projects[media_ustream][patch][] = https://www.drupal.org/files/issues/ustream_api_change-2116043-2.patch

; Nodequeue
projects[nodequeue][type] = module
projects[nodequeue][subdir] = contrib
projects[nodequeue][version] = 2.0-beta1
projects[nodequeue][patch][] = ../patches/contrib/nodequeue_apachesolr_mark_entity.patch

; Privatemsg
projects[privatemsg][type] = module
projects[privatemsg][subdir] = contrib
projects[privatemsg][download][type] = git
projects[privatemsg][download][url] = git://git.drupal.org/project/privatemsg.git
projects[privatemsg][download][branch] = 7.x-2.x
projects[privatemsg][download][revision] = adee03
projects[privatemsg][patch][] = https://www.drupal.org/files/issues/privatemsg-1573000-120.patch

; Session API
projects[session_api][type] = module
projects[session_api][subdir] = contrib
projects[session_api][download][type] = git
projects[session_api][download][url] = git://git.drupal.org/project/session_api.git
projects[session_api][download][branch] = 7.x-1.x
projects[session_api][download][revision] = 434aad
projects[session_api][patch][] = https://www.drupal.org/files/issues/session_api-reset_sid-2705055-2.patch

; Sub-pathauto (Sub-path URL Aliases)
projects[subpathauto][type] = module
projects[subpathauto][subdir] = contrib
projects[subpathauto][version] = 1.3
projects[subpathauto][patch][] = https://www.drupal.org/files/subpathauto-theme_admin_pages-1814516-15.patch

; ZURB Foundation
projects[zurb_foundation][type] = theme
projects[zurb_foundation][version] = 5.0-alpha8
projects[zurb_foundation][patch][] = ../patches/contrib/zurb_foundation_button_style.patch

