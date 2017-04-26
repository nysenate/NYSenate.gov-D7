# NYSenate.gov
This repository contains the source code for [NYSenate.gov](https://www.nysenate.gov), the official web application of the New York State Senate. NYSenate.gov is built on [Drupal](https://www.drupal.org/) and serves as the chamber’s central digital presence.

New York State senators are tasked with representing 20 million citizens. This platform makes it easier for each and every citizen to participate in the legislative process, providing feedback to lawmakers on issues that matter to them. It also makes it easier for senators and staff to authentically consider and respond to the enormous volume of feedback they receive on a daily basis. [Read more about NYSenate.gov’s unique functionality](https://www.nysenate.gov/taking-action).

## Why we publish this source code
For most products, [NY Senate Technology Services](https://twitter.com/nysenatetech) publishes non-proprietary code [on Github](https://github.com/nysenate) and welcomes issue reports and pull requests from external developers. The New York State Senate is an avid consumer of open source technology. Because public funds are used to for our projects, we return the source code to the public domain. 

This repository is published primarily for academic purposes. Specifically, our goal is to share details of our approach with the broader Drupal community and with other local, state, and national legislatures that may be interested in implementing a similar system. To that end, we’d like to draw your attention to some of the [custom aspects of our implementation](https://github.com/nysenate/NYSenate.gov/tree/master/sites/all/modules/custom). Here are a few highlights:

### Open Legislation Integration
NYSenate.gov is a customer of the [Open Legislation API](http://legislation.nysenate.gov) (also created and maintained by NY Senate Technology Services).  This service manages the full revision history of all official legislative documents in the NY State Legislature ([more than 150,000 bills, laws, calendars, agendas, sponsor memos, etc.](http://legislation.nysenate.gov/static/docs/html/index.html)), and NYSenate.gov syncs with it every few minutes. You can explore key integration points in the following modules:

* [Bill Sync/Import Module](/blob/master/sites/all/modules/custom/nys_bill_import/nys_bill_import.module)
* [Law Sync/Import Module](https://github.com/nysenate/NYSenate.gov/tree/master/sites/all/modules/custom/nys_statute_import)

### Bluebird CRM Integration
NYSenate.gov has a suite of CRM features built in to help senators and staff manage correspondence with their constituents. Additionally, NYSenate.gov supports a one-way sync to our full-featured internal constituent relationship management solution, Bluebird ([also published by NY Senate on Github](https://github.com/nysenate/Bluebird-CRM)). We refer to the integration point as “[the accumulator](/sites/all/modules/custom/nys_accumulator),” and it serves a transaction log of all relevant constituent activity on the web site to authorized clients.

### Senate Address Geocoding Engine (SAGE) Integration
An important function of NYSenate.gov is classifying inbound constituents according to the New York State senator who represents them. Since representation is based on geography, this could not be done without [SAGE](https://github.com/nysenate/GeoApi), an open source geocoding service built and maintained by the New York State Senate. Every time a user signs up on NYSenate.gov, SAGE is called to match their address to a senate district. You can take a look at the integration point in the [NYS SAGE](/sites/all/modules/custom/nys_sage) module.

### Slack Integration
Mission-critical system notifications are published directly into our internal Slack channel. The function can be found [here](https://github.com/nysenate/NYSenate.gov/blob/master/sites/all/modules/custom/nys_utils/nys_utils.module#L1763-L1832).

## Roadmap
We welcome suggestions for future development in [the issue queue](https://github.com/nysenate/NYSenate.gov/issues). We would also appreciate meta-feedback on how we can make this repository more useful for developers. Here are a few things we hope to prioritize, but please let us know what else you would like to see.

### Demo Database
Conspicuously missing from this repository is a link to a demo database. We suspect that it would be near impossible to get NYSenate.gov up and running on your local environment without a redacted database. Out of an abundance of caution to protect the political sentiments of the 110,000+ New Yorkers who have used this system to contact their senator, we have decided to phase in a redacted demo database at a later date.

### Generalized Features
This implementation is customized to serve the esoteric requirements of NY’s lawmaking process. We would love to generalize some of our custom modules so that they could serve as turnkey solutions for other legislatures looking to implement similar functionality. If you work with a legislature that would be interested in partnering with us, please [get in touch.](mailto:blair@nysenate.gov)

## Credits
This platform would not exist without conceptualization and ongoing stewardship from the web development team at the New York State Senate, ongoing Drupal consulting from [MediaCurrent](https://www.mediacurrent.com), product design and initial implementation from [Code and Theory](http://www.codeandtheory.com), and a challenging D6 -> D7 data migration executed by [NuCivic (now Granicus)](http://www.granicus.com).

Of course, we’d be remiss not to recognize the [members of the New York State Senate](https://www.nysenate.gov/senators-committees) and the chamber leadership for their unwavering support and commitment to innovation in this space.

## Contact us
If you are interested in exploring a partnership with the New York State Senate on aspects of this platform, please get in touch with the NYSenate.gov product manager, [Ryan Blair](https://github.com/rtblair): [blair@nysenate.gov](mailto:blair@nysenate.gov). 

You can also reach our team on Twitter at https://www.twitter.com/nysenatetech.
