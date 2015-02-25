<?php

/**
 * Form callback for adding / editing an invoice entity.
 */
function invoice_form($form, &$form_state, $invoice = NULL) {

  $form['author_uid'] = array(
    '#title' => t('Author UID'),
    '#type' => 'textfield',
    '#default_value' => isset($invoice->author_uid) ? $invoice->author_uid : '',
    '#description' => t('Author UID of the invoice.'),
    '#required' => TRUE,
  );
  $form['client_uid'] = array(
    '#title' => t('Client UID'),
    '#type' => 'textfield',
    '#default_value' => isset($invoice->client_uid) ? $invoice->client_uid : '',
    '#description' => t('Client UID of the invoice.'),
    '#required' => TRUE,
  );
  $form['status'] = array(
    '#title' => t('Status'),
    '#type' => 'textfield',
    '#default_value' => isset($invoice->status) ? $invoice->status : '',
    '#description' => t('Status of the invoice.'),
    '#required' => TRUE,
  );

  $form['actions'] = array(
    '#type' => 'actions',
    'submit' => array(
      '#type' => 'submit',
      '#value' => isset($invoice->invoice_id) ? t('Update Invoice') : t('Save Invoice'),
    ),
    'send' => array(
      '#type' => 'submit',
      '#value' => 'Send',
      '#submit' => array('invoice_form_send'),
    )
  );
  // field_attach_form('invoice', $invoice, $form, $form_state);
  return $form;
}

/**
 * Submit callback for invoice entity form.
 */
function invoice_form_submit($form, &$form_state) {
  $invoice = entity_ui_form_submit_build_entity($form, $form_state);
  $invoice->save();
  drupal_set_message(t('Invoice has been saved.'));
  $form_state['redirect'] = 'admin/structure/invoice';
}

/**
 * Submit callback for the send button for invoice form.
 */
function invoice_form_send(&$form, &$form_state) {
  $invoice = entity_ui_form_submit_build_entity($form, $form_state);

  $to = 'weiseng@redairship.com';
  $from = 'drupal.local@test.com';

  $subject = 'This is a new invoice';
  $body = 'An invoice created at ' . $invoice->created_at;

  $params = array(
    'subject' => $subject,
    'body' => $body,
  );

  drupal_mail('ras_invoice', 'send', $to, language_default(), $params, $from);
  drupal_set_message('Email sent successfully!');
}

/**
 * Form callback for adding / editing an invoice item entity
 */
function invoice_item_form($form, &$form_state, $invoice_item = NULL) {

  $form['description'] = array(
    '#title' => t('Description'),
    '#type' => 'textfield',
    '#default_value' => isset($invoice_item->description) ? $invoice_item->description : '',
    '#description' => t('Description of the invoice item.'),
    '#required' => TRUE,
  );
  $form['amount'] = array(
    '#title' => t('Amount'),
    '#type' => 'textfield',
    '#default_value' => isset($invoice_item->amount) ? $invoice_item->amount : '',
    '#description' => t('Amount of the invoice item.'),
    '#required' => TRUE,
  );
  $form['price'] = array(
    '#title' => t('Price'),
    '#type' => 'textfield',
    '#default_value' => isset($invoice_item->price) ? $invoice_item->price : '',
    '#description' => t('Price of the invoice item.'),
    '#required' => TRUE,
  );
  $form['invoice_id'] = array(
    '#title' => t('Invoice ID'),
    '#type' => 'textfield',
    '#default_value' => isset($invoice_item->invoice_id) ? $invoice_item->invoice_id : '',
    '#description' => t('Invoice ID of the invoice item.'),
    '#required' => TRUE,
  );

  $form['actions'] = array(
    '#type' => 'actions',
    'submit' => array(
      '#type' => 'submit',
      '#value' => isset($invoice_item->invoice_item_id) ? t('Update Invoice Item') : t('Save Invoice Item'),
    ),
  );

  return $form;
}

/**
 * Submit callback for invoice item entity form
 */
function invoice_item_form_submit($form, &$form_state) {
  $invoice_item = entity_ui_form_submit_build_entity($form, $form_state);
  $invoice_item->save();
  drupal_set_message(t('Invoice item has been saved.'));
  $form_state['redirect'] = 'admin/structure/invoice-item';
}