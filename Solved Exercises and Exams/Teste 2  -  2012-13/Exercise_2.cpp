/*
 * equacoes_dif.cpp
 *
 *  Created on: 05/12/2017
 *      Author: rui
 */

#include <iostream>
#include <cmath>

using namespace std;

const unsigned int a = 2;
const unsigned int b = 2;

double func(double x, double t) { return ( sin(a * x) + sin(b*t) ); }

void rk4(double xi , double ti , double h , unsigned int num_iter){
	double x = xi;
	double t = ti;

	double d1 , d2 , d3 , d4;

	cout << t << "\t\t" << x << endl << endl;

	for (unsigned int i=0 ; i<num_iter ; i++){

		d1 = h * func(t,x);
		d2 = h * func(t + h/2 , x + d1/2);
		d3 = h * func(t + h/2 , x + d2/2);
		d4 = h * func(t + h , x + d3);

		x = x + (d1/6 + d2/3 + d3/3 + d4/6);
		t = t + h;

		cout << t << "\t\t" << x << endl << endl;
	}

}

double quocient(double s , double s_l , double s_ll){  return (s_l - s)/(s_ll - s_l); }

int main(){

	cout << fixed;
	cout.precision(5);

	rk4(1 , 1 , 0.125 , 4);

	cout << quocient(1.501885 , 1.511739 , 1.51222);

	return 0;

}



/****************************************
		Pergunta 2.C

O quociente não é aproximadamente 2^ordem = 2^4 = 16 ,
pelo que deveriamos diminuir o step para metade , a fim
de provocar uma convergência do quociente para 16.

*****************************************/

