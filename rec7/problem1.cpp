#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void replaceNums(int array[], int length)
{
    int temp[length];
    for (int i = 0; i < length; i++)
    {
        temp [i] = array [i];
    }
    
    if  (length != 1 && length != 2)
    {
        for (int i = 1; i < length - 1; i++)
        {
            if (temp[i + 1] > temp[i - 1])
            {
                array[i] = temp[i + 1];
            }
            else if (temp[i + 1] < temp[i - 1])
            {
                array[i] = temp[i - 1];
            }
            else if (temp[i + 1] == temp[i - 1])
            {
                array[i] = temp[i + 1]; 
            }
            // else 
            // {
            //     array[i] = temp[i];
            // }
        }
    }
    // cout << "{";
    // for (int i = 0; i < length ; i++)
    // {
    //     if (i == length - 1)
    //     {
    //         cout << array[i];
    //     }
    //     else 
    //     {
    //         cout << array[i] << ", ";
    //     }
        
    // }
    // cout << "}";    
    
}



int main() 
{
    //int myArray[2] = {1, 5};
    //replaceNums(myArray, 2);
    
    // int myArray[1] = {1};
    // replaceNums(myArray, 1);
    
    // int myArray[3] = {1, 3, 5};
    // replaceNums(myArray, 3);
    
    // int myArray[3] = {5, 3, 1};
    // replaceNums(myArray, 3);
    
    int myArray[5] = {1, 2, 3, 4, 5};
    replaceNums(myArray, 5);
}

