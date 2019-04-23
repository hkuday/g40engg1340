void Display(string username)
{
  string temp;
  ifstream name;
  name.open((username+".txt").c_str());
  name>>temp;
  name>>temp;
  cout<<username<<"'s gender is "<<temp<<endl;
  name>>temp;
  cout<<"Age is "<<temp<<endl;
  name>>temp;
  cout<<"In year "<<temp<<endl;
  name>>temp;
  cout<<"In the faculty of "<<temp<<endl;
  name>>temp;
  cout<<"And lives in "<<temp<<" hall"<<endl<<endl;
  name.close();
}
