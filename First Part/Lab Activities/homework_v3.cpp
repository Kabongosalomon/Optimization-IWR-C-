#include <iostream>
#include <cmath>

using namespace std;

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
	   return pow(q,n/2)*pow(q,n/2); 
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
   	
   cout<<"Enter a number: ";
   cin>>num;

   cout<<"Enter the power: ";
   cin>>power;

   cout<<num<<"^"<<power<<" = "<<f_v2(num,power);
   return 0;
}
