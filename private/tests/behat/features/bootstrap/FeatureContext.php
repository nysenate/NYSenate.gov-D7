<?php

use Drupal\DrupalExtension\Context\RawDrupalContext;
use Behat\Behat\Context\SnippetAcceptingContext;

/**
 * Defines application features from the specific context.
 */
class FeatureContext extends RawDrupalContext implements SnippetAcceptingContext {

  use MinkFieldRandomizer\Context\FilterContext;

  public $random_fields = array();

  /**
   * Initializes context.
   *
   * Every scenario gets its own context instance.
   * You can also pass arbitrary arguments to the
   * context constructor through behat.yml.
   */
  public function __construct() {
  }

  /**
   * Copied from MinkContext.
   *
   * MinkFieldRandomizer assumes we're extending MinkContext and this method
   * will be available, but we're not, we're extending RawMinkContext.
   *
   * @see Behat\MinkExtension\Context\MinkContext::fillField()
   */
  protected function fillField($field, $value) {
    // Save values to public object so it can be available to other functions
    // during this scenario.
    $this->random_fields[$field] = $value;

    $field = $this->fixStepArgument($field);
    $value = $this->fixStepArgument($value);
    $this->getSession()->getPage()->fillField($field, $value);
  }

  /**
   * Copied from MinkContext.
   *
   * MinkFieldRandomizer assumes we're extending MinkContext and this method
   * will be available, but we're not, we're extending RawMinkContext.
   *
   * @see Behat\MinkExtension\Context\MinkContext::fixStepArgument()
   */
  protected function fixStepArgument($argument) {
    return str_replace('\\"', '"', $argument);
  }

  /**
   * Clicks on a css element.
   *
   * @Given I click the :arg1 element
   */
  public function iClickTheElement($selector) {
    $page = $this->getSession()->getPage();
    $element = $page->find('css', $selector);

    if (empty($element)) {
      throw new Exception("No html element found for the selector ('$selector')");
    }

    $element->click();
  }

  /**
   * @BeforeScenario
   */
  public function maximizeWindow() {
    $this->getSession()->getDriver()->maximizeWindow();
  }

  /**
   * @Given I log in as :name
   */
  public function iLogInAs($name) {
    $domain = $this->getMinkParameter('base_url');
    // Pass base url to drush command.
    $uli = $this->getDriver('drush')->drush('uli', array(
      "'" . $name . "'",
      "--browser=0",
      "--uri=$domain",
    ));
    // Trim EOL characters.
    $uli = trim($uli);
    $this->getSession()->visit($uli);
  }

  /**
   * @Given I log in as user with :name email
   */
  public function iLogInAsUserWithEmail($email) {
    $domain = $this->getMinkParameter('base_url');

    // Pass base url to drush command.
    $uli = $this->getDriver('drush')->drush('uli', array(
      "--mail='$email'",
      "--browser=0",
      "--uri=$domain",
    ));

    // Trim EOL characters.
    $uli = trim($uli);
    $this->getSession()->visit($uli);
  }

  /**
   * @When I clean up test user account created
   */
  public function iCleanUpTestUserAccountCreated() {
    // If a random email was used in this scenario, try to delete a user
    // with that address via drush.
    if (!empty($this->random_fields['Email Address'])) {
      $domain = $this->getMinkParameter('base_url');

      $email = $this->random_fields['Email Address'];
      $drush = $this->getDriver('drush')->drush('ucan', array(
        "$email -y",
        "--uri=$domain",
      ));
      $output = trim($drush);

      if (strpos($output, 'has been deleted')) {
        var_export("User with email: $email has been deleted");
      }
    }
  }

  /**
   * @Then Home page Legislative Event View is correctly added or not
   */
  public function homePageLegislativeEventViewCorrectlyAdded() {
    // The View isn't added to the home page if there are no events currently
    // available.
    $view = $this->getSession()->getPage()->find('css', '.view-legislative-events.view-display-id-block');
    if (empty($view)) {
      $this->assertSession()->pageTextContains($this->fixStepArgument("There are no events scheduled at this time."));
    }
    else {
      $this->assertSession()->elementExists('css', '.view-legislative-events.view-display-id-block .view-header a');
      $this->assertSession()->elementExists('css', '.view-legislative-events.view-display-id-block .view-content');
    }
  }

}
