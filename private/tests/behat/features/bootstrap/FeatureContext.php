<?php

use Drupal\DrupalExtension\Context\RawDrupalContext;
use Behat\Behat\Context\SnippetAcceptingContext;

/**
 * Defines application features from the specific context.
 */
class FeatureContext extends RawDrupalContext implements SnippetAcceptingContext {

  use MinkFieldRandomizer\Context\FilterContext;

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

}
