Feature: As a visitor I should be able to load the user page
  Scenario: User page loads
    Given I am on "/user"
    Then I should see "User account"
    Then I should see the link "Create Account"
    Then I should see the button "Login to account"
    Then I should see the button "Facebook Connect"