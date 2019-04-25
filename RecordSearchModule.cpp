#include "LinkedList.cpp"

void searchName(user pref)
{
    string temp;
    if (pref.name!="")
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

void searchAge(user pref)
{
    if (pref.age!=0)
    {
        ifstream age;
        Node* head=NULL;
        string temp,num;
        age.open("AgeKeyFieldFile.txt");
        while(getline(age, temp))
        {
            num=temp.substr(0,2);
            //implement linked list score system then use following if to cut  off at a certain threshold.
            if ((stoi(num) >= (pref.age-3)) and (stoi(num) <= (pref.age+3)))
            {
                temp.erase(0,3);
                temp.erase((temp.length()-5));
                head=Push(temp,head);
            }
        }
        Display(head);
        age.close();
    }
}

void searchGender(user pref)
{
    ifstream gender;
    Node* head=NULL;
    gender.open("GenderKeyFieldFile.txt");
    string temp;
    while(getline(gender, temp))
    {
        if (temp.substr(0,1)==pref.gender)
            {
                temp=temp.substr(2);
                temp=temp.substr(0,temp.length()-5);
                head=Push(temp,head);
            }
    }
    Display(head);
    gender.close();
}

void searchHall(user pref)
{
    ifstream hall;
    Node* head=NULL;
    hall.open("HallKeyFieldFile.txt");
    string temp, name;
    while(getline(hall, temp))
    {
        name=temp.substr(0,temp.find(" "));
        if (name==pref.hall)
        {
            temp=temp.substr((temp.find(" ")+1));
            temp=temp.substr(0,temp.length()-5);
            head=Push(temp,head);
        }
    }
    Display(head);
    hall.close();
}
void SearchMenu()
{
    user pref;
    cout<<"Search criteria\n";
    int choice=0;
    cout<<"1. Name\n";
    cout<<"2. Age \n";
    cout<<"3. Gender \n";
    cout<<"4. Hall\n";
    cin>>choice;
    switch(choice){

      case 1:{
        cin>>pref.name;
        searchName(pref);
        break;
      }
      case 2:{
        cin>>pref.age;
        searchAge(pref);
        break;
      }
      case 3:{
        cin>>pref.gender;
        searchGender(pref);
        break;
      }
      case 4:{
        cin>>pref.hall;
        searchHall(pref);
      }
    }

}
