#include "FTS.hpp"

/*
    *methods needed in this **
    Search()
    Display()
    Update()
    Delete()
    Add()
    generateReport()

*/

class FtsList
{
    private:
        struct FtsRecord
        {
            FitnessTracker trckerapp;
            FtsRecord *Nextptr;

        };
        FtsRecord *head;
    public:
        void insert(FitnessTracker newtrckerapp);//LIFO Type
        void Delete();
        void Search();
        void sort();
        void Update();
        void Display();
        void generateReport();
        int Isempty();

FtsList()
{
    head == nullptr; //instrcutor first runs when the main app run so it automticly first head to Null:)
}
};
int FtsList::Isempty()
{
    if(head==nullptr)
    {
        return 0;
    }else
    {
        return 1;
    }
    
}

void FtsList::insert(FitnessTracker newtrckerapp)
{
    FtsRecord *newNodeptr = new FtsRecord;
    if (newNodeptr ==nullptr)
    {
        cout<<"Error No More Memory Avaible in The Computer ):"<<endl;
    }else
    {
        newNodeptr->trckerapp = newtrckerapp;
        newNodeptr->Nextptr = head;
        head = newNodeptr;
    }

}
