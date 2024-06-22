#include "functions.h"
#include <stdio.h>

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
	  
		scanf("%d", &chose);
		
		getchar(); // Очистка буфера 
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
}
