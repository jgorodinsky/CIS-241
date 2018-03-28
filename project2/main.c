#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "operations.h"

int main(int argc, char* argv[]){
	if(argc == 2)
		doIt(*(argv+1));
	else{
		char input[] = "data.txt";
		doIt(input);
	}
	return 0;

}
