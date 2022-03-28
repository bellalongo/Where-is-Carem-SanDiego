// CSCi 1300 Fall 2021
// Author: Bella Longo
// Recitation: Spencer Paulissen
// Project 3: Code Skeleton

#include "BestBuy.h"
#include "Player.h"
#include "Hacker.h"
#include "Computer.h"
#include "Map.h"
#include "Game.h"
#include <string>
#include <iostream>
using namespace std;


// CONSTRUCTORS
// Default Constructor
Game::Game()
{
    // Set default values
    serverRoomNum = 1;
    bestbuy = BestBuy();
    computer = Computer();
    playerName = Player();
    hacker = Hacker();
    map = Map();
    serverRoomHackers = Hacker();
    numHackers = 0;
    splitString = "";
    delimiter = ',';
    arraySize = 100;
}

// Parametrized Constructor
Game::Game(int roomNum, BestBuy bb, Computer c, Player pN, Hacker h, Map m, Hacker roomHackers, int hackerNum, string splitS, char delimit, string array[], int size)
{
    serverRoomNum = roomNum;
    bestbuy = bb;
    computer = c;
    playerName = pN;
    hacker = h;
    map = m;
    serverRoomHackers = roomHackers;
    splitString = splitS;
    delimiter = delimit;
    arraySize = size;
}


// FUNCTIONS
Map Game::serverRoom(int serverRoomNum)
{
    Map map = Map();
    // Variables
    // numHackers (int) - the number of hackers in the current server room
    int numHackers = 0;
    // numNPC (int) - the number of NPCs in the current server room
    int numNPC = 0;
    // xLocation (int) - the x location
    int xLocation = 0;
    // yLocation (int) - the y location
    int yLocation = 0;

    // Spawn a random number of hackers from 1 - 3
    numHackers = rand() % 3 + 1;

    // Spawn a random number of NPCS from 1 - 3
    numNPC = rand() % 3 + 1;
    
    // Check if it is the first server room
    if (serverRoomNum == 1)
    {
        // Spawn the bestBuy at the initial location
        map.spawnBestBuy(0,0);
    }
    // Spawn bestBuy
    else
    {
        xLocation = rand() % 8 + 0;
        yLocation = rand() % 4 + 0;

        // If a bestBuy can be spawned there
        if(map.spawnBestBuy(xLocation, yLocation) == true)
        {
            map.spawnBestBuy(xLocation, yLocation);
        }
        // If a bestBuy cannot be spawned there
        else
        {
            // Keep getting new x and y locations until a bestBuy can be spawned there
            while(map.spawnBestBuy(xLocation, yLocation) == false)
            {
                xLocation = rand() % 8 + 0;
                yLocation = rand() % 4 + 0;
            }
            // When a bestBuy can be spawned
            map.spawnBestBuy(xLocation, yLocation);
        }
    }

    // Get the x and y location of the hackers
    for(int i = 1; i <= numHackers; i++)
    {
        xLocation = rand() % 8 + 0;
        yLocation = rand() % 4 + 0;
        
        // If a hacker can be spawned there
        if(map.spawnHacker(xLocation, yLocation) == true)
        {
            map.spawnHacker(xLocation, yLocation);
        }
        // If a hacker cannot be spawned there
        else
        {
            // Keep getting new x and y locations until a hacker can be spawned there
            while(map.spawnHacker(xLocation, yLocation) == false)
            {
                xLocation = rand() % 8 + 0;
                yLocation = rand() % 4 + 0;
            }
            map.spawnHacker(xLocation, yLocation);
        }
    }

    // Get the x and y location for the NPCs
    for(int i = 1; i <= numNPC; i++)
    {
        xLocation = rand() % 8 + 0;
        yLocation = rand() % 4 + 0;
        
        // If a NPC can be spawned there
        if(map.spawnNPC(xLocation, yLocation) == true)
        {
            map.spawnNPC(xLocation, yLocation);
        }
        // If a NPC cannot be spawned there
        else
        {
            // Keep getting new x and y locations until a NPC can be spawned there
            while(map.spawnNPC(xLocation, yLocation) == false)
            {
                xLocation = rand() % 8 + 0;
                yLocation = rand() % 4 + 0;
            }
            map.spawnNPC(xLocation, yLocation);
        }
    }

    map.setHackerCount(numHackers);
    map.setNPCCount(numNPC);

    // Display the map
    return map;
}



/*
    The function gives the user the option to repair their computer
    Name:       repairComputer()
    Parameters:
                bestbuy (BestBuy) - the current BestBuy object currently being user in the game
                computer (Computer) - the current user's computer
    Return Value:
                none
*/
void Game::repairComputer(BestBuy bestbuy, Computer computer)
{
    // Check to see if the user's computer can even be repaired
    if(computer.getMaintenanceLevel() >= 100)
    {
        cout << "Your computer does not need repairing!" << endl;
        cout << endl;

        return;
    }
    // If the computer has a virus, then it also cannot be repaired
    else if(getVirus(computer) == true)
    {
        cout << "Your computer has a virus and cannot be repaired!" << endl;
        cout << endl;

        return;
    }
    // If the computer needs repairing
    else
    {
        // Variables
        // partChoice (string) - the computer part the user wants to repair their computer with
        string partChoice;
        // partAmount (int) - the amount of that specific part that the user wants to use
        int partAmount = 0;

        cout << endl;
        // Print the user's inventory
        cout << "INVENTORY" << endl;
        cout << "CPU: " << bestbuy.getComputerParts("CPU") << endl;
        cout << "GPU: " << bestbuy.getComputerParts("GPU") << endl;
        cout << "Power Supply Unit: " << bestbuy.getComputerParts("Power Supply Unit") << endl;
        cout << "Computer Case: " << bestbuy.getComputerParts("Computer Case") << endl;
        cout << "Internet Card: " << bestbuy.getComputerParts("Internet Card") << endl;
        cout << "Keyboard and Mouse: " << bestbuy.getComputerParts("Keyboard and Mouse") << endl;

        // Ask the user to input the computer part they would like to use
        cout << "Enter the name of the computer part you would like to use: " << endl;
        cin >> partChoice;

        // If they choose to use a CPU
        if (partChoice == "CPU")
        {
            // Ask the user how many parts they want to use
            cout << "How many do you want to use? " << endl;
            cin >> partAmount;

            // If the user has enough of the part
            if((bestbuy.getComputerParts("CPU") - partAmount) >= 0 )
            {
                // Set the value of that computer part
                bestbuy.setComputerPartsAt(0, (bestbuy.getComputerParts("CPU") - partAmount));

                // Increase the value of the maintance level to be 20 times the part amount
                computer.setMaintenanceLevel(computer.getMaintenanceLevel() + (partAmount * 20));
            }
            // If the user does not have enough of the part
            else
            {
                cout << "You do not have enough of the part!" << endl;
            }
        }
        // If they choose to use a GPU
        else if(partChoice == "GPU")
        {
            // Ask the user how many parts they want to use
            cout << "How many do you want to use? " << endl;
            cin >> partAmount;

            // If the user has enough of the part
            if((bestbuy.getComputerParts("GPU") - partAmount) >= 0 )
            {
                // Set the value of that computer part
                bestbuy.setComputerPartsAt(1, (bestbuy.getComputerParts("GPU") - partAmount));

                // Increase the value of the maintance level to be 20 times the part amount
                computer.setMaintenanceLevel(computer.getMaintenanceLevel() + (partAmount * 20));
            }
            // If the user does not have enough of the part
            else
            {
                cout << "You do not have enough of the part!" << endl;
            }
        }
        // If they choose to use a Power Supply Unit
        else if(partChoice == "Power Supply Unit")
        {
            // Ask the user how many parts they want to use
            cout << "How many do you want to use? " << endl;
            cin >> partAmount;

            // If the user has enough of the part
            if((bestbuy.getComputerParts("Power Supply Unit") - partAmount) >= 0 )
            {
                // Set the value of that computer part
                bestbuy.setComputerPartsAt(2, (bestbuy.getComputerParts("Power Supply Unit") - partAmount));

                // Increase the value of the maintance level to be 20 times the part amount
                computer.setMaintenanceLevel(computer.getMaintenanceLevel() + (partAmount * 20));
            }
            // If the user does not have enough of the part
            else
            {
                cout << "You do not have enough of the part!" << endl;
            }
        }
        // If they choose to use a Computer Case
        else if(partChoice == "Computer Case")
        {
            // Ask the user how many parts they want to use
            cout << "How many do you want to use? " << endl;
            cin >> partAmount;

            // If the user has enough of the part
            if((bestbuy.getComputerParts("Computer Case") - partAmount) >= 0 )
            {
                // Set the value of that computer part
                bestbuy.setComputerPartsAt(3, (bestbuy.getComputerParts("Computer Case") - partAmount));

                // Increase the value of the maintance level to be 20 times the part amount
                computer.setMaintenanceLevel(computer.getMaintenanceLevel() + (partAmount * 20));
            }
            // If the user does not have enough of the part
            else
            {
                cout << "You do not have enough of the part!" << endl;
            }
        }
        // If they choose to use a Internet Card
        else if(partChoice == "Internet Card")
        {
            // Ask the user how many parts they want to use
            cout << "How many do you want to use? " << endl;
            cin >> partAmount;

            // If the user has enough of the part
            if((bestbuy.getComputerParts("Internet Card") - partAmount) >= 0 )
            {
                // Set the value of that computer part
                bestbuy.setComputerPartsAt(4, (bestbuy.getComputerParts("Internet Card") - partAmount));

                // Increase the value of the maintance level to be 20 times the part amount
                computer.setMaintenanceLevel(computer.getMaintenanceLevel() + (partAmount * 20));
            }
            // If the user does not have enough of the part
            else
            {
                cout << "You do not have enough of the part!" << endl;
            }
        }
        // If they choose to use a Keyboard and Mouse
        else if(partChoice == "Keyboard and Mouse")
        {
            // Ask the user how many parts they want to use
            cout << "How many do you want to use? " << endl;
            cin >> partAmount;

            // If the user has enough of the part
            if((bestbuy.getComputerParts("Keyboard and Mouse") - partAmount) >= 0 )
            {
                // Set the value of that computer part
                bestbuy.setComputerPartsAt(5, (bestbuy.getComputerParts("Keyboard and Mouse") - partAmount));

                // Increase the value of the maintance level to be 20 times the part amount
                computer.setMaintenanceLevel(computer.getMaintenanceLevel() + (partAmount * 20));
            }
            // If the user does not have enough of the part
            else
            {
                cout << "You do not have enough of the part!" << endl;
            }
        }
        // If the user does not input the correct name
        else
        {
            cout << "You did not input the correct name! Please type carefully next time!" << endl;
        }
    }
}



