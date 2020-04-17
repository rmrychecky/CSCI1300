#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

void printNormalHeartRates(string patient_names[], int heart_rates[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (heart_rates[i] >= 70 && heart_rates[i] <= 190)
        {
            cout << patient_names[i] << ' ' << heart_rates[i] << endl;
        }
    }

}

int main()
{
    
string patient_names[4] = {"Joe", "Jack", "Amy", "Bob"};
int heart_rates[4] = {90, 60, 200, 100};
printNormalHeartRates(patient_names, heart_rates, 4);

}