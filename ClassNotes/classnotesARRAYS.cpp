#include <iostream>
using namespace std;

//using an array to find the maximun 
int main()
{  
   const int CAPACITY = 10; //number of elements in the array 
   //int size = 100;
   double values[CAPACITY]; //defining an array-size must be constant
  
   for (int i = 0; i < CAPACITY; i++)
   {
      values[i] = (i + 1) * (i + 1); //squaring them
      cout << values[i] << endl;
   }

   
   return 0;
}

//largest value
/*Please enter values, Q to quit:
1 2 3 4 5 6 q
1
2
3
4
5
6 <== largest value*/

int main()
{  
   const int CAPACITY = 1000;
   double values[CAPACITY];
   double input;
   int array_size = 0;
   double largest = -10000000000;
   
   cout << "Please enter values (separated by spaces), Q to quit:" << endl;
   int i = 0;
   
   // need to remember how many elements we entered
   while (cin >> input)
   {
      // check if we haven't entered more than 1000 numbers
      if (i < CAPACITY)
      {
         values[i] = input;
         i++;
      }
   }
   array_size = i;
   cout << array_size << endl;
   
   // find the largest
   for (i=0; i < array_size; i++)
   {
      if (values[i] > largest) //largest holds max value so far
      {
         largest = values[i];
      }
   }
   //print them
   for (i=0; i < array_size; i++)
   {
      cout << values[i];
      if (values[i] == largest)
      {
         cout << " <== largest value";
      }
      cout << "\n";
   }
   
   return 0;
}

//sum of values in array
void multiply(double values[], int size, double factor)
{
   for (int i = 0; i < size; i++)
   {
      values[i] = values[i] * factor;
   }
}

//multiply values in arrary

void multiply(double values[], int size, double factor)
{
   for (int i = 0; i < size; i++)
   {
      values[i] = values[i] * factor;
   }
}

//adds input values to an array

int read_inputs(double inputs[], int capacity)
{
   int current_size = 0;
   double input;
   while (cin >> input)
   {  
      if (current_size < capacity)
      {
         inputs[current_size] = input;
         current_size++;
      }
   }
   return current_size;
}

//


const int MAXIMUM_NUMBER_OF_VALUES = 1000;
double values[MAXIMUM_NUMBER_OF_VALUES];
int current_size = read_inputs(values, MAXIMUM_NUMBER_OF_VALUES); 
   // values is a partially filled array; the current_size variable specifies its size
Alternatively, you can pass the size as a reference parameter. This is more appropriate for functions that modify an existing array:

void append_inputs(double inputs[], int capacity, int& current_size)
{
   double input;
   while (cin >> input)
   {  
      if (current_size < capacity)
      {
         inputs[current_size] = input;
         current_size++;
      }
   }
}

// Building an array 
const int SIZE = 100; //constant size
int numbers[SIZE]; //makes 100 elements for the array 
for (int k = 0; k < SIZE; k++)
{
   numbers[k] = k + 1 //values from 1 to 100
}

//array that can hold 99 elements
int values[99];
//placing 100 into the last element of the array values
values[98] = 100;
//array that holds numbers, 2, 3, 5, 7
int a[] = {2, 3, 5, 7}; 
int a[7] = {2, 3, 5, 7}; //the other 3 elements will be initalized as 0
//adds one to each element
a[i]++;

//arrays and algorithims
const int NUM_SCORES = 5;

int main()
{
    int score[NUM_SCORES];
    
    cout << "Enter 5 scores: \n";
    cin >> score[0];
    cin >> score[1];
    cin >> score[2];
    cin >> score[3];
    cin >> score[4];
    
    // copying to another array
    int newArray[NUM_SCORES];
    for (int i = 0; i < 5; i++)
    {
        newArray[i] = score[i];
    }
    
    // the sum of all scores
   int total = 0;
	for (int i = 0; i < NUM_SCORES; i++)
	{
	   total = total + score[i];
	}
	cout << "Total: " << total<< endl;
    
    // Find average
    cout << "Average: " << double(total)/NUM_SCORES << endl;
    
    // Find max score
    int max = score[0];
    for (int i = 1; i < NUM_SCORES; i++)
    {
        if (score[i] > max)   
        {
            max = score[i];
        }
    }
    cout << "The highest score is " << max << endl;
    
    // Find the position of the highest score
    int pos = 0;
    bool found = false;
    while (pos < NUM_SCORES && !found)
    {
        if (score[pos] == 100) // looking for 100
        {
            found = true;
        }
        else
        {
            pos++;
        }
    }
    if (pos < NUM_SCORES)
    {
        cout << "The index for 100 is: " << pos << endl;
    }
    else
    {
        cout << "100 not found" << endl;
    }

    return 0;
}

//2-D array 
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int COLUMNS = 3;

/**
   Computes the total of a row in a table.
   @param table: a table with 3 columns
   @param row: the row that needs to be totaled
   @return the sum of all elements in the given row
*/
//const int COUNTRIES = 8;
//const int MEDALS = 3;
//int counts[COUNTRIES] [MEDALS];

double row_total(int table[][COLUMNS], int row)
{
   int total = 0; 
   for (int j = 0; j < COLUMNS; j++)
   {
      total = total + table[row][j];
   }
   return total;
}

double col_total(int table[][COLUMNS], int no_rows, int col)
{
   int total = 0;
   for (int i = 0; i < no_rows; i++)
   {
      total = total + table[i][col];
   }
   return total;
}

int main()
{
   const int COUNTRIES = 7;
   const int MEDALS = 3;

   string countries[] =
      {
         "Canada",
         "China",
         "Germany",
         "Korea",
         "Japan",
         "Russia",
         "United States"
      };
   // C++ uses an array with two subscripts to store a two-dimensional array. 
   // For exam- ple, here is the de nition of an array with 7 rows and 3 columns, 
   // suitable for storing our medal count data:
   int counts[COUNTRIES][MEDALS] = 
   { 
      { 1, 0, 1 },
      { 1, 1, 0 },
      { 0, 0, 1 },
      { 1, 0, 0 },
      { 0, 1, 1 },
      { 0, 1, 1 },
      { 1, 1, 0 }
   }; 

   cout << "        Country    Gold  Silver  Bronze   Total" << endl;

   // Print countries, counts, and row totals
   for (int i = 0; i < COUNTRIES; i++)
   {
      cout << setw(15) << countries[i];
      // Process the ith row
      for (int j = 0; j < MEDALS; j++)
      {
         cout << setw(8) << counts[i][j];
      }
      int total = row_total(counts, i);
      cout << setw(8) << total << endl; 
   }
   
   // Print countries, counts, and rows and column totals
   cout << "\n        Country    Gold  Silver  Bronze   Total" << endl;

   for (int i = 0; i < COUNTRIES; i++)
   {
      cout << setw(15) << countries[i];
      // Process the ith row
      for (int j = 0; j < MEDALS; j++)
      {
         cout << setw(8) << counts[i][j];
      }
      int total = row_total(counts, i);
      cout << setw(8) << total << endl; 
   }
   cout << setw(15) << "Total" << setw(8) <<col_total(counts, COUNTRIES, 0);
   cout << setw(8) << col_total(counts, COUNTRIES, 1);
   cout << setw(8) << col_total(counts, COUNTRIES, 2);

   return 0;
}

matrix 

//what does computer know about array
//base type, address of first indexed variable, number of indexed variables
//needs to know size 
//passing 2-D arrays
// const char p[][100]  (must hardwire the number of columns)