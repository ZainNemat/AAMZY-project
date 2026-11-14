
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;
extern int totalXP;
extern int level;
extern int taskCount;
extern bool taskCompleted[100];
extern int completedCount;

string achievementNames[5] =
{
    "First Step",
    "Getting Started",
    "Productive",
    "XP Hunter",
    "Level Master"
};

string achievementDescriptions[5] =
{
    "Complete your first task",
    "Complete 5 tasks",
    "Complete 10 tasks",
    "Earn 500 XP",
    "Reach Level 5"
};

bool achievementUnlocked[5] = { false, false, false, false, false };

void checkAchievements()
{
    if (completedCount >= 1)  achievementUnlocked[0] = true;
    if (completedCount >= 5)  achievementUnlocked[1] = true;
    if (completedCount >= 10) achievementUnlocked[2] = true;
    if (totalXP >= 500)       achievementUnlocked[3] = true;
    if (level >= 5)           achievementUnlocked[4] = true;
}

void displayAchievements()
{
    HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);
    checkAchievements();
                        
    cout << "\n\n\n\t\t\t\t\t----------------------------------------\n";
    cout << "\t\t\t\t\t|              ACHIEVEMENTS            |\n";
    cout << "\t\t\t\t\t----------------------------------------\n";

    for (int i = 0; i < 5; i++)
    {
        cout << "\n\t\t\t\t\tAchievement: " << achievementNames[i] << endl;
        cout << "\t\t\t\t\tDescription: " << achievementDescriptions[i] << endl;

        if (achievementUnlocked[i] == true)
        {
            cout << "\t\t\t\t\tStatus: ";
            SetConsoleTextAttribute(hc, 0xf3);   // blue text on white background
            cout<<"UNLOCKED!";
            SetConsoleTextAttribute(hc, 0xf0);   // back to the normal colour
            cout << "\n";
        }
        else
        {
            cout << "\t\t\t\t\tStatus: ";
            SetConsoleTextAttribute(hc, 0xf4);   // red text on the white background
            cout << "LOCKED";
            SetConsoleTextAttribute(hc, 0xf0);   // back to the normal colour
            cout << "\n";
        }

        cout << "\n\t\t\t\t\t........................................\n";
    }                        
}
