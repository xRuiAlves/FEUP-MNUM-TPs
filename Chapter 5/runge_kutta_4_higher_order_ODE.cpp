#include <iostream>
#include <cmath>

double f1 (double x , double y , double z){ return (x+y); }

double f2 (double x , double y , double z){ return (z); }

int main(){
	/* Initial conditions */
	const double x0 = 1;
	const double y0 = 1;
	const double z0 = 1;
	const unsigned int n = 40;	// Number of iterations
	double step = 0.1;

	std::cout << std::fixed;
	std::cout.precision(6);


	/* Useful Variables */
	double x = x0;
	double y = y0;
	double z = z0;
	double xn , yn , zn;
	double d1 , d2 , d3 , d4 , l1 , l2 , l3 , l4;


	/* Print the values in (x0 , y0) */
	std::cout << "X = " << x << "   -->   Y = " << y << '\n';


	/* Perform the method */
	for (unsigned int i=0 ; i<n ; i++){
		/* Compute the increments */
		d1 = step*f1(x,y,z);
		l1 = step*f2(x,y,z);

		d2 = step*f1(x+step/2 , y + d1/2 , z + l1/2);
		l2 = step*f2(x+step/2 , y + d1/2 , z + l1/2);

		d3 = step*f1(x+step/2 , y + d2/2 , z + l2/2);
		l3 = step*f2(x+step/2 , y + d2/2 , z + l2/2);

		d4 = step*f1(x+step , y + d3 , z + l3);
		l4 = step*f2(x+step , y + d3 , z + l3);

		/* Compute the new X and the new Y and the new Z */
		zn = z + (d1/6 + d2/3 + d3/3 + d4/6);
		yn = y + (l1/6 + l2/3 + l3/3 + l4/6);
		xn = x + step;

		x = xn;
		y = yn;
		z = zn;

		/* Print the function's value in X */
		std::cout << "X = " << x << "     |     Y = " << y << '\n';
	}
}
