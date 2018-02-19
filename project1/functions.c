#include "functions.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
/*
int main(int argc, char* argv[]){
	int choice, len;
	char *key, encrypt[26], decrypt[26];
	
	//put down below with other error
	//if(argc != 5)

	char *myString = argv[1];
	
	if(myString[0] == 'e')
		choice = 0;
	else if(myString[0] == 'd')
		choice = 1;
	else{
		printf("Error: Please enter a valid input.\n");
                exit(1);
	}
	

	//printf("%d\n", choice);

	key = removeDuplicates(argv[2]);

	printf("%s\n", key);
	printf("%s\n", argv[3]);
	
	initializeEncryptArray(key,encrypt);

	printf("%s\n", encrypt);	

	initializeDecryptArray(encrypt, decrypt);
	removeDuplicates(decrypt);	

	printf("%s\n", decrypt);

	FILE *fin = fopen(argv[3], "r");
	FILE *fout = fopen(argv[4], "w");

	if(choice == 0){
		processInput(fin, fout, encrypt);
	} else{
		processInput(fin, fout, decrypt);
	}

	return 0;
}
*/

int main(int argc, char* argv[])
{  
	int choice, key, len, n = 0;
	char ch, *key_arr, encrypt[27], decrypt[26];
	FILE *fin, *fout;

	if (argc != 5)
	{
		printf ("Usage: cipher option key infile, outfile\n");
		printf ("Option 1 for encryption and 2 for decryption");
		exit(1);
	}

		choice = atoi(argv[1]);
	key = atoi(argv[2]);


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

	key_arr = argv[2];

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

	/*while ( fscanf(fin, "%c", &ch) != EOF )
	{
		key = encrypt[n%len];
	
		printf("%c\n", encrypt[n%len]);

		if (choice == 1)
               		key = -key;

		fprintf(fout, "%c", encryptChar(ch, key));
		n++;
	}

	fclose(fin);
	fclose(fout);*/

	if(choice == 0){
		processInput(fin, fout, encrypt);
	}
	else{
		processInput(fin, fout, decrypt);
	}

	return 0;
}

char* removeDuplicates(char word[]){
	int length = sizeof(word)/sizeof(word[0]);
	
	int i;

	for(i = 1; i < length; i++){
		//printf("%d %c\n",i, word[i]);
		if(word[i] == '\0'){
			break;
		}
		//printf("%d %d\n", i, targetFound(word, i, word[i]));
		if(targetFound(word, i, word[i]) == 1){
			//move all elements after i left one
			int j;
			for(j=i; j < length; j++){	
					word[j] = word[j+1];
			}			

			length = sizeof(word)/sizeof(word[0]);
			i--;
		}
	}
	
	//word[i] = '\0';
	
	return word;
}

int targetFound(char charArray[], int num, char target){
	int i;
	for(i = 0; i < num; i++){
		if(charArray[i] == target){
			return 1;
		}
	}	

	return 0;
}

void initializeEncryptArray(char key[], char encrypt[]){
	char alpha[] = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
	
	int i, j = 0, start;
	
	int length = sizeof(key)/sizeof(key[0])-1;
	for(i = 0; i < length; i++){
		if(key[i] == '\0'){
			length = i;
			break;
		}
		encrypt[i] = key[i];
	}

	start = length;

	length = sizeof(alpha)/sizeof(alpha[0]) - 1;
	

	for(i = start; i < length; i++){
		if(j == 26){
			break;
		}	
			while(targetFound(encrypt, i, alpha[j])){
				j++;
				if(j == 26){
					break;
				}
			}		
			encrypt[i] = alpha[j];
		j++;
	}
	encrypt[i] = '\0';
}

void initializeDecryptArray(char encrypt[], char decrypt[]){
	char alpha[] = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
	char beta[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	//int length = sizeof(encrypt)/sizeof(encrypt[0])-1;
	int length = 26, LEN = 26;
	//printf("%d\n", length);
        int i, j;

	char *p1, *p2;


	 i = 0;
    	 j = 0;

	/*p2 = &alpha[0];
	p1 = &encrypt[0];
    	while ( i < LEN){

		//j = i;
        	p1 = &encrypt[i];
        	p2 = &alpha[0];
	
        	while ( j < LEN){
		
			while(i < LEN){
				p1 = &encrypt[i];
				p2 = &alpha[j];
				if ( strncmp(p1,p2, LEN - 1 - i) == 0 && i != LEN - 1){
	
					p1 = &encrypt[0];
					printf("%c\n", p1[i-1]);
					strcpy(decrypt, encrypt);
					return;
				}
				i++;	
			}	
			//printf("\n");
			j++;
			i = j;
			p2 = &alpha[j];
			//p2 = strnsub(p2, i);
			p1 = &encrypt[i];
        	}
		//i++;
		i = j;
                //p2 = strnsub(p2, LEN - 1 - j);
               
    }
*/

	for(i = 0; i < length; i++){
		//decrypt[i] = beta[i];
	}

	for(i = 0; i < strlen(encrypt); i++){
		decrypt[i] = encrypt[i] - i;
	}

	decrypt[i] = '\0';


}

char* strnsub (char *p, int n)
{
    	char *pntr;
    	int i;
 
    	//allocates memory of appropriate size to the pointer
	pntr = malloc(n + 1);
         
        for(i = 0; i < n; i++){
                *(pntr+i) = *(p);
		p++;
	}
	*(pntr+i) = '\0';
                                         
	return pntr;
}
    
char encryptChar(char ch, int k)
{
	if ( k < 0 )
		k = k + 26;

	if ( isupper(ch) )
		return (ch - 'A' + k) % 26 + 'A';
	
	if ( islower(ch) )
		return (ch - 'a' + k) % 26 + 'a';
	
	return ch;
}   

void processInput(FILE * inf, FILE *outf, char substitute[]){
	char ch;
	int key, n = 0, len = 25;


        /*if (inf ==  NULL || outf == NULL)
        {
                printf("File could not be opened\n");
                exit(1);
        }

        while ( fscanf(inf, "%c", &ch) != EOF )
        {
                key = substitute[n%len];

                fprintf(outf, "%c", encryptChar(ch, letter_convert(key)));
                n++;
        }*/


	 while ( fscanf(inf, "%c", &ch) != EOF )
        {
                key = substitute[n%len];

                //printf("%c\n", substitute[n%len]);

                //if (choice == 1)
                  //      key = -key;

                fprintf(outf, "%c", encryptChar(ch, key));
                n++;
        }

       // fclose(fin);
        //fclose(fout);


        fclose(inf);
        fclose(outf);

	
}


int letter_convert(char ch){
//https://stackoverflow.com/questions/1469711/converting-letters-to-numbers-in-c
	int rtn = 0;
	if (ch >= 'A' && ch <= 'Z')
		rtn = ch - 'A';
	else if (ch >= 'a' && ch <= 'z')
		rtn = ch - 'a'; 		
	return rtn;
}
