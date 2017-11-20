#include <iostream>
#include <vector>

double foo(double x) { return x; }

int main(){

	/* Integrate f(x) between 0 and 2 */
	const double h = 0.5;
	const unsigned int n = 4;		// The integration limits are [0 .. n*h] : In this case, integrating foo(x) from 0 to 2

	/* Make the list */
	std::vector<double> values;

	for (unsigned int i=0 ; i<(n+1) ; i++){		// n intervals  -->  n+1 values
		values.push_back(foo(i*h));
	}


	/* Compute the Integral Value */
	double It = 0;

	for (unsigned int i=1 ; i<n ; i++)	It += values.at(i);	// (y1 ... y(n-1))

	It *= 2;					// 2*(y1 ... y(n-1))

	It += values.at(0);			// y0

	It += values.at(n);			// yn

	It = h/2 * It;				// h/2*(y0 + y1 + ... + yn)


	/* Display the Result */
	std::cout << "Result: " << It;



	return 0;
}
