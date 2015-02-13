<?php

/**
 * @file
 * Rules example module to create custom events, conditions and actions
 */

/**
 * Implements hook_rules_event_info().
 */
function rules_example_rules_event_info() {
  $events = array(
    'rules_example_event_something_happen' => array(
      'label' => t('Something happens!'),
      'group' => t('Rules Example'),
      'variables' => array(
        'user' => array(
          'type' => 'user',
          'label' => t('The user when something happens'),
        ),
        'name' => array(
          'type' => 'text',
          'label' => t('Name of something'),
        ),
      ),
    ),
  );

  return $events;
}

/**
 * Implements hook_rules_condition_info().
 */
function rules_example_rules_condition_info() {
  $conditions = array(
    'rules_example_condition_name_compare' => array(
      'label' => t('Something\'s name to compare'),
      'parameter' => array(
        'user' => array(
          'type' => 'user',
          'label' => t('The user when something happens'),
        ),
        'name' => array(
          'type' => 'text',
          'label' => t('Name of something'),
        ),
      ),
      'group' => t('Rules Example'),
    ),
  );

  return $conditions;
}

/**
 * The condition function for rules_example_condition_name_compare
 */
function rules_example_condition_name_compare($user, $name) {
  return $name == 'something';
}

/**
 * Implements hook_rules_action_info().
 */
function rules_example_rules_action_info() {
  $actions = array(
    'rules_example_action_hello_world' => array(
      'label' => t('Print Hello World on the page'),
      'group' => t('Rules Example'),
    ),
    'rules_example_action_hello_user' => array(
      'label' => t('Print Hello to the logged in user'),
      'group' => t('Rules Example'),
      'parameter' => array(
        'account_to' => array(
          'type' => 'user',
          'label' => t('User to say hello to'),
        ),
        'account_from' => array(
          'type' => 'user',
          'label' => t('User who says hello'),
        ),
      ),
    ),
  );

  return $actions;
}

/**
 * The action function for rules_example_action_hello_world
 */
function rules_example_action_hello_world() {
  drupal_set_message(t('Hello World'));
}

/**
 * The action function for rules_example_action_hello_user
 */
function rules_example_action_hello_user($account_to, $account_from) {
  drupal_set_message(t('Hello @username_to from @username_from',
    array(
      '@username_to' => $account_to->name,
      '@username_from' => $account_from->name
    )
  ));
}

/**
 * Implements hook_rules_data_info().
 */
function rules_example_rules_data_info() {

  // When we configure action, the data selection tool must know the data type.
  // E.g. if the variable is user, it must know the structure of user object
  // - user.id, user.name..., so here is where we provide the definition of
  // the custom data structure or data type.
  $data = array(
    'rules_example_view' => array(
      'label' => t('view object'),
      'wrap' => TRUE,
      'property info' => array(
        'machine_name' => array(
          'type' => 'text',
          'label' => t('Machine name'),
        ),
        'args' => array(
          'type' => 'list<text>',
          'label' => t('Arguments'),
          'setter callback' => 'entity_property_verbatim_set'
        ),
      ),
    ),
  );

  return $data;
}