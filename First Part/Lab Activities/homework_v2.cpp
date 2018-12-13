#include <iostream>
#include <cmath>

int main(){
  /* This function computer q^n
    * using iterativilly. 
    *
    * Please note that The first codition is called the base condition, it is
    * very important to specify the base condition
    * in recursion, otherwise your program will throw
    * stack overflow error.
    *
    * By : Salomon K. 12-Dec-2018 AIMS SA
    */

   int q;
   int n;
   int value=1;
   	
   std::cout<<"Enter a number: ";
   std::cin>>q;

   std::cout<<"Enter the power: ";
   std::cin>>n;
   for (int i = 0 ; i < n ; ++i)
   {
	   value*=q;
   }
   std::cout<<"Result = "<<value;
   return 0;
}
