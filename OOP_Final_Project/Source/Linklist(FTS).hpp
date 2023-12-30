#include "FTS.hpp"
#include <Windows.h>
#include  <list>
#include <algorithm>


/*
    *methods needed in this **
    //Search()
    //Display()
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
        void Search(string usr);
        void Update(string TrgtUsr);
        void sort();
        void Display();
        void generateReport();
        int Isempty();
        void progressbar();

FtsList()
{
    head = nullptr; //instrcutor first runs when the main app run so it automticly first head to Null:)
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
    
};
void FtsList::sort()
{
    if(Isempty()==0)
    {
        cout<<"There Is No Data Yet.."<<endl;
        return;//nothing..
    }
    list<FitnessTracker> FTRecords; //so It's a container that can hold instances of FitnessTracker 
    FtsRecord *Temp = head;
    while (Temp!=nullptr)
    {
        FTRecords.push_back(Temp->trckerapp);
        Temp = Temp->Nextptr;
    }
  FTRecords.sort([](const FitnessTracker &a, const FitnessTracker &b) {
        return a.Username < b.Username;
    });
    for (auto& record : FTRecords)
    {
        record.GetDetails();
    }
    
};
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
    
    
};
 void FtsList::Update(string TrgtUsr)
 {
    if(Isempty()==10)
    {
        cout<<"Nothing To Update Here"<<endl;

    }
    FtsRecord *Curr = head;
    while(Curr != nullptr&&Curr->trckerapp.Username!=TrgtUsr)
    {
        Curr= Curr->Nextptr;

    }
    if(Curr!=nullptr)
    {
        cout<<"Displaying Existing Data For "<<TrgtUsr<<" :"<<endl;
        Curr->trckerapp.GetDetails();

        //time to update
        cout<<".....................Update Field....................."<<endl;
        Curr->trckerapp.setDtails();
        progressbar();
        cout << "User " << TrgtUsr << " updated successfully." << endl;

    }else
    {
        cout<<"User with Name "<<TrgtUsr<< " Didn't Found.."<<endl;
    }
 };


void FtsList::generateReport()
{
    FtsRecord *temp = head;
    if (temp==nullptr)
    {
        cout<<"Nothing To Generate Here"<<endl;

    }else
    {
        while(temp!=nullptr)
        {
            temp->trckerapp.generateReport();
            temp = temp->Nextptr;
        }
    }

};
void FtsList::Display()
{
    FtsRecord *Temp = head;
    if(Temp==nullptr)
    {
        cout<<"Nothing To Generate Here"<<endl;

    }else
    {
        while (Temp != nullptr)
        {
            Temp->trckerapp.GetDetails();
            Temp=Temp->Nextptr;

        }
        
    }
}

void FtsList::Search(string usr)
{
    FtsRecord *Temp = head;
    if(Temp==nullptr)
    {
        cout<<"No Data Entered Yet!"<<endl;

    }else
    {
        while (Temp!=nullptr&&Temp->trckerapp.Username != usr)
        {
            Temp = Temp->Nextptr;
        }
        if(Temp != nullptr)
        {
            cout<<"------------- UserName :"<<usr <<"found successfully-------------"<<endl;
            Temp->trckerapp.GetDetails();
            cout<<"....................................................................."<<endl;
        }else
        {
            cout<<"\t\t!"<<endl;
            cout<<"UseName "<<usr<<" Not Found"<<endl;

        }
        
    }

};
void FtsList::progressbar()
{
    system("COLOR 0e");
    system("cls");
    SetConsoleCP(437);
    SetConsoleOutputCP(437);

    int bar1, bar2;
    bar1 = 177;
    bar2 = 219;

    cout << "\n\n\n\t\t\t\tUpdating...";
    cout << "\n\n\n\t\t\t\t";

    for (int i = 0; i < 25; i++)
        cout << (char)bar1;

    cout << "\r";
    cout << "\t\t\t\t";

    for (int i = 0; i < 25; i++) {
        cout << (char)bar2;
        Sleep(50);
    }

    system("cls");
};