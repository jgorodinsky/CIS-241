all: functions.h functions.o p1.o
	gcc -o p functions.o p1.o

p1.o: functions.h p1.c
	gcc -c p1.c

functions.o: functions.h functions.c
	gcc -c functions.c

enc: 
	./p e GOODMORNING test.txt test.out

dec: 
	./p d GOODMORNING test.out test.bak

test:
	./p e GOODMORNING test.txt test.out
	./p d GOODMORNING test.out test.bak
	diff -s test.txt test.bak

clean:
	rm -f *.o p test.out test.bak

