Feature: Huge Header Warning
In order to understand the caching behavior of my site
As an administrator
I need a notification when my header is truncated.

  @api
  Scenario: Warning message.
    Given I run drush "dis -y pantheon_advanced_page_cache_test"
    Given I run drush "en -y pantheon_advanced_page_cache"
    And I am logged in as a user with the "administrator" role
    And there are 10 article nodes with a huge number of taxonomy terms each
    When I visit "/frontpage"
    And I visit "admin/reports/dblog"
    And I click "More cache tags were present than could be passed in..." in the "pantheon_advanced_page_cache" row
    Then I should see "More cache tags were present than could be passed in the Surrogate-Key HTTP Header due to length constraints"

    @api
  Scenario: No warning message after enabling test module.
    Given I run drush "en -y pantheon_advanced_page_cache_test"
    And I run drush "cc" "all"
    And I am logged in as a user with the "administrator" role
    And I visit "admin/reports/dblog"
    And I press "Clear log messages"
    And there are 10 article nodes with a huge number of taxonomy terms each
    When I visit "/frontpage"
    And I visit "admin/reports/dblog"
    Then I should not see "pantheon_advanced_page_cache"
