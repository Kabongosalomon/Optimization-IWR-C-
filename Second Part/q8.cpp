#include <iostream>
#include <sstream>
#include <string> // need it to access std::stod
#include <cmath>
#include <array> 
#include <vector> // make vector available in your program
#include <algorithm> 
#include <cstdio>
#include <stack>



//=======================================================================================================/

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

// (c)
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

	// Geting the first number
	std::cin>>a0;
	// Convert in int 
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


std::array<double, 2> find_minimum(std::vector<std::array<double, 2>> x)
{
	std::array<double, 2> min_array;

	double min=x[0][1];

	for (int i=0; i<x.size(); i++)
	{
		if(x[i][1]<min)
		{
			min = x[i][1];
			min_array = x[i];
		}
	}
	return min_array;
	
}

//=======================================================================================================/

// Creating a class to deal with the structure of points
class Point 
{
public:
    double x, y;

    // comparison is done first on y coordinate and then on x coordinate
    bool operator < (Point b) {
        if (y != b.y)
            return y < b.y;
        return x < b.x;
    };


};



// Point having the least y coordinate, used for sorting other points
// according to polar angle about this point

Point pivot;
// std::array<double, 2> pivot;

// returns -1 if a -> b -> c forms a counter-clockwise turn,
// +1 for a clockwise turn, 0 if they are collinear
int ccw(Point a, Point b, Point c) {
    int area = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (area > 0)
        return -1;
    else if (area < 0)
        return 1;
    return 0;
}

int direction(std::array<double, 2> x, std::array<double, 2> y, std::array<double, 2> z){
	int area = (y[0]-x[0])*(z[1]-x[1]) - (y[1]-x[1])*(z[0]-x[0]);
	if (area > 0)
		return -1;
	else if (area < 0)
		return 1;
	return 0;
}

// returns square of Euclidean distance between two points
int sqrDist(Point a, Point b)  {
    int dx = a.x - b.x, dy = a.y - b.y;
    return dx * dx + dy * dy;
}

int Dist(std::array<double, 2> x, std::array<double, 2> y)
{
	return (x[0]-y[0])*(x[0]-y[0])+(x[1]-y[1])*(x[1]-y[1]);
}

// used for sorting points according to polar order w.r.t the pivot
bool POLAR_ORDER(Point a, Point b)  {
    int order = ccw(pivot, a, b);
    if (order == 0)
        return sqrDist(pivot, a) < sqrDist(pivot, b);
    return (order == -1);
}

//bool polar_order(std::array<double, 2> x, std::array<double, 2> y)
//{
//	int order= direction(pivot, x, y);
//	if (order == 0)
//		return Dist(pivot, x) < Dist(pivot, y);
//	return (order == -1);
//}



//std::stack<std::array<double,2>> grahamScan_(std::vector<std::array<double, 2>> *points, int N)    
//{
//    std::stack<std:array<double, 2>> hull;
//
//    if (N < 3)
//        return hull;
//
//    // find the point having the least y coordinate (pivot),
//    // ties are broken in favor of lower x coordinate
//    int leastY = 0;
//    for (int i = 1; i < N; i++)
//        if (points[i][1] < points[leastY])
//            leastY = i;
//
//    // swap the pivot with the first point
//    std::array<double,2> temp = points[0];
//    points[0] = points[leastY];
//    points[leastY] = temp;
//
//    // sort the remaining point according to polar order about the pivot
//    pivot = points[0];
//    std::sort(points + 1, points + N, polar_order);
//
//    hull.push(points[0]);
//    hull.push(points[1]);
//    hull.push(points[2]);
//
//    for (int i = 3; i < N; i++) {
//	    std::array<double,2> top = hull.top();
//        hull.pop();
//        while (direction(hull.top(), top, points[i]) != -1)   {
//            top = hull.top();
//            hull.pop();
//        }
//        hull.push(top);
//        hull.push(points[i]);
//    }
//    return hull;
//}

std::stack<Point> grahamScan(Point *points, int N)    {
	std::stack<Point> hull;

    if (N < 3)
        return hull;

    // find the point having the least y coordinate (pivot),
    // ties are broken in favor of lower x coordinate
    int leastY = 0;
    for (int i = 1; i < N; i++)
        if (points[i] < points[leastY])
            leastY = i;

    // swap the pivot with the first point
    Point temp = points[0];
    points[0] = points[leastY];
    points[leastY] = temp;

    // sort the remaining point according to polar order about the pivot
    pivot = points[0];
    std::sort(points + 1, points + N, POLAR_ORDER);

    hull.push(points[0]);
    hull.push(points[1]);
    hull.push(points[2]);

    for (int i = 3; i < N; i++) {
        Point top = hull.top();
        hull.pop();
        while (ccw(hull.top(), top, points[i]) != -1)   {
            top = hull.top();
            hull.pop();
        }
        hull.push(top);
        hull.push(points[i]);
    }
    return hull;
}



int main()  {
    
    std::vector<std::array<double,2>> X1= read_problem();


    //Point points[]={{2, 0}, {3, 2}, {5, 2}, {4, 4}, {1, 3}};
    Point points [X1.size()];

    for (int i=0; i<X1.size(); i++)
    {
	    points[i].x=X1[i][0];
	    points[i].y=X1[i][1];
    }


	//Point points[4];

	//points[0]={0,0};

	//points[1]={1,1};
	
	//points[2]={2,2};
		
	//points[3]={3, -1};

   
    //std::vector<std::array<double, 2>> points;

    //points=read_problem();

    int N = sizeof(points)/sizeof(points[0]);

    // std::stack<std::array<double,2>> hull = grahamScan(points, N);


    std::stack<Point> hull = grahamScan(points, N);


    while (!hull.empty())   
    {
	    //std::array<double, 2> p = hull.top();

	    Point p = hull.top();

	    
	    hull.pop();

        printf("(%f, %f)\n", p.x, p.y);
    }

    //std::vector<std::array<double, 2>> x = read_problem();

    //double min = x[0][1];
	
	
    // Step one Algo
	
    //std::cout<<"Point with the lowest y-coordinate ";

    //printarray(find_minimum(x));

    return 0;
}
	
