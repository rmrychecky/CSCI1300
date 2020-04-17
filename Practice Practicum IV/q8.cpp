#include <iostream>
using namespace std;

class Players 
{
private:

  float salaries[50];
  string names[50];

public: //set each function with their perspective input types

  Players();
  
  void ReadFile(string filename);
  
  float MaxSalary();
  
  string MaxSalaryName();
  
};

int split(string s, char sep, string words[], int max_words);

Players :: Players()
{
  for (int i = 0; i < 50; i++)
  {
    salaries[i] = -1.0;
  }
  for (int j = 0; j < 50; j++)
  {
    names[j] = "";
  }
}

void Players :: ReadFile(string filename)
{
   ifstream file;
   file.open(filename); 
   string line;
   string array[2];
   int i = 0;
   
   if (file.is_open())
   {
     while (getline(file, line))
     {
       split(line, ',', array, 2);
       salaries[i] = stof(array[1]);
       names[i] = array[0];
       i++;
     }
   }
   file.close();
}

float Players :: MaxSalary()
{
  float maximum = 0;
  for (int i = 0; i < 50; i++)
  {
    if (salaries[i] > maximum)
    {
      maximum = salaries[i];
    }
  }
  return maximum;
}

string Players :: MaxSalaryName()
{
  float maximum = MaxSalary();
  string name;
  for (int i = 0; i < 50; i++)
  {
    if(salaries[i] == maximum)
    {
        name = names[i];
    }
  }
  return name;
}