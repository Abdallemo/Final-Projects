#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <limits>
#include<cstdlib>
#include<bits/stdc++.h>//for lowecse the usename so that we can sort them 
using namespace std;
#define SZ 40
class Person
{
    protected:
        int Age;
        int hight;
        int weight;
    public:
            /*
            *****************************************************************
                        Set User's Age, Weight, And Height.                 *
            *****************************************************************
            */
        void SetPerson()
        {
            cout<<"Enter Your Age : ";
            cin>>Age;
            while (cin.fail()|| Age <=0)//cin.fail() is to insure misbehaviour
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout<<"Invalid input!"<<endl;
                cout<<"Enter Your Age : ";
                cin>>Age;
            }//looping until user inputs a correct or valid number✨
            
            cout<<"Enter Your Weight : ";
            cin>>weight;
            while (cin.fail()||weight <= 2 || weight >= 220)
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout<<"Not a Normal Weight Try Again"<<endl;
                cout<<"Enter Your Weight (kg) : ";
                cin>>weight;
            }//looping until user inputs a correct or valid number✨
            
            cout<<"Enter Your Hight : ";
            cin>>hight;
            while(cin.fail()||hight <=43 || hight >= 251)
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout<<hight<<" Is Invalid Height Try Again"<<endl;
                cout<<"Enter Your Hight(cm) : ";
                cin>>hight;
            }//looping until user inputs a correct or valid number✨
        }
        //getterts :)
        int getAge()const
        {
            return Age;
        }
        int getHeight()const
        {
            return hight;
        }
        int getWeight()const
        {
            return weight;
        }
};
//____________________________________________________________________________________________________________
class Activity:public Person //Now class is a child of class Person🎗️
{
    protected:
        int act_type;
        double Calories;
        int Gender; //1 for men👲 2 for women🙍‍♀️|
        double BMR;
        char alphabet[SZ]={"ABCDEFGHIJKLMNO"};//here a Random alphptic we'll use it for generaing ids 

    public:
        string Uniqueid;
        void setAct_type();
        double setBMR();
        double GetBMR()const;
        void GetPersonData();
        string generateUniqueID();
        double getCalories()const;
        string getGender();
};
/*
            *****************************************************************
                       Get user's gender as a string.     .                 *
            *****************************************************************
*/
string Activity::getGender()
{
    switch(Gender)
    {
        case 1:
            return "Male";
            break;
        case 2:
            return "Female";
            break;
        default:
            return "Unknown";
    }
};
/*
            *****************************************************************
                        Display user's age, height, and weight.             *
            *****************************************************************
*/
void Activity::GetPersonData()
{
    cout<<"|Age             : "<<Age<<endl;
    cout<<"|Height          : "<<hight<<endl;
    cout<<"|Weight          : "<<weight<<endl;
}
/*
            *****************************************************************
                       Generate a unique ID for the user                    *
            *****************************************************************
*/
string Activity::generateUniqueID()//this is for Random creation Number 
{
    static int counter = 10;//Id for first Registerer will start from 10
    char randomAlphabet = alphabet[rand() % (sizeof(alphabet) - 1)];// randomAlphabet could now hold any Uppercase letter from A to O in char alphabet[SZ]={"ABCDEFGHIJKLMNO"};
    int randomNumber = counter++;
    return string(1, randomAlphabet) + to_string(randomNumber);
}
/*
            *****************************************************************
                       Set most of user info & set program logic.           *
            *****************************************************************
*/
double Activity::setBMR()
{
 while (true) {
        std::cout << "..Choose Your Gender.." << std::endl;
        std::cout << "1. Male\t\t2. Female" << std::endl; 
        std::cout << "Enter Your Choice : ";
        
        std::cin.clear();  // to clear existing lines
        std::cin >> Gender;

        if (std::cin.fail() || (Gender != 1 && Gender != 2)) {
            std::cin.clear();  // clear the input buffer
            std::cin.ignore(INT_MAX, '\n');  // ignore any remaining characters in the buffer
            std::cout << "Invalid input. Please enter 1 for Male or 2 for Female." << std::endl;
        } else {
            break;  // exit the loop if input is valid
        }
    }

    switch(Gender)
    {
        case 1:
            cout<<"..........BMR Calculation.........."<<endl;
            SetPerson();
            BMR = 10*weight+(6.25*hight)-(5*Age)+5;//for men
            break;
        case 2:
            cout<<"..........BMR Calculation.........."<<endl;
            SetPerson();
            BMR = 10*weight+(6.25*hight)-(5*Age)-161; //for women
            break;
        default:
            cout<<"Something Went Wrong):"<<endl;
            break;
    }
    cout<<endl;
    setAct_type();
    switch (act_type)
    {
    case 1:
        cin.clear();
        Activity::Uniqueid = string(1, alphabet[0]) + generateUniqueID();//if user chosed act1 his ID will start from A
        return Calories = BMR*1.2; //act1
        break;
    case 2:
        cin.clear();
        Activity::Uniqueid = string(1, alphabet[2]) + generateUniqueID();//if user chosed act2 his ID will start from C
        return Calories = BMR*1.375;//act2
        break;
    case 3:
        cin.clear();
        Activity::Uniqueid = string(1, alphabet[5]) + generateUniqueID();//if user chosed act3 his ID will start from F
        return Calories = BMR*1.55;//act3
        break;
    case 4:
        cin.clear();
        Activity::Uniqueid = string(1, alphabet[10]) + generateUniqueID();//if user chosed act4 his ID will start from K
        return Calories = BMR*1.725;//act4
        break;
    case 5:
        cin.clear();
        
        Activity::Uniqueid = string(1, alphabet[3]) + generateUniqueID();//same as other
        return Calories = BMR*1.9;//act5
        break;
    default:
        cout<<"InValid Choice Number to enter is b/w 1-6 "<<endl;
        return 0.0;
        break;
    }
};
/*
            *****************************************************************
                       Set the type of activity.                            *
            *****************************************************************
*/
void Activity::setAct_type()
{
    cout<<"...............................which Activities You Do ..............................."<<endl;
    puts("1.sedentary (little or no exercise)\n");
    Sleep(50);
    puts("2.lightly active (light exercise/sports 1-3 days/week)\n");
    Sleep(50);
    puts("3.moderately active (moderate exercise/sports 3-5 days/week)\n");
    Sleep(50);
    puts("4.very active (hard exercise/sports 6-7 days a week)\n");
    Sleep(50);
    puts("5.extra active (very hard exercise/sports & physical job or 2x training)\n");
    Sleep(50);
    puts(".......................................................................................");
    cout<<"Choose (1-5) : ";
    cin>>act_type;
    while(cin.fail()|| act_type <1 || act_type >5)
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout<<"Invalid choice!! . Choose (1-5) : ";
        cin>>act_type;
    }
};
double Activity::GetBMR()const
{
    return BMR;
};
double Activity::getCalories()const
{
    return Calories;
}
//____________________________________________________________________________________________________________
class FitnessTracker
{
    private:
        int user_type;
        string user_id;
        
