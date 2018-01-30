#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char encrypt(char ch, int k);

int letter_convert(char ch);


int main(int argc, char* argv[])
{  
	int choice, key, *key_arr, len, n = 0;
	char ch;
	FILE *fin, *fout;

	if (argc != 5)
	{
		printf ("Usage: cipher option key infile, outfile\n");
		printf ("Option 1 for encryption and 2 for decryption");
		exit(1);
	}

	choice = atoi(argv[1]);
	key = atoi(argv[2]);


	len = strlen(argv[2]);
	key_arr = (int*)malloc(len * sizeof(int));	

	char *myString = argv[2];

	int i = 0;
	while(i < len){
		key_arr[i] = letter_convert(myString[i]);
		i++;
        }

    	fin = fopen(argv[3], "r");
	fout = fopen(argv[4], "w");
    
    	if (fin ==  NULL || fout == NULL) 
	{
		printf("File could not be opened\n");
		exit(1);
	}

	while ( fscanf(fin, "%c", &ch) != EOF )
	{
		key = key_arr[n%4];
	
		if (choice == 2)
               		key = -key;

		fprintf(fout, "%c", encrypt(ch, key));
		n++;
	}

	fclose(fin);
	fclose(fout);

	return 0;
}

char encrypt(char ch, int k)
{
	if ( k < 0 )
		k = k + 26;

	if ( isupper(ch) )
		return (ch - 'A' + k) % 26 + 'A';
	
	if ( islower(ch) )
		return (ch - 'a' + k) % 26 + 'a';
	
	return ch;
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
