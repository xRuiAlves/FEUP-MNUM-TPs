#include <iostream>
#include <cmath>

using namespace std;

const double PHI = (sqrt(5) - 1)/2;	// Aproximately (GoldenNumber - 1) , where the golden number is (sqrt(5)+1)/2

double f(double x) { return ( (x+2)*(x+2) - 5) ; }	// Function of which we want to find the minimum

pair<double,int> seccao_aurea(double a0 , double b0, double final_interval){
	// variables declaration
	double a = a0;
	double b = b0;
	double quadrica , middle_point;
	
	// Compute the initial 'middle' values, using the value PHI
	double delta = b-a;
	double c = b - delta*PHI;
	double d = a + delta*PHI;

	unsigned long num_iter = 0;	// Count the number of iterations to get to the final interval

	while (abs(b-a) > final_interval){
		num_iter ++;

		// Discard the correct point of the 4 points
		if( f(c) < f(d) ){
			b = d;
			d = c;
			c = b - (b-a)*PHI;
		}
		else{
			a = c;
			c = d;
			d = a + (b-a)*PHI;
		}
	}

	// Made the "quadrica" adjustment, to compute a likely minimum value out of the final interval
	delta = (b-a)/2;
	middle_point = (b+a)/2;
	quadrica = middle_point + (delta*(f(a)-f(b))/(2*(f(b) - 2*f(middle_point) + f(a))));

	return make_pair(quadrica , num_iter);
}

pair<double,int> tercos(double a0 , double b0, double final_interval){
	// Variables declaration
	double a = a0;
	double b = b0;
	double delta;
	double c , d , middle_point;
	double quadrica;

	unsigned long num_iter = 0;	// Count the number of iterations to get to the final interval

	while (abs(b-a) > final_interval){
		num_iter ++;
		delta = b-a;
		
		// Compute the 'middle values'
		c = a + (delta/3);
		d = a + 2*(delta/3);

		// Discard the correct point of the 4 points
		if( f(c) < f(d) )
			b = d;
		else
			a = c;
	}

	// Made the "quadrica" adjustment, to compute a likely minimum value out of the final interval
	delta = (b-a)/2;
	middle_point = (b+a)/2;
	quadrica = middle_point + (delta*(f(a)-f(b))/(2*(f(b) - 2*f(middle_point) + f(a))));

	return make_pair(quadrica , num_iter);
}

int main(){
	// Set printing precision
	cout << fixed;
	cout.precision(6);

	const double a0 = -10000;			// Initial interval value
	const double b0 = 8937;				// Final interval value
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
