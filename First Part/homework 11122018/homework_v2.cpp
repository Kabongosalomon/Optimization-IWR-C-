#include <iostream>
#include <cmath>

using namespace std;


int main(){
   int q;
   int n;
   int value=1;
   	
   cout<<"Enter a number: ";
   cin>>q;

   cout<<"Enter the power: ";
   cin>>n;
   while (n>=0)
   {
	   value*=pow(q,n);
	   n--;
   }
   cout<<"Result = "<<value;
   return 0;
}
