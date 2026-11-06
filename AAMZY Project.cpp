
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
    cout << "\t\t\t\t\tEnter your choice: ";
}

int main()
{
    int choice;
    string username;

    cout << "\t\t\t\t\t========================================\n";
    cout << "\t\t\t\t\t||     WELCOME TO LEVELUP             ||\n";
    cout << "\t\t\t\t\t========================================\n\n";
    cout << "\t\t\t\t\tEnter your username: ";
    getline(cin, username);

    initializeUser(username);
    cout << "\n\n\n\t\t\t\t\tWELCOME " << username << " TO:";

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
            cout << "\n\t\t\t\t\tThank you for using LevelUp!\n";
            return 0;

        default:
            cout << "\n\t\t\t\t\tInvalid choice! Please try again.\n";
        }
    }

    return 0;
}
