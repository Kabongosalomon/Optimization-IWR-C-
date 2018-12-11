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
   for (int i = 0 ; i < n ; ++i)
   {
	   value*=q;
   }
   cout<<"Result = "<<value;
   return 0;
}
