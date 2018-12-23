#include <iostream>
#include <vector>
#include <cmath>
#include <chrono> 
#include <vector> // make vector available in your program


int printvec(std::vector<int> x)
{
	/* This function just help 
	 * to print a vector, element by element in 
	 * a user friendly way
	 *
	 * By K. Salomon 20 December 2018.
	 */

	std::cout<<"[";
	for (int i=0;i<x.size()-1;i++)
		std::cout<<x[i]<<", ";
	std::cout<<x[x.size()-1]<<"]"<<std::endl;
	return 0;	
}

// (b)
int smallest_biggest(std::vector<int> x)
{
	/* This function calculate and 
	 * print on the stard output 
	 * the smallest and the biggest value of
	 * a vector given in paramter
	 *
	 * By K. Salomon 20 December 2018.
	 */

	int smal, big;
	smal=x[0];
	big=x[0];

	for (int i:x)
	{
		// smal=i;
		if(i<smal)
		{
			smal=i;
		}

		if(i>big)
		{
			big=i;
		}
	}
	std::cout<<"Smallest "<<smal<<std::endl;

	std::cout<<"Biggest "<<big<<std::endl;
}

// (c)
std::vector<int> reverse(std::vector<int> x)
{
	/*This function return the reverse
	 * of a given vector
	 *
	 * By K. Salomon 20 December 2018.
	 */

	std::vector<int> temp(x.size());

	for (int i=x.size()-1;i>=0;i--)
	{
		temp[(x.size()-1)-i]=x[i];
	}
	return temp;
}


int main(int argc, char** argv)
{
	// a vector of 10 integers
	std::vector<int> v1(10);

	for (int i=0; i<9;i++)
	{
		std::cout<<"Enter "<<i+1<<" component ";
		std::cin>>v1[i];
	}

	for (int i:v1)
	{
		std::cout<<i<<std::endl;
	}

	smallest_biggest(v1);


	//std::cout<<"Size of v1: "<<v1.size()<<std::endl;
	printvec(v1);

	printvec(reverse(v1));

	std::vector<double> v3={2.11, 3.6, 44.1, 4.8, 1.9, 0.7};
	for (int i=0;i<v3.size();i++)
		v3[i]=std::round(v3[i]);

	for(int i:v3)
		std::cout<<i<<" ";


// a) Entries have 0 as value

// an empty vector of integers
// std::vector<int> v1;
// a vector with entries 3, 8, 7, 5, 9, 2
// std::vector<int> v3 = {3, 8, 7, 5, 9, 2};
}
