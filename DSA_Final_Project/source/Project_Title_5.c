#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <malloc.h>
#include "studentRecord.h"
#include <ctype.h>
/*
    Subcriteria:
        Syntax
        Logical

        implementation/process
        insert☑️ delete☑️ travers☑️ search☑️ & sort☑️

        3 different input validation
            1.input Validation line 90
            2.input validation line 114
            3.input validation line 125
            4.input validation line 136
            5.input validation line 252
            6.input validation line 305

        User-friendly interface☑️
        Correct Input☑️
        Correct Output☑️

*/
struct ThesisRecord
{
    StudentRecord Records; //an strcut from student record that contains all data called linklist&struct
    struct ThesisRecord *next;
};

typedef struct ThesisRecord *Thesis_RecordPtr;

/*
 * Global variable to keep track of the Thesis ID counter
 * it Initialized to a starting value of 1000
 */
int ThesisIDCounter = 10;

// Function to generate a unique Thesis_ID for each record
void generateThesisID(StudentRecord *record);

void Insert(Thesis_RecordPtr *head,StudentRecord NewRecord);//FIFO method (First Recorded First on the List)

bool Delete(Thesis_RecordPtr *head, char Target_ID[NID]);

void Display_Info(Thesis_RecordPtr Current_head);

int IsEmpty(Thesis_RecordPtr head);

void UpdateRecord(Thesis_RecordPtr *head,char Target_ID[NID],char NewData[NSize],int fieldToUpdate);//usecase to Update

void search(Thesis_RecordPtr *head,char Target_ID[NID]);

void bubbleSortByName(Thesis_RecordPtr *head);

void swapNodes(Thesis_RecordPtr a, Thesis_RecordPtr b);

void Instruction();//to display the instruction menu for the user

void getInput(const char *prompt, char *input, int max_length);//to get user input with a specified prompt without typing over and over again😌

void convertToUpper(char *str);
void convertToLower(char *str);


