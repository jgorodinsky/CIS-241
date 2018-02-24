#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string.h>

typedef struct Item ITEM;

struct Item{
	char name[20];
	float quantity;
	char q_unit[20];
	double price;
	char p_unit[20];

	ITEM* next_item;
};


#endif
