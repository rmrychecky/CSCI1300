// CSCI1300 Fall 2018
// Author: Raegan Rychecky
// Recitation: Tillquist (Tuesday 8am)
// Cloud9 Workspace Editor Link: <https://ide.c9.io/ .....>
// hmwk6 


#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;


/* split function
 * the function to split the given string into array of string with respect to a delimiter
 *
 * @param : string , the string we are going to split
 * @param : char, the delimiter
 * @param : string array, the array of string we save after spliting
 * @param : int, size of the  indicates the maximum number of split-apart string pieces
*/
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
    return count ;
 }

/* readBooks function
 * the function reads a book file from the text into book and author arrays
 *
 * @param: string, the name of the file to be read
 * @param: string array, titles
 * @param: string array, authors
 * @param: int, the number of books currently stored in the arrays
 * @param: int, capacity of the authors/titles arrays [assume to be 50]
 * @return: the total number of books in total
 */
int readBooks (string filename, string arraytitles[], string arrayauthors[], int numberofbooks, int capacity) //books.txt 50 50 0 50
{
    ifstream file; //open file 
    file.open(filename);
    string line = ""; //initialize variable to store lines of file in
    string array[2];
    
    if (file.is_open()) //if the file opens
    {
        int i = 0;
        while (getline(file, line)) //store each author in first array and each title in second array
        { 
            split(line, ',', array, 2);
            arrayauthors[i] = array[0];
            arraytitles[i] = array[1];
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

/* readRatings function
 * Read the user ratings from the file and store them
 * into users array and ratings array
 *
 * @param: string, the name of the file to be read
 * @param: string array, usernames
 * @param: 2D int array, list of ratings for each user (first index specifies user)
 * @param: int, the number of users currently stored in the array
 * @param: int, row capacity of the 2D array (convention: array[row][column]) [assume to be 100]
 * @param: int, column capacity of the 2D array [assume to be 50]
 * @return: the number of users in total
 */
   
int readRatings (string filename1, string usernames[], int ratings[][50], int currentusers, int rowcapactiy, int columncapacity)
{
    ifstream file; //open the file and initilize where it is to be stored
    file.open(filename1);
    string line = "";
    string array[2]; //declare two arrays
    string array2[50];
    
    if (file.is_open())
    {
        int i = 0;
        while (getline(file, line))
        { 
            split(line, ',', array, 2); //use split to seperate the name and scores
            
            usernames[i] = array[0];
            split(array[1], ' ', array2, 50); //use split again to seperate the scores
            for (int j = 0; j < 50; j++)
            {
                ratings[i][j] = stoi(array2[j]);
            }
            cout << usernames[i] << "..." << endl;
            i++;
        }
        return i;
    }
    else
    {
        return -1;
    }
    
    file.close(); //close file
    
}

//does the same as readRatings except it does not print out the username and ...
int readRatings1 (string filename1, string usernames[], int ratings[][50], int currentusers, int rowcapactiy, int columncapacity)
{
    ifstream file; 
    file.open(filename1);
    string line = "";
    string array[2];
    string array2[50];
    
    if (file.is_open())
    {
        int i = 0;
        while (getline(file, line))
        { 
            split(line, ',', array, 2);
            
            usernames[i] = array[0];
            split(array[1], ' ', array2, 50);
            for (int j = 0; j < 50; j++)
            {
              
                ratings[i][j] = stoi(array2[j]);
            }
            //cout << usernames[i] << "..." << endl;
            i++;
        }

        return i;
    }
    else
    {
        return -1;
    }
    

    
    file.close();
    
}
 //////////////////////////////////////////////////////////////////////////
 // other helper functions
 //////////////////////////////////////////////////////////////////////////


void printAllBooks (string arraytitles[], string arrayauthors[], int numberofbooks)
{
    if (numberofbooks == 0) //print out all of the books by their title and then author
    {
        cout << "No books are stored" << endl;
    }
    else 
    {
        cout << "Here is a list of books" << endl;
        
        for (int i = 0; i < numberofbooks; i++) //traverse arrays and cout the resulting data
        {
            cout << arraytitles[i] << " by " << arrayauthors[i] << endl;
        }
    }
}

int getUserReadCount (string username, string usernames[], int ratings[][50], int rowcapactiy, int numberofbooks)
{
    int l = 0; 
    for (int i = 0; i < rowcapactiy; i++) //traverse the array
    {
        if (usernames[i] == username) //if it finds the username in the array
        {
            for (int j = 0; j < numberofbooks; j++)
            {
                if (ratings[i][j] != 0) //if its not zero add the the int variable
                {
                    l++;
                }
            }
        }
        
    }
    if (l == 0)  //if the username is not in the array cout this statement
    {
        cout << username << " does not exist in the database" << endl;
        return -1;
    }
    return l; //return the number of books read and reviewed
    
}

double calcAvgRating (string booktitle, string arraytitles[], int ratings[][50], int rowcapactiy, int numberofbooks)
{
    double mean = 0; //initalize variables to calculate the mean
    double sum = 0;
    int l = 0;
    

    // ratings: user-by-rating matrix

    // look at each user (each row)
    for (int i = 0; i < rowcapactiy; i++)
    {
            // each column is a rating for a book
            for (int j = 0; j < numberofbooks; j++)
            {
                if (arraytitles[j] == booktitle && ratings[i][j] != 0) //if the booktitle is found and the rating exists (not 0)
                {
                    //cout << arraytitles[j] << " " << ratings[i][j] << endl;
                    sum = sum + ratings[i][j];
                    //cout << sum << endl;
                    l++;
                }
                
            }
        
    }
    mean = sum / l;
    if (l == 0) //if it is 0 that means no ratings, so it doesn't exist 
    {
        cout << booktitle << " does not exist in our database" << endl;
        return -1;
    }
    else
    {
        return mean;
    }
}

/* displayMenu:
 * displays a menu with options
 * DO NOT MODIFY THIS FUNCTION
 */
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


int main(int argc, char const *argv[]) 
{
    //initalization of all of my used variables
    string choice;
    int numBooks = 0;
    int numUsers = 0;
    int numberofbooks = 50;
    int capacity = 50;
    string arraytitles[capacity];
    string arrayauthors[capacity];
    int currentusers = 0;
    int rowcapactiy = 100;
    int columncapacity = 50;
    string usernames[rowcapactiy];
    int ratings[100][50];
    double mean = 0;
    string filename = "";
    string filename1 = ""; 
    string username = "";
    string booktitle = "";


    while (choice != "6") {
            displayMenu();
            getline(cin, choice);
            switch (stoi(choice)) {
                case 1:
                    // read book file
                    cout << "Enter a book file name:" << endl;
                    getline(cin, filename);
                    
                    //call readBooks in order to get the number of books
                    numBooks = readBooks(filename, arraytitles, arrayauthors, numberofbooks, capacity);
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
                    numUsers = readRatings(filename1, usernames, ratings, currentusers, rowcapactiy, columncapacity);
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
                    printAllBooks(arraytitles, arrayauthors, numberofbooks); //if the file has been opened then print the books
                    }
                    else
                    {
                        cout << "No books are stored" << endl; //if not then print out no books are stored
                    }
                    
                    cout << endl;
                    break;

                case 4:
                    // find the number of books user read
                    cout << "Enter username:" << endl;
                    getline(cin, username);

                    if (filename1 != "ratings.txt" && filename != "books.txt")
                    {
                        cout << username << " does not exist in the database" << endl;
                        numBooks = -1;
                    }
                    //if the files aren't open the cout it doesn't exist 
                    else if (filename1 == "ratings.txt" && filename == "books.txt")
                    {
                
                        numBooks = getUserReadCount(username, usernames, ratings, 86, numberofbooks);
                    }
                    //or esle assign number of books to getUserReadCount 
                    else 
                    {
                        numBooks = 0;
                    }
                    
                    if (numBooks != -1)
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
                    //cin the booktitle
                    int numusers;
                    numusers = readRatings1("ratings.txt", usernames, ratings, currentusers, rowcapactiy, columncapacity); 
                    readBooks("books.txt", arraytitles, arrayauthors, numberofbooks, capacity);
                    //call the readRatings1 function to assing to numusers
                    mean = calcAvgRating(booktitle, arraytitles, ratings, numusers, 50);
                    //get the mean through calcAvgRating
                    if (mean != -1)
                    {
                        cout << "The average rating for " << booktitle << " is " << setprecision(2) << fixed << mean << endl;
                    }
                    //cout the rating
                    cout << endl;
                    break;
                    
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










#include <cctype>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;


/**
   Extracts the country and associated value from an input line.
   @param line a line containing a country name, followed by a number
   @return country
*/
string read_username(string line)
{ 
   string username;
   int i = 0; // Locate the start of the first digit
   while (!isdigit(line[i])) 
   { 
      i++; 
   }
   int j = i - 1; // Locate the end of the preceding word
   while (isspace(line[j])) 
   { 
      j--; 
      
   }
   username = line.substr(0, j + 1); // Extract the country name
   
   return username;
   
   //value = string_to_double(line.substr(i)); // Extract the number value
   // We can't return both country and value. We need to create read_value()
}

/**
   Extracts the country and associated value from an input line.
   @param line a line containing a country name, followed by a number
   @return population or area
*/
double read_value(string line)
{ 
   string country;
   double value;
   int i = 0; // Locate the start of the first digit
   while (!isdigit(line[i])) 
   { 
      i++; 
      
   }
   /*int j = i - 1; // Locate the end of the preceding word
   while (isspace(line[j])) 
   { 
      j--; 
      
   }*/
   //country = line.substr(0, j + 1); // Extract the country name
   
   //return country;
   
   value = string_to_double(line.substr(i)); // Extract the number value
   return value;
}

int main()
{
   ifstream in1;
   ifstream in2;
   in1.open("worldpop.txt"); // Open input files
   in2.open("worldarea.txt");

   ofstream out;
   out.open("world_pop_density.txt"); // Open output file
   out << fixed << setprecision(2);

   string line1;
   string line2;

   // Read lines from each file
   while (getline(in1, line1) && getline(in2, line2))
   {
      string country;
      double population;
      double area;

      // Split the lines into country and associated value
      country = read_country(line1);
      population = read_value(line1);
      area = read_value(line2);

      // Compute and print the population density
      double density = 0;
      if (area != 0) // Protect against division by zero
      {
         density = population * 1.0 / area;
      }
      out << setw(40) << left << country  
         << setw(15) << right << density << endl;      
   }

   return 0;
}
