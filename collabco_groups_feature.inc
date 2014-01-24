<?php

/**
 * @file
 * Helper function for the collabco groups feature.
 */

/*
 * Add a list item for each node bundle, as a link to its node/add page.
 *
 * @return array
 */
function collabco_groups_feature_build_node_links($bundles, $gid = NULL, $options = array()) {
  // Add menu link if the current user can create nodes in the bundle.
  $items = array();
  $options = array_merge($options, collabco_groups_feature_prepopulate_query($gid));
  foreach ($bundles as $bundle) {
    $perm_string = "create $bundle content";
    if (user_access($perm_string)) {
      // Build query array for entity reference prepoluate
      // Construct permission name string for the node bundle.
      $text = t('Create ') . node_type_get_name($bundle);
      $url = "node/add/" . str_replace('_', '-', $bundle);
      $items[$bundle] = l($text, $url, $options); 
    }
  }
  return $items;
}  

/**
 * Build a group list.
 *
 * @return array
 *   A Drupal build array.
 */
function collabco_groups_feature_build_user_groups_list() {
  global $user;

  // Build groups list renderable array.
  $group_links = array();
  $groups = og_get_groups_by_user($user);
  if (!empty($groups)) {
    $list = array(
      '#theme' => 'item_list',
    );
    foreach ($groups['node'] as $key => $gid) {
      $node = node_load($gid);
      $url ='node/' . $node->nid; 
      $list['#items'][$node->nid] = array(
        '#theme' => 'link',
        '#below' => array(),
        '#localized_options' => array(),
        '#attributes' => array(),
        '#title' => $node->title, 
        '#label' => $node->title, 
        '#href' => $url,
      );
    }
    return $list;
  }
} 

/**
 * Add a list item for each taxonomy vocabulary, as a link to its term/add page 
 * and vocabulary view.
 *
 * @return array
 */
function collabco_groups_feature_build_term_links($bundles, $gid = NULL, $options = array()) {
  $items = array();
  $options = array_merge($options, collabco_groups_feature_prepopulate_query($gid));
  foreach ($bundles as $bundle) {
    $vocabulary = taxonomy_vocabulary_machine_name_load($bundle);
    $perm_string = "edit terms in " .  $vocabulary->vid;
    // Construct permission name string for the taxonomy bundle.
    // Add menu link if the current user can create taxonomy terms in the bundle.
    if (user_access($perm_string)) {
      $text = t('Add ') . $vocabulary->name;
      $url = "node/$gid/taxonomy/$bundle/add/";
      $items[$bundle] = l($text, $url, $options); 
      // Link to view to edit all terms in vocab and group.
      $text = t('View ') . $vocabulary->name . ' ' . t('vocabulary');
      $url = "node/$gid/taxonomy/$bundle/";
      $items["view-$bundle"] = l($text, $url); 
    }
  } 
  return $items;
}  

/**
 * Get prepoulate query array to add group context for links.
 *
 * @return array $options
 */
function collabco_groups_feature_prepopulate_query($gid) {
  if ($gid) {
    $query_array = array(OG_AUDIENCE_FIELD => $gid);
    $options = array('query' => $query_array);
    return $options;
  }
  return array();
}


function collabco_groups_feature_get_group_member_ids($entity_type, $gids, $group_type) { 
  $query = db_select('og_membership', 'm')
  ->fields('m', array('etid'))
  ->condition('entity_type', $entity_type, '=')
  ->condition('group_type', $group_type, '=')
  ->condition('state', OG_STATE_ACTIVE, '=')
  ->condition('gid', $gids[$group_type], 'IN');
  $result = $query->execute();

  $etids = array();
  foreach ($result as $row) {
    $etids[] = $row->etid;
  }
  return $etids;
}

/**
 * Get base parent group title, currently only nodes.
 *
 * @return array of group ids.
 */
