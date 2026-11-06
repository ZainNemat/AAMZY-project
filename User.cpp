
#include <iostream>
#include <string>
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
                            
    cout << "\n\n\n\t\t\t\t\t----------------------------------------\n";
    cout << "\t\t\t\t\t|               DASHBOARD              |\n";
    cout << "\t\t\t\t\t----------------------------------------\n\n";

    cout << "\t\t\t\t\tWelcome, " << username << "!\n\n";

    cout << "\t\t\t\t\tLevel: " << level << endl;
    cout << "\t\t\t\t\tTotal XP: " << totalXP << endl;

    cout << "\t\t\t\t\tLevel Progress: "
        << currentXP << " / " << nextLevelXP << " XP\n";

    cout << "\t\t\t\t\tCurrent Streak: "
        << currentStreak << " Days\n";

    cout << "\t\t\t\t\tLongest Streak: "
        << longestStreak << " Days\n";

    cout << "\t\t\t\t\t________________________________________\n\n\n\n";
}                        
