#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "crewmateNPC.h"
#include "ImposterPlayer.h"
#include "Tasks.h"
#include "CrewmatePlayer.h"
#include "AmongUs.h"
#include "Room.h"

using namespace std;

//Function takes a string and makes all of its characters lowercase
//Parameter: string to be made lower case
//Return: returns lowercase string
string lower(string str)
{
    int temp_num = 0;
    char temp;
    for (int i = 0; i < (int)str.length(); i++) {
        temp = str[i];
        if (isupper(temp))
        {
            temp_num = int(temp);
            temp_num += 32;
            temp = char(temp_num);
            str[i] = temp;
        }
    }
    return str;
}

//normal split function modified to not include spaces
//Function splits a string by a defined delimiter and stores the parts in an array
//Parameters: String to be split, character delimiter, string array, size of said array
//Return: num splits, outputs split array
int split(string str, char separator, string arr[], int size)
{
    if (str.length() == 0) // if the string is empty then it returns 0
    {
        return 0;
    }

    str += separator; // adds the separator to the end of the string
    string temp = ""; // a string to store the words before, after and between the separator

    int count = 0; // the number of times separator is in the string str

    for (int i = 0; i < str.length(); i++) // goes through each the string str
    {
        if (str[i] != separator)
        {
            if (str[i] != ' ')
            {
                temp += str[i]; // if thes string is not the separator then each string is added to the string temp
            }
        }
        else
        {
            arr[count] = temp; // adds the word to the array 
            count++;
            temp = ""; // temp is reset to an empty string
        }
    }

    if (count > size) // if the string is split into more pieces than the size of the arry 
    {
        return -1;
    }

    return count; // returns the number of pieces the sting was split into an integer  
}

//Function defines the difficulty of the game from a txt file
//Parameters: string that represents the difficulty, CrewmatePlayer object user to set difficulty for
//Return: no return but sets difficulty for game
void setCrewmateDifficulty(string difficulty, CrewmatePlayer& user)
{
    ifstream difficulty_settings;
    difficulty_settings.open("c_difficulty.txt");
    string line;
    string temp_array[5];
    int count = 3;
    string diff_string = difficulty;
    diff_string[0] = toupper(diff_string[0]);   //Converts the easier inputted difficulty into the formatting of the txt
    diff_string = diff_string + ':';
    if (!difficulty_settings.fail())
    {
        while (getline(difficulty_settings, line))
        {
            if (line[line.length() - 1] == '\r' || line[line.length() - 1] == '\n') //string cleaner
            {
                line = line.substr(0, line.length() - 1);
            }
            if (line == diff_string) //checks where the difficulty definition is in the txt file
            {
                getline(difficulty_settings, line);
                split(line, '=', temp_array, 5);
                user.setNumCrewmates(stoi(temp_array[1]));
                getline(difficulty_settings, line);
                split(line, '=', temp_array, 5);
                user.setNumFinishedTasks(stoi(temp_array[1]));
                getline(difficulty_settings, line);
                split(line, '=', temp_array, 5);
                if (lower(temp_array[1]).substr(0, 4) == "true")
                {
                    user.setEmergencyMeeting(true);
                }
                else
                {
                    user.setEmergencyMeeting(false);
                }
                if (user.getNumCrewmates() == 0)
                {
                    cout << "difficulty boundaries not met. check tutorial for correct values." << endl;
                    cout << "number of finished tasks must be between 1 and 2" << endl;
                    cout << "number of crewmates must be between 2 and 5" << endl;
                }
                return;
            }
        }
    }
    else
    {
        cout << "difficulty file not found" << endl;
    }


}

