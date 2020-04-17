// CSCI1300 Fall 2018
// Author: Raegan Rychecky 
// Recitation: Carter Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/rmrychecky/csci1300
// hmwk8 / Project2

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <string>
#include <iomanip>
#include <fstream>
#include "User.h" //include the User, Book, and Library h files
#include "Book.h"
#include "Library.h"
using namespace std; 

/* displayMenu:
 * displays a menu with options
 * DO NOT MODIFY THIS FUNCTION
 */
 void displayMenu(){
     cout << "Select a numerical option:" << endl;
     cout << "======Main Menu=====" << endl;
     cout << "1. Read book file" << endl;
     cout << "2. Read user file" << endl;
     cout << "3. Print book list" << endl;
     cout << "4. Find number of books user rated" << endl;
     cout << "5. Get average rating" << endl;
     cout << "6. Add a User" << endl;
     cout << "7. Checkout a book" << endl;
     cout << "8. View Ratings" << endl;
     cout << "9. Get Recommendations" << endl;
     cout << "10. Quit" << endl;
 }



int main(int argc, char const *argv[])
{
 //initalization of all of my used variables
    string choice;
    Library member;
    int numBooks = 0;
    int numUsers = 0;
    string newRating;
    double mean = 0;
    bool returnValue;
    string filename = "";
    string username = "";
    string booktitle = "";
    int capacity = 200;
    int numberofbooks = 0;
    int numberofusers = 0;
    string filename1 = "";
    User userdata[200];
    Book booksdata[200];

    while (choice != "10") {
            displayMenu();
            getline(cin, choice);
            switch (stoi(choice)) {
                case 1:
                    // read book file
                    cout << "Enter a book file name:" << endl;
                    getline(cin, filename);
                    
                    //call readBooks in order to get the number of books
                    numBooks = member.readBooks(filename);
                    //if the return isn't negative 1 then show then print out the total
                    if (numBooks == -1)
                    {
                        cout << "No books saved to the database" << endl;
                    }
                    else 
                    {
                        cout << "Total books in the database: " << numBooks << endl;
                    }
                    cout << endl;
                    break;

                case 2:
                    // read user file
                    cout << "Enter a rating file name:" << endl;
                    getline(cin, filename1);
                   
                    //assign readRatings to the number of users
                    numUsers = member.readRatings(filename1);
                    //if its -1 then return the statement or else return the number of users
                    if (numUsers == -1)
                    {
                        cout << "No users saved to database" << endl;
                    }
                    else 
                    {
                        cout << "Total users in the database: " << numUsers << endl;
                    }
                    cout << endl;
                    break;

                case 3:
                
                    member.printAllBooks(); //if the file has been opened then print the books
                 
                    cout << endl;
                    break;

                case 4:
                   // find the number of books user read
                   cout << "Enter username:" << endl;
                   getline(cin, username);
                   
                   numBooks = member.getCountReadBooks(username); //pass to get the count of the books read
                    
                   if (numBooks != -1 && numBooks != -2)
                   {
                        cout << username << " rated " << numBooks << " books" << endl;
                   }
                   //cout the the user and how many books they rated 
                   cout << endl;
                   break;

                case 5:
                   // get the average rating of the book
                   cout << "Enter book title:" << endl;
                   getline(cin, booktitle);
                  
                   mean = member.calcAvgRating(booktitle);
                   //get the mean through calcAvgRating
                   if (mean != -1 && mean != -2)
                   {
                        cout << "The average rating for " << booktitle << " is " << setprecision(2) << fixed << mean << endl;
                   }
                   //cout the rating
                   cout << endl;
                   break;
                   
                case 6:
                   
                   cout << "Enter username:" << endl; //ask for the reader to enter a username
                   getline(cin, username);
                   
                   returnValue = member.addUser(username); //check if the user is there
                   if (returnValue == true) //add to library if not
                   {
                       cout << "Welcome to the library " << username << endl;
                   }
                   else 
                   {
                       cout << username << " could not be added in the database" << endl;
                   }
                   cout << endl;
                   break;
                   
                case 7:
                   cout << "Enter username:" << endl;
                   getline(cin, username);
                   
                   cout << "Enter book title:" << endl;
                   getline(cin, booktitle);
                   
                   cout << "Enter rating for the book:" << endl; //cin rating, booktitle and username
                   getline(cin, newRating);
                   
                   returnValue = member.checkOutBook(username, booktitle, stoi(newRating)); //pass to the check out book function
               
                   if (returnValue == true) //update the rating 
                   {
                       cout << "We hope you enjoyed your book. The rating has been updated" << endl;
                   }
                   else //else say they could not check out
                   {
                       cout << username << " could not check out " << booktitle << endl;
                   }
                   cout << endl;
                   break;
                   
                case 8:
                   cout << "Enter username:" << endl;
                   getline(cin, username); //get a username input
                   
                   member.viewRatings(username); //pass to viewRatings in order to see the ratings
               
                   cout << endl;
                   break;
                   
                case 9:
                   cout << "Enter username:" << endl;
                   getline(cin, username); //get a username input
                   
                   member.getRecommendations(username); //pass username to getRecommendations function
               
                   cout << endl;
                   break;  

                case 10:
                    // quit
                    cout << "good bye!" << endl;
                    cout << endl;
                    break;

                default:
                    cout << "invalid input" << endl;
                    cout << endl;
                    
            }
    }

    return 0;
}
