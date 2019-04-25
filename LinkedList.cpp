
void DisplayProfile(string username)
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

Node* Push(string name, Node * head)
{
  Node* temp= new Node;
  temp->uName=name;
  temp->next=head;
  head=temp;
  return head;
}

void Display(Node* head)
{
  int index=1,choice=0;;
  Node* current=head;
  while(current!=NULL)
  {
      cout<<index<<" : "<<current->uName<<endl;
      current=current->next;
      ++index;
  }
  index=1;
  cin>>choice;
  current =head;
  while(current!=NULL)
  {
      if(index==choice)
        DisplayProfile(current->uName);
      ++index;
  }

}
