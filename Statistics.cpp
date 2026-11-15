#include "Statistics.h"
#include <iostream>
using namespace std;

extern int totalXP;
extern int level;
extern int taskCount;
extern bool taskCompleted[100];

void displayStatistics()
{
    int completedTasks = 0;

    for (int i = 0; i < taskCount; i++)
    {
        if (taskCompleted[i])
            completedTasks++;
    }

    int pendingTasks = taskCount - completedTasks;
    double completionPercentage = 0;

    if (taskCount > 0)
        completionPercentage = (completedTasks * 100.0) / taskCount;

    cout << "\n----------------------------------------\n";
    cout << "|          PRODUCTIVITY STATISTICS     |\n";
    cout << "----------------------------------------\n";

    cout << "\n---------- TASK STATISTICS ----------\n\n";

    cout << "Total Tasks: " << taskCount << "\n";
    cout << "Completed Tasks: " << completedTasks << "\n";
    cout << "Pending Tasks: " << pendingTasks << "\n";

    cout << "Completion Percentage: " << completionPercentage << "%\n";

    cout << "\n---------- USER STATISTICS ----------\n\n";

    cout << "Current Level: " << level << "\n";
    cout << "Total XP Earned: " << totalXP << "\n";

    cout << "\n----------------------------------------\n";
}