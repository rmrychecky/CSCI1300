#include <iostream>
using namespace std;

class ChildGrowth //creating book class
{
private:

   string name;
   int currentAge;
   double weightMetricConversion;
   float weight[10];
   float height[10];

public: //set each function with their perspective input types

  ChildGrowth();
  
  ChildGrowth(string n);
  
  ChildGrowth(string n, int a);
  
  ChildGrowth(string n, int a, float h[], float w[]);
  
  string getName();
  
  void setName(string n);
  
  int getCurrentAge();
  
  void setCurrentAge(int a);
  
  void setHeight(float h[]);
  
  void setWeight(float w[]);
  
  float feetToMeter(float feet);
  
  float poundToKg(float pound);
  
  float calculateBmi(int age);
  
  string getCategory(int age);
  
  
};