#pragma once

#include <string>

constexpr int maxTasks = 100;

int addTask(const std::string& name, int difficultyIndex);
bool completeTask(int index);
bool deleteTask(int index);

extern int taskCount;
extern bool taskCompleted[maxTasks];