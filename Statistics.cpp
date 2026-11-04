
#include <iostream>
using namespace std;

extern int totalXP;
extern int level;
extern int taskCount;
extern bool taskCompleted[100];

void displayStatistics()
{
    int completedTasks = 0;
    int pendingTasks = 0;
    double completionPercentage = 0;

    for (int i = 0; i < taskCount; i++)
    {
        if (taskCompleted[i] == true)
        {
            completedTasks++;
        }
        else
        {
            pendingTasks++;
        }
    }

    if (taskCount > 0)
    {
        completionPercentage =
            (completedTasks * 100.0) / taskCount;
    }

    cout << "\n========================================\n";
    cout << "          PRODUCTIVITY STATISTICS\n";
    cout << "========================================\n";

    cout << "\n---------- TASK STATISTICS ----------\n";

    cout << "Total Tasks: " << taskCount << endl;
    cout << "Completed Tasks: " << completedTasks << endl;
    cout << "Pending Tasks: " << pendingTasks << endl;

    cout << "Completion Percentage: "
        << completionPercentage << "%\n";

    cout << "\n---------- USER STATISTICS ----------\n";

    cout << "Current Level: " << level << endl;
    cout << "Total XP Earned: " << totalXP << endl;

    cout << "\n========================================\n";
}
