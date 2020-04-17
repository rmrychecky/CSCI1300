#include <iostream>
using namespace std;

class Textbook 
{
private:

  string title;
  int pages;
  Float cost;
  bool online;

public: //set each function with their perspective input types

  Textbook();
  
  Textbook(string t, int p, float c, bool o);
  
  void setTitle(string t);
  
  string getTitle();
  
  void setPages(int p);
  
  int getPages();
  
  void setCost(float c);
  
  float getCost();
  
  void setOnline(bool o);
  
  bool getOnline();
  
  float costPerPage();
  
};