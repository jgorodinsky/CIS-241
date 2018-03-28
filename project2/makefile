all: operations.h main.o operations.o
	gcc -o test operations.o main.o

operations.o: operations.h operations.c
	gcc -c operations.c

main.o: operations.h main.c
	gcc -c main.c	

clean: 
	rm -f *.o main test operations

test:
	./test data.txt ay


