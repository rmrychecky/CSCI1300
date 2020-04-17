 void LeavesPerTree (double poundsofleaves)
 {
  double leaves = poundsofleaves / .001;
  double lpert = leaves / 1031.0;
  if (lpert > 10000)
  {
   cout << lpert << endl;
   cout << "More leaves than last year" << endl;
  }
  if (lpert <= 10000)
  {
   cout << lpert << endl;
  }

 }