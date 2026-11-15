#include "Task.h"
#include "ConsoleUtils.h"
#include "Achievement.h"
#include "User.h"
#include <windows.h>
#include <iostream>
#include <string>
using namespace std;

int completedCount = 0;
string tasks[100];
int taskXP[100];
bool taskCompleted[100];

int taskCount = 0;

void manageTasks()
{
    HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);

    while (true)
    {
        paintBelow();

        cout << "\n----------------------------------------\n";
        cout << "|             MANAGE TASKS             |\n";
        cout << "----------------------------------------\n";

        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Complete Task\n";
        cout << "4. Delete Task\n";
        cout << "5. Back to Main Menu\n";

        cout << "----------------------------------------\n";

        int taskChoice = readInt("Enter your choice: ");

        switch (taskChoice)
        {
        case 1:
            addTask();
            break;

        case 2:
            viewTasks();
            break;

        case 3:
            completeTask();
            break;

        case 4:
            deleteTask();
            break;

        case 5:
            return;

        default:
            SetConsoleTextAttribute(hc, 0xf4);
            cout << "\nInvalid choice! Try again.\n";
            SetConsoleTextAttribute(hc, 0xf0);
            break;
        }
    }
}

void addTask()
{
    HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);

    if (taskCount >= 100)
    {
        SetConsoleTextAttribute(hc, 0xf4);
        cout << "\nTask limit reached!\n";
        SetConsoleTextAttribute(hc, 0xf0);
        return;
    }

    while (true)
    {
        cout << "\nEnter task name: ";

        if (!getline(cin, tasks[taskCount]))
            return;

        if (tasks[taskCount].find_first_not_of(" \t\r") != string::npos)
            break;

        SetConsoleTextAttribute(hc, 0xf4);
        cout << "\nTask name cannot be empty!\n";
        SetConsoleTextAttribute(hc, 0xf0);
    }

    cout << "\nSelect Difficulty:\n";
    cout << "1. Easy (10 XP)\n";
    cout << "2. Medium (20 XP)\n";
    cout << "3. Hard (40 XP)\n";

    int difficulty = readInt("Enter choice: ");

    if (difficulty == 1)
    {
        taskXP[taskCount] = 10;
    }
    else if (difficulty == 2)
    {
        taskXP[taskCount] = 20;
    }
    else if (difficulty == 3)
    {
        taskXP[taskCount] = 40;
    }
    else
    {
        SetConsoleTextAttribute(hc, 0xf4);
        cout << "\nInvalid difficulty!\n";
        SetConsoleTextAttribute(hc, 0xf0);
        return;
    }

    taskCompleted[taskCount] = false;
    taskCount++;

    SetConsoleTextAttribute(hc, 0xf3);
    cout << "\nTask added successfully!\n";
    SetConsoleTextAttribute(hc, 0xf0);
}
void viewTasks()
{
    HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);

    cout << "\n----------------------------------------\n";
    cout << "|              YOUR TASKS              |\n";
    cout << "----------------------------------------\n";

    if (taskCount == 0)
    {
        SetConsoleTextAttribute(hc, 0xf4);
        cout << "\nNo tasks available.\n";
        SetConsoleTextAttribute(hc, 0xf0);
        return;
    }

    for (int i = 0; i < taskCount; i++)
    {
        cout << "\nTask " << i + 1 << ": " << tasks[i] << "\n";
        cout << "XP Reward: " << taskXP[i] << "\n";

        if (taskCompleted[i])
            cout << "Status: Completed\n";
        else
            cout << "Status: Pending\n";
    }
}

void completeTask()
{
    HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);

    if (taskCount == 0)
    {
        SetConsoleTextAttribute(hc, 0xf4);
        cout << "\nNo tasks available to complete.\n";
        SetConsoleTextAttribute(hc, 0xf0);
        return;
    }

    viewTasks();

    int taskNumber = readInt("\nEnter task number to complete: ");

    if (taskNumber < 1 || taskNumber > taskCount)
    {
        SetConsoleTextAttribute(hc, 0xf4);
        cout << "\nInvalid task number!\n";
        SetConsoleTextAttribute(hc, 0xf0);
        return;
    }

    int index = taskNumber - 1;

    if (taskCompleted[index])
    {
        cout << "\nThis task is already completed!\n";
        return;
    }

    taskCompleted[index] = true;
    completedCount++;

    totalXP += taskXP[index];
    currentXP += taskXP[index];

    SetConsoleTextAttribute(hc, 0xf3);
    cout << "\nCongratulations! Task completed!\n";
    cout << "You earned " << taskXP[index] << " XP!\n";
    SetConsoleTextAttribute(hc, 0xf0);

    while (currentXP >= nextLevelXP)
    {
        currentXP -= nextLevelXP;
        level++;

        cout << "\nLEVEL UP! You are now Level " << level << "!\n";
    }

    checkAchievements();
}

void deleteTask()
{
    HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);

    if (taskCount == 0)
    {
        SetConsoleTextAttribute(hc, 0xf4);
        cout << "\nNo tasks available to delete.\n";
        SetConsoleTextAttribute(hc, 0xf0);
        return;
    }

    viewTasks();

    int taskNumber = readInt("\nEnter task number to delete: ");

    if (taskNumber < 1 || taskNumber > taskCount)
    {
        SetConsoleTextAttribute(hc, 0xf4);
        cout << "\nInvalid task number!\n";
        SetConsoleTextAttribute(hc, 0xf0);
        return;
    }

    int index = taskNumber - 1;

    for (int i = index; i < taskCount - 1; i++)
    {
        tasks[i] = tasks[i + 1];
        taskXP[i] = taskXP[i + 1];
        taskCompleted[i] = taskCompleted[i + 1];
    }

    taskCount--;

    SetConsoleTextAttribute(hc, 0xf3);
    cout << "\nTask deleted successfully!\n";
    SetConsoleTextAttribute(hc, 0xf0);
}