// CSCi 1300 Fall 2021
// Author: Bella Longo
// Recitation: Spencer Paulissen
// Project 3: Code Skeleton

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
using namespace std;

class Player
{
    public:
    // Constructors
    Player();
    Player(string n, int f, int p, int hd);

    // Setters
    void setPlayerName(string n);
    void setFrustration(int f);
    void setPlayerProgress(int p);
    void setNumHacekersDefeated(int hd);

    // Getters
    string getPlayerName();
    int getFrustration();
    int getplayerProgress();
    int numHackersDefeated();

    private:
    string playerName;
    int playerFrustration;
    int playerProgress;
    int playerHackersDefeated;

};

#endif