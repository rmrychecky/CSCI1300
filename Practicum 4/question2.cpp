#include <iostream>
using namespace std;

class Hurricane 
{
private:

  string name;
  float speed;

public: //set each function with their perspective input types

  Hurricane();
  
  Hurricane(string n, float s);
  
  void setName(string n);
  
  string getName();
  
  void setSpeed(float s);
  
  float getSpeed();
  
  int category();
  
};

Hurricane :: Hurricane()
{
  name = "";
  speed = 0.0;
}

Hurricane :: Hurricane(string n, float s)
{
  name = n;
  speed = s;
}

void Hurricane :: setName(string n)
{
  name = n;
}

string Hurricane :: getName()
{
  return name;
}

void Hurricane :: setSpeed(float s)
{
  speed = s;
}

float Hurricane :: getSpeed()
{
  return speed;
}

int Hurricane :: category()
{
  int categoryValue = 0;
  if(speed <= 74)
  {
    categoryValue = 0;
  }
  else if(speed > 74 && speed <= 95)
  {
    categoryValue = 1;
  }
  else if(speed >= 96 && speed <= 110)
  {
    categoryValue = 2;
  }
  else if(speed >= 111 && speed <= 129)
  {
    categoryValue = 3;
  }
  else if(speed >= 130 && speed <= 156)
  {
    categoryValue = 4;
  }
  else if(speed >= 157)
  {
    categoryValue = 5;
  }
  
  return categoryValue;
}