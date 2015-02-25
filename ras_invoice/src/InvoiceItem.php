<?php
/**
 * Class InvoiceItem
 */
namespace Drupal\ras_invoice;
class InvoiceItem extends \Entity {
  protected function defaultUri() {
    return array('path' => 'invoice-item/' . $this->identifier());
  }
} 