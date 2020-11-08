CC=gcc -Wall

tp:algo.o main.o
	$(CC) algo.o main.o -o tp

main.o : main.c
	$(CC) main.c -c

algo.o : algo.c algo.h
	$(CC) algo.c algo.h -c

clean :
	rm *.o *h.gch tp