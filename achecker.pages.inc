<?php

/**
 * @file
 * Contains functions that returns validation information.
 */

/**
 * Returns information about WCGA compliance of the node content.
 */
function achecker_view_compliance($node) {
  drupal_add_css(drupal_get_path('module', 'achecker') . '/style/achecker.css');
  $q = db_select('achecker_result', 'a')
      ->groupBy('vid');
  $q->addExpression('MAX(result_id)');
  $results = db_select('achecker_result', 'a')
    ->fields('a')
    ->condition('nid', $node->nid, '=')  
    ->condition('result_id', $q, 'IN')  
    ->orderBy('result_id', 'DESC')
    ->execute()
    ->fetchAll();
  $output = '';
  
  if ($results) {
    foreach ($results as $result) {

      $node_inf = db_select('node', 'n')
        ->fields('n')
        ->condition('nid', $node->nid, '=')
        ->execute()
        ->fetchAssoc();

      $revision = '';
      if ($node_inf['vid'] == $result->vid) {
        $revision = t('Current revision');
      }
      $probs = db_select('achecker_results', 'a')
        ->fields('a')
        ->condition('result_id', $result->result_id, '=')
        ->execute()
        ->fetchAll();
      
      $output .= theme('node_compliance_result', array(
        'nid' => $result->nid,
        'vid' => $result->vid,
        'status' => $result->status,
        'numOfErrors' => $result->numOfErrors,
        'numOfLikelyProbs' => $result->numOfLikelyProbs,
        'numOfPotProbs' => $result->numOfPotProbs,
        'guideline' => $result->guideline,
        'revision' => $revision,
        'problems' => $probs,
      ));
    }
  }
  else {
    $output .= theme('node_compliance_result');
  }
  return $output;
}

/**
 * Compliance report page
 */
function achecker_reports() {
  $q = db_select('achecker_result', 'a')
    ->groupBy('vid');
  $q->addExpression('MAX(result_id)');
  $results = db_select('achecker_result', 'a');
  $results->join('node', 'n', 'a.nid = n.nid');
  $results = $results->fields('a')
    ->fields('n', array('title'))
    ->condition('a.result_id', $q, 'IN') 
    ->orderBy('a.result_id', 'DESC')
    ->execute()
    ->fetchAll();
  $output = theme('compliance_report', array('results' => $results));
  
  return $output;
}
