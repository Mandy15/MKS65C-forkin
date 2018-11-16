all: forkin.o
	gcc -o forkin forkin.o

forkin.o: forkin.c
	gcc -c forkin.c

clean:
	rm forkin forkin.o

run:
	./forkin