/*
    The function allows the user to use a piece of antivirus software to remove the viruses
    Name:       useAntivirus()
    Parameters:
                bestbuy (BestBuy) - the BestBuy object currently being used in the game
                computer (Computer) - the current user's computer
    Return Value: 
                none
*/
void Game::useAntivirus(BestBuy bestbuy, Computer computer)
{
    // Variables
    // softwareAmount (int) - the amount of antivirus the user wants to use to get rid of the virus
    int softwareAmount = 0;

    // Check to see if the user has antivirus software that can be used 
    if(bestbuy.getAntiVirusSoftware() > 0)
    {   
        // Tell the user that they can user can use one piece of antivirus software to get rid of the virus
        cout << "Reminder: You can use one USB of antivirus software to remove ALL viruses!" << endl;
        // Ask the user how much software they want to use
        cout << "How many USBs of antivirus software do you wish to use? " << endl;
        cin >> softwareAmount;

        // Update the user's amount of antivirus software
        bestbuy.setAntiVirusSoftware(bestbuy.getAntiVirusSoftware() - softwareAmount);

        // Remove all of the user's viruses
        computer.setNumViruses(0);

        // Tell the user that their viruses have been removed
        cout << "All of your viruses were successfully removed." << endl;
        cout << endl;
    }
    // If the user does not have antivirus software to use
    else
    {
        cout << "You do not have any antivirus software! Maybe visit a BestBuy sometime?" << endl;
        cout << endl;
    }
}



/*
    The function allows the user to browse stackoverflow to reduce frustration
    Name:       browseStackOverflow()
    Parameters:
                bestbuy (BestBuy) - the current bestBuy object being used
                player (Player) - the game's current player
    Return Value:
                none
*/
void Game::browseStackOverflow(BestBuy bestbuy, Player player)
{
    // Variables
    // option (int) - the option of either to complete a puzzle or a game
    int option = 0;

    // Check if their frustration level could be lowered
    if (player.getFrustration() < 5)
    {
        cout << "Player's frustration is already low! Cannot lower frustration!" << endl;
        cout << endl;
        return;
    }

    // Ask the user if they would rather complete a puzzle or a game
    cout << "Welcome to StackOverflow! Would you rather: " << endl;
    cout << "1. Complete a puzzle" << endl;
    cout << "2. Play a game" << endl;
    cout << "Please enter your choice in numeric form (1 or 2) " << endl;
    cin >> option;

    // If the user wishes to complete a puzzle
    if (option == 1)
    {
        // If the user answers the puzzle correctly
        if (puzzle(bestbuy) == true)
        {
            // Lower the user's frustration by 5
            player.setFrustration(player.getFrustration() - 5);

            // Print out the user's current frustration
            cout << "Your frustation level was lowered by 5!" << endl;
            cout << "Your frustration level is now " << player.getFrustration() << endl;
            cout << endl;
            return;
        }
        // If the user answers incorrectly
        else if (puzzle(bestbuy) == false)
        {       
            // Tell the user that their frustration could not be lowered
            cout << "Your frustration could not be lowered! Try again next time!" << endl;
            cout << endl;
            return;
        }
    }
    // If the user wishes to play a play
    else if(option == 2)
    {
        // If the user wins the game
        if (rockPaperScissors() ==  true)
        {
            // Lower the player's frustration by 5
            player.setFrustration(player.getFrustration() - 5);

            // Print out the user's current frustration
            cout << "Your frustation level was lowered by 5!" << endl;
            cout << "Your frustration level is now " << player.getFrustration() << endl;
            cout << endl;
            return;
        }
        // If the user loses the game
        else if (rockPaperScissors() == false)
        {
            // Tell the user that their frustration could not be lowered
            cout << "Your frustration could not be lowered! Try again next time!" << endl;
            cout << endl;
            return;
        }
    }
    // If the user does not select one of the given options
    else
    {
        cout << "You entered an invalid number!! Please be more careful next time!" << endl;
        cout << endl;
        return;
    }
}



/*
    The function has the user interact with an NPC
    Name:       NPC()
    Parameters:
                bestbuy (BestBuy) - the BestBuy object currently being used in the game
    Return Value:
                none
*/
void Game::NPC(BestBuy bestbuy)
{
    // Variables
    // randomNPC (int) - determines the nuetrality of the NPC and assign it a value from 0 - 100
    int randomNPC = rand() % 100;
    // randomPart (int) - the random computer part the user will be awarded with if the NPC is a friend
    int randomPart = 0;
    // whichPartToLose (int) - determines which computer part the user will lose if the NPC is an enemy
    int whichPartToLose = 0;

    cout << "You just ran into a NPC" << endl;
    cout << puzzle(bestbuy) << endl;

    // If the NPC is a friend
    if (randomNPC < 33)
    {
        cout << "The NPC is friendly and wants to give you a gift! " << endl;

        // Give randomPart a value from 0 - 5
        randomPart = rand() % 5;

        // If randomPart = 0, then the user will be awarded a CPU
        if(randomPart == 0)
        {
            cout << "You got a CPU!" << endl;

            bestbuy.setComputerPartsAt(0, (bestbuy.getComputerParts("CPU") + 1));
            cout << endl;
        }
        // If randomPart = 1, then the user will be awared with a GPU
        else if(randomPart == 1)
        {
            cout << "You got a GPU!" << endl;

            bestbuy.setComputerPartsAt(1, (bestbuy.getComputerParts("GPU") + 1));
            cout << endl;
        }
        // If randomPart = 2, then the user will be awarded with a Power Supply Unit
        else if(randomPart == 2)
        {
            cout << "You got a Power Supply Unit!" << endl;

            bestbuy.setComputerPartsAt(2, (bestbuy.getComputerParts("Power Supply Unit") + 1));
            cout << endl;
        }
        // If randomPart = 3, then the user will be awarded with a Computer Case
        else if(randomPart == 3)
        {
            cout << "You got a Computer Case!" << endl;

            bestbuy.setComputerPartsAt(3, (bestbuy.getComputerParts("Computer Case") + 1));
            cout << endl;
        }
        // If randomPart = 4, then the user will be awarded with a Internet Card
        else if(randomPart == 4)
        {
            cout << "You got a Internet Card!" << endl;
            cout << endl;

            bestbuy.setComputerPartsAt(4, (bestbuy.getComputerParts("Internet Card") + 1 ));
        }
        // If randomPart = 5, then the user will be awarded with a Keyboard and Mouse
        else
        {
            cout << "You got a Keyboard and Mouse" << endl;
            cout << endl;

            bestbuy.setComputerPartsAt(5, (bestbuy.getComputerParts("Keyboard and Mouse") + 1));
        }
    }
    // If the NPC is an enemy
    if(randomNPC > 66)
    {
        cout << "The NPC is an enemy and is going to steal something from you!" << endl;

        // The player will also lose a random computer part
        whichPartToLose = rand() % 5;

        // If the user has computer parts to lose
        if(bestbuy.totalComputerParts() > 0)
        {
            // If a CPU will be lost
            if(whichPartToLose == 0)
                {
                    // If there is a CPU to steal
                    if ((bestbuy.getComputerParts("CPU") -1) > 0)
                    {
                        cout << "The NPC stole your CPU!" << endl;
                        cout << endl;
                        bestbuy.setComputerPartsAt(0, bestbuy.getComputerParts("CPU") -1 );
                    } 
                    else
                    {
                        cout << "You had no CPU for the hackers to steal!" << endl;
                        cout << endl;
                    }
                }
            // If the user will lose a GPU
            else if(whichPartToLose == 1)
            {
                // If there is a GPU to steal
                if ((bestbuy.getComputerParts("GPU") -1) > 0)
                {
                    cout << "The GPU stole your CPU!" << endl;
                    cout << endl;
                    bestbuy.setComputerPartsAt(1, bestbuy.getComputerParts("GPU") -1 );
                } 
                else
                {
                    cout << "You had no GPU for the hackers to steal!" << endl;
                    cout << endl;
                }
            }
            // If the user will lose a Power Supply Unit
            else if(whichPartToLose == 2)
            {
                // If there is a Power Supply Unit to steal
                if ((bestbuy.getComputerParts("Power Supply Unit") -1) > 0)
                {
                    cout << "The NPC stole your Power Supply Unit!" << endl;
                    cout << endl;
                    bestbuy.setComputerPartsAt(2, bestbuy.getComputerParts("Power Supply Unit") -1 );
                } 
                else
                {
                    cout << "You had no Power Supply Unit for the hackers to steal!" << endl;
                    cout << endl;
                }
            }
            // If the user will lose a Computer Case
            else if(whichPartToLose == 3)
            {
                // If there is a Computer Case to steal
                if ((bestbuy.getComputerParts("Computer Case") -1) > 0)
                {
                    cout << "The NPC stole your Computer Case!" << endl;
                    cout << endl;
                    bestbuy.setComputerPartsAt(3, bestbuy.getComputerParts("Computer Case") -1 );
                } 
                else
                {
                    cout << "You had no Computer Case for the hackers to steal!" << endl;
                    cout << endl;
                }
            }
            // If the user will lose a Internet Card
            else if(whichPartToLose == 4)
            {
                // If there is a Internet Card to steal
                if ((bestbuy.getComputerParts("Internet Card") -1) > 0)
                {
                    cout << "The NPC stole your Internet Card!" << endl;
                    cout << endl;
                    bestbuy.setComputerPartsAt(4, bestbuy.getComputerParts("Internet Card") -1 );
                } 
                else
                {
                    cout << "You had no Internet Card for the hackers to steal!" << endl;
                    cout << endl;
                }
            }
            // If the user will lose a Keyboard and Mouse
            else
            {
                // If there is a Keyboard and Mouse to steal
                if ((bestbuy.getComputerParts("Keyboard and Mouse") -1) > 0)
                {
                    cout << "The NPC stole your Keyboard and Mouse!" << endl;
                    cout << endl;
                    bestbuy.setComputerPartsAt(5, bestbuy.getComputerParts("Keyboard and Mouse") -1 );
                } 
                else
                {
                    cout << "You had no Keyboard and Mouse for the hackers to steal!" << endl;
                    cout << endl;
                }
            }
        }    
    }
    // If the NPC is nuetral
    else
    {
        cout << "The NPC was nuetral and will give you no award for your travels!" << endl;
        cout << endl;
    }
}



