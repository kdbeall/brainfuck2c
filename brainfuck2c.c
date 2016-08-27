/**
    @file brainfuck2c.c
    @author kdbeall,

    Simple example of a source to source compiler;
    compiles Brainfuck to C.

    This program will take input from the standard input (piped in)
    and then output to standard output (piped out) from the terimal.

    Input will be a Brainfuck source file.
    Output will be the equivalent C source.

 */

//Begin include directives.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//End include directives.

//Begin macros.
#define ARRAY_SIZE     30000
#define INCREMENT      "++ptr;"
#define DECREMENT      "--ptr;"
#define INCREMENT_CELL "++*ptr;"
#define DECREMENT_CELL "--*ptr;"
#define OUTPUT         "putchar(*ptr);"
#define INPUT          "*ptr=getchar();"
#define JMP_FORWARD    "while (*ptr) {"
#define JMP_BACK       "}"
//End macros.


//Begin prototypes.

/**
    Creates the array and pointer at the start of our compiled Brainfuck program in C.

 */
void createArray();

/**
    Create the main method.
 */
void createMainMethod();

/**
   Ends our main method.
 */
void endMain();

/**
    Compiles our Brainfuck source, which is read from standard input.

    @return true if  we have an error, else no errors
 */
bool compile();


//End prototypes.


/**
    Begins compilation.
    @return program exit status
 */
int main()
{
  if(compile()){
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}

void createArray()
{
  printf("char array[%d] = {0};", ARRAY_SIZE);
  printf("\n");
  printf("char *ptr = array;");
  printf("\n");

}

void createMainMethod().
{
  printf("int main()\n");
  printf("{\n");

}

void endMain()
{



}

bool compile()
{


}


