
#include <fstream>  
#include <Windows.h>
#include "animation.hpp"
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

*/
int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    FtsList FitnesList;
    FitnessTracker FTStracker;
 int ch;
 string Targetuser;
    
    cout << "1. Start the App\n2. Exit the App" << endl;
    cout << "Enter (1) or (2): ";
    cin.clear();
    cin >> ch;
    progressbar();

    while (ch != 2) {
        switch (FTStracker.SetType()) {
            case 'A':
                int adminChoice;
                do {
                    cout<<"\n"<<endl;
                    system("COLOR 5E");
                    cout << "1. Set Your Information \t\t2. Delete Existing User info" << endl;
                    cout << "3. Update Existing User info \t 4. Generate text Base for All user info" << endl;
                    cout << "5. Display All Users Info \t 6.Search Existing User info" << endl;
                    cout<<"7.Exit"<<endl;
                    cout << "Enter (1-7): ";
                    cin.clear();
                    cin >> adminChoice;

                    switch (adminChoice) 
                    {
                        case 1:

                            FTStracker.Register();
                            FTStracker.setDtails();
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
                    system("COLOR 6F");
                    cout << "1. Set Your Information \t\t2. Delete Your Information" << endl;
                    cin.clear();
                    cin>>user_Choice;
                    switch (user_Choice)
                    {
                    case 1:
                        FTStracker.Register();
                        break;
                    
                    default:
                        break;
                    }
                } while (use_facet !=3 );
                
               
                cout << "User Type" << endl;
                break;
            default:
                cout << "Error. Try Again" << endl;
                break;
        }

        cout << "1. Start the App\n2. Exit the App" << endl;
        cout << "Enter (1) or (2): ";
        cin.clear();
        cin >> ch;
        progressbar();
    }

    return 0;
}