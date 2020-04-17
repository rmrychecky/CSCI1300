#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void printTwoDArray(int array[][5], int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (j != 4)
            {
                cout << array[i][j] << ",";
            }
            else
            {
                cout << array[i][j];
            }
            
        }
        cout << endl;
        
    }
    if (length == 0)
    {
        cout << 0;
    }
    if (length < 0)
    {
        cout << -1;
    }

}



int main() 
{
    int myArray[3][5] = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15}};
    printTwoDArray(myArray, 3);
}

