CC = g++
CFLAGS = -c -Wall
XXFLAGS = -lgtest -lpthread

all: lab3_d test

lab3_d: main.o utility.o
	$(CC) -o lab3_d main.o utility.o -Llib -lDiceD

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

utility.o: include/utility.cpp
	$(CC) $(CFLAGS) include/utility.cpp

test: test.cpp
	$(CC) test.cpp -o test $(XXFLAGS) -Llib -lDiceD

clean:
	rm -rf *.o lab3_d test
