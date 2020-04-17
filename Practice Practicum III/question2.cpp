#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

 
int countCharacter(string array[], int size, char ch)
{
    int counter = 0;
    string line = "";
    
    for (int i = 0; i < size; i++)
    {
        line = array[i];
        for (int j = 0; j < line.length(); j++)
        {
            if (line[j] == ch)
            {
                counter++;
            }
        }
        
    }
    return counter;
}

int main()
{
string array[6] = {"elephant", "english", "elegant", "america", "united", "apple"};
char ch = 'e';
cout << countCharacter(array, 6, ch) << endl;
 
}