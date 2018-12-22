#include <iostream>
#include <vector>
#include <cmath>
#include <chrono> 
#include <vector> // make vector available in your program


int printvec(std::vector<double> x)
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
int bigest_small(std::vector<int> x)
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

// (c')
std::vector<double> reverse(std::vector<double> x)
{
	/*This function return the reverse
	 * of a given vector
	 *
	 * By K. Salomon 20 December 2018.
	 */

	std::vector<double> temp(x.size());

	for (int i=x.size()-1;i>=0;i--)
	{
		temp[(x.size()-1)-i]=x[i];
	}
	return temp;
}

// (f)
std::vector<double> reverse_swap(std::vector<double> x)
{
	/* This function when given a vector
	 *
	 * return the same verctor with entries reverse 
	 *
	 * By K. Salomon 20 December 2018.
	 */

	int a1,b1;

	for (int i=0;i<x.size()/2;i++)
	{
		std::swap(x[i],x[(x.size()-1)-i]);
	}

	return x;
}


int main(int argc, char** argv)
{
	// a vector of 5 integers
	std::vector<double> v3(5);
	int a,b;

	for (int i=0; i<v3.size();i++)
	{
		std::cout<<"Enter "<<i+1<<" component ";
		std::cin>>v3[i];
	}

	// (d) Round number 
	for (int i=0;i<v3.size();i++)
		v3[i]=std::round(v3[i]);

	printvec(v3);

	// (e)
	v3=reverse_swap(v3);

	printvec(v3);


	// (f)
	//std::cout<<"Please give element you want to swap separated by a space, make sure that there are in your vector ";
	//std::cin>>a,b;

	//v3=swap_ab(v3,1,5);
	//printvec(v3);
	
}
