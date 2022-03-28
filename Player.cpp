// CSCi 1300 Fall 2021
// Author: Bella Longo
// Recitation: Spencer Paulissen
// Project 3: Code Skeleton

#include "Player.h"
#include <iostream>
#include <string>
using namespace std;

// DEFUALT CONSTRUCTORS
// Set the players name to blank, and their frustration level to 0, progress to 0, and number of hackers defeated to 0
Player::Player()
{
    playerName = "";
    playerFrustration = 0;
    playerProgress = 0;
    playerHackersDefeated = 0;

}
// Set the player's name, frustration level, progress, and hackers defeated to the parameters
Player::Player(string n, int f, int p, int hd)
{
    playerName = n;
    playerFrustration = f;
    playerProgress = p;
    playerHackersDefeated = hd;
}

// SETTERS
/*
    Sets playerName to the input value
    Name:       setPlayerName()
    Parameters:
                n (string) - input value 
    Return Value:
                none
*/
void Player::setPlayerName(string n)
{
    playerName = n;
}
/*
    Sets playerFrustration to the input value
    Name:       setFrustration()
    Parameters:
                f (int) - input value 
    Return Value:
                none
*/
void Player::setFrustration(int f)
{
    playerFrustration = f;
}
/*
    Sets playerProgress to the input value
    Name:       setPlayerProgress()
    Parameters:
                p (int) - input value 
    Return Value:
                none
*/
void Player::setPlayerProgress(int p)
{
    playerProgress = p;
}
/*
    Sets numHackersDefeated to the input value
    Name:       setNumHackersDefeated()
    Parameters:
                hd (int) - input value 
    Return Value:
                none
*/
void Player::setNumHacekersDefeated(int hd)
{
    playerHackersDefeated = hd;
}

// GETTERS
/*
    Returns player's name
    Name:       getPlayerName()
    Parameters:
                none
    Return Value:
                playerName
*/
string Player::getPlayerName()
{
    return playerName;
}
/*
    Returns player's frustration
    Name:       getFrustration()
    Parameters:
                none
    Return Value:
                playerFrustration
*/
int Player::getFrustration()
{
    return playerFrustration;
}
/*
    Returns player's progress
    Name:       getplayerProgress()
    Parameters:
                none
    Return Value:
                playerProgress
*/
int Player::getplayerProgress()
{
    return playerProgress;
}
/*
    Returns number of hackers the player has defeated 
    Name:       numHackersDefeated()
    Parameters:
                none
    Return Value:
                play
*/
int Player::numHackersDefeated()
{
    return playerHackersDefeated;
}