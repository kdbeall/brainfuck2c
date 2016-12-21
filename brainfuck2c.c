/**
    @file brainfuck2c.c
    @author kdbeall,jstofer21

    Simple example of a source to source compiler;
    compiles Brainfuck to C.

    This program will take input from command-line arguments.

    Input will be a Brainfuck source file.
    Output will be the equivalent C source.

 */


#include "brainfuck2c.h"


/**
    Begins compilation.
    @return program exit status
 */
int main(int argc, char *argv[])
{
  if(argc != 3){
    return EXIT_FAILURE;
  }
  FILE *in = fopen(argv[1], "r");
  if(!in){
    perror(argv[1]);
    return EXIT_FAILURE;
  }
  FILE *out = fopen(argv[2], "w");
  if(!out){
    perror(argv[2]);
    return EXIT_FAILURE;
  }


  createMainMethod(out);
  createArray(out);
  if(!compile(in, out)){
    return EXIT_FAILURE;
  }
  endMain(out);


  
  return EXIT_SUCCESS;
}

void createArray(FILE *out)
{
  fprintf(out, "  char array[%d] = {0};\n", ARRAY_SIZE);
  fprintf(out, "  char *ptr = array;\n");
}

void createMainMethod(FILE *out)
{
  fprintf(out, "int main()\n");
  fprintf(out, "{\n");

}

void endMain(FILE *out)
{
  fprintf(out, "}\n");
}

bool compile(FILE *in, FILE *out)
{

  int ch;
  int d = 1;
  while( (ch = fgetc(in)) != EOF ){
    checkDent(d);
    switch(ch){
      case INCREMENT_BF:
        indent(out, d);
        fprintf(out, "%s\n", INCREMENT);
        break;

      case DECREMENT_BF:
        indent(out, d);
        fprintf(out, "%s\n", DECREMENT);
        break;

      case INCREMENT_CELL_BF:
        indent(out, d);
        fprintf(out, "%s\n", INCREMENT_CELL);
        break;

      case DECREMENT_CELL_BF:
        indent(out, d);
        fprintf(out, "%s\n", DECREMENT_CELL);
        break;

      case OUTPUT_BF:
          indent(out, d);
          fprintf(out, "%s\n", OUTPUT);
          break;

      case INPUT_BF:
          indent(out, d);
          fprintf(out, "%s\n", OUTPUT);
          break;

      case JMP_FORWARD_BF:
          indent(out, d);
          fprintf(out, "%s\n", JMP_FORWARD);
          d++;
          break;

      case JMP_BACK_BF:
          indent(out, d-1);         
          fprintf(out, "%s\n", JMP_BACK);
          d--;
          break;


      //We choose to ignore invalid ASCII characters than print an error.
      default:
         //fprintf(stderr, USAGE_ERROR, ch);
         //return false;
          break;
    }
    fprintf(out, "\n");
  }

  if(d != 1){
    printf(ERROR);
    exit(ERRORC);
  }

  return true;
}




void indent( FILE *out, int d )
{

  for ( int i = 0; i<2*d; i++ ){

    fputc( SPACE, out );

  }

}


void checkDent( int d )
{
  if ( d < 1 ){
    printf( ERROR );
    exit( ERRORC );
  }
}


