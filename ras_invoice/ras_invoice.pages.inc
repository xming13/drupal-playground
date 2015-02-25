<?php
/**
 * @file
 * Page callbacks for ras_invoice module.
 */

/**
 * Page callback for viewing invoice.
 */
function ras_invoice_view_invoice($invoice) {
  return 'This is an invoice - ID: ' . $invoice->invoice_id;
}

/**
 * Page callback for viewing invoice item.
 */
function ras_invoice_view_invoice_item($invoice_item) {
  return 'This is an invoice item - ID: ' . $invoice_item->invoice_item_id;
}

/**
 * Just provide some basic info for the entity administration page.
 * This can be expanded to add more information / a list of all created entites, etc.
 */
//function invoice_admin_page() {
//  $output = 'Welcome to the administration page for your Invoice Entities.<br/>';
//
//  $output .= '<a href="/invoice/add">Add invoice</a>';
//
//  return $output;
//}
//
///**
// * Page callback for add invoice
// */
//function invoice_add_invoice() {
//  $invoice = (object) array(
//  );
//
//  return drupal_get_form('invoice_add_form', $invoice);
//}
//
///**
// * Form callback for add invoice
// */
//function invoice_add_form($form, &$form_state, $invoice) {
//  $form['amount'] = array(
//    '#type' => 'textfield',
//    '#title' => 'Amount',
//    '#required' => TRUE,
//  );
//
//  field_attach_form('invoice', $invoice, $form, $form_state);
//
//  $form['submit'] = array(
//    '#type' => 'submit',
//    '#value' => t('Save'),
//  );
//
//  return $form;
//}
//
///**
// * Form callback: Validates invoice_add form.
// * We pass things straight through to the Field API to handle validation
// * of the attached fields.
// */
//function invoice_add_form_validate($form, &$form_state) {
//  $invoice_submission = (object) $form_state['values'];
//  field_attach_form_validate('invoice', $invoice_submission, $form, $form_state);
//}
//
///**
// * Form callback: submits invoice_add_form information
// */
//function invoice_add_form_submit($form, &$form_state) {
//  $invoice_submission = (object) $form_state['values'];
//  field_attach_submit('invoice', $invoice_submission, $form, $form_state);
//
//  $invoice_submission->author_uid = 1;
//  $invoice_submission->client_uid = 1;
//  $invoice_submission->created_at = REQUEST_TIME;
//  $invoice_submission->updated_at = REQUEST_TIME;
//  $invoice_submission->status = 0;
//
//  dpm($invoice_submission, '$invoice_submission');
//  $invoice = invoice_save($invoice_submission);
//  $form_state['redirect'] = 'invoice/' . $invoice->invoice_id;
//}
//



///**
// * Page callback for edit invoice
// */
//function invoice_edit_invoice($invoice) {
//  return drupal_get_form('invoice_edit_form', array($invoice));
//}
//
///**
// * Form callback for edit invoice
// */
//function invoice_edit_form($invoice) {
//  $form['amount'] = array(
//    '#type' => 'textfield',
//    '#title' => 'Amount',
//    '#required' => TRUE,
//  );
//
//  field_attach_form('invoice', $invoice, $form, $form_state);
//
//  $form['submit'] = array(
//    '#type' => 'submit',
//    '#value' => t('Save'),
//  );
//
//  return $form;
//}
//
///**
// * Page callback for delete invoice
// */
//function invoice_delete_invoice($invoice) {
//  $form = array();
//
//  return confirm_form($form,
//    'Are you sure you want to delete this invoice?',
//    invoice_uri($invoice),
//    'This action cannot be undone.',
//    'Yes',
//    'Cancel',
//    'confirm'
//  );
//}