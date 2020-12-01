#include <iostream>
#include <string>
#include "Tasks.h"

using namespace std;

//Default Constructor
Tasks::Tasks()
{
    finished = false;
    task_name = "";
    attempts = 0;
}

//Parameterized Constructor
//Parameter: bool for if the task is finished or not, string for task name, int attempts
Tasks::Tasks(bool f, string n, int a)
{
    finished = f;
    task_name = n;
    attempts = a;
}

//Sets whether the task is finished or not
//Parameter: bool on task completion status
void Tasks::setFinished(bool f)
{
    finished = f;
}

//Sets the task name
//Parameter: string representing the task name
void Tasks::setTaskName(string n)
{
    task_name = n;
}

//Sets the number of attempts
//Parameter: int representing the number of attempts
void Tasks::setAttempts(int a)
{
    attempts = a;
}

//Gets the task completion status
//Return: Bool of task completion
bool Tasks::getFinished()
{
    return finished;
}

//Gets task name
//Return: string of task name
string Tasks::getTaskName()
{
    return task_name;
}

//Gets number of attempts
//Return: int representing number of attempts
int Tasks::getAttempts()
{
    return attempts;
}