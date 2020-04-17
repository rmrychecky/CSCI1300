#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void floodMap(double array[][4], int rows, double waterlevel)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 4; j++)
        {
           double compare = array[i][j];
           if (compare < waterlevel)
           {
               cout << "*";
           }
           else if (compare > waterlevel)
           {
               cout << "_";
           }
            
        }
        cout << endl;
        
    }

}

int main() 
{
    double map[1][4] = {{5.0, 7.6, 3.1, 292}};
    floodMap(map, 1, 6.0);
}