/*
    The function has the user fight a hacker
    Name:       fighAHacker()
    Parameters:
                hacker (Hacker) - the hacker object in the current server room
                playername (Player) - the player currently playing the game
                bestbuy (BestBuy) - the BestBuy object currently being used in the game
                computer (Computer) - the Computer object currently being used in the game
                map (Map) - the current server room's map
    Return Value:       
                none      
*/
void Game::fightAHacker(Hacker &hacker, Player &playername, BestBuy &bestbuy, Computer &computer, Map &map)
{
    // Variables
    // hackerChoice (int) - stores whether or not the user will fight the hacker
    int hackerChoice = 0;
    // beatHacker (int) - will store the value of if the player will beat the hacker or not
    int beatHacker = 0;
    // whichPartToLose (int) - decides of the user which computer part the player will lose
    int whichPartToLose = 0;

    // Find out which hacker they will fight
    int whichHacker = 0;

    // Make sure that whichHacker will be a valid number
    if(whichHacker > map.getHackerCount())
    {
        whichHacker = 0;
    }

    // Present the user with the choice to forfeit or attack the hacker
    // Have the hacker be at the index of the current hacker
    cout << "You just ran into " << hacker.getHackerName(whichHacker) << endl;
    cout << "Think you can beat this hacker’s skills?" << endl;
    cout << "1. Attack" << endl;
    cout << "2. Forfeit" << endl;
    cin >> hackerChoice;

    // Increase whichHacker by 1
    whichHacker++;

    switch(hackerChoice)
    {
        // Attack
        case 1:
        {
            // Calculate if the player will win or not
            beatHacker = ( (rand() % 6 + 1)*(bestbuy.getInternet()) ) - ( ( (rand() % 6 + 1)*(hacker.getRoom()) ) * (1/bestbuy.getVPN()) );

            // If the value is positve, the player wins
            if(beatHacker > 0)
            {
                cout << "You beat Carmen's hackers! Good job! " << endl;
                cout << "You get 50 dogecoin!" << endl;
                cout << endl;

                // The player gains 50 dogecoins
                bestbuy.setDogecoin(bestbuy.getDogecoin() + 50);

                // Increase the number of hackers the user has defeated
                playername.setNumHacekersDefeated(playername.numHackersDefeated() + 1);
            }
            // If the value is negative, the hacker wins
            else
            {
                cout << "You lost to Carmen's hackers! Now face the consequences!" << endl;
                cout << "Your computer maintaince has decreased!" << endl;
                cout << "Your virus risk has increased!" << endl;
                cout << endl;

                // The player loses 20 of their computer maintance level
                computer.setMaintenanceLevel(computer.getMaintenanceLevel() - 20);

                // Chance of getting a virus increases by 10
                computer.setVirusRisk(computer.getVirusRisk() + 10);

                // Carmen's progress increases by 25
                hacker.setCarmenProgress(hacker.getCarmenProgress() + 25);
            }

            // After every hacker battle, there is a 30% chance that the computer's maintance level will drop by 10
            // Event will only occur if is not the last battle in the last room
            if( (hacker.getRoom() != 5) && (playername.numHackersDefeated() != map.getHackerCount()) )
            {
                // If a random number between 1-10 is less than or equal to 3
                if( (rand()%3 + 1) <= 3 )
                {
                    // Drop the computer's maintanence level by 10
                    computer.setMaintenanceLevel(computer.getMaintenanceLevel() - 10);
                }

                // The player will also lose a random computer part
                whichPartToLose = rand() % 5;
                // If the user has computer parts to lose
                if(bestbuy.totalComputerParts() > 0)
                {
                    // If a CPU will be lost
                    if(whichPartToLose == 0)
                        {
                            // If there is a CPU to steal
                            if ((bestbuy.getComputerParts("CPU") -1) > 0)
                            {
                                cout << "The hacker stole your CPU!" << endl;
                                cout << endl;
                                bestbuy.setComputerPartsAt(0, bestbuy.getComputerParts("CPU") -1 );
                            } 
                            else
                            {
                                cout << "You had no CPU for the hackers to steal!" << endl;
                                cout << endl;
                            }
                        }
                    // If the user will lose a GPU
                    else if(whichPartToLose == 1)
                    {
                        // If there is a GPU to steal
                        if ((bestbuy.getComputerParts("GPU") -1) > 0)
                        {
                            cout << "The hacker stole your GPU!" << endl;
                            cout << endl;
                            bestbuy.setComputerPartsAt(1, bestbuy.getComputerParts("GPU") -1 );
                        } 
                        else
                        {
                            cout << "You had no GPU for the hackers to steal!" << endl;
                            cout << endl;
                        }
                    }
                    // If the user will lose a Power Supply Unit
                    else if(whichPartToLose == 2)
                    {
                        // If there is a Power Supply Unit to steal
                        if ((bestbuy.getComputerParts("Power Supply Unit") -1) > 0)
                        {
                            cout << "The hacker stole your Power Supply Unit!" << endl;
                            cout << endl;
                            bestbuy.setComputerPartsAt(2, bestbuy.getComputerParts("Power Supply Unit") -1 );
                        } 
                        else
                        {
                            cout << "You had no Power Supply Unit for the hackers to steal!" << endl;
                            cout << endl;
                        }
                    }
                    // If the user will lose a Computer Case
                    else if(whichPartToLose == 3)
                    {
                        // If there is a Computer Case to steal
                        if ((bestbuy.getComputerParts("Computer Case") -1) > 0)
                        {
                            cout << "The hacker stole your Computer Case!" << endl;
                            cout << endl;
                            bestbuy.setComputerPartsAt(3, bestbuy.getComputerParts("Computer Case") -1 );
                        } 
                        else
                        {
                            cout << "You had no Computer Case for the hackers to steal!" << endl;
                            cout << endl;
                        }
                    }
                    // If the user will lose a Internet Card
                    else if(whichPartToLose == 4)
                    {
                        // If there is a Internet Card to steal
                        if ((bestbuy.getComputerParts("Internet Card") -1) > 0)
                        {
                            cout << "The hacker stole your Internet Card!" << endl;
                            cout << endl;
                            bestbuy.setComputerPartsAt(4, bestbuy.getComputerParts("Internet Card") -1 );
                        } 
                        else
                        {
                            cout << "You had no Internet Card for the hackers to steal!" << endl;
                            cout << endl;
                        }
                    }
                    // If the user will lose a Keyboard and Mouse
                    else
                    {
                        // If there is a Keyboard and Mouse to steal
                        if ((bestbuy.getComputerParts("Keyboard and Mouse") -1) > 0)
                        {
                            cout << "The hacker stole your Keyboard and Mouse!" << endl;
                            cout << endl;
                            bestbuy.setComputerPartsAt(5, bestbuy.getComputerParts("Keyboard and Mouse") -1 );
                        } 
                        else
                        {
                            cout << "You had no Keyboard and Mouse for the hackers to steal!" << endl;
                            cout << endl;
                        }
                    }
                }
            }
            break;
        }
        // Forfeit
        case 2:
        {
            cout << "You failed to outsmary Carmen's hacker! Now you lose ALL of your computer parts!" << endl;
            cout << endl;

            // User will lose all of their computer parts
            for(int i = 0; i < 6; i++)
            {
                bestbuy.setComputerPartsAt(i,0);
            }

            break;
        }
        // Invalid input
        default: cout << "Invalid input. " << endl; break;
    }
}



/*
    The function reads a file called hackers.txt and returns a random hacker in that file that is of the wanted server room
    Name:       setHackerInfo()
    Parameters:
                serverRoom (int) - the server room of the current hacker
    Return Value:
                hackerInfo (string) - the name of the hacker in the wanted server room
*/
Hacker Game::setHackerInfo(Hacker serverRoomHackers, int serverRoom, int numHackers)
{
    
    // Step 1: Create a variable for the file to be stored in
    ifstream in_hacker_file;

    // Step 2: Open the file
    in_hacker_file.open("hackers.txt");

    // Step 3: Check if the file can be opened
    if(in_hacker_file.fail())
    {
        return serverRoomHackers;
    }
    
    // Step 4: Declare variables and read the file
    string line;
    string hackerData[2];
    string hackerName[4];
    int hackerRoom[100];
    int index = 0;
    int randomNumbers[3];
    string name;

    // While there is still data in the file to be read
    while(!in_hacker_file.eof())
    {
        // Process the current line of data
        getline(in_hacker_file,line);

        // If the current line is not empty
        if((!isspace(line[0])) && (line.length() > 1 ))
        {
            // Split the current lines data at commas, and store the data in hackerData
            split(line, ',', hackerData, 2);
            
            // Set the current hackerRoom
            hackerRoom[index] = stoi(hackerData[1]);
            // If the wanted server room is equal to the current hacker's server room
            if(hackerRoom[index] == serverRoom)
            {
                // Store the hacker's name in an array called hackerName
                hackerName[index] = hackerData[0];
                index++;
            }
        }
    }

    // Generate 3 (from 0-3) random numbers that represent the index of the hackers in the hackerName array
    for(int i = 0; i < numHackers; i++)
    {
        randomNumbers[i] = rand() % 3;
    }
    // Make sure that each of the three numbers are different
    for(int i = 0; i < numHackers-1; i++)
    {
        // If two of the numbers are the same, keep generating new numbers until they all are different 
        while(randomNumbers[i] == randomNumbers[i+1])
        {
            randomNumbers[i+1] = rand() % 3;
        }
    }
    // Update the Hacker object with all of the hacker's information (names)
    for (int i = 0; i < numHackers; i++)
    {
        serverRoomHackers.setHackerName(i, hackerName[randomNumbers[i]]);
    }
    // Update the Hacker object with all of the hacker's serverRoom
    serverRoomHackers.setRoom(serverRoom);

    // Return the updated Hacker object
    return serverRoomHackers;
}



