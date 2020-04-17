#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string decimalToBinaryIterative(int num){

string res="";

int i=0;

if (num == 0)
{
    res = "0";
}

while(num>0){

int t=(num%2);

res=to_string(t)+res;

num/=2;

}

return res;

}

int main() {

cout<<decimalToBinaryIterative(11);

}