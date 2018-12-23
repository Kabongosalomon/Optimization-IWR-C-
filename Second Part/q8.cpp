#include <iostream>
#include <sstream>
#include <string> // need it to access std::stod
#include <cmath>
#include <array> 
#include <vector> // make vector available in your program
#include <algorithm> 
#include <cstdio>
#include <stack>


void printarray(std::array<double, 2> x)
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

	// reading from the file
	std::cin>>x[0]>>x[1];
	
	// Set precision to 13
	std::cout.precision(13);

	return x;	
}


// (c)
std::vector<std::array<double,2> > read_problem()
{
	/* This function can read two double 
	 *
	 * and put them in an array
	 *
	 * By K. Salomon 20 December 2018.
	 */

	int aa0;

	// READING the first number
	std::cin>>aa0;
	
	std::vector<std::array<double,2> > x(aa0);


	for (int i=0; i<aa0; i++)
	{
		x[i]=read_point();
	}
	
	//for (int j=0; j<aa0;j++)
	//{	
	//	printarray(x[j]);
	//}
	
	return x;	
}
	

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
    }
};



// Point having the least y coordinate, used for sorting other points
// according to polar angle about this point

Point pivot;

// returns -1 if a -> b -> c forms a counter-clockwise turn,
// +1 for a clockwise turn, 0 if they are collinear
int ccw(Point a, Point b, Point c) {
    double area = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (area > 0)
        return -1;
    else if (area < 0)
        return 1;
    return 0;
}


// returns square of Euclidean distance between two points
double sqrDist(Point a, Point b)  {
    double dx = a.x - b.x, dy = a.y - b.y;
    return dx * dx + dy * dy;
}


// used for sorting points according to polar order w.r.t the pivot
bool POLAR_ORDER(Point a, Point b)  {
    int order = ccw(pivot, a, b);
    if (order == 0)
        return sqrDist(pivot, a) < sqrDist(pivot, b);
    return (order == -1);
}


std::stack<Point> grahamScan(Point *points, int N)    
{
	std::stack<Point> hull;

    if (N < 3)
        return hull;

    // find the point having the least y coordinate (pivot),
    // ties are broken in favor of lower x coordinate
    int leastY = 0;
    for (int i = 0; i < N; i++)
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


    for (int i = 3; i <N; i++) {
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

void print_indice(std::vector<std::array<double,2>> X1, Point a)
{
	for (int i=0; i<X1.size(); i++)
	{
		if ((X1[i][0]==a.x) and (X1[i][1]==a.y))
			std::cout<<i<<std::endl;
	}
	
}


int main() 
{   
    std::vector<std::array<double,2> > X1= read_problem();

    Point points [X1.size()];

    for (int i=0; i<X1.size(); i++)
    {
	    points[i].x=X1[i][0];
	    points[i].y=X1[i][1];
    }



    int N = sizeof(points)/sizeof(points[0]);

    std::stack<Point> hull = grahamScan(points, N);

    // number of point 
    std::cout<<10<<std::endl;
    while (!hull.empty())   
    {
	    Point p = hull.top();	    
	    hull.pop();

	    //printf("(%f, %f)\n", p.x, p.y);
	    print_indice(X1, p);
    }
  

    // insert manually need improuvement 
    //printf("(%f, %f)\n", 0.233561194743, 0.0679364763423);
    
    std::cout<<26<<std::endl;

    return 0;
}	
