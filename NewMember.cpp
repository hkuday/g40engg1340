#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
bool access=false;
//Takes in user's input data
//checks if user exists or not
//If not exist then make new account and input  more data
//if exist check password and allow access
void makeAccount(string username)
{
    ofstream user;
    user.open(username.c_str());
    ofstream ageKey, genderKey, hallKey;
    ageKey.open("AgeKeyFieldFile.txt", ios::app);
    genderKey.open("GenderKeyFieldFile.txt", ios::app);
    hallKey.open("HallKeyFieldFile.txt", ios::app);
    string password,retypePassword, temp;
    while(true)
    {
        cout<<"Enter password"<<endl;
        cin>>password;
        cout<<"Re-Enter password"<<endl;
        cin>>retypePassword;
        if (password==retypePassword)
            break;
        else
            cout<<"Passwords do not match"<<endl;
    }
    user<<password<<endl;
    cout<<"What is your gender M/F\n";
    cin>>temp;
    user<<temp<<endl;
    // update KeyFieldFiles
    genderKey<<temp<<" "<<username<<endl;
    cout<<"What is your age\n";
    cin>>temp;
    user<<temp<<endl;
    // update KeyFieldFiles
    ageKey<<temp<<" "<<username<<endl;
    cout<<"What is your year of study\n";
    cin>>temp;
    user<<temp<<endl;
    cout<<"What is your faculty\n";
    cin>>temp;
    user<<temp<<endl;
    cout<<"What is your hall of residence\n";
    cin>>temp;
    user<<temp<<endl;
    // update KeyFieldFiles
    hallKey<<temp<<" "<<username<<endl;
}
int main()
{
    string username;
    cin>>username;
    username=username+".txt";
    ifstream user;
    user.open(username.c_str());
    if (!user.is_open())
    {
        cout<<"User doesnot exist pls try again\n";
        cout<<"Make new account Y/N\n";
        string choice;
        cin>>choice;
        if (choice=="Y")
        {
            makeAccount(username);
        }
        else if (choice=="N")
        {
            cout<<"New account canceled\n";
        }

    }
    else
    {
        string inputPassword, actualPassword;
        cout<<"please enter password\n";
        user>>actualPassword;
        cin>>inputPassword;
        if (!(actualPassword==inputPassword))
        {
            cout<<"Password incorrect\n";
        }
        else
        {
            cout<<"Password accepted\n";
            access=true;
        }
    }
}
