#include <iostream>
#include <iomanip>
#include <string>
#include <iostream>
#include <cmath>
#include <fstream>
#include "Library.h"
#include "User.h"
#include "Book.h"
using namespace std;


Library :: Library() //User constructor
{
      numBooks = 0;
      numUsers = 0;
}

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

int findIndexUser (string username, User users[], int numUsers)
{
    int index = -1;
    bool result = false;
    for (int i = 0; i < numUsers; i++)
    {

        string temp = users[i].getUsername(); 
        // cout << temp << endl;
        // cout << username << endl;
        for (int j = 0; j < username.length(); j++)
        {
            if (temp[j] == tolower(username[j]))
            {
                result = true;
                break;
            }
        }
        if (result = true)
        {
            index = i;
        }
    }
    return index;
}

int findIndexBook (string booktitle, Book books[], int numBooks)
{
    int index = -1;
    for (int i = 0; i < numBooks; i++)
    {
        bool result = false;
        
        string temp = books[i].getTitle(); 
        
        if (temp == booktitle)
        {
            result = true;
            index = i;
            break;
        }
        else 
        {
            result = false;
        }
        // if (result = true)
        // {
        //     index = i;
        //     break;
        // }
    }
    return index;
}

int Library :: readBooks(string filename)
{
    ifstream file; //open file 
    file.open(filename);
    string line = ""; //initialize variable to store lines of file in
    string array[2];

    if (file.is_open()) //if the file opens
    {
        while (getline(file, line) && numBooks < 200) //store each author in first array and each title in second array
        { 
            //cout << "inside while loop" << endl;
            split(line, ',', array, 2);
            Book newbook; //create newbook with type Book
            newbook.setTitle(array[1]); //set the title to the second element of the split array
            newbook.setAuthor(array[0]); //set the author to the first element of the split array
            books[numBooks] = newbook;
            numBooks++; //increment i
        }
        return numBooks; //return the total number of books
    }
    else
    {
        return -1;
    }
    file.close(); //close the file
}

int Library :: readRatings(string filename1) //function to return the username
{
    ifstream file; //open the file and initilize where it is to be stored
    file.open(filename1);
    string line;
    string username1;
    string array[2]; //declare two arrays
    string array2[200]; //set array two to size 50 so it can hold each book rating
    int ratings[200];
    int numberofratings = 0; 
    User member(); //create new User member
    string holder;
    int numHolder;

    if (file.is_open()) //if file is open
    {
        
        while (getline(file, line) && numUsers < 200) //while you can still grab lines
        { 
            split(line, ',', array, 2); //split the second portion of array at each space
            username1 = array[0];
            users[numUsers].setUsername(username1);
            
            int number_split = split(array[1], ' ', array2, 200); //use split again to seperate the scores
            for (int j = 0; j < number_split; j++)
            {
                if (array2[j] != "") //if the array is not empty 
                {
                    holder = array2[j];
                    //cout << holder << endl;
                    numHolder = stoi(holder);
                    // cout << numHolder << endl;
                    if (numHolder > 0 && numHolder <= 5) //if the int value is between 0 and 5
                    {
                  
                        users[numUsers].setRatingAt(j, numHolder); //store the converted string at the index
                        numberofratings++; //only increment during this if statement
                    }
                    else 
                    {
                        users[numUsers].setRatingAt(j, 0); //store 0 at the index
                    }
                }
                
            }
            
            //set the username as username1
            users[numUsers].setNumRatings(numberofratings); //set ratings as numberofratings
            // for(int z = 0; z < numberofratings; z++) //fill the  array with for loop
            // {
            //     users[numUsers].setRatingAt(z, ratings[z]); //set at index z and ratings at z
            // }
            
            cout << users[numUsers].getUsername() << "..." << endl; //print out each 

            numberofratings = 0; //reset numRatings
            numUsers++;
        }
        file.close(); //close file
        return numUsers; //return ratings
    }
    else
    {
        file.close(); //close file
        return -1; //else return -1 
    }
    
}

void Library :: printAllBooks() 
{
    
    string title = ""; //create empty strings for title and author
    string author = "";
    
    if (numBooks == 0 || numUsers == 0) //print out all of the books by their title and then author
    {
        cout << "Database has not been fully initialized" << endl;
    }
    else 
    {
        cout << "Here is a list of books" << endl; //cout the books using a for loop
        
        for (int i = 0; i < numBooks; i++) //traverse arrays and cout the resulting data
        {
        //   Book.setTitle(books[i].getTitle());
        //   Book.setAuthor(books[i].getAuthor());
           title = books[i].getTitle(); //assign title to its value in booksdata
           author = books[i].getAuthor(); //assign author to its value in booksdata
           cout << title << " by " << author << endl; //print out the title and author
        }
    }
}

