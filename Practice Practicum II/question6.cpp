#include <iostream>
#include <string>
#include <cmath>
using namespace std;


void MultiplicationTableWhile()
{
    int i = 1;
    while(i<=5)
    {
        int u = 1;
        while(u<=i)
        {
            cout << i*u << " ";
            u++;
        }
        cout << endl;
        i++;
    }
}

void MultiplicationTableWhile()
{
    int number = 1;
    while (number <= 5)
    {
        if (number == 1)
        {
            cout << number << endl;
            number++;
        }
        if (number == 2)
        {
            cout << number << " " << number * 2 << endl;
            number++;
        }
        if (number == 3)
        {
            cout << number << " " << number * 2 << " " << number * 3 << endl;
            number++;
        }
        if (number == 4)
        {
            cout << number << " " << number * 2 << " " << number * 3 << " " << number * 4 << endl;
            number++;
        }
        if (number == 5)
        {
            cout << number << " " << number * 2 << " " << number * 3 << " " << number * 4 << " " << number * 5 << endl;
            number++;
        }

    }
    
}


int main()
{
MultiplicationTableWhile();
}