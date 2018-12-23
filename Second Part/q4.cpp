#include <iostream>
#include <vector>
#include <numeric>
#include <chrono>

#include <iomanip>
#include <cmath>
#include <limits>

int main()
{
	float x;
	//double x;
	std::cout<<"enter you floating point :";
	std::cin>>x;

	//std::cout<<1+x;
	std::cout<<std::setw(11)<<std::setprecision(50)<<1+x;

	// a) 
	// 1E-8 is the smallest number for float 
	// 1E-16 is the smallest number for double
	//
	// b) There are not the smallest one for float resp. double
	
	return 0;
}
