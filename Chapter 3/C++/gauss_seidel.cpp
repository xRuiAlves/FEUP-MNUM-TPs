/*
 * gauss_seidel.cpp
 *
 *  Created on: 03/01/2018
 *      Author: Rui Alves
 */


#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


typedef vector<vector<double> > matrix;

/***

  Gauss-Seidel method

  m - matrix to solve
  x1_i - Initial x1 guess
  x2_i - Initial x2 guess
  x3_i - Initial x3 guess
  x4_i - Initial x4 guess
  num_iter - Number of iterations

 ***/
void gauss_seidel(matrix & m , double x1_i , double x2_i , double x3_i , double x4_i , unsigned int num_iter){
	// Initial Values
	double x1 = x1_i;
	double x2 = x2_i;
	double x3 = x3_i;
	double x4 = x4_i;

	cout << 0 << ":\t" << x1 << "\t" << x2 << "\t" << x3 << "\t" << x4 << "\t" << endl;

	for (unsigned int i=1 ; i<=num_iter ; i++){
		// Compute the values
		x1 = (m[0][4] - (m[0][1]*x2 + m[0][2]*x3 + m[0][3]*x4))/m[0][0];
		x2 = (m[1][4] - (m[1][0]*x1 + m[1][2]*x3 + m[1][3]*x4))/m[1][1];
		x3 = (m[2][4] - (m[2][0]*x1 + m[2][1]*x2 + m[2][3]*x4))/m[2][2];
		x4 = (m[3][4] - (m[3][0]*x1 + m[3][1]*x2 + m[3][2]*x3))/m[3][3];

		// Print the current values
		cout << i << ":\t" << x1 << "\t" << x2 << "\t" << x3 << "\t" << x4 << "\t" << endl;
	}

}


int main(){
	// Set printing precision
	cout << fixed;
	cout.precision(6);


	// Make the matrix
	matrix m = {{ 95 , 3   , 1  , 2  , 101},
				{ 4  , 100 , 10 , 5  , 119},
				{ 3  , 9   , 55 , 5  , 72 },
				{ 10 , 2   , 4  , 80 , 96 }};

	// Initial values
	const double x1_i = 14.02;
	const double x2_i = 13.123;
	const double x3_i = 94.423;
	const double x4_i = 54.2341;
	const unsigned int num_iter = 7;


	// Perform the method
	gauss_seidel(m , x1_i , x2_i , x3_i , x4_i , num_iter);


	return 0;
}
