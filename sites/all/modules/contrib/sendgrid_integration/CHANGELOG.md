7.x-1.0-beta3
================================================================================
Upgrade to Beta3 prior to 4 May 2016 incorrectly deleted the API Key. The API
key ID was the variable that should have been erased. This bug was fixed in the
upgrade scripts but is documented here.

7.x-1.0-alpha3
================================================================================

Background
--------------------------------------------------------------------------------
Guzzle was introduced into the Sendgrid library in May 2015; however, to 
maintain compatibility with PHP 5.3 Sendgrid choose to use a sunsetted version 
of Guzzle (3.x). The current active version of Guzzle is 6.x which adheres to 
PSR specifications but also requires PHP 5.4. Drupal 8 ships with Guzzle 6.x in
core giving a great upgrade path for any module using web services. I forked 
the Sendgrid PHP library and upgraded it to Guzzle 6.x and Alpha 3 uses this 
forked version that is published in Packagist. The reason I did this was after 
a discusion with the Sendgrid developers, this was the best path forward since 
they had no interest at the moment of maintaining a second version of their 
library. I will continue to maintain the fork till Sendgrid takes on the code to 
upgrade to Guzzle 6.x sometime in the unknown future.

Major changes
--------------------------------------------------------------------------------
* Composer Manager Required (https://www.drupal.org/project/composer_manager)
* Requires PHP 5.4 or greater
* New sub-module for Reports
* MailSystem Module (https://www.drupal.org/project/mailsystem)

Dependencies (loaded via composer)
--------------------------------------------------------------------------------
* Forked Sengrid Library (fastglass/sendgrid)
* Guzzle 6.0.0 or greater

How to upgrade
--------------------------------------------------------------------------------
Required Step:
Install Composer Manager module, enable, and fully configure the module (see
documentation from the module).

Option 1:
Use Drush to install upgrade and resolve dependencies. Tested with Drush 8.x.
Run an update, "drush updb". Go to the admin pages for Sendgrid and update the
settings (admin/config/services/sendgrid).

Option 2:
1. Install dependencies for module before attempting to upgrade module.
2. Download module and replace existing Sendgrid Integration Module.
3. Run update.
4. Configure new settings in admin page for the module. 
   (admin/config/services/sendgrid)