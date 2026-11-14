
#include <iostream>
#include <string>
#include <windows.h>
#include <cstdlib>
using namespace std;

int choice;
int completedCount = 0;

void initializeUser(string name);
void displayDashboard();
void manageTasks();
void displayAchievements();
void displayStatistics();

void paintBelow()
{
    HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hc, &csbi);

    COORD pos = csbi.dwCursorPosition;
    DWORD cells = (csbi.dwSize.Y - pos.Y) * csbi.dwSize.X - pos.X;
    DWORD written;

    FillConsoleOutputAttribute(hc, 0xf0, cells, pos, &written);
}

int readInt(string prompt)
{

    HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);
    int value;

    while (true)
    {
        paintBelow();
        cout << prompt;
        cin >> value;

        if (cin.fail())
        {
            SetConsoleTextAttribute(hc, 0xf4);
            cout << "\n\t\t\t\t\tInvalid input! Please enter digits only.";
            SetConsoleTextAttribute(hc, 0xf0);
            cout << "\n\n";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else
        {
            cin.ignore(1000, '\n');
            return value;
        }
    }
}

void displayMenu()
{
    cout << "\n\t\t\t\t\t****************************************\n";
    cout << "\t\t\t\t\t*                 LEVELUP              *\n";
    cout << "\t\t\t\t\t*         GAMIFIED PRODUCTIVITY        *\n";
    cout << "\t\t\t\t\t****************************************\n";

    cout << "\t\t\t\t\t1. Dashboard\n";
    cout << "\t\t\t\t\t2. Manage Tasks\n";
    cout << "\t\t\t\t\t3. Achievements\n";
    cout << "\t\t\t\t\t4. Productivity Statistics\n";
    cout << "\t\t\t\t\t5. Exit\n";
                       
    cout << "\t\t\t\t\t________________________________________\n\n";
    
    choice = readInt("\t\t\t\t\tEnter your choice: ");
}


int main()
{
    string username;
    HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);
    system("Color F0");
    cout << "\t\t\t\t\t========================================\n";
    cout << "\t\t\t\t\t|         WELCOME TO LEVELUP           |\n";
    cout << "\t\t\t\t\t========================================\n\n";
    while (true)
    {
        cout << "\t\t\t\t\tEnter your username: ";
        getline(cin, username);

        if (username.find_first_not_of(" \t") != string::npos)
            break;                                   

        SetConsoleTextAttribute(hc, 0xf4);
        cout << "\n\t\t\t\t\tUsername cannot be empty!";
        SetConsoleTextAttribute(hc, 0xf0);
        cout << "\n\n";
    }

    initializeUser(username);
    cout << "\n\n\n\t\t\t\t\tWELCOME " << username << " TO:";

    while (true)
    {
        paintBelow();
        displayMenu();

        switch (choice)
        {
        case 1:
            displayDashboard();
            break;

        case 2:
            manageTasks();
            break;

        case 3:
            displayAchievements();
            break;

        case 4:
            displayStatistics();
            break;

        case 5:
            SetConsoleTextAttribute(hc, 0xf3);
            cout << "\n\t\t\t\t\tThank you for using LevelUp!";
            SetConsoleTextAttribute(hc, 0xf0);   
            cout << "\n";
            return 0;

        default:
        {
            SetConsoleTextAttribute(hc, 0xf4);
            cout << "\n\t\t\t\t\tInvalid choice! Please try again.";
            SetConsoleTextAttribute(hc, 0xf0);
            cout << "\n";
            break;
        }
        }
    }
    
    return 0;
}
