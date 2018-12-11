#include <iostream>
#include <cmath>

using namespace std;

//Power function  a more eﬃcient recursive implementation
int f(int q, int n){
   /* This is called the base condition, it is
    * very important to specify the base condition
    * in recursion, otherwise your program will throw
    * stack overflow error.
    */
   if (n == 0)
        return 1;
   else
	return f(q,n-1)*q;
}
int main(){
   int num;
   int power;
   	
   cout<<"Enter a number: ";
   cin>>num;

   cout<<"Enter the power: ";
   cin>>power;

   cout<<num<<"^"<<power<<" = "<<f(num,power);
   return 0;
}
