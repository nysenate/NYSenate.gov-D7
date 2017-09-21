@front @smoke @ci @javascript
Feature: As an anonymous user I should be able to support and oppose bills
Scenario: Bills page loads successfully
  Given I am not logged in
  When I go to "legislation/bills/2009/a8723/amendment/original"
  Then I should see "Assembly Bill A8723"
  Then I should see "Lopez P"
  Then I should see "Authorizes the county of Greene to impose an additional mortgage recording tax of 50 cents per $100 of debt; provides for expiration and repeal of such provisions by December 1, 2012."

Scenario: Anonymous user can support or oppose a bill
  Given I am not logged in
  When I go to "legislation/bills/2009/a8723/amendment/original"
  Then I should see the link "Aye"
  Then I should see the link "Nay"

Scenario: Anonymous user can click to support a bill
  Given I am not logged in
  When I go to "legislation/bills/2009/a8723/amendment/original"
  And I click "Aye"
  And I fill in "First Name" with "Marianne"
  And I fill in "Last Name" with "Markham"
  And I fill in "Email Address" with "mmarkham@example.com"
  And I click the ".autocomplete-manual-switch" element
  And I fill in "First Name" with "Marianne"
  And I fill in "Last Name" with "Markham"
  And I fill in "Email Address" with "mmarkham@example.com"
  And I fill in "Street Address" with "575 Broadway 5th Floor"
  And I fill in "City" with "New York"
  And I fill in "State" with "NY"
  And I fill in "Postal Code" with "10012"
  And I uncheck the box "register"
  And I press "Support this bill"
  Then I should not see "Street Address field is required"
  Then I should see "Thank you for your participation."
