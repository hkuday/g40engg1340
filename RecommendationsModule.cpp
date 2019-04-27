//#include "RecordSearchModule.cpp"
//Commented out sections using variable score reflect a feature we would like to work on after the completion of our course.

//Copies node pinted to by newlist into a new node and adds it to list pointed to by head
Node* addLink(Node * head, Node * newList)
{
  Node* temp= new Node;
  //int tempScore=(head==NULL)?0:head->score;
  temp->uName=newList->uName;
  //temp->score=tempScore+newList->score;
  temp->next=head;
  head=temp;
  return head;//for continuing the linked list the head is return
}

/*void DisplaySorted(Node * head)
{
  int index=1;
  for (int Oscore=12;Oscore>=0;Oscore--)
  {
    Node *current=head;
    while(current!=NULL)
      {
        if(current->score==Oscore)
          {
            cout<<index<<" . "<<current->uName<<" : "<<current->score<<endl;
            ++index;
          }
        current=current->next;
      }
  }
}
*/

// Outputs a linked list based on the intersection of multiple search criterias
void FigureRecommendations()
{
  user temp;
  Node * head1=NULL,* head2=NULL,* head3=NULL, * subSet1=NULL, * subSet2=NULL, * temp1=NULL, * temp3=NULL, * sub1=NULL, * sub=NULL;
  temp.name="";
  cout<<"Enter the gender you are looking for: \n";
  cin>>temp.gender;
  cout<<"Enter the age of the person you are looking for:  \n";
  cin>>temp.age;
  cout<<"Do you have a hall preference? \n";
  cin>>temp.hall;
  //Getting list of elements from different criterias
  head1=searchAge(temp);

  head2=searchGender(temp);

  head3=searchHall(temp);

  //Display(head1);
  //Display(head2);
  //Display(head3);

  //Carrying out a set intersection operation on age and gender & hall and gender
  while (head2!=NULL)
  {
    temp1=head1;
    while(temp1!=NULL)
    {
      if (head2->uName==temp1->uName)
      {
        subSet1=addLink(subSet1, temp1);
        //cout<<subSet1->uName<<subSet1->score;
      }
      temp1=temp1->next;
    }
    temp3=head3;
    while(temp3!=NULL)
    {
      if (head2->uName==temp3->uName)
      {
        subSet2=addLink(subSet2, temp3);
        //cout<<subSet2->uName<<subSet2->score;
      }
      temp3=temp3->next;
    }
    head2=head2->next;
  }


//Another intersection operation from the two lists produced from previous intersection
    while(subSet1!=NULL)
    {
      sub=subSet2;
      while(sub!=NULL)
      {
        if (subSet1->uName==sub->uName)
        {
          sub1=addLink(sub1, sub);
        }
        sub=sub->next;
      }
      subSet1=subSet1->next;
    }
    //cout<<subSet2->uName;
    Display(sub1);
    FreeMemory(sub1);
    delete head1;
    delete head2;
    delete head3;
    delete subSet1;
    delete subSet2;
    delete temp1;
    delete temp3;
    delete sub;
}
