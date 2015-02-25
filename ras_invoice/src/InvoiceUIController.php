<?php
namespace Drupal\ras_invoice;
class InvoiceUIController extends \EntityDefaultUIController {

  /**
   * Overrides hook_menu() defaults.
   */
  public function hook_menu() {
    $items = parent::hook_menu();
    $items[$this->path]['description'] = 'Manage invoices, including fields.';

    return $items;
  }

  /**
   * Overrides overviewTable to display the date for created_at in the overview table
   * @param array $conditions
   * @return array
   */
  public function overviewTable($conditions = array()) {

    $query = new \EntityFieldQuery();
    $query->entityCondition('entity_type', $this->entityType);

    // Add all conditions to query.
    foreach ($conditions as $key => $value) {
      $query->propertyCondition($key, $value);
    }

    if ($this->overviewPagerLimit) {
      $query->pager($this->overviewPagerLimit);
    }

    $results = $query->execute();

    $ids = isset($results[$this->entityType]) ? array_keys($results[$this->entityType]) : array();

    $entities = $ids ? entity_load($this->entityType, $ids) : array();

    ksort($entities);

    $rows = array();
    foreach ($entities as $entity) {
      // Added additional columns for $invoice->created_at
      $rows[] = $this->overviewTableRow($conditions, entity_id($this->entityType, $entity), $entity,
        array("Created at" => format_date($entity->created_at, 'short')));
    }

    $render = array(
      '#theme' => 'table',
      '#header' => $this->overviewTableHeaders($conditions, $rows, array("Created at")),
      '#rows' => $rows,
      '#empty' => t('None.'),
    );
    return $render;
  }
}
