(function ($, Drupal) {

  Drupal.behaviors.STARTER = {
    attach: function(context, settings) {
      // Get your Yeti started.

      // Handle drawing charts after AJAX call
      $(document).ajaxComplete(function(event, xhr, settings) {
        if(settings.url == '/views/ajax'){
          var matches = settings.data.match('senator_dashboard_bills');
          if(matches && (matches.length > 0)) {
            NYS.chartInit();
          }
        }
      });
    }
  };

  NYS = {
    win: $(window),
    winWidth: $(window).width(),

    chapterBtn: $(".node-chapter .node-title"),
    featLegToggle: $('.c-block-legislation-featured .js-leg-toggle'),
    quoteResSocialToggle: $('.c-block .js-quote-toggle'),
    quoteBillSocialToggle: $('.bill-sponsor-quote .js-quote-toggle'),
    dropdowns: $('.dropdown .l-active-container'),
    dropdownItem: $('.dropdown .c-item-button'),
    tabLink: $('.c-tab .c-tab-link'),
    fbConnectLink: $('.fb_login'),
    searchToggle: $('.js-search--toggle'),

    carouselNavBtn: $('.c-carousel--nav .c-carousel--btn'),
    carouselAnimating: false,

    accordions: $("[id^='accordion-']"),
    accordionBtns: $('.accordion--btn'),

    loginBtn: $('.ctools-modal-login-modal'),

    senAndCommJumpLink: $('.c-senators-committees-header .c-container--link'),

    ayeColor: '',
    nayColor: '',

    isScrolling: false,
    isBillPage: $('body').hasClass('node-type-bill') ? true : false,

    isTouch: 'ontouchstart' in document.documentElement,

    init: function() {
      this.socialSharing();

      // TODO: establish logic.
      //  this function should only be called if up-to--container exists
      this.highlightUpTo();

      this.bindEvents();
    },

    isIE8orLess: function () {
      return $('html').hasClass('lt-ie9');
    },

    /*
      highlightUpTo() changes the class so the highlight circle moves
      on info graphic areas
    */
    highlightUpTo: function() {
      var item = $('.c-stats--container .c-stats--item');
      var highlight = $('.c-stats--container .c-stats--highlight');

      if($(window).innerWidth() > 760) {
        item.on('hover', function(){
          var elem = $(this).children('.c-stat--illus');

          if(elem.hasClass('c-illus__signed')) {
            highlight.attr('class', 'c-stats--highlight highlight-first');
          }
          else if(elem.hasClass('c-illus__waiting')) {
            highlight.attr('class', 'c-stats--highlight highlight-second');
          }
          else if(elem.hasClass('c-illus__vetoed')) {
            highlight.attr('class', 'c-stats--highlight highlight-third');
          }
        });
      }
    },
    /*
      accordionText() is functionality added as callback
      to foundation's accordion.
      - grab text stored in data attribute and replace
      current text
      ** something is wrong and this is no longer bound to 'toggled'
        bound to click
    */
    accordionText: function(event) {
      var target = $(event.target);
      var accordion = target.siblings('[id^="accordion-"]');
      var openText = target.data('open-text');
      var closedText = target.data('closed-text');

      if(typeof openText !== 'undefined' && typeof closedText !== 'undefined') {
        if(accordion.hasClass('active')) {
          target.html(closedText)
        }
        else {
          target.html(openText);
        }
      }

      return;
    },
    /*
      TODO: toggle chapter should be replaced with
      foundation's accordion
    */
    toggleChapter: function() {
      var collapseClass = 'c-chapter__collapsed';
      var parent = $(this).parent('.node-chapter');
      var ctaText = $(this).find('.c-chapter-cta');
      var openedText = "Collapse Section";
      var closedText = "Read More"

      if(parent.hasClass(collapseClass)) {
        parent.removeClass(collapseClass);
        ctaText.text(openedText);
      } else{
        parent.addClass(collapseClass);
        ctaText.text(closedText);
      }
    },
    /*
      Opens Feature Legislation blocks.
      Toggles social icons visible / hidden
      -removes collapsed class from blocks that have it.
      -users cannot collapse the blocks
      -applies social-visible class and toggles that state
    */
    toggleFeatureLeg: function() {
      var collapseClass = 'c-block__collapsed';
      var viewSocialClass = 'c-social-visible';
      var parent = $(this).parent('.c-block-legislation-featured');

      if(parent.hasClass(collapseClass)) {
        parent.removeClass(collapseClass);
      } else{
        if(parent.hasClass(viewSocialClass)){
          parent.removeClass(viewSocialClass)
        } else {
          parent.addClass(viewSocialClass);
        }
      }

    },

    toggleResSocial: function() {
      var viewSocialClass = 'c-social-visible';
      var parent = $(this).parent('.c-block');

      if(parent.hasClass(viewSocialClass)){
        parent.removeClass(viewSocialClass)
      } else {
        parent.addClass(viewSocialClass);
      }
    },

    toggleBillSocial: function() {
      var viewSocialClass = 'c-social-visible';
      var parent = $(this).parent('.bill-sponsor-quote"');

      if(parent.hasClass(viewSocialClass)){
        parent.removeClass(viewSocialClass)
      } else {
        parent.addClass(viewSocialClass);
      }
    },

    toggleDropdown: function(e) {
      var dropdown = $(this).parent('.dropdown');

      if(dropdown.hasClass('u-open')) {
        dropdown.removeClass('u-open');
      } else {
        dropdown.addClass('u-open');
      }
    },

    menuItemClick: function() {
      var item = $(this);
      var value = $(this).html();
      item.parents('.dropdown').find('.c-active').html(value);
      item.parents('.dropdown').removeClass('u-open');
    },

    toggleTabDropdown: function() {
      var tab = $(this).parent('.c-tab');
      var tab_bar = $(this).parents('.l-tab-bar');

      if(tab.hasClass('active') && !tab_bar.hasClass('open')){
        tab_bar.addClass('open');
      } else {
        tab_bar.removeClass('open');
      }
    },
    /*
      carouselAdvance() - navigates mobile carousel
      markup should be -
        -a carousel nav .c-carousel--nav with btns
        -adjacent to .js-carousel which is a wrapper
        containing carousel items.
        -carousel only works for single items.
    */

    carouselAdvance: function(e) {

      if(NYS.carouselAnimating) return;

      var $this = $(this);
      var nav;

      // the nav is a different relationship if we're touch
      if(e.direction == 4 || e.direction == 2) {
        nav = $(e.target).parents('.js-carousel').siblings('.c-carousel--nav');
        // this happens on the tour carousel has different DOM
        if(nav.attr('class') == undefined) {
          nav = $(e.target).parents('.c-tour--carousel-wrap').siblings('.c-carousel--nav')
        }
      }
      else {
        nav = $this.parent('.c-carousel--nav');
      }

      var wrap = nav.parent();
      var carousel = wrap.find('.js-carousel');
      var carouselWidth = carousel.width();
      var itemAmt = carousel.children().length
      var itemWidth = carousel.width() / itemAmt;
      var carouselPos = parseInt(carousel.css('left'));
      var newPos;
      var activeElem;

      // if the previous button is hidden - do not move that way or at all
      if (e.direction == 4 && nav.children('.prev').hasClass('hidden')) {
        return false;
      }
      // if the next button is hidden - do not move that way or at all
      else if (e.direction == 2 && nav.children('.next').hasClass('hidden')) {
        return false;
      }
      else {
        e.preventDefault();
      }

      // set flag to stop button jammers
      NYS.carouselAnimating = true;

      var setCarouselAnimating = function() {
        NYS.carouselAnimating = false;
      };

      // logic to set directionaltiy and left offset of carousel
      if($this.hasClass('prev') || e.direction == 4) {
        newPos = carouselPos + itemWidth;
        activeElem = Math.abs(carouselPos) / itemWidth - 1;

        NYS.checkCarouselBtns(nav, activeElem, itemAmt);
      }
      else if($this.hasClass('next')  || e.direction == 2) {

        newPos = carouselPos - itemWidth;
        activeElem = Math.abs(carouselPos) / itemWidth + 1;

        NYS.checkCarouselBtns(nav, activeElem, itemAmt);
      }

      carousel.css({
        left: newPos
      });

      // settimeout based on length of css transition -- stops button jammers
      setTimeout(setCarouselAnimating, 300);

    },

    checkCarouselBtns: function(nav, activeElem, itemAmt) {
      // logic to toggle visiblity of btns
      if(activeElem > 0) {
        nav.children('.prev').addClass('visible').removeClass('hidden');
      }
      else if(activeElem < 1) {
        nav.children('.prev').addClass('hidden').removeClass('visible');
      }

      if(activeElem >= itemAmt - 1) {
        nav.children('.next').addClass('hidden').removeClass('visible');
      }
      else if(activeElem <= itemAmt - 1) {
        nav.children('.next').addClass('visible').removeClass('hidden');
      }
    },

    socialSharing: function() {
      $('.twitter-share').hover(function() {
        $(this).sharrre({
          share: {
            twitter: true
          },
          buttons: {
            twitter: {
            }
          },
          enableHover: false,
          enableTracking: false,
          click: function(api, options){
            api.simulateClick();
            api.openPopup('twitter');
          }
        });
      });

      // bind facebook button on hover
      $('body').on(  'mouseenter', '.facebook-share', function(e) {
        // grab data attrtibutes for sharing
        e.preventDefault();
        var my_url = $(this).data('url');
        var track_url = my_url.split('?')[0];

        $(this).sharrre({
            share: { facebook: true },
            url: my_url,
            enableHover: false,
            enableTracking: false,
            click: function(api, options){
              api.simulateClick();
                api.openPopup('facebook');
              dataLayer.push({
                'event': 'socialEvent',
                'socialAction': 'share',
                'socialTarget':  track_url,
                'socialChannel': 'facebook',
                'pathName': window.location.pathname
              });
            }
        });
      });
    },

    chartInit: function(){
      $('.pieContainer').not('.processed').each(function(){
        if($(this).hasClass('processed')) return;
        $aye = parseInt($(this).find('.aye').html());
        $nay = parseInt($(this).find('.nay').html());
        $voteType  = $(this).find('.vote_type').html();
        $total = parseInt($aye+$nay);
        if(!(isNaN($aye) || isNaN($nay))) {
          NYS.drawPieChart($(this), $aye, $nay, $voteType);
        }
        $(this).addClass('processed');
      });
    },

    drawPieChart: function(element, aye, nay, voteType) {
      voteType = voteType || 'floor';
      if (voteType == 'committee') {
          yesColor = '#F1AF58';
          noColor = '#CB8D37';
      } else {
          yesColor = '#04A9C5';
          noColor = '#1F798F';
      }

      if((aye == 0) && (nay == 0)) { aye=1; nay=0; yesColor='#ccc';}
      var pieWidth = 130;
      var pieHeight = 130;
      if(NYS.win.width() >= 760) { pieWidth = 180; pieHeight = 180;}
      var votesData = [{y:nay, color: noColor, sliced: true}, {y:aye, color: yesColor}];
      element.highcharts({
                chart: {
                    type: 'pie',
                    backgroundColor:'rgba(255, 255, 255, 0.1)',
                    // renderTo: 'chartcontainer',
                    height: pieHeight,
                    width: pieWidth,
                    margin: [0, 0, 0, 0],
              spacingTop: 0,
              spacingBottom: 0,
              spacingLeft: 0,
              spacingRight: 0,
                },
                credits: {
                enabled: false
              },
              yAxis: {
                  title: {
                      text: ''
                  }
              },
               title: {
                  text: ''
              },
                plotOptions: {
                  pie: {
                    size:'100%',
                    startAngle: 0,
                    borderColor: yesColor
                  },
                    series: {
                      states: {
                        hover: {
                            brightness: 0.03
                        }
                    },
                        dataLabels: {
                            enabled: false,
                        }
                    }
                },
        tooltip: {
                  enabled: false
              },
              exporting: {
                  enabled: false
              },

                series: [{
                    name: 'Votes',
                    data: votesData
                }],
            });
    },

// Commenting out show/hide for voting box on bill pages. Retaining code in case this needs to be reverted. If not, please remove.
//    showBillVoteWidget: function() {
//      var targetTop = $('.c-detail--status').offset().top;
//      var winTop = NYS.win.scrollTop();
//      var offset = (NYS.win.height() / 2);
//      var voteWidget = $('.c-bill--vote-widget');
//
//      if(NYS.win.width() > 760 && (winTop + offset) > targetTop && !voteWidget.hasClass('visible')) {
//        voteWidget.fadeIn(function(){
//          voteWidget.addClass('visible');
//        });
//      }
//      else if(NYS.win.width() > 760 && (winTop + offset) < targetTop && voteWidget.hasClass('visible')) {
//        voteWidget.fadeOut(function(){
//          voteWidget.removeClass('visible');
//        });
//      }
//    },

    setScroll: function() {
      NYS.isScrolling = true;
      // scroll events
      setInterval(function() {
        if(NYS.isScrolling && NYS.isBillPage) {
          NYS.isScrolling = false;
        }
      }, 250);
    },

    fixBody: function(e) {
      e.preventDefault();
      var openClass = 'overlay-open';
      var body = $('body');

      if(NYS.win.width() < 760 && !body.hasClass(openClass)) {

        body.addClass(openClass);

        $(document).one("CToolsDetachBehaviors", NYS.unfixBody);

      }
    },

    unfixBody: function() {
      var openClass = 'overlay-open';
      var body = $('body');

      if(body.hasClass(openClass))
        body.removeClass(openClass);
    },

    animateToCommittees: function(e) {
      e.preventDefault();

      var headerHeight;
      var targetBlock = $('#c-committees-container');
      /*
        using static values here. do not have to deal with collapsing header -
        b/c always going down. 140/120 are the collapsed header height and
        60/20 are the standard c-block margins to give a little space.
      */
      if(win.width() > 760) {
        headerHeight = 140 + 60;
      }
      else {
        headerHeight = 120 + 20;
      }

      var targetLoc = targetBlock.offset().top - headerHeight;

      $('html, body').animate({
        scrollTop: targetLoc,
      }, 750);
    },

    bindSwipeEvents: function() {

      // carousels for touch

      // homepage ONLY
      if($('#js-carousel-up-to').length > 0) {
        var upToCar = document.getElementById('js-carousel-up-to');
        var upToHam = new Hammer(upToCar);
          upToHam.on('swipe', NYS.carouselAdvance);
      }
      // about page
      if($('#js-carousel-about-stats').length > 0) {
        var aboutStatsCar = document.getElementById('js-carousel-about-stats');
        var aboutStatsHam = new Hammer(aboutStatsCar);
          aboutStatsHam.on('swipe', NYS.carouselAdvance);
      }
      if($('#js-carousel-tour').length > 0) {
        var aboutTourCar = document.getElementById('js-carousel-tour');
        var aboutTourHam = new Hammer(aboutTourCar);
          aboutTourHam.on('swipe', NYS.carouselAdvance);
      }
      // // how a budget / law is made - in footers, about pg, etc
      if($('#js-carousel-budget').length > 0) {
        var budgetCar = document.getElementById('js-carousel-budget');
        var budgetHam = new Hammer(budgetCar);
          budgetHam.on('swipe', NYS.carouselAdvance);
      }
      if($('#js-carousel-law').length > 0) {
        var lawCar = document.getElementById('js-carousel-law');
        var lawHam = new Hammer(lawCar);
          lawHam.on('swipe', NYS.carouselAdvance);
      }
      // // issues page
      if($('#js-carousel-issue-stats').length > 0) {
        var statsCar = document.getElementById('js-carousel-issue-stats');
        var statsHmr = new Hammer(statsCar);
          statsHmr.on('swipe', NYS.carouselAdvance);
      }
    },

    bindEvents: function() {
      this.win.on('scroll', this.setScroll);

      $('#accordion-1').on('toggled', this.accordionText);

      this.accordionBtns.on('click', this.accordionText);

      this.chapterBtn.on('click', this.toggleChapter);

      this.featLegToggle.on('click', this.toggleFeatureLeg);
      this.quoteResSocialToggle.on('click', this.toggleResSocial);
      this.quoteBillSocialToggle.on('click', this.toggleBillSocial);

      this.dropdowns.on('click', this.toggleDropdown);

      this.dropdownItem.on('click', this.menuItemClick);

      this.tabLink.on('click', this.toggleTabDropdown);

      // TODO: bind swipe events as well.
      this.carouselNavBtn.on('click', this.carouselAdvance);

      if(NYS.isTouch) {
        this.bindSwipeEvents();
      }


      // overridding some of the modal functionality
      this.loginBtn.on('click', this.fixBody);

      // senator and commitee jump link
      this.senAndCommJumpLink.on('click', this.animateToCommittees);


      $(window).on('resize', function() {
        if(NYS.win.innerWidth() > 760) {
          $('.js-carousel').attr('style', '');
        }
        else if(NYS.win.innerWidth() < 760 && NYS.win.innerWidth() != NYS.winWidth) {

          if($('.c-carousel--nav').children('.prev').hasClass('visible')) {
            $('.c-carousel--nav').children('.prev').addClass('hidden').removeClass('visible');
          }
          if($('.c-carousel--nav').children('.next').hasClass('hidden')) {
            $('.c-carousel--nav').children('.next').removeClass('hidden').addClass('visible');
          }
        }
      });

      this.fbConnectLink.on('click', function(e){
        var $this = $(this);
              FB.login(function(response) {}, {
                  scope: 'public_profile, email, user_birthday'
              });

              FB.Event.subscribe('auth.statusChange', function(response) {
                  if (response.status === 'connected') {
                      $.post('/user/registration/fb', {
                          redirect_url: $this.attr('data-redirect')
                      }, function(data, el) {
                          var data = $.parseJSON(data);
                          var redirect_url;
                          if (data.status !== 0) {
                              redirect_url = data.redirect_url;
                              window.location = redirect_url;
                          } else {
                              window.location = '/';
                          }
                      });
                  }
              });
      });

      if(
        $('body').hasClass('page-user-dashboard-bills')
        ||
        $('body').hasClass('page-user-dashboard')
        ||
        $('body').hasClass('node-type-bill') )

        this.chartInit();

      if($('body').hasClass('section-committees')) {
        $('.c-committee--see-all').click(function(e){
          e.preventDefault();
          e.stopPropagation();
          var _top = $('#members').offset().top;
          $(window).scrollTop(_top-150);
        })
      }
    }
  }

  NYS.init();

  //Adding behavior for date picker mobile toggle
  Drupal.behaviors.datePickerToggle = {
    attach: function(context, settings) {
      $('#mobile-cal-trigger').click(function() {
          $('.view-display-id-block_1').toggle(200);
          $('.view-display-id-block_3').toggle(200);
          $('.view-display-id-block_4').toggle(200);
      });
    }
  };

  // Removing active trail classes from Overview menu item
  Drupal.behaviors.rmOverviewActiveTrail = {
    attach: function(context, settings) {

      var myURL = window.location.pathname;
      var linkArray = myURL.split('/'),
      lastItem = linkArray[linkArray.length-1];

      if ($('body').hasClass('senator-dashboard')) {
        if (lastItem !== "dashboard") {
          $('.panel-col-first .pane-content .menu li.first a').removeClass('active-trail');
          $('.panel-col-first .pane-content .menu li.first a').removeClass('active');
        }
      }
      if ($('body').hasClass('constituent-dashboard')) {
        if (myURL == "/user/dashboard/issues") {
          $('.constituent-dashboard .panel-col-first .pane-content .menu li.first a').addClass('active-trail');
          $('.constituent-dashboard .panel-col-first .pane-content .menu li.first a').addClass('active');
        }
      }
    }
  };

  // Add class to senator menu items that are visible
  Drupal.behaviors.inactiveNavs = {
    attach: function(context, settings) {
      $('.c-senator-footer-col__nav a').filter(function() {
        var text = $(this).text();
        return text === 'Legislation';
      }).addClass('visible');
      $('.c-senator-nav a').filter(function() {
        var text = $(this).text();
        return text === 'Legislation';
      }).addClass('visible');
    }
  };

  // Add placeholder to issues search box
  Drupal.behaviors.exploreIssuesSearch = {
    attach: function(context, settings) {
      $('#edit-keyword', '.page-explore-issues').attr('placeholder', 'Search for issues that matter to you...');
      $('#edit-name', '.page-explore-issues').attr('placeholder', 'Search for issues that matter to you...');
    }
  };

  // Add active class to current microsite link menu item
  Drupal.behaviors.setMicroNavActive = {
    attach: function(context, settings) {
      var url = window.location.href;

      // Will also work for relative and absolute hrefs
      $('.c-senator-nav a').filter(function() {
          return this.href == url;
      }).addClass('active');
    }
  };
  // Set calendar filters labels
  Drupal.behaviors.setSelectListsLabels = {
    attach: function(context, settings) {
      $('select#edit-type > option:first-child', '.page-calendar')
        .text('Filter By Type');
    }
  };
  // allow manual closing of flag messages
  Drupal.behaviors.closeFlag = {
    attach: function(context, settings) {
      if($('.flag-message .close-message').length) {
        $('.flag-message .close-message').click(function() {
          $(this).parent().remove();
        });
      }
    }
  };

  // Set calendar filters labels
    Drupal.behaviors.calendarPageInit = {
    attach: function(context, settings) {
      if($('#edit-field-date-value-value input').val()) {
        $('#datepicker input').val($('#edit-field-date-value-value input').val());
      }
      if($('#edit-field-date-value-min input').val()) {
        $('#datepicker input').val($('#edit-field-date-value-min input').val());
      }

      if($('body').hasClass('page-events')) {
        // Init variables
        var viewType = '';
        var formatType = 'm/d/Y';

        // Check the type of view i.e day/week/month and initialize datepicker options
        if($('.view-calendar-page.view-display-id-page').length > 0) {
          viewType = 'day';
        }
        if($('.view-calendar-page.view-display-id-month').length > 0) {
          viewType = 'month';
          formatType = 'm/Y';
        }
        if($('.view-calendar-page.view-display-id-week').length > 0) {
          viewType = 'week';
        }

        // Initialize Zebra Datepicker
        $('#datepicker input').Zebra_DatePicker({
          always_visible: $('#container'),
          show_clear_date: false,
          show_icon: false,
          show_select_today: false,
          first_day_of_week: 0,
          format: formatType,
          onSelect: function(format, jsdate, dateobj) {
            var inputElement = '';

            if(viewType == 'week') inputElement = $('#edit-field-date-value-min input');
            else inputElement = $('#edit-field-date-value-value input');

            inputElement.val(format);
            inputElement.parents('form').submit();
          },
          onOpen: function() {
            this.trigger('change');

            var _text = $('.dp_header .dp_caption').html();
            var _selected = $('.dp_selected').html();
            var _month = _text.split(',');

            if(viewType == 'day') {
              $('.mobile-calendar-toggle').html('Viewing Day of '+_month[0]+' '+_selected);
              $('.cal-nav-wrapper span.title').html(_month[0]+' '+_selected+','+_month[1]);
            }
            if(viewType == 'week') {
              var lastDayOfMonth = '';
              $('.currentweek td').each(function(){
                if(!$(this).hasClass('dp_not_in_month')) lastDayOfMonth = $(this).html();
              });
              $('.mobile-calendar-toggle').html('Viewing Week of '+_month[0]+' '+$('.currentweek td:first').html());
              // $('.cal-nav-wrapper span.title').html('Week of '+_month[0]+' '+$('.currentweek td:first').html()+'-'+lastDayOfMonth+','+_month[1]);
              $('.cal-nav-wrapper span.title').html('Week of '+_month[0]+' '+$('.currentweek td:first').html()+','+_month[1]);

            }
            if(viewType == 'month') {
              $('.mobile-calendar-toggle').html('Viewing month of '+_month[0]);
              $('.cal-nav-wrapper span.title').html(_text);
            }
            $('.cal-nav-wrapper span.title').css('display','inline-block');
          },
          onChange: function(view, elements) {
            elements.each(function(i) {
              if((viewType == 'week') && $(this)[0].className.match(/dp_selected$/)) {
                $(this).parent().addClass('currentweek');
                $(this).parents('table').addClass('week');
              }
            });
          },
        });

        // a bit of a hack to keep header the correct width.
        $('#datepicker .dp_header').css('width', '100%');

        $('.mobile-calendar-toggle').live('click', function(){
          $(this).hide();
          $(this).parent().find('#container .Zebra_DatePicker').show();
        })
      }
    }
  };

  // Fixed messages on Senator contact page site messages
  Drupal.behaviors.senatorMessages = {
    attach: function(context, settings) {
      var messages = $('.js-messages--senator');
      var header = $('.node-type-senator #js-sticky--clone');

      // If there's a message, add classes for fixed positions
      if (messages.length) {
        messages.addClass('messages-open');
        header.addClass('messages-open');

        messages.find('.close').on('click', function() {
          messages.removeClass('messages-open');
          header.removeClass('messages-open');
        });
      }
    }
  };

  // Set calendar filters labels
    Drupal.behaviors.senatorCalendar = {
      attach: function(context, settings) {
        if($('.view-senator-events').length > 0) {
          $('ul.pager-load-more a').live('click', function(e){
            e.preventDefault();
            e.stopPropagation();
            if($(this).hasClass('processed')) return;
            $(this).addClass('processed');
            var _parent = $(this).parents('.view');
            var _url = $(this).attr('href')+'&class='+$(this).parents('.view').attr('class');

            // make ajax call for paging between issues
          $.ajax(_url, {
            success: function(data) {
              var source = $('<div>' + data + '</div>');
              var _content = source.find('.view .view-content').html();
              var _loadmore = source.find('.view .attachment-after').html();

              _parent.find('.view-content').append(_content);
              _parent.find('.attachment-after').html(_loadmore);

            }
          });
          });
        }
      }
    };

})(jQuery, Drupal);

