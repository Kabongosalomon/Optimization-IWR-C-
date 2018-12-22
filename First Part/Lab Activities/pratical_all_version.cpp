
#include <iostream>
#include <cmath>

#include <chrono>

// Normal Recursive
int f_rec(int q, int n){

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

   if (n == 0)
        return 1;
   else
	return f_rec(q,n-1)*q;
}

// Normal Iterative
int f_iter(int q, int n){

   /* This function computer q^n
    * using a loop. 
    *
    * Please note that The first codition is called the base condition, it is
    * very important to specify the base condition
    * in recursion, otherwise your program will throw
    * stack overflow error.
    *
    * By : Salomon K. 12-Dec-2018 AIMS SA
    */
   
   int value=1;

   for (int i = 0 ; i < n ; ++i)
   {
	   value*=q;
   }
   return value;
}

// Recursive Efficient 
int f_rec_effic_v1(int q, int n){
   /* This function computer q^n
    * using reccursivity, in an efficient way
    * version 1
    *
    * # q^n = q^(2k) = (q^k)^2
    * # q^n = q^(2k+1) = (q^k)^2
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
   {
	   int t= f_rec_effic_v1(q,n/2);
	   if(n%2==0)
	   return  t*t; 
   else
	return  q*t*t;
   }
}
// I like this version 
int f_rec_effic_v2(int q, int n){
   
   /* This function computer q^n
    * using reccursivity, in an efficient way
    * version 2
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
   else if(n%2==0)
	   return f_rec_effic_v2(pow(q,2),n/2); 
   else
	return f_rec_effic_v2(q,n-1)*q;
}


// Iterative Eficient 
int f_iter_eff(int q, int n){

   /* This function computer q^n
    * using a loop in an eficient way. 
    *
    * Please note that The first codition is called the base condition, it is
    * very important to specify the base condition
    * in recursion, otherwise your program will throw
    * stack overflow error.
    *
    * By : Salomon K. 12-Dec-2018 AIMS SA
    */
   
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





void print_time(std::string txt, std::chrono::steady_clock::time_point begin, std::chrono::steady_clock::time_point end){

std::cout << "Time difference "+txt+" = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() <<std::endl;

std::cout << "Time difference "+txt+" = "  << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() <<std::endl<<std::endl;

}

int main(){
 
   int q;
   int n;
     	
   std::cout<<"Enter a number: ";
   std::cin>>q;

   std::cout<<"Enter the power: ";
   std::cin>>n;
   
   // First Function 
   

   // record start time
   auto start = std::chrono::high_resolution_clock::now();
   // do some work    
   std::cout <<"Result Recurcive ="<< f_rec(q,n) <<std::endl;
   // record end time
   auto end = std::chrono::high_resolution_clock::now();
   std::chrono::duration<double> diff = end-start;     
   std::cout << "Rec_speed "<< diff.count() << " s\n\n";
 

   // Second Function
   
   // record start time
   start = std::chrono::high_resolution_clock::now();   
   // do some work 
   for (int i = 0 ; i < 100000000 ; ++i)
   {
	   f_iter(q,n);
   }
   std::cout<<"Result Iterative="<<f_iter(q,n)<<std::endl;
   // record end time
   end = std::chrono::high_resolution_clock::now();
   diff = end-start;     
   std::cout << "Iterat_speed "<< diff.count() << " s\n\n"; 
   

   // Third Function
   
   // record start time
   start = std::chrono::high_resolution_clock::now();
   std::cout <<"Result Rec Efficient V1 ="<< f_rec_effic_v1(q,n) <<std::endl;
   // record end time
   end = std::chrono::high_resolution_clock::now();
   diff = end-start;     
   std::cout <<"Rec_Ef_v1 speed "<< diff.count() << " s\n\n";
   
   // record start time
   start = std::chrono::high_resolution_clock::now();
   std::cout <<"Result Rec Efficient V2 ="<< f_rec_effic_v2(q,n) <<std::endl; 
   // record end time
   end = std::chrono::high_resolution_clock::now();
   diff = end-start;     
   std::cout <<"Rec_Ef_v2 speed "<< diff.count() << " s\n\n"; 


   // 4th Function
 
   // record start time
   start = std::chrono::high_resolution_clock::now();
   std::cout <<"Result Iterative Eficient = "<< f_iter_eff(q,n)<<std::endl;
   // record end time
   end = std::chrono::high_resolution_clock::now();
   diff = end-start;     
   std::cout <<"Iterative_Ef_speed "<< diff.count() << " s\n\n";

   return 0;
}
