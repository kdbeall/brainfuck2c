/**
    @file dent.c
    @author Keng-Hui D. Beall (kdbeall)

    This program reads text from standard input and outputs
    properly indented code based on the nesting depth of
    curly brackets.

    The program will read from standard input until EOF is reached.
    The program will replace spaces and tabs ocurring at the
    start of each line with 2d spaces, where d is the current
    indentation depth. Each time the program reads an opening curly
    brace '{' it will increase the indentation depth. Each time it
    reads a closing curly brace '}' it will decrease the indentation
    depth.

    As a program reads an input line, it will discard spaces at the
    start of the line until it reaches a non-whitespace character.
    Then, it will print out spaces to properly indent the line
    and print the rest of the line exactly like it appears in the input.

    However, we have two special cases:
      1. Lines containing only whitespace.
      2. Lines starting with a closing curly bracket '}'

    If a line contains only white space, it should be printed as a
    blank line.

    If a line starts with a closing curly bracket, the indentation level
    should be reduced before the curly bracket is printed. To keep our
    program simple, this will only work for curly bracket and not
    arbitrarily many.

    We will only handle one error. If curly braces are unmatched.
    In this case, the program will exit with a status of 100 and
    print an error message.

 */

//Begin include directives.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//End include directives.

//Begin macros.

/** Space character in hex. */
#define SPACE      0x20
/** Tab character in hex. */
#define TAB        0x9
/** New line character. */
#define NEW_LINE   '\n'
/** Closed curly bracket character. */
#define CC_BRACKET 0x7D
/** Open curly bracket character. */
#define OC_BRACKET 0x7B
/** Error message for unmatched brackets. */
#define ERROR      "Unmatched brackets\n"
/** Error code. */
#define ERRORC     100
/** Exit with success. */
#define SUCCESS    0
//End macros.

//Begin Function Prototypes.
void indent( int d);
bool isASpace( char ch );
bool isNewLine( char ch );
void checkDent( int d );
//End Function Prototypes.

/**
    Starts indentation process.

    @return EXIT_SUCCESS if no errors or EXIT_FAILURE if errors.

 */
int main()
{

  int d = 0;
  bool discardWhiteSpace = true;
  bool lineStart = true;
  int ch;
  while ( (ch = getchar()) != EOF ){
    //begin a new line
    if ( isNewLine(ch) ){
      putchar(ch);
      lineStart = true;
      discardWhiteSpace = true;
      continue;
    }

    if (lineStart){
      if ( ch == CC_BRACKET ){
        d--;
        checkDent(d);
        indent(d);
        putchar(ch);
        discardWhiteSpace = false;
      }else if ( ch == OC_BRACKET ){
        indent(d);
        putchar(ch);
        d++;
        discardWhiteSpace = false;
      }else if ( !isASpace(ch) ){
        indent(d);
        putchar(ch);
        discardWhiteSpace = false;
      }
      lineStart = false;
    }else if ( discardWhiteSpace ){
      if (isASpace(ch) ){
        continue;
      }else{
        if (ch == CC_BRACKET){
          d--;
          checkDent(d);
        }
        indent(d);
        putchar(ch);
        discardWhiteSpace = false;
        if (ch == OC_BRACKET){
          d++;
        }
      }
    }else if ( !discardWhiteSpace ){
      if (ch == OC_BRACKET){
        d++;
      }else if (ch == CC_BRACKET){
        d--;
        checkDent(d);
      }
      putchar(ch);
    }
  }
  //Check if unbalanced at end
  if (d != 0){
    printf( ERROR );
    exit( ERRORC );
  }
  exit( SUCCESS );
}

/**
    Prints out spaces to indent the start
    of the line. Note, we print out 2d spaces.

    @param d The indentation depth.
 */
void indent( int d )
{

  for ( int i = 0; i<2*d; i++ ){

    putchar( SPACE );

  }

}

/**
    Checks if a character is a space or tab.

    @param ch An arbitrary character to check.

    @return Whether the character is a space or tab or not.

 */
bool isASpace( char ch )
{

  if ( ch == SPACE || ch == TAB ){

    return true;
  }

  return false;

}

/**
   Checks if a character is a new line.

   @param ch An arbitrary character to check.

   @return Whether the character is a newline or not.
 */
bool isNewLine( char ch )
{
  if (ch == NEW_LINE){

    return true;

  }

  return false;

}

/**
    Checks to ensure our indentation is correct.
    Exit with error if incorrect.

    @param d The current indentation level.
 */
void checkDent( int d )
{
  if ( d < 0 ){
    printf( ERROR );
    exit( ERRORC );
  }
}
