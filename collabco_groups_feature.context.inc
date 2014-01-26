<?php
/**
 * @file
 * collabco_groups_feature.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function collabco_groups_feature_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'group';
  $context->description = 'group blocks that need more than the block page';
  $context->tag = 'groups feature';
  $context->conditions = array(
    'context' => array(
      'values' => array(
        '~integration' => '~integration',
      ),
    ),
    'context_og_condition_group_type' => array(
      'values' => array(
        '_any_' => '_any_',
      ),
      'options' => array(
        'node_form' => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-group_users-block' => array(
          'module' => 'views',
          'delta' => 'group_users-block',
          'region' => 'sidebar_second',
          'weight' => '-5',
        ),
        'views-subgroups-group_block' => array(
          'module' => 'views',
          'delta' => 'subgroups-group_block',
          'region' => 'sidebar_second',
          'weight' => '5',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('group blocks that need more than the block page');
  t('groups feature');
  $export['group'] = $context;

  return $export;
}
