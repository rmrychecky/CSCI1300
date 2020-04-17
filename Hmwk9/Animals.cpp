#include <iostream>
#include <iomanip>
#include <string>
#include <iostream>
#include <cmath>
#include <fstream>
#include <time.h>
#include "Animals.h" 
#include "Store.h"
// #include "Turns.h"
using namespace std;

int randomNumbers(int min, int max){
    // rand() % (max-min+1) + min
    return (rand() % (max-min+1)) + min;
}

Animals :: Animals() //create Animals constructor to initalize private variables 
{
   food = 0; //set food to 0;

}

void Animals :: setFood(int pounds)
{
   food = food + pounds;
}

int Animals :: getFood()
{
   return food;
}

int Animals :: getRabbit(int minFood, int maxFood, int numBullets) 
{
   int puzzleValue = 0;
   string puzzleGuess;
   int numberOfGuesses = 0;

   if (numBullets <= 10)
   {
      food = -1;
   }
   else if (numBullets > 10)
   {
      puzzleValue = randomNumbers(1, 10);
      
      while (numberOfGuesses < 3)
      {
         cout << "Guess a number between 1 and 10" << endl;
         getline(cin, puzzleGuess);
         while (puzzleGuess != "1" && puzzleGuess != "2" && puzzleGuess != "3" && puzzleGuess != "4" && puzzleGuess != "5" && puzzleGuess != "6" && puzzleGuess != "7" && puzzleGuess != "8" && puzzleGuess != "9" && puzzleGuess != "10")
         {
            cout << "Invalid input, please enter a number between 1 and 10." << endl;
            getline(cin, puzzleGuess);
         }
         if (stoi(puzzleGuess) == puzzleValue)
         {
            food = maxFood;
         }
         numberOfGuesses++;
      }
   }
   return food;
   
}

int Animals :: getFox(int minFood, int maxFood, int numBullets) 
{
   int puzzleValue = 0;
   string puzzleGuess;
   int numberOfGuesses = 0;
   
   if (numBullets <= 10)
   {
      food = -1;
   }
   else if (numBullets > 10)
   {
      puzzleValue = randomNumbers(1, 10);
      
      while (numberOfGuesses < 3)
      {
         cout << "Guess a number between 1 and 10" << endl;
         getline(cin, puzzleGuess);
         while (puzzleGuess != "1" && puzzleGuess != "2" && puzzleGuess != "3" && puzzleGuess != "4" && puzzleGuess != "5" && puzzleGuess != "6" && puzzleGuess != "7" && puzzleGuess != "8" && puzzleGuess != "9" && puzzleGuess != "10")
         {
            cout << "Invalid input, please enter a number between 1 and 10." << endl;
            getline(cin, puzzleGuess);
         }
         if (stoi(puzzleGuess) == puzzleValue)
         {
            food = maxFood;
         }
         numberOfGuesses++;
      }
   }
   return food;
   
}

int Animals :: getDeer(int minFood, int maxFood, int numBullets) 
{
   int puzzleValue = 0;
   string puzzleGuess;
   int numberOfGuesses = 0;
   
   if (numBullets <= 10)
   {
      food = -1;
   }
   else if (numBullets > 10)
   {
      puzzleValue = randomNumbers(1, 10);
      
      while (numberOfGuesses < 3)
      {
         cout << "Guess a number between 1 and 10" << endl;
         getline(cin, puzzleGuess);
         while (puzzleGuess != "1" && puzzleGuess != "2" && puzzleGuess != "3" && puzzleGuess != "4" && puzzleGuess != "5" && puzzleGuess != "6" && puzzleGuess != "7" && puzzleGuess != "8" && puzzleGuess != "9" && puzzleGuess != "10")
         {
            cout << "Invalid input, please enter a number between 1 and 10." << endl;
            getline(cin, puzzleGuess);
         }
         if (stoi(puzzleGuess) == puzzleValue)
         {
            food = randomNumbers(minFood, maxFood);
         }
         numberOfGuesses++;
      }
   }
   return food;
}

int Animals :: getBear(int minFood, int maxFood, int numBullets) 
{
   int puzzleValue = 0;
   string puzzleGuess;
   int numberOfGuesses = 0;
   
   if (numBullets <= 10)
   {
      food = -1;
   }
   else if (numBullets > 10)
   {
      puzzleValue = randomNumbers(1, 10);
      
      while (numberOfGuesses < 3)
      {
         cout << "Guess a number between 1 and 10" << endl;
         getline(cin, puzzleGuess);
         while (puzzleGuess != "1" && puzzleGuess != "2" && puzzleGuess != "3" && puzzleGuess != "4" && puzzleGuess != "5" && puzzleGuess != "6" && puzzleGuess != "7" && puzzleGuess != "8" && puzzleGuess != "9" && puzzleGuess != "10")
         {
            cout << "Invalid input, please enter a number between 1 and 10." << endl;
            getline(cin, puzzleGuess);
         }
         if (stoi(puzzleGuess) == puzzleValue)
         {
            food = randomNumbers(minFood, maxFood);
         }
         numberOfGuesses++;
      }
   }
   return food;
  
}

int Animals :: getMoose(int minFood, int maxFood, int numBullets) 
{
   
   int puzzleValue = 0;
   string puzzleGuess;
   int numberOfGuesses = 0;
   Store object;
   
   if (numBullets <= 10) //if you dont ahve enough bullet you dont get food
   {
      food = -1;
   }
   else if (numBullets > 10) //if you ahve enough you can hunt and a random amount of food will be returned 
   {
      puzzleValue = randomNumbers(1, 10);
      
      while (numberOfGuesses < 3)
      {
         cout << "Guess a number between 1 and 10" << endl; 
         getline(cin, puzzleGuess);
         while (puzzleGuess != "1" && puzzleGuess != "2" && puzzleGuess != "3" && puzzleGuess != "4" && puzzleGuess != "5" && puzzleGuess != "6" && puzzleGuess != "7" && puzzleGuess != "8" && puzzleGuess != "9" && puzzleGuess != "10") //make sure input is valid
         {
            cout << "Invalid input, please enter a number between 1 and 10." << endl;
            getline(cin, puzzleGuess);
         }
         if (stoi(puzzleGuess) == puzzleValue) //if your guess equals the random value then your food is set
         {
            food = randomNumbers(minFood, maxFood);
         }
         numberOfGuesses++; //increment numberOfGuesses 
      }
   }
   return food;
   
}

  