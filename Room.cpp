#include <iostream>
#include <string>
#include "Room.h"

using namespace std;

//Default Constructor
Room::Room()
{
    name = "";
    vent = -1;
}

//Parameterized Constructor
//Parameter: string room name, int vent location
Room::Room(string name_, int vent_)
{
    name = name_;
    vent = vent_;
}

//Gets the name of the room
//Return: string of room name
string Room::getName()
{
    return name;
}

//Checks where the vent in room goes to
//Return: vent integer
int Room::checkVent()
{
    return vent;
}

//There are no setters because vent status is reliant on name, so it is always going to have to be changed with the parameterized constructor anyways