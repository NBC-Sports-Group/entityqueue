<?php

/**
 * @file
 * Contains theme implementations for the Draggable Table module.
 */

/**
 * Themes the subqueue items as a dragtable.
 */
function theme_entityqueue_dragtable($variables) {
  $form = $variables['form'];

  $output = '';
  $rows = array();
  $table_id = $form['#attributes']['id'];
  drupal_add_tabledrag($table_id, 'order', 'sibling', 'item-weight');
  foreach (element_children($form) as $key) {
    if (isset($form[$key]['label'])) {
      $row = array();

      $row[] = drupal_render($form[$key]['label']);
      $row[] = drupal_render($form[$key]['actions']);
      $row[] = drupal_render($form[$key]['weight']);

      $rows[] = array(
        'data' => $row,
        'class' => array('draggable')
      );
    }
  }

  if (empty($rows)) {
    $rows[] = array(array('data' => t('No items.'), 'colspan' => 3));
  }
  $header = array(
    t('Label'),
    t('Actions'),
    t('Weight'),
  );
  $output .= theme('table', array(
    'header' => $header,
    'rows' => $rows,
    'attributes' => array(
      'id' => $table_id,
      'class' => $form['#attributes']['class'],
    ),
  ));

  return $output;
}
