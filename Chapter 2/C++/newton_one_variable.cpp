/*
 * newton_one_variable.cpp
 *
 *  Created on: 03/01/2018
 *      Author: Rui Alves
 */

#include <iostream>
#include <cmath>

using namespace std;

double f(double x) { return (x*x - 4); }	// f(x) = x^2 - 4

double df(double x) { return (2*x); }		// f'(x) = 2*x

/***

  Newton's Method

  x0 - Initial guess
  num_iter - Number of iterations

 ***/
void newton(double x0, unsigned int num_iter){
	// Initial values
	double x = x0;

	cout << 0 << ":\t" << x << endl;

	// Loop until final interval is reached
	for(unsigned int i=1 ; i <= num_iter ; i++){
		x = x - f(x)/df(x);

		// Print current value
		cout << i << ":\t" << x << endl;
	}

}


int main(){
	// Set printing precision
	cout << fixed;
	cout.precision(6);

	// Guess
	const double x0 = 10;

	// Call the method
	newton(x0,7);

	return 0;
}
