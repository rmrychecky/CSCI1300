#include <iostream>
#include <iomanip>
#include <string>
#include <iostream>
#include <cmath>
#include <fstream>
#include "Animals.h" 
#include "Milestones.h"
#include "Store.h"
#include "Turns.h"
#include <time.h>

using namespace std;

Store :: Store() //create Store constructor with empty strings as set variables
{
   money = 1200;
   totalFood = 0;
   totalBullets = 0;
   totalOxen = 0;
   totalWagonParts = 0;
   totalMedicalKits = 0;
   
   for(int i = 0; i < 5; i++)
   {
      totals[i] = 0;
   }
   
}


void Store :: setBill(int numberOxen, int poundsFood, int numberBullets, int numberParts, int numberKits, double inflation)
{
   string answer;
   
   while ((numberOxen/2)*40*inflation > money)
   {
      cout << "You do not have enough money, choose another quantity." << endl;
      getline(cin, answer);
      while (answer != "0" && answer != "1" && answer != "2" && answer != "3" && answer != "4" && answer != "5" && answer != "6" && answer != "7" && answer != "8" && answer != "9" && answer != "10") //make sure the input is valid
      {
         cout << "Invalid input. Please enter the number of oxen you wish to purchase in digit form. This number must only be between 1 and 10." << endl;
         getline(cin, answer);
      }
      numberOxen = stoi(answer); //turn answer into variable
   }
   if ((numberOxen/2)*40*inflation <= money) //if its less then money then you can update values 
   {
      money = money - (numberOxen/2)*40*inflation;
      totalOxen = totalOxen + numberOxen;
      totals[0] = (numberOxen/2)*40*inflation;
   }
   
   while (poundsFood*.5*inflation > money)
   {
      cout << "You do not have enough money, choose another quantity." << endl;
      getline(cin, answer);
      while (!(stoi(answer) >= 0 && stoi(answer) <= 400)) //make sure the input is valid
      {
         cout << "Invalid input. Please enter how many pounds of food you wish to purchase in digit form. This number must only be between 0 and 400." << endl;
         getline(cin, answer);
      }
      poundsFood = stoi(answer); //turn answer into variable
   }
   if (poundsFood*.5*inflation <= money) //if its less then money then you can update values 
   {
      money = money - poundsFood*.5*inflation;
      totalFood = totalFood + poundsFood;
      totals[1] = poundsFood*.5*inflation;
   }
   
   while ((numberBullets/20)*2*inflation > money)
   {
      cout << "You do not have enough money, choose another quantity." << endl;
      getline(cin, answer);
      while (!(stoi(answer) >= 0 && stoi(answer) <= 100)) //make sure the input is valid
      {
         cout << "Invalid input. Please enter how many bullets you wish to purchase in digit form. This number must only be between 0 and 100." << endl;
         getline(cin, answer);
      }
      numberBullets = stoi(answer); //turn answer into variable
   }
   if ((numberBullets/20)*2*inflation <= money) //if its less then money then you can update values 
   {
      money = money - (numberBullets/20)*2*inflation;
      totalBullets =  totalBullets + numberBullets;
      totals[2] = (numberBullets/20)*2*inflation;
   }
   
   while (numberParts*20*inflation > money)
   {
      cout << "You do not have enough money, choose another quantity." << endl;
      getline(cin, answer);
      while (!(stoi(answer) >= 0 && stoi(answer) <= 10)) //make sure the input is valid
      {
         cout << "Invalid input. Please enter how many wagon parts you wish to purchase in digit form. This number must only be between 0 and 10." << endl;
         getline(cin, answer);
      }
      numberParts = stoi(answer); //turn answer into variable
   }
   if (numberParts*20*inflation <= money) //if its less then money then you can update values 
   {
      money = money - numberParts*20*inflation;
      totalWagonParts =  totalWagonParts + numberParts;
      totals[3] = numberParts*20*inflation;
   }
   
   while (numberKits*25*inflation > money)
   {
      cout << "You do not have enough money, choose another quantity." << endl;
      getline(cin, answer);
      while (!(stoi(answer) >= 0 && stoi(answer) <= 10)) //make sure the input is valid
      {
         cout << "Invalid input. Please enter how many medical aid kits wish to purchase in digit form. This number must only be between 0 and 10." << endl;
         getline(cin, answer);
      }
      numberKits = stoi(answer); //turn answer into variable
   }
   if (numberKits*25*inflation <= money) //if its less then money then you can update values 
   {
      money = money - numberKits*25*inflation;
      totalMedicalKits =  totalMedicalKits + numberKits;
      totals[4] = numberKits*25*inflation;
   }
}

void Store :: setBillOriginal(int numberOxen, int poundsFood, int numberBullets, int numberParts, int numberKits, double inflation) //setting original bill to all of the frist values DID NOT USE 
{
   string answer;
   
      money = money - (numberOxen/2)*40*inflation;
      totalOxen = totalOxen + numberOxen;
      totals[0] = (numberOxen/2)*40*inflation;

      money = money - poundsFood*.5*inflation;
      totalFood = totalFood + poundsFood;
      totals[1] = poundsFood*.5*inflation;

      money = money - (numberBullets/20)*2*inflation;
      totalBullets =  totalBullets + numberBullets;
      totals[2] = (numberBullets/20)*2*inflation;

      money = money - numberParts*20*inflation;
      totalWagonParts =  totalWagonParts + numberParts;
      totals[3] = numberParts*20*inflation;

      money = money - numberKits*25*inflation;
      totalMedicalKits =  totalMedicalKits + numberKits;
      totals[4] = numberKits*25*inflation;

}


int Store :: getBill(int index) 
{
   return totals[index];
}

void Store :: settotalFood(int poundsFood)
{ 
   totalFood = totalFood + poundsFood; //total food is previous + inputed value
}

void Store :: settotalFood1(int poundsFood)
{
   totalFood = poundsFood;
}

int Store :: gettotalFood()
{
   return totalFood;
}

void Store :: settotalBullets(int numberBullets)
{
   totalBullets = totalBullets + numberBullets; //total bullets is previous + inputed value
}

void Store :: settotalBullets1(int numberBullets)
{
   totalBullets = numberBullets;
}

int Store :: gettotalBullets()
{
   return totalBullets;
}

void Store :: settotalOxen(int oxes)
{
   totalOxen = totalOxen + oxes; //total oxen is previous + inputed value
}

void Store :: settotalOxen1(int oxes)
{
   totalOxen = oxes;
}

int Store :: gettotalOxen()
{
   return totalOxen;
}

void Store :: settotalWagonParts(int numberParts)
{
   totalWagonParts = totalWagonParts + numberParts; //total wagon parts is previous + inputed value
}

void Store :: settotalWagonParts1(int numberParts)
{
   totalWagonParts = numberParts;
}

int Store :: gettotalWagonParts()
{
   return totalWagonParts;
}

void Store :: settotalMedicalKits(int numberKits)
{
   totalMedicalKits = totalMedicalKits + numberKits; //total medical kits is previous + inputed value
}

int Store :: gettotalMedicalKits()
{
   return totalMedicalKits;
}

void Store :: setMoney(int numberDollars)
{
   money = money + numberDollars;
   if (money < 0) //when money is <=0 it is set to 0
   {
      money = 0;
   }
}

int Store :: getMoney()
{
   return money;
}
   
string Store :: getitemName(int index)
{
   return itemName[index];
}