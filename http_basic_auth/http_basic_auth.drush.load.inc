<?php

/**
 * Implements hook_drush_load().
 *
 * In a drush contrib check if the frontend part (hosting_hook variant) is enabled.
 */
function http_basic_auth_drush_load() {
  return in_array('http_basic_auth', drush_get_option('hosting_features', array()));
}

