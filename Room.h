#include <iostream>
#include <string>
#ifndef ROOM_H
#define ROOM_H

using namespace std;

class Room
{
    public:
        Room(); 
        Room(string name_, int vent_);

        string getName();
        int checkVent();
    private:
        string name;

        int vent;
};


#endif