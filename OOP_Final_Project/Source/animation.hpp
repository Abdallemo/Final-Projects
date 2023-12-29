#include <iostream>
#include <Windows.h>
// #include <cstdlib> 
using namespace std;

void progressbar() 

{
    system("COLOR 0e");
    system("cls");
    SetConsoleCP(437);
    SetConsoleOutputCP(437);

    int bar1, bar2;
    bar1 = 177;
    bar2 = 219;

    cout << "\n\n\n\t\t\t\tLoading...";
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
}

