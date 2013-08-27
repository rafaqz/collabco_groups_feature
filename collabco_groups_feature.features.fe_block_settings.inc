<?php
/**
 * @file
 * collabco_groups_feature.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function collabco_groups_feature_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views-28d52582802129a1e43189419c41eb29'] = array(
    'cache' => -1,
    'css_class' => 'iin-join-conversation-block',
    'custom' => 0,
    'delta' => '28d52582802129a1e43189419c41eb29',
    'module' => 'views',
    'node_types' => array(
      0 => 'closed_group',
    ),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'openhub' => array(
        'region' => 'content_lower',
        'status' => 1,
        'theme' => 'openhub',
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
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'openhub' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'openhub',
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

  return $export;
}
