#include "stdio.h"
#include "math.h"

#define int_length sizeof(int)*8 -1 

void print_binary_representation_int(const int number){
	for (int i= sizeof(int)*8 -1; i>=0; i--){
		printf("%d", ((number >> i)& 1) );
	}
}

// Вообще если передать на вход print_binary_representation_int
// она корректно конвертирует отрицательное, но я проделаю эту операцию

void print_binary_representation_negative_int(const int number){

	char number_bytes[ int_length ];

	
	for (int i = int_length ; i>=0; i--){
			number_bytes[i] = !(number >> i)& 1;
	}
	
	number_bytes[0]  = number_bytes[0] ^ 0b1 ;
	
	for (int i= int_length; i>=0; i--){
		printf("%d", number_bytes[i]) ;
	}
}

int number_of_ones(const int number){
	int j = 0;
	for (int i= sizeof(int)*8 -1; i>=0; i--){
		if ((number >> i)& 1) {
			j+= 1 ;
		}
	}
	return j;
}



int change_positeve_int_third_byte(const int number, const int byte){

	char number_bytes[ int_length ];

	
	for (int i = int_length ; i>=0; i--){
			number_bytes[i] = (number >> i)& 1;
	}
	
	printf("\nChange binary view\n");

	number_bytes[2] = (char)byte;
	
	for (int i = int_length ; i>=0; i--){
		printf("%d",number_bytes[i]);
	}
	
	int new_number = 0;

	for (int i = int_length; i >= 0; i--) {
        new_number += number_bytes[i] * (1 << i);
    }
    
	printf("\nChange int view:%d\n",new_number);
	return new_number;
}



int main(){

    
	int number = 0;
	int byte = 0;

		
	scanf("%d %d", &number, &byte);

	printf("Binary represintation positive int %d\n", number);
		
	print_binary_representation_int(number);

	printf("\nBinary represintation negative int %d\n",number);

	print_binary_representation_negative_int(number);
	
	printf("\nNumber of ones:%d", number_of_ones(number));
	
	change_positeve_int_third_byte(number,byte);

	return 0;
}
