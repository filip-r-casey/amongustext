#include <iostream>
#include <string>
#include <fstream>
#include "AmongUs.h"

using namespace std;

//This is what actually runs the game
int main()
{
    CrewmateNPC array[5];
    Tasks tasks[3];
    string temp_string;
    AmongUs game_1;
    int choice;
    do //Game will run until quit from the main menu
    {
        choice = game_1.mainMenu();
        switch (choice)
        {
        case (1):
            game_1.playCrewmate(array, tasks);
            game_1.incrementGameNum();
            break;
        case (2):
            game_1.playImposter(array);
            game_1.incrementGameNum();
            break;    
        default:
            break;
        }
    } while (choice != 0);
    cout << "Thanks for playing " << game_1.getGameNum() << " games :)" << endl;
    cout << "Confirm exit by entering any character: ";
    getline(cin, temp_string);

}