#ifndef USER_H
#define USER_H
#include <string>
#include <iostream>
using namespace std;

class User
{
public:
   User(); // sets title and author to empty strings

   User(string u, int array[], int a); //User constructor with parameters
   
   string getUsername();
   
   void setUsername(string);
   
   int getRatingAt(int); //h file for all of the functions
   
   bool setRatingAt(int, int);
   
   int getNumRatings();
   
   void setNumRatings(int);
   
   int getSize();
   
private: //all of the variables are declared in private
   string username; 
   const int SIZE = 200; //constant SIZE is set to 200
   int ratings[200];
   int numRatings;
};

#endif
