#include <iostream>
#include <vector>

double foo(double x) { return (x*x*x*x); }

int main(){

	/* Integrate f(x) between 0 and 2 */
	const double h = 0.5;
	const unsigned int n = 4;		// The integration limits are [0 .. n*h] : In this case, integrating foo(x) from 0 to 2

	/* Make the list */
	std::vector<double> values;

	for (unsigned int i=0 ; i<(n+1) ; i++){
		values.push_back(foo(i*h));
	}


	/* Compute the Integral Value */
	double Is = 0, Is_odds = 0, Is_evens = 0;



	for (unsigned int i=1 ; i<n ; i+=2)	Is_odds += values.at(i);	// The odd terms , the 4*y.. terms

	for (unsigned int i=2 ; i<n ; i+=2)	Is_evens += values.at(i);	// The odd terms , the 4*y.. terms

	Is_odds *= 4;				// 4*(odd terms)

	Is_evens *= 2;				// 2*(even terms)

	Is += values.at(0);			// y0

	Is += values.at(n);			// yn

	Is += Is_odds + Is_evens;		// y0 + 4*y1 + 2*y2 + ... + 2*y(n-2) + 4*y(n-1) + yn

	Is = Is*h/3;				// h/3 * (y0 + 4*y1 + 2*y2 + ... + 2*y(n-2) + 4*y(n-1) + yn)


	/* Display the Result */
	std::cout << "Result: " << Is;



	return 0;
}
