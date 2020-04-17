#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

double matrixAverage(int numbers[][2], int size)
{
    double average = 0;
    double sum1 = 0;
    double sum2 = 0;
    double total = 0;
    
    for (int i = 0; i < size; i++)
    {
        
        for (int j = 0; j < 2; j++)
        {
            sum2 = sum2 + numbers[i][j];
        }
    }
    total = sum1 + sum2;
    average = total / (size*2);
    return average;
    
}

int main()
{
    // int array[1][2] = {{13, 15}};
    // cout << matrixAverage(array, 1) << endl;
    
    // int array[2][2]={{1,1},{3,4}}; 
    // cout << matrixAverage(array, 2) << endl;
    
    int array[4][2]={{3,4},{78,98},{12,-11},{1909,4}};
    cout << matrixAverage(array, 4) << endl;

}