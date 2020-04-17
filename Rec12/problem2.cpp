#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string decimalToBinaryRecursive(int n) 
{
    if(n == 0) 
    {
        return "0";
    } 
    else if(n == 1) 
    {
        return "1";
    } 
    else 
    {
        int d = n % 2;
        string s = d == 0 ? "0" : "1";
        return decimalToBinaryRecursive(n/2) + s;
    }
}

