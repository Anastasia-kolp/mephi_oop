CC = g++
CFLAGS = -c -Wall
XXFLAGS = -lgtest -lpthread

all: prog2 test

prog2: main.o FoliumOfDescrates.o utility.o
	$(CC) main.o FoliumOfDescrates.o utility.o -o prog2

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

FoliumOfDescrates.o: FoliumOfDescrates.cpp
	$(CC) $(CFLAGS) FoliumOfDescrates.cpp

utility.o: utility.cpp
	$(CC) $(CFLAGS) utility.cpp

test: test.cpp
	$(CC) test.cpp -o test $(XXFLAGS)

clean:
	rm -rf *.o prog2 test
