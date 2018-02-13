#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 4

char* strnsub (char *p, int n);

int main()
{
    char line[] = "His textbook was bought from that bookstore";  
    char *p1, *p2;

    //set p1 to the beginning of string line;
    p1 = &line[0];
	
    int i = 0;
    int j = 0;
    while ( i < sizeof(line)-1-LEN){
        //set p2 to the position immediately after p1
	j = i + LEN ;
        p1 = &line[i];
        p2 = &line[j];
	
        while ( j < sizeof(line) -1 - LEN){

	    // use strncmp() to compare if a match is found
            if ( strncmp(p1,p2, LEN) == 0)
            {
                printf("The original string is:\n%s\n", line);
                printf("The first substring:  %s\n", strnsub(p1, LEN));
                printf("The second substring: %s\n", strnsub(p2, LEN));
                return 0;
            }
               j++;
	        p2 = &line[j];

        }
	i++;
        j = i + LEN;
    }
    printf("No repeated patterns of length %d in the following string:\n%s\n",
            LEN, line);
    return 0;
}


// returns a string with the first n characters of string p
// https://www.programmingsimplified.com/c/source-code/c-substring
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

