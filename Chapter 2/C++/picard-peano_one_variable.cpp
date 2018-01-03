/*
 * picard-peano_one_variable.cpp
 *
 *  Created on: 03/01/2018
 *      Author: Rui Alves
 */

#include <iostream>
#include <cmath>

using namespace std;

double f(double x) { return (atan(x+1)); }	// f(x) = x + 1 - tan(x) = 0   --->   x = tan(x) - 1   --->   tan(x) = x + 1   --->   x = atan(x+1)

/***

  Picardo-Peano's Method

  x0 - Initial guess
  num_iter - Number of iterations

 ***/
void picardo_peano(double x0, unsigned int num_iter){
	// Initial values
	double x = x0;

	cout << 0 << ":\t" << x << endl;

	// Loop until final interval is reached
	for(unsigned int i=1 ; i <= num_iter ; i++){
		x = f(x);

		// Print current value
		cout << i << ":\t" << x << endl;
	}

}


int main(){
	// Set printing precision
	cout << fixed;
	cout.precision(6);

	// Guess
	const double x0 = 1.1;

	// Call the method
	picardo_peano(x0,8);

	return 0;
}
