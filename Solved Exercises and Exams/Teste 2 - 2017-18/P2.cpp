/*
 * P2.cpp
 *
 *  Created on: 05/01/2018
 *      Author: Rui Alves
 */


#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

typedef vector<vector<double> > matrix;


void gauss_seidel(const matrix & m , double x1 , double x2 , double x3 , double x4 , unsigned int num_iter){

	cout << 0 << ":\t" << x1 << '\t' << x2 << '\t' << x3 << '\t' << x4 << endl;

	for (unsigned int i=1 ; i<=num_iter ; i++){
		x1 = (m[0][4] - (m[0][1]*x2 + m[0][2]*x3 + m[0][3]*x4))/m[0][0];
		x2 = (m[1][4] - (m[1][0]*x1 + m[1][2]*x3 + m[1][3]*x4))/m[1][1];
		x3 = (m[2][4] - (m[2][0]*x1 + m[2][1]*x2 + m[2][3]*x4))/m[2][2];
		x4 = (m[3][4] - (m[3][0]*x1 + m[3][1]*x2 + m[3][2]*x3))/m[3][3];

		cout << i << ":\t" << x1 << '\t' << x2 << '\t' << x3 << '\t' << x4 << endl;
	}
}


int main(){

	cout << fixed;
	cout.precision(6);

	matrix m = {{ 6.00000 , 0.50000 , 3.00000 , 0.25000 , 19.00000},
				{ 1.20000 , 3.00000 , 0.25000 , 0.20000 , -2.20000},
				{-1.00000 , 0.25000 , 4.00000 , 2.00000 ,  9.00000},
				{ 2.00000 , 4.00000 , 1.00000 , 8.00000 , 15.00000}};



	double x1 =  1.67969;
	double x2 = -1.78160;
	double x3 =  1.93752;
	double x4 =  2.10369;

	unsigned int num_iter = 1;

	gauss_seidel(m , x1 , x2 , x3 , x4 , num_iter);


	return 0;
}
