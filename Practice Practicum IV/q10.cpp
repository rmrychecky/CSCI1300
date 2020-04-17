#include <iostream>
using namespace std;

class Probability  
{
private:

  float prob_values[50];
  string event[50];

public: //set each function with their perspective input types

  Probability();
  
  void ReadFile(string filename);
  
  string getMostLikelyEvent(float value);
  
};

Probability :: Probability()
{
  for (int i = 0; i < 50; i++)
  {
    prob_values[i] = 0.0;
    event[i] = "";
  }
}

void Probability :: ReadFile(string filename)
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
       prob_values[i] = stof(array[1]);
       event[i] = array[0];
       i++;
     }
   }
   file.close();
}

string Probability :: getMostLikelyEvent(float value)
{
    float likely;
    string mostLikelyEvent;
    for (int i = 0; i < 50; i++)
    {
        if (prob_values[i] >= value)
        {
            mostLikelyEvent = event[i];
            return mostLikelyEvent;
        }
        else 
        {
            mostLikelyEvent = "";
        }
    }
    return mostLikelyEvent;
}
