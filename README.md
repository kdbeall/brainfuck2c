# Brainfuck2C
A simple Brainfuck to C source to source compiler written in C.
In other words, this program converts Brainfuck source code to C source code.
The program also checks for mismatched curly braces and indents the outputted C code.



To use this program, do the following.
I'll assume you're using Linux and gcc.

Open up your terminal in a directory of your choice (preferably an empty one or 
one you use for playing around with programs). Let's, clone this repository.

```shell
git clone https://github.com/kdbeall/Brainfuck2C.git
```

Next, *cd* into the newly created Brainfuck2C directory.

```shell
cd Brainfuck2C
```

Next, let's build the program.
There's a Makefile ready to be used.

```shell
make
```

Our program is now ready to be used!

Recall, our program takes a Brainfuck source file .bf and outputs a .c source file.
It takes the two file names as command-line arguments.

```shell
./brainfuck2c [Your Brainfuck file] [Your output C file]
```

I've included a test folder with a single test file.
To run the helloworld example, do the following.

```shell
./brainfuck2c ./test/helloworld.bf ./test/helloworld.c
```

Next, *cd* to the test directory.

```shell
cd test
```

Next compile the helloworld.c file with gcc.
```shell
gcc -Wall -std=c99 helloworld.c -o helloworld
```

Last, but not least, run it.

```shell
./helloworld

```

The following should be printed to your terminal.
```shell
Hello World!
```

