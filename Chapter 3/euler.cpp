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
	const double x0 = 2;
	const double y0 = 1;
	const unsigned int n = 4;	// Number of iterations
	const double step = 1;


	/* Useful Variables */
	double x_N;
	double y_N;
	double x = x0;
	double y = y0;
	double result;


	/* Print the values in (x0 , y0) */
	std::cout << "X = " << x << "   -->   Y = " << y << '\n';


	/* Perform the method */
	for (unsigned int i=0 ; i<n ; i++){
		/* Compute the new X and the new Y */
		y_N = y + step*foo(x,y);
		x_N = x + step;

		/* Update the X and Y values */
		x = x_N;
		y = y_N;

		/* Print the function's value in X */
		std::cout << "X = " << x << "   -->   Y = " << y << '\n';
	}
}
