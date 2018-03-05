#include "operations.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void print_messages(){
	system("clear");

        char border[] = "==========================================================";


        char* options[] = {
                                "Add product to store" , "Purchase product from store",
                                "Check price of a product", "Show products in store",
                                "Clean up a product from store", "Find product",
                                "Inventory", "Done for today"

                        };

        char welcome_message[] = "Welcome to Kroger++\nplease enter a number ";

        int options_size = ((char) sizeof(options)/sizeof(options[0]));


        printf("%s[%d-%d]\n%s\n", welcome_message, 1, options_size, border);

        int i = 0;

        //Prints Menu Options
        //FOR MODULIZATION JUST PRINT IT ONE BY ONE, I++, BUT WHENEVER I % 2 == 0, PRINT A NEW LINE
        for(i = 0; i < options_size; i+=2){
                printf("%d%s%-32s%d%s%-32s\n", i+1, ": ", options[i], i+2, ": ", options[i+1]);
        }

        printf("%s\n", border);
}

int insert(product **l, product node){
	return 0;
}

void rmItem(product *l, product *node){	
}

void showList(product *l){
	
}

int loadData(char inf[], product **l){
	return  0;
}

int saveData(char outf[], product *l){
	//save data to file
	
	//free data
	struct product* tmp;
        while(l != NULL){
                tmp = l;
                l = l -> next;
                free(tmp);
        }

	return 0;
}

float purchase(product *l, char product[], float q){
	return q;
}

void check_price(product *l, char p[]){
}

void findItem(product *l, char p[]){
}

int doIt(char data[]){
	int choice = -1;

	//load data
	
	//ask input
	while(choice != 0){
		print_messages();	
		scanf("%d", &choice);
		//switch statement
	}
	//save data

	return 0;
}
