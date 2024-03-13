#include "stdio.h"
#include "math.h"

// 1 

void print_square_matrix(const int N){

	int matrix[N][N];
	int counter = 1;
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N ; j++){
			matrix[i][j] = counter; 
			counter++;
		}
	}

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N ;j++){	
			printf("%d\t",matrix[i][j]); 
		}
		printf("\n");
	}
	
}

// 2 

void print_reverse_array(const int* array, const int size ){

	for(int i = size - 1; i >= 0; i--){
		printf("%d\t", array[i]);
	}
}

// 3
void fill_matrix_by_zero_ones(const int size ,int (*matrix)[size]){

	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			if (i+j < size - 1){
				// (*(*(matrix + i) + j) = 1;
				matrix[i][j] = 0;
			}
			else {
				// (*(*(matrix + i) + j) = 0;
				matrix[i][j] = 1;
			}
		}
	}
	
}

void print_matrix(const int size ,int (*matrix)[size]){
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size ;j++){	
			printf("%d\t",matrix[i][j]); 
		}
		printf("\n");
	}
}

void fill_matrix_as_snail(const int size ,int (*matrix)[size]){
	int row_step_iterator = 0;
	int column_step_iterator = 0;
	int max = pow(size, 2)   ;
	int temp = 1;
	int direction_tmp = 1;
	while(temp <= max){

		switch(direction_tmp){
			case 1:
				for(int j = row_step_iterator; j < size - row_step_iterator; j++){
					matrix[column_step_iterator][j] = temp;
					temp++;
				}
				for(int i = 1 + column_step_iterator ; i < size - column_step_iterator ; i++ ){
					matrix[i][size - 1 - row_step_iterator] = temp;
					temp++;
				}
				row_step_iterator++;
				direction_tmp = 0;
				break;
				
			case 0:
				for(int j = size - 1 - (column_step_iterator + 1) ; j >= column_step_iterator ; j--){
					matrix[size- 1 - column_step_iterator][ j ] = temp;
					temp++;
				}
		
				for(int i = size - 1 - (column_step_iterator + 1)  ; i > column_step_iterator ; i-- ){
					matrix[i][(column_step_iterator )] = temp;
					temp++;
				}
				column_step_iterator++;
				direction_tmp = 1;
				break;
				
		}
	}
}


int main(){
	const int N = 6;
	int matrix[N][N] = {} ;
	
	int array[] = {1,2,3,4,5,6}; 

	print_square_matrix(N);
	printf("\n");
	
	print_reverse_array( array, N);
	printf("\n");
	
	fill_matrix_by_zero_ones(N,matrix);
	printf("\n");
	
	print_matrix(N,matrix);
	printf("\n");

	fill_matrix_as_snail(N,matrix);
	printf("\n");

	print_matrix(N,matrix);
	printf("\n");
	return 0;
}
