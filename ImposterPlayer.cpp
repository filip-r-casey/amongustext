#include <iostream>
#include <string>
#include "crewmateNPC.h"
#include "ImposterPlayer.h"

using namespace std;

//Default Constructor
ImposterPlayer::ImposterPlayer()
{
    color = "";
    num_kills = 0;
    num_crewmates = 0;
    round = 0;
}

//Parameterized Constructor
//Parameters: CrewmateNPC object array, player color string, number of kills int, number of crewmates int, current round int
ImposterPlayer::ImposterPlayer(CrewmateNPC a[], string c, int k, int n, int r)
{
    color = c;
    num_kills = k;
    num_crewmates = n;
    round = r;
}

//Sets the color of the player
//Parameter: color string
void ImposterPlayer::setColor(string c)
{
    color = c;
}

//Sets the number of kills the player has
//Parameter: Number of kills string
void ImposterPlayer::setNumKills(int k)
{
    num_kills = k;
}

//Sets the number of crewmates
//Parameter: int number of crewmates
void ImposterPlayer::setNumCrewmates(int n)
{
    num_crewmates = n;
}

//Sets the current round number
//Parameter: int representing current round number
void ImposterPlayer::setRound(int r)
{
    round = r;
}

//Sets the number of total rounds
//Parameter: int representing total number of rounds
void ImposterPlayer::setTotalRounds(int tr)
{
    total_rounds = tr;
}

//Gets the player color
//Return: string color of player
string ImposterPlayer::getColor()
{
    return color;
}

//Gets the number of kills
//Return: int representing number of kills
int ImposterPlayer::getNumKills()
{
    return num_kills;
}

//Gets the number of crewmates
//Return: int representing the number of crewmates
int ImposterPlayer::getNumCrewmates()
{
    return num_crewmates;
}

//Gets the current round
//Return: Current round int
int ImposterPlayer::getRound()
{
    return round;
}

//Gets the total number of rounds
//Return: int total rounds
int ImposterPlayer::getTotalRounds()
{
    return total_rounds;
}