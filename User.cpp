#include "User.h"
#include <iostream>
using namespace std;

string username = "Player";

int level = 1;
int totalXP = 0;
int currentXP = 0;
int nextLevelXP = 100;
int currentStreak = 0;
int longestStreak = 0;

void initializeUser(string name)
{
    username = name;
}

void displayDashboard()
{
    cout << "\n----------------------------------------\n";
    cout << "|               DASHBOARD              |\n";
    cout << "----------------------------------------\n";

    cout << "\nWelcome, " << username << "!\n\n";

    cout << "Level: " << level << "\n";
    cout << "Total XP: " << totalXP << "\n";

    cout << "Level Progress: "
        << currentXP << " / " << nextLevelXP << " XP\n";

    cout << "Current Streak: " << currentStreak << " Days\n";
    cout << "Longest Streak: " << longestStreak << " Days\n";

    cout << "________________________________________\n";
}