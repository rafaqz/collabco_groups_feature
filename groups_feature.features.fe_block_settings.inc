<?php
/**
 * @file
 * groups_feature.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function groups_feature_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['groups_feature-group_toolbar'] = array(
    'cache' => 1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'group_toolbar',
    'module' => 'groups_feature',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'custom_zurb' => array(
        'region' => 'sidebar_second',
        'status' => 1,
        'theme' => 'custom_zurb',
        'weight' => -32,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['groups_feature-user_groups_list'] = array(
    'cache' => 1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'user_groups_list',
    'module' => 'groups_feature',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'custom_zurb' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'custom_zurb',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-group_users-block'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'group_users-block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'node/*/edit
user/*/edit',
    'roles' => array(
      'authenticated user' => 2,
    ),
    'themes' => array(
      'custom_zurb' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'custom_zurb',
        'weight' => -30,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => 'Members',
    'visibility' => 0,
  );

  $export['views-subgroups-group_block'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'subgroups-group_block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'custom_zurb' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'custom_zurb',
        'weight' => 5,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
