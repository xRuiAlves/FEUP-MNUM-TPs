/************************************************

	In this example, I am integrating the function
	x * y beetween y=3 and y=8 and between x=4 and x=12.
	Even tho I am using a relatively low step for both
	X and Y directions (hA = hB = 0.5) , I got the value
	1760. The analitical values is also 1760, the result
	was exact!

*************************************************/


#include <vector>
#include <iostream>


double foo ( double x , double y ) { return (x*y); }

double simpson(std::vector<double> points , double h) {
	double i_odds = 0;
	double i_evens = 0;
	double integral = 0;

	// Compute the odds
	for (unsigned int i=1 ; i<points.size()-1 ; i+=2){
		i_odds += points.at(i);
	}

	// Computhe the evens
	for (unsigned int i=2 ; i<points.size()-1 ; i+=2){
		i_evens += points.at(i);
	}

	i_odds *= 4;	// Odd terms have coeficient 4
	i_evens *= 2;	// Even terms have coeficient 2 (except y0 and yn)
	integral += i_odds + i_evens;

	integral += points.at(0);	// y0
	integral += points.at(points.size()-1);	// yn

	integral *= h/3;	// I = h/3 * (y0 + 4y1 + 2y2 + 4y3 + ... + 4y(n-3) + 2y(n-2) + 4y(n-1) + y(n) )

	return integral;
}

int main(){

	const double a = 3;
	const double A = 8;
	const double b = 4;
	const double B = 12;
	const double hA = 0.5;
	const double hB = 0.5;
	const unsigned int nA = (A-a)/hA;
	const unsigned int nB = (B-b)/hB;


	// Apply the Simpson's method to every row of the integration "square", and save the results in a vector
	std::vector<double> simpson_averages;
	std::vector<double> row;
	for(unsigned int i=0 ; i<=nA ; i++){
		row.clear();
		for(unsigned int j=0 ; j<=nB ; j++){
			row.push_back(foo (a + i*hA , b + j*hB));
		}
		simpson_averages.push_back(simpson(row, hB));
	}

	// Apply the Simpson's method to the averages vector, thus completing the double integration
	std::cout << simpson(simpson_averages , hA);

	return 0;
}
