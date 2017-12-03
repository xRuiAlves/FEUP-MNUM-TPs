/*******************************************************

 In this example i am integrating x^2 between values
 4 and 10. With a step equal to 0.1 , i got the value
 312.01 for the integral. The analitacal solution is 312.
 The error was very small ( 0.01 ) because i am using a very
 low step!

 This method works fine, but Simpson's method works better,
 without harder calculations associated. This method is a 2nd
 order method: When we lower the step by half , the error will
 be reduced by 2^order = 2^2 = 4 times! This is good, but Simpson's
 method, being 4th order, diminishes the error by 16 times by lowering
 the step with the same amount, without more work. That being said,
 Simpson's method is highly prefered!!

*******************************************************/

#include <iostream>
#include <vector>

using namespace std;

double foo(double x) { return (x*x); }

int main(){

	const double a = 4;
	const double b = 10;
	const double h = 0.1;
	const unsigned int n = (b-a)/h;

	double integral = 0;

	// Make the list
	vector<double> values;
	for (double i = 0; i <= n ; i++){
		values.push_back(foo(a + i*h));
	}


	// Compute the middle terms (all except y0 and yn)
	for (unsigned int i=1 ; i<n ; i++){
		integral += values[i];
	}

	integral *= 2; 	// The middle terms have coeficient 2

	integral += values[0];	// y0
	integral += values[n];	// yn

	integral *= h/2;		// I = h/2 * (y0 + 2y1 + 2y2 + ... + 2y(n-1) + y(n) )

	cout << integral << endl;

	return 0;
}
