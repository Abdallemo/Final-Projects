#include "LMS.hpp"
#include <fstream>  


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
int main(){

   // current date and time on the current system
   time_t now = time(0);

   // convert now to string form
   char* date_time = ctime(&now);

   cout << "The current date and time is: " << date_time << endl;

    return 0;
}