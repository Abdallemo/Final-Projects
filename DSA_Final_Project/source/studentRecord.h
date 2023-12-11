#include <stdio.h>
#include <string.h>
#define NSize 100
#define NID 10 

//**this Struct is for info outside the overal thesis record
struct Contact_Information
{
    char Email_address[NSize]; //**for furhter info
    char Phone_Number[NID]; //**Most number in the Word consist 6-10 digits
};
typedef struct Contact_Information info;

struct Student_Record
{
    char Student_Name[NSize];
    char Student_ID[NID];
    char Student_Program[NSize];
    char Supervisor_Name[NSize];
    info std_info;
};
typedef struct Student_Record StudentRecord;



