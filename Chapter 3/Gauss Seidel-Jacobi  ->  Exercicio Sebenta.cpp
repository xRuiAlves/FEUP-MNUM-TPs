#include <iostream>
#include <cmath>

using namespace std;

void gauss_seidel(double x0, double y0 , double z0 , unsigned int num_iter){
	double x = x0;
	double y = y0;
	double z = z0;

	cout << "Iteracao no. " << 0 << endl;
	cout << "[ " << x << " , " << y << " , " << z << " ]" << endl;
	cout << "Residuo em X: " << abs(24 - 7*x - 2*y) << endl;
	cout << "Residuo em Y: " << abs(27 - 4*x - 10*y - z) << endl;
	cout << "Residuo em Z: " << abs(27 - 5*x + 2*y - 8*z) << endl << endl;

	for (unsigned int i=1 ; i<=num_iter ; i++){
		x = (24 - 2*y)/7;
		y = (27 - 4*x - z)/10;
		z = (27 - 5*x + 2*y)/8;

		cout << "Iteracao no. " << i << endl;
		cout << "[ " << x << " , " << y << " , " << z << " ]" << endl;
		cout << "Residuo em X: " << abs(24 - 7*x - 2*y) << endl;
		cout << "Residuo em Y: " << abs(27 - 4*x - 10*y - z) << endl;
		cout << "Residuo em Z: " << abs(27 - 5*x + 2*y - 8*z) << endl << endl;
	}
}

void gauss_jacobi(double x0, double y0 , double z0 , unsigned int num_iter){
	double x = x0;
	double y = y0;
	double z = z0;
	double xn , yn , zn;

	cout << "Iteracao no. " << 0 << endl;
	cout << "[ " << x << " , " << y << " , " << z << " ]" << endl;
	cout << "Residuo em X: " << abs(24 - 7*x - 2*y) << endl;
	cout << "Residuo em Y: " << abs(27 - 4*x - 10*y - z) << endl;
	cout << "Residuo em Z: " << abs(27 - 5*x + 2*y - 8*z) << endl << endl;

	for (unsigned int i=1 ; i<=num_iter ; i++){
		xn = (24 - 2*y)/7;
		yn = (27 - 4*x - z)/10;
		zn = (27 - 5*x + 2*y)/8;

		x = xn;
		y = yn;
		z = zn;

		cout << "Iteracao no. " << i << endl;
		cout << "[ " << x << " , " << y << " , " << z << " ]" << endl;
		cout << "Residuo em X: " << abs(24 - 7*x - 2*y) << endl;
		cout << "Residuo em Y: " << abs(27 - 4*x - 10*y - z) << endl;
		cout << "Residuo em Z: " << abs(27 - 5*x + 2*y - 8*z) << endl << endl;
	}
}


int main(){

	const double x0 = 0;
	const double y0 = 0;
	const double z0 = 0;

	gauss_jacobi( x0 , y0 , z0 , 4);

	cout << "\n  *** PRESS ENTER ***\n";
	getchar();

	gauss_seidel( x0 , y0 , z0 , 4);


	return 0;
}
