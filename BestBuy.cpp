// CSCi 1300 Fall 2021
// Author: Bella Longo
// Recitation: Spencer Paulissen
// Project 3: Code Skeleton

#include "BestBuy.h"
#include <string>
#include <iostream>
using namespace std;

// DEFUALT CONSTRUCTORS
// Sets the number of dogecoins to 200, and numbe of computers, interet, and vpn to 1, and the rest are intialized to 0
BestBuy::BestBuy()
{
    numDogecoins = 200;
    numAntivirusSoftware = 0;
    numComputers = 1;
    numVPN = 1;
    numInternet = 1;

    // Intialize all computer parts to 0
    for(int i = 0; i < 7; i++)
    {
        computerParts[i] = 0;
    }

    // Set all prices to server room 1 prices
    partPrices[0] = 10;         // CPU
    partPrices[1] = 20;         // GPU
    partPrices[2] = 5;          // Power Supply Unit
    partPrices[3] = 15;         // Computer Case
    partPrices[4] = 5;          // Internet Card
    partPrices[5] = 10;         // Keyboard and Mouse
    partPrices[6] = 100;        // Premade Computer

    otherPrices[0] = 10;        // Antivirus Software
    otherPrices[1] = 20;        // VPN
    internetPrices[0] = 10;     // Internet Level 2
    internetPrices[1] = 25;     // Internet Level 3
    internetPrices[2] = 40;     // Internet Level 4
    internetPrices[3] = 50;     // Internet Level 5
}

// Set values to the parameters
BestBuy::BestBuy(int dc, int avs, int c, int cp[7], int v, int i)
{   
    numDogecoins = dc;
    numAntivirusSoftware = avs;
    numComputers = c;
    numVPN = v;
    numInternet = i;

    for(int i = 0; i < 7; i++)
    {
        computerParts[i] = cp[i];
    }
}

