 double PizzaParty (int numberOfPizzas, double costPerPizza, double discount)
 {
     double totalcost;
     if (numberOfPizzas < 10)
     {
        totalcost = (numberOfPizzas * costPerPizza) + 10;
     }
     if (numberOfPizzas >= 10)
     {
         totalcost = numberOfPizzas * (costPerPizza - (discount * costPerPizza));
     }
     return totalcost;
 }