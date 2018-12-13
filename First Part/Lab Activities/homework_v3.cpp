#include <iostream>
#include <cmath>

//Power function  a more eﬃcient recursive implementation
int f_v1(int q, int n){
   /* This is called the base condition, it is
    * very important to specify the base condition
    * in recursion, otherwise your program will throw
    * stack overflow error.
    */
   if (n == 0)
        return 1;
   else if(n%2==0)
	   return  std::pow(q,n/2)*pow(q,n/2); 
   else
	return f_v1(q,n-1)*q;
}

// I like this version 
int f_v2(int q, int n){
   /* This is called the base condition, it is
    * very important to specify the base condition
    * in recursion, otherwise your program will throw
    * stack overflow error.
    */
   if (n == 0)
        return 1;
   else if(n%2==0)
	   return f_v2(pow(q,2),n/2); 
   else
	return f_v2(q,n-1)*q;
}

int main(){
   int num;
   int power;
   	
   std::cout<<"Enter a number: ";
   std::cin>>num;

   std::cout<<"Enter the power: ";
   std::cin>>power;

   //time_point begin = now();
   
   std::cout<<num<<"^"<<power<<" = "<<f_v2(num,power);
   
   //time_point end= now();
   
   //print_time("Speed :",begin,end);
   return 0;
}
