<?php
namespace Drupal\ras_invoice;
class InvoiceItemUIController extends \EntityDefaultUIController {

  /**
   * Overrides hook_menu() defaults.
   */
  public function hook_menu() {
    $items = parent::hook_menu();
    $items[$this->path]['description'] = 'Manage invoice items, including fields.';

    return $items;
  }
}
