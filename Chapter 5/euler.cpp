/*******************************************************

	In the following example, i am solving dy/dx = y.
	This equation can be solved by variables separation
	method, getting the answer y = e^x. Using Euler's with
	such a small step, we get a very, very good aproximation
	for e^x.

	For example:
	For x=5
		e^5 = 148.413159
		We got 117.391
		With RK4 we would get 148.413 !!!

	This is not a very good result... Euler's is a first order
	method. This means that if we lower the step to half, the
	error will be 2^order = 2^1 = 2 times lower.

	With RK4 (4th order method), by reducing the step to half, we would lower
	the error 16 times instead of just 2. This means that if we want
	to lower the error in the same quantity (approximately!!!) we would
	need to lower the step 8 times more in the Euler's method than in the RK4
	method (16/2 = 8) !!!!!

********************************************************/


#include <iostream>

double foo (double x , double y) { return (y); }		// dy/dx = y   ---->   y = e^x

int main(){
	/* Initial conditions */
	const double x0 = 0;
	const double y0 = 1;
	const unsigned int n = 60;	// Number of iterations
	const double step = 0.1	;


	/* Useful Variables */
	double x = x0;
	double y = y0;


	/* Print the values in (x0 , y0) */
	std::cout << "X = " << x << "   -->   Y = " << y << '\n';


	/* Perform the method */
	for (unsigned int i=0 ; i<n ; i++){
		/* Compute the new X and the new Y */
		y = y + step*foo(x,y);
		x = x + step;


		/* Print the function's value in X */
		std::cout << "X = " << x << "   -->   Y = " << y << '\n';
	}

	return 0;
}
