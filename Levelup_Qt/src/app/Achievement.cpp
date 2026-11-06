#include "Achievement.h"
#include "Task.h"
#include "User.h"

namespace
{
std::array<Achievement, 5> achievements{{
    {"First Step", "Complete your first task", false},
    {"Getting Started", "Complete 5 tasks", false},
    {"Productive", "Complete 10 tasks", false},
    {"XP Hunter", "Earn 500 XP", false},
    {"Level Master", "Reach Level 5", false}
}};
}

void checkAchievements()
{
    int completedTasks = 0;

    for (int i = 0; i < taskCount; ++i)
    {
        if (taskCompleted[i])
        {
            ++completedTasks;
        }
    }

    if (completedTasks >= 1)
    {
        achievements[0].unlocked = true;
    }

    if (completedTasks >= 5)
    {
        achievements[1].unlocked = true;
    }

    if (completedTasks >= 10)
    {
        achievements[2].unlocked = true;
    }

    if (totalXP >= 500)
    {
        achievements[3].unlocked = true;
    }

    if (level >= 5)
    {
        achievements[4].unlocked = true;
    }
}

const std::array<Achievement, 5>& getAchievements()
{
    return achievements;
}