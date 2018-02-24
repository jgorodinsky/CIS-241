#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "operations.h"

void print_messages();

int main(int argc, char* argv[]){

	printf("\nWelcome to Kroger++\n");	

	print_messages();
	
	int choice;

	//Gets user input
	scanf("%d", &choice);
//	printf("You have chosen %d\n", choice);
	printf("\n");

	ITEM item;
	
}

void print_messages(){
	char border[] = "==========================================================";


        char* options[] = {
                                "Add product to store" , "Purchase product from store",
                                "Check price of a product", "Show products in store",
                                "Clean up a product from store", "Find product",
                                "Inventory", "Done for today"

                        };

        char welcome_message[] = "please enter a number ";

        int options_size = ((char) sizeof(options)/sizeof(options[0]));


        printf("%s[%d-%d]\n%s\n", welcome_message, 1, options_size, border);

        int i = 0;

        //Allows for increase in menu options
        //FOR MODULIZATION JUST PRINT IT ONE BY ONE, I++, BUT WHENEVER I % 2 == 0, PRINT A NEW LINE
        for(i = 0; i < options_size; i+=2){
                printf("%d%s%-32s%d%s%-32s\n", i+1, ": ", options[i], i+2, ": ", options[i+1]);
        }

        printf("%s\n", border);
}