function collabco_groups_feature_get_title_recursive($group) {
  $title = l($group->title,"node/{$group->nid}");
  if (empty($group->{OG_AUDIENCE_FIELD}['und'][0]['target_id'])) {
    return $title;
  }
  $group_parent = node_load($group->{OG_AUDIENCE_FIELD}['und'][0]['target_id']);
  return collabco_groups_feature_get_title_recursive($group_parent) . ' > ' . $title;
}

/**
 * Get all parent groups, currently only nodes.
 *
 * @return object - the group entity.
 */
function collabco_groups_feature_get_parent_recursive($group) {
  if (empty($group->{OG_AUDIENCE_FIELD}['und'][0]['target_id'])) {
    return $group;
  }
  $group_parent = node_load($group->{OG_AUDIENCE_FIELD}['und'][0]['target_id']);
  return collabco_groups_feature_get_parent_recursive($group_parent);
}

/**
 * Get all child groups, currently only nodes.
 *
 * @return array of group ids.
 */
function collabco_groups_feature_get_children_recursive($gids) {
  // Get children of all passed gids.
  $entity_type = 'node';
  if (!empty($gids[$entity_type])) {
    $result = db_query('SELECT b.gid, b.group_type
    FROM og_membership a, og_membership b
    WHERE a.gid IN (:gids)
    AND a.etid = b.gid 
    AND a.entity_type = :entity_type
    AND b.group_type = :entity_type',
    array(':entity_type' => $entity_type, ':gids' => $gids[$entity_type]));
    foreach ($result as $record) {
      $child_gids[$record->group_type][$record->gid] = $record->gid;
    }
  }
  if (empty($child_gids)) {
    return array();
  }
  $grandchild_gids = collabco_groups_feature_get_children_recursive($child_gids);
  return array_merge($child_gids, $grandchild_gids);
}

/**
 * Add all taxonomy terms from the parent group to the newly created group.
 */
function collabco_groups_feature_add_parent_terms_to_group($entity,$type) { 
  $wrapper = entity_metadata_wrapper($type, $entity);
  // Only look at groups.
  if (!$wrapper->__isset(OG_GROUP_FIELD) || $wrapper->{OG_GROUP_FIELD}->value() == '0') {
    return;
  }
  // And only look at subgroups.
  if (!$wrapper->__isset(OG_AUDIENCE_FIELD) || !($wrapper->{OG_AUDIENCE_FIELD}->value())) {
    return;
  }
  // Find all taxonomy terms in the group.
  $gids = array('node' => array($wrapper->{OG_AUDIENCE_FIELD}->raw())); 
  $tids = collabco_groups_feature_get_group_member_ids('taxonomy_term', $gids, 'node'); 
  // Add all terms from the parent group to the newly created group.
  // This should be done directly with og_group to skip the load/save.
  foreach ($tids as $tid) {
    $term_wrapper = entity_metadata_wrapper('taxonomy_term',taxonomy_term_load($tid));
    $term_wrapper->{OG_AUDIENCE_FIELD}[] = $wrapper->getIdentifier();
    $term_wrapper->save();
  }
}

/**
 * Add a permissions aware create-content link to a view area.
 */
function collabco_groups_feature_views_content_link($view, $display_id, $bundles, $areas) {
  global $user;
  $group = og_context();
  if (empty($group) or !og_is_member($group['group_type'], $group['gid'], 'user', $user)) {
    return;
  }

  $links = array(
    '#theme' => 'item_list',
    '#attributes' => array('class' => array('add-content-links')),
    '#items' => collabco_groups_feature_build_node_links($bundles, $group['gid'])
  );
  // Views wont render the array for us so we render now.
  $rendered_links = drupal_render($links);
  if ($links) {
    $options = array(
       'id' => 'area',
       'table' => 'views',
       'field' => 'area',
       'empty' => TRUE,
       'content' => $rendered_links,
       'format' => 'filtered_html',
       'tokenize' => 0,
    );
    foreach ($areas as $area) {
      $view->add_item($display_id, $area, 'views', 'area', $options);
      //$view->display_handler->set_option($area, array('text' => $options));
    }
  }
}


