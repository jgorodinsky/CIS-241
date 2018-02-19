functions: functions.o
		gcc functions.o -o functions
functions.o: functions.c

test: test1 test2
test1:
	./functions e ABC  test.txt test.out
test2:
	./functions d ABC test.out test.bak
test3:
	./functions f TEST
test4:
	./functions e ZAB
test5:
	./functions e D
