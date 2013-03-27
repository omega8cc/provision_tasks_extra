<?php

/**
 * @file
 * Provision/Drush hooks for the provision_tasks_extra module.
 *
 * These are the hooks that will be executed by the drush_invoke function.
 */

/**
 * Implementation of hook_drush_command().
 */
function provision_tasks_extra_drush_command() {
  $items['provision-flush_cache'] = array(
    'description' => 'Flushes all caches.',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH
  );
  $items['provision-rebuild_registry'] = array(
    'description' => 'Rebuilds the registry and flushes all caches.',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH
  );
  $items['provision-run_cron'] = array(
    'description' => 'Runs standard cron.',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH
  );
  $items['provision-delete_rebuild_registry'] = array(
    'description' => 'Truncates and re-creates registry tables.',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH
  );

  return $items;
}

/**
 * Implements the provision-flush_cache command.
 */
function drush_provision_tasks_extra_provision_flush_cache() {
  drush_errors_on();
  provision_backend_invoke(d()->name, 'cache-clear all -d');
  drush_log(dt('All caches cleared with debugging enabled'));
}

/**
 * Implements the provision-rebuild_registry command.
 */
function drush_provision_tasks_extra_provision_rebuild_registry() {
  drush_errors_on();
  provision_backend_invoke(d()->name, 'registry-rebuild -d');
  drush_log(dt('Rebuilt registry and caches cleared with debugging enabled'));
}

/**
 * Implements the provision-run_cron command.
 */
function drush_provision_tasks_extra_provision_run_cron() {
  drush_errors_on();
  provision_backend_invoke(d()->name, 'core-cron -d');
  drush_log(dt('Cron run with debugging enabled'));
}

/**
 * Implements the provision-delete_rebuild_registry command.
 */
function drush_provision_tasks_extra_provision_delete_rebuild_registry() {
  drush_errors_on();
  if (d()->type === 'site') {
    if (drush_drupal_major_version(d()->root) == 7) {
      provision_backend_invoke(d()->name, 'registry-rebuild --fire-bazooka -d');
      drush_log(dt('Registry and registry_file tables rebuilt from scratch'));
    }
    else {
      $platform_root = d()->root;
      drush_log(dt("This drush registry-rebuild --fire-bazooka -d task works only for Drupal 7 sites"), 'warning');
    }
  }
}
