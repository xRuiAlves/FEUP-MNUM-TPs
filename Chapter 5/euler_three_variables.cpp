/*
 * euler_three_variables.cpp
 *
 *  Created on: 04/01/2018
 *      Author: Rui Alves
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


double f1 (double x , double y , double z){ return (z); }

double f2 (double x , double y , double z){ return (1.5 + x*x + x*z); }


/***

  Euler's method

  x0 - initial x value
  y0 - initial y value
  z0 - initial z value
  h - step
  num_iter - number of iterations

 ***/
void euler(double x0 , double y0 , double z0 , double h , unsigned int num_iter){

	// Variables
	double x = x0;
	double y = y0;
	double z = z0;
	double xn , yn , zn;

	cout << 0 << ":\t" << x << "\t" << y << "\t" << z << endl;

	for (unsigned int i=1 ; i<=num_iter ; i++){
		// Compute the values
		yn = y + h*f1(x,y,z);
		zn = z + h*f2(x,y,z);
		xn = x + h;

		x = xn;
		y = yn;
		z = zn;

		// Print the current values
		cout << i << ":\t" << x << "\t" << y << "\t" << z << endl;
	}
}


int main(){
	// Set printing precision
	cout << fixed;
	cout.precision(6);

	// Integral Conditions
	const double x0 = 1;
	const double y0 = 0;
	const double z0 = 1;
	const double h = 0.2;
	const unsigned int num_iter = 2;

	// Perform the method
	euler(x0 , y0 , z0 , h , num_iter);





	return 0;
}
