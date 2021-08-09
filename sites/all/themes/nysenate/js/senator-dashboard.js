(function ($, Drupal) {

	var NYS_DB = {

		init: function() {

			this.bindEvents();
		},

		bindEvents: function() {

			/****************************************************
				Questionnaires Tab
			*****************************************************/
			// Toggle user block
			$('.view-senator-dashboard-petitions-and-questionnaires.view-display-id-questionnaires .poll-signature-header').live('click', function(){
				$(this).parent().find('.user-list').toggle();
			});

			// AJAX function to handle loading of issues
			$('.view-senator-dashboard-petitions-and-questionnaires.view-display-id-questionnaires .more-link a').live('click', function(e){
				e.preventDefault();
				e.stopPropagation();
				var pagenumber = $(this).attr('href').split('?page=')[1];
				var allquest = 0;
				if($(this).parents('.content').hasClass('your-petitions')) allquest = 1;
				$(this).append('<div class="ajax-progress-throbber"><div class="throbber" style="text-align: center;margin: 0 auto;"></div></div>');

				// make ajax call for paging between issues
				// $.ajax('/nys_dashboard_get_questionnaires/'+pagenumber+'/'+allquest, {
				$.ajax($(this).attr('href'), {
					success: function(data) {
						var source = $('<div>' + data + '</div>');
						var rowcount = source.find('.view-content .poll-container').length;
						var tab = '';
						if(allquest == 1) tab = $('.content.your-petitions');
						else tab = $('.content.all-petitions');

						// Update the pager counter
						tab.find('.view-senator-dashboard-petitions-and-questionnaires.view-display-id-questionnaires .more-link.pager-load-more').html(source.find('.more-link.pager-load-more').html());

						// Update the issues content
						tab.find('.view-senator-dashboard-petitions-and-questionnaires.view-display-id-questionnaires .view-content').append(source.find('.view-content').html());
					}
				});
			});

			// AJAX function to retrieve users on senator dashboard questionnaires tab
			$('.view-senator-dashboard-petitions-and-questionnaires.view-display-id-questionnaires .poll-container .user-list .pagination-centered ul.pager li a').live('click', function(e){
				var _this = $(this);
				var userRetrieveUrl = $(this).attr('href');
				e.preventDefault();
				e.stopPropagation();

				// make ajax call for paging between users for each issue
				$.ajax(userRetrieveUrl, {
					success: function(data) {
						var source = $('<div>' + data + '</div>');

						_this.parents('#senator_constituents_table').find('.stat-data tbody').html(source.find('.#senator_constituents_table table tbody').html());
						_this.parents('#senator_constituents_table').find('.pagination-centered').html(source.find('#senator_constituents_table .pagination-centered').html());
					}
				});
			});

			/****************************************************
				Petitions Tab
			*****************************************************/
			// Toggle user block
			$('.view-senator-dashboard-petitions-and-questionnaires.view-display-id-petitions .poll-signature-header').live('click', function(){
				$(this).parent().find('.user-list').toggle();
			});

			// AJAX function to handle loading of petitions
			$('.view-senator-dashboard-petitions-and-questionnaires.view-display-id-petitions .more-link a').live('click', function(e){
				e.preventDefault();
				e.stopPropagation();
				var pagenumber = $(this).attr('href').split('page=')[1];
				var allquest = 0;
				if($(this).parents('.content').hasClass('your-petitions')) allquest = 1;
				$(this).append('<div class="ajax-progress-throbber"><div class="throbber" style="text-align: center;margin: 0 auto;"></div></div>');


				// make ajax call for paging between petitions
				$.ajax($(this).attr('href'), {
					success: function(data) {
						var source = $('<div>' + data + '</div>');
						var rowcount = source.find('.view-content .poll-container').length;
						var tab = '';
						if(allquest == 1) tab = $('.content.your-petitions');
						else tab = $('.content.all-petitions');

						// Update the pager counter
						tab.find('.view-senator-dashboard-petitions-and-questionnaires.view-display-id-petitions .more-link.pager-load-more').html(source.find('.more-link.pager-load-more').html());

						// Update the issues content
						tab.find('.view-senator-dashboard-petitions-and-questionnaires.view-display-id-petitions .view-content').append(source.find('.view-content').html());
					}
				});
			});

			// AJAX function to retrieve users on senator dashboard petitions tab
			$('.view-senator-dashboard-petitions-and-questionnaires.view-display-id-petitions .poll-container .user-list .pagination-centered ul.pager li a').live('click', function(e){
				var _this = $(this);
				var userRetrieveUrl = $(this).attr('href');
				e.preventDefault();
				e.stopPropagation();

				// make ajax call for paging between users for each issue
				$.ajax(userRetrieveUrl, {
					success: function(data) {
						var source = $('<div>' + data + '</div>');

						_this.parents('#senator_constituents_table').find('.stat-data tbody').html(source.find('.#senator_constituents_table table tbody').html());
						_this.parents('#senator_constituents_table').find('.pagination-centered').html(source.find('#senator_constituents_table .pagination-centered').html());
					}
				});
			});

			/****************************************************
				Bills Tab
			*****************************************************/

			// Translates the default pager link into an AJAX call for Messages table on Bills tab.
			$('#nys-dashboard-senator-bills-form ul.pager li a').live('click', function(e){
				let ctrl = $('#nys-dashboard-senator-bills-form').find('.filter-page'),
						element = Drupal.ajax['edit-namesearch'],
						old_page = parseInt($('#senator_constituents_table ul.pager li.current a').text()),
						new_page = 0;
				e.preventDefault();
				e.stopPropagation();
				switch (this.innerText) {
					case '‹ previous':
						new_page = old_page - 1; break;
					case '« first':
						new_page = 0; break;
					case 'next ›':
						new_page = old_page + 1; break;
					case 'last »':
						new_page = 'last'; break;
					default: new_page = this.innerText; break;
				}
				if (new_page < 0 || new_page === 'NaN') { new_page = 0; }
				ctrl.val(new_page);
				if (element.element && element.element_settings.event) {
					$(element.element).trigger(element.element_settings.event);
				}
			});
		}
	}

	NYS_DB.init();

})(jQuery, Drupal);
