#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void MultiplicationTableFor()
{
    for(int i = 1; i<=5; i++)
    {
        for(int u = 1; u<=i; u++)
        {
            cout << u*i << " ";
        }
        cout << endl;
    }
}



int main()
{
MultiplicationTableFor();
}