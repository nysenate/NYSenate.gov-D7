Sendgrid Integration Reports
============================

With this module enabled you will have reports and insights into your Sendgrid
account. The dashboard displays the general stats created by Sendgrid.

This module creates a custom cache bin for the statistics and reports. The data
could be large depending on the activity of your site; therefore, we store this
in a cache to make the reports pages display without having to perform service
calls on each load.

A custome cache bin was created in order to allow you to use other cacheing
backends for your Drupal website. By default, the data gets stored into the
main database for the website. But you could store the information in other
cacheing backends such as Memcache, MongoDB, or Redis.

This module requires the main Sendgrid Integration module to be loaded which
in turn requires the installation of Composer Manager module.

Requirements
============
1. Sendgrid Integration Module
2. Composer Manager
3. Guzzlehttp (loaded with Composer Manager)
