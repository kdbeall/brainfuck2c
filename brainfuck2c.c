/**
    @file brainfuck2c.c
    @author kdbeall,jstofer21

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

//Begin Macros
#define ARRAY_SIZE     30000
#define INCREMENT      "++ptr;"
#define DECREMENT      "--ptr;"
#define INCREMENT_CELL "++*ptr;"
#define DECREMENT_CELL "--*ptr;"
#define OUTPUT         "putchar(*ptr);"
#define INPUT          "*ptr=getchar();"
#define JMP_FORWARD    "while (*ptr) {"
#define JMP_BACK       "}"

#define INCREMENT_BF        '>'
#define DECREMENT_BF        '<'
#define INCREMENT_CELL_BF   '+'
#define DECREMENT_CELL_BF   '-'
#define OUTPUT_BF           '.'
#define INPUT_BF            ','
#define JMP_FORWARD_BF      '['
#define JMP_BACK_BF         ']'

#define USAGE_ERROR         "Invalid ascii value %d in BrainFuck Code."
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

    @return false if  we have an error, else no errors
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
  printf("char array[%d] = {0};\n", ARRAY_SIZE);
  printf("char *ptr = array;\n");
}

void createMainMethod()
{
  printf("int main()\n");
  printf("{\n");

}

void endMain()
{
  printf("}\n");
}

bool compile()
{
  int ch;
  while( (ch = getchar()) != EOF ){
    switch(ch){
      case INCREMENT_BF:
        printf("%s\n", INCREMENT);
        break;

      case DECREMENT_BF:
        printf("%s\n", DECREMENT);
        break;

      case INCREMENT_CELL_BF:
        printf("%s\n", INCREMENT_CELL);
        break;

      case DECREMENT_CELL_BF:
        printf("%s\n", DECREMENT_CELL);
        break;

      case OUTPUT_BF:
          printf("%s\n", OUTPUT);
          break;

      case INPUT_BF:
          printf("%s\n", OUTPUT);
          break;

      case JMP_FORWARD_BF:
          printf("%s\n", JMP_FORWARD);
          break;

      case JMP_BACK_BF:
          printf("%s\n", JMP_BACK);
          break;
      //Error message
      default:
          printf(USAGE_ERROR, ch);
          return false;
    }
    printf("\n");
  }
  return true;
}