/*
    The function returns true when the player can move on to the next server room
    Name:       canProgress()
    Parameters:
                map (Map) - the current server room's map
                playerName (Player) - the current player's object
    Return Value:
                true/false (bool) - returns true if the player can progress to the next server room
*/
bool Game::canProgress(Map &map, Player &playerName)
{
    if(playerName.numHackersDefeated() == map.getHackerCount())
    {
        return true;
    }
    return false;
}


/*
    The function figures out if the player's computer will get a virus
    Name:       getVirus()
    Parameters:
                hacker (Hacker)
    Return Value:
                true/false (bool) - if the computer will get a virus or not
*/
bool Game::getVirus(Computer computer)
{
    // getVirus (int) - generates a random number that will determine if the user's computer will get a virus or not
    int getVirus = 0;

    // Generate a random number from 1 - 100
    getVirus = rand() % 100 + 1;

    // If the number is less than or equal to the computer's current virusRisk, then the computer will get a virus
    if(getVirus <= computer.getVirusRisk())
    {
        cout << "OH NO! Your computer got infected with a virus!" << endl;
        cout << "You can remove the virus in your next turn using antivirus software!" << endl;
        cout << endl;

        // Reset their risk of getting a virus back to 0 and increase the computer's number of viruses by 1
        computer.setVirusRisk(0);
        computer.setNumViruses(computer.getnumViruses() + 1);
        return true;
    }
    // If the computer does not get a virus, false will be returned
    else
    {
        return false;
    }

    // Default return false
    return false;

}



/*
    The function determines whether the game is over
    Name:           gameOver()
    Parameters:     
                    playerName (Player) - the current player
                    hacker (Hacker) - the hackers in the current serverRoom

    Return Value:
                    true/false (bool) - determines whether or not the player lost the game
*/
bool Game::gameOver(Player playerName, Hacker hacker, Computer computer)
{
    // If the player's frustration reaches 100 by the end of their turn, the game ends
    if(playerName.getFrustration() >= 100)
    {
        cout << "GAME OVER!" << endl; 
        cout << "YOU RAGE QUIT!!" << endl;
        return true;
    }
    // If Carmens's progress reaches 100, the game ends 
    else if(hacker.getCarmenProgress() == 100)
    {
        cout << "GAME OVER!" << endl;
        cout << "CARMEN STOLE ALL OF YOUR INFORMATION!" << endl;
        return true;
    }
    else if(computer.getMaintenanceLevel() == 0)
    {
        cout << "GAME OVER" << endl;
        cout << "COMPUTER MAINTANCE LEVEL REACHED 0" << endl;
        return true;
    }
    else
    {
        return false;
    }

    return false;
}



/*
    The function allows the user to player rock paper scissors
    Name:       rockPaperScissors()
    Parameters:
                none
    Return Value:
                bool (true/false) - determines whether the user won the game or not
*/
bool Game::rockPaperScissors()
{
    // Variables
    // playerMove (int) - the player's move
    int playerMove = 0;
    // computerMove (int) - the computer's move
    int computerMove  = 0;

    // Generate the move that the computer will use using:
    // 1. Rock   2. Paper   3. Scissors
    computerMove =  rand() % 3 + 1;

    // Ask the user to input a move
    cout << "Welcome to Rock, Paper, Scissors!" << endl;
    cout << "Please insert a numerical value for what you would like to do" << endl;
    cout << "1. Rock" << endl;
    cout << "2. Paper" << endl;
    cout << "3. Scissors" << endl;
    cin >> playerMove;

    // Check that the user input a proper value
    if ((playerMove <= 0 ) || (playerMove > 3))
    {
        // Print that the user input an invalid value and return false
        cout << "You input an invalid value! Please be more careful next time!" << endl;

        return false;
    }

    // If the computer and player both pick the same thing
    if(computerMove == playerMove)
    {
        // Print that it was a tie and return false
        cout << "TIE" << endl;
        cout << "Both the you and computer selected the same thing!" << endl;
        cout << endl;

        return false;
    }
    // If the computer beats the player
    else if(computerMove > playerMove)
    {
        // Print that the computer won and return false
        cout << "LOSE" << endl;
        cout << "The computer beat you!" << endl;
        cout << endl;

        return false;
    }
    // If the player wins
    else
    {
        // Print that the user won and return true
        cout << "WIN" << endl;
        cout << "You beat the computer!" << endl;
        cout << endl;

        return true;
    }
}



/*
    The function will determine if a misfortune event will occur while the player moves around the map
    Name:       misfortune()
    Parameters:
                computer (Computer) - the player's computer
                bestBuy (BestBuy) - the BestBuy currently being used in the game
                player (Player) - the current player playing the game
*/
bool Game::misfortune(Computer computer, BestBuy bestBuy, Player player)
{
    // randomNumber (int) - the random number that will determine if a misfortune event will occur
    int randomNumber = 0;
    // randomMisfortune (int) - will determine which misfortune event will occur
    int randomMisfortune = 0;
    // whichPartToLose (int) - decides of the user which computer part the player will lose
    int whichPartToLose = 0;

    // Assign randomNumber a random value between 1-10
    randomNumber = rand() % 10 + 1;
    
    // If randomNumber is 1,2, or 3 (30%)
    if (randomNumber <= 3)
    {
        // Assign randomMisfortune a value from 1-3
        randomMisfortune = rand() % 3 + 1;

        // If randomMisfortune is 1
        if (randomMisfortune == 1)
        {
            // Print out the message annoncing the misfortune
            cout << "OH NO! Your team was robbed by Carmen’s dastardly hackers!" << endl;

            // decides of the user will lose a VPN or computer part
            whichPartToLose = rand() % 5;

            // If the user has no computer parts to steal , then the user will lose their VPNs
            if (bestBuy.totalComputerParts() == 0)
            {
                // If the player has VPNs to lose
                if (bestBuy.getVPN() > 0)
                {
                    bestBuy.setVPN(bestBuy.getVPN() -1 );
                    cout << "You have " << bestBuy.getVPN() << " VPNs left!" << endl;
                }
                else
                {
                    cout << "The hackers had nothing to steal! You really should visit a BestBuy..." << endl;
                }
            }
            // If the user has computer parts to lose
            else
            {
                // If the user will lose a CPU
                if(whichPartToLose == 0)
                {
                    // If there is a CPU to steal
                    if ((bestBuy.getComputerParts("CPU") -1) > 0)
                    {
                        cout << "The hacker stole your CPU!" << endl;
                        cout << endl;
                        bestBuy.setComputerPartsAt(0, bestBuy.getComputerParts("CPU") -1 );
                    } 
                    else
                    {
                        cout << "You had no CPU for the hackers to steal!" << endl;
                        cout << endl;
                    }
                }
                // If the user will lose a GPU
                else if(whichPartToLose == 1)
                {
                    // If there is a GPU to steal
                    if ((bestBuy.getComputerParts("GPU") -1) > 0)
                    {
                        cout << "The hacker stole your GPU!" << endl;
                        cout << endl;
                        bestBuy.setComputerPartsAt(1, bestBuy.getComputerParts("GPU") -1 );
                    } 
                    else
                    {
                        cout << "You had no GPU for the hackers to steal!" << endl;
                        cout << endl;
                    }
                }
                // If the user will lose a Power Supply Unit
                else if(whichPartToLose == 2)
                {
                    // If there is a Power Supply Unit to steal
                    if ((bestBuy.getComputerParts("Power Supply Unit") -1) > 0)
                    {
                        cout << "The hacker stole your Power Supply Unit!" << endl;
                        cout << endl;
                        bestBuy.setComputerPartsAt(2, bestBuy.getComputerParts("Power Supply Unit") -1 );
                    } 
                    else
                    {
                        cout << "You had no Power Supply Unit for the hackers to steal!" << endl;
                        cout << endl;
                    }
                }
                // If the user will lose a Computer Case
                else if(whichPartToLose == 3)
                {
                    // If there is a Computer Case to steal
                    if ((bestBuy.getComputerParts("Computer Case") -1) > 0)
                    {
                        cout << "The hacker stole your Computer Case!" << endl;
                        cout << endl;
                        bestBuy.setComputerPartsAt(3, bestBuy.getComputerParts("Computer Case") -1 );
                    } 
                    else
                    {
                        cout << "You had no Computer Case for the hackers to steal!" << endl;
                        cout << endl;
                    }
                }
                // If the user will lose a Internet Card
                else if(whichPartToLose == 4)
                {
                    // If there is a Internet Card to steal
                    if ((bestBuy.getComputerParts("Internet Card") -1) > 0)
                    {
                        cout << "The hacker stole your Internet Card!" << endl;
                        cout << endl;
                        bestBuy.setComputerPartsAt(4, bestBuy.getComputerParts("Internet Card") -1 );
                    } 
                    else
                    {
                        cout << "You had no Internet Card for the hackers to steal!" << endl;
                        cout << endl;
                    }
                }
                // If the user will lose a Keyboard and Mouse
                else
                {
                    // If there is a Keyboard and Mouse to steal
                    if ((bestBuy.getComputerParts("Keyboard and Mouse") -1) > 0)
                    {
                        cout << "The hacker stole your Keyboard and Mouse!" << endl;
                        cout << endl;
                        bestBuy.setComputerPartsAt(5, bestBuy.getComputerParts("Keyboard and Mouse") -1 );
                    } 
                    else
                    {
                        cout << "You had no Keyboard and Mouse for the hackers to steal!" << endl;
                        cout << endl;
                    }
                }
                // Print out how many computer parts the player has left after the misfortune
                cout << "You have " << bestBuy.totalComputerParts() << " computer parts left!" << endl;
                cout << endl;
            }
            
            return true;
        }
        // If randomMisfortune = 2
        else if (randomMisfortune == 2)
        {
            cout << "OH NO! Your computer was damaged!" << endl;
            // Set computer maintance level to 10
            computer.setMaintenanceLevel(computer.getMaintenanceLevel() - 10);
            cout << "You now have a computer maintance level of " << computer.getMaintenanceLevel() << endl;
            cout << endl;
            return true;
        }
        // If randomMisfortune = 3
        else
        {  
            cout << "OH NO! Why won’t my code work!!!!" << endl;
            cout << "Your frustration level was increased." << endl;
            player.setFrustration(player.getFrustration() + 10);
            cout << "You now have a frustration level of " << player.getFrustration() << endl;
            cout << endl;
            return true;
        }
    }

    return false;
}



