<?php

/**
 * Implements hook_drush_load().
 *
 * In a drush contrib check if the frontend part (hosting_hook variant) is enabled.
 */
function provision_tasks_extra_drush_load() {
  return in_array('tasks_extra', drush_get_option('hosting_features', array()));
}

