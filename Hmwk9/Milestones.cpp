#include <iostream>
#include <iomanip>
#include <string>
#include <iostream>
#include <cmath>
#include <fstream>
#include <time.h>
#include "Animals.h" 
#include "Milestones.h"
#include "Store.h"
#include "Turns.h"
using namespace std;

int split (string str, char c, string array[], int size) //given split function
{
    if (str.length() == 0) {
         return 0;
     }
    string word = "";
    int count = 0;
    str = str + c;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == c)
        {
            if (word.length() == 0)
                continue;
            array[count++] = word;
            word = "";
        } else {
            word = word + str[i];
        }
    }
    return count;

}

Milestones :: Milestones() //create Milestones constructor with empty strings as set variables
{
  filenameFort = "fort-milestones.txt";
  filenameRiver = "river-milestones.txt";
  milesTraveled = 0;
  milestoneDistance = 0;
  holderRiver = 0;
  holderFort = 0;
  inflation = 1.0;
}
//set and get functions for the private variables 

void Milestones :: setmilesTraveled(int miles)
{
  milesTraveled = milesTraveled + miles;
}

void Milestones :: setmilesTraveled1(int miles)
{
    milesTraveled = miles;
}

int Milestones :: getmilesTraveled()
{
  return milesTraveled;
}

void Milestones :: setHolderRiver(int increment)
{
    holderRiver = holderRiver + increment;
}

int Milestones :: getHolderRiver()
{
    return holderRiver;
}

void Milestones :: setHolderFort(int increment)
{
    holderFort = holderFort + increment;
}

int Milestones :: getHolderFort()
{
    return holderFort;
}

//set fort names, distances and depth arrays
void Milestones :: setFort(string filenameFort)
{
    ifstream fileF; //open the file and initilize where it is to be stored
    fileF.open(filenameFort);
    string lineF;
    string array[3];
    int i = 0;

    //if the file is open get each time and split into perpective arrays
    if (fileF.is_open()) //if file is open
    {
        while (getline(fileF, lineF)) //while you can still grab lines
        { 
            split(lineF, ',', array, 3); //split the second portion of array at each space

                forts[i] = array[0];
                fortDistances[i] = stoi(array[1]);
                fortDepth[i] = stoi(array[2]);
                i++;
        }
    }
    
    fileF.close(); //close files
}

string Milestones :: getforts(int index)
{
    return forts[index];
}

int Milestones :: getfortDistances(int index)
{
    return fortDistances[index];
}

int Milestones :: getfortDepth(int index)
{
    return fortDepth[index];
}

//set river names, distances and depth arrays
void Milestones :: setRiver(string filenameRiver)
{
    ifstream fileR; //open the file and initilize where it is to be stored
    fileR.open(filenameRiver);
    string lineR;
    string array[3];
    int i = 0;

//if the file is open get each time and split into perpective arrays

    if (fileR.is_open()) //if file is open
    {
        while (getline(fileR, lineR)) //while you can still grab lines
        { 
            split(lineR, ',', array, 3); //split the second portion of array at each space

                rivers[i] = array[0];
                riverDistances[i] = stoi(array[1]);
                riverDepth[i] = stoi(array[2]);
                i++;
        }
    }
    
    fileR.close(); //close file
    
}

string Milestones :: getrivers(int index)
{
    return rivers[index]; //get river name at index
}

int Milestones :: getriverDistances(int index)
{
    return riverDistances[index]; //get river distance at index
}

int Milestones :: getriverDepth(int index)
{
    return riverDepth[index]; //get the river depth at index
}
   
int Milestones :: getMilestones() 
{
    string answer;
    Turns member;
    Store member1;
    string numberOxen;
    string poundsFood;
    string numberBullets;
    string numberParts;
    string numberKits;
    int money = 0;
    int returnTrail;
   
   
   
  if (riverDistances[holderRiver] < fortDistances[holderFort]) //river distances is the next milestone if the riverDistances is less than the fortDistances
  {
      returnTrail = 1;
      
  }
  if (riverDistances[holderRiver] > fortDistances[holderFort]) //fort distances is the next milestone if the fortDistances is less than the riverDistances
  {
      returnTrail = 2;

  }
  
   return returnTrail;
}

void Milestones :: setmilestoneDistance(int milesTraveled)
{
  if (milesTraveled == 0) //first milestone is river at 0 index
  {
      milestoneDistance = riverDistances[0];
  }
  else if (riverDistances[holderRiver] < fortDistances[holderFort]) 
  {
      if (milesTraveled >= riverDistances[holderRiver]) //get the next milestone by holder + 1
      {
          milestoneDistance = riverDistances[holderRiver + 1];
      }
      else if (milesTraveled < riverDistances[holderRiver]) 
      {
          milestoneDistance = riverDistances[holderRiver] - milesTraveled; //if you have not made it then the milestone stays the same and the distqnce will decrease
      }
  }
  else if (riverDistances[holderRiver] > fortDistances[holderFort])
  {
      if (milesTraveled >= fortDistances[holderFort]) 
      {
          milestoneDistance = fortDistances[holderFort + 1]; //get the next milestone by holder + 1
      }
      else if (milesTraveled < fortDistances[holderFort])
      {
          milestoneDistance = fortDistances[holderFort] - milesTraveled; //if you have not made it then the milestone stays the same and the distqnce will decrease
      }
       
  }
   
}

void Milestones :: setmilestoneDistance1(int value)
{
    milestoneDistance = value;
}

int Milestones :: getmilestoneDistance()
{
    return milestoneDistance;
}

void Milestones :: setInflation(int number1)
{
    inflation = inflation + number1;
}

double Milestones :: getInflation() //set inflation to + .25 at each fort milestone!
{
    return inflation;
}