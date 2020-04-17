#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

int CountVowels(string string1)
{
    int numberofvowels = 0;
    for (int i = 0; i < string1.length(); i++)
    {
        if (string1[i] == 'a' || string1[i] == 'e' || string1[i] == 'i' || string1[i] == 'o' || string1[i] == 'u')
        {
            numberofvowels++;
        }
        if (string1[i] == 'A' || string1[i] == 'E' || string1[i] == 'I' || string1[i] == 'O' || string1[i] == 'U')
        {
            numberofvowels++;
        }
    }
    if (string1 == "")
    {
        return -1;
    }
    return numberofvowels;
}

int writeVowels(string filename, string array[], int size)
{
    ofstream outputfile;
    outputfile.open(filename);
    string temp = "";
    int numberofvowels = 0;
    int j = 0;
    
    if (outputfile.is_open())
    {
        
        for (int i = 0; i < size; i++)
        {
            temp = array[i];
            if (temp != "")
            {
                numberofvowels = CountVowels(temp);
                outputfile << temp << ',' << numberofvowels << endl;
                j++;
            }
            
        }
        
    }
    outputfile.close();
    
    return j;
}

int main()
{
string lines[3] = {"hello","","WORLD"};
string filename = "output.txt";
cout << writeVowels(filename, lines, 3) << endl;
}