/*
    The function displays an update of the user's current status
    Name:       statusUpdate()
    Parameters:
                player (playerName) - the current player
                computer (Computer) - the current player's computer
                bestBuy (BestBuy) - all of the parts that the player owns
                hackers (Hacker) - the hacker's in the current serverRoom
    Return Value:
                none
*/
void Game::statusUpdate(Player &playerName, Computer &computer, BestBuy &bestbuy, Hacker &hackers)
{
    cout << endl;
    cout << "STATUS UPDATE" << endl;
    // Print out the computers current maintance level
    cout << "COMPUTER INFORMATION" << endl;
    cout << "Computer Maintance Level: " << computer.getMaintenanceLevel() << endl;
    // Print out the number of viruses the computer has
    cout << "Number of viruses: " << computer.getnumViruses() << endl;
    // Computer Parts 
    cout << "PART INFORMATION" << endl;
    cout << "You have: " << endl;
    cout << bestbuy.getComputerParts("CPU") << " CPUs " << endl;
    cout << bestbuy.getComputerParts("GPU") << " GPUs " << endl;
    cout << bestbuy.getComputerParts("Power Supply Unit") << " power supply units " << endl;
    cout << bestbuy.getComputerParts("Computer Case") << " computer cases " << endl;
    cout << bestbuy.getComputerParts("Internet Card") << " internet cards " << endl;
    cout << bestbuy.getComputerParts("Keyboard and Mouse") << " keyboards and mouses " << endl;
    cout << bestbuy.getComputerParts("Premade Computer") << " premade computers " << endl;
    cout << bestbuy.getAntiVirusSoftware() << " Antivirus Software " << endl;
    cout << bestbuy.getVPN() << " VPNs " << endl;
    cout << "Internet Provider Level: " << bestbuy.getInternet() << endl;
    // Player Information
    cout << "PLAYER INFORMATION" << endl;
    cout << bestbuy.getDogecoin() << " dogecoins" << endl;
    cout << playerName.getFrustration() << " frustration" << endl;
    // Hacker Information
    cout << "HACKER INFORMATION " << endl;
    cout << playerName.numHackersDefeated() << " hackers defeated in the current server room" << endl;
    cout << "Carmen's progress is " << hackers.getCarmenProgress() << endl;
    cout << endl;
}



/*
    The function reads a file called puzzles.txt and returns a random puzzle as an vector
    Name:       puzzle()
    Parameters:
                bestbuy (BestBuy) - the current bestbuy object being used in the game
    Return Value:
                true/false (bool) - whether the user answered correctly or not
*/
bool Game::puzzle(BestBuy bestbuy)
{
    // Step 1: Create a variable for the file to be stored in
    ifstream in_puzzles_file;

    // Step 2: Open the file
    in_puzzles_file.open("puzzles.txt");

    // Step 3: Check if the file can be opened
    if(in_puzzles_file.fail())
    {
        return false;
    }

    // Step 4: Declare variables
    // line (string) - the current line being processed
    string line;
    // index (int) - will store the index of the current puzzle (column)
    int index = 0;
    // randomPuzzle (int) - will store the index of the random puzzle
    int randomPuzzle = 0;
    // randomPuzzleSize (int) - stores the size of the current random puzzle
    int randomPuzzleSize = 0;
    // column (int) - the size of the current column of the 2D array
    int column = 0;
    // puzzlesArray (string) - a 2D array that will store all of the puzzles
    string puzzlesArray[5][50];
    // puzzleAnswerInt (int) - the puzzle answer for the first and second puzzle
    int puzzleAnswerInt = 0;
    // puzzleAnswerChar (int) - the puzzle answer for the rest of the puzzles
    char puzzleAnswerChar;

    // Give randomPuzzle a random integer from 0-4
    randomPuzzle = rand() % 4;

    // If randomPuzzle = 0, the size = 32
    if(randomPuzzle == 0)
    {
        randomPuzzleSize = 32;
    }
    // If randomPuzzle = 1, then size = 45
    else if (randomPuzzle == 1)
    {
        randomPuzzleSize = 24;
    }
    // If randomPuzzle = 2, then size = 20
    else if(randomPuzzle == 2)
    {
        randomPuzzleSize = 20;
    }
    // If randomPuzzle = 3, then size = 13
    else if(randomPuzzle == 3)
    {
        randomPuzzleSize = 13;
    }
    // If randomPuzzle = 4, then size = 7
    else
    {
        randomPuzzleSize = 7;
    }

    // While there is data in the file that can be read
    while(!in_puzzles_file.eof())
    {
        // Process the curernt line of data
        getline(in_puzzles_file, line);

        // If the current line is not empty
        if( (!isspace(line[0])) && (line.length() > 1) )
        {
            // Store the current line in the 2D vector if the current line is not "---"
            if(line != "---")
            {
                // Store the puzzle at the index row of the vector
                puzzlesArray[index][column] = line;
                column++;
            }
            else
            {
                // Increment index by 1 so the next puzzle will be stored at a different index
                index++;
                column = 0;
            }
        }
    }

    // Print the random puzzle
    for(int i = 0; i < randomPuzzleSize; i++)
    {
        cout << puzzlesArray[randomPuzzle][i] << endl;
    }

    // Depending on the puzzle, ask the user for the answer
    // If randomPuzzle = 0, then the answer is 21
    if(randomPuzzle == 0)
    {
        // Reask the question
        cout << "As said above, enter the number of the line on which the error appears to win this puzzle." << endl;
        cin >> puzzleAnswerInt;

        // If they answer correctly and the NPC is their friend
        if((puzzleAnswerInt == 21))
        {
            cout << "Congrats you answered correctly!" << endl;
            cout << endl;

            return true;
        }
        // If they answer incorrectly
        else
        {
            cout << "You answered incorrectly! Better luck next time!" << endl;
            cout << endl;

            return false;
        }
    }
    // If randomPuzzle = 1, then the answer is 13
    else if(randomPuzzle == 1)
    {
        // Reask the question
        cout << "As said above, Enter the number of the line on which the error appears to win this puzzle." << endl;
        cin >> puzzleAnswerInt;
        
        // If they answer correctly
        if(puzzleAnswerInt == 13)
        {
            cout << "Congrats you answered correctly!" << endl;
            cout << endl;

            return true;
        }
        // If they answer incorrectly
        else
        {
            cout << "You answered incorrectly! Better luck next time!" << endl;
            cout << endl;

            return false;
        }
    }
    // If randomPuzzle = 2, then the answer is B
    else if(randomPuzzle == 2)
    {
        // Reask the question
        cout << "As said above, How many times will the sentence inside of the for loop be printed? (enter a character)" << endl;
        cin >> puzzleAnswerChar;
        
        // If they answer correctly
        if(puzzleAnswerChar == 'B')
        {
            cout << "Congrats you answered correctly!" << endl;
            cout << endl;

            return true;
        }
        // If they answer incorrectly
        else
        {
            cout << "You answered incorrectly! Better luck next time!" << endl;
            cout << endl;

            return false;
        }
    }
    // If randomPuzzle = 3, then the answer is A
    else if(randomPuzzle == 3)
    {
        // Reask the question
        cout << "As said above, In the function below, word double before multiply represents what about the function? (enter a character)" << endl;
        cin >> puzzleAnswerChar;
        
        // If they answer correctly
        if(puzzleAnswerChar == 'A')
        {
            cout << "Congrats you answered correctly!" << endl;
            cout << endl;

            return true;
        }
        // If they answer incorrectly
        else
        {
            cout << "You answered incorrectly! Better luck next time!" << endl;
            cout << endl;

            return false;
        }
    }
    // If randomPuzzle = 4, then the answer is D
    else
    {
       // Reask the question
        cout << "As said above, In the function below,  Which of the following streams should you use to both read and write from this file? (enter a character)" << endl;
        cin >> puzzleAnswerChar;
        
        // If they answer correctly
        if(puzzleAnswerChar == 'D')
        {

            cout << "Congrats you answered correctly!" << endl;
            cout << endl;

            return true;
        }
        // If they answer incorrectly
        else
        {
            cout << "You answered incorrectly! Better luck next time!" << endl;
            cout << endl;

            return false;
        }
    }
    
    return false;
}