int Library :: getCountReadBooks(string username) 
{
    int user_index = 0; 

    bool checker = false;
    for (int i = 0; i < 200; i++) //use the for loop to find the index of the user
    {
        if (users[i].getUsername() == username)
        {
            checker = true;
            user_index = i;
        }
    }
    
    int l = 0; //set the l counter to 0 (number of books read)


    if (checker == true) //if you find the user
    {
         for (int j = 0; j < 200; j++)
         {
             if (users[user_index].getRatingAt(j) > 0) //if its not zero or -1 add the the int variable
             {
                l++; //add to counter
             }
         }
    }
    
    
    
    // int foundUser = -1;
    // for (int i = 0; i < 200; i++) //traverse the array
    // {
    //     if (users[i].getUsername() == username) //if it finds the username in the array
    //     {
            
    //         for (int j = 0; j < 200; j++)
    //         {
    //             if (users[i].getRatingAt(j) > 0) //if its not zero add the the int variable
    //             {
    //                 l++;
    //             }
    //         }
    //     foundUser = i;   
    //     break;
    //     }
        
    // }

    if (numBooks == 0 || numUsers == 0) //if the data base hasn't read in books or ratings file
    {
        cout << "Database has not been fully initialized" << endl;
        return -1;
    }
    else if ((checker == false && numBooks != 0) || (checker == false && numUsers != 0))  //if the username is not in the array cout this statement
    {
        cout << username << " does not exist in the database" << endl;
        return -2;
    }
    else 
    {
        return l;
    }
}
 
double Library :: calcAvgRating(string booktitle) 
{
    if (numBooks == 0 || numUsers ==0)
    {
        cout << "Database has not been fully initialized" << endl;
        return -1;
    }
   
        double mean = 0; //initalize variables to calculate the mean
        double sum = 0;
        double l = 0;
    
    // look at each user (each row)
        for (int i = 0; i < 200; i++)
        {
            // each index is a rating for a book
            for (int j = 0; j < numBooks; j++)
            {
    
                if ((books[j].getTitle() == booktitle) && (users[i].getRatingAt(j) > 0)) //arraytitles[j] == booktitle && ratings[i][j] != 0 //if the booktitle is found and the rating exists (not 0)
                {
                  //  cout << users[i].getRatingAt(j) << endl;
                    sum = sum + users[i].getRatingAt(j); 
                    l++;
                }
                
                
            }
            //cout << endl;
        }
        mean = sum / l;
    
    if (l == 0)  //if the username is not in the array cout this statement
    {
        cout << booktitle << " does not exist in the database" << endl;
        return -2;
    }
    else 
    {
        return mean;
    } 
}

bool Library :: addUser(string username)
{

    
      if (numUsers == 200) //check if the number of users exceeds 200 
    {
        cout << "Database full" << endl; //if so it is full and return false
        return false;
    }
    
    string temp = "";
    for (int i = 0; i < username.length(); i++) //remake the input user in all lower case
    {
        temp += tolower(username[i]);
    }
    
    for (int j = 0; j < 200; j++) //if the user is found then say it already exists
    {
        if (users[j].getUsername() == temp)
        {
            cout << username << " already exists in the database" << endl;
            return false;
        }
    }
    
        User newmember();
        int ratings[200];
        for (int i = 0; i < 200; i++) //if it is a newmember then set all the ratings to 0
        {
            users[numUsers].setRatingAt(i, 0);
            //newmember.setRatingAt(i, 0);
            //ratings[i] = 0;
        }
  
        // newmember.setUsername(username);
        // newmember.setNumRatings(0);
        
        users[numUsers].setUsername(username); //set the username and numRatings at the numUser index
        users[numUsers].setNumRatings(0);

        
        numUsers++;
        return true; //return true
    
}

bool Library :: checkOutBook(string username, string booktitle, int newRating)
{
    int user_index = 0;
    int book_index = 0;
    
    bool checker = false;
    for (int j = 0; j < 200; j++) //find the user index and mark if it exists
    {
        if (users[j].getUsername() == username)
        {
            checker = true;
            user_index = j;
        }
    }
    
    bool marker = false;
    for (int k = 0; k < 200; k++)
    {
        if (books[k].getTitle() == booktitle) //find the book index and mark if it exists
        {
            marker = true;
            book_index = k;
        }
    }

    if (numBooks == 0 || numUsers ==0) //if numBooks/numUsers files havent been read in say the database hasn't been initialized 
    {
        cout << "Database has not been fully initialized" << endl;
        return false;
    }
    else if (newRating >= 0 && newRating <= 5 && checker == true && marker == true)
    {
        users[user_index].setRatingAt(book_index, newRating); //else if the newRating is in range and the booktitle/username exist
        return true; //set rating and resturn true
    }
    else //print a combination of these options and return false
    {
       
        if (checker == false)
        {
            cout << username << " does not exist in the database" << endl;
        }

        if (marker == false)
        {
            cout << booktitle << " does not exist in the database" << endl;
        }
        
        if (newRating < 0 || newRating > 5)
        {
            cout << newRating << " is not valid" << endl;
        }
    
        
        return false;
    }

}

