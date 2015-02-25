<?php
/**
 * Class Invoice
 */
namespace Drupal\ras_invoice;
class Invoice extends \Entity {
  protected function defaultUri() {
    return array('path' => 'invoice/' . $this->identifier());
  }
}