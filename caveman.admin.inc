<?php
/**
 * @file
 * Admin settings form for Caveman filter.
 */

function caveman_admin_settings($form, &$form_state) {
  $form['caveman_override'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable Caveman filter'),
    '#default_value' => (bool) config_get('caveman.settings', 'caveman_override'),
    '#description' => t('Me turn caveman talk on site-wide. On April 1, filter still go even if this off.'),
  );
  $form['actions']['#type'] = 'actions';
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
  );
  return $form;
}

function caveman_admin_settings_submit($form, &$form_state) {
  $config = config('caveman.settings');
  $config->set('caveman_override', (bool) $form_state['values']['caveman_override']);
  $config->save();

  backdrop_set_message(t('Settings saved.'));
}
