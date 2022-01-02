CC=g++
CFLAGS=-I.
DEPS = hotel.h

main: main.cpp hotel.cpp
	$(CC) main.cpp hotel.cpp ${CFLAGS}