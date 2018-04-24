.PHONY: all clean install uninstall
CC=g++
CFLAGS=-c -Wall
GCCFLAGS = -c -Wall -Werror
VPATH = src
PATH_SRC = ./src/
PATH_BUILD = ./build/
SOURCES=chesinput.cpp board_print_plain.cpp plain.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=prog

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
	
clean: rm -rf *.o prog
