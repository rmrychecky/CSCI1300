#include <iostream>
using namespace std;

class InvestmentProfile 
{
private:

  string companyName;
  float sharesHeld;

public: //set each function with their perspective input types

  InvestmentProfile();
  
  InvestmentProfile(string c, float s);
  
  void setCompanyName(string c);
  
  string getCompanyName();

  void setSharesHeld(float s);
  
  float getSharesHeld();
  
  string influence();
  
};

InvestmentProfile :: InvestmentProfile()
{
  companyName = "Company co.";
  sharesHeld = 100.0;
}

InvestmentProfile :: InvestmentProfile(string c, float s)
{
  companyName = c;
  sharesHeld = s;
}

void InvestmentProfile :: setCompanyName(string c)
{
  companyName = c;
}

string InvestmentProfile :: getCompanyName()
{
  return companyName;
}

void InvestmentProfile :: setSharesHeld(float s)
{
  sharesHeld = s;
}

float InvestmentProfile :: getSharesHeld()
{
  return sharesHeld;
}

string InvestmentProfile :: influence()
{
  string statement;
  if (sharesHeld <  50.0)
  {
    statement = "Minority Shareholder";
  }
  else if (sharesHeld >= 50.0 && sharesHeld < 100.0)
  {
    statement = "Majority Shareholder";
  }
  else if (sharesHeld >= 100.0)
  {
    statement = "Sole Shareholder";
  }
  return statement;
}
