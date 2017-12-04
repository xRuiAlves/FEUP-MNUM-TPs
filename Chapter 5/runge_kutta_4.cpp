/*******************************************************

	In the following example, i am solving dy/dx = y.
	This equation can be solved by variables separation
	method, getting the answer y = e^x. Using RK4 with
	such a small step, we get a very, very good aproximation
	for e^x.

	For example:
	For x=5
		e^5 = 148.413159
		We got 148.413

	This is a fantastic result! RK4 is a 4th order method. This
	means that if we lower the step to half, the error will be
	2^order = 2^4 = 16 times lower!!!

********************************************************/



#include <iostream>

double foo (double x , double y){ return (y); }   // dy/dx = y   ---->   y = e^x

int main(){
	/* Initial conditions */
	const double x0 = 0;
	const double y0 = 1;
	const unsigned int n = 60;	// Number of iterations
	const double step = 0.1;


	/* Useful Variables */
	double x = x0;
	double y = y0;
	double d1 , d2 , d3 , d4;


	/* Print the values in (x0 , y0) */
	std::cout << "X = " << x << "   -->   Y = " << y << '\n';


	/* Perform the method */
	for (unsigned int i=0 ; i<n ; i++){
		/* Compute the increments */
		d1 = step*foo(x,y);
		d2 = step*foo(x+step/2 , y + d1/2);
		d3 = step*foo(x+step/2 , y + d2/2);
		d4 = step*foo(x+step , y + d3);

		/* Compute the new X and the new Y */
		y = y + (d1/6 + d2/3 + d3/3 + d4/6);
		x = x + step;

		/* Print the function's value in X */
		std::cout << "X = " << x << "   -->   Y = " << y << '\n';
	}

}
