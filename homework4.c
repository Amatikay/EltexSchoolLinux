#include <stdio.h>

#define DIRECTORYSIZE 100
#define FIELDSIZE 10

struct abonent {
	char name[FIELDSIZE];
	char second_name[FIELDSIZE];
	char tel[FIELDSIZE];
};

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
			print_abonent(directory[i]);
		}
	}	
};

void print_abonent(struct abonent* abonent){
	printf("Имя: %s\n", abonent->name);
	printf("Фамилия: %s\n", abonent->second_name);
	printf("Телефон: %s\n", abonent->tel);
};

void print_directory(struct abonent* directory) {
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

int main(){

	struct abonent directory[DIRECTORYSIZE] = {0};
	int chose = 0;
	int size = 0;
	
	while(chose != 5){
		printf("\n\n1) Добавить абонента\n"
	  				 "2) Удалить абонента\n"
	   				 "3) Поиск абонентов по имени\n"
	   				 "4) Вывод всех записей\n"
	   				 "5) Выход\n");
	  int chose = 0;
		
		scanf("%d", &chose);
		
		getchar();
		switch(chose){
			case 1:
				if(size < DIRECTORYSIZE){
					// Нет проверки на размер введенной строки.
					struct abonent abonent;
					printf("Имя: ");
					
					fgets(abonent.name, FIELDSIZE, stdin);

					printf("Фамилия: ");
				
					fgets(abonent.second_name, FIELDSIZE, stdin);

					printf("Телефон: ");

					fgets(abonent.tel, FIELDSIZE, stdin);

					add(directory, abonent);
					size++;
				} else {
					printf("Справочник заполнен!");
					};
				
				break;
			case 2:
						int delete_number = -1;
						printf("Номер абонента для удаления: ");
						scanf("%d", &delete_number);
						
						if (delete_number >= 0 && delete_number <= DIRECTORYSIZE){
							remove_abonent(directory+delete_number);	
						} else{
							printf("Неверный номер для удаления");
						};
						
				break;
			case 3:
				printf("Введите имя для поиска: ");
				char name[FIELDSIZE] = {0};
				fgets(name, FIELDSIZE, stdin);
				printf("====================\n"
				 			 "======Абоненты======\n"
				 			 "====================\n\n");
				find(name, directory);
				break;
			case 4:
				print_directory(directory);
				break;
			case 5:
				return 0;				
				break;
		}

	}
   return 0;
}
