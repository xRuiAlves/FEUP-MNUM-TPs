/*
 * P6.cpp
 *
 *  Created on: 05/01/2018
 *      Author: Rui Alves
 */


#include <iostream>
#include <cmath>

using namespace std;


const double A = 1.5;


double f1(double t , double y , double z){ return (z); }

double f2(double t , double y , double z){ return (A + t*t + t*z); }


void euler(double t , double y , double z , double h , unsigned int num_iter){

	double tn , yn , zn;

	cout << 0 << ":\t" << t << '\t' << y << '\t' << z << endl;


	for (unsigned int i=1 ; i<=num_iter ; i++){
		zn = z + h*f2(t,y,z);
		yn = y + h*f1(t,y,z);
		tn = t + h;

		z = zn;
		y = yn;
		t = tn;

		cout << i << ":\t" << t << '\t' << y << '\t' << z << endl;
	}
}


void rk4(double t , double y , double z , double h , unsigned int num_iter){

	double d1,d2,d3,d4,l1,l2,l3,l4;

	cout << 0 << ":\t" << t << '\t' << y << '\t' << z << endl;


		for (unsigned int i=1 ; i<=num_iter ; i++){
			d1 = h*f1(t,y,z);
			l1 = h*f2(t,y,z);

			d2 = h*f1(t+h/2 , y+d1/2 , z+l1/2);
			l2 = h*f2(t+h/2 , y+d1/2 , z+l1/2);

			d3 = h*f1(t+h/2 , y+d2/2 , z+l2/2);
			l3 = h*f2(t+h/2 , y+d2/2 , z+l2/2);

			d4 = h*f1(t+h , y+d3 , z+l3);
			l4 = h*f2(t+h , y+d3 , z+l3);

			z += (l1/6 + l2/3 + l3/3 + l4/6);
			y += (d1/6 + d2/3 + d3/3 + d4/6);
			t += h;

			cout << i << ":\t" << t << '\t' << y << '\t' << z << endl;
		}

}



int main(){

	cout << fixed;
	cout.precision(6);

	double t = 1;
	double y = 0;
	double z = 1;
	double h = 0.2;
	unsigned int num_iter = 2;

	cout << "   -----  EULER  -----" << endl;
	euler(t , y , z , h , num_iter);

	cout << "\n   -----  RK4  -----" << endl;
	rk4(t , y , z , h , num_iter);


	return 0;
}
