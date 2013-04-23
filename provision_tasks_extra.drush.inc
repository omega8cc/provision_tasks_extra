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
    'description' => 'Flushes all caches on the site.',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH
  );
  $items['provision-rebuild_registry'] = array(
    'description' => 'Rebuilds the registry and flushes all caches on the site.',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH
  );
  $items['provision-run_cron'] = array(
    'description' => 'Runs cron on the site.',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH
  );
  $items['provision-update'] = array(
    'description' => dt('Run updates on a site'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH
  );
  $items['provision-flush_drush_cache'] = array(
    'description' => 'Flush the Drush cache on the server.',
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
 * Implements the provision-update command.
 */
function drush_provision_tasks_extra_provision_update() {
  drush_errors_on();
  provision_backend_invoke(d()->name, 'updatedb -d');
  drush_log(dt('Ran updates with debugging enabled'));
}

/**
 * Implements drush_hook_COMMAND_pre_validate().
 *
 * Make a backup of the site before we mess with it.
 */
function drush_provision_tasks_extra_provision_update_pre_validate() {
  $backup_file = d()->platform->server->backup_path . '/' . d()->uri . '-pre-update-' . date("Ymd.His", time()) . '.tar.gz';
  // Ensure a unique backup file is used.
  $count = 0;
  while (is_file($backup_file)) {
    $count++;
    $backup_file = d()->platform->server->backup_path . '/' . d()->uri . '-pre-update-' .  date('Ymd.His', time()) . '_' . $count . '.tar.gz';
  }
  drush_set_option('pre_update_backup_file', $backup_file);

  drush_set_option('force', true);
  $success = drush_invoke_process('@self', 'provision-backup', array($backup_file));
  if (!$success) {
    // If the backup failed, we don't want to try restoring it in the rollback.
    drush_set_option('pre_update_backup_file', FALSE);
  }
}

/**
 * Implements drush_hook_COMMAND_rollback().
 */
function drush_provision_tasks_extra_provision_update_rollback() {
  $restore_file = drush_get_option('pre_update_backup_file', FALSE);

  if ($restore_file) {
    drush_set_option('force', true);
    drush_invoke_process('@self', 'provision-restore', array($restore_file));
    drush_unset_option('force');
  }
}

/**
 * Implements the provision-flush_drush_cache command.
 */
function drush_provision_tasks_extra_provision_flush_drush_cache() {
  drush_errors_on();
  provision_backend_invoke(d()->name, 'cache-clear drush -d');
  drush_log(dt('Cleared the Drush cache cleared with debugging enabled'));
}


