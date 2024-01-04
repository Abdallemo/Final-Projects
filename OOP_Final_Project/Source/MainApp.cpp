
#include <fstream>  
#include <Windows.h>
//#include "animation.hpp"
#include "Linklist(FTS).hpp"
#include <ctime>
using namespace std;
/*
participants: Fahad , Abdikarin , marian & abdullahi
 ______________________________________________________________________________________________________
|1- Demonstrate the following methods with records of objects: create and insert new object,           |
|remove existing object, search object, update object, and display object(s). (A3, 16 marks)           |
|                                                                                                      |
|2- Be logical in the design of the solution – implement at least 3 classes including main() class,    |
|apply inheritance, create linked list of objects or array of objects, input validation (C4, 10        |
|marks)                                                                                                |
|                                                                                                      |
|3- Implement tasks to manipulate records in producing meaningful output – (e.g. apply                 |
|searching and/or sorting to generate reports, perform calculation and others) (P4, 14 marks)          |
|                                                                                                      |
|4- Submit the project report on week 13. Presentation will be scheduled in week 14. The cover         |
|page shall contain UTHM logo, project title, names and matric no of all project members.              |
|______________________________________________________________________________________________________|

                    the main driver needs to be able to read write to a .txt file using librr ofstream 
                    wtring to a file Exmaple : ofstream MyFile("filename.txt");
                    reading from a file Exmaple : ifstream MyReadFile("filename.txt"); Reff: https://rb.gy/eh3dqi
                    project inspirtion from : https://mohap.gov.ae/en/more/awareness-center/calories-calculation (UAE ministry of health and prevention)

*/
int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));//to use window time to generte randomatic number/Alphapets
    FtsList FitnesList;
    FitnessTracker FTStracker;
 int ch;
 string Targetuser;
    puts("\n\t\t\tFITNESS\n\n\t\t\tTRACKER\n\n\t\t\tPROJECT\n");
    puts("\nMADE BY : GR14");
    Sleep(1900);
    system("CLS");
    cout << "\n\t\t1. START THE APP\n\n\t\t2. EXIT THE APP\n" << endl;
    cout << "ENTER (1) OR (2): ";
    cin.clear();
    cin >> ch;
    while(cin.fail()||ch<1||ch > 2)
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid input! Enter (1) or (2): ";
        cin >> ch;
    }
    progressbar();
    while (ch == 1) {

        switch (FTStracker.SetType()) {
            case 'A':
                int adminChoice;
                do {
                    cout<<"\n"<<endl;
                    system("COLOR d0");
                    cout<<"................................Menu.........................................."<<endl;
                    cout << "1. Set Your Information \t 2. Delete Existing User info" << endl;
                    cout << "3. Update Existing User info \t 4. Generate text Base for All user info" << endl;
                    cout << "5. Display All Users Info \t 6.Search Existing User info" << endl;
                    cout << "7. Exit"<<endl;
                    puts("..............................................................................");
                    cout << "Enter (1-7): ";
                    cin.clear();
                    cin >> adminChoice;

                    while(cin.fail()||adminChoice <1 || adminChoice > 7)
                    {
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        cout << "Invalid choice. Enter (1-7): ";
                        cin >> adminChoice;
                    }

                    switch (adminChoice) 
                    {
                        case 1:
                            FTStracker.Register();
                            FTStracker.setDtails();
                            cin.clear();
                            cout<<"Your Auto Generted ID : "<<FTStracker.activities.Uniqueid<<endl;
                            FitnesList.insert(FTStracker);
                            break;
                        case 2:
                            cout<<"Enter The UserName To delete: ";
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            getline(cin,Targetuser);
                            FitnesList.Delete(Targetuser);
                            break;
                        case 3:
                            cout<<"Enter The UserName To Update: ";
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            getline(cin,Targetuser);
                            FitnesList.Update(Targetuser);
                            break;
                        case 4:
                            FitnesList.generateReport();
                            break;
                        case 5:
                            FitnesList.sort();
                            break;
                        case 6:
                            cout<<"Enter The UserName To Search: ";
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            getline(cin,Targetuser);
                            FitnesList.Search(Targetuser);
                            break;
                        case 7:
                            system("cls");
                            break;
                        default:
                            cout << "Invalid choice. Try again." << endl;
                            break;
                    }
                } while (adminChoice != 7);
                break;
            case 'U':
                int user_Choice;
                
                do
                {
                    system("Color b0");
                    puts("\n\n");
                    puts("..............................................................................");
                    cout << "\t\t1. BMR & Calories Calculation \t\t2.Exit" << endl;
                    cout << "\nchoose (1)or(2) : ";
                    cin.clear();
                    cin>>user_Choice;
                    switch (user_Choice)
                    {
                    case 1:
                        FTStracker.setDtails();
                        puts("....................................Result....................................");
                        puts("");
                        cout<<"Your BMR : "<<FTStracker.activities.GetBMR()<<endl;
                        cout<<"Your Calories : "<<FTStracker.activities.getCalories()<<endl;
                        puts("..............................................................................");
                        break;
                    case 2:
                        system("cls");
                        break;
                    default:
                        break;
                    }
                } while (user_Choice != 2);

            default:
                break;
        }

        cout << "\n\t\t1. START THE APP\n\n\t\t2. EXIT THE APP\n" << endl;
        cout << "ENTER (1) OR (2): ";
        cin >> ch;
        while(cin.fail()||ch<1||ch > 2)
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid input! Enter (1) or (2): ";
            cin >> ch;

        }
        progressbar();
    }
    return 0;
}