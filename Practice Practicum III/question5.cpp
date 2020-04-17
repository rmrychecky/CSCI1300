#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

void findDuplicate(int array[], int size)
{
    int num = 0;
    int copy = 0;
    
   for (int i = 0; i < size; i++)
   {
       num = array[i];
       for (int j = i + 1; j <= size - 1; j++)
       {
            if (array[j] == num)
            {
                copy = array[j];
                break;
            }    
            
       }
      
   }
   if (copy == 0)
   {
       cout << -1 << endl;
   }
   else 
   {
       cout << copy << endl;
   }

}

int main()
{
// int array[10] = {2,3,5,6,11,20,4,8,4,9};
// findDuplicate(array, 10);

int array[8] = {11,20,4,8,9,9,21,50};
findDuplicate(array, 8);

// int array[6] = {10,-10,4,7,20,7};
// findDuplicate(array,6);
 
}