/*  
    The function presents the user with the option to buy items from BestBuy
    Name:           bestBuy()
    Parameters:
                    bestbuy (BestBuy) - the bestbuy the user will be spawned in
                    serverRoom (int) - the server room that the user is currently in
    Return Value:
                    bestbuy (BestBuy) - the updated bestbuy
*/
BestBuy Game::bestBuy(BestBuy bestbuy, int serverRoom)
{
    // bestBuySelection (int) - the user's bestBuy selection
    int bestBuySelection = 0;
    // computerPartSelection (int) - the user's computer part selection
    int computerPartSelection = 0;
    // numComputerParts (int) - the total number of computer parts the user purchases
    int numComputerParts = 0;
    // numPartsAvailable (int) - the total number of computer parts available to purchase
    int numPartsAvailable = 0;
    // internetSelection (int) - the internet level selection of the user
    int internetSelection = 0;

    // Update prices to match the increase with the change in serverRoom
    bestbuy.setComputerPriceFor(serverRoom);

    // Present the user with information about bestBuy
    cout << "You have been spawned into BestBuy! " << endl;
    cout << endl;
    cout << "You have 200 dogecoins, 1 computer and 1 VPN. You will need to spend the rest of your money on the following items: " << endl;
    cout << "- COMPUTER PARTS. If your computer breaks, you need 5 computer parts to make a new one." << endl;
    cout << "- ANTIVIRUS SOFTWARE. If your computer is infected with a virus, use the antivirus software to get rid of it." << endl;
    cout << "- VIRTUAL PRIVATE NETWORK (VPN). The more VPNs you havethe harder it is for a hacker to infect your computer with a virus." << endl;
    cout << "- INTERNET PROVIDER. The better the internet provider, the more reliable your hacking will be" << endl;

    cout << "You can spend all of your money here before you start your journey, or you can save some to spend on a different" << endl;
    cout << "electronics site along the way. But beware, some of the websites online are shady, and they won’t always give you a" << endl;
    cout << "fair price..." << endl;
    cout << endl;

    cout << "Parts currently available to buy: " << endl;
    cout << "1. Computer Parts - price varies on purchase" << endl;
    cout << "2. Antivirus Software - " << bestbuy.getComputerPriceFor("Antivirus Software") << " dogecoins " << endl;
    cout << "3. Virtual Private Network (VPN) - " << bestbuy.getComputerPriceFor("VPN")  << " dogecoins" << endl;
    cout << "4. Internet Provider - price varies on purchase" << endl;
    cout << "5. Quit" << endl;
    cin >> bestBuySelection;

    // For loop that will continously loop until 4 is inputted
    for (int i = 0; bestBuySelection != 5; i++)
    {
        switch(bestBuySelection)
        {
            // Computer Parts
            case 1:
            {
                cout << "Best Buy recommends that the player should purchase at least 1 of each computer part" << endl;
                cout << "in case your main computer breaks. You can have a maximum of 3 of each computer" << endl;
                cout << "part and 1 extra premade computer. These are the different parts:" << endl;
                cout << endl;
                
                cout << "Computer Parts avaiable to purchase: " << endl;
                cout << "1. CPU - " << bestbuy.getComputerPriceFor("CPU") << " dogecoins" << endl;
                cout << "2. GPU - " << bestbuy.getComputerPriceFor("GPU") << " dogecoins" << endl;
                cout << "3. Power Supply Unit - " << bestbuy.getComputerPriceFor("Power Supply Unit") << " dogecoins" << endl;
                cout << "4. Computer Case - " << bestbuy.getComputerPriceFor("Computer Case") << " dogecoins" << endl;
                cout << "5. Internet Card - " << bestbuy.getComputerPriceFor("Internet Card") << " dogecoins" << endl;
                cout << "6. Keyboard and Mouse - " << bestbuy.getComputerPriceFor("Keyboard and Mouse") << " dogecoins" << endl;
                cout << "7. Premade Computer - " << bestbuy.getComputerPriceFor("Premade Computer") << " dogecoins" << endl;
                cout << "8. Done purchasing Computer Parts" << endl;
                cin >> computerPartSelection;

                for(int i = 0; computerPartSelection != 8; i++)
                {
                    switch(computerPartSelection)
                    {
                        // CPU
                        case 1:
                        {
                            // If the current number of CPUs the user has is less than 3
                            if (bestbuy.getComputerParts("CPU") < 3)
                            {
                                // Set numPartsAvailable to the number of CPUs the user is able to purchase
                                numPartsAvailable = 3 - bestbuy.getComputerParts("CPU");
                                cout << endl;
                                cout << numPartsAvailable << " CPUs are avaialbe to purchase!" << endl;
                                cout << "How many CPUs do you wish to purchase? " << endl;
                                cin >> numComputerParts;
                                // If the number of computer parts the user wants to purchase is <= the number of parts available
                                if(numComputerParts <= numPartsAvailable && ((bestbuy.getDogecoin() - (bestbuy.getComputerPriceFor("CPU")*numComputerParts)) >= 0))
                                {
                                    // Set the number of CPUs to the current number of CPUs + number of parts purchased
                                    bestbuy.setComputerPartsAt(0, bestbuy.getComputerParts("CPU")+ numComputerParts);
                                    // Update number of dogecoins
                                    bestbuy.setDogecoin(bestbuy.getDogecoin() - (bestbuy.getComputerPriceFor("CPU")*numComputerParts));
                                    cout <<  "You have " << bestbuy.getDogecoin() << " dogecoin left!" << endl;
                                    cout << endl;
                                } 
                                // If the number of CPUs wanted to purchase cannot be purchased
                                else if(numComputerParts > numPartsAvailable)
                                {
                                    cout << "You cannot purchase that amount! Now you have to restart the whole process :(" << endl;
                                    cout << endl;
                                }
                                // If the user doesn't have enough money
                                else
                                {
                                    cout << "You don't have enough dogecoins to complete the purchase, choose a different amount!" << endl;
                                    cout << "You have " << bestbuy.getDogecoin() << " dogecoin left! " << endl;
                                    cout << endl;
                                }

                            }
                            // If the user cannot purchase anymore CPUs
                            else
                            {
                                cout << "You cannot purchase anymore CPUs!" << endl;
                                cout << endl;
                            }
                            cout << endl;

                            break;
                        }
                        // GPU
                        case 2:
                        {
                            // If the number of GPUs the user currently has is less than 3
                            if(bestbuy.getComputerParts("GPU") < 3)
                            {
                                // Set numPartsAvailable to the number of GPUs the user can buy
                                numPartsAvailable = 3 - bestbuy.getComputerParts("GPU");
                                cout << endl;
                                cout << numPartsAvailable << " GPUs are available to purchase!" << endl;
                                cout << "How many GPUs do you wish to purchase?" << endl;
                                cin >> numComputerParts;
                                // If the number of GPUs the user wants to purchase is <= the number of parts available
                                if(numComputerParts <= numPartsAvailable && ((bestbuy.getDogecoin() - (bestbuy.getComputerPriceFor("GPU")*numComputerParts)) >= 0))
                                {
                                    // Set the number of GPUs to the current number of GPUs + the num parts available
                                    bestbuy.setComputerPartsAt(1, bestbuy.getComputerParts("GPU") + numComputerParts);
                                    // Update the number of dogecoins
                                    bestbuy.setDogecoin(bestbuy.getDogecoin() - (bestbuy.getComputerPriceFor("GPU")*numComputerParts));
                                    cout << "You have " << bestbuy.getDogecoin() << " dogecoin left! " << endl;
                                    cout << endl;
                                }
                                // If the number of GPUs wanted to purchase cannot be purchased
                                else if(numComputerParts > numPartsAvailable)
                                {
                                    cout << "You cannot purchase that amount! Now you have to restart the whole process :(" << endl;
                                    cout << endl;
                                }
                                // If the user doesn't have enough money
                                else
                                {
                                    cout << "You don't have enough dogecoins to complete the purchase, choose a different amount!" << endl;
                                    cout << "You have " << bestbuy.getDogecoin() << " dogecoin left! " << endl;
                                    cout << endl;
                                }

                            }
                            // If the user cannot purchase anymore GPUs
                            else
                            {
                                cout << "You cannot purchase anymore GPUs!" << endl;
                                cout << endl;
                            }
                            cout << endl;

                            break;
                        }
                        // Power Supply Unit
                        case 3:
                        {
                            // If the number of Power Supply Units the user currently has is less than 3
                            if(bestbuy.getComputerParts("Power Supply Unit") < 3)
                            {
                                // Set numPartsAvailable to the number of Power Supply Units the user can buy
                                numPartsAvailable = 3 - bestbuy.getComputerParts("Power Supply Unit");
                                cout << endl;
                                cout << numPartsAvailable << " Power Supply Units are available to purchase!" << endl;
                                cout << "How many Power Supply Units do you wish to purchase?" << endl;
                                cin >> numComputerParts;
                                // If the number of Power Supply Units the user wants to purchase is <= the number of parts available
                                if(numComputerParts <= numPartsAvailable && ((bestbuy.getDogecoin() - (bestbuy.getComputerPriceFor("Power Supply Unit")*numComputerParts)) >= 0))
                                {
                                    // Set the number of Power Supply Units to the current number of PSUs + the num parts available
                                    bestbuy.setComputerPartsAt(2, bestbuy.getComputerParts("Power Supply Unit") + numComputerParts);
                                    // Update the number of dogecoins
                                    bestbuy.setDogecoin(bestbuy.getDogecoin() - (bestbuy.getComputerPriceFor("Power Supply Unit")*numComputerParts));
                                    cout << "You have " << bestbuy.getDogecoin() << " dogecoin left! " << endl;
                                    cout << endl;
                                }
                                // If the number of Power Supply Units wanted to purchase cannot be purchased
                                else if(numComputerParts > numPartsAvailable)
                                {
                                    cout << "You cannot purchase that amount! Now you have to restart the whole process :(" << endl;
                                    cout << endl;
                                }
                                // If the user doesn't have enough money
                                else
                                {
                                    cout << "You don't have enough dogecoins to complete the purchase, choose a different amount!" << endl;
                                    cout << "You have " << bestbuy.getDogecoin() << " dogecoin left! " << endl;
                                    cout << endl;
                                }

                            }
                            // If the user cannot purchase anymore Power Supply Units
                            else
                            {
                                cout << "You cannot purchase anymore Power Supply Units!" << endl;
                                cout << endl;
                            }
                            cout << endl;

                            break;
                        }
                        // Computer Case
                        case 4:
                        {
                            // If the number of Computer Cases the user currently has is less than 3
                            if(bestbuy.getComputerParts("Computer Case") < 3)
                            {
                                // Set numPartsAvailable to the number of Computer Cases the user can buy
                                numPartsAvailable = 3 - bestbuy.getComputerParts("Computer Case");
                                cout << endl;
                                cout << numPartsAvailable << " Computer Cases are available to purchase!" << endl;
                                cout << "How many Computer Cases do you wish to purchase?" << endl;
                                cin >> numComputerParts;
                                // If the number of Computer Cases the user wants to purchase is <= the number of parts available
                                if(numComputerParts <= numPartsAvailable && ((bestbuy.getDogecoin() - (bestbuy.getComputerPriceFor("Computer Case")*numComputerParts)) >= 0))
                                {
                                    // Set the number of Computer Cases to the current number of Computer Cases + the num parts available
                                    bestbuy.setComputerPartsAt(3, bestbuy.getComputerParts("Computer Case") + numComputerParts);
                                    // Update the number of dogecoins
                                    bestbuy.setDogecoin(bestbuy.getDogecoin() - (bestbuy.getComputerPriceFor("Computer Case")*numComputerParts));
                                    cout << "You have " << bestbuy.getDogecoin() << " dogecoin left! " << endl;
                                    cout << endl;
                                }
                                // If the number of Computer Cases wanted to purchase cannot be purchased
                                else if(numComputerParts > numPartsAvailable)
                                {
                                    cout << "You cannot purchase that amount! Now you have to restart the whole process :(" << endl;
                                    cout << endl;
                                }
                                // If the user doesn't have enough money
                                else
                                {
                                    cout << "You don't have enough dogecoins to complete the purchase, choose a different amount!" << endl;
                                    cout << "You have " << bestbuy.getDogecoin() << " dogecoin left! " << endl;
                                    cout << endl;
                                }

                            }
                            // If the user cannot purchase anymore Computer Cases
                            else
                            {
                                cout << "You cannot purchase anymore Computer Cases!" << endl;
                                cout << endl;
                            }
                            cout << endl;

                            break;
                        }
                        // Internet Card
                        case 5:
                        {
                            // If the number of Internet Cards the user currently has is less than 3
                            if(bestbuy.getComputerParts("Internet Card") < 3)
                            {
                                // Set numPartsAvailable to the number of Internet Cards the user can buy
                                numPartsAvailable = 3 - bestbuy.getComputerParts("Internet Card");
                                cout << endl;
                                cout << numPartsAvailable << " Internet Cards are available to purchase!" << endl;
                                cout << "How many Internet Cards do you wish to purchase?" << endl;
                                cin >> numComputerParts;
                                // If the number of Internet Cards the user wants to purchase is <= the number of parts available
                                if(numComputerParts <= numPartsAvailable && ((bestbuy.getDogecoin() - (bestbuy.getComputerPriceFor("Internet Card")*numComputerParts)) >= 0))
                                {
                                    // Set the number of Internet Cards to the current number of Internet Cards + the num parts available
                                    bestbuy.setComputerPartsAt(4, bestbuy.getComputerParts("Internet Card") + numComputerParts);
                                    // Update the number of dogecoins
                                    bestbuy.setDogecoin(bestbuy.getDogecoin() - (bestbuy.getComputerPriceFor("Internet Card")*numComputerParts));
                                    cout << "You have " << bestbuy.getDogecoin() << " dogecoin left! " << endl;
                                    cout << endl;
                                }
                                // If the number of Internet Cards wanted to purchase cannot be purchased
                                else if(numComputerParts > numPartsAvailable)
                                {
                                    cout << "You cannot purchase that amount! Now you have to restart the whole process :(" << endl;
                                    cout << endl;
                                }
                                // If the user doesn't have enough money
                                else
                                {
                                    cout << "You don't have enough dogecoins to complete the purchase, choose a different amount!!" << endl;
                                    cout << "You have " << bestbuy.getDogecoin() << " dogecoin left! " << endl;
                                    cout << endl;
                                }

                            }
                            // If the user cannot purchase anymore Internet Cards
                            else
                            {
                                cout << "You cannot purchase anymore Internet Cards!" << endl;
                                cout << endl;
                            }
                            cout << endl;

                            break;
                        }
                        // Keyboard and Mouse
                        case 6:
                        {
                            // If the number of Keyboard and Mouses the user currently has is less than 3
                            if(bestbuy.getComputerParts("Keyboard and Mouse") < 3)
                            {
                                // Set numPartsAvailable to the number of Keyboard and Mouses the user can buy
                                numPartsAvailable = 3 - bestbuy.getComputerParts("Keyboard and Mouse");
                                cout << endl;
                                cout << numPartsAvailable << " Keyboard and Mouses are available to purchase!" << endl;
                                cout << "How many Keyboard and Mouses do you wish to purchase?" << endl;
                                cin >> numComputerParts;
                                // If the number of Keyboard and Mouses the user wants to purchase is <= the number of parts available
                                if(numComputerParts <= numPartsAvailable && ((bestbuy.getDogecoin() - (bestbuy.getComputerPriceFor("Keyboard and Mouse")*numComputerParts)) >= 0))
                                {
                                    // Set the number of Keyboard and Mouses to the current number of K and Bs + the num parts available
                                    bestbuy.setComputerPartsAt(5, bestbuy.getComputerParts("Keyboard and Mouse") + numComputerParts);
                                    // Update the number of dogecoins
                                    bestbuy.setDogecoin(bestbuy.getDogecoin() - (bestbuy.getComputerPriceFor("Keyboard and Mouse")*numComputerParts));
                                    cout << "You have " << bestbuy.getDogecoin() << " dogecoin left! " << endl;
                                    cout << endl;
                                }
                                // If the number of Keyboard and Mouses wanted to purchase cannot be purchased
                                else if(numComputerParts > numPartsAvailable)
                                {
                                    cout << "You cannot purchase that amount! Now you have to restart the whole process :(" << endl;
                                    cout << endl;
                                }
                                // If the user doesn't have enough money
                                else
                                {
                                    cout << "You don't have enough dogecoins to complete the purchase, choose a different amount!!" << endl;
                                    cout << "You have " << bestbuy.getDogecoin() << " dogecoin left! " << endl;
                                    cout << endl;
                                }

                            }
                            // If the user cannot purchase anymore Keyboard and Mouses
                            else
                            {
                                cout << "You cannot purchase anymore Keyboard and Mouses!" << endl;
                                cout << endl;
                            }
                            cout << endl;

                            break;
                        }
                        // Premade Computer
                        case 7:
                        {
                            // If the number of Premade Computers the user currently has is less than 1
                            if(bestbuy.getComputerParts("Premade Computer") < 1)
                            {
                                // Set numPartsAvailable to the number of Premade Computers the user can buy
                                numPartsAvailable = 1 - bestbuy.getComputerParts("Premade Computer");
                                cout << endl;
                                cout << numPartsAvailable << " Premade Computers are available to purchase!" << endl;
                                cout << "How many Premade Computers do you wish to purchase?" << endl;
                                cin >> numComputerParts;
                                // If the number of Premade Computers the user wants to purchase is <= the number of parts available
                                if(numComputerParts <= numPartsAvailable && ((bestbuy.getDogecoin() - (bestbuy.getComputerPriceFor("Premade Computer")*numComputerParts)) >= 0))
                                {
                                    // Set the number of Premade Computers to the current number of Premades + the num parts available
                                    bestbuy.setComputerPartsAt(6, bestbuy.getComputerParts("Premade Computer") + numComputerParts);
                                    // Update the number of dogecoins
                                    bestbuy.setDogecoin(bestbuy.getDogecoin() - (bestbuy.getComputerPriceFor("Premade Computer")*numComputerParts));
                                    cout << "You have " << bestbuy.getDogecoin() << " dogecoin left! " << endl;
                                    cout << endl;
                                }
                                // If the number of Premade Computers wanted to purchase cannot be purchased
                                else if(numComputerParts > numPartsAvailable)
                                {
                                    cout << "You cannot purchase that amount! Now you have to restart the whole process :(" << endl;
                                    cout << endl;
                                }
                                // If the user doesn't have enough money
                                else
                                {
                                    cout << "You don't have enough dogecoins to complete the purchase, choose a different amount!!" << endl;
                                    cout << "You have " << bestbuy.getDogecoin() << " dogecoin left! " << endl;
                                    cout << endl;
                                }

                            }
                            // If the user cannot purchase anymore Premade Computers
                            else
                            {
                                cout << "You cannot purchase anymore Premade Computers!" << endl;
                                cout << endl;
                            }
                            cout << endl;


                            break;
                        }
                        default: cout << "Invalid input. " << endl; break;
                    }

                    // Print the menu
                    cout << "Computer Parts avaiable to purchase: " << endl;
                    cout << "1. CPU - " << bestbuy.getComputerPriceFor("CPU") << " dogecoins" << endl;
                    cout << "2. GPU - " << bestbuy.getComputerPriceFor("GPU") << " dogecoins" << endl;
                    cout << "3. Power Supply Unit - " << bestbuy.getComputerPriceFor("Power Supply Unit") << " dogecoins" << endl;
                    cout << "4. Computer Case - " << bestbuy.getComputerPriceFor("Computer Case") << " dogecoins" << endl;
                    cout << "5. Internet Card - " << bestbuy.getComputerPriceFor("Internet Card") << " dogecoins" << endl;
                    cout << "6. Keyboard and Mouse - " << bestbuy.getComputerPriceFor("Keyboard and Mouse") << " dogecoins" << endl;
                    cout << "7. Premade Computer - " << bestbuy.getComputerPriceFor("Premade Computer") << " dogecoins" << endl;
                    cout << "8. Done purchasing Computer Parts" << endl;
                    cin >> computerPartSelection;
                }
                // When the user is done purchasing computer parts
                cout << "Finalizing computer parts purchase" << endl;
                cout << "You have: " << endl;
                cout << bestbuy.getComputerParts("CPU") << " CPUs " << endl;
                cout << bestbuy.getComputerParts("GPU") << " GPUs " << endl;
                cout << bestbuy.getComputerParts("Power Supply Unit") << " power supply units " << endl;
                cout << bestbuy.getComputerParts("Computer Case") << " computer cases " << endl;
                cout << bestbuy.getComputerParts("Internet Card") << " internet cards " << endl;
                cout << bestbuy.getComputerParts("Keyboard and Mouse") << " keyboards and mouses " << endl;
                cout << bestbuy.getComputerParts("Premade Computer") << " premade computers " << endl;
                cout << "You have " << bestbuy.getDogecoin() << " dogecoin left. " << endl;
                cout << endl;

                break;
            }
            // Antivirus Software
            case 2:
            {
                cout << "You currently have " << bestbuy.getAntiVirusSoftware() << " Antivirus Software. " << endl;
                cout << "How much Antivirus Software do you wish to purchase? " << endl;
                cin >> numComputerParts;

                // If the user has enough money to purchase the desired amount of software
                if( (bestbuy.getDogecoin() - (bestbuy.getComputerPriceFor("Antivirus Software")*numComputerParts)) >= 0 )
                {
                    // Update the number of Antivirus Software
                    bestbuy.setAntiVirusSoftware(bestbuy.getAntiVirusSoftware() + numComputerParts);
                    // Update the number of dogecoins
                    bestbuy.setDogecoin(bestbuy.getDogecoin() - (bestbuy.getComputerPriceFor("Antivirus Software")*numComputerParts));
                    cout << "You have " << bestbuy.getDogecoin() << " dogecoin left! " << endl;
                    cout << endl;
                }
                else
                {
                    cout << "You don't have enough dogecoins to complete the purchase, choose a different amount!!" << endl;
                    cout << "You have " << bestbuy.getDogecoin() << " dogecoin left! " << endl;
                    cout << endl;
                }
                cout << endl;

                break;
            }
            // VPN
            case 3:
            {
                cout << "You can purchase an unlimited amount of VPNs, but the security increase maxes out at 2. " << endl;
                cout << "You currently have " << bestbuy.getVPN() << " VPNs. " << endl;
                cout << "How mant VPNs do you wish to purchase? " << endl;
                cin >> numComputerParts;

                // If the user has enough money to purchase the desired amount of VPNs
                if( (bestbuy.getDogecoin() - (bestbuy.getComputerPriceFor("VPN")*numComputerParts)) >= 0 )
                {
                    // Update the number of VPNs
                    bestbuy.setVPN(bestbuy.getVPN() + numComputerParts);
                    // Update the number of dogecoins
                    bestbuy.setDogecoin(bestbuy.getDogecoin() - (bestbuy.getComputerPriceFor("VPN")*numComputerParts));
                    cout << "You have " << bestbuy.getDogecoin() << " dogecoin left! " << endl;
                    cout << endl;
                }
                else
                {
                    cout << "You don't have enough dogecoins to complete the purchase, choose a different amount!!" << endl;
                    cout << "You have " << bestbuy.getDogecoin() << " dogecoin left! " << endl;
                    cout << endl;
                }
                cout << endl;


                break;
            }
            // Internet Provider
            case 4:
            {
                cout << "You current have an Internet Provider Level of " << bestbuy.getInternet() << endl;
                cout << "You can level up your internet provider level to the following: " << endl;
                cout << "Level 2. " << bestbuy.getComputerPriceFor("Internet Level 2") << " dogecoins" << endl;
                cout << "Level 3. " << bestbuy.getComputerPriceFor("Internet Level 3") << " dogecoins" << endl;
                cout << "Level 4. " << bestbuy.getComputerPriceFor("Internet Level 4") << " dogecoins" << endl;
                cout << "Level 5. " << bestbuy.getComputerPriceFor("Internet Level 5") << " dogecoins" << endl;
                cout << "What level would you like to ugrade by? (input just the number)" << endl;
                cin >> internetSelection;

                switch(internetSelection)
                {
                    case 2:
                    {
                        if(((bestbuy.getDogecoin() - bestbuy.getComputerPriceFor("Internet Level 2")) >= 0) && (bestbuy.getInternet() < internetSelection))
                        {
                            bestbuy.setInternet(2);
                            bestbuy.setDogecoin(bestbuy.getDogecoin() - bestbuy.getComputerPriceFor("Internet Level 2"));
                            cout << "You have " << bestbuy.getDogecoin() << " dogecoin left! " << endl;
                            cout << endl;
                        }
                        else if(bestbuy.getInternet() >= internetSelection)
                        {
                            cout << "You have already surpassed that internet level!" << endl;
                            cout << endl;
                        }
                        // If the user doesn't have enough dogecoin
                        else
                        {
                            cout << "You don't have enough dogecoins to complete the purchase, choose a different level!!" << endl;
                            cout << "You have " << bestbuy.getDogecoin() << " dogecoin left! " << endl;
                            cout << endl;
                        }
                        break;
                    }
                    case 3:
                    {
                        if((bestbuy.getDogecoin() - bestbuy.getComputerPriceFor("Internet Level 3")) >= 0 && (bestbuy.getInternet() < internetSelection))
                        {
                            bestbuy.setInternet(3);
                            bestbuy.setDogecoin(bestbuy.getDogecoin() - bestbuy.getComputerPriceFor("Internet Level 3"));
                            cout << "You have " << bestbuy.getDogecoin() << " dogecoin left! " << endl;
                            cout << endl;
                        }
                        else if(bestbuy.getInternet() >= internetSelection)
                        {
                            cout << "You have already surpassed that internet level!" << endl;
                            cout << endl;
                        }
                        // If the user doesn't have enough dogecoin
                        else
                        {
                            cout << "You don't have enough dogecoins to complete the purchase, choose a different level!!" << endl;
                            cout << "You have " << bestbuy.getDogecoin() << " dogecoin left! " << endl;
                            cout << endl;
                        }
                        break;
                    }
                    case 4:
                    {
                        if((bestbuy.getDogecoin() - bestbuy.getComputerPriceFor("Internet Level 4")) >= 0 && (bestbuy.getInternet() < internetSelection))
                        {
                            bestbuy.setInternet(4);
                            bestbuy.setDogecoin(bestbuy.getDogecoin() - bestbuy.getComputerPriceFor("Internet Level 4"));
                            cout << "You have " << bestbuy.getDogecoin() << " dogecoin left! " << endl;
                            cout << endl;
                        }
                        else if(bestbuy.getInternet() >= internetSelection)
                        {
                            cout << "You have already surpassed that internet level!" << endl;
                            cout << endl;
                        }
                        // If the user doesn't have enough dogecoin
                        else
                        {
                            cout << "You don't have enough dogecoins to complete the purchase, choose a different level!!" << endl;
                            cout << "You have " << bestbuy.getDogecoin() << " dogecoin left! " << endl;
                            cout << endl;
                        }
                        break;
                    }
                    case 5:
                    {
                        if((bestbuy.getDogecoin() - bestbuy.getComputerPriceFor("Internet Level 5")) >= 0 && (bestbuy.getInternet() < internetSelection))
                        {
                            bestbuy.setInternet(5);
                            bestbuy.setDogecoin(bestbuy.getDogecoin() - bestbuy.getComputerPriceFor("Internet Level 5"));
                            cout << "You have " << bestbuy.getDogecoin() << " dogecoin left! " << endl;
                            cout << endl;
                        }
                        else if(bestbuy.getInternet() >= internetSelection)
                        {
                            cout << "You have already surpassed that internet level!" << endl;
                            cout << endl;
                        }
                        // If the user doesn't have enough dogecoin
                        else
                        {
                            cout << "You don't have enough dogecoins to complete the purchase, choose a different level!!" << endl;
                            cout << "You have " << bestbuy.getDogecoin() << " dogecoin left! " << endl;
                            cout << endl;
                        }
                        break;
                    }
                    default: cout << "Invalid input." << endl; break;
                    cout << endl;
                }
                
                break;
            }
            default: cout << "Invalid input." << endl; break;
            cout << endl;
        }

        // Print the menu:
        cout << "Parts currently available to buy: " << endl;
        cout << "1. Computer Parts - price varies on purchase" << endl;
        cout << "2. Antivirus Software - " << bestbuy.getComputerPriceFor("Antivirus Software") << " dogecoins " << endl;
        cout << "3. Virtual Private Network (VPN) - " << bestbuy.getComputerPriceFor("VPN")  << " dogecoins" << endl;
        cout << "4. Internet Provider - price varies on purchase" << endl;
        cout << "5. Quit" << endl;
        cin >> bestBuySelection;
    }

    // When the user selects 5, the user exits bestBuy
    cout << endl;

    cout << "You now currently own: " << endl;
    cout << bestbuy.totalComputerParts() << " Computer Parts" << endl;
    cout << bestbuy.getAntiVirusSoftware() << " Antivirus Software" << endl;
    cout << bestbuy.getVPN() << " VPNs" << endl;
    cout << "Internet Level " << bestbuy.getInternet() << endl;
    cout << "You have " << bestbuy.getDogecoin() << " dogecoins" << endl;
    cout << endl;

    cout << "Exiting BestBuy... " << endl;

    return bestbuy;
}



