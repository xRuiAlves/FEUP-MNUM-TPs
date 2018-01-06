/*
 * newton_two_variables.cpp
 *
 *  Created on: 03/01/2018
 *      Author: Rui Alves
 */

#include <iostream>
#include <cmath>

using namespace std;

double f1(double x , double y) { return (x*x - 4 - y); }	// f1(x,y) = x^2 - 4 - y

double df1x(double x , double y) { return (2*x); }			// df1/dx(x,y) = 2*x

double df1y(double x , double y) { return (-1); }			// df1/dy(x,y) = -1

double f2(double x , double y) { return (y - x); }			// f2(x,y) = y - x

double df2x(double x , double y) { return (-1); }			// df2/dx(x,y) = -1

double df2y(double x , double y) { return (1); }			// df2/dy(x,y) = 1

/***

  Newton's Method (two variables)

  x0 - Initial X guess
  y0 - Initial Y guess
  num_iter - Number of iterations

 ***/
void newton(double x0 , double y0 , unsigned int num_iter){
	// Initial values
	double x = x0;
	double y = y0;

	// Auxiliary variables
	double xn;
	double yn;
	double jacobian;

	cout << 0 << ":\t" << x << "\t" << y << endl;

	// Loop until final interval is reached
	for(unsigned int i=1 ; i <= num_iter ; i++){
		jacobian = df1x(x,y)*df2y(x,y) - df2x(x,y)*df1y(x,y);
		xn = x - (f1(x,y)*df2y(x,y) - f2(x,y)*df1y(x,y)) / jacobian;
		yn = y - (f2(x,y)*df1x(x,y) - f1(x,y)*df2x(x,y)) / jacobian;

		// Update the variables
		x = xn;
		y = yn;

		// Print current values
		cout << i << ":\t" << x << "\t" << y << endl;
	}

}


int main(){
	// Set printing precision
	cout << fixed;
	cout.precision(6);

	// Guesses
	const double x0 = 10;
	const double y0 = 8;

	// Call the method
	newton(x0,y0,7);

	return 0;
}
