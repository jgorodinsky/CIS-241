#include "operations.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void print_messages(){
	system("clear");

        char border[] = "==========================================================";


        char* options[] = {
                                "Add product to store" , "Purchase product",
                                "Check price of a product", "Show products in store",
                                "Remove product from store", "Find product",
                                "Inventory", "Exit"

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

int insert(product *l, product *node){
	product* tmp = l;

	while(tmp -> next != NULL){
		tmp = tmp -> next;
	}
	tmp -> next = node;
	return 0;
}

void rmItem(product *l, product *node){	
}

void showList(product *l){
	product *tmp = l;
	
	while(tmp != NULL){
		printf("%s\n", tmp -> name);
		tmp = tmp -> next;
	}	
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
	int choice = 0;
	char in_char[N];

	//load data
	
	product* head;
	head = (product*)malloc(sizeof(product));

	//DELETE AFTER IMPLEMENTING FILE LOADING
	strcpy(head -> name, "AY");
	head -> next = NULL;

	//ask input
	while(choice != 8){
		print_messages();	
		scanf("%d", &choice);
	
		product* tmp = (product*)malloc(sizeof(product));
		tmp -> next = NULL;

		switch(choice){
			case 1:;
				printf("What is the product's name?\n");
				scanf("%20s", tmp -> name);
	
				printf("How many of these products are there?\n");
				scanf("%f", &tmp -> quantity);

				printf("What quantity unit does this product use?\n");
				scanf("%20s", tmp -> q_unit);

				printf("How much does this product cost?\n");
				scanf("%f", &tmp -> price);				

				printf("What price unit does this product use?\n");
				scanf("%20s", tmp -> p_unit);				
			
				insert(head, tmp);
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				showList(head);
				printf("Press ENTER to continue\n");
				getchar();
				getchar();
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
			default:
				break;
		}
	}
	//save data
	
	//deallocate data
	free(head);
	return 0;
}
