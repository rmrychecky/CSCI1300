#ifndef MILESTONES_H 
#define MILESTONES_H 
#include <iostream>
#include <iomanip>
#include <string>
#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

class Milestones //creating book class
{
private:
   string forts[7];
   string rivers[4];
   int fortDistances[7];
   int riverDistances[4];
   int fortDepth[7];
   int riverDepth[4];
   string filenameFort;
   string filenameRiver;
   int milesTraveled;
   int milestoneDistance;
   double inflation;
   int holderRiver; 
   int holderFort; 
   
public: 

   Milestones(); //set milesTraveled and milestoneDistance to 0 and the filenames to the fort and river files
   
   void setmilesTraveled(int miles); //add previous value assinged to variable to additional input miles;
   
   void setmilesTraveled1(int miles);

   int getmilesTraveled(); //get the milesTraveled 
   
   void setHolderRiver(int increment);
   
   int getHolderRiver();
   
   void setHolderFort(int increment);
   
   int getHolderFort();
   
   void setFort(string filenameFort); //open both files with ifstream and compare the first two
   //if the first one in the fort is greater than that in the river write the river and move to next river
   //repeat this pattern until the array (milestones[]) is full and you have moved through both the files
   
   string getforts(int index);
   
   int getfortDistances(int index);
   
   int getfortDepth(int index);
   
   void setRiver(string filenameRiver); //open both files with ifstream and compare the first two
   //if the first one in the fort is greater than that in the river write the river and move to next river
   //repeat this pattern until the array (milestones[]) is full and you have moved through both the files
   
   string getrivers(int index);
   
   int getriverDistances(int index);
   
   int getriverDepth(int index);

   int getMilestones(); //compare the milesTraveled value with the milestones array
   //traverse the whole array and see when the next milestone is and return the next milestone
   
   void setmilestoneDistance(int milesTraveled); //compare the milesTraveled value with the milestones array
   //must convert the string value in the array 
   
   void setmilestoneDistance1(int value);
   
   int getmilestoneDistance(); //compare the milesTraveled value with the milestones array
   //return the distance to the next milestone
   
   void setInflation(int number1);

   double getInflation();
   
};

#endif
