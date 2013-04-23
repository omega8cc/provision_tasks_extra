Provision tasks extra
=====================

This code extends Aegir's back-end with some additional commands.

Supported commands are:

- drush cache-clear -d
- drush registry-rebuild -d
- drush core-cron -d
- drush updatedb -d
- drush cache-clear drush -d

INSTALLATION
------------

This code is for provision, so it needs to be uploaded
in the ~/.drush/ directory of your Aegir backend.

You will need hosting_tasks_extra module uploaded
in the modules directory of the hostmaster platform
to be able to use this extension from the frontend:

http://drupal.org/project/hosting_tasks_extra

Requires registry-rebuild Drush extension uploaded
also in the ~/.drush/ directory of your Aegir backend.

http://drupal.org/project/registry_rebuild

