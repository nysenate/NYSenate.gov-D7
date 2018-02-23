Feature: As a visitor I should be able to load the home page
  Scenario: Home page loads
    Given I am on the homepage
    Then I should see "The New York State Senate"

  Scenario: Get involved and login options appear
    Given I am not logged in
    When I am on the homepage
    Then I should see the link "get involved"
    Then I should see the link "login"

  Scenario: View: Homepage hero is present
    Given I am not logged in
    When I am on the homepage
    Then I should see an ".view-homepage-hero.view-display-id-homepage_hero" element

  Scenario: View: Homepage hero contains expected content
    Given I am not logged in
    When I am on the homepage
    Then I should see an ".view-homepage-hero.view-display-id-homepage_hero .view-content" element
    Then I should see 1 ".view-homepage-hero.view-display-id-homepage_hero .view-content img" elements
    Then I should see an ".view-homepage-hero.view-display-id-homepage_hero .view-content .c-hero--date" element
    Then I should see an ".view-homepage-hero.view-display-id-homepage_hero .view-content .c-hero--committee" element
    Then I should see an ".view-homepage-hero.view-display-id-homepage_hero .view-content .c-hero--title" element

  Scenario: View: Homepage news:Homepage Featured Story is present
    Given I am not logged in
    When I am on the homepage
    Then I should see an ".view-homepage-news.view-display-id-hp_featured_stories" element

  Scenario: View: Homepage news:Homepage Featured Story contains expected content
    Given I am not logged in
    When I am on the homepage
    Then I should see an ".view-homepage-news.view-display-id-hp_featured_stories .view-header" element
    Then I should see "Featured Story"
    Then I should see an ".view-homepage-news.view-display-id-hp_featured_stories .view-content" element
    Then I should see 2 ".view-homepage-news.view-display-id-hp_featured_stories .view-content article" elements

  Scenario: View: Homepage news:Homepage news and updates is present
    Given I am not logged in
    When I am on the homepage
    Then I should see an ".view-homepage-news.view-display-id-hp_news_updates" element

  Scenario: View: Homepage news:Homepage news and updates contains expected content
    Given I am not logged in
    When I go to homepage
    Then I should see "Recent Updates"
    Then I should see the link "Go to News"
    Then I should see an ".view-homepage-news.view-display-id-hp_news_updates .view-content" element

  Scenario: View: Legislative Events: Upcoming Legislative Events block is present
    Given I am not logged in
    When I go to the homepage
    Then Home page Legislative Event View is correctly added or not

  Scenario: View: Promotional Banners: Sitewide footer Promotion Blocks is present
    Given I am not logged in
    When I go to the homepage
    Then I should see an ".view-promo-banner-senators-committees.view-id-promo_banner_senators_committees" element

  Scenario: View: Promotional Banners: Sitewide footer Promotion Blocks contains expected content
    Given I am not logged in
    When I go to the homepage
    Then I should see the link "The New NYSenate.gov"
    And I should see the link "Read More"
