.PHONY: all clean install uninstall
GCCFLAGS = -c -Wall -Werror
VPATH = src
PATH_SRC = ./src/
PATH_BUILD = ./build/

all: prog

prog: chesinput.o board_print_plain.o plain.o
	g++ chesinput.o board_print_plain.o plain.o -o $(PATH_BUILD)prog

chesinput.o: chesinput.cpp
	g++ $(GCCFLAGS) $(PATH_SRC)chesinput.cpp

board_print_plain.o: board_print_plain.cpp
	g++ $(GCCFLAGS) $(PATH_SRC)board_print_plain.cpp
	
plain.o: plain.cpp
	g++ $(GCCFLAGS) $(PATH_SRC)plain.cpp
	
clean: rm -rf *.o