int main()
{
    Thesis_RecordPtr strPtr = NULL ;//giving the head of node to be null at the start
    StudentRecord StdRecord;
    int choice;
    char StudentName[NSize];
    char StudentID[NID];
    char StudentEmail[NSize];
    char StudentProgram[NSize];
    char StudentPhone[NID];
    char SupervisoName[NSize];
    char SubmissionDate[NID];
    char Status[NSize];
    char NewData[NSize];

    Instruction();
    scanf("%d",&choice);
    while (getchar() != '\n');  // Clear input buffer
    while(choice != 6)
    {
        switch(choice)
        {
            case 1:
                //**student info  setup

                getInput("\nEnter Student Name", StudentName, NSize);
                strcpy(StdRecord.Student_Name,StudentName);

                convertToLower(StdRecord.Student_Name);

                getInput("\nEnter Student ID", StudentID, NID);
                while (strcmp(StudentID,StdRecord.Student_ID)==0)//1.input Validation 
                {
                    printf("Id %s is Already Registred Please Enter Another One \n",StudentID);
                    getInput("Enter Student ID ", StudentID, NID);
                }
                strcpy(StdRecord.Student_ID,StudentID);

                getInput("\nEnter Program Name", StudentProgram,NID);
                strcpy(StdRecord.Student_Program , StudentProgram);

                getInput("\nEnter Email address", StudentEmail,NSize);
                strcpy(StdRecord.std_info.Email_address , StudentEmail);

                getInput("\nEnter  Phone Number", StudentPhone,NID);
                strcpy(StdRecord.std_info.Phone_Number , StudentPhone);

                getInput("\nEnter Supervisor Name", SupervisoName,NSize);
                strcpy(StdRecord.Supervisor_Name , SupervisoName);

                printf("\n$ The Status List : progress(P), submitted(S), under review(U) $\n");
                getInput("Enter the Thesis Status (use charecters)", Status,NSize);
                convertToUpper(Status);

                //2.input validation in here
               while (strcmp(Status, "P") != 0 && strcmp(Status, "S") != 0 && strcmp(Status, "U") != 0)
                {
                    printf("Wrong Charecters. Please Try Again!\n");
                    printf("\n$ The Status List : progress(P), submitted(S), under review(U) $\n");
                    getInput("Enter the Thesis Status (use charecters)", Status,NSize);
                    convertToUpper(Status);
                }
                //after loop //
                if (strcmp(Status, "P") == 0) 
                {
                    strcpy(Status, "progress");
                } 
                else if (strcmp(Status, "S") == 0) 
                {
                    strcpy(Status, "submitted");
                } 
                else if (strcmp(Status, "U") == 0) 
                {
                    strcpy(Status, "under review");
                } 
                else {
                    printf("Something went wrong!!\n");
                }
                strcpy(StdRecord.Thesis_Status , Status);
                getInput("\nEnter The Submission Date", SubmissionDate,NID);
                strcpy(StdRecord.Submission_Date , SubmissionDate);
                Insert(&strPtr,StdRecord);
                printf("Data For ID %s sucssesfuly Added\n",StdRecord.Student_ID);
            break;

            case 2:
                getInput("Enter ID Remove Existing Student Record",StudentID,NID);
                bool result = Delete(&strPtr,StudentID);
                if (result==true)
                {
                    printf("The Data For ID %s Is sucssesfuly Deleted\n",StudentID);
                }
            break;    

            case 3:
                getInput("Enter ID to Update Existing Student Record", StudentID, NID);
                //input validation to check if the list is empty
                if (strPtr == NULL) 
                {
                    printf("Error: The list is empty. Cannot update.\n");
                    break;
                }
                int fieldToUpdate;
                printf("--------------fields to update:--------------\n");
                printf("1. Student Name\n");
                printf("2. Student ID\n");
                printf("3. Student Program\n");
                printf("Select One field to update(1,2,3): ");
                scanf("%d", &fieldToUpdate);
                    // Clear input buffer
                while (getchar() != '\n');

                if(fieldToUpdate==1){
                    getInput("Enter Student Name", NewData, NID);
                }else if (fieldToUpdate==2)
                {
                    getInput("Enter Student ID", NewData, NID);
                }
                else if (fieldToUpdate==3)
                {
                    getInput("Enter Student Program", NewData, NID);
                }
                UpdateRecord(&strPtr, StudentID, NewData, fieldToUpdate);
            break;    
            case 4:
                getInput("Enter ID to Find Existing Student Record",StudentID,NID);
                search(&strPtr,StudentID);
            break;    
            case 5:
                bubbleSortByName(&strPtr);
                printf("-----------------Displaying All Student Data Recorded-----------------\n");
                Display_Info(strPtr);
            break;    
            case 6:
                exit(0);
            break;
            default:
                printf("There Is No %d In the Available List\n",choice);
            break;    
        }
        Instruction();
        scanf("%d",&choice);
        while (getchar() != '\n');
    }


    return 0;
}

        /*
        *****************************************************************
        Function to insert a new student record into the linked list
        *****************************************************************

        */
void Insert(Thesis_RecordPtr *head, StudentRecord NewRecord)
{
    Thesis_RecordPtr NewRecordptr = (Thesis_RecordPtr)malloc(sizeof(struct ThesisRecord));
    if (NewRecordptr != NULL)
    {
        NewRecordptr->Records = NewRecord;
        generateThesisID(&(NewRecordptr->Records));  // Generate unique Thesis_ID
        NewRecordptr->next = NULL;
        if (*head == NULL)
        {
            *head = NewRecordptr;
        }
        else
        {
            Thesis_RecordPtr current = *head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = NewRecordptr;
        }
    }
    else
    {
        printf("Error! No more memory available\n");
    }
}
        /*
        *****************************************************************
        Boolan type to delete an existing student record from the linked list✨✨
        *****************************************************************
        */
