Feature: As a visitor I can locate relevant legislation content
  Scenario: Advanced Legislation Search form loads and contains all elements
    Given I am not logged in
    And I am on "/search/legislation"
    Then the response status code should be 200
    And I should see a "select[name=type]" element
    And the "select[name=type] option[selected=selected]" element should contain "Bills"
    And I should see a "input[name=bill_printno]" element
    And I should see a "select[name=bill_session_year]" element
    And I should see a "input[name=bill_text]" element
    And I should see a "select[name=bill_sponsor]" element
    And I should see a "select[name=bill_status]" element
    And I should see a "select[name=bill_committee]" element
    And I should see a "select[name=bill_issue]" element
    And I should see the button "Search"

  Scenario: Bill search yields accurate result
    Given I am not logged in
    And I am on "/search/legislation"
    When I select "Bills" from "type"
    And I fill in "Print No" with "A40"
    And I select "2015-2016" from "bill_session_year"
    And I press the "adv-search-submit" button
    Then I should see the link "Authorizes the reimbursement of non-public schools and teachers"

