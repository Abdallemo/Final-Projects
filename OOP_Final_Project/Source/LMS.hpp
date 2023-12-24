#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>  
using namespace std;
#include <ctime>




/*
+------------------------+
|        Customer        |
+------------------------+
| -Name: string          |
| -address: string       |
| -email: string         |
+------------------------+
| +SetName(): void       |
| +SetAddress(): void    |
| +SetEmail(): void      |
| +GetName(): void       |
| +GetAddress(): void    |
| +GetEmail(): void      |
+------------------------+
+------------------------+
|          Book          |
+------------------------+
| -title: string         |
| -author: string        |
| -isbn: string          |
| -categoryName: string  |
| -price: double         |
+------------------------+
| +SetBookInfo(): void   |
| +GetBookInfo(): void   |
+------------------------+

and
+------------------------+
|     BookstoreMgnt      |
+------------------------+
| -Amount: int        |
+------------------------+
| +orderDate(): void     |
+------------------------+


*/

class BookstoreMgnt
{
    private:
        int Amount;
        Book bookinfo;
        Customer customerinfo;


    public:
        void orderDate();
        void SetInfo();

};
void BookstoreMgnt::SetInfo()
{
    cout<<"....................................Welcome To Our Store...................................."<<endl;

    cout<<"Enter Amount of Books : ";
    cin>>Amount;
}


class Book
{
    private:
        string title;
        string author;
        string isbn;
        string categoryName;
        double price;

    public:
    void SetBookInfo();
    void GetBookInfo();

};



class Customer
{
    private:
    string Name;
    string address;
    string email;

    public:
    void SetName();
    void SetAddress();
    void SetEmail();

    void GetName();
    void GetAddress();
    void GetEmail();
    
};