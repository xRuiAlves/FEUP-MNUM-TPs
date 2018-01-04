/*
 * gradient.cpp
 *
 *  Created on: 04/01/2018
 *      Author: Rui Alves
 */

#include <iostream>
#include <cmath>

using namespace std;

double f(double x , double y) { return ( (x+2)*(x+2) + (y+2)*(y+2) - 5 ); }	// f(x,y) = (x+2)^2 + (y+2)^2 - 5

double dfx(double x , double y) { return (2*(x+2)); }	// df(x,y)/dx = 2(x+2)

double dfy(double x , double y) { return (2*(y+2)); }	// df(x,y)/dy = 2(y+2)

/***

  Gradient Method

  x0 - Initial X value
  y0 - Initial Y value
  h0 - Final step
  num_iter - number of iterations

 ***/
void gradient(double x0 , double y0 , double h0 , unsigned int num_iter){
	// Initial values
	double x = x0;
	double y = y0;
	double h = h0;

	// Auxiliary Variables
	double xn, yn;

	cout << 0 << ":\t" << x << '\t' << y << endl;

	// Perform the method the indicated number of times
	for (unsigned int i=1 ; i<=num_iter ; i++){
		// Compute the new values
		xn = x - h*dfx(x,y);
		yn = y - h*dfy(x,y);

		// Make the decision
		if ( !(f(xn,yn) < f(x,y)) ){	// If the function's value hasn't diminished , change the step to half and don't update the values.
			h = h/2;
		}
		else{	// If the functions value has indeed diminished , double the step and update the values
			x = xn;
			y = yn;
			h = h*2;
		}

		// Print the current values
		cout << i << ":\t" << x << '\t' << y << endl;
	}

}


int main(){
	// Set printing precision
	cout << fixed;
	cout.precision(6);

	// Values
	const double x0 = 31415.92;
	const double y0 = -5028.45;
	const double h = 0.1;
	const unsigned int num_iter = 95;

	// Call the method
	gradient(x0 , y0 , h , num_iter);

	return 0;
}
