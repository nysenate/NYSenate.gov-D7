(function ($, Drupal) {

	NYS.About = {
		win: $(window),
		doc: $(document),
		timeline: $('#js-about-timeline'),
		timelineContainer: $('.c-timeline'),
		timelineIsReady: false,
		timelineBtn: $('[class*=c-timeline-mv-]'),
		leftBtn: $('#moveLeft'),
		rightBtn: $('#moveRight'),

		nav: $('#js-page-nav'),
		navItems: $("#js-page-nav [class*='js-nav-item']"),
		sections: $("[id^='section-']"),
		header: $('#js-sticky--clone'),
		pageNav: $('#js-sticky--clone .c-nav--wrap'),

		collapsedHeaderHeight: 140,
		openHeaderHeight: 200,

		// defined after timeline is built
		timelineItems: null,
		timelineItemsWidth: 0,
		timelineAnim: undefined,
		timelineOffset: 0,
		timelineX: 0,

		timelineHolding: false,
		timelineTicking: false,
		isLeftButtonDown: false,
		isRightButtonDown: false,

		didScroll: false,

		isTouch: 'ontouchstart' in document.documentElement,

		init: function() {
			
			this.aboutPageNav();
			this.getTimelineData();

			this.bindEvents();
		},

		aboutPageNav: function() {

			// Find the offset for each section
			NYS.About.sections.each(function() {
				var this_section = $('#' + this.id);
				var this_height = this_section.outerHeight();

				this.top_offset = this_section.offset().top;
				this.bottom_offset = this.top_offset + this_height;
			});

			// bind .scrollTo to nav links
			NYS.About.navItems.on('click', NYS.About.animateTo);

			$(window).scroll(function(){
				NYS.About.didScroll = true;
			});

			setInterval(function() {
				if(NYS.About.didScroll) {
					NYS.About.didScroll = false;
					NYS.About.checkScroll();
				}
			}, 250);

		},

		animateTo: function(e) {
			e.preventDefault();

			var headerHeight = NYS.About.header.height();
			var targetId = $(e.target).parent('li').attr('data-section');

			var offset;

			var currLoc = NYS.About.win.scrollTop();
			var targetLoc = $("#" +targetId).offset().top;
			
			/*
				if the current location is below the target, the nav will open so the offset should be based on that. otherwise the offset is the closed header height.
			*/
			if(currLoc > targetLoc) {
				offset = NYS.About.openHeaderHeight - 2;
			}
			else {
				offset = NYS.About.collapsedHeaderHeight - 2;
			}

			$('html, body').animate({
				scrollTop: targetLoc - offset,
			}, 750);
		},

		checkScroll: function() {

			var win_top = NYS.About.win.scrollTop();
			var win_height = NYS.About.win.height();

			var offset;

			if(!NYS.About.pageNav.hasClass('closed')) {
				offset = NYS.About.openHeaderHeight;
			}
			else {
				offset = NYS.About.collapsedHeaderHeight;
			}

			var boundary_top = win_top + offset;
			var boundary_bottom = win_top + win_height;
			var active_section;

			// loop through sections. test to see if it's in the right place.
			NYS.About.sections.each(function(){
				if(	(this.top_offset <= boundary_top && this.bottom_offset >= boundary_top) )
		 		{
					active_section = this.id;
				}
			});

			NYS.About.setActiveNavItem(active_section);

			// collapse or expand menu
			if ($(window).scrollTop() > 100){
			   NYS.About.nav.addClass('collapsed');
			}
			else {
			   NYS.About.nav.removeClass('collapsed');
			}
		},

		setActiveNavItem: function(active) {
			// use the active section to set which link is active
			// and offset ul to show that item
			if (active !== undefined) {
				NYS.About.navItems.removeClass('active');
				NYS.About.nav.find("[data-section='" + active + "']").addClass('active');

				// move nav
				NYS.About.nav.children('ul').css('top', active.substr(active.length - 1) * -50 + 'px');
			}
		},

		getTimelineData: function() {
			// DOM where the timeline will be attached
			var container = document.getElementById('js-about-timeline');
			var now = new Date();
			var thisYear = now.getFullYear();
			var JSON;
			var dataArray = [];

			var dataLocation;

			// TODO: add production location or alter this logic altogether

			if(location.host == 'qa.nysenate.codeandtheory.net') {
				dataLocation = 'http://qa.nysenate.codeandtheory.net/api/v1/senate-timeline';
			}
			else {
				dataLocation = '/senate-timeline.json';
			}

			// make ajax call for JSON of content-type
			$.ajax(dataLocation, {
				success: function(data) {
					JSON = data;

					// build a new array
					$.each(data.nodes, function(i){
						data.nodes[i].node.id = i;
						
						// change the key of 'title' to header
						data.nodes[i].node.header = data.nodes[i].node.title;
						delete data.nodes[i].node.title;
						
						// remove 'end' if it has no content - causes errors otherwise
						if(data.nodes[i].node.end.value = undefined);
							delete data.nodes[i].node.end

						dataArray.push(data.nodes[i].node);
					});

					NYS.About.buildTimeline(dataArray);
				}
			});

		},

		buildTimeline: function(JSON) {
			var items = JSON;

			var itemTemplate = function(item, year) {
				return '<div class="timeline-item"><div class="timeline-mark">'+ year +'</div><div class="content"><h4 class="c-timeline-item--header">' + item.header + '</h4><p class="c-timeline-item--body">' + item.description + '</p></div></div>';
			}

			NYS.About.timeline.css({
				'display': 'none',
				'box-sizing': 'content-box',
				'left': 0,
				'top': 70,
			});

			// populate the timeline with each item
			for(var i = 0; i < items.length; i++) {
				var year = items[i].header.substr(items[i].header.length - 4);
				var html = itemTemplate(items[i], year);

				NYS.About.timeline.append(html);
			}

			var timelineLine = '<div class="timeline-line"></div>';

			NYS.About.timeline.append(timelineLine);

			// define global variables
			NYS.About.timelineItems = $('.timeline-item');
			NYS.About.timelineItemsWidth = NYS.About.timelineItems.width();

			// set timeline width
			NYS.About.timeline.width(NYS.About.timelineItemsWidth * NYS.About.timelineItems.length);
			// checkNavBtns disables or enables nav btns
			NYS.About.checkNavBtns()
			// fade in and set timeline is ready to true
			NYS.About.timeline.fadeIn('normal', function(){
				NYS.About.timelineIsReady = true;
			});

		},

		checkNavBtns: function() {
			// hide or show previous button
			if(parseInt(NYS.About.timeline.css('left')) >= 0) {
				if(NYS.About.isLeftButtonDown) {
					NYS.About.stopNavTimeline();
				}
				NYS.About.leftBtn.css('display', 'none');
			}
			else {
				NYS.About.leftBtn.css('display', 'block');
			}
			// hide or show next button
			if (parseInt(NYS.About.timeline.css('left')) <= -parseInt(NYS.About.timeline.width()) + NYS.About.timelineContainer.width()) {
				if(NYS.About.isRightButtonDown) {
					NYS.About.stopNavTimeline();
				}
				NYS.About.rightBtn.css('display', 'none');
			}
			else {
				NYS.About.rightBtn.css('display', 'block');
			}

		},

		moveNavTimeline: function(evt) {
			var target = $(evt.target);
			var direction = target.attr('id') == 'moveLeft' ? 'left' : 'right';
			var item = $('.c-block--about-timeline .timeline-item');
			var itemWidth = item.outerWidth();
			var increment = itemWidth;//35; // in pixels
			var nextLeft;

			// only do anything if we're ready 
			if(NYS.About.timelineIsReady) {
				
				// NYS.About.timelineAnim = setInterval(function(){
					NYS.About.checkTimelineOffset();

					// var currentLeft = Math.ceil((NYS.About.timelineX / NYS.About.timelineContainer.width() ) * 100);
					
					if (direction == 'right') {
						NYS.About.isRightButtonDown = true;


						nextLeft = NYS.About.timelineX - increment;

					}
					else if (direction == 'left') {
						NYS.About.isLeftButtonDown = true;

						nextLeft = NYS.About.timelineX + increment;
					}

					NYS.About.timeline.animate({
						'left': nextLeft
					}, 500);

					NYS.About.checkNavBtns();

				// }, 100);
			}

			return;
		},

		stopNavTimeline: function() {
			clearInterval(NYS.About.timelineAnim);
			
			NYS.About.isLeftButtonDown = false;
			NYS.About.isRightButtonDown = false;

			return false;
		},	

		bindSwipeEvents: function() {
			// make sure to hide nav btns - causes conflict.
			$('.c-timeline .menu').css('display', 'none');
			
			var timeline = document.getElementById('js-about-timeline');

			var tlHammer = new Hammer.Manager(timeline);
				tlHammer.add(new Hammer.Pan({ threshold: 0, pointers: 0, direction: Hammer.DIRECTION_HORIZONTAL}));
    			tlHammer.add(new Hammer.Swipe({direction: Hammer.DIRECTION_HORIZONTAL})).recognizeWith(tlHammer.get('pan'));


			tlHammer.on('panmove', NYS.About.timelinePan);
			
		},

		timelinePan: function(ev) {

			NYS.About.timelineOffset -= ev.velocityX * ((768/window.innerWidth)*20);
			
			var minVal  = (NYS.About.timelineContainer.width() - NYS.About.timeline.width());

			NYS.About.timelineOffset = Math.min(0, Math.max(minVal, NYS.About.timelineOffset));

			NYS.About.updateTimeline();

		},
		/**
		 *	used to create a release event for hammer
		 */
		release: function(ev) {
			if(ev.type === 'hold') {
				NYS.About.timelineHolding = true;
			}
			else if (ev.type === 'touchend' || ev.type === 'mouseup') {
				NYS.About.timelineHolding = false;
        			console.log('release 2');

			}
		},

		checkTimelineOffset: function() {
			NYS.About.timelineX = parseInt(NYS.About.timeline.css('left'));
		},

		updateTimeline: function() {
			
			//NYS.About.timeline.css('transform','translate3d('+NYS.About.timelineOffset+'px,0,0)');

			NYS.About.timeline.css('left', NYS.About.timelineOffset);
			NYS.About.timelineTicking = false;
		},

		bindEvents: function() {
			this.timelineBtn.on('click', NYS.About.moveNavTimeline);
			this.doc.on('mouseup', NYS.About.stopNavTimeline);

			if(NYS.About.isTouch) {
				this.bindSwipeEvents();
			}
		}
	}

	// test for the about page nav and its timeline
	if($("#js-page-nav").length > 0 && $('#js-about-timeline').length > 0) {
		NYS.About.init();

	    var reqAnimationFrame = (function () {
	        return window[Hammer.prefixed(window, 'requestAnimationFrame')] || function (callback) {
	            window.setTimeout(callback, 1000 / 60);
	        };
	    })();
	}

})(jQuery, Drupal);
