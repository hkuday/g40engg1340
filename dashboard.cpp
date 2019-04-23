#include <iostream>

using namespace std;

void PostLogin(string name){
  int choice=4;
  do{
    cout<<"Welcome,"<<name<<endl;
    cout<<"*******************************************************************\n";
    cout<<"1.Sorting the data\n";
    cout<<"2.Search for a user\n";
    cout<<"3.Recommend a date\n";
    cout<<"4.Logout\n";
    cout<<"********************************************************************\n";

    cin>>choice;//Enter User command

    switch(choice){

      case 1:{
        cout<<"sort\n";
        break;
      }
      case 2:{
        cout<<"search\n";
        break;
      }
      case 3:{
        cout<<"recommend\n";
        break;
      }
      case 4:
        cout<<"Bye Bye\n";

    }
  }while(choice!=4);
}
