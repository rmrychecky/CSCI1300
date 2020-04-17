#include <iostream>
#include <string>
using namespace std;

// int main()
// {
//     //declaration and initialization at the same time
//     string str1 = "Vile";
//     string str2 = "plume";
//     string str3 = "Gloom";
//     int len1;
//     string str4, str5;
    
//     //str4 = "Vile" + "plume"; // not allowed; instead = "Vileplume"
    
//     str5 = " "; // a space
//     str4 = "Vile" + str5 + "plume"; // allowed
    
//     //instead, + combines strings one and two with no white space in between
//     str4 = str1 + str2; //concatenate
//     cout << "New string reads " << str4 << endl << endl;
//     len1 = str4.length(); //length function
//     cout << "The length of the string is: "<< len1 << endl << endl;
//     str5 = str3; //reassignment
//     cout << "New string reads " << str5 << endl << endl;

//     //referencing different characters in the string
//     cout << "str1[0] reads " << str1[0] << endl << endl; //index 0 is 1st letter
//     cout << "str1[1] reads " << str1[1] << endl << endl; //index 1 is 2nd letter
//     cout << "str1[2] reads " << str1[2] << endl << endl;
//     cout << "str1[3] reads " << str1[3] << endl << endl;
//     cout << "str1[4] reads " << str1[4] << endl << endl; //index 4 is outside str1
//     cout << "str1[5] reads " << str1[5] << endl << endl; //index 5 is outside str1

//     return 0;
// }

// int main() 
// {
//   string str = "jaldskjfoei";
   
//   for (int i = 0; i < str.length(); i++)
//   {
//       cout << "str[0] reads " << str[i] << endl;
//   }
//   return 0;
// }

//HOW MANY CHARACTER 'A' ARE IN A STRING

// int countAs(string s)
// {
//     int count = 0;
//     if (s.length() == 0)
//     {
//         return -1;
//     }
//     else 
//     {
        
//         for (int i = 0; i < s.length(); i++)
//         {
//              if (s[i] == 'A')
//             {
//                 count++;
//             }
       
//         }
  
//     }
//      return count;
    
// }

// int main() 
// {
//   string str = "";
//   cout << countAs(str);
//   return 0;
// }

//HOW MANY CHARACTER 'A', 'B', 'C' s ARE IN A STRING

// int countAs(string s)
// {
//     int count = 0;
//     if (s.length() == 0)
//     {
//         return -1;
//     }
//     else 
//     {
        
//         for (int i = 0; i < s.length(); i++)
//         {
//              if (s[i] >= 'A' && s[i] <= 'C') //uses values from the ASCII table 
//             {
//                 count++;
//             }
       
//         }
  
//     }
//     return count;
    
// }

// int main() 
// {
//   string str = "ASDFBBBCCCClalkjsdf adsf 1234";
//   cout << countAs(str);
//   return 0;
// }

//EMAIL Example

// int main()
// {
//     string email;
    
//     cout << "Enter your email ID: ";
//     cin >> email;
    
//     bool flag = false;
//     int i = 0;
//     string s;
//     int index = -1;
    
//     // for loop equivalent
//     for(i=0; i < email.length(); i++)
//     {
//         s = email.substr(i,1);
//         if (s == "@")
//         {
//             index = i;
//             flag = true;
//         }
//     }
//     if (flag == true)
//     {
//         cout << "You have mail!!!";
//     }
//     else
//     {
//         cout << "Invalid input";
//     }

//     return 0;
// }
    
 //email with substring    

int main()
{
    string email = "io@edu.com";
    bool flag = false;
    int i = 0;
    string mySubstring;

    string lookup = ".com";     // look for ".com"

    for(i=0; i < email.length() - lookup.length() + 1; i++)
    {
        mySubstring = email.,lookup.length());
        if (mySubstring == lookup)
        {
            flag = true;
        }
    }
    if (flag == true)
    {
        cout << "You have mail!!!";
    }
    else
    {
        cout << "Invalid input";
    }

    return 0;
}