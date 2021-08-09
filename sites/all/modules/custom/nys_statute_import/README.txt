NYS Statute Import Module

GUI Monitor and Reports
The module creates a Statute Status command in the Admin Reports Menu
  Statute Status -
      Statute Status                   - A Monitor of the progress of a running import or report on a finished job.
      NYS Extra Pages                  - Pages on NYS not in open leg.
      NYS Missing Pages                - Pages in open leg not in NYS by statute id
      law_id & location_id not found   - Pages in open leg not in NYS by law_id and location_id
      Duplicate statute_id             - Duplicate / Multiplicate statute_ids
      Duplicate law_id & location_id   - Duplicate / Multiplicate law_id & location_id

These reports are also available in the Audit Report drug command.

All the reports except for the Statutes Report require a complete update-all-statutes or
audit audit-all-statutes run to populate the nys_statute_import_log table.
This table gets updated when single law_ids are updated.

The Clearing a Range of Statutes drush command populate the nys_statute_import_law_queue
table with the law_ids that have structural changes. The table is used to store
the law_ids to be deleted. It is available for use by the structure-update-range-statutes
drush command at some point after the structure-clear-range-statutes command has been run.



Drush Commands                             Command Description

update-all-statutes                        Importing or Updating All Statutes
restart-update-all-statutes
audit-all-statutes                         Auditing of All Statutes
restart-audit-all-statutes
statutes-report                            Statutes Report
audit-report                               Audit Report
update-range-statutes                      Updating a Range of Statutes
structure-clear-range-statutes             Clearing a Range of Statutes
structure-update-range-statutes            Updating a Cleared Range of Statutes
repeal-range-statutes                      Repealing a Range of Statutes
                                           Info and Utility Commands
stop-statute-processing                    Stopping a Running Job
reset-statute-processing                   Resetting and preparing for a new run.
status-all-statutes			   Real time monitor of a live run or status of the the last run.

====================================================================================================
Importing or Updating All Statutes
====================================================================================================
These commands Import or Update statutes.
If a statute is not in the system it gets imported.
If a statute has already been imported previously it gets compared to the open leg data.
If the node matches the open leg data it is left alone.
If the node does not match the open leg data it gets updated.

+-------------------------------------------------+
| IMPORT OR UPDATE ALL STATUTES THAT HAVE CHANGED |
+-------------------------------------------------+

Drush Command:                      update-all-statutes                         Import or Update Statute Nodes.

Alias:                              uas

Argument:                           lawID-locationID
                                    An optional lawID or a lawID-locationID

Option:
                                     --force                                    Forces a clear of previous data.

Examples:
Standard example                    drush update-all-statutes                   Process All Statute Nodes.
lawID example                       drush update-all-statutes ABP               Process All ABP Statute Nodes.
lawID-locationID example            drush update-all-statutes ABP-215           Process the ABP-215 Statute Node.


+----------------------------------------------------------------+
| RESTART AN IMPORT OR UPDATE ALL STATUTES THAT HAVE CHANGED RUN |
+----------------------------------------------------------------+

Drush Command:                      restart-update-all-statutes                 Restart Import or Update Statute Nodes after a failure.

Alias:                              ruas

Argument:                           lawID                                       An optional lawID where processing starts
                                                                                With no argument the date from the last run is used as the starting point.

Examples:
Standard example                    drush restart-update-all-statutes           Process All Statute Nodes restarting at the failure point.
lawID example                       drush restart-update-all-statutes ABP       Process All Statute Nodes starting with ABP.

Note:                                                                           The restart- command with no argumentss gets the starting point from the
                                                                                nys_statute_import_process_statutes drupal variable.
                                                                                You can use drush vget nys_statute_import_process_statutes to view the value.



====================================================================================================
Auditing of All Statutes                                                                           |
====================================================================================================
These commands create an audit report of statutes.
Data is returned in a csv format and can be opened in a spredsheet application if desired.


+--------------------+
| AUDIT ALL STATUTES |
+--------------------+

Drush Command:                      audit-all-statutes				Audit All Statutes.

Alias:                              aas

Argument:                           lawID-locationID
                                    An optional lawID or a lawID-locationID

Examples:
Standard example                    drush audit-all-statutes                    Process All Statute Nodes.
lawID example                       drush audit-all-statutes ABP                Process All ABP Statute Nodes.
lawID-locationID example            drush audit-all-statutes ABP-215            Process the ABP-215 Statute Node.

+-----------------------------------+
| RESTART AN AUDIT ALL STATUTES RUN |
+-----------------------------------+

Drush Command:                      restart-audit-all-statutes                  Restart Import or Forced Update Statute Nodes after a failure.

Alias:                              raas

Argument:                           lawID                                       An optional lawID where processing starts
                                                                                With no argument the date from the last run is used as the starting point.

