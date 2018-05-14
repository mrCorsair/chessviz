prog:bin build bin/prog
test:bin build bin/test

bin:
	mkdir -p bin

build:
	mkdir -p build

bin/prog: build/chesinput.o build/board_print_plain.o build/plain.o
	gcc -Wall -Werror build/chesinput.o build/board_print_plain.o build/plain.o -o bin/prog
	
bin/test:build/board_print_plain.o build/plain.o build/test.o build/in.o
	gcc -Wall -Werror build/board_print_plain.o build/plain.o build/test.o build/in.o -o bin/test

build/chesinput.o: src/chesinput.c
	gcc -Wall -Werror -c src/chesinput.c -o build/chesinput.o

build/board_print_plain.o: src/board_print_plain.c
	gcc -Wall -Werror -c src/board_print_plain.c -o build/board_print_plain.o

build/plain.o: src/plain.c
	gcc -Wall -Werror -c src/plain.c -o build/plain.o 

build/test.o: test/test.c
	gcc -Wall -c test/test.c -o build/test.o -Ithirdparty -Isrc

build/in.o: test/in.c
	gcc -Wall -c test/in.c -o build/in.o -Ithirdparty
	
.PHONY: clean
clean:
	rm -rf build bin
