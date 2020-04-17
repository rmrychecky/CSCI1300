#ifndef TURNS_H
#define TURNS_H
#include <iostream>
#include <iomanip>
#include <string>
#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

class Turns
{
public:
   Turns(); //set currentMonth to 03 and currentDay to 28 as default 
   
   //at the beginning of every turn run a status update to update all the information inputs
   //these values are updated in the previous turn so they are accurate when called
   void setStatusUpdate(int milesTraveled, int miley, int totalFood, int totalBullets, int money);
   
   // //Get function which returns strings with statements about the current date, milesTraveled, distance to the next milestone,
   // //totalFood, totalBullets, and money.
   // string getStatusUpdate();
   
   //this function will update the date and food values after a rest turn
   int rest(int players, int input1); //if player chooses rest from the menu then call this function
   
   //this function will increment the date by 2 weeks, milesTraveled by (70-140) and food values after a continue turn
   int continueTrail(int input1); //if player chooses continue from the menu then call this function
   
   int hunt(int players, int input1, int rabbit, int fox, int deer, int bear, int moose);
   //add 1 to current day 
   //use proablility function to decide which animal is encountered 
   //they could encounter more than 1 animal on the trip or none...
   // srand(time(0));
   //int r = rand()%100; //values between 0 and 99
   //cout what animal they encountered and ask them if they want to hunt it
   //call animal class!
   //food is returned
   //ask them how well they want to eat (within if they want to hunt)
   //update the food
   //if the total food still exceeds 1000 lbs then set food to 1000 else just set to amount off there
   //print message explaining they had to leave the rest of the food behind
   
   //print out a mesage expressing regret of the party that had to cut their trip short
   void quit();
   
   void setcurrentDay(int day); //this funciton will update the current day or initalize it to a different value if the player decides they want to start at a different day
   
   int getcurrentDay(); //gets currentDay
   
   void setcurrentMonthOriginal(int month);
   
   int getcurrentMonthOriginal();
   
   void setcurrentDayOriginal(int day);
   
   int getcurrentDayOriginal();
   
   void setcurrentMonth(int day); //this funciton will update the current month or initalize it to a different value if the player decides they want to start at a different month
   
   int getcurrentMonth(); //getscurrentMonth
   
   int getcurrentYear();

private: //all of the variables are declared in private

   int currentDay;
   int currentMonth;
   const int CURRENTYEAR = 1847;
};

#endif
