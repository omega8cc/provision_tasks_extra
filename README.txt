Hosting tasks extra
=====================

This module extends Aegit hostmaster (and drush/provision)
with some additional tasks.

Supported commands are:

- drush cache-clear -d
- drush registry-rebuild -d
- drush core-cron -d


INSTALL
=================

As it has code for both hostmaster and drush it needs to be in both
a modules directory of the hostmaster site and a directory where
drush looks e.g. ~/.drush/.

The module can be placed in both directories or symlinked.

Registry-rebuild required the equally named drush module,
installable with e.g. drush dl registry-rebuild.