// SETTERS
/*
    Sets numDogecoins to the input value
    Name:       setDogeCoin()
    Parameters:
                dc (int) - input value 
    Return Value:
                none
*/
void BestBuy::setDogecoin(int dc)
{
    numDogecoins = dc;
}
/*
    Sets the prices of all of the items at BestBuy depending on what room the user is currently in
    Name:       setComputerPriceFor(int serverRoom)
    Parameters:
                serverRoom (int)
    Return Value:
                none

*/
void BestBuy::setComputerPriceFor(int serverRoom)
{
    // If the serverRoom =1
    if (serverRoom == 1)
    {
        // Set all prices to server room 1 prices
        partPrices[0] = 10;         // CPU
        partPrices[1] = 20;         // GPU
        partPrices[2] = 5;          // Power Supply Unit
        partPrices[3] = 15;         // Computer Case
        partPrices[4] = 5;          // Internet Card
        partPrices[5] = 10;         // Keyboard and Mouse
        partPrices[6] = 100;        // Premade Computer

        otherPrices[0] = 10;        // Antivirus Software
        otherPrices[1] = 20;        // VPN
        internetPrices[0] = 10;     // Internet Level 2
        internetPrices[1] = 25;     // Internet Level 3
        internetPrices[2] = 40;     // Internet Level 4
        internetPrices[3] = 50;     // Internet Level 5
    }
    else if (serverRoom == 2)
    {
        // Set all prices to server room 2 prices (1 prices * 1.10)
        partPrices[0] = 10*1.10;         // CPU
        partPrices[1] = 20*1.10;         // GPU
        partPrices[2] = 5*1.10;          // Power Supply Unit
        partPrices[3] = 15*1.10;         // Computer Case
        partPrices[4] = 5*1.10;          // Internet Card
        partPrices[5] = 10*1.10;         // Keyboard and Mouse
        partPrices[6] = 100*1.10;        // Premade Computer

        otherPrices[0] = 10*1.10;        // Antivirus Software
        otherPrices[1] = 20*1.10;        // VPN
        internetPrices[0] = 10*1.10;     // Internet Level 2
        internetPrices[1] = 25*1.10;     // Internet Level 3
        internetPrices[2] = 40*1.10;     // Internet Level 4
        internetPrices[3] = 50*1.10;     // Internet Level 5
        
    }
    else if (serverRoom == 3)
    {
        // Set all prices to server room 2 prices (1 prices * 1.20)
        partPrices[0] = 10*1.20;         // CPU
        partPrices[1] = 20*1.20;         // GPU
        partPrices[2] = 5*1.20;          // Power Supply Unit
        partPrices[3] = 15*1.20;         // Computer Case
        partPrices[4] = 5*1.20;          // Internet Card
        partPrices[5] = 10*1.20;         // Keyboard and Mouse
        partPrices[6] = 100*1.20;        // Premade Computer

        otherPrices[0] = 10*1.20;        // Antivirus Software
        otherPrices[1] = 20*1.20;        // VPN
        internetPrices[0] = 10*1.20;     // Internet Level 2
        internetPrices[1] = 25*1.20;     // Internet Level 3
        internetPrices[2] = 40*1.20;     // Internet Level 4
        internetPrices[3] = 50*1.20;     // Internet Level 5
    }
    else if(serverRoom == 4)
    {
        // Set all prices to server room 2 prices (1 prices * 1.25)
        partPrices[0] = 10*1.25;         // CPU
        partPrices[1] = 20*1.25;         // GPU
        partPrices[2] = 5*1.25;          // Power Supply Unit
        partPrices[3] = 15*1.25;         // Computer Case
        partPrices[4] = 5*1.25;          // Internet Card
        partPrices[5] = 10*1.25;         // Keyboard and Mouse
        partPrices[6] = 100*1.25;        // Premade Computer

        otherPrices[0] = 10*1.25;        // Antivirus Software
        otherPrices[1] = 20*1.25;        // VPN
        internetPrices[0] = 10*1.25;     // Internet Level 2
        internetPrices[1] = 25*1.25;     // Internet Level 3
        internetPrices[2] = 40*1.25;     // Internet Level 4
        internetPrices[3] = 50*1.25;     // Internet Level 5
    }
    else
    {
        // Set all prices to server room 2 prices (1 prices * 1.30)
        partPrices[0] = 10*1.30;         // CPU
        partPrices[1] = 20*1.30;         // GPU
        partPrices[2] = 5*1.30;          // Power Supply Unit
        partPrices[3] = 15*1.30;         // Computer Case
        partPrices[4] = 5*1.30;          // Internet Card
        partPrices[5] = 10*1.30;         // Keyboard and Mouse
        partPrices[6] = 100*1.30;        // Premade Computer

        otherPrices[0] = 10*1.30;        // Antivirus Software
        otherPrices[1] = 20*1.30;        // VPN
        internetPrices[0] = 10*1.30;     // Internet Level 2
        internetPrices[1] = 25*1.30;     // Internet Level 3
        internetPrices[2] = 40*1.30;     // Internet Level 4
        internetPrices[3] = 50*1.30;     // Internet Level 5
    }
}
/*
    Sets numAntiVirusSoftware to the input value
    Name:       setAntiVirusSoftware()
    Parameters:
                avs (int) - input value 
    Return Value:
                none
*/
void BestBuy::setAntiVirusSoftware(int avs)
{
    numAntivirusSoftware = avs;
}
/*
    Sets numComputers to the input value
    Name:       setComputers()
    Parameters:
                c (int) - input value 
    Return Value:
                none
*/
void BestBuy::setComputers(int c)
{
    numComputers = c;
}
/*
    Sets the amount of a specific computer part at the input value
    Name:       setComputerPartsAt()
    Parameters:
                part (string) - the computer part
                value (int) - the number of the specific computer part
    Return Value:
                true/false (bool) - true if the number of parts was successfully updated
*/
bool BestBuy::setComputerPartsAt(int index, int value)
{
    // If the index is less than 7, and the number of that specific part is less than or equal to 3
    if ((index < 7) && (value <= 3))
    {
        // Add the current number of a specific computer part to the new one
        computerParts[index] = value;
        return true;
    }
    else 
    {
        return false;
    }
}
/*
    Sets numVPN to the input value
    Name:       setVPN()
    Parameters:
                v (int) - input value 
    Return Value:
                none
*/
void BestBuy::setVPN(int v)
{
    numVPN = v;
}
/*
    Sets numInternet to the input value
    Name:       setInternet()
    Parameters:
                i (int) - input value 
    Return Value:
                none
*/
void BestBuy::setInternet(int i)
{
    numInternet = i;
}