//Function defines the difficulty of the game from a txt file for Imposter
//Parameters: string that represents the difficulty, ImposterPlayer object user to set difficulty for
//Return: no return but sets difficulty for game
void setImposterDifficulty(string difficulty, ImposterPlayer& user)
{
    ifstream difficulty_settings;
    difficulty_settings.open("i_difficulty.txt");
    string line;
    string temp_array[5];
    int count = 3;
    string diff_string = difficulty;
    diff_string[0] = toupper(diff_string[0]);   //Converts the easier inputted difficulty into the formatting of the txt
    diff_string = diff_string + ':';
    if (!difficulty_settings.fail())
    {
        while (getline(difficulty_settings, line))
        {
            if (line[line.length() - 1] == '\r' || line[line.length() - 1] == '\n') //string cleaner
            {
                line = line.substr(0, line.length() - 1);
            }
            if (line == diff_string) //checks where the difficulty definition is in the txt file
            {
                getline(difficulty_settings, line);
                split(line, '=', temp_array, 5);
                user.setNumCrewmates(stoi(temp_array[1]));
                getline(difficulty_settings, line);
                split(line, '=', temp_array, 5);
                user.setTotalRounds(stoi(temp_array[1]));
                if (user.getNumCrewmates() == 0)
                {
                    cout << "difficulty boundaries not met. check tutorial for correct values." << endl;
                    cout << "number of finished tasks must be between 1 and 2" << endl;
                    cout << "number of crewmates must be between 2 and 5" << endl;
                }
                return;
            }
        }
    }
    else
    {
        cout << "difficulty file not found" << endl;
    }


}

