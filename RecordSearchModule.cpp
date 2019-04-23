#include <iostream>
#include <fstream>
using namespace std;
struct recommendations
{
    string name="";
    int age=0;
    string gender="";
    string hall="";
};

void searchName(recommendations pref)
{
    string temp;
    if (pref.name!="")
    {
        ifstream name;
        name.open((pref.name+".txt").c_str());
        if (name.is_open())
        {
            name>>temp;
            name>>temp;
            cout<<pref.name<<"'s gender is "<<temp<<endl;
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
        else
        {
            cout<<"User does not exist\n";
        }
    }
}
void searchAge(recommendations pref)
{
    if (pref.age!=0)
    {
        ifstream age;
        string temp,num;
        age.open("AgeKeyFieldFile.txt");
        while(getline(age, temp))
        {
            num=temp.substr(0,2);
            //implement linked list score system then use following if to cut  off at a certain threshold.
            if ((stoi(num) >= (pref.age-3)) and (stoi(num) <= (pref.age+3)))
            {
                temp.erase(0,3);
                temp.erase((temp.length()-4));
                cout<<temp<<endl;
            }
        }
        age.close();
    }
}
void searchGender(recommendations pref)
{
    ifstream gender;
    gender.open("GenderKeyFieldFile.txt");
    string temp;
    while(getline(gender, temp))
    {
        if (temp.substr(0,1)==pref.gender)
            {
                temp=temp.substr(2);
                temp=temp.substr(0,temp.length()-4);
                cout<<temp<<endl;
            }
    }
}
void searchHall(recommendations pref)
{
    ifstream hall;
    hall.open("HallKeyFieldFile.txt");
    string temp, name;
    while(getline(hall, temp))
    {
        name=temp.substr(0,temp.find(" "));
        if (name==pref.hall)
        {
            temp=temp.substr((temp.find(" ")+1));
            temp=temp.substr(0,temp.length()-4);
            cout<<temp<<endl;
        }
    }
}
int main()
{
    recommendations pref;
    cout<<"Search criteria\n";
    cout<<"Name (leave blank if none)\n";
    cin>>pref.name;
    cout<<"Age (leave blank if none)\n";
    cin>>pref.age;
    cout<<"Gender (leave blank if none)\n";
    cin>>pref.gender;
    cout<<"Hall (leave blank if none)\n";
    cin>>pref.hall;
    ///////////////////////////////////////////////////////////////////////////////////
    searchName(pref);
    //////////////////////////////////////////////////////////////////////////////
    searchAge(pref);
    ////////////////////////////////////////////////////////////////////////
    searchGender(pref);
    //////////////////////////////////////////////////////////////////
    searchHall(pref);
}
