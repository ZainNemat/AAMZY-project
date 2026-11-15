#include "Achievement.h"
#include "ConsoleUtils.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <cstdlib>
#include "Statistics.h"
#include "Task.h"
#include "User.h"
using namespace std;

int displayMenu()
{
    cout << "\n****************************************\n";
    cout << "*                 LEVELUP              *\n";
    cout << "*         GAMIFIED PRODUCTIVITY        *\n";
    cout << "****************************************\n";

    cout << "1. Dashboard\n";
    cout << "2. Manage Tasks\n";
    cout << "3. Achievements\n";
    cout << "4. Productivity Statistics\n";
    cout << "5. Exit\n";

    cout << "________________________________________\n\n";

    return readInt("Enter your choice: ");
}

int main()
{
    string username;
    HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);

    system("Color F0");

    cout << "========================================\n";
    cout << "|         WELCOME TO LEVELUP           |\n";
    cout << "========================================\n\n";

    while (true)
    {
        cout << "Enter your username: ";

        if (!getline(cin, username))
            return 0;

        if (username.find_first_not_of(" \t\r") != string::npos)
            break;

        SetConsoleTextAttribute(hc, 0xf4);
        cout << "\nUsername cannot be empty!\n\n";
        SetConsoleTextAttribute(hc, 0xf0);
    }

    initializeUser(username);
    cout << "\nWELCOME " << username << " TO:\n";

    while (true)
    {
        paintBelow();

        int choice = displayMenu();

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
            cout << "\nThank you for using LevelUp!\n";
            SetConsoleTextAttribute(hc, 0xf0);
            return 0;

        default:
            SetConsoleTextAttribute(hc, 0xf4);
            cout << "\nInvalid choice! Please try again.\n";
            SetConsoleTextAttribute(hc, 0xf0);
            break;
        }
    }
}