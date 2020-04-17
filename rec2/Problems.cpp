
// Author: Raegan Rychecky CS1300 Fall 2018
// Recitation: 104 (8am) – Richard Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/rmrychecky/csci1300
// Recitation 2 - Problem 1

#include <iostream>
#include <math.h>
using namespace std;

/**
 * Algorithm
 * 1. Take given code and analyze
 * 2. Create variable for surface area
 * 3. Solve for surface area
 * 4. Print out surface area: solved value
 **/

int main(){
    cout << "Enter a radius: " << endl; //lines 20-25 were given
    float radius;
    cin >> radius;
    float volume;
    volume = (4.0/3.0) * M_PI * pow(radius, 3);
    cout << "volume: " << volume << endl;
    
    float surface_area; //create surface area variable
    surface_area = (4.0) * M_PI * pow(radius, 2); //solve for surface area
    cout << "surface area: " << surface_area << endl; //print out the surface area
    return 0;
    
}


// Author: Raegan Rychecky CS1300 Fall 2018
// Recitation: 104 (8am) – Richard Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/rmrychecky/csci1300
// Recitation 2 - Problem 2

#include <iostream>
#include <math.h>


using namespace std;

/**
 * Algorithm: solves for the volume of a sphere with a given input of radius.
 * 1. Take the value passed into the function for radius
 * 2. Solve for volume using the equation (4/3)*π*r^3
 * Input Parameter: radius (with type float)
 * Output: volume (float type)
 * Returns: nothing
 **/
 

 float sphereVolume(float radius) //define the function to solve for sphere volume
 {

     float volume = (4.0/3.0) * M_PI * pow(radius, 3); //solve for volume as a float value
     
     cout <<  "volume: " << volume << endl; //print out the volume
     return 0;
     
 }
 
 int main() //test cases
 {
     sphereVolume(5.0);
     sphereVolume(3.0);
     return 0;

 }


// Author: Raegan Rychecky CS1300 Fall 2018
// Recitation: 104 (8am) – Richard Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/rmrychecky/csci1300
// Recitation 2 - Problem 3

#include <iostream>
#include <math.h>

using namespace std;


/**
 * Algorithm: solves for the surface area of a sphere with a given input of radius
 * 1. Take the value passed into the function for radius
 * 2. Solve for surface area using the equation (4)*π*r^2
 * Input Parameter:radius (with type float)
 * Output: surface area (float type)
 * Returns: nothing
 **/


float sphereSurfaceArea(float radius) //define the function to solve for sphere surface area
{
    float surface_area = (4.0) * M_PI * pow(radius, 2); //solve for surface area
     
     cout <<  "surface area: " << surface_area << endl; //print out the surface area
     return 0;
}

int main() //test cases
{
    sphereSurfaceArea(5.0);
    sphereSurfaceArea(3.0);
    return 0;
}



// Author: Raegan Rychecky CS1300 Fall 2018
// Recitation: 104 (8am) – Richard Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/rmrychecky/csci1300
// Recitation 2 - Problem 4

#include <iostream>
#include <math.h>
using namespace std;

/**
 * Algorithm: takes an integer argument and prints a greeting based on given value
 * 1. Take the value passed into the function 
 * 2. Print out Hello, CS (value) World!
 * Input Parameter: integer
 * Output: Hello, CS (value) World! greeting
 * Returns: nothing
 **/
 


 void classGreeting(int number) //define a void function to print out the greeting
 {
     cout << "Hello, CS " << number << " World!";
     
 }

int main() 
{
    
cout << "Enter a CS course number" << endl; //ask the user to input a number
int number;
cin >> number;

classGreeting(number); //pass the number through the function (void classGreeting)
return 0;

}
