#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

bool similarity(int arr1[], int size1, int arr2[], int size2)
{
    if (size1 != size2)
    {
        return false;
    }
    else 
    {
        for (int i = 0; i < size1; i++)
        {
            if (arr1[i] != arr2[i])
            {
                return false;
            }
        }
        return true;
    }

}


int main()
{
int size1 = 6;   
int arr1[6] = {1, 4, 6, 7, 23, 3};
int size2 = 6;
int arr2[6] = {1, 4, 6, 7, 23, 3};

cout << similarity(arr1, size1, arr2, size2) << endl;

}