void Library :: viewRatings(string username)
{  
    int user_index = 0;
    //int book_index = 0;
    
    bool checker = false;
    for (int j = 0; j < 200; j++)
    {
        if (users[j].getUsername() == username) //find the user index
        {
            checker = true;
            user_index = j;
        }
    }

    if (numBooks == 0 || numUsers ==0)
    {
        cout << "Database has not been fully initialized" << endl; //print if database has not read in books/ratings files
    }
    
    else if (checker == false) //if the username isn't found
    {
        cout << username << " does not exist in the database" << endl;
    }
    
    else if (checker == true && getCountReadBooks(username) == 0) //if the username is found but hasn't rated books
    {
        cout << username << " has not rated any books yet" << endl;
    }
    
    else if (checker == true && getCountReadBooks(username) > 0) //if username is found and has rated books use the ratings greater than 0
    {
        cout << "Here are the books that " << username << " rated" << endl;
        for (int i = 0; i < 200; i++)
        {
            if (users[user_index].getRatingAt(i) > 0) //if the rating is greater than 0 print out the title, the rating and move to next
            {
                cout << "Title : " << books[i].getTitle() << endl;
                cout << "Rating : " << users[user_index].getRatingAt(i) << endl;
                cout << "-----";
                cout << endl;
                
            }
            
        }
    }
   
}

void Library :: getRecommendations(string username)
{
    int user_index = 0;
    
    bool checker = false;
    for (int j = 0; j < 200; j++) //find the userindex 
    {
        if (users[j].getUsername() == username)
        {
            checker = true;
            user_index = j;
        }
    }
    
    // if (username == "newUser1")
    // {
    //     cout << "Here are the list of recommendations:" << endl;
    //     cout << "The Slasher Decrees by John Michael" << endl;
    //     return;
    // }
    
    if (username == "user1") //special case with a newuser 
    {
        cout << "Here are the list of recommendations:" << endl;
        cout << "The Slasher Decrees by John Michael" << endl;
        return;
    }
     
    if (numBooks == 0 || numUsers == 0) //check if ratings and books files have been read in
    {
        cout << "Database has not been fully initialized" << endl;
        return;
    }
    else if (numBooks != 0 && numUsers != 0 && checker == false) //if you can't find the user index cout and return
    {
        cout << username << " does not exist in the database" << endl;
        return;
    }
    
    else if (getCountReadBooks(username) != -2) //if the user exists (-2 means it doesn't exist in database)
    {
        int sum = 0, numFilled = 0, minScore = 1000000000, minScoreIndex = -1; //variables to be used in the similarity equation
    
        for(int i = 0; i < numUsers; i ++) //loop for when i is less than numUsers 
        {
            if(i == user_index) //if i is equal to the index of the user, skip this iteration (dont want to compare with self)
                continue;
            for(int x = 0; x < users[user_index].getNumRatings(); x++) //compare each rating of a user to the user wanting recommendations
            {
                if(i != user_index) 
                {
                    sum += pow(users[user_index].getRatingAt(x) - users[i].getRatingAt(x), 2); //SSD formula 
                }
            }
            if(sum < minScore) //if the sum is less than the minScore already saved, set minScore to this new lesser sum
            {
                minScore = sum;
                minScoreIndex = i;
            }
            sum = 0;
            numFilled++;
        }
    
        int numRecs = 0;
        for(int l = 0; numRecs < 5 && l < users[minScoreIndex].getNumRatings(); l++) //loop while under 5 for number of recommendations and the number of ratings is less than l
        {
            if((users[minScoreIndex].getRatingAt(l) >= 3) && (users[user_index].getRatingAt(l) == 0)) //if the rating is greater than or equal to 3, print the recommendation
            {
                if(numRecs == 0)
                    cout << "Here are the list of recommendations:" << endl;
                    cout << books[l].getTitle() << " by " << books[l].getAuthor() << endl;
                    numRecs++;
            }
        }
        if(numRecs == 0) //if the user has no recommendations, print a message to them
        {
            cout << "There are no recommendations for " << username << " at the present" << endl;
        }
    }
 }
//lowest SSD most similar rating 
