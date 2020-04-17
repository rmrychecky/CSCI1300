#include <iostream>
using namespace std;

class Temperatures  
{
private:

  float temp_values[7];
  string days[7];

public: //set each function with their perspective input types

  Temperatures();
  
  void ReadFile(string filename);
  
  float getMinTemp();
  
  string getMinTempDay();
  
};

Temperatures :: Temperatures()
{
  for (int i = 0; i < 7; i++)
  {
    temp_values[i] = 120.0;
    days[i] = "";
  }
}

void Temperatures :: ReadFile(string filename)
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
       temp_values[i] = stof(array[1]);
       days[i] = array[0];
       i++;
     }
   }
   file.close();
}

float Temperatures :: getMinTemp()
{
    float minTemp = 0;
    
    for (int i = 0; i < 7; i++)
    {
        if (temp_values[i] <= minTemp)
        {
            minTemp = temp_values[i];
        }
    }
    return minTemp;
}

string Temperatures :: getMinTempDay()
{
    string minTempDay;
    float minTemp = 0;
    minTemp = getMinTemp();
    for (int i = 0; i < 7; i++)
    {
        if (temp_values[i] == minTemp)
        {
            minTempDay = days[i];
        }
    }
    if (minTempDay == "1")
    {
        minTempDay = "Sunday";
    }
    else if (minTempDay == "2")
    {
        minTempDay = "Monday";
    }
    else if (minTempDay == "3")
    {
        minTempDay = "Tuesday";
    }
    else if (minTempDay == "4")
    {
        minTempDay = "Wednesday";
    }
    else if (minTempDay == "5")
    {
        minTempDay = "Thursday";
    }
    else if (minTempDay == "6")
    {
        minTempDay = "Friday";
    }
    else if (minTempDay == "7")
    {
        minTempDay = "Saturday";
    }
    
    return minTempDay;
}