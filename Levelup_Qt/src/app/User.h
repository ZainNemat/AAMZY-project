#pragma once

#include <string>

void setUsername(std::string name);
std::string getUsername();

void recordTaskCompletionDay();
int getCurrentStreak();

extern int level;
extern int totalXP;
extern int currentXP;
extern int nextLevelXP;
extern int currentStreak;
extern int longestStreak;