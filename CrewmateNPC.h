#include <iostream>
#include <string>
#ifndef CREWMATENPC_H
#define CREWMATENPC_H

using namespace std;

class CrewmateNPC
{
    public:
        CrewmateNPC();
        CrewmateNPC(string c, bool a, int r);

        void setColor(string c);
        void setAlive(bool a);
        void setRoom(int room_);

        string getColor();
        bool getAlive();
        int getRoom();
    private:
        string color;
        
        bool alive;

        int room;
};


#endif