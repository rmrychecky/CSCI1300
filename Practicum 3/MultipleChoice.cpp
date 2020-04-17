#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
    
// int total = 50;
// int table[][3] = { { 5, 3, 5 }, { 0, 2, 3 }, { 1, 4, 8 }, };
// for (int k = 0; k < 3; k++)
// {
//     total = total - table[k][k];
// }
// cout << total;

// int mynum[5];
// for (int i = 1; i < 5; i++)
// {
//     mynum[i] = i + 1;
//     cout << mynum[i];
// }

string str = "Hello World";
string line;
int count = 0;
ifstream infile;
infile.open("Data.txt");
while (getline (infile, line))
{
    count++;
    str = line;
}
cout << count << " " << str << " " << line << endl;
return 0;


}