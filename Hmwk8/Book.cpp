#include <iostream>
#include <iomanip>
#include <string>
#include "Book.h"
using namespace std;

Book :: Book() //create Book constructor with empty strings as set variables
{
   title = "";
   author = "";
}

Book :: Book(string t, string a) //reasign string values
{
   title = t;
   author = a;
}

string Book :: getTitle() //function to return title
{
   return title;
}

void Book :: setTitle(string inputT) //set title to string input
{
   title = inputT;
}

string Book :: getAuthor() //funciton to return author
{
   return author;
}

void Book :: setAuthor(string inputA) //set author to string input
{
   author = inputA; 
}

