#include <iostream>
#include <iomanip>
#include <string>
#include <iostream>
#include "User.h"
using namespace std;


User :: User() //User constructor
{
      username = ""; //set numRatings to 0 and username to an empty string
      numRatings = 0; 
      for (int i = 0; i < SIZE; i++) //fill all of ratings array with -1 
      {
         ratings[i] = -1;
      } 
}

User :: User(string u, int array[], int a) //User consturctor with parameters to redefine variables
{
   username = u;
   numRatings = a;
   ratings[SIZE];
   for (int j = 0; j < numRatings; j++)
   {
      ratings[j] = array[j]; //must use for loop to traverse and fill the array
   }
}

string User :: getUsername() //function to return the username
{
   return username;
}

void User :: setUsername(string inputT) //assigns username to input string
{
   username = inputT;
}

int User :: getRatingAt(int index) //returns the rating at an int index
{
   if (index >= 200) //if the index is greater than 50 function should return -1 
   {
      return -1;
   }
   else 
   {
      return ratings[index];
   }
}

bool User :: setRatingAt(int index, int value) //set ratings at a specific index and value
{
   if (index >= 0 && index <= 200 && value >= 0 && value <= 5) //make sure the index is within capacity and ratings values * index is now 200
   {
      ratings[index] = value; 
      return true; //return true or false based on index and value intervals
   }
   else 
   {
      return false;
   }
}

int User :: getNumRatings() //function returns the number of ratings
{
   return numRatings;
}

void User :: setNumRatings(int input1) //sets the number of ratings to the integer input
{
   numRatings = input1;
}

int User :: getSize() //returns the constant size
{
   return SIZE;
}

