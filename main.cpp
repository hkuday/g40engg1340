#include <iostream>
#include <string>
#include "main.h"
#include "dashboard.cpp"
#include "AccessControl.cpp"


int main(){
  string name;
  if(AccessControl(name))
      PostLogin(name);



  return 0;
}
