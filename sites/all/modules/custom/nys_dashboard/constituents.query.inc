<?php

function nys_dashboard_constituents_query($filters) {


  $user = user_load(arg(1));
  $district_tid = user_get_district_tid($user);
  if(empty($district_tid)) {
    return array();
  }



  $limit = 10;

  $start = $_REQUEST['page'] * $limit;



  $query = "SELECT DISTINCT(u.uid), u.name,
    fn.field_first_name_value AS first, ln.field_last_name_value AS last,
    l.city, l.postal_code,
    FLOOR((unix_timestamp() - dob.field_dateofbirth_value)/(86400*365)) AS age,
    fg.field_gender_user_value AS gender,
    fb.fbid as facebook_verified
    FROM users u
    JOIN field_data_field_district fd ON fd.entity_id = u.uid AND fd.bundle = 'user'
    JOIN field_data_field_first_name fn ON fn.entity_id = u.uid and fn.bundle = 'user'
    JOIN field_data_field_last_name ln ON ln.entity_id = u.uid and fn.bundle = 'user'
    LEFT JOIN field_data_field_dateofbirth dob ON dob.entity_id = u.uid and dob.bundle = 'user'
    LEFT JOIN flagging fl ON fl.uid = u.uid AND fl.entity_type = 'taxonomy_term' AND fl.fid = 4
    LEFT JOIN field_data_field_address fa ON fa.entity_id = u.uid and fa.bundle = 'user'
    LEFT JOIN field_data_field_gender_user fg ON fg.entity_id = u.uid and fg.bundle = 'user'
    LEFT JOIN location l ON l.lid = fa.field_address_lid
    LEFT JOIN fboauth_users fb ON fb.uid = u.uid
    WHERE fd.field_district_target_id = :district_tid
    ";


    $queryArgs = array(
     ':district_tid' => $district_tid,
   );

    if (!empty($filters['namesearch'])) {
      $query .= " and (CONCAT(fn.field_first_name_value, ' ', ln.field_last_name_value) LIKE :namesearch)";

      $queryArgs[':namesearch'] = '%' . $filters['namesearch'] .'%';
    }

    if (!empty($filters['agesearch']) && $filters['agesearch'] != "all") {
      $query .= " and FLOOR((unix_timestamp() - dob.field_dateofbirth_value)/(86400*365)) >= :agesearch_low AND FLOOR((unix_timestamp() - dob.field_dateofbirth_value)/(86400*365)) <= :agesearch_high ";



      $arr = preg_split("/-/", $filters['agesearch']);


      $queryArgs[':agesearch_low'] = $arr[0];
      $queryArgs[':agesearch_high'] = $arr[1];
    }

     if (!empty($filters['issue_id'])) {
      $query .= " and fl.entity_id = :issue_id ";

      $queryArgs[':issue_id'] = $filters['issue_id'];

    }

    if (!empty($filters['gender']) && $filters['gender'] != "all") {

      $gender_values = array(
       'women' => 'female',
       'men' => 'male',
       'other' => 'other'
      );

      if(isset($filters['gender'])) {

        $gender_key = $gender_values[$filters['gender']];

        $query .= " and fg.field_gender_user_value = :gender_value";

        $queryArgs[':gender_value'] = $gender_key;
      }
    }

    if(isset($filters['zipsearch']) && is_numeric($filters['zipsearch'])) {

      $query .= " and l.postal_code = :zipsearch";

      $queryArgs[':zipsearch'] = trim($filters['zipsearch']);
    }

     if(isset($filters['fb']) && $filters['fb'] != "all") {

      if($filters['fb'] == 1) {
        $query .= " and fb.fbid IS NOT NULL";
      } else if ($filters['fb'] == 0) {
        $query .= " and fb.fbid IS NULL";
      }
    }

   $query .= ' ORDER BY last, first';

   return array('query' => $query, 'queryArgs' => $queryArgs);
}
