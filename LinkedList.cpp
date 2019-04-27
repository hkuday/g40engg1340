/*
Function: FreeMemory(Node * &head)
Input:
  head for the linked list
Output:
  deletes the linked list
*/
void FreeMemory(Node * &head)
{

  	while ( head != NULL ) {
      Node * p = head;
	    head= head->next;
	    delete p;
      }
    delete head;
}

/*
  Function: DisplayProfile(string username)
  Input:
    username: Username of the person whose profile is to be displayed
  Output:
    1.Open's the user profile file
    2.Prints the details except the password
*/
void DisplayProfile(string username)
{
  clrscr();
  string temp;
  ifstream name;
  name.open((username+".txt").c_str());//1
  //Executing 2
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

  Pause();

}

/*
  Function: Push(string name, Node * head)
  Input:
    name: the name of the user to be added to the stack
    head: the current memory location for head
  Output:
    Pushes the string username to the stack whose head it receives
*/

Node* Push(string name, Node * head)
{
  Node* temp= new Node;
  temp->uName=name;
  temp->next=head;
  head=temp;
  return head;//for continuing the linked list the head is return
}

/*
  Function: Display(Node* head)
  Input:
    head: the current memory location for head
  Output:
    1. Traverses the linked list and displays it
    2. Enter choice for whose profile to display
    3.The DisplayProfile Function is called
*/

void Display(Node* head)
{
  int index=1,choice=0;;
  Node* current=head;
  while(current!=NULL)//traversing the linked list
  {
      cout<<index<<" : "<<current->uName<<endl;//display the menu
      current=current->next;
      ++index;
  }

  index=1;
  cin>>choice;//2
  current =head;
  while(current!=NULL)
  {
      if(index==choice)//the choice the user entered
        DisplayProfile(current->uName);//Displays the profile
        current=current->next;
      ++index;
  }

}
