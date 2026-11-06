
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
        cout << "\n\n\t\t\t\t\t----------------------------------------\n";
        cout << "\t\t\t\t\t|             MANAGE TASKS             |\n";
        cout << "\t\t\t\t\t----------------------------------------\n";

        cout << "\t\t\t\t\t1. Add Task\n";
        cout << "\t\t\t\t\t2. View Tasks\n";
        cout << "\t\t\t\t\t3. Complete Task\n";
        cout << "\t\t\t\t\t4. Delete Task\n";
        cout << "\t\t\t\t\t5. Back to Main Menu\n";

        cout << "\t\t\t\t\t----------------------------------------\n";
        cout << "\t\t\t\t\tEnter your choice: ";
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
            cout << "\n\t\t\t\t\tInvalid choice! Try again.\n";
        }
    }
}

void addTask()
{
    if (taskCount >= 100)
    {
        cout << "\n\t\t\t\t\tTask limit reached!\n";
        return;
    }

    cin.ignore();

    cout << "\n\t\t\t\t\tEnter task name: ";
    getline(cin, tasks[taskCount]);

    int difficulty;

    cout << "\n\t\t\t\t\tSelect Difficulty:\n";
    cout << "\t\t\t\t\t1. Easy (10 XP)\n";
    cout << "\t\t\t\t\t2. Medium (20 XP)\n";
    cout << "\t\t\t\t\t3. Hard (40 XP)\n";
    cout << "\t\t\t\t\tEnter choice: ";
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
        cout << "\n\t\t\t\t\tInvalid difficulty!\n";
        return;
    }

    taskCompleted[taskCount] = false;

    taskCount++;

    cout << "\n\t\t\t\t\tTask added successfully!\n";
}

void viewTasks()
{
    cout << "\n\n\t\t\t\t\t----------------------------------------\n";
    cout << "\t\t\t\t\t|              YOUR TASKS              |\n";
    cout << "\t\t\t\t\t----------------------------------------\n\n";

    if (taskCount == 0)
    {
        cout << "\t\t\t\t\tNo tasks available.\n";
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
    if (taskCount == 0)
    {
        cout << "\n\t\t\t\t\tNo tasks available to complete.\n";
        return;
    }

    viewTasks();

    int taskNumber;

    cout << "\n\t\t\t\t\tEnter task number to complete: ";
    cin >> taskNumber;

    if (taskNumber < 1 || taskNumber > taskCount)
    {
        cout << "\n\t\t\t\t\tInvalid task number!\n";
        return;
    }

    int index = taskNumber - 1;

    if (taskCompleted[index] == true)
    {
        cout << "\n\t\t\t\t\tThis task is already completed!\n";
        return;
    }

    taskCompleted[index] = true;

    totalXP = totalXP + taskXP[index];
    currentXP = currentXP + taskXP[index];

    cout << "\n\t\t\t\t\tCongratulations! Task completed!\n";
    cout << "\t\t\t\t\tYou earned " << taskXP[index] << " XP!\n";

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
    if (taskCount == 0)
    {
        cout << "\n\t\t\t\t\tNo tasks available to delete.\n";
        return;
    }

    viewTasks();

    int taskNumber;

    cout << "\n\t\t\t\t\tEnter task number to delete: ";
    cin >> taskNumber;

    if (taskNumber < 1 || taskNumber > taskCount)
    {
        cout << "\n\t\t\t\t\tInvalid task number!\n";
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

    cout << "\n\t\t\t\t\tTask deleted successfully!\n";
}
