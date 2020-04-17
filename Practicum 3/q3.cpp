#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

int writePositiveEven(string filename, int array[], int size)
{
    ofstream outputfile;
    outputfile.open(filename);
    string line = ""; 

    if (outputfile.is_open()) //if the file opens
    {
        for (int i = 0; i < size; i++)
        {
            if (array[i] >= 0 && array[i] % 2 == 0)
            {
                outputfile << array[i] << endl;
                
            }
        }
        return 1; 
    }
    else
    {
        return -1;
    }
    outputfile.close();
}

int main()
{
    
int array[5] = {1,2,-6,4,5};
string filename = "output.txt";
cout << writePositiveEven(filename, array, 5) << endl;

}