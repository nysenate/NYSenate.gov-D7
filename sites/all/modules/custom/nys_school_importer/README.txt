NYS School Importer



---------------------------------------------------------------------+
Importing or Updating the NYSED Index                                |                             
---------------------------------------------------------------------+
Before importing the Schools you should import the NYSED Institution Data.
This is used to determine a schools physical address 
when importing or updating the data for a school.

The Import NYSED and School Data from CSV Files page
allows you to import a NYSED data file.


You can get a NYSED csv data export at this link:
https://portal.nysed.gov/discoverer/app/export?event=startExport

You can import a NYSED file in one shot, or divide it up 
into pieces if its too big. You can also merge different
NYSED files or update records just by feeding in the changed rows.

The Import NYSED and School Data from CSV Files page displays the
number of Institutions that were uploaded previously.

When you are done Importing or Updating the NYSED Index 
click the `Completed NYSED Uploads -  Continue to School Import Button.


---------------------------------------------------------------------+
Import the CSV File Into School Nodes.                               |
---------------------------------------------------------------------+


If the School exists it is checked to see if it differs.
If there are no differences the School node is left unchanged.
If the import data does differ the School node gets updated.

In order to have unique and distinct School names.
Duplicate or multi plicate instances of school names are
lengthened as necessary with unique data.

In order to make them unique a School name might get it's city, 
organization_type (Elementary) or zip code added to it when necessary.

Importing Schools is a four step process.
I. Survey
The input CSV file gets uploaded and a table named `nys_school_names` gets created
with the School name as well as it's city, organization_type (Elementary) and zip code.

II. Analysis
Each school name is analyzed for uniqueness.
All duplicate and multiplicate school names are added to a second table named 
nys_school_names_index along with a number indicating how many key items
will need to be added to make it unique.

III. Import/Update
If a school name can not made unique by adding three additional keys to it.
The process is stopped at this point to report the School names having a problem.

IV. Report
At the end of the processing a list is created of any schools which 
do not have uniques names. Links to the edit pages of the non unique pages 
are provided so corrections can be made.


At that point the process can be quit and the school names can be made unique in 
the input data and then re uploaded to complete Step I and II.

You can also Continue and go ahead with the Import/Update.
The School Names which could not be made unique by adding three additional keys will
have an additional number appended to them to make them unique.
These can be updated manually if desired.

The mapping of the CSV file to Drupal School fields is accomplished using
the data in the nys_school_importer_mapping.json.

To start the process go to admin/config and click School Importer or
/admin/config/system/nys-school-import.

You will be prompted for the CSV file
and will see the three batches processed.
At the end a Message will be presented.




---------------------------------------------------------------------+
Appendix:                                                            |                             
---------------------------------------------------------------------+

Location of pages:
I. Upload and Survey
/admin/config/system/nys-school-import

II. Analysis
/admin/nys-school-analyze

III. Import/Update
/admin/nys-school-import

IV. Report
/admin/nys-school-report


Mapping File
nys_school_importer_mapping.json is used to map the import CSV file
to the Drupal fields of the School content type.
There is an entry for every Column in the CSV file.


{
  "4": {                                          The Column Number in the CSV file                                  
         "csv_colname": "LEGAL NAME",             The Column Name for this column from the first row.
         "drupal_colname": "legal_name",          The Name of the Drupal Field to populate.
         "drupal_coltype": "value",               The Type of Drupal field (most are `value`)
         "drupal_coltitle": "School Legal Name"   The Human Readable Name of the Drupal Column (Unused)
  },
  ... The rest of the columns in the CSV file.
}


Analysis Exception File

If the Unique Naming analysis does not provide the required number of keys for any reason.
You can add  an entry into the nys_school_importer_exceptions.json File.
You put the legal_name and num_keys into the json and the school will be updated
at the end  of the Analysis. 

num_keys
----------------------------------------------------------------------------------------+
value   Description                                                                     |
----------------------------------------------------------------------------------------+ 
1       Just the legal_name                                                             |
2       The legal_name, city                                                            |
3       The legal_name, grade_organization, city                                        |
4       The legal_name, grade_organization, city, zip                                   |
5       The legal_name, grade_organization, city, zip, (A single random numeral added)  |
6+      The legal_name, grade_organization, city, zip, (A single random numeral added)  |
----------------------------------------------------------------------------------------+ 


[{
	"legal_name": "IMMACULATE CONCEPTION SCHOOL",   The legal_name of the school
	"num_keys": "4"                                 The Number of keys to add to a school name
}]


OPTIONS
---------------------------------------------------------------------+
Appendix:                                                            |                             
---------------------------------------------------------------------+
drush vset  nys_school_importer_default_school_names_index_name 0
This will set the system up to use the calculated school names in the school node titles.

drush vdel  nys_school_importer_default_school_names_index_name
Clears the nys_school_importer_default_school_names_index_name and uses
the default value of 4 for all school names

drush vset  nys_school_importer_default_school_names_index_name 3
Sets the school names to use 3 elements in the school name.




