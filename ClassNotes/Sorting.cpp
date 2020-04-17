//vector<double> values; (empty)
//get an error

values.push_back(32); //one element with 32

//can only add and remove from the end
values.pop_back();

#include <iostream>
#include <vector>

using namespace std;


vector<double> read_inputs();
vector<double> multiply(vector<double> values, double factor);
void print(vector<double> values);

int main()
{  
   vector<double> values = read_inputs();
   print(values);
   vector<double> doubleValues = multiply(values, 2);
   print(doubleValues);

   return 0;
}
/**
   Reads a sequence of floating-point numbers.
   @return a vector containing the numbers
 */
vector<double> read_inputs()
{
   vector<double> result;
   cout << "Please enter values, Q to quit:" << endl;
   bool more = true;
   while (more)
   {  
      double input;
      cin >> input;
      if (cin.fail())
      {
         more = false;
      }
      else 
      {
         result.push_back(input);
      }
   }
   return result;
}

/**
   Multiplies all elements of a vector by a factor
   @param values a vector
   @param factor the value with which each element is multiplied
 */
vector<double> multiply(vector<double> values, double factor)
{
   for (int i = 0; i < values.size(); i++)
   {
      values[i] = values[i] * factor;
   }
   return values;
}

/**
   Prints the elements of a vector, separated by commas.
   @param values a vector
 */
void print(vector<double> values)
{
   for (int i = 0; i < values.size(); i++)
   {
      if (i > 0) { cout << ", "; }
      cout << values[i];
   }
   cout << endl;
}

/**
   Multiplies all elements of a vector by a factor
   @param values a vector
   @param factor the value with which each element is multiplied
 */
void multiply2(vector<double>& values, double factor)
{
   for (int i = 0; i < values.size(); i++)
   {
      values[i] = values[i] * factor;
   }
}

//PUSH BACK

#include <iostream>
#include<vector>
using namespace std;

/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].
*/

vector<int> read_inputs()
{
   vector<int> result;
   int input;
   cout << "Please enter values, Q to quit: ";
   while (cin >> input)
   {
        result.push_back(input);
        cout << "Please enter values, Q to quit: ";
   }
    cin.clear(); 
    cin.ignore();
   return result;
}

void print(vector<int> values)
{
   for (int i = 0; i < values.size(); i++)
   {
      cout << values[i] << " ";
   }
   cout << endl;
}

vector<int> moveZeroes(vector<int> nums) {
    int i=0;
    int size = nums.size();
    while ( i< size) {
        if (nums[i] == 0) {
            nums.push_back(0);
            nums.erase(nums.begin()+i);
            size--;
        } else {
            i++;
        }
    }
    return nums;
}

//adding values into a vector
double input;
while (cin>> input)
{
   values.push_back(input);
}

main() {
    vector<int> one = read_inputs();
    vector<int> three = moveZeroes(one);
    cout << "old: ";
    print(one);
    cout << "new: ";
    print(three);
    
}

//ROTATING AN ARRAY OF N ELEMENTS TO THE RIGHT BY K STEPS

#include <iostream>
#include<vector>
using namespace std;

/*
Rotate an array of n elements to the right by k steps.
For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
*/

vector<int> read_inputs()
{
   vector<int> result;
   int input;
   cout << "Please enter values, Q to quit: ";
   while (cin >> input)
   {
        result.push_back(input);
        cout << "Please enter values, Q to quit: ";
   }
    cin.clear(); 
    cin.ignore();
   return result;
}

void print(vector<int> values)
{
   for (int i = 0; i < values.size(); i++)
   {
      cout << values[i] << " ";
   }
   cout << endl;
}

vector<int> rotate(vector<int> nums, int k) {
    for (int i = 0; i < k; i++) {
        nums.insert(nums.begin(), nums[nums.size()-1]);
        nums.pop_back();
    }
    return nums;
}


main() {
    vector<int> one = read_inputs();
    vector<int> three = rotate(one, 3);
    cout << "old: ";
    print(one);
    cout << "new: ";
    print(three);
    
}

//finding values in array that meet certain condition
//create another arry and copy the elements that meet the condition

//remove element from vector
//overwrite the element at that postion with the last element in the vector
//values[i] = values[size() -1] 
//int last_pos = values.size() - 1;
//pop the last one

//inserting an element into a vector in a sepcific position 
//push back value at last position

int last_pos = values.size() - 1;
values.push_back(values[last_pos]);

//go through the loop that shifts them
for (int i = last_pos; i > pos; i--)
{
    values[i] = values[i - 1];
}
values[pos] = new_element;