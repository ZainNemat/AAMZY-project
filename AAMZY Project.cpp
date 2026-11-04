
#include <iostream>
#include <string>
using namespace std;

void initializeUser(string name);
void displayDashboard();
void manageTasks();
void displayAchievements();
void displayStatistics();

void displayMenu()
{
    cout << "\n========================================\n";
    cout << "                 LEVELUP\n";
    cout << "        GAMIFIED PRODUCTIVITY\n";
    cout << "========================================\n";

    cout << "1. Dashboard\n";
    cout << "2. Manage Tasks\n";
    cout << "3. Achievements\n";
    cout << "4. Productivity Statistics\n";
    cout << "5. Exit\n";

    cout << "========================================\n";
    cout << "Enter your choice: ";
}

int main()
{
    int choice;
    string username;

    cout << "========================================\n";
    cout << "          WELCOME TO LEVELUP\n";
    cout << "========================================\n";

    cout << "Enter your username: ";
    getline(cin, username);

    initializeUser(username);

    while (true)
    {
        displayMenu();

        cin >> choice;

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
            cout << "\nThank you for using LevelUp!\n";
            return 0;

        default:
            cout << "\nInvalid choice! Please try again.\n";
        }
    }

    return 0;
}
