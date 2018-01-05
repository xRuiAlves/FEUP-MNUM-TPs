/*
 * P3.cpp
 *
 *  Created on: 05/01/2018
 *      Author: Rui Alves
 */

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;


double trapezio(const vector<double> & values , double h){
	unsigned int n = values.size() - 1;
	double integral;

	// Sum the middle terms (except y0 and yn)
	for (unsigned int i=1 ; i<n ; i++)	integral+=values.at(i);

	// Middle terms have coeficient 2
	integral *= 2;

	// Sum y0 and yn
	integral += values.at(0) + values.at(n);

	// Multiply the result by h/2
	integral *= h/2;

	return integral;	// Return the result
}

double estimated_error(double I2, double I3){ return( (I3-I2)/3 ); }


int main(){

	cout << fixed;
	cout.precision(6);

	vector<double> values;
	double h = 0.8;

	// Make the values with step 0.8
	values = {1.16 , 0.65 , 0.42};

	double I1 = trapezio(values,h);
	cout << "I1: " << I1 << endl;


	// Make the values with step 0.4
	h /= 2;
	values = {1.16 , 1.08 , 0.65 , 1.24 , 0.42};

	double I2 = trapezio(values,h);
	cout << "I2: " << I2 << endl;


	// Make the values with step 0.2
	h /= 2;
	values = {1.16 , 0.45 , 1.08 , 0.53 , 0.65 , 1.32 , 1.24 , 1.18 , 0.42};

	double I3 = trapezio(values,h);
	cout << "I3: " << I3 << endl << endl;


	// Estimate the error
	cout << "Integral value (lowest step): " << I3 << endl;
	cout << "Estimated Error: " << estimated_error(I2,I3) << endl;

	return 0;
}
