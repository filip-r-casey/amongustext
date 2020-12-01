#include <iostream>
#include <string>
#ifndef CREWMATEPLAYER_H
#define CREWMATEPLAYER_H

using namespace std;

class CrewmatePlayer
{
    public:
        CrewmatePlayer();
        CrewmatePlayer(int nc, int nf, int r, string c, bool e);

        void setNumCrewmates(int n);
        void setNumFinishedTasks(int n);
        void setRound(int r);
        void setColor(string c);
        void setEmergencyMeeting(bool e);

        int getNumCrewmates();
        int getNumFinishedTasks();
        int getRound();
        string getColor();
        bool getEmergencyMeeting();    
    private:
        int num_crewmates;
        int num_finished_tasks;
        int round;
        
        string color;

        bool emergency_meeting;
};



#endif