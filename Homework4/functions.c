#include <stdio.h>
#include "functions.h"

int hash_abonent(struct abonent abonent){
	int sum = 0;
	for (int i = 0; i < FIELDSIZE; i++){
		sum = sum + abonent.name[i] + abonent.second_name[i] + abonent.tel[i];
	}
	return sum;
};

int hash_string(char* string){
	int sum = 0;
	for (int i = 0; i < FIELDSIZE; i++){
		sum = sum + string[i];
	}
	return sum;
};


void add(struct abonent* directory, struct abonent abonent ){ 
	
	if(hash_abonent(directory[0]) == 0){
		directory[0] = abonent;	
	}else{
		int i = 1;
		while(hash_abonent(directory[i]) != 0 ){
			i++;
		}
		directory[i] = abonent;
	}
};

void remove_abonent(struct abonent* abonent){ 
	char* ptr = abonent;
	for( int i = 0; i < (int)sizeof(struct abonent);	i++	){
		*(ptr + i) = 0;
	}
};

void find(char* name, struct abonent* directory ){ 
	int hash_name = hash_string(name);
	for(int i = 0; i < DIRECTORYSIZE; i++){
		int hash_name_tmp = 0;
		hash_name_tmp = hash_name_tmp + hash_string(directory[i].name);
		if (hash_name_tmp == hash_name){
			print_abonent(&directory[i]);
		}
	}	
};

void print_abonent(struct abonent* abonent){
	printf("Имя: %s\n", abonent->name);
	printf("Фамилия: %s\n", abonent->second_name);
	printf("Телефон: %s\n", abonent->tel);
};

void print_directory(struct abonent* directory){
	printf("====================\n"
				 "======Абоненты======\n"
				 "====================\n\n");
	for (int i = 0; i < DIRECTORYSIZE; i++) {
	
  	if (hash_abonent(directory[i]) != 0) {
			printf("Абонент %d\n", i);
    	print_abonent(&directory[i]);
    }
  }
}
