<?php
/**
 * @file
 * Admin settings form for Caveman filter.
 */

function caveman_admin_settings($form, &$form_state) {
  $form['caveman_override'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable Caveman filter'),
    '#default_value' => config_get('caveman.grunt', 'caveman_override'),
    '#description' => t('Enable caveman-speak site-wide. When off, only activates on April 1st.'),
  );
  $form['actions']['#type'] = 'actions';
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
  );
  return $form;
}

function caveman_admin_settings_submit($form, &$form_state) {
  $config = config('caveman.grunt');
  $config->set('caveman_override', (bool) $form_state['values']['caveman_override']);
  $config->save();
  backdrop_set_message(t('Settings saved.'));
}
