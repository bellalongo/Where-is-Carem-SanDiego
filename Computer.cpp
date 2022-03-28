// CSCi 1300 Fall 2021
// Author: Bella Longo
// Recitation: Spencer Paulissen
// Project 3: Code Skeleton

#include "Computer.h"
#include <iostream>
#include <string>
using namespace std;

// DEFUALT CONSTRUCTORS
// Set all values to 0
Computer::Computer()
{
    maintenanceLevel = 100;
    numViruses = 0;
    virusPercentage = 0;
}
// Set all values to the paremetrized values
Computer::Computer(int m, int v)
{
    maintenanceLevel = m;
    numViruses = v;
}

// Setters
/*
    Sets maintence level to the input value
    Name:       setMaintenenceLevel()
    Parameters:
                m (int) - input value 
    Return Value:
                none
*/
void Computer::setMaintenanceLevel(int m)
{
    maintenanceLevel = m;
}
/*
    Sets numViruses to the input value
    Name:       setNumViruses()
    Parameters:
                v (int) - input value 
    Return Value:
                none
*/
void Computer::setNumViruses(int v)
{
    numViruses = v;
}
/*
    Sets virusPercentage to the input value
    Name:       setVirusRisk()
    Parameters:
                p (int) - input value 
    Return Value:
                none
*/
void Computer::setVirusRisk(int p)
{
    virusPercentage = p;
}

// Getters
/*
    Returns the computer's maintenance level
    Name:       getRoom()
    Parameters:
                none
    Return Value:
                maintenanceLevel
*/
int Computer::getMaintenanceLevel()
{
    return maintenanceLevel;
}
/*
    Returns the number of viruses the computer has 
    Name:       getNumViruses()
    Parameters:
                none
    Return Value:
                numViruses
*/
int Computer::getnumViruses()
{
    return numViruses;
}
/*
    Returns the percent risk the computer has of being infecteted
    Name:       getVirusRisk()
    Parameters:
                none
    Return Value:
                virusPercentage
*/
int Computer::getVirusRisk()
{
    return virusPercentage; 
}