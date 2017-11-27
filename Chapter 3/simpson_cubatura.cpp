#include <iostream>
#include <vector>

double foo(double x , double y) { return (x*y); }

double simpson(const std::vector<double> v, double h){
	/* Compute the Integral Value */
	double Is = 0, Is_odds = 0, Is_evens = 0;
	double n = v.size()-1;

	for (unsigned int i=1 ; i<n ; i+=2)	Is_odds += v.at(i);	// The odd terms , the 4*y.. terms

	for (unsigned int i=2 ; i<n ; i+=2)	Is_evens += v.at(i);	// The odd terms , the 4*y.. terms

	Is_odds *= 4;				// 4*(odd terms)

	Is_evens *= 2;				// 2*(even terms)

	Is += v.at(0);				// y0

	Is += v.at(n);				// yn

	Is += Is_odds + Is_evens;	// y0 + 4*y1 + 2*y2 + ... + 2*y(n-2) + 4*y(n-1) + yn

	Is = Is*h/3;				// h/3 * (y0 + 4*y1 + 2*y2 + ... + 2*y(n-2) + 4*y(n-1) + yn)

	return Is;
}

int main(){

	/* Integrate f(x,y) between [a , A] in the Y axis and [b , B] in the X axis */
	const double hx = 0.5;
	const double hy = 0.5;
	const unsigned int nx = 4;		// The integration limits are [0 .. nx*hx] : In this case, integrating foo(x,y) from 0 to 2 in x axis
	const unsigned int ny = 4;		// The integration limits are [0 .. ny*hy] : In this case, integrating foo(x,y) from 0 to 2 in y axis

	/* Make the list */
	std::vector< std::vector<double> > values;
	std::vector<double> row;

	for (unsigned int j=0 ; j<(ny+1) ; j++){
		row.clear();
		for (unsigned int i=0 ; i<(nx+1) ; i++){
			row.push_back(foo(i*hx , j*hy));
		}
		values.push_back(row);
	}

	/* Apply the simpson's method to each row */
	std::vector<double> rows_averages;

	for(unsigned int j=0 ; j<values.size() ; j++){
		rows_averages.push_back(simpson(values.at(j),hx));
	}

	/* Apply the simpson's method to the row's averages, thus making the "cubatura" */
	std::cout << "Result: " << simpson(rows_averages, hy);


	return 0;
}
