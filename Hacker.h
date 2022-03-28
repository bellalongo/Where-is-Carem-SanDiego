// CSCi 1300 Fall 2021
// Author: Bella Longo
// Recitation: Spencer Paulissen
// Project 3: Code Skeleton

#ifndef HACKER_H
#define HACKER_H

#include <iostream>
#include <string>
using namespace std;

class Hacker
{
    public:
    // Constructors
    Hacker();
    Hacker(string n, int p, int r);

    // Setters
    void setHackerName(int index, string n);
    void setCarmenProgress(int p);
    void setRoom(int r);
    void setHackerIndex(int index);

    // Getters
    string getHackerName(int index);
    int getCarmenProgress();
    int getRoom();
    int getHackerIndex();

    private:
    string hackerName;
    int carmenProgress;
    int room;
    string hackers[4];
    int hackerIndex;
};

#endif
