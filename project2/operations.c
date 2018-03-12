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
        for(i = 0; i < options_size; i+=2){
                printf("%d%s%-32s%d%s%-32s\n", i+1, ": ", options[i], i+2, ": ", options[i+1]);
        }

        printf("%s\n", border);
}

int insert(product **l, product *node){
	product* tmp = *l;

	if(tmp == NULL){
		tmp = (product*)malloc(sizeof(product));
		tmp = node;
		tmp -> next = *l;
		*l = tmp;
	}
	else{

		while(tmp -> next != NULL){
			tmp = tmp -> next;
		}
		tmp -> next = node;
	}
	
	return 0;
}

void rmItem(product *l, product *node){	
	product *tmp = l;

	if(tmp != NULL){

		if(strcmp(tmp -> name, node -> name) == 0){
			tmp = l -> next;
			free(tmp);
			return;
		}

		if(tmp -> next != NULL){
			while(tmp -> next != NULL && strcmp(tmp -> next -> name, node -> name) != 0){
				tmp = tmp -> next;
			}

			/*if(tmp -> next == NULL){
				printf("\n   ERROR:  Item not found\n");
				return;
			}*/

			if(strcmp(tmp -> next -> name, node -> name) == 0){
				product *children = tmp -> next -> next;
				free(tmp -> next);
				tmp -> next = children;
				return;
			}
		}

	//	printf("\n    ERROR: Item not found\n");
	
	}
	else{
		printf("\n    ERROR: List empty\n");
	}
		
}

void showList(product *l){
	product *tmp = l;
	
	printf("\n   PRODUCT LIST:\n");
		
	while(tmp != NULL){
		if(!(tmp -> price == 0 && tmp -> quantity == 0)){
			printf("   %s\n", tmp -> name);
		}
		tmp = tmp -> next;
	}	
}

int loadData(char inf[], product **l){
	//printf("%s\n", inf);
	FILE* fin;
	fin = fopen(inf, "r");

	if(fin == NULL){
		printf("failed");
		return 1;
	}

	char *split;	
	
	char line[256];
	while(fgets(line, sizeof(line), fin)){
		int i = 0;
		char *info[5];		

		split = strtok(line, " ");

		while(split != NULL){
			info[i++] = split;
			split = strtok(NULL, " ");
		}

		product* tmp;
		tmp = (product*)malloc(sizeof(product));

		strcpy(tmp -> name, info[0]);
		tmp -> quantity = atof(info[1]);
		strcpy(tmp -> q_unit, info[2]);
		tmp -> price = atof(info[3]);
		strcpy(tmp -> p_unit, info[4]);	
		tmp -> next = NULL;
	
		if(!(tmp -> quantity == 0 && tmp -> price == 0)){	
			insert(l, tmp);
		}	
	}


	fclose(fin);

	return  0;
}

int saveData(char outf[], product *l){
	//save data to file
	FILE *fout;
	fout = fopen(outf, "w");

	if(fout == NULL)
		return 1;
	
	
	product *tmp = l;

	while(tmp != NULL){
			if(!(tmp -> quantity == 0 && tmp -> price == 0)){
				fprintf(fout, "%s %f %s %lf %s", tmp -> name, tmp -> quantity, tmp -> q_unit, tmp -> price, tmp -> p_unit);
			}
			tmp = tmp -> next;
	}


	fclose(fout);
	
	//free data
        while(l != NULL){
                tmp = l;
                l = l -> next;
                free(tmp);
        }

	return 0;
}

float purchase(product *l, char product[], float q){
	
	struct product *tmp = l;

	while(tmp != NULL){
		if(strcmp(tmp -> name, product) == 0){

			if( q <= tmp -> quantity){
				tmp -> quantity = tmp -> quantity - q;
				
				printf("\n   %s has %.2f %s remaining\n", tmp -> name, tmp -> quantity, tmp -> q_unit);	
				return tmp -> quantity;
			}
			
			printf("\n   ERROR: buy amount greater than stock\n");
			return tmp -> quantity;
		}		

		tmp = tmp -> next;
	}
	
	printf("\n   ERROR: product not found\n");
	return q;
}

void check_price(product *l, char p[]){
	product *tmp = l;

	while(tmp != NULL){
		if(strcmp(tmp -> name, p) == 0){
			printf("\n   %s costs %.2lf %s(s)\n", tmp -> name, tmp -> price, tmp -> p_unit);
			return;	
		}
		
		tmp = tmp -> next;
	}

	printf("\n   ERROR: product \"%s\" not found\n");
	return;
}

void findItem(product *l, char p[]){
	product *tmp = l;
	
	float q = 0;

	while(tmp != NULL){
                if(strcmp(tmp -> name, p) == 0){
                        q = tmp -> quantity;
			break;
                }

                tmp = tmp -> next;
        }

	if(tmp == NULL){
		printf("\n   ERROR: product not found\n");
		return;
	}

	if(!(tmp -> quantity == 0 && tmp -> price == 0)){
		printf("\n   We have %.2lf %s(s) in stock\n", q, tmp -> name);
	}
}

int doIt(char data[]){


	int choice = 0;

	//load data
	product* head;
	head = (product*)malloc(sizeof(product));
	loadData(data, &head);

	//ask input
	while(choice != 8){
		print_messages();	
		scanf("%d", &choice);
	
		product* tmp = (product*)malloc(sizeof(product));
		tmp -> next = NULL;

		switch(choice){
			case 1:
				printf("What is the product's name?\n");
				scanf("%20s", tmp -> name);
	
				printf("How many of these products are there?\n");
				scanf("%f", &tmp -> quantity);

				printf("What quantity unit does this product use?\n");
				scanf("%20s", tmp -> q_unit);

				printf("How much does this product cost?\n");
				scanf("%lf", &tmp -> price);				

				printf("What price unit does this product use?\n");
				scanf("%20s", tmp -> p_unit);				
			
				insert(&head, tmp);
				break;
			case 2:
				printf("What is the name of the product being purchased?\n");
				scanf("%20s", tmp -> name);
				
				printf("How many units are being purchased?\n");
				scanf("%f", &tmp -> quantity);

				purchase(head, tmp -> name, tmp -> quantity);
	
				break;
			case 3:
				printf("What item's price is being checked?\n");
				scanf("%20s", tmp -> name);				
	
				check_price(head, tmp -> name);
				break;
			case 4:
				showList(head);
				break;
			case 5:
				printf("What is the name of the product being removed?\n");
				scanf("%20s", tmp -> name);

				rmItem(head, tmp);
				break;
			case 6:
				printf("What is the name of the product we are looking for?\n");
				scanf("%20s", tmp -> name);

				findItem(head, tmp -> name);
				break;
			case 7:
				tmp = head;
				while(tmp != NULL){
					findItem(tmp, tmp -> name);
					tmp = tmp -> next;
					//printf("\n");
				}
				break;
		}
		if(choice != 8){
			printf("\nPress ENTER to continue\n");
			
			//catches '\n'
			getchar();
		
			//waits for user input
			getchar();
		}
	}

	//save data
	saveData(data, head);
	return 0;
}
