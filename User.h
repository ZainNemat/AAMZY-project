#pragma once

#include <string>

extern std::string username;

extern int level;
extern int totalXP;
extern int currentXP;
extern int nextLevelXP;
extern int currentStreak;
extern int longestStreak;

void initializeUser(std::string name);
void displayDashboard();