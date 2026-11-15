#pragma once

#include <string>

extern std::string tasks[100];
extern int taskXP[100];
extern bool taskCompleted[100];
extern int taskCount;
extern int completedCount;
void manageTasks();
void addTask();
void viewTasks();
void completeTask();
void deleteTask();