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
        3 different input validation
        User-friendly interface
        Correct Input
        Correct Output

*/
struct ThesisRecord
{
    StudentRecord Records; //an strcut from student record that contains all data called linklist&struct
    struct ThesisRecord *next;
};

typedef struct ThesisRecord *Thesis_RecordPtr;
int ThesisIDCounter = 1000;//this is for Automtic generate An Thesis_ID
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
void Instruction();
void getInput(const char *prompt, char *input, int max_length);
void convertToUpper(char *str);


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
void getInput(const char *prompt, char *input, int max_length)
{
    printf("%s: ", prompt);
    fgets(input, max_length, stdin);
    input[strcspn(input, "\n")] = '\0';
}

void convertToUpper(char *str) {
    while (*str) {
        *str = toupper((unsigned char)*str);
        str++;
    }
}
void generateThesisID(StudentRecord *record)
{
    sprintf(record->Thesis_ID, "T%04d", ThesisIDCounter++);

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
void bubbleSortByName(Thesis_RecordPtr *head) {
    int swapped;
    Thesis_RecordPtr current;
    Thesis_RecordPtr last = NULL;

    // Base case: empty or single-node list
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }

    do {
        swapped = 0;
        current = *head;

        while (current->next != last) {
            // Compare adjacent nodes and swap if needed based on Student_Name
            if (strcmp(current->Records.Student_Name, current->next->Records.Student_Name) > 0) {
                swapNodes(current, current->next);
                swapped = 1;
            }
            current = current->next;
        }
        last = current;

    } while (swapped);
}
void swapNodes(Thesis_RecordPtr a, Thesis_RecordPtr b) {
    StudentRecord temp = a->Records;
    a->Records = b->Records;
    b->Records = temp;
}