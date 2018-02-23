@front @smoke @ci @javascript
Feature: As an anonymous user I should be able to support and oppose bills

  Scenario: Bills page loads successfully
    Given I am not logged in
    When I go to "/legislation/bills/2009/a8723/amendment/original"
    Then the response should contain "NY State Assembly Bill A8723"
    Then I should see "Lopez P"
    Then I should see "Authorizes the county of Greene to impose an additional mortgage recording tax of 50 cents per $100 of debt; provides for expiration and repeal of such provisions by December 1, 2012."

  Scenario: Anonymous user can support or oppose a bill
    Given I am not logged in
    When I go to "/legislation/bills/2009/a8723/amendment/original"
    Then I should see the link "Aye"
    Then I should see the link "Nay"

  Scenario: Anonymous user can click to support a bill
    Given I am not logged in
    When I go to "/legislation/bills/2009/a8723/amendment/original"
    And I click "Aye"
    And I fill in "First Name" with "Marianne"
    And I fill in "Last Name" with "Markham"
    And Fill "Email Address" with a random mail
    And I click the ".autocomplete-manual-switch" element
    And I fill in "Street Address" with "575 Broadway 5th Floor"
    And I fill in "City" with "New York"
    And I fill in "State" with "NY"
    And I fill in "Postal Code" with "10012"
    And I uncheck the box "register"
    And I press "Support this bill"
    And I wait for AJAX to finish
    Then I should not see "Street Address field is required"
    Then the response should contain "Thank you for your participation."

  Scenario: Anonymous user can click to oppose a bill
    Given I am not logged in
    When I go to "/legislation/bills/2009/a8723/amendment/original"
    And I click "Nay"
    And I fill in "First Name" with "Marianne"
    And I fill in "Last Name" with "Markham"
    And Fill "Email Address" with a random mail
    And I click the ".autocomplete-manual-switch" element
    And I fill in "Street Address" with "575 Broadway 5th Floor"
    And I fill in "City" with "New York"
    And I fill in "State" with "NY"
    And I fill in "Postal Code" with "10012"
    And I uncheck the box "register"
    And I press "Oppose this bill"
    And I wait for AJAX to finish
    Then I should not see "Street Address field is required"
    Then the response should contain "Thank you for your participation."

  Scenario: Anonymous user can view bill with no amendments
    Given I am not logged in
    When I go to "/legislation/bills/2017/s897"
    Then I should see "S897 - BILL TEXT"

  Scenario: Anonymous user can view bill with multiple amendments
    Given I am not logged in
    When I go to "/legislation/bills/2017/s3983"
    And I should see a ".c-detail--section-title" element
    And I should see a "div.c-bill--amendment-details.c-bill-section h3.c-detail--subhead.c-detail--section-title" element
    Then the "div.c-bill--amendment-details.c-bill-section h3.c-detail--subhead.c-detail--section-title" element should contain "BILL AMENDMENTS"

  Scenario: Anonymous user can view a substituted senate bill
    Given I am not logged in
    When I go to "/legislation/bills/2017/s1069"
    Then the response should contain "substituted by a380"
    Then I should see "CURRENT BILL STATUS VIA A380"

  Scenario: Anonymous user can view a substituted assembly bill
    Given I am not logged in
    When I go to "/legislation/bills/2017/a7067"
    Then the response should contain "substituted by s5491"
    Then I should see "CURRENT BILL STATUS VIA S5491"

  @register
  Scenario: Anonymous user can vote on a Bill and register for an account
    Given I am not logged in
    When I go to "/legislation/bills/2009/a8723/amendment/original"
    And I click "Nay"
    And I fill in "First Name" with "Behat"
    And I fill in "Last Name" with "Test-user"
    And Fill "Email Address" with a random mail
    And I click the ".autocomplete-manual-switch" element
    And I fill in "Street Address" with "575 Broadway 5th Floor"
    And I fill in "City" with "New York"
    And I fill in "State" with "NY"
    And I fill in "Postal Code" with "10012"
    And I press "Oppose this bill"
    And I wait for AJAX to finish
    Then the response should contain "Success! Your NY State Senate Account has been created. You can activate your account by visiting the URL that was just sent to the email address you provided."
    And I clean up test user account created

  @register
  Scenario: Anonymous user can vote on a Bill and send message to senator
    Given I am not logged in
    When I go to "/legislation/bills/2009/a8723/amendment/original"
    And I click "Nay"
    And I fill in "First Name" with "Behat"
    And I fill in "Last Name" with "Test-user"
    And Fill "Email Address" with a random mail
    And I click the ".autocomplete-manual-switch" element
    And I fill in "Street Address" with "426 2nd St #3"
    And I fill in "City" with "Brooklyn"
    And I fill in "State" with "NY"
    And I fill in "Postal Code" with "11215"
    And I fill in "message" with "Behat message for senator"
    And I press "Oppose this bill"
    And I wait for AJAX to finish
    And the response should contain "Success! Your NY State Senate Account has been created. You can activate your account by visiting the URL that was just sent to the email address you provided."
    Then I log in as "146681"
    And I go to "/user"
    And I click "Manage Kevin S. Parker's inbox"
    Then I should see "Behat Test-user opposed A8723"
    And I should see "Behat message for senator"
    And I clean up test user account created

  Scenario: Anonymous user with existing email is prompted to log in
    Given I am not logged in
    When I go to "/legislation/bills/2009/a8723/amendment/original"
    And I click "Nay"
    And I fill in "First Name" with "Behat"
    And I fill in "Last Name" with "Test-user"
    And I fill in "Email Address" with "nys.senate.dev+emailtest@gmail.com"
    And I click the ".autocomplete-manual-switch" element
    And I fill in "Street Address" with "426 2nd St #3"
    And I fill in "City" with "Brooklyn"
    And I fill in "State" with "NY"
    And I fill in "Postal Code" with "11215"
    And I fill in "message" with "Behat message for senator"
    And I press "Oppose this bill"
    And I wait for AJAX to finish
    Then I should see "Our records show you already have an account."
    Then I should see "Please log in"