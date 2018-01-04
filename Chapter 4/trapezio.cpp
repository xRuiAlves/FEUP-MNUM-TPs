/*
 * trapezio.cpp
 *
 *  Created on: 04/01/2018
 *      Author: Rui Alves
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


double f(double x) { return (x*x - 4*x + 3.5); }	// f(x) = x^2 - 4*x + 3.5


/***

  Trapezio's method

  a - integral initial value
  b - integral final value
  h - step

 ***/
double trapezio(const double a , const double b , const double h){

	const unsigned int n = abs(b-a)/h;
	double integral = 0;

	// Make the values list
	vector<double> values;
	for (unsigned int i=0 ; i<=n ; i++){
		values.push_back(f(a + i*h));
	}

	// Compute the middle values ( all except y0 and yn )
	for (unsigned int i=1 ; i<n ; i++)	integral += values.at(i);

	// The middle terms have coeficient 2
	integral *= 2;

	integral += values.at(0);	// y0
	integral += values.at(n);	// yn

	// Multiply by step/2

	integral *= h/2;	// I = h/2 * (y0 + 2y1 + 2y2 + ... + 2y(n-1) + y(n) )


	// Return the computed value
	return integral;
}

/* Function no compute the Convergence Quotient */
double quotient(double s , double s_l , double s_ll){  return (s_l - s)/(s_ll - s_l); }



int main(){
	// Set printing precision
	cout << fixed;
	cout.precision(6);

	// Integral Values
	const double a = 2;
	const double b = 6;
	double h = 0.25;

	// Compute and print the answers
	double integral1 = trapezio(a , b , h);
	cout << "Using h = " << h << endl;
	cout << "Integral: " << integral1 << endl << endl;

	h /= 2;	// Dimish the step

	double integral2 = trapezio(a , b , h);
	cout << "Using h = " << h << endl;
	cout << "Integral: " << integral2 << endl << endl;

	h /= 2;	// Dimish the step

	double integral3 = trapezio(a , b , h);
	cout << "Using h = " << h << endl;
	cout << "Integral: " << integral3 << endl << endl;

	// Print the convergence quotient
	double convergence_quotient = quotient(integral1 , integral2 , integral3);
	cout << "Convergence quotient: " << convergence_quotient << endl;


	return 0;
}
