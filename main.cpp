#include "main.h"
#include "dashboard.cpp"
#include "AccessControl.cpp"

using namespace std;

int main(){
  string name;
  if(AccessControl(name))
      PostLogin(name);



  return 0;
}
