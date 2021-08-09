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

; Advanced Poll
projects[advpoll][type] = module
projects[advpoll][subdir] = contrib
projects[advpoll][version] = 3.0
projects[advpoll][patch][] = ../patches/contrib/advpoll-7.x-3.0.patch

; Drupal 8 Cache
projects[d8cache][type] = module
projects[d8cache][subdir] = contrib
projects[d8cache][version] = 1.0-beta1
projects[d8cache][patch][] = https://www.drupal.org/files/issues/2018-05-17/invalid_argument_foreach-2950616-4.patch

; Entity Reference
projects[entityreference][type] = module
projects[entityreference][subdir] = contrib
projects[entityreference][version] = 1.5
projects[entityreference][patch][] = ../patches/contrib/entity_reference__restrict_access_label_fix.patch

; Entity Reference
projects[entityreference][type] = module
projects[entityreference][subdir] = contrib
projects[entityreference][version] = 1.5
projects[entityreference][patch][] = ../patches/contrib/1702172-80.patch

; Features
; Issue - https://www.drupal.org/project/rules/issues/2701957
projects[features][type] = module
projects[features][subdir] = contrib
projects[features][version] = 2.13
projects[features][patch][] = https://www.drupal.org/files/issues/features-rules_dont_revert-2701957-25.patch

; GMap
projects[gmap][location_gmap_find_address][type] = module
projects[gmap][location_gmap_find_address][subdir] = contrib
projects[gmap][location_gmap_find_address][version] = 2.11
projects[gmap][location_gmap_find_address][patch][] = ../patches/contrib/location-gmap-fix-find-address-button.patch

; Location
projects[location][location_deprecation_warning_each][type] = module
projects[location][location_deprecation_warning_each][subdir] = contrib
projects[location][location_deprecation_warning_each][version] = 7.x-3.7
projects[location][location_deprecation_warning_each][patch][] = ../patches/contrib/location-deprecation-warning-on-php72-2957208-3.patch

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

; Sendgrid Integration
projects[sendgrid_integration][type] = module
projects[sendgrid_integration][subdir] = contrib
projects[sendgrid_integration][version] = 7.x-1.1
projects[sendgrid_integration][patch][] = ../patches/contrib/sendgrid_integration-7.x-1.1.patch

; Sendgrid Integration
projects[sendgrid_integration][type] = module
projects[sendgrid_integration][subdir] = contrib
projects[sendgrid_integration][version] = 7.x-1.1
projects[sendgrid_integration][patch][] = https://www.drupal.org/files/issues/sendgrid_integration-dont_check_send-2786379-2.patch

; Sub-pathauto (Sub-path URL Aliases)
projects[subpathauto][type] = module
projects[subpathauto][subdir] = contrib
projects[subpathauto][version] = 1.3
projects[subpathauto][patch][] = https://www.drupal.org/files/subpathauto-theme_admin_pages-1814516-15.patch

; Views Load More
projects[views_load_more][type] = module
projects[views_load_more][subdir] = contrib
projects[views_load_more][version] = 1.5
projects[views_load_more][patch][] = https://www.drupal.org/files/issues/views_load_more-content_query_miss-2415591-1.patch

; ZURB Foundation
projects[zurb_foundation][type] = theme
projects[zurb_foundation][version] = 5.0-alpha8
projects[zurb_foundation][patch][] = ../patches/contrib/zurb_foundation_button_style.patch