Examples:
Standard example                    drush restart-audit-all-statutes            Process All Statute Nodes restarting at the failure point.
lawID example                       drush restart-audit-all-statutes ABP		Process All Statute Nodes starting with ABP.

Note:                                                                           The restart- command with no argumentss gets the starting point from the
                                                                                nys_statute_import_process_statutes drupal variable.
                                                                                You can use drush vget nys_statute_import_process_statutes to view the value.


====================================================================================================
Statutes Report                                                                                    |
====================================================================================================
This command generates a report which compares the number of statutes in openleg with drupal.
If a law_id is specified the report will only be run for that single law_id.

Run
Drush Command:                      	   statutes-report


Examples:
 Standard example                          drush statutes-report
 lawID example                             drush statutes-report ABP

Arguments:
 arg1                                      An optional lawID argument for
                                           single law_id

====================================================================================================
Audit Report                                                                                    |
====================================================================================================
This command generates a series of reports
Choose the report you want to run from the menu.
Pass in the report number as an argument if desired.

Run
Drush Command:                      	   audit-report


Examples:
 Standard example                          drush audit-report
 lawID example                             drush audit-report 2

Arguments:
 arg1                                      An optional report number.

====================================================================================================
Updating a Range of Statutes
====================================================================================================
structure-update-range-statutes


This commands Update statutes.
If no argument is supplied the last run date is used as the start point and now is the end point.
If an argument is supplied the run will be for the lawID and date range specified.
The date range needs to be in the ISO date time format something like this. 2015-01-01T00:00:00.

+------------------------------------+
| UPDATE A RANGE OF STATUTES BY DATE |
+------------------------------------+

Drush Command:                      update-range-statutes				Run Update range Statutes.

Alias:                              uns

Argument:                           lawID/fromDateTime/toDateTime			Optional argument.
                                    /ABP/2015-01-01T00:00:00/2016-01-01T00:00:00/ 	Specify lawID Start and End times.


Examples:
Standard example                    drush update-range-statutes 			Does a run between the last time run and now.
Argument example                    drush update-range-statutes /ABP/2015-01-01T00:00:00/2016-01-01T00:00:00/


Update lawID ABP where the change date was between 2015-01-01T00:00:00 and 2016-01-01T00:00:00


====================================================================================================
Clearing a Range of Statutes
====================================================================================================
structure-clear-range-statutes


The structure-clear-range-statutes drush command can clear a range of statutes that had structural changes in open leg
that require a complete reload of statutes in a law_id.

After you Clear a Range of Statutes you might run
structure-update-range-statutes to update or replace that same group of law_ids
that was last cleared with the structure-clear-range-statutes drush command.

You can also update or replace statutes removed by structure-clear-range-statutes
using the update-all-statutes drush command.


Drush Command:                             structure-clear-range-statutes

Alias:                                     scrs

Examples:
 Standard example                          drush structure-clear-range-statutes
 lawID, fromDateTime & toDateTime example  drush structure-clear-range-statutes
                                           2015-01-01T00:00:00
                                           2016-01-01T00:00:00

Arguments:
 from_date_time                            An optional argument to specify the
                                           fromDateTime Use the ISO time format
                                           and include slashes.
 to_date_time                              An optional argument to specify the
                                           toDateTime. Use the ISO time format
                                           and include slashes.

Options:
 --dry                                     Do Not Delete, Just List Them.




====================================================================================================
Updating a Cleared Range of Statutes
====================================================================================================
After you Clear a Range of Statutes you might run
structure-update-range-statutes to update or replace that same group of law_ids
that was last cleared with the structure-clear-range-statutes drush command.

You can also update or replace statutes removed by structure-clear-range-statutes
using the update-all-statutes drush command.

If you run this command before ever running the structure-clear-range-statutes
it wont do anything bacause there wont be a list of law_ids in the law_id_queue.


Drush Command:                             structure-update-range-statutes

Alias:                                     surs



====================================================================================================
Repealing a Range of Statutes
====================================================================================================
This commands Deletes statutes.
If no argument is supplied the last run date is used as the start point and now is the end point.
If an argument is supplied the run will be for the lawID and date range specified.
The date range needs to be in the ISO date time format something like this. 2015-01-01T00:00:00.

+--------------------------------------+
| REPEAL  (DELETE) BY A RANGE OF DATES |                       |
+--------------------------------------+
Repeal (delete) a range of statutes.
Pass in a date range or it will use the current dat and last run.


Drush Command:                      repeal-range-statutes

Alias:                              rrs

Argument:                           Date or date range.


Examples:
Standard example                    drush repeal-range-statutes /2015-01-01T00:00:00/2016-01-01T00:00:00/


Repeals (Deletes) where the change date was between 2015-01-01T00:00:00 and 2016-01-01T00:00:00

