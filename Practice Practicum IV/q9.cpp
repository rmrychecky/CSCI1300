#include <iostream>
using namespace std;

class OddEven 
{
private:

  int numbers[50];

public: //set each function with their perspective input types

  OddEven();
  
  void ReadFile(string filename);
  
  int getOddCount();
  
  int getEvenCount();
  
};

OddEven :: OddEven()
{
  for (int i = 0; i < 50; i++)
  {
    numbers[i] = -1;
  }
}

void OddEven :: ReadFile(string filename)
{
   ifstream file;
   file.open(filename); 
   string line;
   int i = 0;
   
   if (file.is_open())
   {
     while (getline(file, line))
     {
       if (line[0] != '1' && line[0] != '2' && line[0] != '3' && line[0] != '4' && line[0] != '5' && line[0] != '6' && line[0] != '7' && line[0] != '8' && line[0] != '9')
       {
         file.close();
         return;
       }
       numbers[i] = stoi(line);
       i++;
     }
   }
   file.close();
}

int OddEven :: getOddCount()
{
  int oddCount = 0;
  for (int i = 0; i < 50; i++)
  {
     if(numbers[i]%2 != 0 && numbers[i] != -1)
     {
       oddCount++;
     }
  }
  return oddCount;
}

int OddEven :: getEvenCount()
{
  int evenCount = 0;
  for (int i = 0; i < 50; i++)
  {
     if(numbers[i]%2 == 0 && numbers[i] != -1)
     {
       evenCount++;
     }
  }
  return evenCount;
}