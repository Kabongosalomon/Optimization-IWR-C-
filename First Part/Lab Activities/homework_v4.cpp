#include <iostream>
#include <cmath>


int main(){
/*
 * This function shows the efficient way to compute q^n
 * using this technique : q^n:=(q^2)^(n/2)
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