bool Delete(Thesis_RecordPtr *head, char Target_ID[NID]) {
    if (*head == NULL) {
        printf("Nothing To Delete Here\n");
        return false;
    }

    Thesis_RecordPtr current = *head;
    Thesis_RecordPtr prev = NULL;

    
    if (strcmp(current->Records.Student_ID, Target_ID) == 0) {
        *head = current->next;
        free(current);
        return true;
    }

    //**so this Traverse the list to find the node to delete
    while (current != NULL && strcmp(current->Records.Student_ID, Target_ID) != 0) {
        prev = current;
        current = current->next;
    }

    // If the node is found this Function Deletes
    
    if (current != NULL) {
        prev->next = current->next;
        free(current);
        return true;
    } else {
        printf("Student with ID %s not found\n", Target_ID);
        return false;
    }
}

/*

 * Function to update specific fields of an existing student record
 * Parameters:
 * - head: Pointer to the head of the linked list
 * - Target_ID: ID of the student record to be updated
 * - NewData: New data to be updated in the specified field
 * - fieldToUpdate: Field identifier (1 for Student Name, 2 for Student ID, 3 for Student Program)
 *
*/

void UpdateRecord(Thesis_RecordPtr *head, char Target_ID[NID], char NewData[NSize],int fieldToUpdate) {
    Thesis_RecordPtr current = *head;

    while (current != NULL && strcmp(current->Records.Student_ID, Target_ID) != 0) {
        current = current->next;
    }

    if (current != NULL) {
        switch (fieldToUpdate) 
        {
            case 1:
                strcpy(current->Records.Student_Name, NewData);
                printf("-----------------Record with ID %s updated successfully-----------------\n", Target_ID);
                break;
            case 2:
                strcpy(current->Records.Student_ID, NewData);
                printf("-----------------Record with ID %s updated successfully-----------------\n", Target_ID);
                break;
            case 3:
                strcpy(current->Records.Student_Program, NewData);
                printf("-----------------Record with ID %s updated successfully-----------------\n", Target_ID);
                break;
            // 
            default:
                printf("Invalid fieldToUpdate value\n");
        
        } 
    }
    else {
        printf("Student with ID %s not found\n", Target_ID);
    }
}
void Instruction()
{
    puts("-------------------------------------------------------------------");
    puts("              Student Recorder Program:-\n");
    puts("1. To Insert New Student Record");
    puts("2. To Remove Existing Student Record");
    puts("3. To Update Existing Student Record");
    puts("4. To Find Existing Student Record");
    puts("5. To Display All Student Data Recorded");
    puts("6. Exit the App");
    puts("-------------------------------------------------------------------\n");
    printf("Enter Your Choice : ");
}
    /*
    * the function is to search for and display existing information about a specific student record
    * Parameters are :
    * - head: Pointer to the head of the linked list
    * - Target_ID: ID of the student record to be searched
    */
void search(Thesis_RecordPtr *head, char Target_ID[NID]) {
    Thesis_RecordPtr current = *head;

    while (current != NULL && strcmp(current->Records.Student_ID, Target_ID) != 0) {
        current = current->next;
    }

    if (current != NULL) {
        printf("\n");
        printf("-------------Record with ID %s found successfully-------------\n", Target_ID);
        printf("Thesis ID: %s\n", current->Records.Thesis_ID);
        printf("Student Name: %s\n", current->Records.Student_Name);
        printf("Student ID: %s\n", current->Records.Student_ID);
        printf("Student Program: %s\n", current->Records.Student_Program);
        printf("Supervisor Name: %s\n", current->Records.Supervisor_Name);
        printf("Thesis Status: %s\n", current->Records.Thesis_Status);
        printf("Submission Date: %s\n", current->Records.Submission_Date);
        printf("Email: %s\n", current->Records.std_info.Email_address);
        printf("Phone: %s\n", current->Records.std_info.Phone_Number);
        puts("-------------------------------------------------------------------\n");
        printf("\n");
        
    } else {
        printf("Student with ID %s not found\n", Target_ID);
    }
}

