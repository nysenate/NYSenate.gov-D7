/**
 * SendGrid Integration
 */

This project is not affiliated with SendGrid, Inc.
Use the issue tracker for bug reports or questions about Drupal integration.
If you want more info about SendGrid email services, 
contact SendGrid (http://sendgrid.com) instead

FUNCTIONALITY:
This module overrides default email sending behaviour, 
sending emails throught SendGrid services instead.

INSTALLATION:
Installing this module is simple

1. Move this folder under modules directory of your installation,
   example sites/all/modules or sites/default/modules
   
2. Navigate to administer >> build >> modules and enable SendGrid Integration

3. Configure your SendGrid Username and API-Key in admin/config/system/sendgrid

#Optional

If sending email fails with certain (pre-defined) response codes will email be
added to Cron Queue for later delivery.
You may want to configure Cron running period and when it is possible also
add your drupal site to crontab, read more about cront at 
http://drupal.org/cron.
