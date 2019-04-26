#include "RecordSearchModule.cpp"
#include "LinkedList.cpp"
Node* addLink(Node * head, Node * newList,)
{
  Node* temp= new Node;
  temp->uName=newList.uName;
  temp->score=newList.score;
  temp->next=head;
  head=temp;
  return head;//for continuing the linked list the head is return
}
void FigureRecommendations()
{
  user temp;
  Node * head1=NULL,* head2=NULL,* head3=NULL, * subSet1=NULL, * subSet2=NULL;
  temp.name="";
  cout<<"Enter the gender you are looking for: \n";
  cin>>temp.gender;
  cout<<"Enter the age of the person you are looking for:  \n";
  cin>>temp.age;
  cout<<"Do you have a hall preference? \n";
  cin>>temp.hall;

  cin>>temp.age;
  head1=searchAge(pref);

  cin>>temp.gender;
  head2=searchGender(pref);

  cin>>temp.hall;
  head3=searchHall(pref);

  while (head2!=NULL)
  {
    while(head1!=NULL)
    {
      if (head2.uName==head1.uName)
      {
        subSet1=addLink(subSet1, head1.uName);
      }
      head1=head1.next;
    }
    while(head3!=NULL)
    {
      if (head2.uName==head3.uName)
      {
        subSet2=addLink(subSet2, head3.uName);
      }
      head3=head3.next;
    }
    head2=head2.next;
  }


    while(subSet1!=NULL)
    {
      while(subSet2!=NULL)
      {
        if (subSet1==subSet2)
        {
          subSet1.score=subSet1.score+subSet2.score;
        }
      }
    }
    Display(subset1);
}
