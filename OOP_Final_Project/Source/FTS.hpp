#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include<cstdlib>



#include<bits/stdc++.h>//for lowecse the usename so that we can sort them 
using namespace std;
#define SZ 40
/*
+---------------------+        +---------------------+         +---------------------+
|   FitnessTracker   |        |      Activity       |         |       Person        |
+---------------------+        +---------------------+         +---------------------+
| - user_type: int    |        | - act_type: int      |         | - Age: int           |
| - user_id: string   |        | - Calories: double  |         | - hight: int         |
| - Username: string  |◄-------| - Gender: int        |         | - weight: int        |
| - activities        |        | - BMR: double        |         +---------------------+
+---------------------+        +---------------------+                 |
   |                           | + setAct_type(): void|                 |
   |                           | + setBMR(): double   |                 |
   |                           | + GetBMR(): void     |                 |
   |                           | + GetPersonData(): void                 |
   |                           | + generateUniqueID(): string            |
   V                           V                                        |
+---------------------+        +---------------------+                 |
|       Person        |        |      FitnessTracker  |                 |
+---------------------+        +---------------------+                 |
| + SetPerson(): void |        | - user_type: int    |                 |
+---------------------+        | - user_id: string   |                 |
                               | - activities: Activity|                 |
                               +---------------------+                 |
                               | + SetType(): char    |                 |
                               | + setDtails(): void  |                 |
                               | + Register(string): void              |
                               | + GetDetails(): void |                 |
                               +---------------------+ 


avtivities :
         (little or no exercise) BMR x 1.2
         (light exercise/sports 1-3 days​/week)BMR x 1.375
         (moderate exercise/sports 3-5 days/week)BMR x 1.55
          (hard exercise/sports 6-7 days a week)BMR x 1.725
          (very hard exercise/sports & physical job or 2x training)BMR x 1.9

*/
class Person
{
    protected:
        int Age;
        int hight;
        int weight;
    public:
        void SetPerson()
        {
            cout<<"Enter Your Age : ";
            cin>>Age;
            cin.ignore();
            while (Age <=0)
            {
                cout<<"Invalid input!"<<endl;
                cout<<"Enter Your Age : ";

                cin>>Age;
                cin.ignore();
            }
            
            cout<<"Enter Your Weight : ";
            cin>>weight;
            while (weight <= 2)
            {
                cout<<"Not a Normal Weight Try Again"<<endl;
                cout<<"Enter Your Weight : ";

                cin>>weight;
                cin.ignore();
            }
            
            cout<<"Enter Your Hight : ";
            cin>>hight;
            cin.ignore();
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
class Activity:public Person
{
    protected:
        int act_type;
        double Calories;
        int Gender; //1 for men 2 for women|
        double BMR;
        char alphabet[SZ]={"ABCDEFGHIJKLMNO"};

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
    }
}

void Activity::GetPersonData()
{
    cout<<"|Age : "<<Age<<"|"<<endl;
    cout<<"|Height : "<<hight<<"|"<<endl;
    cout<<"|Weight : "<<weight<<"|"<<endl;
};

string Activity::generateUniqueID()//this is for Random creation Number 
{
    static int counter = 10;
    char randomAlphabet = alphabet[rand() % (sizeof(alphabet) - 1)];
    int randomNumber = counter++;
    return string(1, randomAlphabet) + to_string(randomNumber);
}

double Activity::setBMR()
{
   do
    {
        cout << "..Choose Your Gender.." << endl;
        cout<<"1. Male\t\t2.Female"<<endl;
        cout<<"Enter Your Choice : ";
        cin.clear();
        cin >> Gender;
    } while (Gender != 1 && Gender != 2);

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
        Activity::Uniqueid = string(1, alphabet[7]) + generateUniqueID();//same as other
        return Calories = BMR*1.9;//act5
        break;
    default:
        cout<<"InValid Choice Number to enter is b/w 1-6 "<<endl;
        break;
    }
    
};
void Activity::setAct_type()
{
    cout<<"...............................which Activities You Do ..............................."<<endl;
    puts("1.sedentary (little or no exercise)");
    puts("2.lightly active (light exercise/sports 1-3 days/week)");
    puts("3.moderately active (moderate exercise/sports 3-5 days/week)");
    puts("4.very active (hard exercise/sports 6-7 days a week) :");
    puts("5.extra active (very hard exercise/sports & physical job or 2x training)");
    cout<<"Choose (1-5) : ";
    cin>>act_type;
    cin.ignore();

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
char FitnessTracker::SetType()
{
    cout<<"................Login Type................"<<endl;
    puts("1.administrator Account Type");
    puts("2.User Account Type");
    cout<<"Choose (1) Or (2) : ";
    cin>>user_type;
    cin.ignore();
    while(user_type != 1 && user_type != 2)
    {
        cout<<"     Error!!   "<<endl;
        cout<<"("<<user_type<<")"<<"Not in the List "<<endl;
        puts("1.administrator Account Type");
        puts("2.User Account Type");
        cout<<"Choose (1) Or (2) : ";
        cin>>user_type;
        cin.ignore();
        
    }
    switch (user_type)//here is when we deciding b/w user or admin
    {
    case 1:
        return 'A';
        break;
    case 2:
        return 'U';
        break;
    
    default:
        cout<<"Something Went Wrong!!"<<endl;
        break;
    }
};

void FitnessTracker::setDtails()
{
    activities.setBMR();
};
void FitnessTracker::Register()
{
    cout<<"................User Account Creation................"<<endl;
    cout<<"Enter UserName : ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(cin,Username);
    transform(Username.begin(), Username.end(), Username.begin(), ::tolower); //ref. https://en.cppreference.com/w/cpp/string/wide/towlower
    //?sorting is alphapetic sensitive so we convert username to lowercase
    

};
void FitnessTracker::GetDetails()
{

    cout<<"...............User Data............... "<<endl;
    cout<<"|Username : @"<<Username<<""<<endl;
    cout<<"|User Id : "<<activities.Uniqueid<<""<<endl;
    activities.GetPersonData();
    cout<<"|User BMR : "<<activities.GetBMR()<<""<<endl;
    cout<<"|Calories Burned : "<<activities.getCalories()<<""<<endl;
    cout<<"|______________________________________________"<<endl;
    
};

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