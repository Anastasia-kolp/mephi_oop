CC = g++
CFLAGS = -c -Wall

all: lab3

lab3: main.o utility.o
	$(CC) -o lab3 main.o utility.o -Llib -lDice

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

utility.o: include/utility.cpp
	$(CC) $(CFLAGS) include/utility.cpp

clean:
	rm -rf *.o lab3
