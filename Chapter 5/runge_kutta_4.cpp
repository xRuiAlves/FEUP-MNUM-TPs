////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
// ****************************************************************************************** //
// *********************************** WARNING : UNFINISHED ********************************* //
// ****************************************************************************************** //
////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////


#include <iostream>

double foo (double x , double y){ return (x*y); }

int main(){
	/* Initial conditions */
	const double x0 = 1;
	const double y0 = 1;
	const unsigned int n = 6;	// Number of iterations
	const double step = 1;


	/* Useful Variables */
	double x_N;
	double y_N;
	double x = x0;
	double y = y0;
	double result;
	double d1 , d2 , d3 , d4;


	/* Print the values in (x0 , y0) */
	std::cout << "X = " << x << "   -->   Y = " << y << '\n';


	/* Perform the method */
	for (unsigned int i=0 ; i<n ; i++){
		/* Compute the increments */
		d1 = step*foo(x,y);
		d2 = step*foo(x+step/2 , y + d1/2);
		d3 = step*foo(x*step/2 , y + d2/2);
		d4 = step*foo(x*step , y + d3);

		/* Compute the new X and the new Y */
		y_N = y + (d1/6 + d2/3 + d3/3 + d4/6);
		x_N = x + step;

		/* Update the X and Y values */
		x = x_N;
		y = y_N;

		/* Print the function's value in X */
		std::cout << "X = " << x << "   -->   Y = " << y << '\n';
	}

}
