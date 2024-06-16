#include <stdio.h>

#define N 10
#define STRSIZE 100

// Задание 1

int main() {

	int a = 0;
	char *ptr = &a;
	ptr = ptr + 3;

	scanf("%d %d", &a, ptr);

	printf("%d", a);
	
	return 0;
}

// Задание 2

int main(void)
{

	float x = 5.0;
	printf("x = %f, ", x);
	float y = 6.0;
	printf("y = %f\n", y);
	float *xp = &y;  
	float *yp = &y;
	printf("Результат: %f\n", *xp + *yp);
}
 

// Задание 3

int main(){
	int array[N]= {};
	for (int i = 0; i < N; i++){
		*(array + i)  =  i + 1;
	}

	for (int i = 0; i < N; i++){
		printf("%d ", *(array + i));
	}
	puts("\n");
	return 0;
}

// Задание 4

int number_sumbols_in_string(char* string){
	int string_length = 0;
	char* ptr_string = string;
	while(*ptr_string){ 
		string_length++;
		ptr_string++;
	}
	return string_length;
}

int sum_of_string(char* string, char* end){
	int sum = 0;
	for(char* ptr_i = string; ptr_i < end; ptr_i++ ){
		sum = sum + *ptr_i;
	}
	return sum;
}

int main(){
	char string[STRSIZE] = {};
	char substring[STRSIZE] = {};

	fgets(string, STRSIZE, stdin);
	fgets(substring, STRSIZE, stdin);
	
	int len_substring = number_sumbols_in_string(substring);
	int len_string = number_sumbols_in_string(string);
	int sum_substr = sum_of_string(substring, (substring + len_substring));

	int i = 0;

	char* result_ptr = NULL;// результурующий указатель
	
	// Пока не достигну максимально возможного индекса, или "хеш" строки и подстроки совпадет.
	while( (i <= len_string - len_substring) ){
		if (sum_substr == sum_of_string((string + i), (string + i + len_substring ) ) ){
			result_ptr = string + i;
			break;
		}
		i++;
	}


	if (result_ptr){
		printf("Начало посдтроки с симовола номер: %d.\nСимвол: %c\n", (result_ptr - string), *result_ptr );	
	}else{
		printf("NULL\n");
	}
	
	return 0;
}
