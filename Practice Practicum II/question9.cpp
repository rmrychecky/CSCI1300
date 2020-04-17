#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void PrintOddPattern()
{
    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j<i; j++)
        {
            cout << "$*$*$" << endl;
        }
    }

}
   

int main()
{
PrintOddPattern();
}