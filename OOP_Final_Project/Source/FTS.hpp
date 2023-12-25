#include <iostream>
#include <string>
using namespace std;
/*
+---------------------+        +---------------------+
|   FitnessTracker   |        |      Activity       |
+---------------------+        +---------------------+
| - user_type: string |        | - act_type: int      |
| - user_id: int      |        | - Calories: double  |
| - Username: string  |        | - Gender: int        |
| - activities        |◄-------| - BMR: double        |
+---------------------+        +---------------------+
   |                           | + setAct_type(): void|
   |                           | + setBMR(): double   |
   |                           |
   |                           |
   |                           |
   V                           V
+---------------------+
|       Person        |
+---------------------+
| # Age: int           |
| # hight: int         |
| # weight: int        |
| + SetPerson(): void  |
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
            while (Age <=0)
            {
                cout<<"Invalid input!"<<endl;
                cout<<"Enter Your Age : ";
                cin>>Age;
            }
            
            cout<<"Enter Your Weight : ";
            cin>>weight;
            while (weight <= 2)
            {
                cout<<"Not a Normal Weight Try Again"<<endl;
                cout<<"Enter Your Weight : ";
                cin>>weight;
            }
            
            cout<<"Enter Your Hight : ";
            cin>>hight;
        }
};
class Activity:public Person
{
    private:
        int act_type;
        double Calories;
        int Gender; //1 for men 2 for women|
        double BMR;
    public:
        void setAct_type();
        double setBMR();
        
};
double Activity::setBMR()
{
   do
    {
        cout << "..Choose Your Gender.." << endl;
        puts("1. Male\t\t2.Female\n");
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
            SetPerson();
            BMR = 10*weight+(6.25*hight)-(5*Age)+161; //for women
            break;
            default:
                cout<<"Something Went Wrong):"<<endl;
                break;
    }

    setAct_type();
    switch (act_type)
    {
    case 1:
        return Calories = BMR*1.2; //act1
        break;
    case 2:
        return Calories = BMR*1.2;//act2
        break;
    case 3:
        return Calories = BMR*1.2;//act3
        break;
    case 4:
        return Calories = BMR*1.2;//act4
        break;
    case 5:
        return Calories = BMR*1.2;//act5
        break;
    case 6:
        return Calories = BMR*1.2;//act6
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
    cin.clear();
    cin>>act_type;

};

class FitnessTracker
{
    private:
        string user_type;
        int user_id;
        string Username;
        Activity activities;
        
        
    public:
        void setDtails();
        void Register();
};
void FitnessTracker::setDtails()
{

};
void FitnessTracker::Register()
{
    cout<<"................User Account Creation................"<<endl;
    
};