INTRODUCTION
------------

The Password Policy module allows administrators to define and enforce password
policies for user passwords. A password policy comprises (1) constraints on
password composition, (2) conditions that determine to which users it should
apply, and (3) items that provide other settings (e.g., expiration).

The Password Policy module includes an example policy that is enabled by
default and applies to all users. The module also includes constraints,
conditions, and items that an administrator can use to define their own
policies.


REQUIREMENTS
------------

This module requires the following modules:

 * Chaos tool suite (https://drupal.org/project/ctools)


INSTALLATION
------------

Install as you would normally install a contributed Drupal module. For further
information, visit:
  https://drupal.org/documentation/install/modules-themes/modules-7


CONFIGURATION
-------------

Configure policies at Administration » Configuration » People » Password
policies.

An example policy is provided and enabled by default. To customize the default
policy there are two options:

    1. Edit the example policy using the "Edit" link in the "Operations"
       column menu.

    2. Disable the example policy using the "Disable" link in the "Operations"
       column menu. Then, add a new policy.

You can add a policy using the "Add" link at the top of the page.

You can duplicate a policy using the "Clone" link in the "Operations" column
menu. This can be useful if you would like to have similar, but not identical,
policies that apply to different roles.

You can export/import policies using the "Import" link at the top of
configuration page and the "Export" link in the "Operations" column menu.


LIMITATIONS
-----------

Password policies only apply to passwords set via user forms in the web
interface. Passwords changed by other means (Drush, web services, etc.) will
not be subject to password policy constraints. Please see the following issue
if you would like to contribute to removing this limitation:
  https://www.drupal.org/node/2451159
