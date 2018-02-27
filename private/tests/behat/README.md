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
  * `cd private/tests/behat`
  * `./behat-run.sh`
  * Note: This script must run in the environment hosting the local development site
* To run specific tests, run the behat binary directly and pass in scenario name or tags
  * `bin/behat --tags @register`
  * `bin/behat --name="Anonymous user"`

## Current tests

* Tests are found in the `features` folder

## Step Definitions

* You can view all the defined step definitions to aide in writing new tests.
  * CD to `/private/tests/behat/`
  * Run `bin/behat -dl`

## Failed Steps

* Failed steps will generate screenshots in `/private/tests/behat/screenshots`


## Current defined step definitions
```
default | Given I click the :arg1 element
default | Given I log in as :name
default | Given I log in as user with :name email
default | When I clean up test user account created
default | Then Fill :field with a random loremipsum
default | Then Fill :field with an existent loremipsum
default | Then Fill :field with a random mail
default | Then Fill :field with an existent mail
default | Then Fill :field with a random phone
default | Then Fill :field with an existent phone
default | Then Fill :field with a random name
default | Then Fill :field with an existent name
default | Then Fill :field with a random surname
default | Then Fill :field with an existent surname
default | Then Fill :field with a random number
default | Then Fill :field with an existent number
default | Then Fill :field with a random text
default | Then Fill :field with an existent text
default | Then /^the "(?P<field>(?:[^"]|\\")*)" field should contains "(?P<value>(?:[^"]|\\")*)" value$/
default | Then Fill :field with :value
default | Then I select :arg1 option from :arg2
default | Given I am an anonymous user
default | Given I am not logged in
default | Given I am logged in as a user with the :role role(s)
default | Given I am logged in as a/an :role
default | Given I am logged in as a user with the :role role(s) and I have the following fields:
default | Given I am logged in as :name
default | Given I am logged in as a user with the :permissions permission(s)
default | Then I should see (the text ):text in the :rowText row
default | Then I should not see (the text ):text in the :rowText row
default | Given I click :link in the :rowText row
default | Then I (should )see the :link in the :rowText row
default | Given the cache has been cleared
default | Given I run cron
default | Given I am viewing a/an :type (content )with the title :title
default | Given a/an :type (content )with the title :title
default | Given I am viewing my :type (content )with the title :title
default | Given :type content:
default | Given I am viewing a/an :type( content):
default | Then I should be able to edit a/an :type( content)
default | Given I am viewing a/an :vocabulary term with the name :name
default | Given a/an :vocabulary term with the name :name
default | Given users:
default | Given :vocabulary terms:
default | Given the/these (following )languages are available:
default | Then (I )break
default | Given I am at :path
default | When I visit :path
default | When I click :link
default | Given for :field I enter :value
default | Given I enter :value for :field
default | Given I wait for AJAX to finish
default | When /^(?:|I )press "(?P<button>(?:[^"]|\\")*)"$/
default | When I press the :button button
default | Given I press the :char key in the :field field
default | Then I should see the link :link
default | Then I should not see the link :link
default | Then I should not visibly see the link :link
default | Then I (should )see the heading :heading
default | Then I (should )not see the heading :heading
default | Then I (should ) see the button :button
default | Then I (should ) see the :button button
default | Then I should not see the button :button
default | Then I should not see the :button button
default | When I follow/click :link in the :region( region)
default | Given I press :button in the :region( region)
default | Given I fill in :value for :field in the :region( region)
default | Given I fill in :field with :value in the :region( region)
default | Then I should see the heading :heading in the :region( region)
default | Then I should see the :heading heading in the :region( region)
default | Then I should see the link :link in the :region( region)
default | Then I should not see the link :link in the :region( region)
default | Then I should see( the text) :text in the :region( region)
default | Then I should not see( the text) :text in the :region( region)
default | Then I (should )see the text :text
default | Then I should not see the text :text
default | Then I should get a :code HTTP response
default | Then I should not get a :code HTTP response
default | Given I check the box :checkbox
default | Given I uncheck the box :checkbox
default | When I select the radio button :label with the id :id
default | When I select the radio button :label
default | Given /^(?:|I )am on (?:|the )homepage$/
default | When /^(?:|I )go to (?:|the )homepage$/
default | Given /^(?:|I )am on "(?P<page>[^"]+)"$/
default | When /^(?:|I )go to "(?P<page>[^"]+)"$/
default | When /^(?:|I )reload the page$/
default | When /^(?:|I )move backward one page$/
default | When /^(?:|I )move forward one page$/
default | When /^(?:|I )follow "(?P<link>(?:[^"]|\\")*)"$/
default | When /^(?:|I )fill in "(?P<field>(?:[^"]|\\")*)" with "(?P<value>(?:[^"]|\\")*)"$/
default | When /^(?:|I )fill in "(?P<field>(?:[^"]|\\")*)" with:$/
default | When /^(?:|I )fill in "(?P<value>(?:[^"]|\\")*)" for "(?P<field>(?:[^"]|\\")*)"$/
default | When /^(?:|I )fill in the following:$/
default | When /^(?:|I )select "(?P<option>(?:[^"]|\\")*)" from "(?P<select>(?:[^"]|\\")*)"$/
default | When /^(?:|I )additionally select "(?P<option>(?:[^"]|\\")*)" from "(?P<select>(?:[^"]|\\")*)"$/
default | When /^(?:|I )check "(?P<option>(?:[^"]|\\")*)"$/
default | When /^(?:|I )uncheck "(?P<option>(?:[^"]|\\")*)"$/
default | When /^(?:|I )attach the file "(?P<path>[^"]*)" to "(?P<field>(?:[^"]|\\")*)"$/
default | Then /^(?:|I )should be on "(?P<page>[^"]+)"$/
default | Then /^(?:|I )should be on (?:|the )homepage$/
default | Then /^the (?i)url(?-i) should match (?P<pattern>"(?:[^"]|\\")*")$/
default | Then /^the response status code should be (?P<code>\d+)$/
default | Then /^the response status code should not be (?P<code>\d+)$/
default | Then /^(?:|I )should see "(?P<text>(?:[^"]|\\")*)"$/
default | Then /^(?:|I )should not see "(?P<text>(?:[^"]|\\")*)"$/
default | Then /^(?:|I )should see text matching (?P<pattern>"(?:[^"]|\\")*")$/
default | Then /^(?:|I )should not see text matching (?P<pattern>"(?:[^"]|\\")*")$/
default | Then /^the response should contain "(?P<text>(?:[^"]|\\")*)"$/
default | Then /^the response should not contain "(?P<text>(?:[^"]|\\")*)"$/
default | Then /^(?:|I )should see "(?P<text>(?:[^"]|\\")*)" in the "(?P<element>[^"]*)" element$/
default | Then /^(?:|I )should not see "(?P<text>(?:[^"]|\\")*)" in the "(?P<element>[^"]*)" element$/
default | Then /^the "(?P<element>[^"]*)" element should contain "(?P<value>(?:[^"]|\\")*)"$/
default | Then /^the "(?P<element>[^"]*)" element should not contain "(?P<value>(?:[^"]|\\")*)"$/
default | Then /^(?:|I )should see an? "(?P<element>[^"]*)" element$/
default | Then /^(?:|I )should not see an? "(?P<element>[^"]*)" element$/
default | Then /^the "(?P<field>(?:[^"]|\\")*)" field should contain "(?P<value>(?:[^"]|\\")*)"$/
default | Then /^the "(?P<field>(?:[^"]|\\")*)" field should not contain "(?P<value>(?:[^"]|\\")*)"$/
default | Then /^(?:|I )should see (?P<num>\d+) "(?P<element>[^"]*)" elements?$/
default | Then /^the "(?P<checkbox>(?:[^"]|\\")*)" checkbox should be checked$/
default | Then /^the "(?P<checkbox>(?:[^"]|\\")*)" checkbox is checked$/
default | Then /^the checkbox "(?P<checkbox>(?:[^"]|\\")*)" (?:is|should be) checked$/
default | Then /^the "(?P<checkbox>(?:[^"]|\\")*)" checkbox should (?:be unchecked|not be checked)$/
default | Then /^the "(?P<checkbox>(?:[^"]|\\")*)" checkbox is (?:unchecked|not checked)$/
default | Then /^the checkbox "(?P<checkbox>(?:[^"]|\\")*)" should (?:be unchecked|not be checked)$/
default | Then /^the checkbox "(?P<checkbox>(?:[^"]|\\")*)" is (?:unchecked|not checked)$/
default | Then /^print current URL$/
default | Then /^print last response$/
default | Then /^show last response$/
default | Then I should see the error message( containing) :message
default | Then I should see the following error message(s):
default | Given I should not see the error message( containing) :message
default | Then I should not see the following error messages:
default | Then I should see the success message( containing) :message
default | Then I should see the following success messages:
default | Given I should not see the success message( containing) :message
default | Then I should not see the following success messages:
default | Then I should see the warning message( containing) :message
default | Then I should see the following warning messages:
default | Given I should not see the warning message( containing) :message
default | Then I should not see the following warning messages:
default | Then I should see the message( containing) :message
default | Then I should not see the message( containing) :message
default | Given I run drush :command
default | Given I run drush :command :arguments
default | Then drush output should contain :output
default | Then drush output should match :regex
default | Then drush output should not contain :output
default | Then print last drush output
default | When save screenshot
default | When I save screenshot
```
