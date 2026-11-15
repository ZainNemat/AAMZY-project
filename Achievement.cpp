#include "Achievement.h"
#include "User.h"
#include <iostream>
#include <string>
#include <windows.h>
#include "Task.h"
using namespace std;

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

bool achievementUnlocked[5] = { false };

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

    cout << "\n----------------------------------------\n";
    cout << "|              ACHIEVEMENTS            |\n";
    cout << "----------------------------------------\n";

    for (int i = 0; i < 5; i++)
    {
        cout << "\nAchievement: " << achievementNames[i] << "\n";
        cout << "Description: " << achievementDescriptions[i] << "\n";
        cout << "Status: ";

        if (achievementUnlocked[i])
        {
            SetConsoleTextAttribute(hc, 0xf3);
            cout << "UNLOCKED!";
        }
        else
        {
            SetConsoleTextAttribute(hc, 0xf4);
            cout << "LOCKED";
        }

        SetConsoleTextAttribute(hc, 0xf0);
        cout << "\n";

        cout << "\n........................................\n";
    }
}