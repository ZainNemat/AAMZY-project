#include "User.h"

#include <QDate>

namespace
{
std::string username = "Player";
QDate lastCompletionDate;
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

void recordTaskCompletionDay()
{
    const QDate today = QDate::currentDate();

    if (lastCompletionDate.isValid() && today <= lastCompletionDate)
    {
        return;
    }

    if (lastCompletionDate.isValid() && lastCompletionDate.addDays(1) == today)
    {
        ++currentStreak;
    }
    else
    {
        currentStreak = 1;
    }

    lastCompletionDate = today;

    if (currentStreak > longestStreak)
    {
        longestStreak = currentStreak;
    }
}

int getCurrentStreak()
{
    const QDate today = QDate::currentDate();

    if (!lastCompletionDate.isValid() || lastCompletionDate.addDays(1) < today)
    {
        return 0;
    }

    return currentStreak;
}