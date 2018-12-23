#include <iostream>
#include <cmath>
#include <exception>
#include "sstream"


// This help undle non positive exception
class myexception: public std::exception
{
  virtual const char* what() const throw()
  {
    return "Please this program undle only postive powers";
  }
} checksign;

// This help undle non integer exception
class myexception2: public std::exception
{
  virtual const char* what() const throw()
  {
    return "Please this program undle only base that are integer";
  }
} checkint;


// Question 3. (a)
int pow_iterative(int q, int n)
{
   /* This function computer q^n
    * using iteration. 
    *
    * Please note that The first codition is called the base condition, it is
    * very important to specify the base condition
    * in recursion, otherwise your program will throw
    * stack overflow error.
    *
    * By : Salomon K. 18-Dec-2018 AIMS SA
    */
   
   try 
   {
	   if (n<0)
		   throw checksign;
	   
	  if (std::cin.fail())
	  {
		  std::cout<<"Check you input please\n";
		  return 0;
	  }
   }
   catch(std::exception & e) 
   {
	   std::cout << e.what() << std::endl;
	   return 0;
   }
	
   int value=1;
   for (int i = 0 ; i < n ; ++i)
   {
	   value*=q;
   
   }
   
    
   
   return value;
}

// Question 3. (b)
int pow_recursive(int q, int n)
{
   /* This function computer q^n
    * using recursivity. 
    *
    * Please note that The first codition is called the base condition, it is
    * very important to specify the base condition
    * in recursion, otherwise your program will throw
    * stack overflow error.
    *
    * By : Salomon K. 12-Dec-2018 AIMS SA
    */
   
  try 
   {
	   if (n<0)
		   throw checksign;


	   if (std::cin.fail())
	  {
		  std::cout<<"Check you input please\n";
		  return 0;
	  }

   } catch(std::exception & e) 
   {
	   std::cout << e.what() << std::endl;
	   return 0;
   }

   if (n == 0)
        return 1;
   else
	return pow_recursive(q,n-1)*q;
}

// Question 3. (c)
int pow_iterative_eff(int q, int n){

   /* This function computer q^n
    * using a loop in an eficient way. 
    *
    * Please note that The first codition is called the base condition, it is
    * very important to specify the base condition
    * in recursion, otherwise your program will throw
    * stack overflow error.
    *
    * By : Salomon K. 18-Dec-2018 AIMS SA
    */
   
   try 
   {
	   if (n<0)
		   throw checksign;

	   if (std::cin.fail())
	  {
		  std::cout<<"Check you input please\n";
		  return 0;
	  }

   } catch(std::exception & e) 
   {
	   std::cout << e.what() << std::endl;
	   return 0;
   }


   int value=1;

 
   while(n>0)
   {
	   if(n%2!=0)
	   {
		   value*=q;
		   n--;
	   }
	   q *= q;
	   n /= 2;  
   }

   return value; 
}




int main(){
 
   int q;
   int n;

   std::cout<<"Enter a number q: ";
   std::cin>>q;

	  
   std::cout<<"Enter the power n: ";	   
   std::cin>>n;

   std::cout<<q<<"^"<<n<<" (iterative)="<<pow_iterative(q, n)<<std::endl;  
   std::cout<<q<<"^"<<n<<" (recursive)="<<pow_recursive(q, n)<<std::endl;
   std::cout<<q<<"^"<<n<<" (iterative_efficient)="<<pow_iterative_eff(q, n)<<std::endl;
   
   return 0;
}
