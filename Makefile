all: memgrind.c mymalloc.o
	gcc -O -g -o memgrind memgrind.c mymalloc.o

mymalloc.o: mymalloc.c
	gcc -c mymalloc.c

clean:
	rm -rf memgrind; rm mymalloc.o

run:
	./memgrind
