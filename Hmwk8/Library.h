#ifndef LIBRARY_H
#define LIBRARY_H
#include <string>
#include <iostream>
#include "User.h"
#include "Book.h"
using namespace std;

class Library
{
public:
   Library(); // sets numBooks and numUsers to 0
   
   int readBooks(string);
   
   int readRatings(string); //set all the functions and their input/return values
   
   void printAllBooks();
   
   int getCountReadBooks(string);
   
   double calcAvgRating(string);
   
   bool addUser(string);
   
   bool checkOutBook(string, string, int);
   
   void viewRatings(string);
   
   void getRecommendations(string);
   
private: //all of the variables are declared in private

   const int SIZEBOOK = 200; //botht the size of the book and user arrays are 200
   const int SIZEUSER = 200;
   Book books[200]; //both arrays are set to size 200 to make room for new users and multiple book rating files
   User users[200];
   int numBooks;
   int numUsers;
};

#endif
