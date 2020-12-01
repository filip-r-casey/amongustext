#include <iostream>
#include <string>
#ifndef TASKS_H
#define TASKS_H

using namespace std;

class Tasks
{
    public:
        Tasks();
        Tasks(bool f, string n, int a);

        void setFinished(bool f);
        void setTaskName(string n);
        void setAttempts(int a);

        bool getFinished();
        string getTaskName();
        int getAttempts();
    private:
        bool finished;

        string task_name;

        int attempts;
};


#endif