/*
Function: editProFile(int target, string change, string name)
  Input:
    target: index of the field to be edited
    change: the new value for the above field
    name: the user name whose data is to be edited
  Output:
    1.The function opens the user file in read mode and and creates a new file in
    write mode
    2.The user file is read and simultaneously the temp file is written on
    3.If the index matches the target, the new value is written else the file is
     just copied word-by-word
    4.user file is deleted
    5.temp is renamed as the user file
*/
void editProFile(int target, string change, string name)
{
  ifstream file;//the user file is opened in this object
  ofstream temp;//the temp file is opened in this object
  file.open((name+".txt").c_str());//1
  temp.open("temp.txt");//1
  int index=1;
  string word;
  while(file>>word)//2
  {
    //read the word from file and write till the point we need to write the change
    if(index==target)//Now the record needs to be edited
        temp<<change<<endl;//then the record is edited
    else//2
      temp<<word<<endl;//if the field is not the one to be changed the file is just copied
    ++index;

  }
  name+=".txt";
  //closing files
  file.close();
  temp.close();
  //rename and delete files
  remove(name.c_str());//4
  rename("temp.txt",name.c_str());//5

}

/*
Function: editKeyFile(string name, string change, string key)
  Input :
    name : the username of the person whose value is edited in the file
    change : the new value for the field
    key : the name of the key field file to be changed
  Output:
    1.The function opens the key field file in read mode and and creates a new file in
    write mode
    2.The key field file is read line -by -line and simultaneously the temp file is written on
    3.If the name of the person is found in a line , the new value is added else
    the key file is copied
    4.key field file is deleted
    5.temp is renamed as the key field file
*/
void editKeyFile(string name, string change, string key)
{
  ifstream old;//1
  ofstream temp;//1
  old.open((key).c_str());
  temp.open("tempKey.txt");
  string line;
  while(getline(old, line))//2
  {
    if(line.find(name)==string::npos)//3
      temp<<line<<endl;//3
    else
      temp<<change<<" "<<name+".txt"<<endl;//3
  }
  //closing files
  temp.close();
  old.close();
  //rename and delete files
  remove(key.c_str());//4
  rename("tempKey.txt",key.c_str());//5
}

/*
Function: editProfile(string name)
  Input:
    name: Username of the person whose record is to be edited
  Output:
    1.Displays a list of the fields that can be edited
    2.Takes user's choice
    3.Updates the required user file and key field file by calling relevant functions
*/

void editProfile(string name)
{

  int choice;
  //clrscr();
  cout<<"\t____ ___  _ ___          _  _ ____ _  _ _  _ \n";
  cout<<"\t|___ |  \\ |  |     __    |\\/| |___ |\\ | |  | \n";
  cout<<"\t|___ |__/ |  |           |  | |___ | \\| |__|  \n\n";

  //1
  cout<<"What do you want to edit:\n"<<endl;//Displaying menu
  cout<<"=======================================================================\n\n";
  cout<<"1. Password : \n";
  cout<<"2. Gender : \n";
  cout<<"3. Age  : \n";
  cout<<"4. Year of Study : \n";
  cout<<"5. Faculty of Study : \n";
  cout<<"6. Hall of Residence : \n\n";
  cout<<"=======================================================================\n\n";
  cout<<"Choice : ";//2
  cin>>choice;//User enters choice
  string word;
  cout<<"Enter New : ";//Enter the new value for the field to be edited
  cin>>word;
  //implemeting step 3
  editProFile(choice,word,name);//edit profile file

  //The part below is only for updating the key field files ie only for 2,3,6
  switch(choice){

    case 2:{//Updating gender key field file
      editKeyFile(name,word,"GenderKeyFieldFile.txt");
      break;
    }
    case 3:{//Updating age key field file
      editKeyFile(name,word,"AgeKeyFieldFile.txt");
      break;
    }
    case 6:{//Updating hall key field file
      editKeyFile(name,word,"HallKeyFieldFile.txt");
      break;
    }

  }
  cout<<"The changes have been made"<<endl<<endl;
  Pause();
}
