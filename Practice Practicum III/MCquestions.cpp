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


//Consider a function that takes an array of integers and returns the sum of all the elements. 
//The case where the function is called with an array of size zero is called a BOUNDARY CONDITION

//Consider an array of size 3 by 4. What is the offset to reach the array[2][1] element? 9

// const int SIZE = 5;
// int data_array[SIZE];
// for (int i = 0; i < SIZE; i++)
// {
//   data_array[i] = 2 * (i–1);
// }
//2


// int marks[3] = { 90, 45, 67 };
// for (int i = 0; i <= 3; i++)
// {
//   cout << marks[i] << endl;
// }
// The code snippet has a bounds error or displays redundant data.


// int numarray[6];
// for (int cnt = 1; cnt < 6; cnt++)
// {
//  numarray[cnt] = cnt + 1;
// }
// Initializes all except the first element 

// int number[3]; // Line 1
// number[3] = 5; // Line 2
//Line 2 causes a bounds error because 3 is an invalid index number.

// int somearray[6];
// for (int i = 1; i < 6; i++)
// {
//   somearray[i] = i + 1;
// }
//all except the first

// int arr[2][3] = { { 13, 23, 33 }, { 14, 24, 34 }};What is the appropriate statement to display the value 24 from the given array?
//arr[1][1]

// my_fun(dataset, vardata);
// Which one of the following function headers is valid for my_fun, where dataset is an integer array and vardata is an integer variable?
// void my_fun(int dataset[], int vardata)

//int myarr[10][8];
//can store 80 elements

// int numarray[10];
// making an integer array of 10 elements

int my_fun (int A[], int size)
{
  int result = 0;
  for (int i = 0; i < size; i++)
  {
     result = result + A[i];
  }
  return result;
}
int main()
{
  int myarr[10] = { 5, 6, 10, 1, 2, 4, 8, 1, 2, 1 };
  for (int i = 0; i < 3; i++)
  {
     cout << my_fun(myarr, i);
  }
}
//0511

//What is the valid range of index values for an array of size 7?
//0-6

// int a[] = {0,1,2};
// int b[4];
// b = a;
//this won't compile becase arrays can only be copied one element at a time

//Which one of the following is a valid signature of a function with an integer two-dimensional array parameter of size 10 x 10?
//void func(int arr[][10])

// int maximum = intarray[0]; 
// for (int counter = 1; counter < 100; counter++)
// {  if (intarray[counter] > maximum)
//   {      maximum = intarray[counter];   }
// }
//for finding the max number in an array...

//initlaizing an array with three rows and two columns 
//int arr[3][2] =  
// {
//   { 1, 1 },   { 2, 2 },   { 3, 3 }
// };

// 1. int main()
// 2. {
// 3.    char rd;
// 4.    ifstream read_file;
// 5.    read_file.open("C:\network.txt");
// 6.    while (read_file.get(rd))
// 7.    {
// 8.       cout << rd << endl;
// 9.    }
// 10.   return 0;
// 11. }
//line 5 does not open the file

// int main()
// {   
//   ifstream read_file;
//   read_file.open("File.txt");
   
//   string line1, line2;
//   read_file >> line1;
//   getline(read_file, line2);
   
//   cout << line1 << endl;
//   cout << line2 << endl;
//   return 0;
// }
//prints out "This"

// int main()
// {   
//   ifstream read_file;
//   read_file.open("File.txt");
   
//   char line1[80];
//   string line2;
//   getline(read_file, line1);
//   getline(read_file, line2);
   
//   cout << line1 << endl;
//   cout << line2 << endl;
//   return 0;
// }

//does not compile due to missing getline
}
