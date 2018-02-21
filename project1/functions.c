#include "functions.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

char* removeDuplicates(char word[]){
	int length = strlen(word);
	
	int i, pos;

	for(i = 1; i < length; i++){
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

void initializeDecryptArray(char encrypt[], char decrypt[]){
	char beta[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int i;

	 i = 0;

	for(i = 0; i < strlen(encrypt); i++){
		decrypt[encrypt[i]-'A'] = beta[i];
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


int letter_convert(char ch){
//https://stackoverflow.com/questions/1469711/converting-letters-to-numbers-in-c
	int rtn = 0;
	if (ch >= 'A' && ch <= 'Z')
		rtn = ch - 'A';
	else if (ch >= 'a' && ch <= 'z')
		rtn = ch - 'a'; 		
	return rtn;
}
