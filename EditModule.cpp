void editProFile(int target, string change, string name)
{
  ifstream file;
  ofstream temp;
  file.open((name+".txt").c_str());
  temp.open("temp.txt");
  int index=1;
  string word;
  while(file>>word)
  {
    //read the word from file and write till the point we need to write the change
    if(index==target)//Now the record needs to be edited
        temp<<change<<endl;//then the record is edited
    else
      temp<<word<<endl;//if the field is not the one to be changed the file is just copied
    ++index;

  }
  name+=".txt";
  file.close();
  temp.close();
  remove(name.c_str());
  rename("temp.txt",name.c_str());

}

void editKeyFile(string name, string change, string key)
{
  ifstream old;
  ofstream temp;
  old.open((key).c_str());
  temp.open("tempKey.txt");
  string line;
  while(getline(old, line))
  {
    if(line.find(name)==string::npos)
      temp<<line<<endl;
    else
      temp<<change<<" "<<name+".txt"<<endl;
  }
  temp.close();
  old.close();
  remove(key.c_str());
  rename("tempKey.txt",key.c_str());
}

void editProfile(string name)
{

  int choice;
  cout<<"What do you want to edit:\n"<<endl;
  cout<<"1. Password\n";
  cout<<"2. Gender\n";
  cout<<"3. Age\n";
  cout<<"4. Year of Study\n";
  cout<<"5. Faculty of Study\n";
  cout<<"6. Hall of Residence\n";
  cout<<"Choice:";
  cin>>choice;
  string word;
  cout<<"Enter New";
  cin>>word;
  editProFile(choice,word,name);//edit profile file

  switch(choice){

    case 2:{
      editKeyFile(name,word,"GenderKeyFieldFile.txt");
      break;
    }
    case 3:{
      editKeyFile(name,word,"AgeKeyFieldFile.txt");
      break;
    }
    case 6:{
      editKeyFile(name,word,"HallKeyFieldFile.txt");
      break;
    }

  }

}
