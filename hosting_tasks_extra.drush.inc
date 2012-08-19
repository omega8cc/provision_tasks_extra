<?php

/**
 * @file
 * Provision/Drush hooks for the hosting_tasks_extra module.
 *
 * These are the hooks that will be executed by the drush_invoke function.
 */

/**
 * Implementation of hook_drush_command().
 */
function hosting_tasks_extra_drush_command() {
  $items['provision-flush_cache'] = array(
    'description' => 'Flushes all caches on the site.',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH
  );
  $items['provision-rebuild_registry'] = array(
    'description' => 'Rebuilds the registry and flushes all caches on the site.',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH
  );

  return $items;
}

/**
 * Implements the provision-flush_cache command.
 */
function drush_hosting_tasks_extra_provision_flush_cache() {
  $site_path = d()->site_path;
  drush_shell_cd_and_exec($site_path, 'drush cache-clear all -d');
  drush_log(dt('All caches cleared with debugging enabled'));
}

/**
 * Implements the provision-rebuild_registry command.
 */
function drush_hosting_tasks_extra_provision_rebuild_registry() {
  $site_path = d()->site_path;
  drush_shell_cd_and_exec($site_path, 'drush registry-rebuild -d');
  drush_log(dt('Rebuilt registry and caches cleared with debugging enabled'));
}

