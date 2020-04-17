string DayOfWeek (int dayofweek)
 {
  switch (dayofweek) 
       {
           case 1:
                return "MONDAY";
                break;
           case 2:
                return "WORKDAY";
                break;
           case 3:
                return "WORKDAY";
                break;
           case 4:
                return "WORKDAY";
                break;     
           case 5:
                return "FUNDAY";
                break;
           case 0:
                return "SLEEPDAY";
                break;
           case 6:
                return "SLEEPDAY";
                break;     
           default:
                return "INVALID";
       }

 }