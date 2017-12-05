/*
 * quadratura_cubatura.cpp
 *
 *  Created on: 05/12/2017
 *      Author: rui
 */

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;


const double k = 1.5;

double f(double x) { return sqrt(1 + (k * exp(k*x))*(k * exp(k*x)) ); }

double trapezio (double a , double b , double h){

	const unsigned int n = (b-a)/h;
	double result = 0;

	vector<double> vals;
	for (unsigned int i=0 ; i<=n ; i++){
		vals.push_back(f(a+i*h));
	}

	for (unsigned int i=1 ; i<n ; i++) {
		result += vals.at(i);
	}

	result *= 2;

	result += vals.at(0);
	result += vals.at(n);

	result *= h/2;

	return result;
}

double simpson(double a , double b , double h){

	const unsigned int n = (b-a)/h;
	double result = 0;
	double result_odds = 0;
	double result_evens = 0;

	vector<double> vals;
	for (unsigned int i=0 ; i<=n ; i++){
		vals.push_back(f(a+i*h));
	}

	for (unsigned int i=1 ; i<n ; i+=2) {
		result_odds += vals.at(i);
	}

	for (unsigned int i=2 ; i<n ; i+=2) {
		result_evens += vals.at(i);
	}

	result_odds *= 4;
	result_evens *= 2;

	result += vals.at(0);
	result += vals.at(n);
	result += result_odds;
	result += result_evens;

	result *= h/3;

	return result;

}

double quocient(double s , double s_l , double s_ll){  return (s_l - s)/(s_ll - s_l); }

int main(){

	// Trapezios
	double L1_trapezio = trapezio(0 , 1 , 0.25);
	double L2_trapezio = trapezio(0 , 1 , 0.125);
	double L3_trapezio = trapezio(0 , 1 , 0.0625);

	cout << L1_trapezio << endl;
	cout << L2_trapezio << endl;
	cout << L3_trapezio << endl;
	cout << quocient(L1_trapezio , L2_trapezio , L3_trapezio) << endl;
	cout << (L3_trapezio - L2_trapezio)/3 << endl << endl;

	// Simpson
	double L1_simpson = simpson(0 , 1 , 0.25);
	double L2_simpson = simpson(0 , 1 , 0.125);
	double L3_simpson = simpson(0 , 1 , 0.0625);

	cout << L1_simpson << endl;
	cout << L2_simpson << endl;
	cout << L3_simpson << endl;
	cout << quocient(L1_simpson , L2_simpson , L3_simpson) << endl;
	cout << (L1_simpson - L2_simpson)/15 << endl << endl;

	return 0;
}
