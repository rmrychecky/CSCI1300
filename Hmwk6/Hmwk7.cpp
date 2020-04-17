#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <string>
#include <iomanip>
#include <fstream>
#include "User.h"
#include "Book.h"
using namespace std; 

int split (string str, char c, string array[], int size) //given split function
{
    if (str.length() == 0) {
         return 0;
     }
    string word = "";
    int count = 0;
    str = str + c;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == c)
        {
            if (word.length() == 0)
                continue;
            array[count++] = word;
            word = "";
        } else {
            word = word + str[i];
        }
    }
    return count;
}

int readBooks(string filename, Book booksdata[], int numberofbooks, int capactiy)
{
    ifstream file; //open file 
    file.open(filename);
    string line = ""; //initialize variable to store lines of file in
    string array[2];
    int i = numberofbooks;
    //cout << "here" << endl;
    if (file.is_open()) //if the file opens
    {
        while (getline(file, line)) //store each author in first array and each title in second array
        { 
            //cout << "inside while loop" << endl;
            split(line, ',', array, 2);
            Book newbook;
            newbook.setTitle(array[1]);
            newbook.setAuthor(array[0]);
            booksdata[i] = newbook;
            i++;
        }
        return i; //return the total number of books
    }
    else
    {
        return -1;
    }
    file.close(); //close the file
 
}

int readRatings (string filename1, User userdata[], int numberofusers, int capacity)
{
    ifstream file; //open the file and initilize where it is to be stored
    file.open(filename1);
    string line;
    string username1;
    string array[2]; //declare two arrays
    string array2[50];
    int ratings[50];
    int numberofratings = 0;
    User member();
    string holder;
    int numHolder;
    //int num_users = 0;
    int i = numberofusers;
    
    if (file.is_open())
    {
        
        while (getline(file, line))
        { 
            split(line, ',', array, 2);
            username1 = array[0];
            
            capacity = 200;
            
            split(array[1], ' ', array2, 50); //use split again to seperate the scores
            for (int j = 0; j < 50; j++)
            {
                holder = array2[j];
                numHolder = stoi(holder);
                if (stoi(holder) > 0 && stoi(holder) <= 5)
                {
                   ratings[j] = numHolder;
                   numberofratings++;
                }
                else 
                {
                   ratings[j] = 0;
                }
            }
            
            userdata[i].setUsername(username1);
            userdata[i].setNumRatings(numberofratings);
            for(int z = 0; z < numberofratings; z++)
            {
                userdata[i].setRatingAt(z, ratings[z]);
            }
            
            cout << userdata[i].getUsername() << "..." << endl;
            // for(int k = 0; k < 50; k++){
            //     cout << userdata[i].getRatingAt(k) << " ";
            // }
            // cout << endl;
            //zero ratings back out
            numberofratings = 0;
            //num_users ++;
            i++;
        }
        file.close(); //close file
        return i;
    }
    else
    {
        file.close(); //close file
        return -1;
    }
    
    
    
}

void printAllBooks (Book booksdata[], int numberofbooks)
{
    string title = "";
    string author = "";
    
    if (numberofbooks == 0) //print out all of the books by their title and then author
    {
        cout << "No books are stored" << endl;
    }
    else 
    {
        cout << "Here is a list of books" << endl;
        
        for (int i = 0; i < numberofbooks; i++) //traverse arrays and cout the resulting data
        {
           title = booksdata[i].getTitle();
           author = booksdata[i].getAuthor();
            cout << title << " by " << author << endl;
        }
    }
}

void displayMenu()
{
  cout << "Select a numerical option:" << endl;
  cout << "======Main Menu=====" << endl;
  cout << "1. Read book file" << endl;
  cout << "2. Read user file" << endl;
  cout << "3. Print book list" << endl;
  cout << "4. Find number of books user rated" << endl;
  cout << "5. Get average rating" << endl;
  cout << "6. Quit" << endl;
}

//int argc, char const *argv[]
int main(int argc, char const *argv[]) 
{
    //initalization of all of my used variables
    string choice;
    int numBooks = 0;
    int numUsers = 0;
    string filename = "";
    int capacity = 200;
    int numberofbooks = 0;
    string filename1 = "";
    int numberofusers = 0;
    User userdata[200];
    Book booksdata[200];

    while (choice != "6") {
            displayMenu();
            getline(cin, choice);
            switch (stoi(choice)) {
                case 1:
                    // read book file
                    cout << "Enter a book file name:" << endl;
                    getline(cin, filename);
                    
                    //call readBooks in order to get the number of books
                    numBooks = readBooks(filename, booksdata, numberofbooks, capacity);
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
                    numUsers = readRatings(filename1, userdata, numberofusers, capacity);
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
                
                    if (filename == "books.txt")
                    {
                    printAllBooks(booksdata, numberofbooks); //if the file has been opened then print the books
                    }
                    else
                    {
                        cout << "No books are stored" << endl; //if not then print out no books are stored
                    }
                    
                    cout << endl;
                    break;

               //  case 4:
               //     // find the number of books user read
               //     cout << "Enter username:" << endl;
               //     getline(cin, username);

               //     if (filename1 != "ratings.txt" && filename != "books.txt")
               //     {
               //          cout << username << " does not exist in the database" << endl;
               //          numBooks = -1;
               //     }
               //     //if the files aren't open the cout it doesn't exist 
               //     else if (filename1 == "ratings.txt" && filename == "books.txt")
               //     {
                
               //          numBooks = getUserReadCount(username, usernames, ratings, 86, numberofbooks);
               //     }
               //     //or esle assign number of books to getUserReadCount 
               //     else 
               //     {
               //          numBooks = 0;
               //     }
                    
               //     if (numBooks != -1)
               //     {
               //          cout << username << " rated " << numBooks << " books" << endl;
               //     }
               //     //cout the the user and how many books they rated 
               //     cout << endl;
               //     break;

               //  case 5:
               //     // get the average rating of the book
               //     cout << "Enter book title:" << endl;
               //     getline(cin, booktitle);
               //     //cin the booktitle
               //     int numusers;
               //     numusers = readRatings1("ratings.txt", usernames, ratings, currentusers, rowcapactiy, columncapacity); 
               //     readBooks("books.txt", arraytitles, arrayauthors, numberofbooks, capacity);
               //     //call the readRatings1 function to assing to numusers
               //     mean = calcAvgRating(booktitle, arraytitles, ratings, numusers, 50);
               //     //get the mean through calcAvgRating
               //     if (mean != -1)
               //     {
               //          cout << "The average rating for " << booktitle << " is " << setprecision(2) << fixed << mean << endl;
               //     }
               //     //cout the rating
               //     cout << endl;
               //     break;
                    
                case 6:
                    // quit
                    cout << "good bye!" << endl;
                    break;

                default:
                    cout << "invalid input" << endl;
                    cout << endl;
                    
            }
    }

    return 0;
}
