/*
 * P4.cpp
 *
 *  Created on: 05/01/2018
 *      Author: Rui Alves
 */

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;


typedef vector<vector<double> > matrix;


int main(){

	cout << fixed;
	cout.precision(6);


	matrix m = {{ 6.5 , 1.5 , 1.2 },
				{ 2.1 , 4.5 , 2.2 },
				{ 1.1 , 1.4 , 4.1 }};

	double hx = 0.9;
	double hy = 0.9;

	double I1 = m[0][0] + m[0][2] + m[2][0] + m[2][2];	// Coeficient 1 terms
	double I2 = m[0][1] + m[1][0] + m[1][2] + m[2][1];	// Coeficient 4 terms
	double I3 = m[1][1];								// Coeficient 16 term

	double result = hx/3 * hy/3 * (1*I1 + 4*I2 + 16*I3);

	cout << "Result: " << result << endl;


	return 0;
}
