# NYS Behat Testing


## Dependencies and setup

* Behat tests are located in `private/tests/behat`
* Requirements (installed via setup instructions below)
  * [Behat](http://behat.org/en/latest/)
  * [Drupal Extension](https://www.drupal.org/project/drupalextension)
  * [MinkFieldRandomizer](https://github.com/JordiGiros/MinkFieldRandomizer)
  * [PhantomJS](https://www.npmjs.com/package/phantomjs)
  * [Forever](https://www.npmjs.com/package/forever)
  * [Composer](https://getcomposer.org/) (for installation)
  * [npm](https://www.npmjs.com/) (for installation)
* The default base URL for Behat tests is http://example.local
  * Edit the behat.local.yml file with the local development environment base URL
* Setup requirements to run tests locally
  * `cd private/tests/behat`
  * `composer install`
  * `npm install`
* To run the tests, execute the script:
  * cd private/tests/behat
  * `./behat-run.sh`
  * Note: This script must run in the environment hosting the local development site

## Current tests

* Tests are found in the `features` folder

## Step Definitions

* You can view all the defined step definitions to aide in writing new tests.
  * CD to `/private/tests/behat/`
  * Run `bin/behat -dl`