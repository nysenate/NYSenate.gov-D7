/*
	By Osvaldas Valutis, www.osvaldas.info
	Available for use under the MIT License

	this plugin helps with mobile double tap for dropdowns.
*/

;(function( $, window, document, undefined )
{
	$.fn.doubleTapToGo = function( params )
	{
		if( !( 'ontouchstart' in window ) &&
			!navigator.msMaxTouchPoints &&
			!navigator.userAgent.toLowerCase().match( /windows phone os 7/i ) ) return false;

		this.each( function()
		{
			var curItem = false;

			$( this ).on( 'click', function( e )
			{
				var item = $( this );
				if( item[ 0 ] != curItem[ 0 ] )
				{
					e.preventDefault();
					curItem = item;
				}
			});

			$( document ).on( 'click touchstart MSPointerDown', function( e )
			{
				var resetItem = true,
					parents	  = $( e.target ).parents();

				for( var i = 0; i < parents.length; i++ )
					if( parents[ i ] == curItem[ 0 ] )
						resetItem = false;

				if( resetItem )
					curItem = false;
			});
		});
		return this;
	};
})( jQuery, window, document );

//	end plugin



(function ($, Drupal) {

	NYS.Nav = {
		origNav: null,
		nav: null,
		menu: null,
		headerBar: null,
		mobileNavToggle: null,
		searchToggle: null,
		topbarDropdown: null,

		origActionBar: null,
		actionBar: null,

		win: null,
		doc: null,

		currentTop: null,
		previousTop: null,

		init: function() {
			// store original nav
			origNav = $('#js-sticky');

			win = $(window);
			doc = $(document);

			currentTop = doc.scrollTop();
			previousTop = 0;

			// we don't support IE 8 - so, quit
			if(NYS.isIE8orLess())
				return;

			// store clone of nav -- make it fixed
			nav = origNav.clone().attr('id', 'js-sticky--clone').addClass('fixed');
			// build the correct one
			if(this.isSenatorLanding()) {
				this.senatorLanding();
			}
			else if(this.isHomepage()) {
				this.basic(true);
			}
			else {
				this.basic(false);
			}

			// bind events after you build
			this.bind();
		},

		storeNewNavItems: function() {
			menu = nav.find('.c-nav--wrap');
			headerBar = nav.find('.c-header-bar');
			mobileNavToggle = nav.find('.js-mobile-nav--btn');
			searchToggle = $('.js-search--toggle');
			topbarDropdown = nav.find('.c-login--list');
		},

		// basic nav setup

		basic: function(isHomepage) {
			// place clone
			nav.prependTo('.page').css({
				'z-index': '100'
			});
			// if we are on the homepage - also clone actionbar and place it
			if(isHomepage) {

				origActionBar = $('.c-actionbar');
				actionBar = origActionBar.clone();

				if(this.isInSession()) {
					actionBar.appendTo(nav);
					origActionBar.css('visibility', 'hidden');
				}
				else {

					actionBar.appendTo(nav).addClass('hidden');
				}
			}

			// store new variables
			this.storeNewNavItems();
			// hide original nav -- just for visual
			origNav.css('visibility', 'hidden');


			if(this.isTooLow()) {
				menu.addClass('closed');
			}

			// bind scrolling
			if (this.isMicroSitePage()) {
				win.scroll(this.microSiteScroll);
			}
			else {
				win.scroll(this.basicScroll);
			}
		},

		// senator landing setup

		senatorLanding: function() {
			var navHeight = -240;
			actionBar = nav.find('.c-senator-hero');

			// place clone
			nav.prependTo('.page').css({
				'z-index': '14',
				// 'top': navHeight
			}).addClass('l-header__collapsed');

			// store new variables
			this.storeNewNavItems();

			// collapse / hide nav
			menu.addClass('closed');
			actionBar.addClass('hidden');
			// set headerBar to collapsed state
			// headerBar.addClass('collapsed');
			origNav.find('.c-header-bar').css('visibility', 'hidden');
			// bind scrolling
			win.scroll(this.senatorLandingScroll);
		},

		// always close search when you scroll - call this within each scroll type
		closeSearch: function() {

			if($('.c-nav--wrap').hasClass('search-open')) {
				$('.c-nav--wrap').removeClass('search-open');
				$('.c-nav--wrap').find('.c-site-search--box').blur();
			}
		},
		// basic scrolling behavior

		basicScroll: function() {
			currentTop = doc.scrollTop();

			// NYS.Nav.closeSearch();

			// homepage NOT in session has different actionbar behavior
			if(NYS.Nav.isHomepage() && !NYS.Nav.isInSession()) {

				if(NYS.Nav.isMovingDown() && currentTop + nav.outerHeight() >= origActionBar.offset().top  ) {
					actionBar.removeClass('hidden');
				}
				else if(NYS.Nav.isMovingUp() && currentTop <= origActionBar.offset().top) {

					actionBar.addClass('hidden');
				}
			}

			NYS.Nav.checkTopBarState();
			NYS.Nav.checkMenuState();

			previousTop = doc.scrollTop();
		},

		microSiteScroll: function() {
			currentTop = doc.scrollTop();

			// NYS.Nav.closeSearch();

			NYS.Nav.checkTopBarState();
			NYS.Nav.checkMenuState();

			previousTop = doc.scrollTop();
		},

		senatorLandingScroll: function() {
			currentTop = doc.scrollTop();

			// NYS.Nav.closeSearch();

			var navHeight = -240;
			var heroHeight = origNav.outerHeight() - menu.outerHeight() - $('.c-senator-hero--contact-btn').outerHeight() - headerBar.outerHeight() - nav.outerHeight();

			// origNav - 100 (menu) - 100 (actionbar / btn) - 40 (headerbar);

			if(win.width() < 760) {
				if(NYS.Nav.isMovingDown() && currentTop >= origNav.outerHeight()) {
          //jQuery('#senatorImage').html(jQuery('#largeShotImage').html());
					actionBar.removeClass('hidden');
					NYS.Nav.checkTopBarState();
				}
				else if(NYS.Nav.isMovingUp() && currentTop < origNav.outerHeight()) {
          jQuery('#senatorImage').html(jQuery('#smallShotImage').html());
					actionBar.addClass('hidden');
					headerBar.removeClass('collapsed');
				}
			}
			else {
				NYS.Nav.checkTopBarState();

				if (NYS.Nav.isMovingUp() && currentTop <= origNav.outerHeight() - 100 - 100 ) {
					menu.addClass('closed');

					if (NYS.Nav.isMovingUp() && currentTop <= origNav.outerHeight() - 100 - 100 - 40 - 100) {
						actionBar.addClass('hidden');
						//jQuery('#senatorImage').delay(500).html(jQuery('#largeShotImage').html());
						jQuery('#largeHeadshot').addClass('hidden');
            jQuery('#smallHeadshot').removeClass('hidden');
					}
				}

				else if(currentTop >= heroHeight) {
					// nav.css('top', 0);
          jQuery('#senatorImage').html(jQuery('#smallShotImage').html());
					actionBar.removeClass('hidden');
					NYS.Nav.checkMenuState();
				}
			}


			previousTop = doc.scrollTop();
		},

		checkTopBarState: function() {
			if(this.isOutOfBounds())
				return;

			if(currentTop > nav.outerHeight() && !headerBar.hasClass('collapsed')) {
				headerBar.addClass('collapsed');
			}
			else if(currentTop <= nav.outerHeight() && headerBar.hasClass('collapsed')){
				headerBar.removeClass('collapsed');
			}
		},

		checkMenuState: function() {

			if(this.isOutOfBounds())
				return;

			if(this.isMovingDown()) {
				menu.addClass('closed');
			}
			else if(this.isMovingUp()){
				menu.removeClass('closed');
			}
		},

		toggleMobileNav: function() {
			var openClass = 'nav-open';
			var body = $('body');
			var navHeight = nav.outerHeight();

			// toggle classes
			if(body.hasClass(openClass)) {
				body.removeClass(openClass);
			} else {
				body.addClass(openClass);
			}
		},

		toggleSearchBar: function(e) {
			e.preventDefault();
			var nav = $(this).parents('.c-nav--wrap');

			if(nav.hasClass('search-open')) {
				nav.removeClass('search-open');
				nav.find('.c-site-search--box').blur();
			}
			else {
				nav.addClass('search-open');
				nav.find('.c-site-search--box').focus();
			}
		},

		isHomepage: function() {
			return $('.view-homepage-hero').length > 0;
		},
		isInSession: function() {
			return this.isHomepage() && $('.c-hero-livestream-video').length > 0;
		},
		isMicroSitePage: function() {
			return $('.c-senator-hero').length > 0;
		},
		isSenatorLanding: function() {
			return this.isMicroSitePage() &&
					!origNav.hasClass('l-header__collapsed');
		},

		isMovingUp: function() {
			return currentTop < previousTop;
		},
		isMovingDown: function() {
			return currentTop > previousTop;
		},
		// deals with bounces
		isOutOfBounds: function() {
			return this.isTooHigh() || this.isTooLow();
		},
		isTooHigh: function() {
			return (currentTop < 0 || previousTop < 0);
		},
		isTooLow: function() {
			// return true;
			return currentTop + win.height() >= doc.height();
		},

		bind: function() {

			mobileNavToggle.on('click', this.toggleMobileNav);
			searchToggle.on('click', this.toggleSearchBar);
			topbarDropdown.doubleTapToGo();

		}
	}

	NYS.Nav.init();

})(jQuery, Drupal);
