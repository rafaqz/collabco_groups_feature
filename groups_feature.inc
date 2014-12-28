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
/**
 * Get prepoulate query array to add group context for links.
 *
 * @return array $options
 */
function groups_feature_prepopulate_query($gid) {
  if (!empty($gid)) {
    $query_array = array(OG_AUDIENCE_FIELD => $gid);
    $options = array('query' => $query_array);
    return $options;
  }
  return array();
}
function groups_feature_get_group_member_ids($entity_type, $gids, $group_type) { 
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
 * Get all parent groups, currently only nodes.
 *
 * @return object - the group entity.
 */
function groups_feature_get_parent_recursive($group) {
  if (empty($group->{OG_AUDIENCE_FIELD}['und'][0]['target_id'])) {
    return $group;
  }
  $group_parent = node_load($group->{OG_AUDIENCE_FIELD}['und'][0]['target_id']);
  return groups_feature_get_parent_recursive($group_parent);
}

/**
 * Get all child groups, currently only nodes.
 *
 * @return array of group ids.
 */
function groups_feature_get_children_recursive($gids) {
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
  $grandchild_gids = groups_feature_get_children_recursive($child_gids);
  return array_merge($child_gids, $grandchild_gids);
}

function groups_feature_add_child_groups_to_entity($entity,$type) { 
  // Recursive function needs an array of gids by entity type.
  $wrapper = entity_metadata_wrapper($type, $entity);
  $gids = array('node' => $wrapper->{OG_AUDIENCE_FIELD}->raw()); 
  $child_gids = groups_feature_get_children_recursive($gids);
  if (empty($child_gids['node'])) { 
    return;
  }
  $values = array(
    'entity_type' => $type, 
    'entity' => $entity, 
    'field_name' => OG_AUDIENCE_FIELD, 
    'state' => OG_STATE_ACTIVE,
  );
  foreach ($child_gids['node'] as $gid) {
    og_group('node', $gid, $values);
  }
}

/**
 * Add all taxonomy terms from the parent group to the newly created group.
 */
function groups_feature_add_parent_terms_to_group($entity,$type) { 
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
  $tids = groups_feature_get_group_member_ids('taxonomy_term', $gids, 'node'); 
  // Add all terms from the parent group to the newly created group.
  // This should be done directly with og_group to skip the load/save.
  foreach ($tids as $tid) {
    $term_wrapper = entity_metadata_wrapper('taxonomy_term',taxonomy_term_load($tid));
    $term_wrapper->{OG_AUDIENCE_FIELD}[] = $wrapper->getIdentifier();
    $term_wrapper->save();
  }
}

/**
 * Build a list of groups for the current user.
 *
 * @return array
 *   A Drupal build array.
 */
function groups_feature_build_user_groups_list($account = NULL) {
  if (empty($account)) {
    global $user;
    $account = $user;
  }

  // Build groups list renderable array.
  $group_links = array();
  $groups = og_get_groups_by_user($account);
  if (!empty($groups)) {
    $list = array();
    foreach ($groups['node'] as $key => $gid) {
      if ($node = node_load($gid)) {
        $url ='node/' . $node->nid; 
        $list[$node->nid] = array(
          'title' => $node->title, 
          'href' => $url,
        );
      }
    }
    return $list;
  }
} 

/**
 * Build a group list block.
 *
 * @return array
 *   A Drupal build array.
 */
function groups_feature_build_user_groups_list_block() {
  $block = array();
  $links = groups_feature_build_user_groups_list(); 

  if (empty($links)) { 
    return;
  }
  // Build groups section.
  if (!empty($groups)) {
    $block['content'] = array(
      '#type' => 'container',
      '#attributes' => array('class' => array('group-list')),
      'title' => array(
        '#type' => 'markup',
        '#markup' => 'Your Groups',
        '#weight' => -2,
        '#prefix' => '<h5>',
        '#suffix' => '</h5>'
      ),
      'group_list' => $links,
    );
  }
  return $block;
} 

/**
 * Build a group toolbar block.
 *
 * @return array
 *   A Drupal build array.
 */
function groups_feature_build_group_toolbar_block() {
  global $user;

  // Check if the current user is in the current group from context.
  $og_context = og_context();
  $entity_type = 'user';
  if (empty($og_context ) or !og_is_member($og_context ['group_type'], $og_context ['gid'], $entity_type, $user)) {
    return;
  }
  $block['og_context'] = $og_context ;

  // Create list of links for each node type that the user can add to the group. 
  
  // Get all entities that can be added to a group.
  $group_field_info = field_info_field(OG_AUDIENCE_FIELD);
  if (!empty($group_field_info)) {
    // Get links for all group bundles.
    $node_links = integration_build_node_links($group_field_info['bundles']['node'], $og_context ['gid']);
    // Build render array structure.
    $block = array();
    $block['content'] = array(
      '#type' => 'container',
      '#attributes' => array('class' => array('group-toolbar')),
      //'content' => array(
        //'#type' => 'markup',
        //'#markup' => t('Add content to this group:'),
        //'#weight' => 0,
      //),
      'add-content-button' => array(
        '#theme' => 'link',
        '#text' => 'Add Content',
        '#path' => '',
        '#options' => array(
          'attributes' => array('title' => 'Add Content', 'class' => array('add-content'), 'data-dropdown' => array('add-content-drop')),
          'html' => FALSE,
        ),
        '#weight' => 1,
      ),
      'add-content-list' => array(
        '#theme' => 'item_list',
        '#attributes' => array('id' => array('add-content-drop'), 'class' => array('f-dropdown')),
        '#weight' => 2,
        '#items' => $node_links,
      ),
    );
    return $block;
  }
}

