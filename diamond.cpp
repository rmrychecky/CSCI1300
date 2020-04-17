#include <iostream>
using namespace std;

//n = 4
//___*___
//__***__
//_*****_
//*******

//n = 3
//__*__
//_***_
//*****

int main()
{
    int n = 4;
    for (int i = 0; i < n; i++)
    {
        //dashes first: how many? 4-row 
        for (int j = 0; j < n-(i+1); j++)
        {
            cout << "-";
        }
        //stars:
        for (int k = 0; k < 2 * (i + 1) - 1; k++)
        {
            cout << "*";
        }
        //dashes
        for (int j = 0; j < n-(i+1); j++)
        {
            cout << "-";
        }
        cout << endl;
    }
    
    
    
    
}
