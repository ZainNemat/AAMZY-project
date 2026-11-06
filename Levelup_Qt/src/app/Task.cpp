#include "Task.h"
#include "Achievement.h"
#include "User.h"

namespace
{
constexpr int xpRewards[] = {10, 20, 40};
constexpr int difficultyCount = sizeof(xpRewards) / sizeof(xpRewards[0]);

std::string tasks[maxTasks];
int taskXP[maxTasks] = {};
}

int taskCount = 0;
bool taskCompleted[maxTasks] = {};

int addTask(const std::string& name, int difficultyIndex)
{
    if (name.empty() || taskCount >= maxTasks ||
        difficultyIndex < 0 || difficultyIndex >= difficultyCount)
    {
        return 0;
    }

    const int reward = xpRewards[difficultyIndex];

    tasks[taskCount] = name;
    taskXP[taskCount] = reward;
    taskCompleted[taskCount] = false;
    ++taskCount;

    return reward;
}

bool completeTask(int index)
{
    if (index < 0 || index >= taskCount || taskCompleted[index])
    {
        return false;
    }

    taskCompleted[index] = true;
    totalXP += taskXP[index];
    currentXP += taskXP[index];

    while (currentXP >= nextLevelXP)
    {
        currentXP -= nextLevelXP;
        ++level;
    }

    checkAchievements();
    return true;
}

bool deleteTask(int index)
{
    if (index < 0 || index >= taskCount)
    {
        return false;
    }

    for (int i = index; i < taskCount - 1; ++i)
    {
        tasks[i] = tasks[i + 1];
        taskXP[i] = taskXP[i + 1];
        taskCompleted[i] = taskCompleted[i + 1];
    }

    --taskCount;
    return true;
}