// Getters
/*
    Returns the numDogecoins
    Name:       getDogecoin()
    Parameters:
                none
    Return Value:
                numDogeCoins
*/
int BestBuy::getDogecoin()
{
    return numDogecoins;
}
/*
    Returns the numAntiVirusSoftware
    Name:       getAntiVirusSoftware()
    Parameters:
                none
    Return Value:
                numAntiVirusSoftware
*/
int BestBuy::getAntiVirusSoftware()
{
    return numAntivirusSoftware; 
}
/*
    Returns the numComputers
    Name:       getComputers()
    Parameters:
                none
    Return Value:
                numComputers
*/
int BestBuy::getComputers()
{
    return numComputers;
}
/*
    Returns the number of a specific computer part
    Name:       getComputerParts()
    Parameters:
                none
    Return Value:
                numParts
*/
int BestBuy::getComputerParts(string part)
{
    // Return Value
    int numParts = 0;

    if(part == "CPU")
    {
        numParts = computerParts[0];
    }
    else if (part == "GPU")
    {
        numParts = computerParts[1];
    }
    else if (part == "Power Supply Unit")
    {
        numParts = computerParts[2];
    }
    else if(part == "Computer Case")
    {
        numParts = computerParts[3];
    }
    else if(part == "Internet Card")
    {
        numParts = computerParts[4];
    }
    else if (part == "Keyboard and Mouse")
    {
        numParts = computerParts[5];
    }
    else if (part == "Premade Computer")
    {
        numParts = computerParts[6];
    }
    else
    {
        return -1;
    }

    return numParts;


}
/*
    Returns the numVPN
    Name:       getVPN()
    Parameters:
                none
    Return Value:
                numVPN
*/
int BestBuy::getVPN()
{
    return numVPN;
}
/*
    Returns the numInternet
    Name:       getInternet()
    Parameters:
                none
    Return Value:
                numInternet
*/
int BestBuy::getInternet()
{
    return numInternet;
}

/*
    Returns the price for a specific part
    Name:       getComputerPriceFor()
    Parameters:
                part (string)
    Return Value:
                bestBuyPrice (int)
*/
int BestBuy::getComputerPriceFor(string part)
{
    // Return Value
    int bestBuyPrice = 0;

    if(part == "CPU")
    {
        bestBuyPrice = partPrices[0];
    }
    else if (part == "GPU")
    {
        bestBuyPrice = partPrices[1];
    }
    else if (part == "Power Supply Unit")
    {
        bestBuyPrice = partPrices[2];
    }
    else if(part == "Computer Case")
    {
        bestBuyPrice = partPrices[3];
    }
    else if (part == "Internet Card")
    {
        bestBuyPrice = partPrices[4];
    }
    else if (part == "Keyboard and Mouse")
    {
        bestBuyPrice = partPrices[5];
    }
    else if (part == "Premade Computer")
    {
        bestBuyPrice = partPrices[6];
    }
    else if(part == "Antivirus Software")
    {
        bestBuyPrice = otherPrices[0];
    }
    else if (part == "VPN")
    {
        bestBuyPrice = otherPrices[1];
    }
    else if (part == "Internet Level 2")
    {
        bestBuyPrice = internetPrices[0];
    }
    else if (part == "Internet Level 3")
    {
        bestBuyPrice = internetPrices[1];
    }
    else if (part == "Internet Level 4")
    {
        bestBuyPrice = internetPrices[2];
    }
    else if (part == "Internet Level 5")
    {
        bestBuyPrice = internetPrices[3];
    }
    else
    {
        bestBuyPrice = 0;
    }

    return bestBuyPrice;

}

// Methods
/*
    Calculates and returns the total number of computer parts the player has
    Name:       totalComputerParts()
    Parameters:
                none
    Return Value:
                totalCP
*/
int BestBuy::totalComputerParts()
{
    int totalCP = 0;

    for (int i = 0; i < 7; i++)
    {
        totalCP += computerParts[i];
    }

    return totalCP;
}
