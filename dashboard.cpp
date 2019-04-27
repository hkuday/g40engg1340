//Pre-processor directive
#include "RecordSearchModule.cpp"
#include "EditModule.cpp"
#include "RecommendationsModule.cpp"

/*
Function:PostLogin(string name)
  Input:
    name: Username of the person whose account it is
  Output:
    1.Serves as the display and menu for options available to the user
    2.Calls functions or exits program according to what is asked
*/

void PostLogin(string name){
  int choice=4;//By default choice is set to exit condtion below
  do{
    clrscr();
    //Found the text format at: http://patorjk.com/software/taag/#p=display&f=Varsity&t=Dashboard
    cout<<"\t\t ___  ____ ____ _  _ ___  ____ ____ ____ ___  \n";
    cout<<"\t\t|  \\ |__| [__  |__| |__] |  | |__| |__/ |  \\ \n";
    cout<<"\t\t|__/ |  | ___] |  | |__] |__| |  | |  \\ |__/ \n";

    cout<<"\n\nWelcome,"<<name<<endl;
    cout<<"*******************************************************************\n";
    cout<<"1.Edit your profile\n";//*
    cout<<"2.Search for a user\n";//**
    cout<<"3.Recommend a date\n";//***
    cout<<"4.Logout\n";//****
    cout<<"********************************************************************\n";

    cin>>choice;//Enter User command from the options 1-4

    switch(choice){

      case 1:{//*
        editProfile(name);
        break;
      }
      case 2:{//**
        SearchMenu();
        break;
      }
      case 3:{//***
        FigureRecommendations();
        break;
      }
      case 4://****
        cout<<"Successful Logout\n";
      //default://if invalid input
      //  {
          //clrscr();
      //    cout<<"\n\nPlease enter Valid Command\n\n";
      //  }

    }
  }while(choice!=4);
}
