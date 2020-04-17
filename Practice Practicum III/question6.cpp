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
 
float maxTemp(string filename)
{
    ifstream file; 
    file.open(filename);
    string line = ""; 
    string array[2];
    float max = 0.0;
    
    if (file.is_open()) //if the file opens
    {
        while (getline(file, line)) //store each author in first array and each title in second array
        { 
            Split(line, ',', array, 2);
            if (line != "")
            {
                if (stoi(array[1]) > max)
                {
                    max = stoi(array[1]);
                }
            }
        }
        return max; 
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
cout << maxTemp(filename) << endl; //expected return: 8
 
}