    public:
        Activity activities;
        string Username;      
        void setDtails();
        void Register();
        void GetDetails();
        char SetType();
        void generateReport();// :) 
};
/*
            *****************************************************************
                        Set user type as admin or user.                     *
            *****************************************************************
*/
char FitnessTracker::SetType()
{
    cout<<"................Login Type................"<<endl;
    puts("1.administrator Account Type");
    puts("2.User Account Type");
    cout<<"Choose (1) Or (2) : ";
    cin.clear();
    cin>>user_type;
    while(user_type != 1 && user_type != 2&&cin.fail())//cin.fail() used  again misbehaive like if you enter string where to enter a int✨
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout<<"     Error!!   "<<endl;
        cout<<"("<<user_type<<")"<<"Not in the List "<<endl;
        puts("1.administrator Account Type");
        puts("2.User Account Type");
        cout<<"Choose (1) Or (2) : ";
        cin>>user_type;
    }
    switch (user_type)//here is when we deciding b/w user or admin
    {
    case 1:
        return 'A';//A stands for admin
        break;
    case 2:
        return 'U';//U for user
        break;
    default:
        cout<<"Something Went Wrong!!"<<endl;
        return 'E';
        break;
    }
};
/*
            *****************************************************************
                        Set details such as BMR for the user.               *
            *****************************************************************
*/
void FitnessTracker::setDtails()
{
    activities.setBMR();
};

/*
            *****************************************************************
                       Register a user with a username.                     *
            *****************************************************************
*/
void FitnessTracker::Register()
{
    cout<<"................User Account Creation................"<<endl;
    cout<<"Enter UserName : ";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(cin,Username);

    transform(Username.begin(), Username.end(), Username.begin(), ::tolower); //ref. https://en.cppreference.com/w/cpp/string/wide/towlower
    //?sorting is alphapetic sensitive so we convert username to lowercase
};

/*
            *****************************************************************
                        Display user details.                               *
            *****************************************************************
*/
void FitnessTracker::GetDetails()
{
    cout<<"...............User Data............... "<<endl;
    cout<<"|Username        : @"<<Username<<""<<endl;
    cout<<"|User Id         : "<<activities.Uniqueid<<""<<endl;
    cout<<"|User Gender     : "<<activities.getGender()<<""<<endl;
    activities.GetPersonData();
    cout<<"|User BMR        : "<<activities.GetBMR()<<""<<endl;
    cout<<"|Calories Burned : "<<activities.getCalories()<<""<<endl;
    cout<<"|______________________________________________"<<endl;
};
/*
            *****************************************************************
                       generate a report and save to "Report.txt".          *
            *****************************************************************
*/
void FitnessTracker::generateReport()
{
    fstream myFile;
    myFile.open("Report.txt", ios::app);
    if(myFile.is_open())
    {
        myFile <<">>>>>>>>>>>>>>>>>>>>>...........<<<<<<<<<<<<<<<<<<<<<\n";
        myFile << "Username: @" << Username<<"\n";
        myFile << "User ID: " <<  activities.Uniqueid<<"\n";
        myFile << "Age: " <<activities.getAge()<<"\n";
        myFile << "Height: " <<activities.getHeight()<<"\n";
        myFile << "Weight: " <<activities.getWeight()<<"\n";
        myFile << "User BMR: "<<activities.GetBMR()<<"\n";
        myFile << "Calories: "<<activities.getCalories()<<"\n";
        myFile <<".....................................................\n";
    }
}