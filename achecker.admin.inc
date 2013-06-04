<?php

/**
 * @file
 * Contains module configuration form.
 */

/**
 * AChecker module configuration form.
 */
function achecker_admin_settings() {
  $validation = variable_get('achecker_enable_validation', 0);
  $validation = $validation ? t('<em>enabled</em>. Uncheck the checkbox below to disable it.') : t('<em>disabled</em>. Check the checkbox below to enable it.');
  $form['achecker_status'] = array(
    '#type' => 'markup',
    '#prefix' => '<h5>',
    '#suffix' => '</h5>',
    '#markup' => t('Currently compliance validation is') . ' ' . $validation,
  );
  $form['achecker_enable_validation'] = array(
    '#type' => 'checkbox',
    '#default_value' => variable_get('achecker_enable_validation', 0),
    '#title' => t('Enable compliance validation'),
  );
  
  $form['achecker_session_id'] = array(
    '#type' => 'textfield',
    '#title' => t('AChecker session ID'),
    '#description' => t('This will set the unique session ID which you can get after registration on !achecker', array(
      '!acheker' => l(t('AChecker web service site'), 'http://achecker.ca/checker/index.php'))
    ),
    '#default_value' => variable_get('achecker_session_id', ''),
    '#required' => TRUE,
  );
  $form['achecker_compliance_standard'] = array(
    '#type' => 'radios',
    '#title' => t('AChecker compliance standard'),
    '#description' => t('Choose compliance standard'),
    '#options' => drupal_map_assoc(array(t('BITV1'), t('508'), t('STANCA'), t('WCAG1-A'), t('WCAG1-AA'), t('WCAG1-AAA'), t('WCAG2-A'), t('WCAG2-AA'), t('WCAG2-AAA'))),
    '#default_value' => variable_get('achecker_compliance_standard', 'WCAG2-AA'),
    '#required' => TRUE,
  );
  $form['achecker_fields'] = array(
    '#type' => 'textfield',
    '#title' => t('Fields'),
    '#description' => t('Please input here space separated machine names of textarea fields to validate'),
    '#default_value' => variable_get('achecker_fields', NULL),
  );
    
  return system_settings_form($form);
}
