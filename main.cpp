// CSCi 1300 Fall 2021
// Author: Bella Longo
// Recitation: Spencer Paulissen
// Project 3 

#include "BestBuy.h"
#include "Player.h"
#include "Hacker.h"
#include "Computer.h"
#include "Map.h"
#include "Game.h"
#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    srand(time(0));
    // VARIABLES
    // name (string) - the user's name
    string name;
    // progress (int) - determines in the player wants to progress in the game or not
    int progress = 0;
    // move (char) - the move that the player wants to execute
    char move;


    // Ask the user to input their name
    cout << "Please enter your name: " << endl;
    cin >> name;
    cout << "Welcome " << name << " to WHERE IN THE CODE IS CARMEN SANDIEGO!" << endl;
    cout << endl;

    // Set defualt values for the game's information
    Game game = Game();
    Player playerName = Player();
    Hacker hackers = Hacker();
    Computer computer = Computer();
    BestBuy bestbuy = BestBuy();
    playerName.setPlayerName(name);

    for(int i = 1; i <= 5; i++)
    {
        Map serverRoomMap = Map();
        serverRoomMap = game.serverRoom(i);
        cout << "Below is a map of the current server room: " << endl;
        serverRoomMap.displayMap();
        cout << endl;
        // Spawn the user in bestBuy 
        bestbuy = game.bestBuy(bestbuy, i);
        // Update the current room's hacker's info
        hackers = game.setHackerInfo(hackers, i, serverRoomMap.getHackerCount());
        playerName.setNumHacekersDefeated(0);
        progress = 0;

        // Show the Map again and ask the user to input a move and print status update
        serverRoomMap.displayMap();
        cout << "Travel the server room" << endl;
        serverRoomMap.displayMoves();
        cout << "Other menu options:" << endl;
        cout << "e (Repair your computer)" << endl;
        cout << "f (Use antivirus software)" << endl;
        cout << "g (Browse StackOverflow)" << endl;
        cout << "h (Status Update)" << endl;
        cout << "i (Quit Game)" << endl;
        cout << "What would you like to do? (input a character)" << endl;
        cin >> move;

        // Keep the player in the serverRoom until they wish to progress
        for(int i = 0; (progress == 0) && (game.gameOver(playerName, hackers, computer) == false) && (move != 'i'); i++)
        {
            switch(move)
            {
                // Move up
                case 'w':
                {
                    // Increase player's frustration by 2
                    playerName.setFrustration(playerName.getFrustration() + 2);

                    // Move the player on the map
                    serverRoomMap.executeMove('w');

                    // If the player is on a hacker spot
                    if(serverRoomMap.isHackerLocation() == true)
                    {
                        // Call fightAHacker function
                        game.fightAHacker(hackers, playerName, bestbuy, computer, serverRoomMap);
                    }
                    // If the player is on a NPC spot
                    else if(serverRoomMap.isNPCLocation() == true)
                    {
                        // Call NPC function
                        game.NPC(bestbuy);
                    }
                    // If the player is on a BestBuy spt
                    else if (serverRoomMap.isBestBuyLocation() == true)
                    {
                        // Call bestBuy function
                        game.bestBuy(bestbuy, i);
                    }

                    // Check to see if a misfortune occured
                    if(game.misfortune(computer, bestbuy, playerName) == true)
                    {
                        
                    }

                    // Check to see if the computer got a virus
                    if(game.getVirus(computer) == true)
                    {
                        // Call the virus function
                        game.getVirus(computer);
                    }

                    // If a computer has viruses, the computer's maintance level will drop by 10 with each action taken
                    if(computer.getnumViruses() > 0)
                    {
                        // The computer's maintance will drop by 10 per virus the computer has
                        computer.setMaintenanceLevel(computer.getMaintenanceLevel() - (10*computer.getnumViruses()));
                    }

                    break;
                }
                // Move left
                case 'a':
                {
                    // Increase player's frustration by 2
                    playerName.setFrustration(playerName.getFrustration() + 2);

                    // Move the player on the map
                    serverRoomMap.executeMove('a');

                    // If the player is on a hacker spot
                    if(serverRoomMap.isHackerLocation() == true)
                    {
                        // Call fightAHacker function
                        game.fightAHacker(hackers, playerName, bestbuy, computer, serverRoomMap);
                    }
                    // If the player is on a NPC spot
                    else if(serverRoomMap.isNPCLocation() == true)
                    {
                        // Call NPC function
                        game.NPC(bestbuy);
                    }
                    // If the player is on a BestBuy spt
                    else if (serverRoomMap.isBestBuyLocation() == true)
                    {
                        // Call bestBuy function
                        game.bestBuy(bestbuy, i);
                    }

                    // Check to see if a misfortune occured
                    if(game.misfortune(computer, bestbuy, playerName) == true)
                    {

                    }

                    // Check to see if the computer got a virus
                    if(game.getVirus(computer) == true)
                    {
                        // Call the virus function
                        game.getVirus(computer);
                    }

                    // If a computer has viruses, the computer's maintance level will drop by 10 with each action taken
                    if(computer.getnumViruses() > 0)
                    {
                        // The computer's maintance will drop by 10 per virus the computer has
                        computer.setMaintenanceLevel(computer.getMaintenanceLevel() - (10*computer.getnumViruses()));
                    }

                    break;
                }
                // Move down
                case 's':
                {
                    // Increase player's frustration by 2
                    playerName.setFrustration(playerName.getFrustration() + 2);

                    // Move the player on the map
                    serverRoomMap.executeMove('s');

                    // If the player is on a hacker spot
                    if(serverRoomMap.isHackerLocation() == true)
                    {
                        // Call fightAHacker function
                        game.fightAHacker(hackers, playerName, bestbuy, computer, serverRoomMap);
                    }
                    // If the player is on a NPC spot
                    else if(serverRoomMap.isNPCLocation() == true)
                    {
                        // Call NPC function
                        game.NPC(bestbuy);
                    }
                    // If the player is on a BestBuy spt
                    else if (serverRoomMap.isBestBuyLocation() == true)
                    {
                        // Call bestBuy function
                        game.bestBuy(bestbuy, i);
                    }

                    // Check to see if a misfortune occured
                    if(game.misfortune(computer, bestbuy, playerName) == true)
                    {

                    }

                    // Check to see if the computer got a virus
                    if(game.getVirus(computer) == true)
                    {
                        // Call the virus function
                        game.getVirus(computer);
                    }

                    // If a computer has viruses, the computer's maintance level will drop by 10 with each action taken
                    if(computer.getnumViruses() > 0)
                    {
                        // The computer's maintance will drop by 10 per virus the computer has
                        computer.setMaintenanceLevel(computer.getMaintenanceLevel() - (10*computer.getnumViruses()));
                    }

                    break;
                }
                // Move right
                case 'd':
                {
                    // Increase player's frustration by 2
                    playerName.setFrustration(playerName.getFrustration() + 2);

                    // Move the player on the map
                    serverRoomMap.executeMove('d');

                    // If the player is on a hacker spot
                    if(serverRoomMap.isHackerLocation() == true)
                    {
                        // Call fightAHacker function
                        game.fightAHacker(hackers, playerName, bestbuy, computer, serverRoomMap);
                    }
                    // If the player is on a NPC spot
                    else if(serverRoomMap.isNPCLocation() == true)
                    {
                        // Call NPC function
                        game.NPC(bestbuy);
                    }
                    // If the player is on a BestBuy spt
                    else if (serverRoomMap.isBestBuyLocation() == true)
                    {
                        // Call bestBuy function
                        game.bestBuy(bestbuy, i);
                    }

                    // Check to see if a misfortune occured
                    if(game.misfortune(computer, bestbuy, playerName) == true)
                    {

                    }

                    // Check to see if the computer got a virus
                    if(game.getVirus(computer) == true)
                    {
                        // Call the virus function
                        game.getVirus(computer);
                    }

                    // If a computer has viruses, the computer's maintance level will drop by 10 with each action taken
                    if(computer.getnumViruses() > 0)
                    {
                        // The computer's maintance will drop by 10 per virus the computer has
                        computer.setMaintenanceLevel(computer.getMaintenanceLevel() - (10*computer.getnumViruses()));
                    }

                    break;
                }
                // Repair computer
                case 'e':
                {
                    // Call repair computer function
                    game.repairComputer(bestbuy, computer);

                    break;
                }
                // Use antivirus software
                case 'f':
                {
                    // Call the user antivirus function
                    game.useAntivirus(bestbuy, computer);

                    break;
                }
                // Browse StackOverflow
                case 'g':
                {
                    // Call the browse stackOverflow function
                    game.browseStackOverflow(bestbuy, playerName);

                    break;
                }
                // Status Update
                case 'h':
                {
                    // Call the status update function
                    game.statusUpdate(playerName, computer, bestbuy, hackers);
                }
                default: cout << "Invalid move. " << endl; break;
            }

            // If the player can progress to the next room
            if (game.canProgress(serverRoomMap, playerName) == true)
            {
                cout << "Do you wish to progress to the next room? " << endl;
                cout << "Input 1 if you wish to go to the next room" << endl;
                cout << "Input 0 if you do not wish to go to the next room" << endl;
                cin >> progress;
            }
            else
            {
                // Show the Map again and ask the user to input a move
                serverRoomMap.displayMap();
                cout << "Travel the server room:" << endl;
                serverRoomMap.displayMoves();
                cout << "Other menu options:" << endl;
                cout << "e (Repair your computer)" << endl;
                cout << "f (Use antivirus software)" << endl;
                cout << "g (Browse StackOverflow)" << endl;
                cout << "h (Status Update)" << endl;
                cout << "i (Quit Game)" << endl;
                cout << "What would you like to do? (input a character)" << endl;
                cin >> move;
            }

        }

        // If the user wishes to progress to the next level
        if(progress == 1)
        {
            cout << "Congrats! You beat this server room, you have now advances to the second server room!" << endl;
        }
        else if(game.gameOver(playerName, hackers, computer) == true)
        {
            return 0;
        }
        // If the user wants to quit the game
        else if(move == 'i')
        {
            cout << "You quit the game, goodbye!" << endl;

            // Have the game end
            return 0;
        }
    }

    return 0;
}
