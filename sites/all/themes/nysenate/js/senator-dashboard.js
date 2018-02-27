(function ($, Drupal) {

	var NYS_DB = {

		init: function() {

			this.bindEvents();
		},

		bindEvents: function() {

			/****************************************************
				Issues Tab
			*****************************************************/
			// Toggle user block
			$('.view-senator-dashboard-issues.view-display-id-block .issue-follower-header').live('click', function(){
				$(this).parent().find('form').toggle();
			});

			// AJAX function to handle loading of issues
			$('.view-senator-dashboard-issues.view-display-id-block .more-link a').live('click', function(e){
				e.preventDefault();
				e.stopPropagation();
				var pagenumber = $(this).attr('href').split('page=')[1];
				var nameSearch = $('#senator-issues #edit-keys').val();
				var userId = $('#senator-issues #userid').val();
				var sortSearch = $('#senator-issues select').val();

				var issueAjaxUrl = '/nys-dashboard/get-issues?nameSearch='+nameSearch+'&sortSearch='+sortSearch+'&userid='+userId+'&page='+pagenumber;
				$(this).append('<div class="ajax-progress-throbber" style="top:-10px;"><div class="throbber" style="text-align: center;margin: 0 auto;"></div></div>');
				// make ajax call for paging between issues
				$.ajax(issueAjaxUrl, {
					success: function(data) {
						var source = $('<div>' + data + '</div>');
						var rowcount = source.find('.view-content .issue-container').length;

						// Update the pager counter
						if(source.find('.more-link.pager-load-more').length > 0) $('.view-senator-dashboard-issues.view-display-id-block .more-link').html(source.find('.more-link.pager-load-more').html());
						// if(rowcount == 10) $('.view-senator-dashboard-issues.view-display-id-block .more-link a').attr('href', '/nys-dashboard/get-issues?page='+(parseInt(pagenumber)+1))
						else $('.view-senator-dashboard-issues.view-display-id-block .more-link a').remove();

						// Update the issues content
						$('.view-senator-dashboard-issues.view-display-id-block .view-content').append(source.find('.view-content').html());
					}
				});
			});

			// AJAX function to retrieve users on senator dashboard issues tab
			$('.view-senator-dashboard-issues.view-display-id-block .issue-container .user-list .pagination-centered ul.pager li a').live('click', function(e){
				var _this = $(this);
				var userRetrieveUrl = $(this).attr('href');
				e.preventDefault();
				e.stopPropagation();
				$(this).append('<div class="ajax-progress-throbber"><div class="throbber"></div></div>');

				// make ajax call for paging between users for each issue
				$.ajax(userRetrieveUrl, {
					success: function(data) {
						var source = $('<div>' + data + '</div>');

						_this.parents('#senator_constituents_table').find('.stat-data tbody').html(source.find('.#senator_constituents_table table tbody').html());
						_this.parents('#senator_constituents_table').find('.pagination-centered').html(source.find('#senator_constituents_table .pagination-centered').html());
					}
				});
			});

			/*
			* AJAXify issues sort functionality on senator dashboard
			 */
			$('#senator-issues .filter-wrapper select').on('change', function(e){
				$(this).parents('form').trigger('submit');

			});

			$('form#senator-issues').on('submit', function(e){
				e.preventDefault();
				e.stopPropagation();
				var nameSearch = $('#senator-issues #edit-keys').val();
				var userId = $('#senator-issues #userid').val();
				var sortSearch = $('#senator-issues select').val();

				var issueAjaxUrl = '/nys-dashboard/get-issues?nameSearch='+nameSearch+'&sortSearch='+sortSearch+'&userid='+userId+'&page='+0;
				$(this).append('<div class="ajax-progress-throbber"><div class="throbber"></div></div>');
				// make ajax call for paging between issues
				$.ajax(issueAjaxUrl, {
					success: function(data) {
						var source = $('<div>' + data + '</div>');
						var rowcount = source.find('.view-content .issue-container').length;

						// Update the issues content
						$('.view-senator-dashboard-issues.view-display-id-block .more-link').html(source.find('.more-link.pager-load-more').html());
						$('.view-senator-dashboard-issues.view-display-id-block .view-content').html(source.find('.view-content').html());
						$('form#senator-issues .ajax-progress-throbber').remove();

					}
				});
			});

			// Filter messages based on communication status
			$('.issue-filters select').live('click', function(){
				$(this).one('change', function(){
					var _view = $(this).parents('.view');
					var _type = '';
					if(_view.hasClass('view-display-id-petitions')) _type = 'petitions';
					if(_view.hasClass('view-display-id-questionnaires')) _type = 'questionnaires';
					if(_view.hasClass('view-id-senator_dashboard_issues')) _type = 'issues';
					if($('#nys_senators_constituents_bills').length > 0) _type = 'bills';
					var _this = $(this);
					var _comm_status = $(this).val();
          var _vid = '';
          _view.attr('class').split(' ').each(function() {
            if (this.match(/^view-dom-id-.*$/)) {
              _vid = this.split('-')[1];
            }
          });
          var _senator_id = $(this).parents('form').find('input[name=senator_id]').val();
					var _tid = $(this).parents('form').find('input[name=issue_id]').val();
					var _nid = $(this).parents('form').find('input[name=petition_id]').val();
					var _url = '';
					var _vote_type = '';
					var _bill_name = '';
					var _loaded_user = '';

					switch(_type) {
						case 'issues':
							_url = '/nys-dashboard/issues-users?view=senator_issues&tid='+_tid+'&comm_status='+_comm_status;
							break;
						case 'petitions':
							_url = '/nys-dashboard/petitions-users?view=senator_issues&vid='+_vid+'&senator_id='+_senator_id+'&nid='+_nid+'&comm_status='+_comm_status;
							break;
						case 'questionnaires':
							_url = '/nys-dashboard/questionnaires-users?view=senator_issues&nid='+_nid+'&comm_status='+_comm_status;
							break;
						case 'bills':
							_vote_type = $('select.vote_type').val();
							_comm_status = $('select.comm_status').val();
							_bill_name = $('input[name="namesearch"]').val();
							_loaded_user = $('input#loaded_user').val();
							_url = '/nys-dashboard/bills-users?view=senator_bills&comm_status='+_comm_status+'&vote_type='+_vote_type+'&bill_name='+_bill_name+'&userid='+_loaded_user;
							break;
					}


					// make ajax call for paging between users for each issue
					$.ajax(_url, {
						success: function(data) {
							var source = $('<div>' + data + '</div>');
							var new_html = '';
							new_html = source.find('#senator_constituents_table table tbody').html();

							_this.parents('.issue-filters').find('#senator_constituents_table').find('.stat-data tbody').html(new_html);
							_this.parents('.issue-filters').find('#senator_constituents_table').find('.pagination-centered').html(source.find('#senator_constituents_table .pagination-centered').html());
						   Drupal.attachBehaviors();
						}
					});
				});
			});

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

			// AJAX function to retrieve users on senator dashboard bills tab
			$('#nys_senators_constituents_bills #senator_constituents_table .pagination-centered ul.pager li a').live('click', function(e){
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

			// Moved this functionality to submit event of form submit enclosing this button
			/*$('.bill-name-search').live('change', function(e){

				e.preventDefault();
				e.stopPropagation();

				var _vote_type = $('select.vote_type').val();
				var _comm_status = $('select.comm_status').val();
				var _bill_name = $(this).val();
				var _url = '/nys-dashboard/bills-users?view=senator_bills&comm_status='+_comm_status+'&vote_type='+_vote_type+'&bill_name='+_bill_name;

				// make ajax call for paging between users for each issue
				$.ajax(_url, {
					success: function(data) {
						var source = $('<div>' + data + '</div>');
						var new_html = '';
						new_html = source.find('#senator_constituents_table table tbody').html();

						$('#senator_constituents_table').find('.stat-data tbody').html(new_html);
						$('#senator_constituents_table').find('.pagination-centered').html(source.find('#senator_constituents_table .pagination-centered').html());
					}
				});
			});*/

			$('#nys-dashboard-senator-bills-form #edit-submit').live('click', function(e){
				var parentForm = $(this).parents('form');
				e.preventDefault();
				e.stopPropagation();

				var _vote_type = parentForm.find('select.vote_type').val();
				var _comm_status = parentForm.find('select.comm_status').val();
				var _bill_name = parentForm.find('input.bill-name-search').val();
				var _loaded_user = $('input#loaded_user').val();
				var _url = '/nys-dashboard/bills-users?view=senator_bills&comm_status='+_comm_status+'&vote_type='+_vote_type+'&bill_name='+_bill_name+'&userid='+_loaded_user;

				// make ajax call for paging between users for each issue
				$.ajax(_url, {
					success: function(data) {
						var source = $('<div>' + data + '</div>');
						var new_html = '';
						new_html = source.find('#senator_constituents_table table tbody').html();

						$('#senator_constituents_table').find('.stat-data tbody').html(new_html);
						$('#senator_constituents_table').find('.pagination-centered').html(source.find('#senator_constituents_table .pagination-centered').html());
					}
				});
			});

			$('#nys-dashboard-senator-bills-form').live('submit', function(e){
				if($(this).find("input:focus").length > 0) {
					if($(this).find("input:focus")[0].name == 'namesearch') {
						e.preventDefault();
						e.stopPropagation();
						$(this).find('#edit-submit').trigger('click');
					}
				}
			});
		}
	}

	NYS_DB.init();

})(jQuery, Drupal);