jQuery(document).ready(function() {
  jQuery('.quickFactsLink').click(function() {
    var panelNumber = jQuery(this).data('panel');
    
    var theViewportWidth = jQuery(window).width();
    var headingCurrentPosition = jQuery('#issuesUpdatesHeader').offset().top;
    var currentPagePosition = jQuery(window).scrollTop();
    var pageBody = jQuery('HTML, BODY');
    
    jQuery('#tab' + panelNumber).click();

    if (theViewportWidth > 769) {
      pageBody.stop().animate({scrollTop:headingCurrentPosition - 220}, '1000', 'swing');
    }
    else {
      pageBody.stop().animate({scrollTop:headingCurrentPosition - 110}, '1000', 'swing');
    }
  });
  
  jQuery(document).ajaxSuccess(function() {
    // Alter committee page link label on the senators-committees page based on filters.
    if (jQuery('#edit-tid').length) {
      theValue = jQuery('#edit-tid').val();
      theCommittee = jQuery("#edit-tid option:selected" ).text();
      theLink = jQuery('.c-committee-title:contains(' + theCommittee + ')').parent().prop('href');
      $scLink = jQuery('#scLink');
      $scLink.prop('href', theLink).html('Visit The ' + theCommittee + ' Committee Page');
      jQuery('#senator-committee-link').css('display', 'block');
    }
  });
  
  jQuery(document).ready(function() {
    jQuery('.bill-version-tab').click(function() {
      bill_version = jQuery(this).data('version');
      new_url = jQuery(this).data('target');
      history.pushState({}, "NY State Senate Bill " + bill_version, new_url);
      jQuery('DL.l-tab-bar').find('DD.active').removeClass('active');
      jQuery(this).parent().addClass('active');
      jQuery('.tabs-content').find('.active').removeClass('active');
      jQuery('.tabs-content').find('[data-version="' + bill_version + '"]').addClass('active');
    })
  })

  var mobileTabClickCount = 0;

  jQuery(document).ready(function() {
    jQuery('.bill-version-tab-mobile').click(function() {
      mobileTabClickCount++;
      if (mobileTabClickCount % 2 == 1) {
        jQuery('#mobile-bill-tab').css('padding-top', '0px').find('DD.active').removeClass('active');
        jQuery('#mobile-bill-arrow').css('display', 'none');
      }
      else {
        bill_version = jQuery(this).data('version');
        new_url = jQuery(this).data('target');
        history.pushState({}, "NY State Senate Bill " + bill_version, new_url);
        jQuery('#mobile-bill-tab').css('padding-top', '45px').find('[data-version="' + bill_version + '"]').parent().addClass('active');
        jQuery('#mobile-bill-arrow').css('display', 'block');
        jQuery('.tabs-content').find('.active').removeClass('active');
        jQuery('.tabs-content').find('[data-version="' + bill_version + '"]').addClass('active');
      }
    })
  });

  jQuery(document).ready(function() {
    jQuery('.text-expander').click(function() {
        link = jQuery(this);
        expander = jQuery(this).parent().parent().parent().prev();
        lineCount = jQuery(this).parent().parent().parent().prev().data('linecount');
        anchor = jQuery(this).parent().parent().parent().parent().prev().prev();
        part_1_text = expander.prev();
        if (expander.is(':hidden')) {
            expander.slideToggle(0);
            jQuery('html,body').animate({scrollTop: (expander.offset().top - 180)});
            link.html('View Less');
            link.addClass('expanded');
        }
        else {
            expander.slideToggle(0);
            jQuery('html,body').animate({scrollTop: (anchor.offset().top - 180)});
            link.html('View More (' + lineCount + ' Lines)');
            link.removeClass('expanded');
        }
    });
  });

    jQuery(document).ready(function() {
        jQuery('.u-text-expander--inline').click(function() {
            link = jQuery(this);
            ellipsis = jQuery(this).prev();
            hiddenText = jQuery(this).next();
            ellipsis.html(';');
            link.remove();
            hiddenText.fadeIn();
        });
    });



});

