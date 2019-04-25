#include "RecordSearchModule.cpp"
#include "EditModule.cpp"
void PostLogin(string name){
  int choice=4;
  do{
    cout<<"Welcome,"<<name<<endl;
    cout<<"*******************************************************************\n";
    cout<<"1.Edit your profile\n";
    cout<<"2.Search for a user\n";
    cout<<"3.Recommend a date\n";
    cout<<"4.Logout\n";
    cout<<"********************************************************************\n";

    cin>>choice;//Enter User command

    switch(choice){

      case 1:{
        editProfile(name);
        break;
      }
      case 2:{
        SearchMenu();
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
