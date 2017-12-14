#include <iostream>
#include <cmath>

using namespace std;

const double FI = (sqrt(5) - 1)/2;

double f(double x) { return ( (x+2)*(x+2) - 5) ; }

pair<double,int> seccao_aurea(double a0 , double b0, double final_interval){
	double a = a0;
	double b = b0;
	double delta = b-a;
	double c = b - delta*FI;
	double d = a + delta*FI;
	double quadrica , middle_point;

	unsigned long num_iter = 0;

	while (abs(b-a) > final_interval){
		num_iter ++;

		if( f(c) < f(d) ){
			b = d;
			d = c;
			c = b - (b-a)*FI;
		}
		else{
			a = c;
			c = d;
			d = a + (b-a)*FI;
		}
	}

	delta = (b-a)/2;
	middle_point = (b+a)/2;
	quadrica = middle_point + (delta*(f(a)-f(b))/(2*(f(b) - 2*f(middle_point) + f(a))));

	return make_pair(quadrica , num_iter);
}

pair<double,int> tercos(double a0 , double b0, double final_interval){
	double a = a0;
	double b = b0;
	double delta;
	double c , d , middle_point;
	double quadrica;

	unsigned long num_iter = 0;

	while (abs(b-a) > final_interval){
		num_iter ++;
		delta = b-a;
		c = a + (delta/3);
		d = a + 2*(delta/3);

		if( f(c) < f(d) )
			b = d;
		else
			a = c;
	}

	delta = (b-a)/2;
	middle_point = (b+a)/2;
	quadrica = middle_point + (delta*(f(a)-f(b))/(2*(f(b) - 2*f(middle_point) + f(a))));

	return make_pair(quadrica , num_iter);
}

int main(){

	cout << fixed;
	cout.precision(6);

	const double a0 = -10000;
	const double b0 = 8937;
	const double termination_interval = 0.1;

	cout << "  ***** TERCOS *****" << endl;
	pair<double,int> answer_tercos = tercos(a0 , b0 , termination_interval);
	cout << "Minimum: " << answer_tercos.first << endl;
	cout << "Num. of Iterations: " << answer_tercos.second << endl;

	cout << "\n  ***** SECCAO AUREA *****" << endl;
	pair<double,int> answer_aurea = seccao_aurea(a0 , b0 , termination_interval);
	cout << "Minimum: " << answer_aurea.first << endl;
	cout << "Num. of Iterations: " << answer_aurea.second << endl;

	return 0;
}
