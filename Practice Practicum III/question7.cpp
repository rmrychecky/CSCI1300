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
 
int PrintStudents(string filename, int minimum, string output)
{
    ifstream file; 
    file.open(filename);
    ofstream outputfile;
    outputfile.open(output);
    
    string line = ""; 
    string array[3];
    
    if (file.is_open()) //if the file opens
    {   
        int i = 0;
        while (getline(file, line)) //store each author in first array and each title in second array
        { 
            Split(line, ',', array, 3);
            if (line != "")
            {
                if (stoi(array[1]) >= minimum)
                {
                    outputfile << array[0] << ',' << array[2] << endl;

                }
                i++;
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
string filename = "data.txt";
string output = "output.txt";
cout << PrintStudents(filename, 80, output) << endl; //expected return: 8
 
}