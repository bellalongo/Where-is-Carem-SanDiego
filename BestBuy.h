// CSCi 1300 Fall 2021
// Author: Bella Longo
// Recitation: Spencer Paulissen
// Project 3: Code Skeleton

#ifndef BESTBUY_H
#define BESTBUY_H

#include <iostream>
#include <string>
using namespace std;

class BestBuy
{
    public:
    // Constructors
    BestBuy();
    BestBuy(int dc, int avs, int c, int cp[7], int v, int i);

    // Setters
    void setDogecoin(int dc);
    void setAntiVirusSoftware(int avs);
    void setComputers(int c);
    bool setComputerPartsAt(int index, int value);
    void setVPN(int v);
    void setInternet(int i);
    void setComputerPriceFor(int serverRoom);

    // Getters
    int getDogecoin();
    int getAntiVirusSoftware();
    int getComputers();
    int getComputerParts(string part);
    int getVPN();
    int getInternet();
    int getComputerPriceFor(string part);

    // Methods
    int totalComputerParts();


    private:
    int numDogecoins;
    int numAntivirusSoftware;
    int numComputers;
    int computerParts[7];
    int numVPN;
    int numInternet;
    int partPrices[7];
    int otherPrices[3];
    int internetPrices[4];

};

#endif