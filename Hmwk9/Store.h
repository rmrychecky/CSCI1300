#ifndef STORE_H 
#define STORE_H
#include <iostream>
#include <iomanip>
#include <string>
#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

class Store //creating Store class
{
private:
   
   string itemName[5] = {"Oxen", "Food", "Bullets", "Wagon Parts", "Medical Aid Kits"};
   double itemPrice[5] = {40, .5, 2, 20, 25};
   int totals[5];
   int totalFood;
   int totalBullets;
   int totalOxen;
   int totalWagonParts;
   int totalMedicalKits;
   int money;
   
public: 

   Store(); //Store constructors, set all the variables (except the arrays) to 0 except money which = 1200.
   
   // //update the totals for all of the items based on input values from the player (must be done after the bill is computed in order to check if anything goes over the money the player has)
   // Store(int numberOxen, int poundsFood, int numberBullets, int numberParts, int numberKits, int money); 
   // //if total is greater than money after ANY calculation then promt the player to choose again
   
   //use the number of items selected along with the set arrays to fill the totals array
   void setBill(int numberOxen, int poundsFood, int numberBullets, int numberParts, int numberKits, double inflation); 
   
   void setBillOriginal(int numberOxen, int poundsFood, int numberBullets, int numberParts, int numberKits, double inflation);
   
   //get function that returns the Bill at a certain index (for whichever variable is desired)
   int getBill(int index); //print updated bill at each index and corresponding itemName
   
   void settotalFood(int poundsFood); //this function will set the totalFood to the previous value plus negative or postive input amount resulting from a turn or purchase 
   
   void settotalFood1(int poundsFood);
   
   int gettotalFood(); //gets totalFood
   
   void settotalBullets(int numberBullets); //set totalBullets to the previous value plus negative or postive input amount resulting from a turn or purchase 
   
   void settotalBullets1(int numberBullets);
   
   int gettotalBullets(); //gets totalBullets
   
   void settotalOxen(int oxes); //set totalOxen to the previous value plus negative or postive input amount resulting from a turn or purchase 
   
   void settotalOxen1(int oxes);
   
   int gettotalOxen(); //gets totalOxen
   
   void settotalWagonParts(int numberParts); //set totalWagonParts to the previous value plus negative or postive input amount resulting from a turn or purchase 
   
   void settotalWagonParts1(int numberParts);
   
   int gettotalWagonParts(); //gets totalWagonParts
   
   void settotalMedicalKits(int numberKits); //sets totalMedicalKits to the previous value plus negative or postive input amount resulting from a turn or purchase 
   
   int gettotalMedicalKits(); //gets totalMedicalKits
   
   void setMoney(int numberDollars); //sets money to the previous value plus negative or postive input amount resulting from a turn or purchase 
   
   int getMoney(); //gets the value of money
   
   string getitemName(int index);
   
};

#endif