/*
 * Function to get user input with a specified prompt
 * Parameters:
 * - prompt: The message prompt to display to the user
 * - input: The buffer to store the user input
 * - max_length: The maximum length of the input buffer
 */

void getInput(const char *prompt, char *input, int max_length)
{
    // Display the prompt message to the use
    printf("%s: ", prompt);
    // Read user input from the standard input :)
    fgets(input, max_length, stdin);

    // Remove the newline character from the input (if present)
    input[strcspn(input, "\n")] = '\0';
}

void convertToUpper(char *str) {
    while (*str) {
        *str = toupper((unsigned char)*str);
        str++;
    }
}
void convertToLower(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

/*
 * Function to generate a unique Thesis ID for each record
 * Parameters:
 * - record: Pointer to the StudentRecord structure to store the generated Thesis ID
 */
void generateThesisID(StudentRecord *record)
{
    // Format the Thesis ID using a template "T%04d" (e.g., T1001)
    sprintf(record->Thesis_ID, "TI%04d", ThesisIDCounter++);
    //!and aslo The counter is incremented for the next Thesis ID so when we record a new student it will be T1002 and so on

}

void Display_Info(Thesis_RecordPtr Current_head)
{
    if (IsEmpty(Current_head))
    {
        puts("-------------------------------------------------------------------\n");
        printf("There Is No Student Record Yet\n");
        puts("-------------------------------------------------------------------\n");

    }else
    {
        while (Current_head != NULL)
        {
            printf("\n");
            printf("Thesis ID: %s\n", Current_head->Records.Thesis_ID);
            printf("Student Name: %s\n", Current_head->Records.Student_Name);
            printf("Student ID: %s\n", Current_head->Records.Student_ID);
            printf("Student Program: %s\n", Current_head->Records.Student_Program);
            printf("Supervisor Name: %s\n", Current_head->Records.Supervisor_Name);
            printf("Thesis Status: %s\n", Current_head->Records.Thesis_Status);
            printf("Submission Date: %s\n", Current_head->Records.Submission_Date);
            printf("Email: %s\n", Current_head->Records.std_info.Email_address);
            printf("Phone: %s\n", Current_head->Records.std_info.Phone_Number);
            puts("-------------------------------------------------------------------\n");
            printf("\n");
            Current_head = Current_head->next;
        }
        
    }
    
    
}
int IsEmpty(Thesis_RecordPtr head)
{
     return head == NULL;
}

/*
 * Function to sort the linked list of student records by name using the bubble sort algorithm
 * Parameters:
 * - head: Pointer to the head of the linked list
 */

void bubbleSortByName(Thesis_RecordPtr *head) {
    int swapped;//to track if any swaps were made
    Thesis_RecordPtr current;// Pointer to the current node 
    Thesis_RecordPtr last = NULL;// Pointer to the last node

    // if empty or single-node list
    if (*head == NULL || (*head)->next == NULL) {
        return;//we dont need to sort
    }

    do {
        swapped = 0;
        current = *head; // we will Start from the head of the list

        while (current->next != last) {
            
            if (strcmp(current->Records.Student_Name, current->next->Records.Student_Name) > 0) 
            {
                swapNodes(current, current->next);// Swap nodes
                swapped = 1;
            }
            current = current->next;// and Move to the next pair of nodes✨🎗️
        }
        last = current;

    } while (swapped);
}

/*
 * Function to swap the data of two nodes in the linked list
 * Parameters:
 * - a: Pointer to the first node
 * - b: Pointer to the second node
 */
void swapNodes(Thesis_RecordPtr a, Thesis_RecordPtr b) {
    StudentRecord temp = a->Records;// Temporary variable to hold data during the swap
    a->Records = b->Records;
    b->Records = temp;
}