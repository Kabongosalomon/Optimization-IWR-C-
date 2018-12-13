#include <iostream>
#include <cmath>

int f(int q, int n){

   /* This function computer q^n
    * using reccursivity. 
    *
    * Please note that The first codition is called the base condition, it is
    * very important to specify the base condition
    * in recursion, otherwise your program will throw
    * stack overflow error.
    *
    * By : Salomon K. 12-Dec-2018 AIMS SA
    */

   if (n == 0)
        return 1;
   else
	return f(q,n-1)*q;
}

int main(){
   int num;
   int power;
   	
   std::cout<<"Enter a number: ";
   std::cin>>num;

   std::cout<<"Enter the power: ";
   std::cin>>power;

   std::cout<<num<<"^"<<power<<" = "<<f(num,power);
   return 0;
}
