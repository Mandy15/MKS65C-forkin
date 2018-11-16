all: forkin.o
	gcc -o forkin forkin.o

forkin.o: forkin.c
	gocc -c forkin.c

clean:
	rm forkin forkin.o

run:
	./forkin
