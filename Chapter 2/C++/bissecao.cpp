/*
 * bissecao.cpp
 *
 *  Created on: 03/01/2018
 *      Author: Rui Alves
 */

#include <iostream>
#include <cmath>

using namespace std;

double f(double x) { return (x*x - 4); }	// f(x) = x^2 - 4

/***

  Bissection Method

  a0 - Interval's left extreme
  b0 - Interval's right extreme
  final_interval - Interval b-a to reach : termination condition

 ***/
void bissecao(double a0, double b0, double final_interval){
	// Initial values
	double a = a0;
	double b = b0;
	double m;
	unsigned int iterations_counter = 0;

	cout << iterations_counter << ":\t" << a << "\t" << b << "\t" << abs(b-a) << endl;

	// Loop until final interval is reached
	while(abs(b-a) > final_interval){
		m = (b+a)/2;

		// Decide which extreme changes
		if (f(m) * f(a) > 0)
			a = m;
		else
			b = m;

		// Print current values
		iterations_counter ++;
		cout << iterations_counter << ":\t" << a << "\t" << b << "\t" << abs(b-a) << endl;
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
	bissecao(a0,b0,0.001);

	return 0;
}
