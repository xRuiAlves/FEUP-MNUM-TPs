/*
 * equacoes_dif.cpp
 *
 *  Created on: 05/12/2017
 *      Author: rui
 */

#include <iostream>
#include <cmath>

using namespace std;

const double a = 20.00000;
const double b = 0.50000;

double f1(double t, double C , double T) { return (-exp(-b/(T+273)) * C); }

double f2(double t, double C , double T) { return (a*exp(-b/(T+273))*C - b*(T-20)); }

void euler(double ti , double Ci , double Ti , double h , unsigned int num_iter){
	double t = ti;
	double C = Ci;
	double T = Ti;
	double tn, Cn, Tn;

	cout << t << "\t\t" << C << "\t\t" << T << endl;

	for (unsigned int i=0 ; i<num_iter ; i++){
		Cn = C + h*f1(t,C,T);
		Tn = T + h*f2(t,C,T);
		tn = t + h;

		C = Cn;
		T = Tn;
		t = tn;

		cout << t << "\t\t" << C << "\t\t" << T << endl;
	}
}

void rk4(double ti , double Ci , double Ti , double h , unsigned int num_iter){
	double t = ti;
	double C = Ci;
	double T = Ti;
	double tn, Cn, Tn;
	double d1, d2, d3, d4;
	double l1, l2, l3, l4;

	cout << t << "\t\t" << C << "\t\t" << T << endl;

	for (unsigned int i=0 ; i<num_iter ; i++){
		d1 = h * f1(t,C,T);
		l1 = h * f2(t,C,T);

		d2 = h * f1(t + h/2 , C + d1/2 , T + l1/2);
		l2 = h * f2(t + h/2 , C + d1/2 , T + l1/2);

		d3 = h * f1(t + h/2 , C + d2/2 , T + l2/2);
		l3 = h * f2(t + h/2 , C + d2/2 , T + l2/2);

		d4 = h * f1(t + h , C + d3 , T + l3);
		l4 = h * f2(t + h , C + d3 , T + l3);

		Cn = C + (d1/6 + d2/3 + d3/3 + d4/6);
		Tn = T + (l1/6 + l2/3 + l3/3 + l4/6);
		tn = t + h;

		C = Cn;
		T = Tn;
		t = tn;

		cout << t << "\t\t" << C << "\t\t" << T << endl;
	}
}

double quocient(double s , double s_l , double s_ll){  return (s_l - s)/(s_ll - s_l); }

int main(){

	cout << fixed;
	cout.precision(5);


	cout << "Alinea A:\n";
	euler(0 , 2.0 , 20.0 , 0.2 , 2);
	cout << "\n--------------------------------\nAlinea B:\n";
	rk4(0 , 2.0 , 20.0 , 0.2 , 2);
	cout << "\n--------------------------------\nAlinea C:\n";
	cout << "Step 0.2\n";
	euler(0 , 2.0 , 20.0 , 0.2 , 2);
	cout << "\nStep 0.1\n";
	euler(0 , 2.0 , 20.0 , 0.1 , 4);
	cout << "\nStep 0.05\n";
	euler(0 , 2.0 , 20.0 , 0.05 , 8);
	cout << "\nQuociente: " << quocient(1.28108 , 1.31318 , 1.32777) << endl;
	cout << "Erro: " << 1.32777 - 1.31318 << endl;

	return 0;

}


