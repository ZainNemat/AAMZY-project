
#include <iostream>
#include <string>
using namespace std;

extern int totalXP;
extern int currentXP;
extern int nextLevelXP;
extern int level;

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
    int choice;

    while (true)
    {
        cout << "\n========================================\n";
        cout << "              MANAGE TASKS\n";
        cout << "========================================\n";

        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Complete Task\n";
        cout << "4. Delete Task\n";
        cout << "5. Back to Main Menu\n";

        cout << "========================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
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
            cout << "\nInvalid choice! Try again.\n";
        }
    }
}

void addTask()
{
    if (taskCount >= 100)
    {
        cout << "\nTask limit reached!\n";
        return;
    }

    cin.ignore();

    cout << "\nEnter task name: ";
    getline(cin, tasks[taskCount]);

    int difficulty;

    cout << "\nSelect Difficulty:\n";
    cout << "1. Easy (10 XP)\n";
    cout << "2. Medium (20 XP)\n";
    cout << "3. Hard (40 XP)\n";
    cout << "Enter choice: ";
    cin >> difficulty;

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
        cout << "\nInvalid difficulty!\n";
        return;
    }

    taskCompleted[taskCount] = false;

    taskCount++;

    cout << "\nTask added successfully!\n";
}

void viewTasks()
{
    cout << "\n========================================\n";
    cout << "                YOUR TASKS\n";
    cout << "========================================\n";

    if (taskCount == 0)
    {
        cout << "No tasks available.\n";
        return;
    }

    for (int i = 0; i < taskCount; i++)
    {
        cout << "\nTask " << i + 1 << ": " << tasks[i] << endl;
        cout << "XP Reward: " << taskXP[i] << endl;

        if (taskCompleted[i] == true)
        {
            cout << "Status: Completed\n";
        }
        else
        {
            cout << "Status: Pending\n";
        }
    }
}

void completeTask()
{
    if (taskCount == 0)
    {
        cout << "\nNo tasks available to complete.\n";
        return;
    }

    viewTasks();

    int taskNumber;

    cout << "\nEnter task number to complete: ";
    cin >> taskNumber;

    if (taskNumber < 1 || taskNumber > taskCount)
    {
        cout << "\nInvalid task number!\n";
        return;
    }

    int index = taskNumber - 1;

    if (taskCompleted[index] == true)
    {
        cout << "\nThis task is already completed!\n";
        return;
    }

    taskCompleted[index] = true;

    totalXP = totalXP + taskXP[index];
    currentXP = currentXP + taskXP[index];

    cout << "\nCongratulations! Task completed!\n";
    cout << "You earned " << taskXP[index] << " XP!\n";

    while (currentXP >= nextLevelXP)
    {
        currentXP = currentXP - nextLevelXP;
        level++;

        cout << "\nLEVEL UP! You are now Level " << level << "!\n";
    }

    checkAchievements();
}

void deleteTask()
{
    if (taskCount == 0)
    {
        cout << "\nNo tasks available to delete.\n";
        return;
    }

    viewTasks();

    int taskNumber;

    cout << "\nEnter task number to delete: ";
    cin >> taskNumber;

    if (taskNumber < 1 || taskNumber > taskCount)
    {
        cout << "\nInvalid task number!\n";
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

    cout << "\nTask deleted successfully!\n";
}
