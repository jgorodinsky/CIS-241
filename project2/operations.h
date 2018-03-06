#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string.h>

#define N 20

typedef struct product{
	char name[N];
	float quantity;
	char q_unit[N];
	double price;
	char p_unit[N];

	struct product *next;
} product;

//insert a node to the list
int insert(product *l, product node);

//remove a node from list
void rmItem(product *l, product *node);

//show list
void showList(product *l);

//load data from file inf
int loadData(char inf[], product **l);

//save data to file outf
int saveData(char outf[], product *l);

//sell purchase product of quantity q
float purchase(product *l, char product[], float q);

//check out price of product p from list l
void check_price(product *l, char p[]);

//find product p from list l
void findItem(product *l, char p[]);

//the job starts here, start with loading data from the file data, and preform the functions by calling related functions.  Ends at saving data to the file data
int doIt(char data[]);

//Prints out the welcome and options messages
void print_messages();

#endif
