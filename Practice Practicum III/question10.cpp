#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

bool similarity(int arr1[][3], int row1, int arr2[][3], int row2)
{
    if (row1 != row2)
    {
        return false;
    }
    else 
    {
        for (int i = 0; i < row1; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (arr1[i][j] != arr2[i][j])
                {
                    return false;
                }
            }
            
        }
        return true;
    }

}


int main()
{
int row1 = 3;   
int arr1[3][3]= {{1, 4, 6}, {7, 23, 3}, {5, 15, 25}};
int row2 = 3;
int arr2[3][3]= {{1, 4, 6}, {7, 23, 3}, {5, 15, 25}};

cout << similarity(arr1, row1, arr2, row2) << endl;

}