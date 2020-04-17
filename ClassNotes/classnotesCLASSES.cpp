#include "cashregister.h"

CashRegister::CashRegister()
{
   clear();
}

void CashRegister::clear()
{
   item_count = 0;
   total_price = 0;
}

void CashRegister::add_item(double price)
{
   item_count++;
   total_price = total_price + price;
}

double CashRegister::get_total() const
{
   return total_price; 
}

int CashRegister::get_count() const
{
   return item_count; 
}



#ifndef CASHREGISTER_H
#define CASHREGISTER_H

/**
   A simulated cash register that tracks the item count and
   the total amount due.
 */
class CashRegister
{
public:
   /**
      Constructs a cash register with cleared item count and total.
   */
   CashRegister();

   /**
      Clears the item count and the total.
   */
   void clear();

   /**
      Adds an item to this cash register.
      @param price the price of this item
   */
   void add_item(double price);

   /**
      @return the total amount of the current sale
   */
   double get_total() const;

   /**
      @return the item count of the current sale
   */
   int get_count() const;

private:
   int item_count;
   double total_price;
};

#endif


//set of objects with the same behavior 
//you must specify the behavior