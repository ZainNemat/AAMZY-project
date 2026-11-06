
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

    cout << "\n\t\t\t\t\t----------------------------------------\n";
    cout << "\t\t\t\t\t|          PRODUCTIVITY STATISTICS     |\n";
    cout << "\t\t\t\t\t----------------------------------------\n";

    cout << "\n\t\t\t\t\t  ---------- TASK STATISTICS ----------\n\n";

    cout << "\t\t\t\t\tTotal Tasks: " << taskCount << endl;
    cout << "\t\t\t\t\tCompleted Tasks: " << completedTasks << endl;
    cout << "\t\t\t\t\tPending Tasks: " << pendingTasks << endl;

    cout << "\t\t\t\t\tCompletion Percentage: "
        << completionPercentage << "%\n";

    cout << "\n\t\t\t\t\t  ---------- USER STATISTICS ----------\n\n";

    cout << "\t\t\t\t\tCurrent Level: " << level << endl;
    cout << "\t\t\t\t\tTotal XP Earned: " << totalXP << endl;

    cout << "\n\t\t\t\t\t----------------------------------------\n\n\n";
}
