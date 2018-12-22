#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
 
// (a)
double root_iterative(double q, int n, int steps)
{
	/* This functon calculate approximation of 
	 * q^(1/n), here steps is the number of steps
	 * calculated by the program.
	 */

	double a;
	double ak=1;
	
	for (int i=0; i<steps;++i)
	{
	a=ak+(1.0/n)*(q/(pow(ak,n-1))-ak);	
	ak=a;
	}
	return a;
}

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


double pow_iterative_eff(double q, int n){

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
   } catch(std::exception & e) 
   {
	   std::cout << e.what() << std::endl;
	   return 0;
   }


   double value=1;

 
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



// (b)
double root_iterative_b(double q, int n, int steps)
{
	/* This functon calculate approximation of 
	 * q^(1/n), here steps is the number of steps
	 * calculated by the program. 
	 *
	 * Please note : (We are using a more efficient way to compute a^(n-1)
	 * 		using our previous function pow_iterative modified version.
	 *
	 * By K. Salomon 21 Dec 20118.
	 */

	double a;
	double ak=1;
	
	for (int i=0; i<steps;++i)
	{
	a=ak+(1.0/n)*(q/(pow_iterative_eff(ak,n-1))-ak);
	ak=a;
	}
	return a;
}

// (c) 
void test_root(double q, int n, int steps)
{
	/* A function that tests the accuracy of my calculation 
	 *
	 *
	 * By K. Salomon 21 Dec 20188
	 */

	double a_=root_iterative_b(q,n,steps);
	double a_n=pow_iterative_eff(a_,n);


	std::cout<<"q ="<<q<<", n ="<<n<<", a_ ="<<a_<<", a_^n ="<<a_n<<", (q-a_^n) ="<<(q-a_n)<<std::endl;

}

int main()
{
	double q;
	int n,steps;

	std::cout<<"input q :";
	std::cin>>q;

	std::cout<<"input n :";
	std::cin>>n;

	std::cout<<"input steps :";
	std::cin>>steps;


	test_root(q, n, steps);
	std::cout<<root_iterative_b(q, n, steps)<<std::endl;

}
