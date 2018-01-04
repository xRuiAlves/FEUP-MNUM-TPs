/*
 * simpson.cpp
 *
 *  Created on: 04/01/2018
 *      Author: Rui Alves
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


double f(double x) { return (5*x*x*x*x + 8.5*x*x*x + 3.14); }	// f(x) = 5x^4 + 8.5x^3 + 3.14


/***

  Simpson's method

  a - integral initial value
  b - integral final value
  h - step

 ***/
double simpson(const double a , const double b , const double h){

	const unsigned int n = abs(b-a)/h;
	double integral = 0;
	double integral_odd_terms = 0;
	double integral_even_terms = 0;

	// Make the values list
	vector<double> values;
	for (unsigned int i=0 ; i<=n ; i++){
		values.push_back(f(a + i*h));
	}

	// Compute the odd values
	for (unsigned int i=1 ; i<n ; i+=2)	integral_odd_terms += values.at(i);


	// Compute the even values
	for (unsigned int i=2 ; i<n ; i+=2)	integral_even_terms += values.at(i);

	integral_odd_terms *= 4;	// The odd values have coeficient 4

	integral_even_terms *= 2;	// The even values have coeficient 2

	integral += values.at(0);	// y0
	integral += values.at(n);	// yn
	integral += integral_odd_terms;
	integral += integral_even_terms;

	// Multiply by step/3

	integral *= h/3;	// I = h/3 * (y0 + 4y1 + 2y2 + 4y3 + ... + 4y(n-3) + 2y(n-2) + 4y(n-1) + y(n) )


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
	double integral1 = simpson(a , b , h);
	cout << "Using h = " << h << endl;
	cout << "Integral: " << integral1 << endl << endl;

	h /= 2;	// Dimish the step

	double integral2 = simpson(a , b , h);
	cout << "Using h = " << h << endl;
	cout << "Integral: " << integral2 << endl << endl;

	h /= 2;	// Dimish the step

	double integral3 = simpson(a , b , h);
	cout << "Using h = " << h << endl;
	cout << "Integral: " << integral3 << endl << endl;

	// Print the convergence quotient
	double convergence_quotient = quotient(integral1 , integral2 , integral3);
	cout << "Convergence quotient: " << convergence_quotient << endl;


	return 0;
}
