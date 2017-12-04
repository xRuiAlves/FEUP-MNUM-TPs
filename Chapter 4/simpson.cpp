/*******************************************************

 In this example i am integrating x^4 between values
 5 and 10. With a step equal to 0.5 , i got the value
 19375 for the integral. The analitacal solution is ...
 ... 19375!

 This method works very well, because it doesn't
 have a harder calculation than the "Trapezio" method. Allthough,
 Trapezio is a 2nd order method and Simpson is a 4th order method.
 This means that, with Simpson's method, if we reduce the step (h)
 to half, we are lowering the absolute error 2^order = 2^4 = 16 times!

*******************************************************/

#include <vector>
#include <iostream>


double foo ( double x ) { return (x*x*x*x); }

int main(){

   const double a = 5;
	  const double b = 10;
	  const double h = 0.5;
	  const unsigned int n = (b-a)/h;

	  double i_odds = 0;
	  double i_evens = 0;
	  double integral = 0;

	  // Make the list
	  std::vector<double> values;

	  for (unsigned int i=0 ; i<=n ; i++){
	  	values.push_back(foo(a + i*h));
  	}

	  // Compute the odds
	  for (unsigned int i=1 ; i<n ; i+=2){
	   	i_odds += values.at(i);
	  }

	  // Computhe the evens
	  for (unsigned int i=2 ; i<n ; i+=2){
	   	i_evens += values.at(i);
	  }

  	i_odds *= 4;	// Odd terms have coeficient 4
	  i_evens *= 2;	// Even terms have coeficient 2 (except y0 and yn)
  	integral += i_odds + i_evens;

  	integral += values.at(0);	// y0
  	integral += values.at(n);	// yn

  	integral *= h/3;	// I = h/3 * (y0 + 4y1 + 2y2 + 4y3 + ... + 4y(n-3) + 2y(n-2) + 4y(n-1) + y(n) )

  	std::cout << integral;

  	return 0;
}
