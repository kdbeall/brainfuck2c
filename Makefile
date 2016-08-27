CFLAGS=-Wall -std=c99
all:
	gcc -Wall -std=c99 brainfuck2c.c -o brainfuck2c

clean:
	rm -f brainfuck2c
