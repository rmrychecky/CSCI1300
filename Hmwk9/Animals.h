#ifndef ANIMALS_H 
#define ANIMALS_H
#include <iostream>
#include <iomanip>
#include <string>
#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

class Animals //creating book class
{
private:

   int food;
   
public: //set each function with their perspective input types

   Animals(); //set both private variables to 0 
   
   void setFood(int pounds); //set the minFood value to what it should be for the animal that was choosen
   
   int getFood(); // gets the minFood value
   
   int getRabbit(int minFood, int maxFood, int numBullets); //min and max food is 2 lbs and totalbullts = -10 if sucessfull
   //use the random number generator to decide how much food is gained and to solve the puzzels if totalBullets > 10

   int getFox(int minFood, int maxFood, int numBullets);//min and max food is 5 lbs and totalbullts = -8 if sucessfull
   //use the random number generator to decide how much food is gained and to solve the puzzels if totalBullets > 10

   int getDeer(int minFood, int maxFood, int numBullets); //min 30 max 55 lbs and totalbullts = -5 if sucessfull
   //use the random number generator to decide how much food is gained and to solve the puzzels if totalBullets > 10

   int getBear(int minFood, int maxFood, int numBullets); //min 100 max 350 food and totalbullts = -10 if sucessfull
   //use the random number generator to decide how much food is gained and to solve the puzzels if totalBullets > 10

   int getMoose(int minFood, int maxFood, int numBullets); //min 300 max 600 food and totalbullts = -12 if sucessfull
   //use the random number generator to decide how much food is gained and to solve the puzzels if totalBullets > 10

};

#endif
