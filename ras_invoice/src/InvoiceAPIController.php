<?php

namespace Drupal\ras_invoice;
class InvoiceAPIController extends \EntityAPIController {

  public function save($invoice, \DatabaseTransaction $transaction = NULL) {
    if (isset($invoice->is_new)) {
      $invoice->created_at = REQUEST_TIME;
      $invoice->invoice_items = array();
    }
    $invoice->updated_at = REQUEST_TIME;

    return parent::save($invoice, $transaction);
  }

  public function load($ids = array(), $conditions = array()) {
    $invoices = parent::load($ids, $conditions);

    $result = db_select('invoice_item', 'i')
      ->fields('i')
      ->condition('invoice_id', array_keys($invoices), 'IN')
      ->execute()
      ->fetchAllAssoc('invoice_item_id');

    foreach ($result as $invoice_item) {
      // get the parent of the $invoice_item
      $invoice = $invoices[$invoice_item->invoice_id];

      // create a children array if it does not exist
      if (!isset($invoice->invoice_items)) {
        $invoice->invoice_items = array();
      }

      // assign $invoice_item to the children
      $invoice->invoice_items[$invoice_item->invoice_item_id] = $invoice_item;
    }

    return $invoices;
  }
}