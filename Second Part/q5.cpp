#include <iostream>
#include <vector>
#include <numeric>
#include <chrono>
 

double fa(double x)
{
	if (x>=0 && x<0.5)
	{
		return 2*x;
	}
	else
	{
		return 2-2*x;
	}
}

double fb(double x)
{
	if (x>=0 && x<0.5)
	{
		return 1.999999*x;
	}
	else
	{
		return 1.999999*(1-x);
	}
}

int main()
{
	double x=0.01401;


	std::cout<<x<<std::endl;
	for (int i = 1; i<=100; ++i)
	{
		std::cout<<fb(x)<<std::endl;
		x=fb(x);
	}
	
}
