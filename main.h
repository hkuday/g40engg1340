#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>


using namespace std;

struct user
{
  //add the key fields
  int age=0;
  int yearOfStudy=0;
  string name="";
  string hall="";
  string gender="";
};

struct Node//for creating linked list
{
  string uName;
  Node * next;
};
