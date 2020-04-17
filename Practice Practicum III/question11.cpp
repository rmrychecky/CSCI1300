#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <string>
#include <iomanip>
#include <fstream>
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
    return count ;
 }
 
int writeCountryDensity(string filename, int maximum_density, string file)
{
    ifstream inputfile; 
    inputfile.open(filename);
    ofstream outputfile;
    outputfile.open(file);
    
    string line = ""; 
    string array[3];
    float density = 0;
    float population = 0;
    float area = 0;
    
    if (inputfile.is_open() && outputfile.is_open()) //if the file opens
    {   
        int i = 0;
        while (getline(inputfile, line)) //store each author in first array and each title in second array
        { 
            split(line, ',', array, 3);
            if (line != "")
            {
                population = stoi(array[1]);
                area = stoi(array[2]);
                density = population / area;
                
                if (density <= maximum_density)
                {
                    outputfile << array[0] << ", " << density << endl;
                    i++;

                }
                
            }
            
        }
        return i;

    }
    else
    {
        return -1;
    }
    inputfile.close();
    outputfile.close();

}


int main()
{
string filename = "input.txt";
string file = "output.txt";
cout << writeCountryDensity(filename, 80, file) << endl; 
 

}