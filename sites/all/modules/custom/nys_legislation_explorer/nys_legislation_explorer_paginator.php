<?php

function get_pagination_state($total, $per_page, $curr_page, $max_page_links) {
	$num_pages = ceil($total / $per_page);
	$start_page = 1;
	$end_page = min($max_page_links, $num_pages);
	if ($curr_page > $max_page_links) {
		$start_page = (floor($curr_page / $max_page_links)) * $max_page_links;
		$end_page = $start_page + $max_page_links - 1;
	}
	return array(
		'active' => ($total > $per_page),
		'prev_active' => ($curr_page > 1), 
		'next_active' => ($curr_page < $num_pages),
		'start_page' => $start_page,
		'curr_page' => $curr_page,
		'end_page' => $end_page
	);
}

function render_pagination(&$pagination_state, $base_url, $url_params, $page_param_name) {
	if ($pagination_state['active']) {
   	    unset($url_params['page']);
		$curr_page = $pagination_state['curr_page'];
		$link_url = $base_url . http_build_query($url_params) . '&' . $page_param_name. '='; 
		$links = ($pagination_state['prev_active']) 
			? "<li class='arrow'><a href='" . ($link_url . ($curr_page - 1)) . "'>&laquo;</a></li>" 
			: "";
		for ($i = $pagination_state['start_page']; $i <= $pagination_state['end_page']; $i++) {
			$links .= "<li class='" . (($curr_page == $i) ? 'current' : '') . "''>
			            <a href='" . ($link_url . $i) . "'>${i}</a>
			           </li>";
		}
		$links .= ($pagination_state['next_active'])
			? "<li class='arrow'><a href='" . ($link_url . ($curr_page + 1)) . "'>&raquo;</a></li>"
			: "";
		$html = 
			"<div class='pagination-centered'>
	      <div class='item-list'>
	        <ul class='pagination pager'>${links}
	        </ul>
	      </div>
	    </div>";
	  echo $html;	
	}	  
}
