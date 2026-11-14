
#include <windows.h>
#include <iostream>
#include <string>
using namespace std;

extern int totalXP;
extern int currentXP;
extern int nextLevelXP;
extern int level;
extern int completedCount;
int readInt(string prompt);
void paintBelow();


void checkAchievements();

string tasks[100];
int taskXP[100];
bool taskCompleted[100];

int taskCount = 0;

void addTask();
void viewTasks();
void completeTask();
void deleteTask();

void manageTasks()
{
    HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);
    int taskChoice;

    while (true)
    {
        paintBelow();
        cout << "\n\n\t\t\t\t\t----------------------------------------\n";
        cout << "\t\t\t\t\t|             MANAGE TASKS             |\n";
        cout << "\t\t\t\t\t----------------------------------------\n";

        cout << "\t\t\t\t\t1. Add Task\n";
        cout << "\t\t\t\t\t2. View Tasks\n";
        cout << "\t\t\t\t\t3. Complete Task\n";
        cout << "\t\t\t\t\t4. Delete Task\n";
        cout << "\t\t\t\t\t5. Back to Main Menu\n";

        cout << "\t\t\t\t\t----------------------------------------\n";
        taskChoice = readInt("\t\t\t\t\tEnter your choice: ");

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
            cout << "\n\t\t\t\t\tInvalid choice! Try again.";
            SetConsoleTextAttribute(hc, 0xf0);
            cout << endl;
        }
    }
    

}

void addTask()
{
    HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);
    if (taskCount >= 100)
    {
        SetConsoleTextAttribute(hc, 0xf4);
        cout << "\n\t\t\t\t\tTask limit reached!";
        SetConsoleTextAttribute(hc, 0xf0);
        cout << endl;
        return;
    }

    while (true)
    {
        cout << "\n\t\t\t\t\tEnter task name: ";
        getline(cin, tasks[taskCount]);

        if (tasks[taskCount].find_first_not_of(" \t") != string::npos)
            break;                                   

        SetConsoleTextAttribute(hc, 0xf4);
        cout << "\n\t\t\t\t\tTask name cannot be empty!";
        SetConsoleTextAttribute(hc, 0xf0);
        cout << endl;
    }

    int difficulty;

    cout << "\n\t\t\t\t\tSelect Difficulty:\n";
    cout << "\t\t\t\t\t1. Easy (10 XP)\n";
    cout << "\t\t\t\t\t2. Medium (20 XP)\n";
    cout << "\t\t\t\t\t3. Hard (40 XP)\n";
    difficulty = readInt("\t\t\t\t\tEnter choice: ");

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
        cout << "\n\t\t\t\t\tInvalid difficulty!";
        SetConsoleTextAttribute(hc, 0xf0);
        cout << endl;
        return;
    }

    taskCompleted[taskCount] = false;

    taskCount++;
    SetConsoleTextAttribute(hc, 0xf3);
    cout << "\n\t\t\t\t\tTask added successfully!";
    SetConsoleTextAttribute(hc, 0xf0);
    cout << endl;

}

void viewTasks()
{
    HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << "\n\n\t\t\t\t\t----------------------------------------\n";
    cout << "\t\t\t\t\t|              YOUR TASKS              |\n";
    cout << "\t\t\t\t\t----------------------------------------\n\n";

    if (taskCount == 0)
    {
        SetConsoleTextAttribute(hc, 0xf4);
        cout << "\t\t\t\t\tNo tasks available.";
        SetConsoleTextAttribute(hc, 0xf0);
        cout << endl;
        return;
    }

    for (int i = 0; i < taskCount; i++)
    {
        cout << "\n\t\t\t\t\tTask " << i + 1 << ": " << tasks[i] << endl;
        cout << "\t\t\t\t\tXP Reward: " << taskXP[i] << endl;

        if (taskCompleted[i] == true)
        {
            cout << "\t\t\t\t\tStatus: Completed\n";
        }
        else
        {
            cout << "\t\t\t\t\tStatus: Pending\n";
        }
    }
   
}

void completeTask()
{
    HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);
    if (taskCount == 0)
    {
        SetConsoleTextAttribute(hc, 0xf4);
        cout << "\n\t\t\t\t\tNo tasks available to complete.";
        SetConsoleTextAttribute(hc, 0xf0);
        cout << endl;
        return;
    }

    viewTasks();

    int taskNumber;

    taskNumber = readInt("\n\t\t\t\t\tEnter task number to complete: ");

    if (taskNumber < 1 || taskNumber > taskCount)
    {
        SetConsoleTextAttribute(hc, 0xf4);
        cout << "\n\t\t\t\t\tInvalid task number!";
        SetConsoleTextAttribute(hc, 0xf0);
        cout << endl;
        return;
    }

    int index = taskNumber - 1;

    if (taskCompleted[index] == true)
    {
        cout << "\n\t\t\t\t\tThis task is already completed!\n";
        return;
    }

    taskCompleted[index] = true;
    completedCount++;

    totalXP = totalXP + taskXP[index];
    currentXP = currentXP + taskXP[index];

    SetConsoleTextAttribute(hc, 0xf3);
    cout << "\n\t\t\t\t\tCongratulations! Task completed!";
    SetConsoleTextAttribute(hc, 0xf0);
    cout << endl;
    SetConsoleTextAttribute(hc, 0xf3);
    cout << "\t\t\t\t\tYou earned " << taskXP[index] << " XP!";
    SetConsoleTextAttribute(hc, 0xf0);
    cout << endl;

    while (currentXP >= nextLevelXP)
    {
        currentXP = currentXP - nextLevelXP;
        level++;

        cout << "\n\t\t\t\t\tLEVEL UP! You are now Level " << level << "!\n";
    }

    checkAchievements();
  
}

void deleteTask()
{
    HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);
    if (taskCount == 0)
    {
        SetConsoleTextAttribute(hc, 0xf4);
        cout << "\n\t\t\t\t\tNo tasks available to delete.";
        SetConsoleTextAttribute(hc, 0xf0);
        cout << endl;
        return;
    }

    viewTasks();

    int taskNumber;

    taskNumber = readInt("\n\t\t\t\t\tEnter task number to delete: ");

    if (taskNumber < 1 || taskNumber > taskCount)
    {
        SetConsoleTextAttribute(hc, 0xf4);
        cout << "\n\t\t\t\t\tInvalid task number!";
        SetConsoleTextAttribute(hc, 0xf0);
        cout << endl;
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
    cout << "\n\t\t\t\t\tTask deleted successfully!";
    SetConsoleTextAttribute(hc, 0xf0);
    cout << endl; 
}
