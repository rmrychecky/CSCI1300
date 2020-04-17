#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

bool IsPrime(int x)
{
    bool frog = 1;
    if (x < 0)
    {
        x = x * -1;
    }
    if (x == 1)
    {
        frog = 0;
    }
    
    for(int i = x - 1; i > 1; i--)
    {
        if(x % i==0)
        {
            frog = 0;
        }
    }
    return frog;
}

int countPrimes(int array[], int size)
{
    int counter = 0;
   for (int i = 0; i < size; i++)
   {
       if (array[i] == 0)
       {
           
       }
       else if (IsPrime(array[i]) == 1)
       {
           counter++;
       }
   }
   return counter;
}

int main()
{
int array[5] = {1, 2, 3, 4, 0};

cout << countPrimes(array, 5) << endl;

// int array[8] = {1, 2, 3, 4, 5, 7, 10, 12};
// cout << countPrimes(array, 8) << endl;
 
}