/*
 * rk4_three_variables.cpp
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

  RK4's method

  x0 - initial x value
  y0 - initial y value
  z0 - initial z value
  h - step
  num_iter - number of iterations

 ***/
void rk4(double x0 , double y0 , double z0 , double h , unsigned int num_iter){

	// Variables
	double x = x0;
	double y = y0;
	double z = z0;
	double d1 , d2 , d3 , d4;
	double l1 , l2 , l3 , l4;

	cout << 0 << ":\t" << x << "\t" << y << "\t" << z << endl;

	for (unsigned int i=1 ; i<=num_iter ; i++){
		// Compute the increments
		d1 = h*f1(x,y,z);
		l1 = h*f2(x,y,z);

		d2 = h*f1(x+h/2,y+d1/2,z+l1/2);
		l2 = h*f2(x+h/2,y+d1/2,z+l1/2);

		d3 = h*f1(x+h/2,y+d2/2,z+l2/2);
		l3 = h*f2(x+h/2,y+d2/2,z+l2/2);

		d4 = h*f1(x+h,y+d3,z+l3);
		l4 = h*f2(x+h,y+d3,z+l3);

		// Perform the method
		z += (l1/6 + l2/3 + l3/3 + l4/6);
		y += (d1/6 + d2/3 + d3/3 + d4/6);
		x += h;

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
	rk4(x0 , y0 , z0 , h , num_iter);





	return 0;
}
