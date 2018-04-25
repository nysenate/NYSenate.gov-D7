Feature: As a logged in user, I want to verify user permissions.
  Scenario: Legislative Correspondent is able to manage senator inbox
    Given I log in as user with "useremail@example.com" email
    When I go to "/user"
    And I click "Manage John Smith's inbox"
    Then the response should contain "John Smiths’s Dashboard"
    And I should see "Inbox"