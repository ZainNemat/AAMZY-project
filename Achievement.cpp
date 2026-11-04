
#include <iostream>
#include <string>
using namespace std;
extern int totalXP;
extern int level;
extern int taskCount;
extern bool taskCompleted[100];

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
    int completedTasks = 0;

    for (int i = 0; i < taskCount; i++)
    {
        if (taskCompleted[i] == true)
        {
            completedTasks++;
        }
    }

    if (completedTasks >= 1)
    {
        achievementUnlocked[0] = true;
    }

    if (completedTasks >= 5)
    {
        achievementUnlocked[1] = true;
    }

    if (completedTasks >= 10)
    {
        achievementUnlocked[2] = true;
    }

    if (totalXP >= 500)
    {
        achievementUnlocked[3] = true;
    }

    if (level >= 5)
    {
        achievementUnlocked[4] = true;
    }
}

void displayAchievements()
{
    checkAchievements();

    cout << "\n========================================\n";
    cout << "              ACHIEVEMENTS\n";
    cout << "========================================\n";

    for (int i = 0; i < 5; i++)
    {
        cout << "\nAchievement: " << achievementNames[i] << endl;
        cout << "Description: " << achievementDescriptions[i] << endl;

        if (achievementUnlocked[i] == true)
        {
            cout << "Status: UNLOCKED!\n";
        }
        else
        {
            cout << "Status: LOCKED\n";
        }

        cout << "----------------------------------------\n";
    }
}
