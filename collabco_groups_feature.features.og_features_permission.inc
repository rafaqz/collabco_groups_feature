<?php
/**
 * @file
 * collabco_groups_feature.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function collabco_groups_feature_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:group:add user'
  $permissions['node:group:add user'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:group:administer group'
  $permissions['node:group:administer group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:group:approve and deny subscription'
  $permissions['node:group:approve and deny subscription'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:group:create discussion content'
  $permissions['node:group:create discussion content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:create knowledge_object content'
  $permissions['node:group:create knowledge_object content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:delete any discussion content'
  $permissions['node:group:delete any discussion content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:delete any knowledge_object content'
  $permissions['node:group:delete any knowledge_object content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:delete own discussion content'
  $permissions['node:group:delete own discussion content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:delete own knowledge_object content'
  $permissions['node:group:delete own knowledge_object content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:manage members'
  $permissions['node:group:manage members'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:group:manage permissions'
  $permissions['node:group:manage permissions'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:group:manage roles'
  $permissions['node:group:manage roles'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:group:subscribe'
  $permissions['node:group:subscribe'] = array(
    'roles' => array(
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:group:subscribe without approval'
  $permissions['node:group:subscribe without approval'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:unsubscribe'
  $permissions['node:group:unsubscribe'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:group:update any discussion content'
  $permissions['node:group:update any discussion content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:update any knowledge_object content'
  $permissions['node:group:update any knowledge_object content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:update body field'
  $permissions['node:group:update body field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:update field_author_or_source field'
  $permissions['node:group:update field_author_or_source field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:update field_external_link field'
  $permissions['node:group:update field_external_link field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:update field_file_or_media field'
  $permissions['node:group:update field_file_or_media field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:update field_first_name field'
  $permissions['node:group:update field_first_name field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:update field_image field'
  $permissions['node:group:update field_image field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:update field_knowledge_object_image field'
  $permissions['node:group:update field_knowledge_object_image field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:update field_last_name field'
  $permissions['node:group:update field_last_name field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:update field_license field'
  $permissions['node:group:update field_license field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:update field_precinct field'
  $permissions['node:group:update field_precinct field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:update group'
  $permissions['node:group:update group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:group:update group_group field'
  $permissions['node:group:update group_group field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:group:update og_group_ref field'
  $permissions['node:group:update og_group_ref field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:update og_user_node field'
  $permissions['node:group:update og_user_node field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:update own discussion content'
  $permissions['node:group:update own discussion content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:update own knowledge_object content'
  $permissions['node:group:update own knowledge_object content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:view body field'
  $permissions['node:group:view body field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:view field_author_or_source field'
  $permissions['node:group:view field_author_or_source field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:view field_external_link field'
  $permissions['node:group:view field_external_link field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:view field_file_or_media field'
  $permissions['node:group:view field_file_or_media field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:view field_first_name field'
  $permissions['node:group:view field_first_name field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:view field_image field'
  $permissions['node:group:view field_image field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:view field_knowledge_object_image field'
  $permissions['node:group:view field_knowledge_object_image field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:view field_last_name field'
  $permissions['node:group:view field_last_name field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:view field_license field'
  $permissions['node:group:view field_license field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:view field_precinct field'
  $permissions['node:group:view field_precinct field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:view group_group field'
  $permissions['node:group:view group_group field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:group:view og_group_ref field'
  $permissions['node:group:view og_group_ref field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:view og_user_node field'
  $permissions['node:group:view og_user_node field'] = array(
    'roles' => array(),
  );

  return $permissions;
}
