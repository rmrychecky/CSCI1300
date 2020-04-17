#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

int diagonalSum(int array[][3], int row)
{
   int sum = 0;
   for (int i = 0; i < row; i++) //i = row index
   {
       
       for (int j = 0; j < 3; j++) //j = column index
       {
           if (i == j)
           {
               sum = sum + array[i][j];
           }
        
       }
      
   }
   return sum;

}

int main()
{
    
int array[3][3]= {{1, 4, 6}, {7, 23, 3}, {5, 15, 25}}; //0,0 1,1 2,2 
cout << diagonalSum(array, 3) << endl;
 
}