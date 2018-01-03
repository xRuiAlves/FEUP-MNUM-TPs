/*
 * corda.cpp
 *
 *  Created on: 03/01/2018
 *      Author: Rui Alves
 */

#include <iostream>
#include <cmath>

using namespace std;

double f(double x) { return (x*x - 4); }	// f(x) = x^2 - 4

/***

  Rope's Method

  a0 - Interval's left extreme
  b0 - Interval's right extreme
  num_iter - Number of iterations

 ***/
void corda(double a0, double b0, unsigned int num_iter){
	// Initial values
	double a = a0;
	double b = b0;
	double m;

	cout << 0 << ":\t" << a << "\t" << b << "\t" << abs(b-a) << endl;

	// Loop until final interval is reached
	for(unsigned int i=1 ; i <= num_iter ; i++){
		m = ( a*f(b) - b*f(a) ) / ( f(b) - f(a) );

		// Decide which extreme changes
		if (f(m) * f(a) > 0)
			a = m;
		else
			b = m;

		// Print current values
		cout << i << ":\t" << a << "\t" << b << "\t" << abs(b-a) << endl;
	}

}


int main(){
	// Set printing precision
	cout << fixed;
	cout.precision(6);

	// Values
	const double a0 = 0;
	const double b0 = 12;

	// Call the method
	corda(a0,b0,45);

	return 0;
}
