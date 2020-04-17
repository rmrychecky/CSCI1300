
#include <iostream>
using namespace std;
#include <string>
#include <iomanip> //set predcison or width
#include <cmath> // b * (1 + r/100)^2

// cout << ":" << setw(6) << 12; //:      12
// cout << fixed << setprecison(2) << 12.3; //12.30

// //homework 3 problem 4 bool example 

// bool failed = true;

// You can use the value later in your program to make a decision:

// if (failed) // Only executed if failed has been set to true
// {
//   . . .
// }

int function()
{
 int value = 35;
 return value + 5;
 value += 10;
}

 int main ()
 {
    cout << function() << endl;
    cout << "This is the computer\n programming book\n";
    cout << "hello";
    cout << "Hello Students/n";
    
    int x, y, z; 
    y = 10; 
    z = 3; 
    x = y * z + 3;  
    cout << x << endl;
    
    double value = 33.5; 
    cout << "value" << endl;
    
    float a; 
    a = 15/4;
    cout << a << endl;
    
    int w; 
    w = 15 % 4;
    cout << w << endl;
    
    float j; 
    j = 3.0 / 4.0 + 3 + 2 / 5;
    cout << j << endl;
    
    float k; 
    k = 3.0 / 4.0 + (3 + 2 )/ 5;
    cout << k << endl;
    
    //(!(x<15 && y>=3)) = (x>=15 || y < 3)
    //if x is 0, what is the value of (!x ==0)? FALSE
    
    
    
 }
 
 
 
// <cmath>
// •int abs(int x)
// •double abs(double x)
// Function: Absolute value, |x|
// •double cos(double x)
// Function: Cosine, cos x (x in radians)
// •double log(double x)
// Function: Natural log, log(x), x > 0
// •double log10(double x)
// Function: Decimal log, log10 (x), x > 0
// •double pow(double x, double y)
// Function: Power, xy. If x > 0, y can be any value. If x is 0, y must be > 0. If x < 0, y must be an integer.
// •double sin(double x)
// Function: Sine, sin x (x in radians)
// •double sqrt(double x)
// Function: Square root, 
// •double tan(double x)
// Function: Tangent, tan x (x in radians)
