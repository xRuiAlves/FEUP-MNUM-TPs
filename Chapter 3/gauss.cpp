#include <iostream>

void rowop(double matrix[4][5] , int a , int b , double k){
	for (unsigned int i=0 ; i<5 ; i++){
		matrix[a][i] -= matrix[b][i]*k;
	}
}

int main(){

	double matrix[4][5] = { { 95 , 3   , 1  , 2  , 101},
			                { 4  , 100 , 10 , 5  , 119},
							{ 3  , 9   , 55 , 5  , 72 },
							{ 10 , 2   , 4  , 80 , 96 }};

	for (unsigned int i=0 ; i<4 ; i++){
		rowop(matrix,i,i,1-1/matrix[i][i]);
		for (unsigned int j=0 ; j<4 ; j++){
			if (i != j){
				rowop(matrix,j,i,matrix[j][i]);
			}
		}
	}

	for (unsigned int i=0 ; i<4 ; i++){
		for (unsigned int j=0 ; j<5 ; j++){
			std::cout << matrix[i][j] << "  ";
		}
		std::cout << "\n\n";
	}




	return 0;
}