====================================================================================================
Info and Utility Commands                                                                          |
====================================================================================================

====================================================================================================
Stopping a Running Job
====================================================================================================
This command stops a running Job.

Drush Command:                     stop-statute-processing      Run stop-statute-processing

Examples:
 Standard example                  drush stop-statute-processing

Arguments:
 arg1                              No optional arguments

Alias:                             ssp


====================================================================================================
Resetting and preparing for a new run.
====================================================================================================
This command clears the stopped / paused flag variable used by a running Job.

Drush Command:                    reset-statute-processing     Run reset-statute-processing

Examples:
 Standard example                 drush reset-statute-processing

Arguments:
 arg1                             No optional arguments

Alias:                            rsp

+---------------------------------------------------+
| GET THE CURRENT LAW-ID OR LAW-ID WHERE A RUN DIED |
+---------------------------------------------------+

Drush Command:                      currently-processing-law-id			Run Update range Statutes.

Alias:                              cpli

Argument:                           drush 					Any argument drush for example will produce important status and config info.
										No argument produces the current lawID or the lastID in case of a failure.


Examples:
Standard example                    drush currently-processing-law-id 		Produces a naked lawID like ABP.
Argument example                    drush currently-processing-law-id drush	Produces LawID and drush alias.



+-------------------------------------+
| STATUS REPORT                       |
+-------------------------------------+
Shows the progress of a running of finished run.


Drush Command:                      status-all-statutes

Alias:                              sas

Argument:                           No arguments.


Examples:
Standard example                    drush status-all-statutes

====================================================================================================
CHANGE HISTORY                                                                                     |
====================================================================================================

--------------------------
nys_statute.import Module
--------------------------

Added multi threading by breaking up the larger task and calling a single drush command repeatedly for each law_id breaking a complete run into 143 smaller runs.

Added the nys_statute_import_log table to store the structure of the open_leg data.
The table is rebuilt on complete update-all-statutes or audit-all-statutes runs.

If a run is for a single law_id the data in the nys_statute_import_log table
will be updated to reflext any changes in the law_id.

Added the nys_statute_import_law_queue table to store a list of law_ids
that have structural changes requiring a rebuild of the law_id.

The nys_statute_import_law_queue table is used by the structure-clear-range-statutes drush command to identify which law_id`s to clear.

The nys_statute_import_law_queue table is used by the structure-update-range-statutes drush command to identify which law_id`s to clear.

Added a page to monitor the status of a live or completed run an admin page at admin/reports/statute/status.
With tabs for the following reports.

    Statute Status                   monitors the status of a live or completed run an admin page at
                                     admin/reports/statute/status.

    NYS Extra Pages                  A report on pages on NYS site not in open leg.
                                     /admin/reports/statute/report/1

    NYS Missing Pages                A report on pages on open leg site not in NYS.
                                     /admin/reports/statute/report/2

    law_id & location_id not found   A report on pages on NYS with incorrect law_id & location_id.
                                     /admin/reports/statute/report/3

    Duplicate statute_id             A report on duplicate pages on NYS with the same statute_id.
                                     /admin/reports/statute/report/4

    Duplicate law_id & location_id   A report on duplicate pages on NYS with the same law_id & location_id.
                                     /admin/reports/statute/report/5


Added these new drush commands.


statutes-report                            Statutes Report shows missing or extra statutes

status-all-statutes			   Real time monitor of a live run or status of the the last run.

audit-report                               A series of reports also available at admin/reports/statute/status

structure-clear-range-statutes             Clearing a Range of Statutes specified by open leg Get law tree updates

structure-update-range-statutes            Updating a Cleared Range of Statutes specified by open leg Get law tree updates

repeal-range-statutes                      Repealing a Range of Statutes specified by open leg Get repealed laws


--------------------------
nys_statute_delete Module
--------------------------

Added a drush command to delete all the statutes for a particular law_id.

Added multi threading by breaking up the larger task and calling a single drush command repeatedly for each law_id breaking a complete run into 143 smaller runs.

Added a command to return the number of statute nodes or the number of statutes with a particular law_id.

Added these new drush commands.

clear-all-law-ids    - Clears all law ids
clear-law-id         - Clears a single Law ID
get-statute-count    - Gets the number of statute nodes


====================================================================================================
APPENDIX                                                                                           |
====================================================================================================

This is the normal command to run on a regular basis

drush @pantheon.my-site-alias update-all-statutes -y

or
drush @pantheon.my-site-alias update-all-statutes --force -y


To rebuild laws when the law tree structure changes
put these two drush commands in the shell script run by the regular cron job.

drush @pantheon.my-site-alias structure-clear-range-statutes -y
drush @pantheon.my-site-alias update-all-statutes --force -y
