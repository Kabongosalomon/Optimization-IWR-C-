#include <iostream>
#include <sstream>
#include <string> // need it to access std::stod
#include <cmath>
#include <array> 
#include <vector> // make vector available in your program

int printarray(std::array<double, 2> x)
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
std::array<double, 2> read_point()
{
	/* This function can read two double 
	 *
	 * and put them in an array
	 *
	 * By K. Salomon 20 December 2018.
	 */
	std::array<double, 2> x;

	std::string a1, a2;

	// reading from the file
	std::cin>>a1>>a2;
	
	// Set precision to 13
	std::cout.precision(13);

	// Converte string to long double and put them in the array
	x[0]=std::stod(a1);
	x[1]=std::stod(a2);

	return x;	
}

std::vector<std::array<double,2>> read_problem()
{
	/* This function can read two double 
	 *
	 * and put them in an array
	 *
	 * By K. Salomon 20 December 2018.
	 */

	std::string a0;
	int aa0;


	std::cin>>a0;
	aa0=std::stoi(a0);
	
	std::vector<std::array<double,2>> x;
	
	for (int i=0; i<aa0; i++)
	{
		x.push_back(read_point());
	}
	
	for (int j=0; j<aa0;j++)
	{
		printarray(x[j]);
	}
	return x;	
}


int main()
{
	
	read_problem();




	return 0;
}

	
	
