#include <iostream>
#include <string>
#include "crewmateNPC.h"
#include "ImposterPlayer.h"
#include "Tasks.h"
#include "CrewmatePlayer.h"
#ifndef AMONGUS_H
#define AMONGUS_H
using namespace std;

class AmongUs 
{
    public:
        AmongUs();
        AmongUs(CrewmateNPC a[], Tasks t[], int n);
        int mainMenu();
        void playImposter(CrewmateNPC a[]);
        void playCrewmate(CrewmateNPC a[], Tasks t[]);

        void setCrewmateArray(CrewmateNPC a[]);
        void setTaskArray(Tasks t[]);
        void incrementGameNum();
        int getGameNum();
    private:
        CrewmateNPC crewmates[5];
        Tasks task_array[3];
        int game_num;
};
#endif