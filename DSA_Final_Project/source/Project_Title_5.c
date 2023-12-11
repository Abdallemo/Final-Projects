#include <stdio.h>
#include <string.h>
#include "studentRecord.h"
struct ThesisRecord
{
    studentRecord Record; 
    struct ThesisRecord *next;
};
