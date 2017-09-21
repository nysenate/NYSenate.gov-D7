

Importing or Updating All Statutes
Auditing of All Statutes
Updating a Range of Statutes
Info and Utility Commands

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

Alias:                              ias

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

Alias:                              rias

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

Drush Command:                      audit-all-statutes							Audit All Statutes.

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
Updating a Range of Statutes
====================================================================================================
This commands Update statutes.
If no argument is supplied the last run date is used as the start point and now is the end point.
If an argument is supplied the run will be for the lawID and date range specified.
The date range needs to be in the ISO date time format something like this. 2015-01-01T00:00:00.

+------------------------------------+
| UPDATE A RANGE OF STATUTES BY DATE |
+------------------------------------+

Drush Command:                      update-range-statutes						Run Update range Statutes.

Alias:                              uns

Argument:                           lawID/fromDateTime/toDateTime					Optional argument.
                                    /ABP/2015-01-01T00:00:00/2016-01-01T00:00:00/ 	Specify lawID Start and End times.


Examples:
Standard example                    drush update-range-statutes 					Does a run between the last time run and now.
Argument example                    drush update-range-statutes /ABP/2015-01-01T00:00:00/2016-01-01T00:00:00/
									Update lawID ABP where the change date was between 2015-01-01T00:00:00 and 2016-01-01T00:00:00




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
This command clears flags and variables used by a running Job.

Drush Command:                    reset-statute-processing     Run reset-statute-processing

Examples:
 Standard example                 drush reset-statute-processing

Arguments:
 arg1                             No optional arguments

Alias:                            rsp

+---------------------------------------------------+
| GET THE CURRENT LAW-ID OR LAW-ID WHERE A RUN DIED |
+---------------------------------------------------+

Drush Command:                      currently-processing-law-id						Run Update range Statutes.

Alias:                              cpli

Argument:                           drush 											Any argument drush for example will produce important status and config info.
																					No argument produces the current lawID or the lastID in case of a failure.


Examples:
Standard example                    drush currently-processing-law-id 				Produces a naked lawID like ABP.
Argument example                    drush currently-processing-law-id drush			Produces LawID and drush alias.

																					LAST PROCESSING GBS
																					drush vget nys_statute_import_process_statutes = GBS


+-------------------------------------+
| DELETE AND REMOVE ALL STATUTE NODES |
+-------------------------------------+

Drush Command:                      clear-all-statutes								Delete all Statute Nodes.

Alias:                              casn

Argument:                           No arguments.


Examples:
Standard example                    drush clear-all-statutes 						Delete all Statute Nodes.





====================================================================================================
APPENDIX                                                                                           |
====================================================================================================

Notes.

There are over 22,000 statutes.
It can take up to 10 hours for a run to complete.

You can do a complete import /update run with the following command.

drush update-all-statutes -y
