#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;


 int Split (string str, char c, string array[], int size) //given split function
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
 
int parseScores(string filename)
{
    ifstream file; 
    file.open(filename);
    string line = ""; 
    string array[4];
    int maximum = 0;
    
    if (file.is_open()) //if the file opens
    {
        int i = 0;
        while (getline(file, line)) //store each author in first array and each title in second array
        { 
            Split(line, ',', array, 4);
            if (line != "")
            {
                if (stoi(array[0]) > stoi(array[1]) && stoi(array[0]) > stoi(array[2]))
                {
                    maximum = stoi(array[0]);
                }
                else if (stoi(array[1]) > stoi(array[0]) && stoi(array[1]) > stoi(array[2]))
                {
                    maximum = stoi(array[1]);
                }
                else 
                {
                    maximum = stoi(array[2]);
                }
                i++;
                cout << array[3] << ": " << maximum << endl;
            }
        }
        return i; 
    }
    else
    {
        return -1;
    }
    file.close();

}

int main()
{
string filename = "text.txt";
cout << parseScores(filename) << endl; //expected return: 8
 
}