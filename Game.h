// CSCi 1300 Fall 2021
// Author: Bella Longo
// Recitation: Spencer Paulissen
// Project 3: Code Skeleton

#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include "BestBuy.h"
#include "Player.h"
#include "Hacker.h"
#include "Computer.h"
#include "Map.h"
using namespace std;

class Game
{
    public:
    // Constructors
    Game();
    Game(int roomNum, BestBuy bb, Computer c, Player pN, Hacker h, Map m, Hacker roomHackers, int hackerNum, string splitS, char delimit, string array[], int size);

    // Functions
    Map serverRoom(int roomNum);
    void repairComputer(BestBuy bb, Computer c);
    void useAntivirus(BestBuy bb, Computer c);
    void browseStackOverflow(BestBuy bb, Player pN);
    void NPC(BestBuy bestbuy);
    void fightAHacker(Hacker &h, Player &pN, BestBuy &bb, Computer &c, Map &m);
    Hacker setHackerInfo(Hacker roomHackers, int roomNum, int hackerNum);
    bool canProgress(Map &m, Player &pN);
    bool getVirus(Computer c);
    bool gameOver(Player pN, Hacker h, Computer c);
    bool rockPaperScissors();
    bool misfortune(Computer c, BestBuy bb, Player p);
    void statusUpdate(Player &pN, Computer &c, BestBuy &bb, Hacker &h);
    bool puzzle(BestBuy bb);
    BestBuy bestBuy(BestBuy bb, int rommNum);
    int split(string splitS, char delimit, string array[], int size );

    private:
    int serverRoomNum;
    BestBuy bestbuy;
    Computer computer;
    Player playerName;
    Hacker hacker;
    Map map;
    Hacker serverRoomHackers;
    int numHackers;
    string splitString;
    char delimiter; 
    string arr[100];
    int arraySize;
};

#endif