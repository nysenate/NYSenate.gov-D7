<?php

use Behat\Behat\Context\Context;
use Behat\Behat\Context\SnippetAcceptingContext;
use Behat\Behat\Hook\Scope\BeforeScenarioScope;
use Drupal\DrupalExtension\Context\MinkContext;


use Drupal\DrupalExtension\Context\RawDrupalContext;

/**
 * Define application features from the specific context.
 */
class FeatureContext extends RawDrupalContext implements Context, SnippetAcceptingContext {
  /**
   * Initializes context.
   * Every scenario gets its own context object.
   *
   * @param array $parameters
   *   Context parameters (set them in behat.yml)
   */
  public function __construct(array $parameters = []) {
    // Initialize your context here
  }

  /** @var \Drupal\DrupalExtension\Context\MinkContext */
  private $minkContext;
  /** @BeforeScenario */
  public function gatherContexts(BeforeScenarioScope $scope)
  {
      $environment = $scope->getEnvironment();
      $this->minkContext = $environment->getContext('Drupal\DrupalExtension\Context\MinkContext');
  }


    /**
     * @Given there are :numnber_of_nodes article nodes with a huge number of taxonomy terms each
     */
    public function thereAreArticleNodesWithAHugeNumberOfTaxonomyTermsEach($number_of_nodes)
    {
       $i = 0;
       while ($i < $number_of_nodes) {
           $this->WhenIGenerateAnArticleWithLotsOfTerms();
           $i++;
       }
    }

    /**
     * @When a generate a :type node
     */
    public function WhenIGenerateAnArticleWithLotsOfTerms()
    {
        $random_node_title = "Random Node Title: " . rand();
        $this->minkContext->visit('node/add/article');
        $this->minkContext->fillField('Title', $random_node_title);
        $this->minkContext->fillField('Tags', $this->generateRandomTaxonomyString());
        $this->minkContext->pressButton('Save');
        $this->minkContext->assertTextVisible($random_node_title);
    }

    /**
     * Generates a long string of tags used on node add form.
     */
    private function generateRandomTaxonomyString() {
        $all_letters = explode(' ', 'a b c d e f g h i j k l m n o p q r s t u v w x y z');
        $i = 0;
        $random_three_letter_combos = array();
        while($i < 250) {

            $random_three_letter_combos[] = $all_letters[rand(0, 25)] . $all_letters[rand(0, 25)] . $all_letters[rand(0, 25)];
            $i++;
        }
        return implode(",", $random_three_letter_combos);
    }
}
