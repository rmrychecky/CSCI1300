
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;



    
int split (string str, char c, string array[], int size)
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
        } 
        else 
        {
            word = word + str[i];
        }
    }
    return count;
 }
 
int readBooks (string filename, string arraytitles[], string arrayauthors[], int numberofbooks, int capacity) //books.txt 50 50 0 50
{
    ifstream file; 
    file.open(filename);
    string line = "";
    string array[2];
    
    if (file.is_open())
    {
        int i = 0;
        while (getline(file, line))
        { 
            split(line, ',', array, 2);
            arrayauthors[i] = array[0];
            arraytitles[i] = array[1];
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
    
    
int readRatings (string filename1, string usernames[], int ratings[][50], int currentusers, int rowcapactiy, int columncapacity)
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
            cout << usernames[i] << "..." << endl;
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

void printAllBooks (string arraytitles[], string arrayauthors[], int numberofbooks)
{
    if (numberofbooks == 0)
    {
        cout << "No books are stored" << endl;
    }
    else 
    {
        cout << "Here is a list of books" << endl;
        
        for (int i = 0; i <= numberofbooks; i++)
        {
            cout << arraytitles[i] << " by " << arrayauthors[i] << endl;
        }
    }
}

int getUserReadCount (string username, string usernames[], int ratings[][50], int rowcapactiy, int numberofbooks)
{
    int l = 0;
    for (int i = 0; i < rowcapactiy; i++)
    {
        if (usernames[i] == username)
        {
            for (int j = 0; j < numberofbooks; j++)
            {
                if (ratings[i][j] != 0)
                {
                    l++;
                }
            }
        }
    }
    if (l == 0)
    {
        return -1;
    }
    else
    {
        return l;
    }
    
}


double calcAvgRating (string booktitle, string arraytitles[], int ratings[][50], int rowcapactiy, int numberofbooks)
{
    double mean = 0;
    double sum = 0;
    int l = 0;
    for (int i = 0; i < numberofbooks; i++)
    {
        if (arraytitles[i] == booktitle)
        {
            for (int j = 0; j < rowcapactiy; j++)
            {
                if (ratings[j][i] != 0)
                {
                    sum = sum + ratings[j][i];
                    l++;
                }
            }
        }
    }
    mean = sum / l;
    if (l == 0)
    {
        cout << booktitle << " does not exist in the database" << endl;
        return -1;
    }
    else
    {
        return mean;
    }
}



int main()
{
    int numberofbooks = 50;
    int capacity = 50;
    string arraytitles[capacity];
    string arrayauthors[capacity];
    string filename = "books.txt";
    cout << readBooks(filename, arraytitles, arrayauthors, numberofbooks, capacity) << endl;
    for (int i = 0; i < 50; i++)
    {
        cout << arraytitles[i] << arrayauthors[i] << endl;
    }
    
    string filename1 = "ratings.txt"; 
    int currentusers = 0;
    int rowcapactiy = 100;
    int columncapacity = 50;
    string usernames[rowcapactiy];
    int ratings[100][50];
    cout << readRatings(filename1, usernames, ratings, currentusers, rowcapactiy, columncapacity) << endl;
    
    numberofbooks = 5;
    printAllBooks(arraytitles, arrayauthors, numberofbooks);
    
    numberofbooks = 50;
    string username = "jerry";
    cout << getUserReadCount(username, usernames, ratings, rowcapactiy, numberofbooks) << endl;
    
    
    string booktitle = "The Da Vinci Code";
    cout << calcAvgRating(booktitle, arraytitles, ratings, rowcapactiy, 50);
    
    cout << "Enter book title:" << endl;
    cin >> booktitle;
    double mean = 0;
    mean = calcAvgRating(booktitle, arraytitles, ratings, rowcapactiy, 50);
        if (mean != -1)
        {
            cout << "The average rating for " << booktitle << " is " << mean << endl;
        }
}
