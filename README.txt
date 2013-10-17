Provision tasks extra
=====================

This code extends Aegir's back-end with some additional commands.

Supported commands are:

- drush cache-clear
- drush cache-clear drush
- drush clean-modules (via site_health_check, requires http://drupal.org/project/clean_missing_modules)
- drush core-cron
- drush pm-updatestatus (via site_health_check, requires Drush 6)
- drush registry-rebuild
- drush security-review (via site_health_check, requires http://drupal.org/project/security_review)
- drush status-report (via site_health_check, requires Drush 5)
- drush updatedb
- drush updatedb-status (via site_health_check, requires Drush 6)

INSTALLATION
------------

This code is for provision, so it needs to be uploaded
in the ~/.drush/ directory of your Aegir backend.

You will need hosting_tasks_extra module uploaded
in the modules directory of the hostmaster platform
to be able to use this extension from the frontend:

http://drupal.org/project/hosting_tasks_extra

Requires registry_rebuild Drush extension uploaded
also in the ~/.drush/ directory of your Aegir backend.

http://drupal.org/project/registry_rebuild
