/*
 * sistemas_iterativos.cpp
 *
 *  Created on: 05/12/2017
 *      Author: rui
 */


#include <iostream>
#include <cmath>

using namespace std;

void gauss_jacobi(double x1i, double x2i, double x3i, double x4i , unsigned int num_iter){
	double x1 = x1i;
	double x2 = x2i;
	double x3 = x3i;
	double x4 = x4i;

	double x1n , x2n , x3n , x4n;

	cout << x1 << endl << x2 << endl << x3 << endl << x4 << endl << endl;

	for (unsigned int i=0 ; i < num_iter ; i++){

		x1n = (1 + 1*x2 + 1*x3 - 1*x4)/4.5;
		x2n = (-1 + 1*x1 - 1*x3 + 1*x4)/4.5;
		x3n = (-1 + 1*x1 - 2*x2 + 1*x4)/4.5;
		x4n = (0 - 2*x1 + 1*x2 + 1*x3)/4.5;

		x1 = x1n;
		x2 = x2n;
		x3 = x3n;
		x4 = x4n;

		cout << x1 << endl << x2 << endl << x3 << endl << x4 << endl << endl;

	}


}

int main(){

	cout << fixed;
	cout.precision(5);

	gauss_jacobi(0.25 , 0.25 , 0.25 , 0.25 , 2);

	return 0;
}


/**************************************
	RESPOSTA 1. B

O método converge, pois cada elemento da
diagonal principal é dominante relativamente
à sua linha, isto é, para qualquer linha, o
módulo do elemento da diagonal principal é
superior à soma dos módulos dos restantes
elementos da linha

***************************************/

