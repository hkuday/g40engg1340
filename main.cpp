//Pre-processor directives
#include "main.h"
#include "dashboard.cpp"
#include "AccessControl.cpp"


int main(){
  string name;//For receiving the name of the user
  //clrscr();
  //Found the text format at: http://patorjk.com/software/taag/#p=display&f=Big&t=HKU-Tinder
  cout<<"\t __    _ _  ___    _     _______ _           _\n";
  cout<<"\t| |  | | |/ / |  | |   |__   __(_)         | |\n";
  cout<<"\t| |__| | ' /| |  | |______| |   _ _ __   __| | ___ _ __\n";
  cout<<"\t|  __  |  < | |  | |______| |  | | '_ \\ / _` |/ _ \\ '__|\n";
  cout<<"\t| |  | | . \\| |__| |      | |  | | | | | (_| |  __/ |\n";
  cout<<"\t|_|  |_|_|\\_\\\\____/       |_|  |_|_| |_|\\__,_|\\___|_| \n";
  cout<<endl<<endl;


  if(AccessControl(name))//checks if a successful login or new account is made
      PostLogin(name);//display the dashboard


  return 0;
}//main ends
