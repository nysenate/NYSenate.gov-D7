

Importing or Updating All Statutes
Importing or Forced Update of All Statutes
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

Drush Command:                      import-all-statutes                         Import or Update Statute Nodes.

Alias:                              ias

Argument:                           lawID-locationID
                                    An optional lawID or a lawID-locationID

Examples:
Standard example                    drush import-all-statutes                   Process All Statute Nodes.
lawID example                       drush import-all-statutes ABP               Process All ABP Statute Nodes.
lawID-locationID example            drush import-all-statutes ABP-215           Process the ABP-215 Statute Node.


+----------------------------------------------------------------+
| RESTART AN IMPORT OR UPDATE ALL STATUTES THAT HAVE CHANGED RUN |
+----------------------------------------------------------------+

Drush Command:                      restart-import-all-statutes                 Restart Import or Update Statute Nodes after a failure.

Alias:                              rias

Argument:                           lawID                                       An optional lawID where processing starts
                                                                                With no argument the date from the last run is used as the starting point.

Examples:
Standard example                    drush restart-import-all-statutes           Process All Statute Nodes restarting at the failure point.
lawID example                       drush restart-import-all-statutes ABP       Process All Statute Nodes starting with ABP.

Note:                                                                           The restart- command with no argumentss gets the starting point from the
                                                                                nys_statute_import_process_statutes drupal variable.
                                                                                You can use drush vget nys_statute_import_process_statutes to view the value.


+------------------------------------------------------------------------------+
| PRINT THE INDIVIDUAL DRUSH COMMANDS FOR AN IMPORT OR UPDATE ALL STATUTES RUN |
+------------------------------------------------------------------------------+

Drush Command:                      describe-import-all-statutes                Prints Import All Statute Nodes individual drush commands.

Alias:                              dias

Argument:                           lawID                                       An optional lawID where processing starts

Examples:
Standard example                    drush describe-import-all-statutes          Returns the individual Import Drush commands for all statutes.
lawID example                       drush describe-import-all-statutes ABP      Returns the individual Import Drush commands for all statutes starting with ABP.

Note:                                                                           You should set the nys_statute_import_drush_alias for the alias to be included.



====================================================================================================
Importing or Forced Update of All Statutes                                                         |
====================================================================================================
These commands Import or Update statutes.
If a statute is not in the system it gets imported.
If a statute has already been imported previously it gets updated wether it changed or not.
All nodes will have a new changed date.

+-------------------------------+
| IMPORT OR UPDATE ALL STATUTES |
+-------------------------------+

Drush Command:                      update-all-statutes                         Import or Update Statute Nodes.

Alias:                              uas

Argument:                           lawID-locationID
                                    An optional lawID or a lawID-locationID

Examples:
Standard example                    drush update-all-statutes                   Process All Statute Nodes.
lawID example                       drush update-all-statutes ABP               Process All ABP Statute Nodes.
lawID-locationID example            drush update-all-statutes ABP-215           Process the ABP-215 Statute Node.

+----------------------------------------------+
| RESTART AN IMPORT OR UPDATE ALL STATUTES RUN |
+----------------------------------------------+

Drush Command:                      restart-update-all-statutes                 Restart Import or Forced Update Statute Nodes after a failure.

Alias:                              ruas

Argument:                           lawID                                       An optional lawID where processing starts
                                                                                With no argument the date from the last run is used as the starting point.

Examples:
Standard example                    drush restart-update-all-statutes           Process All Statute Nodes restarting at the failure point.
lawID example                       drush restart-update-all-statutes ABP       Process All Statute Nodes starting with ABP.

Note:                                                                           The restart- command with no argumentss gets the starting point from the
                                                                                nys_statute_import_process_statutes drupal variable.
                                                                                You can use drush vget nys_statute_import_process_statutes to view the value.

+------------------------------------------------------------------------------+
| PRINT THE INDIVIDUAL DRUSH COMMANDS FOR AN IMPORT OR UPDATE ALL STATUTES RUN |
+------------------------------------------------------------------------------+


Drush Command:                      describe-update-all-statutes                Prints Update All Statute Nodes individual drush commands.

Alias:                              dias

Argument:                           lawID                                       An optional lawID where processing starts

Examples:
Standard example                    drush describe-update-all-statutes          Returns the individual Update Drush commands for all statutes.
lawID example                       drush describe-update-all-statutes ABP      Returns the individual Update Drush commands for all statutes starting with ABP.

Note:                                                                           You should set the nys_statute_import_drush_alias for the alias to be included.


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

+-------------------------------------------------------------------+
| PRINT THE INDIVIDUAL DRUSH COMMANDS FOR AN AUDIT ALL STATUTES RUN |
+-------------------------------------------------------------------+

Drush Command:                      describe-audit-all-statutes                	Prints Audit All Statute Nodes individual drush commands.

Alias:                              daas

Argument:                           lawID                                       An optional lawID where processing starts

Examples:
Standard example                    drush describe-audit-all-statutes          	Returns the individual Audit Drush commands for all statutes.
lawID example                       drush describe-audit-all-statutes ABP      	Returns the individual Audit Drush commands for all statutes starting with ABP.

Note:                                                                           You should set the nys_statute_import_drush_alias for the alias to be included.


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

																					THE DRUSH ALIAS FOR describe- COMMANDS IS SET TO loc.nysenate.
																					drush vset nys_statute_import_drush_alias [sites drush alias heres]   
									 
									 
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

drush import-all-statutes -y

Depending on the memory resources available 
this could exceed the available memory for php scripts.

If runs produce errors running out of memory or
to insure trouble free operation of the import/update
break the task up by generating individual drush commands using the 
drush describe-import-all-statutes command.
This breaks the import/update processing job up into 135 much smaller processes.

Creating a command file on your local machine with the drush commands in it.

Step 1.
drush vset nys_statute_import_drush_alias [your site id goes here]

Step 2.
drush describe-import-all-statutes -y > [desired location of your command file]

Step 3.
Execute the command file.

Example command file (output from the `describe-import-all-statutes VOL` command):

drush @your-alias import-all-statutes VOL -y
drush @your-alias import-all-statutes WKC -y
drush @your-alias import-all-statutes YFA -y
drush @your-alias import-all-statutes YTS -y

The `drush @your-alias describe-import-all-statutes -y` command creates all 134 drush commands 
breaking the complete run into components.




