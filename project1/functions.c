#include "functions.h"

int main(int argc, char* argv[]){
	int choice = -1;

	char *myString = argv[1];
	
	if(myString[0] == 'e')
		choice = 0;
	else if(myString[0] == 'd')
		choice = 1;
	
	printf(argv[1]);
	printf("\n");
	printf("%d", choice);
	printf("\n");


	return 0;
}
