/*
 * gauss.cpp
 *
 *  Created on: 03/01/2018
 *      Author: Rui Alves
 */


#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


typedef vector<vector<double> > matrix;

/* Row_A = Row_A - Row_B * k */
void rowop(matrix & m , unsigned int a , unsigned int b , double k){
	for(unsigned int i=0 ; i<m[0].size() ; i++){
		m[a][i] -= k*m[b][i];
	}
}

/***

  Gauss method

  m - matrix to solve

 ***/
void gauss(matrix & m){

	for (unsigned int i=0 ; i<m.size() ; i++){
		rowop(m , i , i , 1-1/m[i][i]);
		for (unsigned int j=0 ; j<m.size() ; j++){
			if (i != j)	rowop(m , j , i , m[j][i]);
		}
	}

}

/* Print a matrix on the screen */
void print_matrix(const matrix & m){
	for (unsigned int i=0 ; i<m.size() ; i++){
		for (unsigned int j=0 ; j<m[0].size() ; j++){
			cout << m[i][j] << '\t';
		}
		cout << '\n';
	}
}


int main(){
	// Set printing precision
	cout << fixed;
	cout.precision(6);


	// Make the matrix
	matrix m = {{ 95 , 3   , 1  , 2  , 101},
				{ 4  , 100 , 10 , 5  , 119},
				{ 3  , 9   , 55 , 5  , 72 },
				{ 10 , 2   , 4  , 80 , 96 }};


	// Print the matrix before solving
	print_matrix(m);


	// Perform the method
	gauss(m);


	// Print the matrix after solving
	cout << endl;
	print_matrix(m);

	return 0;
}
