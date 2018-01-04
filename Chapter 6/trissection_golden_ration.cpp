/*
 * trissection_golden_ration.cpp
 *
 *  Created on: 04/01/2018
 *      Author: Rui Alves
 */

#include <iostream>
#include <cmath>

using namespace std;


const double B = (sqrt(5) - 1)/2;		// B = 1 - golden number = 0.6180339887	(approximately)
const double A = (B*B);					// A = B^2 = 0.3819660112 (approximately)


double f(double x) { return ( (x+2)*(x+2) - 5) ; }		// f(x) = (x+2)^2 - 5

/***

  Trissection Method

  a0 - Interval's left extreme
  b0 - Interval's right extreme
  final_interval - Interval b-a to reach : termination condition

 ***/
pair<double,double> trissection(double a0, double b0, double final_interval){
	// Initial values
	double x1 = a0;
	double x2 = b0;
	double x3 = x1 + A*(x2-x1);
	double x4 = x1 + B*(x2-x1);
	unsigned int iterations_counter = 0;

	cout << iterations_counter << ":\t" << x1 << "\t" << x2 << "\t" << abs(x2-x1) << endl;

	// Loop until final interval is reached
	while(abs(x2-x1) > final_interval){
		// Decide which extreme changes
		if (f(x3) < f(x4)){
			x2 = x4;
			x4 = x3;
			x3 = x1 + A*(x2-x1);
		}
		else{
			x1 = x3;
			x3 = x4;
			x4 = x1 + B*(x2-x1);
		}

		// Print current values
		iterations_counter ++;
		cout << iterations_counter << ":\t" << x1 << "\t" << x4 << "\t" << abs(x2-x1) << endl;
	}

	// Return the final interval that was reached
	return make_pair(x1,x2);
}

/* Makes a Quadratic Interpolation Adjustment */
double quadratic_interpolation(double a , double b){
	double m = (a+b)/2;		// Compute the middle point
	double h = (b-a)/2;		// Compute the interval

	// Compute the function values in the three points
	double f1 = f(a);
	double f2 = f(m);
	double f3 = f(b);

	// Perform the interpolation
	double result = m + (h * (f1 - f3))/(2 * (f3 - 2*f2 + f1));

	return result;
}


int main(){
	// Set printing precision
	cout << fixed;
	cout.precision(6);

	// Values
	const double a0 = -10000;
	const double b0 = 8937;

	// Call the method
	pair<double,double> mininum_int = trissection(a0,b0,0.01);
	cout << "\nLeft interval extreme:  " << mininum_int.first  << endl;
	cout << "Right interval extreme: " << mininum_int.second << endl;

	cout << "\nMinimum value (after applying quadratic interpolation: " << quadratic_interpolation(mininum_int.first , mininum_int.second) << endl;

	return 0;
}
