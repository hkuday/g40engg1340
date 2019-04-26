//Pre-processor directives
#include "LinkedList.cpp"

/*
  Function: searchName(user pref)
  Input:
    pref: only for recording the prefernce against which the function will be run
  Output:
    1.Checks whether the user input is Valid
    2.Calls the Display Function corresponding to the prefernce
*/
void searchName(user pref)
{
    string temp;
    if (pref.name!="")//1
    {
        ifstream name;
        name.open((pref.name+".txt").c_str());
        if (name.is_open())
        {
            DisplayProfile(pref.name);
            name.close();
        }
        else
        {
            cout<<"User does not exist\n";
        }
    }
}

/*
  Function: searchAge(user pref)
  Input:
    pref: only for recording the prefernce against which the function will be run
  Output:
    1.Opens the AgeKeyFieldFile if user input is valid
    2.Read the file line by line
    3.Extract the required information (the age)
    4.Check criteria
    5.If matches push to linked list
*/
Node* searchAge(user pref)
{
    Node* head=NULL;//initiating the head for linked list
    if (pref.age!=0)//1
    {
        ifstream age;
        string temp,num;
        age.open("AgeKeyFieldFile.txt");
        while(getline(age, temp))//2
        {
            num=temp.substr(0,2);//3
            //implement linked list score system then use following if to cut  off at a certain threshold.
            if ((stoi(num) >= (pref.age-3)) and (stoi(num) <= (pref.age+3)))//4
            {
                temp.erase(0,3);
                temp.erase((temp.length()-4));
                head=Push(temp,head);//5
                head->score=abs((6*(stoi(num)-pref.age)/3));
            }
        }
        age.close();
    }
    return head;
}

/*
  Function: searchGender(user pref)
  Input:
    pref: only for recording the prefernce against which the function will be run
  Output:
    1.Opens the GenderKeyFieldFile if user input is valid
    2.Read the file line by line
    3.Extract the required information (the gender)
    4.Check criteria
    5.If matches push to linked list
*/

Node * searchGender(user pref)
{
    ifstream gender;
    Node* head=NULL;//initiating the head for linked list
    gender.open("GenderKeyFieldFile.txt");//1
    string temp;
    while(getline(gender, temp))//2
    {
        if (temp.substr(0,1)==pref.gender)//3 and 4
            {
                temp=temp.substr(2);
                temp=temp.substr(0,temp.length()-4);
                head=Push(temp,head);//5
                head->score=6;
            }
    }
    gender.close();
    return head;
}

/*
  Function: searchHall(user pref)
  Input:
    pref: only for recording the prefernce against which the function will be run
  Output:
    1.Opens the HallKeyFieldFile if user input is valid
    2.Read the file line by line
    3.Extract the required information (the hall)
    4.Check criteria
    5.If matches push to linked list
*/

Node * searchHall(user pref)
{
    ifstream hall;
    Node* head=NULL;//initiating the head for linked list
    hall.open("HallKeyFieldFile.txt");//1
    string temp, name;
    while(getline(hall, temp))//2
    {
        name=temp.substr(0,temp.find(" "));
        if (name==pref.hall)//3 and 4
        {
            temp=temp.substr((temp.find(" ")+1));
            temp=temp.substr(0,temp.length()-5);
            head=Push(temp,head);//5
            head->score=6;
        }
    }
    hall.close();
    return head;
}

/*
  Function: Search Menu()
  Input: none
  Output:
    1.The search criteria are displayed
    2.User enters the choice
    3.Accordingly the corresponding function is called
*/
void SearchMenu()
{
    user pref;//the object just stores the preference
    Node * head=NULL;
    cout<<"Search criteria\n";
    int choice=0;
    cout<<"1. Name\n";
    cout<<"2. Age \n";
    cout<<"3. Gender \n";
    cout<<"4. Hall\n";
    cin>>choice;//enter choice
    switch(choice){

      case 1:{
        cin>>pref.name;
        searchName(pref);
        break;
      }
      case 2:{
        cin>>pref.age;
        head=searchAge(pref);
        break;
      }
      case 3:{
        cin>>pref.gender;
        head=searchGender(pref);
        break;
      }
      case 4:{
        cin>>pref.hall;
        head=searchHall(pref);
      }
    }
    if(head!=NULL)
      Display(head);
    head=NULL;
}
