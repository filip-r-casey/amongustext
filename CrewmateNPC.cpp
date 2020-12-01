#include <iostream>
#include <string>
#include "crewmateNPC.h"

using namespace std;

//Default constructor
CrewmateNPC::CrewmateNPC()
{
    color = "";
    alive = true;
    room = 0;
}

//Paramterized Constructor
//Parameters: string that represents color, bool that represents life status, and integer that represents room location
CrewmateNPC::CrewmateNPC(string c, bool a, int r)
{
    color = c;
    alive = a;
    room = r;
}

//Sets color of an npc object
//Parameter: valid color string
void CrewmateNPC::setColor(string c)
{ 
    if (c == "red" || c == "blue" || c == "green" || c == "yellow" || c == "orange" || c == "black" || c == "white" || c == "purple" || c == "cyan" || c == "brown" || c == "lime")
    {
        color = c;
    }    
}

//Sets life status of an npc object
//Parameter: bool of life status
void CrewmateNPC::setAlive(bool a)
{
    alive = a;
}

//Sets room of npc object
//Parameter: integer representing room number
void CrewmateNPC::setRoom(int room_)
{
    room = room_;
}

//Gets color of npc object
//Return: color string of npc object
string CrewmateNPC::getColor()
{
    return color;
}

//Gets life status of npc object
//Return: bool representing life status
bool CrewmateNPC::getAlive()
{
    return alive;
}

//Gets location of npc object
//Return: int representing location
int CrewmateNPC::getRoom()
{
    return room;
}
