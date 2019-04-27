# HKU-Tinder

## Introduction:
The aim of the project is to make a dating program for HKU Students. Such a project, if successful can have its log-in incorporated with the HKU Portal.

## Running the Program
Using an IDE:
  * You may just run the main.cpp file

Using Terminal or Console Commands
  * First compile all the files and create the executable using
    ```
    make
    ```
  * Now you may just run the hence created executable called output
    ```
    ./output
    ```  
    
## How to navigate through the system
1. Once the program is up and running, you will see the **log-in page** :
   * For new user: You will be asked to enter the user details.
   * For existing user: You will be asked to enter the password.
2. Now you shall be lead to the dashboard which allows you to:
   1. Edit your profile within the system
   2. Search for an existing user
   3. Recommends a date
   
## Types of Files:

The Program will majorly have two types of files:

1. Key field files :These fields will contain the key fields, responsible for processing queries like sorting, searching and      recommendations.
2. Profiles : These fields are displayed only when another user or the owner themselves want to view the profile.

## Profiles:

This file uses the following type of data from the user: name, age, residence/hall, nationality, race, skin color and some physical features.

## Structure and how the program works:

The program relies on first facing a log in page which then generates a textfile based on their username or asks a new user to log in. Once into their account the user has the option to search for profiles, sort according to certain key fields or ask for recommendations from the program.

![Untitled Diagram](https://user-images.githubusercontent.com/47697048/55280324-20467e00-535f-11e9-9ecc-33d7dd2ab286.jpg)


### How data is stored on the database:

* The users have their individual **Profile Files**, named according to their username.
* The **Key files** contain the username and the information of the User under the field.


### How our system manages the data:

1. Upon a search request, the program looks up the Master Key file and matches the username to the relevant Profile file and displays the profile.
2. If there is a sort request, the program looks for the matching Key file and obtains the result by solving the request.

## How the recommendation works:

The user is given the option of adding preferences once the recommendations option is selected from the menu. Such preferences basically define the basis for how the recommendation system works. According to what preferences the user enters, the program matches it with the database providing the recommended people according to the most matching categories.

## How the program matches the requirements:

1. file i/o: As explained before there are two types of text files in which the data is stored.
2. Dynamic memory allocation: The program creates multiple linked lists to send the data across between different functions.

## Limitations to out project
1. Any input must not have any space or else it may interfere with inputs later.
2. If a number out of the range of any option on the menu is entered, the program will not prompt the user to enter correct input.

## Future developments
In addition to removing the current limitations to the system, we further would develop the recommendations module within the system. There shall be a scoring system (currently in the comments) which once implemented would arrange users according to those who meet the requirements the most to those who match the least. This shall refine the recommendations system giving a more accurate result for recommendations.

 
