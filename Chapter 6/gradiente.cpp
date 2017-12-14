#include <iostream>
#include <cmath>

using namespace std;

double f(double x, double y) { return ( (x+2)*(x+2) + (y+2)*(y+2) - 5 ); }

double f_diff_x(double x, double y) { return (2*(x+2)); }

double f_diff_y(double x, double y) { return (2*(y+2)); }

pair<double,double> gradiente(double x0, double y0 , double h0 ,  unsigned int num_iter){
	double x = x0;
	double y = y0;
	double h = h0;
	double xn , yn;

	for (unsigned int i=0 ; i<num_iter ; i++){
		xn = x - h*f_diff_x(x,y);
		yn = y - h*f_diff_y(x,y);

		if (f(x,y) < f(xn,yn)){
			h = h/2;
		}
		else{
			h = h*2;
			x = xn;
			y = yn;

		}
	}

	return (make_pair(x,y));

}

int main(){

	cout << fixed;
	cout.precision(10);

	const double x0 = 10;
	const double y0 = 15;
	const double h = 10;
	const unsigned int num_iter = 100;

	pair<double,double> answer = gradiente(x0 , y0 , h , num_iter);

	cout << "Final X: " << answer.first << endl;
	cout << "Final Y: " << answer.second << endl;



	return 0;
}
