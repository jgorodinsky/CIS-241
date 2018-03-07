#include "functions.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

/*
 * Remove duplicate characters in array word
 * return the resulting string
 */
char* removeDuplicates(char word[]){
	int length = strlen(word);
	
	int i, pos;

	for(i = 1; i < length; i++){
		//if the current char is the terminating value
		if(word[i] == '\0'){
			break;
		}
		if(targetFound(word, i, word[i]) == 1){
			//move all elements after i left one
			int j;
			for(j=i; j < length; j++){	
					word[j] = word[j+1];
			}			

			length = strlen(word);
			i--;
		}
	}
	
	word[i] = '\0';
	return word;
}

/*
 * Search the first nun characters in array charArray for 
 * 	character target
 * return a non-zero integer if found, otherwise, returns zero
 */
int targetFound(char charArray[], int num, char target){
	int i;
	for(i = 0; i < num; i++){
		if(charArray[i] == target){
			return 1;
		}
	}	

	return 0;
}

/*
 * Initialize the encrypt array with appropriate cipher letters 
 * 	according to the given key
 */
void initializeEncryptArray(char key[], char encrypt[]){
	//reverse alphabet
	char alpha[] = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
	
	int i, j = 0, start;
	
	int length = strlen(key);
	for(i = 0; i < length; i++){
		if(key[i] == '\0'){
			length = i;
			break;
		}
		encrypt[i] = key[i];
	}

	start = length;

	length = strlen(alpha);

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

/*
 * Initialize the decrypt array with appropriate substitute letters based on the *	encrypt array
 */
void initializeDecryptArray(char encrypt[], char decrypt[]){
	//alphabet
	char beta[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int i;

	 i = 0;

	for(i = 0; i < strlen(encrypt); i++){
		decrypt[encrypt[i]-'A'] = beta[i];
	}

	decrypt[i] = '\0';

}

/*
 * Return a substring of n length from *p
 */
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

/*
 * Takes data from the inf, encrypt/decrypts it, then
 * 	sends the output to the outf
 */
void processInput(FILE * inf, FILE *outf, char substitute[]){
	char ch;


	 while ( fscanf(inf, "%c", &ch) != EOF )
        {
                if(isupper(ch)){
			ch = substitute[ch-'A'];
		}

                fprintf(outf, "%c", ch);
        }

        fclose(inf);
        fclose(outf);
	
}
