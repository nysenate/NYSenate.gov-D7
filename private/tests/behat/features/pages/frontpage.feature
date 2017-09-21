@front @smoke @ci
Feature: As a visitor I should be able to load the home page
Scenario: Home page loads
  Given I am on the homepage
  Then I should see "The New York State Senate"

Scenario: Get involved and login options appear
  Given I am not logged in
  When I am on the homepage
  Then I should see the link "get involved"
  Then I should see the link "login"
