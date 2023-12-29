
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
    
    cout << "1. Start the App\n2. Exit the App" << endl;
    cout << "Enter (1) or (2): ";
    cin.clear();
    cin >> ch;

    while (ch != 2) {
        switch (FTStracker.SetType()) {
            case 'A':
                cout << "Admin Type" << endl;
                int adminChoice;
                do {
                    cout << "1. Set Your Information\t2. Display All Users Info" << endl;
                    cout << "3. Update Existing User info\t4. Generate text Base for All user info" << endl;
                    cout << "5. Delete Existing User Data\t6. Exit" << endl;
                    cout << "Enter (1-6): ";
                    cin.clear();
                    cin >> adminChoice;

                    switch (adminChoice) {
                        case 1:
                            
                            break;
                        case 2:
                            
                            break;
                        case 3:
                            
                            break;
                        case 4:
                            
                            break;
                        case 5:
                            
                            break;
                        case 6:
                            
                            break;
                        default:
                            cout << "Invalid choice. Try again." << endl;
                            break;
                    }
                } while (adminChoice != 6);
                break;
            case 'U':
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
    }

    return 0;
}