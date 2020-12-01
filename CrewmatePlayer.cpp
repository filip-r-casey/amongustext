#include <iostream>
#include <string>
#include "CrewmatePlayer.h"

using namespace std;

//Default Constructor
CrewmatePlayer::CrewmatePlayer()
{
    num_crewmates = 0;
    num_finished_tasks = 0;
    round = 0;
    color = "";
    emergency_meeting = 1;
}

//Parameterized constructor
//Parameters: int representing number of crewmates, int representing number of finished tasks, int representing round, string representing color, bool representing emergency meeting status
CrewmatePlayer::CrewmatePlayer(int nc, int nf, int r, string c, bool e)
{
    num_crewmates = nc;
    num_finished_tasks = nf;
    round = r;
    color = c;
    emergency_meeting = e;
}

//Sets the number of crewmates to a value
//Parameter: int representing the number of crewmates
void CrewmatePlayer::setNumCrewmates(int n)
{
    if (n > 1 && n <= 5)
    {
        num_crewmates = n;
    }
}

//Sets the number of finished tasks
//Parameter: int representing the number of finished tasks
void CrewmatePlayer::setNumFinishedTasks(int n)
{
    if (n >= 0 && n < 3)
    {
        num_finished_tasks = n;
    }
}

//Sets the round number
//Parameter: an integer representing the round number
void CrewmatePlayer::setRound(int r)
{
    if (r <= 0)
    {
        round = r;
    }
}

//Sets the color of the player
//Parameter: string representing a valid color
void CrewmatePlayer::setColor(string c)
{
    if (c == "red" || c == "blue" || c == "green" || c == "yellow" || c == "orange" || c == "black" || c == "white" || c == "purple" || c == "cyan" || c == "brown" || c == "lime")
    {
        color = c;
    }
}

//Sets the emergency meeting status
//Parameter: boolean representing the status of the emergency meeting
void CrewmatePlayer::setEmergencyMeeting(bool e)
{
    emergency_meeting = e;
}

//Gets the number of crewmates
//Return: int number of crewmates
int CrewmatePlayer::getNumCrewmates()
{
    return num_crewmates;
}

//Gets the number of finished tasks
//Return: int number of finished tasks
int CrewmatePlayer::getNumFinishedTasks()
{
    return num_finished_tasks;
}

//Gets current round number
//Return: int round number
int CrewmatePlayer::getRound()
{
    return round;
}

//Gets color of player
//Return: string player color
string CrewmatePlayer::getColor()
{
    return color;
}

//Gets emergency meeting status
//Return: bool emergency meeting
bool CrewmatePlayer::getEmergencyMeeting()
{
    return emergency_meeting;
}