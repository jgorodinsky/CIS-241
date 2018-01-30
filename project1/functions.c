#include "functions.h"
#include <stdlib.h>

int main(int argc, char* argv[]){
	int choice = -1;
	FILE *fin, *fout;
	
	//put down below with other error
	//if(argc != 5)

	char *myString = argv[1];
	
	if(myString[0] == 'e')
		choice = 0;
	else if(myString[0] == 'd')
		choice = 1;
	
	if(choice == -1){
		printf("Error: Please enter a valid input.\n");
		exit(1);
	}

	return 0;
}

char * removeDuplicates(char word[]){
	char* used = "";
	int len = strlen(word);
	int i = 0;
	while(i < len){
		if(strchr(used, word){
		}
		i++;
	}

	return '0';
}
