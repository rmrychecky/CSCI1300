#include <iostream>
#include <string>
#include <cmath>
using namespace std;


int main()
{
    
bool token = false;
if (token)
{
   cout << "Hello World!" << endl;
}
else
{
   cout << "Terminates" << endl;
}


while (token)
{
   cout << "Hello World!" << endl;
}

int i = 1;
while (i != 9)
{
   cout << i << " ";
   i++;
   if (i = 9)
   {
      cout << "End";
   }
}
// 1 End

int i;
int j;
for (i = 0; i < 6; i++)
{
   for (j = 7; j > i; j--)
   {
      cout << "+";
   }
   cout << endl;
}


}
//The correct answer is: An inverted right triangle with six rows and seven columns of the plus sign. The number of columns decrements by one on completion of one iteration of the inner loop.

//do while does not check condition at beginning of loop

string s = "1234";
for (int i = 0; i <= 4; i++)
{
   cout << s.substr (i, 1);
}
//No, there will be a string index out of bounds error.

//rec 4 problem 3 print out the asterik squares