/*
 * picard-peano_two_variables.cpp
 *
 *  Created on: 03/01/2018
 *      Author: Rui Alves
 */

#include <iostream>
#include <cmath>

using namespace std;

double f1(double x , double y) { return ( sqrt((x*(y+5) - 1)/2) ); }		// f1(x,y) = 2x^2 - xy - 5x + 1 = 0    --->   x = sqrt( (x(y + 5) - 1)/2 )

double f2(double x , double y) { return ( sqrt( x + log10(x)) ); }			// f2(x,y) = x + 3log10(x) - y^2 = 0   --->   y = sqrt( x + log10(x) )

/***

  Picardo-Peano's Method (two variables)

  x0 - Initial X guess
  y0 - Initial Y guess
  num_iter - Number of iterations

 ***/
void picardo_peano(double x0 , double y0 , unsigned int num_iter){
	// Initial values
	double x = x0;
	double y = y0;

	// Auxiliary variables
	double xn;
	double yn;

	cout << 0 << ":\t" << x << "\t" << y << endl;

	// Loop until final interval is reached
	for(unsigned int i=1 ; i <= num_iter ; i++){
		xn = f1(x,y);
		yn = f2(x,y);

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

	// Guess
	const double x0 = 4;
	const double y0 = 4;

	// Call the method
	picardo_peano(x0,y0,15);

	return 0;
}
