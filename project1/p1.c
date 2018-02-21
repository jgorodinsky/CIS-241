#include "functions.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>


int main(int argc, char* argv[])
{
        int choice, len, n = 0;
        char *key_arr, encrypt[27], decrypt[26];
        FILE *fin, *fout;

        if (argc != 5)
        {
                printf ("Usage: cipher option key infile, outfile\n");
                printf ("Option 1 for encryption and 2 for decryption");
                exit(1);
        }

        len = 26;

        key_arr = (char*)malloc(len * sizeof(char));

        char *myString = argv[1];

        if(myString[0] == 'e')
                choice = 0;
        else if(myString[0] == 'd')
                choice = 1;
        else{
                printf("Error: Please enter a valid input.\n");
                exit(1);
        }
	
        strcpy(key_arr, argv[2]);
        strcpy(key_arr, removeDuplicates(key_arr));
        printf("%s\n", key_arr);
        initializeEncryptArray(key_arr, encrypt);
        initializeDecryptArray(encrypt, decrypt);

        printf("%s\n", encrypt);
        printf("%s\n\n", decrypt);

        fin = fopen(argv[3], "r");
        fout = fopen(argv[4], "w");

        if (fin ==  NULL || fout == NULL)
        {
                printf("File could not be opened\n");
                exit(1);
        }

        if(choice == 0){
                processInput(fin, fout, encrypt);
        }
        else{
                processInput(fin, fout, decrypt);
        }

        return 0;
}