/*
    The function takes in a string, which has elements seperated by a deliminter, and seperates the string at the deliminter and returns
    the amount of the times the string was split
    Name:       split()
    Parameters:
                splitString (string) - the string to be split at the deliminters
                deliminter (char) - where the string will be split
                arr[] (string) - the array where the split string will be added to
                arraySize (int) - the max size of the array
    Return Value:
                splitCounter (int) - will store the amount of times the string was split
*/
int Game::split(string splitString, char deliminter, string arr[], int arraySize )
{
    // Check if the string inputted has characters in it
    if (splitString.substr(0,1) == "")
    {
        // 0 will be returned if the string is empty
        return 0;
    }


    // Declare and initialize variables
    // deliminiterCounter (int) - count the amount of times the deliminiter appears in the string
    int delimiterCounter = 0;
    // position (int) - store where the deliminter is in the string
    int position = 0;
    // arrayIndex (int) - store the current index where the split string will be stored
    int arrayIndex = 0;
    // subSize (int) - store the size of the subString up to the deliminter
    int subSize = 0;
    // Return Value:
    // splitCounter (int) - store the amount of times the string was split
    int splitCounter = 0;
    // splitStringLength (int) - store the length of the string that is inputted 
    int splitStringLength = splitString.length();


    // Check the number of times the deliminter appears in the string
    for (int i = 0; i < splitStringLength; i++)
    {
        if(splitString[i] == deliminter)
        {
            // deliminterCounter increases by 1
            delimiterCounter++;
        }
    }


    // If delimiterCounter = 0, 1 is returned, and the string is assinged to the first index in the array
    if (delimiterCounter == 0)
    {
        arr[0] = splitString;
        return 1;
    }

    // If the deliminterCounter + 1 is greater than the expected array size, -1 will be returned and only elements up to the array size 
    // will be added to the array
    else if (delimiterCounter + 1 > arraySize)
    {
        // For every character in the string
        for (int i = 0; i < splitStringLength; i++)
        {
            // subSize increases by 1
            subSize++;
            
            // If the character in the substring = the delimiter and the current arrayIndex is less than the max array size
            if ((splitString[i] == deliminter) && (arrayIndex <= arraySize))
            {
                // posititon of the delimiter is assigned to position
                position = i;

                // the split string is added to the array 
                arr[arrayIndex] = splitString.substr((position-subSize+1), (subSize -1));

                // Increase arrayIndex by 1
                arrayIndex++;
                // subSize gets reset to 0
                subSize = 0;
                // splitCounter increases by 1
                splitCounter++;

            }
        }
        // Last item to the string will be added to the array
        arr[arrayIndex] = splitString.substr(position + 1, splitString.length()-1 );
        splitCounter++;

        // -1 will be returned
        return -1;

    } else
    {
        // For every character in the string
        for (int i = 0; i < splitStringLength; i++)
        {
            // subSize increases by 1
            subSize++;
            
            // If the character in the substring = the delimiter and the current arrayIndex is less than the max array size
            if ((splitString[i] == deliminter) && (arrayIndex <= arraySize))
            {

                // posititon of the delimiter is assigned to position
                position = i;

                // the split string is added to the array 
                arr[arrayIndex] = splitString.substr((position-subSize+1), (subSize -1));

                // Increase arrayIndex by 1
                arrayIndex++;
                // subSize gets reset to 0
                subSize = 0;
                // splitCounter increases by 1
                splitCounter++;

            }
        }
        // Last item to the string will be added to the array
        arr[arrayIndex] = splitString.substr(position + 1, splitString.length()-1 );
        splitCounter++;
    }

    return splitCounter++;

}