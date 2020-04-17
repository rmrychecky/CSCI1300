#ifndef BOOK_H 
#define BOOK_H
#include <string>
#include <iostream>
using namespace std;

class Book //creating book class
{
private:
   string title; //initalizing title and author to empty strings 
   string author;
   
public: //set each function with their perspective input types

   Book(); //Book constructors
   
   Book(string, string); 

   string getTitle(); // return title as a string
   
   void setTitle(string);
   
   string getAuthor(); //return author as a string
   
   void setAuthor(string);
   
};

#endif
