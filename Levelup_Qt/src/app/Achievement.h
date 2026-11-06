#pragma once

#include <array>

struct Achievement
{
    const char *name;
    const char *description;
    bool unlocked;
};

void checkAchievements();
const std::array<Achievement, 5>& getAchievements();