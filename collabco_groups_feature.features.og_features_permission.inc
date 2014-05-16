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

  // Exported og permission: 'node:private_group:add user'
  $permissions['node:private_group:add user'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:private_group:administer group'
  $permissions['node:private_group:administer group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:private_group:approve and deny subscription'
  $permissions['node:private_group:approve and deny subscription'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:private_group:create basic_page content'
  $permissions['node:private_group:create basic_page content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:private_group:create private_group content'
  $permissions['node:private_group:create private_group content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:private_group:create group content'
  $permissions['node:private_group:create group content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:private_group:delete any basic_page content'
  $permissions['node:private_group:delete any basic_page content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:private_group:delete any private_group content'
  $permissions['node:private_group:delete any private_group content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:private_group:delete any group content'
  $permissions['node:private_group:delete any group content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:private_group:delete own basic_page content'
  $permissions['node:private_group:delete own basic_page content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:private_group:delete own private_group content'
  $permissions['node:private_group:delete own private_group content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:private_group:delete own group content'
  $permissions['node:private_group:delete own group content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:private_group:manage members'
  $permissions['node:private_group:manage members'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:private_group:manage permissions'
  $permissions['node:private_group:manage permissions'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:private_group:manage roles'
  $permissions['node:private_group:manage roles'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:private_group:subscribe'
  $permissions['node:private_group:subscribe'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:private_group:subscribe without approval'
  $permissions['node:private_group:subscribe without approval'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:private_group:unsubscribe'
  $permissions['node:private_group:unsubscribe'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:private_group:update any basic_page content'
  $permissions['node:private_group:update any basic_page content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:private_group:update any private_group content'
  $permissions['node:private_group:update any private_group content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:private_group:update any group content'
  $permissions['node:private_group:update any group content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:private_group:update body field'
  $permissions['node:private_group:update body field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:private_group:update field_first_name field'
  $permissions['node:private_group:update field_first_name field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:private_group:update field_last_name field'
  $permissions['node:private_group:update field_last_name field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:private_group:update group'
  $permissions['node:private_group:update group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:private_group:update group_access field'
  $permissions['node:private_group:update group_access field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:private_group:update group_group field'
  $permissions['node:private_group:update group_group field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:private_group:update og_group_ref field'
  $permissions['node:private_group:update og_group_ref field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:private_group:update og_user_node field'
  $permissions['node:private_group:update og_user_node field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:private_group:update own basic_page content'
  $permissions['node:private_group:update own basic_page content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:private_group:update own private_group content'
  $permissions['node:private_group:update own private_group content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:private_group:update own group content'
  $permissions['node:private_group:update own group content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:private_group:view body field'
  $permissions['node:private_group:view body field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:private_group:view field_first_name field'
  $permissions['node:private_group:view field_first_name field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:private_group:view field_last_name field'
  $permissions['node:private_group:view field_last_name field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:private_group:view group_access field'
  $permissions['node:private_group:view group_access field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:private_group:view group_group field'
  $permissions['node:private_group:view group_group field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:private_group:view og_group_ref field'
  $permissions['node:private_group:view og_group_ref field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:private_group:view og_user_node field'
  $permissions['node:private_group:view og_user_node field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

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

  // Exported og permission: 'node:group:create basic_page content'
  $permissions['node:group:create basic_page content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:group:create private_group content'
  $permissions['node:group:create private_group content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:group:create group content'
  $permissions['node:group:create group content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:group:delete any basic_page content'
  $permissions['node:group:delete any basic_page content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:group:delete any private_group content'
  $permissions['node:group:delete any private_group content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:group:delete any group content'
  $permissions['node:group:delete any group content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:group:delete own basic_page content'
  $permissions['node:group:delete own basic_page content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:group:delete own private_group content'
  $permissions['node:group:delete own private_group content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:group:delete own group content'
  $permissions['node:group:delete own group content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
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
    'roles' => array(
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:group:unsubscribe'
  $permissions['node:group:unsubscribe'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:group:update any basic_page content'
  $permissions['node:group:update any basic_page content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:group:update any private_group content'
  $permissions['node:group:update any private_group content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:group:update any group content'
  $permissions['node:group:update any group content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:group:update body field'
  $permissions['node:group:update body field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:group:update field_first_name field'
  $permissions['node:group:update field_first_name field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:group:update field_last_name field'
  $permissions['node:group:update field_last_name field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:group:update group'
  $permissions['node:group:update group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:group:update group_access field'
  $permissions['node:group:update group_access field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:group:update group_group field'
  $permissions['node:group:update group_group field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:group:update og_group_ref field'
  $permissions['node:group:update og_group_ref field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:group:update og_user_node field'
  $permissions['node:group:update og_user_node field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:group:update own basic_page content'
  $permissions['node:group:update own basic_page content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:group:update own private_group content'
  $permissions['node:group:update own private_group content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:group:update own group content'
  $permissions['node:group:update own group content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:group:view body field'
  $permissions['node:group:view body field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:group:view field_first_name field'
  $permissions['node:group:view field_first_name field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:group:view field_last_name field'
  $permissions['node:group:view field_last_name field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:group:view group_access field'
  $permissions['node:group:view group_access field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
      'non-member' => 'non-member',
    ),
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
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:group:view og_user_node field'
  $permissions['node:group:view og_user_node field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  return $permissions;
}
