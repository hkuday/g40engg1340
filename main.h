//Pre processor directives
//Header Files
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>


using namespace std;

//Structures included
struct user//infomation recorded about a user
{
  //add the key fields for each user
  int age;
  int yearOfStudy;
  string name="";
  string hall="";
  string gender="";
  string faculty="";
};

struct Node//for creating linked list
{
  string uName;//Only information is username
  int score=0;
  Node * next;//For connecting the linked list
};

//Function : clrscr()
//The function just prints 60 new lines to clear screen
void clrscr(){
  cout<<string(60,'\n');
}

//Function: Pause()
//Only for generating a console pause
void Pause()
{
  char temp;
  cout<<"Input any character to continue..."<<endl;
  cin>>temp;//garbage input, is not used
}
