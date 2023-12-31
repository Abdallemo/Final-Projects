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

    cout << "\n\n\n\n\n\n\n\n\t\t\t\t\tLoading...";
    cout << "\n\n\n\n\n\t\t\t\t\t";

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

void deleteBar() 

{
    system("COLOR 0c");
    system("cls");
    SetConsoleCP(437);
    SetConsoleOutputCP(437);

    int bar1, bar2;
    bar1 = 177;
    bar2 = 219;

    cout << "\n\n\n\n\n\n\n\n\t\t\t\t\tDeleting...";
    cout << "\n\n\n\n\n\t\t\t\t\t";

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
void searchbar() 

{
    system("COLOR 0a");
    system("cls");
    SetConsoleCP(437);
    SetConsoleOutputCP(437);

    int bar1, bar2;
    bar1 = 177;
    bar2 = 219;

    cout << "\n\n\n\n\n\n\n\n\t\t\t\t\tSearching...";
    cout << "\n\n\n\n\n\t\t\t\t\t";

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
void ReportgenBar() 

{
    system("COLOR 03");
    system("cls");
    SetConsoleCP(437);
    SetConsoleOutputCP(437);

    int bar1, bar2;
    bar1 = 177;
    bar2 = 219;

    cout << "\n\n\n\n\n\n\n\n\t\t\t\t\tGenerating Report.txt...";
    cout << "\n\n\n\n\n\t\t\t\t\t";

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
