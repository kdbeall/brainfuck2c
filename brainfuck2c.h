/**
    @file brainfuck2c.h
    @author kdbeall

    Headerfile for our brainfuck2c program.

*/

//Begin include directives.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//End include directives.

//Begin Macros
#define ARRAY_SIZE          30000
#define INCREMENT           "++ptr;"
#define DECREMENT           "--ptr;"
#define INCREMENT_CELL      "++*ptr;"
#define DECREMENT_CELL      "--*ptr;"
#define OUTPUT              "putchar(*ptr);"
#define INPUT               "*ptr=getchar();"
#define JMP_FORWARD         "while (*ptr) {"
#define JMP_BACK            "}"
#define SPACE               ' '

#define INCREMENT_BF        '>'
#define DECREMENT_BF        '<'
#define INCREMENT_CELL_BF   '+'
#define DECREMENT_CELL_BF   '-'
#define OUTPUT_BF           '.'
#define INPUT_BF            ','
#define JMP_FORWARD_BF      '['
#define JMP_BACK_BF         ']'


#define USAGE_ERROR         "Invalid ascii value %d in BrainFuck Code."
#define ERROR               "Unmatched brackets\n"
#define ERRORC              100


//End macros.


//Begin prototypes.

/**
    Creates the array and pointer at the start of our compiled Brainfuck program in C.
    @param out A file pointer to output C file.
 */
void createArray(FILE *out);

/**
    Create the main method.
    @param out A file pointer to output C file.
 */
void createMainMethod(FILE *out);

/**
   Ends our main method.
    @param out A file pointer to output C file.
 */
void endMain(FILE *out);

/**
    Compiles our Brainfuck source.
    @param in A file pointer to input brainfuck file.
    @param out A file pointer to output C file.
    @return If have an error during our compilation or not.

 */
bool compile(FILE *in, FILE *out);

/**
    Prints out spaces to indent the start
    of the line. Note, we print out 2d spaces.
    @param out A file pointer to output C file.
    @param d The indentation depth.
 */
void indent( FILE *out, int d );


/**
    Checks to ensure our indentation is correct.
    Exit with error if incorrect.

    @param d The current indentation level.
 */
void checkDent( int d );

//End prototypes.
