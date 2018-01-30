#include <stdio.h>

// remove duplicate characters in array word and return the resulting string
char* removeDuplicates(char word[]);

//search the first num characters in array charArray for character target
//return a non-zero integer if found, otherwise, return 0
int targetFound(char charArray[], int num, char target);

//initialize decrpyt array with appropriate substitute letters based on the encrypt array
void initializeDecryptArray(char encrypt[], char decrypt[]);

//process data from the input file and write the result to the output file
//pass the encrypt array to parameter substitute if encryption is intended
//pas the decrypt array to parameter substitute if decryption is intended
void processInput(FILE* inf, FILE* outf, char substitute[]);
