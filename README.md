# HKU-Tinder

## Introduction:
The aim of the project is to make a dating program for HKU Students. Such a project, if successful can have its log-in incorporated with the HKU Portal.

## Types of Files:

The Program will majorly have two types of files:

1. Key field files :These fields will contain the key fields, reponsible for processing queries like sorting, searching and      recommendations.
2. Profiles : These fields are displayed only when another user or the owner themselves want to view the profile.

## Profiles:

This file uses the following type of data from the user: name, age, residence/hall, nationality, race, skin color and some physical features.

## Structure and how the program works:

The program relies on first facing a log in page which then generates a textfile based on their username or asks a new user to log in. Once into their account the user has the option to search for profiles, sort according to certain key fields or ask for recommendations from the program.

### How data is stored on the database:

* The users have their individual **Profile Files**, named according to their username.
* The **Master Key** file contains only the User's Name and the username.
* The **Key files** contain the username and the information of the User under the field.


### How our system manages the data:

1. Upon a search request, the program looks up the Master Key file and matches the username to the relevant Profile file and displays the profile.
2. If there is a sort request, the program looks for the matching Key file and obtains the result by solving the request.

## How the recommendation works:

The user is given the option of adding preferences to their profile. Such preferances basically define the basis for how the recommendation system works. According to what preferences the user enters, the program matches it with the database providing the recommended people according to the most matching categories.

## How the program matches the requirements:

Our program constructs a DBMS for the users using the two types of files as specified and runs the required queries of sort and search on the key field files. Hence, meeting the requirements for the problem.

## 
