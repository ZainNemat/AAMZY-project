#include "User.h"

namespace
{
std::string username = "Player";
}

int level = 1;
int totalXP = 0;
int currentXP = 0;
int nextLevelXP = 100;
int currentStreak = 0;
int longestStreak = 0;

void setUsername(std::string name)
{
    username = name;
}

std::string getUsername()
{
    return username;
}