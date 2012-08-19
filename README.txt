Provision tasks extra
=====================

This code extends Aegir back-end with some additional commands.

Supported commands are:

- drush cache-clear -d
- drush registry-rebuild -d
- drush core-cron -d

Code: https://github.com/omega8cc/provision_tasks_extra


INSTALL
=================
This code is for provision, so it needs to be uploaded
in the ~/.drush/ directory of your Aegir backend.

You will need hosting_tasks_extra module uploaded
in the modules directory of the hostmaster platform
to be able to use this extension:

https://github.com/omega8cc/hosting_tasks_extra

Requires registry-rebuild Drush extension uploaded
also in the ~/.drush/ directory of your Aegir backend.

http://drupal.org/project/registry_rebuild

