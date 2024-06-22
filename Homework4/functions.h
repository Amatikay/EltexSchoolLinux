#ifndef __FUNCTIONS__
#define __FUNCTIONS__
#define DIRECTORYSIZE 100
#define FIELDSIZE 10

struct abonent {
	char name[FIELDSIZE];
	char second_name[FIELDSIZE];
	char tel[FIELDSIZE];
};

int hash_abonent(struct abonent abonent);

int hash_string(char* string);

void add(struct abonent* directory, struct abonent abonent );

void remove_abonent(struct abonent* abonent);

void find(char* name, struct abonent* directory );

void print_abonent(struct abonent* abonent);

void print_directory(struct abonent* directory);

#endif
