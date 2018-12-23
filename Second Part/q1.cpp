#include <iostream>
#include <cmath>


// Definition of our function 
int collatz_sequence(int x){
	
	/* This function implement the Callatz problem 
	 * 
	 * By : Salomon K. 16-Dec-2018 AIMS SA
	 */
	
	std::cout<<"["<<x<<", ";

	while (x>0)
	{
		if (x%2==0)
		{
			x/=2;
		}

		else
		{
			if(x>1)
		{
			x = 3*x+1;
		}
		}

		if (x==1)
		{
			std::cout << x <<"]\n";
			return 0;
		}
		
		std::cout << x <<", ";
	}

	return 0;
}

// Running of the main program 
int main(){
 
	int number;
     	
	std::cout<<"Enter a number: ";
	std::cin>>number;
 
	// Call to our function
	collatz_sequence(number);
   
	return 0;
}
