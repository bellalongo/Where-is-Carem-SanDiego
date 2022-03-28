// CSCi 1300 Fall 2021
// Author: Bella Longo
// Recitation: Spencer Paulissen
// Project 3: Code Skeleton

#include "Hacker.h"
#include <iostream>
#include <string>
using namespace std;

// DEFUALT CONSTRUCTORS
// Set all values to 0 or blanks
Hacker::Hacker()
{
    for(int i = 0; i < 4; i++)
    {
        hackers[i] = "";
    }
    carmenProgress = 0;
    room = 1;
    hackerIndex = 0;
}
// Set all values to the parametrized values
Hacker::Hacker(string n, int p, int r)
{
    for(int i = 0; i < 4; i++)
    {
        hackers[i] = "";
    }
    carmenProgress = p;
    room = r;
}

// SETTERS
/*
    Sets hackerName to the input value
    Name:       setHackerName()
    Parameters:
                n (string) - input value 
    Return Value:
                none
*/
void Hacker::setHackerName(int index, string n)
{
    hackers[index] = n;
}
/*
    Sets carmenProgress to the input value
    Name:       setPlayerName()
    Parameters:
                p (int) - input value 
    Return Value:
                none
*/
void Hacker::setCarmenProgress(int p)
{
    carmenProgress = p;
}
/*
    Sets room to the input value
    Name:       setRoom()
    Parameters:
                r (int) - input value 
    Return Value:
                none
*/
void Hacker::setRoom(int r)
{
    room = r;
}
/*
    Sets index of the current hacker
    Name:       setHackerIndex()
    Parameters:
                index (int) - input value 
    Return Value:
                none
*/
void Hacker::setHackerIndex(int index)
{
    hackerIndex = index;
}

// GETTERS
/*
    Returns hacker's name
    Name:       getHackerName()
    Parameters:
                none
    Return Value:
                hackerName
*/
string Hacker::getHackerName(int index)
{
    return hackers[index];
}
/*
    Returns carmen's progress
    Name:       getCarnmenProgress()
    Parameters:
                none
    Return Value:
                carmenProgress
*/
int Hacker::getCarmenProgress()
{
    return carmenProgress;
}
/*
    Returns hacker's room number 
    Name:       getRoom()
    Parameters:
                none
    Return Value:
                room
*/
int Hacker::getRoom()
{
    return room;
}
/*
    Returns hacker's index
    Name:       getHackerIndex()
    Parameters:
                none
    Return Value:
                room
*/
int Hacker::getHackerIndex()
{
    return hackerIndex;
}