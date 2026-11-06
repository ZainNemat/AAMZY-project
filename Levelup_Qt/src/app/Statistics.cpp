#include "Statistics.h"
#include "Task.h"

TaskStatistics getTaskStatistics()
{
    int completed = 0;

    for (int i = 0; i < taskCount; ++i)
    {
        if (taskCompleted[i])
        {
            ++completed;
        }
    }

    double completionRate = 0.0;
    if (taskCount > 0)
    {
        completionRate = completed * 100.0 / taskCount;
    }

    return {
        taskCount,
        completed,
        taskCount - completed,
        completionRate
    };
}