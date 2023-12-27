#include "FTS.hpp"

/*
    *methods needed in this **
    Search()
    Display()
    //Update()
    //Delete()
    //Add()
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
        void Delete(string Targetusr);
        void Search();
        void sort();
        void Update(string Targetusr ,string);
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
void FtsList::Delete(string Targetusr)
{
    if(Isempty()==0)
    {
        cout<<"There Is No Data Yet.."<<endl;

    }
    FtsRecord *currnt_record = head;
    FtsRecord *previous_record = nullptr;
    // so here is Traverse the list to find the node to delete
    while (currnt_record != nullptr && currnt_record->trckerapp.Username != Targetusr)
    {
        previous_record = currnt_record;
        currnt_record = currnt_record->Nextptr;
    }
    if(currnt_record != nullptr)
    {
        if(previous_record==nullptr)
        {
            head = currnt_record->Nextptr;
        }else
        {
            previous_record->Nextptr = currnt_record->Nextptr;
        }
        delete currnt_record;
        cout<<"User "<< Targetusr<<" deleted successfully.."<<endl;
        
    }else
    {
        cout<<"User "<<Targetusr<<" not found."<<endl;
    }
    
    
}
void FtsList::generateReport()
{
    FtsRecord *temp = new FtsRecord;
    if (temp==nullptr)
    {
        cout<<"Nothing To Generate Here"<<endl;

    }else
    {
        while(temp!=nullptr)
        {
            
        }
    }

};