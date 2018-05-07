all:bin build prog

bin:
	mkdir -p bin

build:
	mkdir -p build

prog: build/chesinput.o build/board_print_plain.o build/plain.o
	g++ -Wall -Werror build/chesinput.o build/board_print_plain.o build/plain.o -o prog

build/chesinput.o: src/chesinput.cpp
	g++ -Wall -Werror -c src/chesinput.cpp -o build/chesinput.o

build/board_print_plain.o: src/board_print_plain.cpp
	g++ -Wall -Werror -c src/board_print_plain.cpp -o build/board_print_plain.o

build/plain.o: src/plain.cpp
	g++ -Wall -Werror -c src/plain.cpp -o build/plain.o 
	
.PHONY: clean
clean:
	rm -rf build bin
