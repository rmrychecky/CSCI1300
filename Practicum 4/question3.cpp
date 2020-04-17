#include <iostream>
using namespace std;

class AwardWinners 
{
private:

  string name[20];
  int year[20];

public: //set each function with their perspective input types

  AwardWinners();
  
  int ReadFile(string filename);
  
  string getWinnerName(int winningYear);
  
  int getWinningYear(string winner);
  
};

AwardWinners :: AwardWinners()
{
  for (int i = 0; i < 20; i++)
  {
    name[i] = "";
    year[i] = 0;
    
  }
}

int AwardWinners :: ReadFile(string filename)
{
   ifstream file;
   file.open(filename); 
   string line;
   string array[2];
   int i = 0;
   int value;
   
   if (file.is_open())
   {
     while (getline(file, line))
     {
       split(line, '@', array, 2);
       year[i] = stoi(array[1]);
       name[i] = array[0];
       i++;
     }
     value = 0;
   }
   else 
   {
     value = -1;
   }
   file.close();
   
   return value;
}

string AwardWinners :: getWinnerName(int winningYear)
{
  string names = "";
  
  for (int i = 0; i < 20; i++)
  {
    if (year[i] == winningYear)
    {
      names = name[i];
      break;
    }
  }
  
  return names;
}

int AwardWinners :: getWinningYear(string winner)
{
  int years = -1;
  
  for (int i = 0; i < 20; i++)
  {
    if (name[i] == winner)
    {
      years = year[i];
      break;
    }
  }
  
  return years;
}