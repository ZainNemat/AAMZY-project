#pragma once

struct TaskStatistics
{
    int total;
    int completed;
    int pending;
    double completionRate;
};

TaskStatistics getTaskStatistics();