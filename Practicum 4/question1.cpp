#include <iostream>
#include <string>
using namespace std;


class ComputerLab 
{
private:

   string name;
   int nItems;
   float speeds[128];
   string models[128];


public:

  ComputerLab();
  
  ComputerLab(string labName);
  
  void InitDataMembers();
  
  bool AddCPU(float speed, string model);
  
  float CalcAverage();
  
  int CountAvailable(float minSpeed);
  
  int CountAvailableModels(string model);
  
};