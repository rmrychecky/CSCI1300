#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

void printTotalMedals(string disciplines[], int gold_medals[], int silver_medals[], int bronze_medals[], int size)
{
    int sum = 0;
    int number1 = 0;
    int number2 = 0;
    int number3 = 0;
    
    if (size < 1)
    {
        cout << "Invalid size. Size must be at least 1." << endl;
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            number1 = gold_medals[i];
            number2 = silver_medals[i];
            number3 = bronze_medals[i];
            sum = number1 + number2 + number3;
            cout << disciplines[i] << ": " << sum << endl; 
        }
    }


}


int main()
{

const int SIZE = 3; // number of sports/disciplines
string disciplines[] = {"Figure Skating", "Speed Skating", "Short track"};

int gold_medals[SIZE] =   {1, 0, 0};
int silver_medals[SIZE] = {1, 0, 0};
int bronze_medals[SIZE] = {1, 2, 1};

printTotalMedals(disciplines, gold_medals, silver_medals, bronze_medals, 3); 

}