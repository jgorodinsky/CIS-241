#include "operations.h"
#include <string.h>

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

        //Prints Menu Options
        //FOR MODULIZATION JUST PRINT IT ONE BY ONE, I++, BUT WHENEVER I % 2 == 0, PRINT A NEW LINE
        for(i = 0; i < options_size; i+=2){
                printf("%d%s%-32s%d%s%-32s\n", i+1, ": ", options[i], i+2, ": ", options[i+1]);
        }

        printf("%s\n", border);
}

