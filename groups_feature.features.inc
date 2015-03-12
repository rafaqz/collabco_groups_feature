<?php
/**
 * @file
 * groups_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function groups_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function groups_feature_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function groups_feature_node_info() {
  $items = array(
    'private_group' => array(
      'name' => t('Private Group'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'group' => array(
      'name' => t('Group'),
      'base' => 'node_content',
      'description' => t('Basic group.'),
      'has_title' => '1',
      'title_label' => t('Group Name'),
      'help' => '',
    ),
  );
  return $items;
}