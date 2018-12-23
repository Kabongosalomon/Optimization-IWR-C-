#include <iostream>
#include <cmath>


// Definition of our function 
bool isPrime(int number){
	
	/* This function implement the Callatz problem 
	 * 
	 * By : Salomon K. 16-Dec-2018 AIMS SA
	 */

	if (number== 0 || number==1)
	{
		return 0;
	}

	for(int i = 2; i <= number / 2; ++i)
	{
		if(number % i == 0)
		{
			return false;
		} 
	}

	return true;
}

void printPrimes(int upto)
{
	/*This function return the number of prime number upto a given number 
	 * using an other define function isPrime
	 *
	 * By : Salomon K. 18 Dec 2018
	 */

	std::cout<<"[";
	for (int i = 2; i<=upto; ++i)
	{
		if (isPrime(i))
		{
			std::cout<<i<<" ";
		}
	}
	
	std::cout<<"]";
	
	return ;
}

// Running of the main program 
int main(){
 
	int number;
     	
	std::cout<<"Enter a number: ";
	std::cin>>number;
 
	// Call to our function
  
	printPrimes(number);

	return 0;
}
