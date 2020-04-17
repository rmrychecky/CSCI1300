#include <iostream>
using namespace std;

class Coffee 
{
private:

  string roastType;
  float temp = 180.0;

public: //set each function with their perspective input types

  Coffee();
  
  Coffee(string r, float t);
  
  void setRoastType(string r);
  
  string getRoastType();
  
  void setTemp(float t);
  
  float getTemp();
  
  string drinkability();
  
};

Coffee :: Coffee()
{
  roastType = "";
  temp = 180.0;
}

Coffee :: Coffee(string r, float t)
{
  roastType = r;
  temp = t;
}

void Coffee :: setRoastType(string r)
{
  roastType = r;
}

string Coffee :: getRoastType()
{
  return roastType;
}

void Coffee :: setTemp(float t)
{
  temp = t;
}

float Coffee :: getTemp()
{
  return temp;
}

string Coffee :: drinkability()
{
  string statement;
  if (temp <  100.0)
  {
    statement = "Too Cold";
  }
  else if (temp >= 100 && temp < 160)
  {
    statement = "Just Right";
  }
  else if (temp >= 160 & temp < 180)
  {
    statement = "Hot";
  }
  else
  {
    statement = "Too Hot";
  }
  return statement;
}