# File: Makefile
# Author: Anderson Taylor & Trey Howell
# Makefile for the Library program.

# Compiler Version
CC=g++

# Debugging flag -g
DEBUG=-g

# Target
TARGET=library

# Compile with all errors and warnings
CFLAGS=-c -Wall $(DEBUG)

# Makefile syntax:
# target: dependencies
#(tab) system command(s)

all: $(TARGET)

$(TARGET): main.o Library.o
	$(CC) main.o Library.o -o $(TARGET)

main.o: main.cpp Library.h
	$(CC) $(CFLAGS) main.cpp

list.o: Library.cpp Library.h
	$(CC) $(CFLAGS) Library.cpp

clean:
	rm *.o *~ $(TARGET)

