To get started go to a url like this

/subscriptions/signup/378/1/
where 378 is the taxonomy tid
and 1 is the node id of the bill.

Add an email address and click the Subscribe button.

This will generate a new subscription.
and will show the links to use on that subscription
that would normally come inside of emails in the drupal message box.



Example
-------------------

Signup - received.

API CALL TO CREATE       nys_subscriptions_send_confirmation_email(378, 1, basilfamone@aol.com)                     API CALL TO CREATE SUBSCRIPTION

Confirmation Link        /subscriptions/subscribe/iTuklbat-_LTUlOoXGMHfs1l9kd1jKVZtZDK5bMbg8Y/                   SUBSCRIPTION KEY

RE/UNUNSubsubscribe Link /subscriptions/unsubscribe/iTuklbat-_LTUlOoXGMHfs1l9kd1jKVZtZDK5bMbg8Y/                 SUBSCRIPTION KEY

Manage Subscriptions     /subscriptions/manage-subscriptions/iTuklbat-_LTUlOoXGMHfs1l9kd1jKVZtZDK5bMbg8Y/        EMAIL KEY

Global UNSubscrube       /subscriptions/global-unsubscribe/iTuklbat-_LTUlOoXGMHfs1l9kd1jKVZtZDK5bMbg8Y/          EMAIL KEY






These keys are just examples and only valid on muy local system.

The data is stored in the nys_subscriptions table.

he drush bw commands report on subscription data.


+--------------------+--------------+------------------------------------------+
| drush commands     | aliases      | argument description                     |
+--------------------+--------------+------------------------------------------+
| subscriptions       | sw   sws     | All Subscriptions  NO ARGUMENT REQUIRED  |
| subscriptions-key   | swk  swkey   | Subscription with subscr KEY             |
| subscriptions-id    | swi  swid    | Subscription ID                          |
| subscriptions-tid   | swt  swtid   | Subscriptions to TID                     |
| subscriptions-nid   | swn  swnid   | Subscriptions to NID                     |
| subscriptions-uid   | swu  swuid   | Subscriptions by UID                     |
| subscriptions-email | swe          | Subscriptions by email                   |
| subscriptions-keys  | swks  swkeys | Subscriptions by either KEY              |
+--------------------+--------------+------------------------------------------+

--------------------------------------------------------------------------------
drush help subscriptions
Show All Subscriptions.

Aliases: sw, sws

--------------------------------------------------------------------------------
drush help subscriptions-key
Show data for a subscription.

Arguments:
 key                                      Theswid subscriptions subscription key.

Aliases: swk, swkey

--------------------------------------------------------------------------------
drush help subscriptions-id
Show data for a subscription.

Arguments:
 bwid                                      The bwid subscriptions index.

Aliases: swi, swid

--------------------------------------------------------------------------------
drush help subscriptions-tid
Show the Subscriptions associated with a bills tid.

Arguments:
 tid                                       The tid of the subscription.

Aliases: swt, swtid

--------------------------------------------------------------------------------
drush help subscriptions-nid
Show the Subscriptions associated with a bills nid.

Arguments:
 nid                                       The nid of the subscription.

Aliases: swn, swnid

--------------------------------------------------------------------------------
drush help subscriptions-uid
Show the Subscriptions associated with a bills nid.

Arguments:
 uid                                       The uid of the subscription.

Aliases: swu, swuid

--------------------------------------------------------------------------------
drush help subscriptions-email
Show data for a Subscriber.

Arguments:
 email                                     The email of the subscription.

Aliases: swe

--------------------------------------------------------------------------------
drush help subscriptions-keys
Show data for a Subscriber using either key.

Arguments:
 key                         The subscription or email key of the subscription.

Aliases: swks, swkeys

--------------------------------------------------------------------------------


Configuration

drush vset nys_subscriptions_signup_template 49ffed17-54d8-4bd9-81cb-b373be950a64