//Function runs the encryption task
//Parameters: none
//Return: Returns 1 if task completed correctly and 0 if task failed
int task1()
{
    ifstream words;
    string line;
    string plaintext;
    string temp_string;
    int count = 0;
    int word_num = 0;
    srand(time(NULL));
    char array[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
    char cipher[26];
    int start = rand() % (26);
    for (int i = 0; i < 26; i++) // creates an incredibly basic cypher, just starts the alphabet at a different point
    {
        if ((start + i) < 26)
        {
            cipher[i] = array[start + i]; //cipher at index is equal to the value in the alphabet array offset by some random value
        }
        else
        {
            start = -i; // restarts the array when it hits Z
            i--;
        }
    }
    // Then both are printed
    cout << "Alphabet: " << endl;
    for (int i = 0; i < 26; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    cout << "Cypher: " << endl;
    for (int i = 0; i < 26; i++)
    {
        cout << cipher[i] << " ";
    }
    srand(time(NULL));
    word_num = rand() % 975;
    words.open("wiki-100k.txt"); // List of most common english words from h3xx
    if (!words.fail())
    {
        while (getline(words, line)) // pulls the word at the randomly generated line
        {
            count++;
            if (count == word_num)
            {
                plaintext = lower(line);
                break;
            }
        }
        cout << endl;
        cout << "Ciphertext: " << endl;
        for (int i = 0; i < plaintext.length(); i++)
        {
            cout << cipher[int(plaintext[i]) - 97];
        }
        cout << endl;
        cout << "Plaintext: ";
        getline(cin, temp_string);
        cout << endl;
        if (lower(temp_string) == lower(plaintext) || temp_string == "uhoh")
        {
            cout << "Correct" << endl;
            cout << endl;
            return 1;
        }
        else
        {
            cout << "Incorrect" << endl;
            cout << endl;
            return 0;
        }
    }
    else
    {
        cout << "Commonly used words txt file missing. Please locate it as the game cannot function without it." << endl;
    }
    return 0;
}

//Function runs the wires task
//Parameters: none
//Return: Returns 1 if task completed correctly and 0 if task failed
int task2()
{
    vector<int> numbers{ 1, 2, 3, 4, 5, 6, 7, 8 };
    vector<int> answers(8);
    int num_stored = 0;
    int num_array[8] = { 0 };
    int temp_num = 0;
    bool exists = false;
    bool correct = true;
    string temp_string;
    srand(time(NULL));
    random_shuffle(numbers.begin(), numbers.end()); //shuffles the numbers one through eight using a built-in rng
    cout << "_________________" << endl;
    cout << "|1" << "             " << numbers.at(0) << "|" << endl; //Prints all the wires and their ports
    cout << "|2" << "             " << numbers.at(1) << "|" << endl;
    cout << "|3" << "             " << numbers.at(2) << "|" << endl;
    cout << "|4" << "             " << numbers.at(3) << "|" << endl;
    cout << "|5" << "             " << numbers.at(4) << "|" << endl;
    cout << "|6" << "             " << numbers.at(5) << "|" << endl;
    cout << "|7" << "             " << numbers.at(6) << "|" << endl;
    cout << "|8" << "             " << numbers.at(7) << "|" << endl;
    cout << "────────────────" << endl;
    cout << endl;
    cout << "Connect the wires: " << endl;
    for (int i = 0; i < 8; i++)   //sets up the formatting and prompts user for the corresponding wire position
    {
        cout << i + 1 << ": ";
        getline(cin, temp_string);
        while (!isdigit(temp_string[0]))
        {
            cout << "Invalid Input" << endl;
            getline(cin, temp_string);
        }
        if (temp_string == "uhoh")         //cheat
        {
            return 1;
        }
        answers.at(i) = stoi(temp_string);
    }
    cout << endl;
    for (int i = 0; i < 8; i++) //Checks to see if the orientation is correct
    {
        if ((i + 1) != numbers.at((answers.at(i)) - 1))
        {
            correct = false;
            break;
        }
    }
    if (correct) // returns a win or a loss
    {
        cout << "Nice Job." << endl;
        cout << endl;
        return 1;
    }
    else
    {
        cout << "Ouch" << endl;
        cout << endl;
        return 0;
    }
    return 0;
}

//Function runs the lights task
//Parameters: none
//Return: Returns 1 if task completed correctly and 0 if task failed
int task3()
{
    vector<int> numbers(8);
    srand(time(NULL));
    for (int i = 0; i < 8; i++)
    {
        numbers.at(i) = (rand() % 2);
    }
    vector<int> answers(8);
    bool correct = true;
    string temp_string;

    for (int i = 0; i < 8; i++) //sets the answer values to opposite the set power values
    {
        if (numbers.at(i) == 0)
        {
            answers.at(i) = 1;
        }
        else
        {
            answers.at(i) = 0;
        }
    }
    for (int i = 0; i < 8; i++) //prints the current power on/off in terms of ones and zeroes
    {
        if (numbers.at(i) == 1)
        {
            cout << "_____________________" << endl;
            cout << "|              ║     |" << endl;
            cout << "|   ON         ║     |" << endl;
            cout << "|              ║     |" << endl;
            cout << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯" << endl;
        }
        else
        {
            cout << "_____________________" << endl;
            cout << "|    ║               |" << endl;
            cout << "|    ║     OFF       |" << endl;
            cout << "|    ║               |" << endl;
            cout << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯" << endl;
        }

    }
    cout << "Turn all the lights on. If a switch is on, print 'leave'. If a switch is off, print 'flip' to turn it on." << endl;
    for (int i = 0; i < 8; i++)   //sets up the formatting and prompts user for the corresponding wire position
    {
        cout << i + 1 << ": ";
        while (getline(cin, temp_string))
        {
            if (temp_string == "uhoh")
            {
                return 1;
            }
            if (lower(temp_string) == "flip" || lower(temp_string) == "leave")
            {
                break;
            }
            else
            {
                cout << "Invalid input. Use 'flip' or 'leave'" << endl;
                cout << i + 1 << ": ";
            }

        }
        if (lower(temp_string) == "flip")
        {
            answers.at(i) = 1;
        }
        if (lower(temp_string) == "leave")
        {
            answers.at(i) = 0;
        }
    }
    cout << endl;
    for (int i = 0; i < 8; i++) //Checks to see if the orientation is correct
    {
        if (numbers.at(i) == answers.at(i))
        {
            correct = false;
            break;
        }
    }
    if (correct) // returns a win or a loss
    {
        cout << "Nice Job." << endl;
        cout << endl;
        return 1;
    }
    else
    {
        cout << "Ouch!" << endl;
        cout << endl;
        return 0;
    }
    return 0;
}

//Function checks a room and allows for killing or venting when playing as imposter
//Parameters: an ImposterPlayer object to be modified, an array of CrewmateNPC objects, integer that represents room choice
//Return: returns 1 if a player is killed, -1 if a player is not killed, 0 if no one is in the room
int checkRoom(ImposterPlayer& player, CrewmateNPC a[], int choice)
{
    string temp_string;
    for (int i = 0; i < player.getNumCrewmates(); i++)
    {
        if (a[i].getRoom() == choice)
        {
            cout << a[i].getColor() << " is in this room." << endl;
            cout << "Kill? (yes/no): ";
            getline(cin, temp_string);
            cout << endl;
            while (temp_string != "yes" && temp_string != "no")
            {
                cout << "Invalid input, must be 'yes' or 'no'" << endl;
                getline(cin, temp_string);
            }
            if (temp_string == "yes")
            {
                a[i].setAlive(false);
                player.setNumKills(player.getNumKills() + 1);
                cout << a[i].getColor() << " is dead" << endl;
                cout << endl;
                cout << "Round " << player.getRound() + 1 << " over." << endl;
                cout << endl;
                return 1;
            }
            else
            {
                cout << "Round " << (player.getRound() + 1) << " over." << endl;
                cout << endl;
                return -1;
            }
        }
    }
    cout << "No one in this room." << endl;
    cout << endl;
    return 0;
}

//Default constructor for the AmongUs game class
//Parameters: none 
AmongUs::AmongUs()
{
    crewmates;
    game_num = 0;
}

//Default constructor for the AmongUs game class
//Parameters: crewmatenpc array, task object array, integer for game_num
AmongUs::AmongUs(CrewmateNPC a[], Tasks t[], int n)
{
    for (int i = 0; i < 5; i++)
    {
        crewmates[i] = a[i];
    }
    t[0] = Tasks(false, lower("Encryption"), 0);
    t[1] = Tasks(false, "Wires", 0);
    t[2] = Tasks(false, "Lights", 0);
    game_num = n;
}

//Sets a certain CrewmateNPC array as the crewmate array of the AmongUs object
//Parameters: CrewmateNPC object array
void AmongUs::setCrewmateArray(CrewmateNPC a[])
{
    for (int i = 0; i < 5; i++)
    {
        crewmates[i] = a[i];
    }
}

//Sets a certain Task array as the task array of the AmongUs object
//Parameters: Task object array
void AmongUs::setTaskArray(Tasks t[])
{
    for (int i = 0; i < 5; i++)
    {
        task_array[i] = t[i];
    }
}

//Runs the main menu and allows for access to the rest of the game
//No parameters
//Returns a 1 to play as crewmate, 2 to play as imposter, 0 to end
int AmongUs::mainMenu()
{
    ifstream tutorial;
    ifstream statistics;
    string line;
    string temp_string;
    int choice = 0;
    int subchoice = 0;
    while (choice != 6)
    {
        cout << "Among Us" << endl;
        cout << "1. Play as Crewmate" << endl;
        cout << "2. Play as Imposter" << endl;
        cout << "3. Task Practice" << endl;
        cout << "4. Tutorial" << endl;
        cout << "5. Statistics" << endl;
        cout << "6. Quit" << endl;
        cout << "Menu option: ";
        getline(cin, temp_string);
        cout << endl;
        if (isdigit(temp_string[0]))
        {
            choice = stoi(temp_string);
        }
        else
        {
            choice = 7; //sets to an invalid input
        }
        temp_string = "";
        switch (choice)
        {
        case (1):
            return (1);
            break;
        case (2):
            return (2);
            break;
        case (3):
            while (subchoice != 4)
            {
                cout << "What task do you want to practice?" << endl;
                cout << "1. Encryption" << endl;
                cout << "2. Wires" << endl;
                cout << "3. Lights" << endl;
                cout << "4. Return to Main Menu" << endl;
                cout << "Menu option: ";
                getline(cin, temp_string);
                cout << endl;
                if (isdigit(temp_string[0]))
                {
                    subchoice = stoi(temp_string);
                }
                else
                {
                    subchoice = 5; // sets to an invalid input
                }
                switch (subchoice)
                {
                case (1):
                    task1();
                    break;
                case (2):
                    task2();
                    break;
                case (3):
                    task3();
                    break;
                case (4):
                    break;
                default:
                    cout << "Invalid Input" << endl;
                }
            }
            break;
        case (4):
            tutorial.open("among_us_tutorial.txt");
            if (!tutorial.fail())
            {
                while (getline(tutorial, line))
                {
                    cout << line << endl;
                }
                tutorial.close();
            }
            else
            {
                cout << "Tutorial file not found. Make sure it wasn't deleted or moved." << endl;
            }
            break;
        case (5):
            statistics.open("player_statistics.txt");
            if (!statistics.fail())
            {
                while (getline(statistics, line))
                {
                    if (line == "")
                    {
                        cout << "You haven't played any games yet. Statistics will appear after you've played at least one game." << endl;
                        break;
                    }
                    cout << line << endl;
                }
                statistics.close();
            }
            else
            {
                cout << "Statistics file not found. Make sure it wasn't deleted or moved." << endl;
            }
            break;
        case (6):
            break;
        default:
            if (choice < 1 || choice > 6)
            {
                cout << "Invalid Input" << endl;
            }
            break;
        }
    }
    return 0;
}

//Runs the imposter game, more elaboration in tutorial and comments within this function
//Parameters: CrewmateNPC array
//Return: nothing. Stats are logged via a text file.
void AmongUs::playImposter(CrewmateNPC a[])
{
    srand(time(NULL));
    string won;
    int denominator = 1000;
    int numerator = 0;
    int probability = 0;
    bool victory = false;
    cout << "Enter difficulty: ";
    string temp_string;
    string difficulty;
    while (true) //sets difficulty
    {
        getline(cin, temp_string);
        if (lower(temp_string) == "easy" || lower(temp_string) == "normal" || lower(temp_string) == "hard" || lower(temp_string) == "custom")
        {
            break;
        }
        else
        {
            cout << "Invalid input. Use 'easy', 'normal', 'hard', or 'custom'." << endl;
        }
    }
    ImposterPlayer player = ImposterPlayer();
    setImposterDifficulty(temp_string, player);
    difficulty = temp_string;
    difficulty[0] = difficulty[0] - 32;
    temp_string = "";
    int choice = -2;
    cout << "Choose color: ";
    while (true) //sets color
    {
        getline(cin, temp_string);
        if (temp_string == "red" || temp_string == "blue" || temp_string == "green" || temp_string == "yellow" || temp_string == "orange" || temp_string == "black" || temp_string == "white" || temp_string == "purple" || temp_string == "cyan" || temp_string == "brown" || temp_string == "lime")
        {
            break;
        }
        cout << "Invalid Input. Must be red, blue, green, yellow, orange, black, white, purple, cyan, brown, and lime" << endl;
    }
    cout << endl;
    player.setColor(temp_string);
    vector <string> color{ "red", "blue", "green", "yellow", "orange", "black", "white", "purple", "cyan", "brown", "lime" };
    for (int i = 0; i < 10; i++)
    {
        if (color.at(i) == player.getColor()) //Takes out the color that the user chose
        {
            color.erase(color.begin() + i);
        }
    }
    random_shuffle(color.begin(), color.end());
    for (int i = 0; i < player.getNumCrewmates(); i++) //Sets up NPC Crewmate Array
    {
        a[i].setAlive(true);
        a[i].setColor(color.at(i));
    }
    Room array[10];
    array[0] = Room("Cafeteria", -1);    //sets up rooms
    array[1] = Room("Engine", 2);        //the integer is where they can vent to from the room
    array[2] = Room("Reactor", 1);        //if its -1 there is no vent.
    array[3] = Room("MedBay", 4);
    array[4] = Room("Security", 5);
    array[5] = Room("Electrical", 3);
    array[6] = Room("Storage", -1);
    vector <int> room_loc{ 0, 1, 2, 3, 4, 5, 6 };

    while (victory == false)
    {
        cout << "1: Check Rooms" << endl;
        cout << "2: Sabotage Room" << endl;
        cout << "Action: ";
        getline(cin, temp_string);
        cout << endl;
        while (temp_string[0] != '1')
        {
            if (temp_string[0] != '2')
            {
                cout << "Invalid input" << endl;
                getline(cin, temp_string);
            }
            else
            {
                break;
            }
        }
        choice = stoi(temp_string);
        temp_string = "";
        switch (choice)
        {
        case(1):
            while (true)
            {
                for (int i = 0; i < 7; i++)
                {
                    if (find(room_loc.begin(), room_loc.end(), i) != room_loc.end())
                    {
                        cout << i << ": " << array[i].getName() << endl;
                    }
                }
                random_shuffle(room_loc.begin(), room_loc.end());          //Randomly ordering rooms to assign to crewmates
                for (int i = 0; i < player.getNumCrewmates(); i++)
                {
                    if (i < player.getNumCrewmates())
                    {
                        if (a[i].getAlive() == true)              //Only puts living crewmates in rooms
                        {
                            a[i].setRoom(room_loc.at(i));
                            //cout << a[i].getRoom() << endl;                    //cheat
                        }
                        else
                        {
                            a[i].setRoom(-1);
                            //i--;
                        }
                    }
                }
                cout << "Go to: ";
                getline(cin, temp_string);
                cout << endl;
                if (isdigit(temp_string[0]))
                {
                    choice = stoi(temp_string);
                }
                else
                {
                    choice = 7;
                }
                temp_string = "";
                if (find(room_loc.begin(), room_loc.end(), choice) != room_loc.end()) //checks to make sure value is valid and room has not been sabotaged
                {
                    if (checkRoom(player, a, choice) == 0) //checks the room, if a player gets a kill then the next bit of code is skipped
                    {
                        if (array[choice].checkVent() != -1) //checks if venting is an option
                        {
                            cout << "Vent? (yes/no)" << endl;
                            getline(cin, temp_string);
                            while (temp_string != "yes" && temp_string != "no")
                            {
                                cout << "Invalid input, must be 'yes' or 'no'" << endl;
                                getline(cin, temp_string);
                            }
                            if (temp_string == "yes") //vent
                            {
                                checkRoom(player, a, array[choice].checkVent());   //runs check room again
                            }
                        }
                    }
                    break;
                }
                else
                {
                    cout << "Invalid Input. Value could be out of range, or could be a room that has been sabotaged. Try another";
                }
            }
            break;
        case(2):        // Sets up sabotage option
            if (room_loc.size() > (player.getNumCrewmates() - player.getNumKills() + 1))
            {
                cout << "Which room would you like to sabotage?" << endl;
                cout << endl;
                while (true) {
                    getline(cin, temp_string); //input validation
                    cout << endl;
                    if (isdigit(temp_string[0]))
                    {
                        choice = stoi(temp_string);
                        if (choice >= 0 && choice <= 6)
                        {
                            break;
                        }
                        else
                        {
                            cout << "Invalid input" << endl;
                        }
                    }
                }
                for (int i = 0; i < room_loc.size(); i++)
                {
                    if (room_loc.at(i) == choice)
                    {
                        room_loc.erase(room_loc.begin() + i);
                        cout << array[choice].getName() << " was sabotaged." << endl;
                        cout << endl;
                        break;
                    }
                    else if (i == room_loc.size() - 1)
                    {
                        cout << "You have probably already sabotaged this room. Try another." << endl;
                        cout << endl;
                    }

                }
            }
            else
            {
                cout << "Sorry there are not enough rooms for each crewmate. You should be fine without sabotaging for right now." << endl;
            }
            break;
        default:
            cout << "Invalid input" << endl;
            break;
        }

        if ((player.getNumKills() + 2) >= player.getNumCrewmates())
        {
            victory = true;
            cout << "Ship successfully sabotaged." << endl;
            cout << endl;
        }
        else
        {
            victory = false;
        }
        numerator = (pow(2, player.getTotalRounds()) / 25) * pow(player.getRound(), 2); //uses an exponential equation to make a difficulty that becomes harder as time goes on
        int temp_int = rand() % denominator;
        if (temp_int <= numerator)
        {
            victory = false;
            cout << "All tasks completed" << endl;
            cout << endl;
            break;
        }
        player.setRound(player.getRound() + 1);
    }
    if (victory)
    {
        won = "won";
    }
    else
    {
        won = "lost";
    }
    ofstream stats; //Logging game stats
    stats.open("player_statistics.txt", ofstream::app);
    if (!stats.fail())
    {
        stats << difficulty << " Imposter Game " << won << " with " << player.getNumKills() << " kills.";
        stats << " Lasted " << player.getRound() << " round(s)." << '\n';
    }
}

//Runs the crewmate game, more elaboration in tutorial and comments within this function
//Parameters: CrewmateNPC array, Task object array
//Return: nothing. Stats are logged via a text file.
void AmongUs::playCrewmate(CrewmateNPC a[], Tasks t[])
{
    CrewmateNPC Imposter;
    srand(time(NULL));
    vector <int> num{ 0, 1, 2 };
    random_shuffle(num.begin(), num.end());
    string won;
    int num_attempts = 0;
    int choice;
    cout << "Enter difficulty: ";
    string temp_string;
    string difficulty;
    while (true) //sets difficulty
    {
        getline(cin, temp_string);
        if (lower(temp_string) == "easy" || lower(temp_string) == "normal" || lower(temp_string) == "hard" || lower(temp_string) == "custom")
        {
            break;
        }
        else
        {
            cout << "Invalid input. Use 'easy', 'normal', 'hard', or 'custom'." << endl;
        }
    }
    CrewmatePlayer player = CrewmatePlayer();
    setCrewmateDifficulty(temp_string, player);
    difficulty = temp_string;
    difficulty[0] = difficulty[0] - 32;
    temp_string = "";
    int death_count = 0;
    cout << "Choose color: ";
    getline(cin, temp_string);
    while (true) //sets color
    {
        if (temp_string == "red" || temp_string == "blue" || temp_string == "green" || temp_string == "yellow" || temp_string == "orange" || temp_string == "black" || temp_string == "white" || temp_string == "purple" || temp_string == "cyan" || temp_string == "brown" || temp_string == "lime")
        {
            break;
        }
        cout << "Invalid Input. Must be red, blue, green, yellow, orange, black, white, purple, cyan, brown, and lime" << endl;
        getline(cin,temp_string);
    }
    cout << endl;
    player.setColor(temp_string);
    vector <string> color{ "red", "blue", "green", "yellow", "orange", "black", "white", "purple", "cyan", "brown", "lime" };
    for (int i = 0; i < 10; i++)
    {
        if (color.at(i) == player.getColor()) //Takes out the color that the user chose
        {
            color.erase(color.begin() + i);
        }
    }
    random_shuffle(color.begin(), color.end());
    for (int i = 0; i < player.getNumCrewmates(); i++) //Sets up NPC Crewmate Array
    {
        a[i].setAlive(true);
        a[i].setColor(color.at(i));
    }
    int imposter_index = rand() % player.getNumCrewmates();
    Imposter = a[imposter_index];
    int count = 0;
    for (int i = 0; i < (3 - player.getNumFinishedTasks()); i++)
    {
        switch (num.at(i)) // runs through the tasks in random order
        {
        case(0):
            while (t[0].getFinished() == false)
            {
                t[0].setFinished(task1());
                num_attempts++;
            }
            t[0].setAttempts(num_attempts);
            num_attempts = 0;
            player.setRound(player.getRound() + t[0].getAttempts());
            break;
        case(1):
            while (t[1].getFinished() == false)
            {
                t[1].setFinished(task2());
                num_attempts++;
            }
            t[1].setAttempts(num_attempts);
            num_attempts = 0;
            player.setRound(player.getRound() + t[1].getAttempts());
            break;
        case(2):
            while (t[2].getFinished() == false)
            {
                t[2].setFinished(task3());
                num_attempts++;
            }
            t[2].setAttempts(num_attempts);
            num_attempts = 0;
            player.setRound(player.getRound() + t[2].getAttempts());
            break;
        default:
            break;
        }
        for (int j = 0; j < (t[num.at(i)].getAttempts()); j++)
        {
            if (death_count == player.getNumCrewmates() && player.getNumCrewmates() > 0)
            {
                break;
            }
            if (rand() % 2 == 1) //Crewmate kill probability
            {
                a[death_count].setAlive(false);
                cout << a[death_count].getColor() << " died." << endl;
                death_count++;
            }
        }
        cout << player.getNumCrewmates() - death_count << " crewmates remaining." << endl;
        cout << endl;
        if (player.getEmergencyMeeting())
        {
            cout << "Emergency Meeting? (yes/no): ";          //Emergency Meeting
            getline(cin, temp_string);
            while (temp_string != "yes" && temp_string != "no")
            {
                cout << "Invalid input, must be 'yes' or 'no'" << endl;
                getline(cin, temp_string);
            }
            if (temp_string == "yes")
            {
                temp_string = "";
                for (int i = 0; i < player.getNumCrewmates(); i++) //Lists living crewmates
                {
                    if (a[i].getAlive())
                    {
                        cout << i << ": " << a[i].getColor() << endl;
                        count++;
                    }
                }
                cout << "Eject: ";
                while (true)
                {
                    getline(cin, temp_string);
                    if (isdigit(temp_string[0]))
                    {
                        choice = stoi(temp_string);
                        break;
                    }
                    else
                    {
                        cout << "Invalid Input" << endl;
                    }
                }
                if (imposter_index == choice) {
                    cout << Imposter.getColor() << " was the imposter. Victory." << endl;
                    death_count == player.getNumCrewmates() - 1;
                    break;
                }
                else
                {
                    cout << Imposter.getColor() << " was not the imposter and was ejected" << endl;
                    a[imposter_index].setAlive(false);
                }
            }
            player.setEmergencyMeeting(false);
        }
        if (death_count == player.getNumCrewmates()) //Calculates loss condition
        {
            cout << "Imposter won." << endl;
            cout << endl;
            won = "Lost";
            break;
        }
    }
    if (death_count < player.getNumCrewmates())
    {
        won = "Won";
        cout << "You successfully completed all tasks" << endl;
        cout << endl;
    }
    ofstream stats; //Logging game stats
    stats.open("player_statistics.txt", ofstream::app); //NEEDS A WAY TO SKIP FILLED LINES, ADD DIFFICULTY
    if (!stats.fail())
    {
        stats << difficulty << " Crewmate Game " << won << " with " << player.getNumCrewmates() - death_count << " crewmates remaining.";
        if (t[0].getAttempts() != 0)
        {
            stats << " Encryption completed in " << t[0].getAttempts() << " attempts.";
        }
        else
        {
            stats << " Encryption not completed.";
        }
        if (t[1].getAttempts() != 0)
        {
            stats << " Wires completed in " << t[1].getAttempts() << " attempts.";
        }
        else
        {
            stats << " Wires not completed.";
        }
        if (t[2].getAttempts() != 0)
        {
            stats << " Lights completed in " << t[2].getAttempts() << " attempts." << '\n';
        }
        else
        {
            stats << " Lights not completed." << '\n';
        }

    }
}

//Increments the game num, modifying the value by 1
//Parameters: an integer
//Return: nothing
void AmongUs::incrementGameNum()
{
    game_num ++;
}

//Gets the game number
//Return: game number integer
int AmongUs::getGameNum()
{
    return game_num;
}