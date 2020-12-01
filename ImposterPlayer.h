#include <iostream>
#include <string>
#include "crewmateNPC.h"
#ifndef IMPOSTERPLAYER_H
#define IMPOSTERPLAYER_H

using namespace std;

class ImposterPlayer
{
    public:
        ImposterPlayer();
        ImposterPlayer(CrewmateNPC a[], string c, int k, int n, int r);

        void setCrewmatesArray(CrewmateNPC a[]);
        void setColor(string c);
        void setNumKills(int k);
        void setNumCrewmates(int n);
        void setRound(int r);
        void setTotalRounds(int tr);


        string getColor();
        int getNumKills();
        int getNumCrewmates();
        int getRound();
        int getTotalRounds();
    private:
        string color;

        int num_kills;
        int num_crewmates;
        int round;
        int room;
        int total_rounds;
};


#endif