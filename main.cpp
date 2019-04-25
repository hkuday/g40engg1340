
#include "main.h"
#include "dashboard.cpp"
#include "AccessControl.cpp"


int main(){
  string name;
  if(AccessControl(name))
      PostLogin(name);
      //add else


  return 0;
}
