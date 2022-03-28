// CSCi 1300 Fall 2021
// Author: Bella Longo
// Recitation: Spencer Paulissen
// Project 3: Code Skeleton

#ifndef COMPUTER_H
#define COMPUTER_H

#include <iostream>
#include <string>
using namespace std;

class Computer
{
    public:
    // Constructors
    Computer();
    Computer(int m, int v);

    // Setters
    void setMaintenanceLevel(int m);
    void setNumViruses(int v);
    void setVirusRisk(int p);

    // Getters
    int getMaintenanceLevel();
    int getnumViruses();
    int getVirusRisk();

    private:
    int maintenanceLevel;
    int numViruses;
    int virusPercentage;

};

#endif