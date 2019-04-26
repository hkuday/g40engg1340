//#include "RecordSearchModule.cpp"
Node* addLink(Node * head, Node * newList)
{
  Node* temp= new Node;
  temp->uName=newList->uName;
  temp->score=temp->score+newList->score;
  temp->next=head;
  head=temp;
  return head;//for continuing the linked list the head is return
}
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
  head1=searchAge(temp);

  head2=searchGender(temp);

  head3=searchHall(temp);

  while (head2!=NULL)
  {
    temp1=head1;
    while(temp1!=NULL)
    {
      if (head2->uName==temp1->uName)
      {
        subSet1=addLink(subSet1, temp1);
      }
      temp1=temp1->next;
    }
    temp3=head3;
    while(temp3!=NULL)
    {
      if (head2->uName==temp3->uName)
      {
        subSet2=addLink(subSet2, temp3);
      }
      temp3=temp3->next;
    }
    head2=head2->next;
  }
  //Display(subSet1);
  //Display(subSet2);


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
    cout<<"End";

}
