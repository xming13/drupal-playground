<?php

/**
 * @file
 * Rules example module to create custom actions, events, and conditions
 */

/**
 * Implements hook_rules_event_info().
 */
function rules_example_rules_event_info() {
  $events = array(
    'rules_example_event_something_happen' => array(
      'label' => t('Something happens!'),
      'group' => t('Rules Example'),
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
        'name' => array(
          'label' => t('Something\'s name'),
          'type' => 'text',
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
function rules_example_condition_name_compare($name) {
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
  $data = array(

  );

  return $data;
}