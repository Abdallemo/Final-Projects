#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <malloc.h>
#include "studentRecord.h"
struct ThesisRecord
{
    StudentRecord Records; //an strcut from student record that contains all data called linklist&struct
    struct ThesisRecord *next;
};
typedef struct ThesisRecord *Thesis_RecordPtr;
void Insert(Thesis_RecordPtr *head,StudentRecord NewRecord);
bool Delete(Thesis_RecordPtr *head, char Target_ID[NID]);
void Display_Info(Thesis_RecordPtr Current_head);
void IsEmpty(Thesis_RecordPtr head);
void UpdateRecord(Thesis_RecordPtr *head,char Taeget_ID[NID],char NewData[NID]);//usecase to Update
void Instruction();


int main()
{

    return 0;
}

void Insert(Thesis_RecordPtr *head,StudentRecord NewRecord)
{
    Thesis_RecordPtr NewRecordptr = (Thesis_RecordPtr)malloc(sizeof(struct ThesisRecord));
    if(NewRecordptr!=NULL)
    {
        NewRecordptr->Records = NewRecord;
        NewRecordptr->next = NULL;
    
        if(*head == NULL)
        {
            *head = NewRecordptr;
        }else
        {
            Thesis_RecordPtr current = *head;
            while (current->next != NULL)
            {
                current =  current->next;
            }
            current->next=NewRecordptr;
            
        }

    }else {
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
void UpdateRecord(Thesis_RecordPtr *head, char Target_ID[NID], char NewData[NID]) {
    Thesis_RecordPtr current = *head;

    while (current != NULL && strcmp(current->Records.Student_ID, Target_ID) != 0) {
        current = current->next;
    }

    if (current != NULL) {

        strcpy(current->Records.Student_Program, NewData);
        printf("Record with ID %s updated successfully\n", Target_ID);
    } else {
        printf("Student with ID %s not found\n", Target_ID);
    }
}

