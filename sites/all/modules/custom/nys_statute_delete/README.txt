NYS statute_delete module.


clear-all-statutes   - Clears all statutes
clear-all-law-ids    - Clears all law ids
clear-law-id         - Clears a single Law ID
get-statute-count    - Gets the number of statute nodes




-------------------------------------------------------------------------------------------------
clear-all-statutes

This is a very large task and would probably run out of memory more than once
on must systems. Just run it over and over until it completes to completely
clear all statutes.

You can also run clear-all-law-ids which clears out each law_id in a separate
process so you never run out of memory no matter how many statute nodes there are.

Examples:
 Standard example                          drush clear-all-statutes

Arguments:
 arg1                                      An optional argument

Aliases: casn


-------------------------------------------------------------------------------------------------
clear-all-law-ids    			   Clears all law ids

clear-all-law-ids clears out each law_id in a separate
process so you never run out of memory no matter how many statute nodes there are.

Examples:
 Standard example                          drush clear-all-law-ids

Arguments:
 arg1                                      An optional argument

Aliases: cali


-------------------------------------------------------------------------------------------------
clear-law-id                               Clears a single law id

This is used internally by the clear-all-law-ids drush command.
You will not be asked before clearing it just rudely clears without asking.


Examples:
 Standard example                          drush clear-law-id
 Argument example                          drush clear-law-id ABP

Arguments:
 arg1                                      An optional argument

Aliases: clid


-------------------------------------------------------------------------------------------------
get-statute-count                          Gets the number of statute nodes


Examples:
 Standard example                          drush get-statute-count
 Argument example                          drush get-statute-count ABP

Arguments:
 arg1                                      An optional argument

Aliases: gsc
