bool access=false;
//Takes in user's input data
//checks if user exists or not
//If not exist then make new account and input  more data
//if exist check password and allow access
void makeAccount(string username)
{
    ofstream user1;
    user1.open(username.c_str());
    ofstream ageKey, genderKey, hallKey;
    ageKey.open("AgeKeyFieldFile.txt", ios::app);
    genderKey.open("GenderKeyFieldFile.txt", ios::app);
    hallKey.open("HallKeyFieldFile.txt", ios::app);
    string password,retypePassword,temp1;
    user temp;
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
    user1<<password<<endl;
    cout<<"What is your gender M/F : \n";
    cin>>temp.gender;
    user1<<temp.gender<<endl;
    // update KeyFieldFiles: gender
    genderKey<<temp.gender<<" "<<username<<endl;
    cout<<"What is your age : \n";
    cin>>temp.age;
    user1<<temp.age<<endl;
    // update KeyFieldFiles : age
    ageKey<<temp.age<<" "<<username<<endl;
    cout<<"What is your year of study : \n";
    cin>>temp.yearOfStudy;
    user1<<temp.yearOfStudy<<endl;
    cout<<"What is your faculty : \n";
    cin>>temp.faculty;
    user1<<temp.faculty<<endl;
    cout<<"What is your hall of residence : \n";
    cin>>temp.hall;
    user1<<temp.hall<<endl;
    // update KeyFieldFiles
    hallKey<<temp.hall<<" "<<username<<endl;
}
bool AccessControl(string &name)
{
    cout<<"Enter Username : ";
    cin>>name;
    string username=name+".txt";
    ifstream user;
    user.open(username.c_str());
    if (!user.is_open())//Checking whether existing user
    {
        cout<<"User doesnot exist pls try again\n";
        cout<<"Make new account Y/N\n";
        string choice;
        cin>>choice;
        if (choice=="Y")
        {
            makeAccount(username);
            access=true;
        }
        else if (choice=="N")
        {
            cout<<"New account canceled\n";
        }

    }
    else // Existing user then check credentials
    {
        string inputPassword, actualPassword;
        cout<<"Please enter password: \n";
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
    return access;
}
