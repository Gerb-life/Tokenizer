/**
 * tokenizer.c - A simple token recognizer.
 *
 * NOTE: The terms 'token' and 'lexeme' are used interchangeably in this
 *       program.
 *
 * @author Your Name
 * @version current date
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "tokenizer.h"

// global variables
char *line;             // Global pointer to line of input

// (optional) can declare some additional variable if you want to
char token[TSIZE];
int count = 0;
int ind = 0;
int statement = 1;
/**
* add comment
*/
int main(int argc, char* argv[]) {
   char  input_line[LINE];  /* Line of input, fixed size        */
   FILE  *in_file = NULL;        /* File pointer                     */
   FILE  *out_file = NULL;
   int   line_count,        /* Number of lines read             */
         start,    /* is this the start of a new statement? */
         count;             /* count of tokens                  */

  if (argc != 3) {
    printf("Usage: tokenizer inputFile outputFile\n");
    exit(1);
  }

  in_file = fopen(argv[1], "r");
  if (in_file == NULL) {
    fprintf(stderr, "ERROR: could not open %s for reading\n", argv[1]);
    exit(1);
  }

  out_file = fopen(argv[2], "w");
  if (out_file == NULL) {
    fprintf(stderr, "ERROR: could not open %s for writing\n", argv[2]);
    exit(1);
  }

   // (optional) can add some code here if you want some here
  while (fgets(input_line, LINE, in_file) != NULL){
        line = input_line;  // Sets a global pointer to the memory location


     for(int i = 0 ; i < strlen(line); i++){
                if(isspace(line[i])){

                }

                else if(isdigit(line[i]) == 1){

                        line[i] = line[i] + '0';
                        get_chars(line[i]);
                }
                else{
                        get_chars(line[i]);
                }
        }


   }

   for(int i = 0  ; i < strlen(token); i++){
        get_token(token[i]);
   }

   fclose(in_file);
   fclose(out_file);
   return 0;
}


void get_chars(char c){
        token[ind] = c;
        //printf("%c" , token[ind]);
        ind++;
}
/**
*
*/
void get_token(char token_ptr){
        // token_ptr is the token at index i;
        if(count == 0 ){
                printf("Statement # %d \n" , statement);
        }

        switch (token_ptr){


                case '0'... '9':
                           printf("Lexeme %d is %c \n" ,count ,  token_ptr);
                           count++;
                           break;

                case '(':
                           printf("Lexeme %d is %c \n", count , token_ptr);
                           count++;
                           break;

                case ')':
                           printf("Lexeme %d is %c \n", count , token_ptr);
                           count++;
                           break;
                case '+':
                           printf("Lexeme %d is %c \n", count , token_ptr);
                           count++;
                           break;

                case '-':
                           printf("Lexeme %d is %c \n", count , token_ptr);
                           count++;
                           break;

                case '*':
                           printf("Lexeme %d is %c \n", count , token_ptr);
                           count++;
                           break;

                case '/':
                           printf("Lexeme %d is %c \n", count , token_ptr);
                           count++;
                           break;

                case '^':
                           printf("Lexeme %d is %c \n", count , token_ptr);
                           count++;
                           break;
                case '=':
                           printf("Lexeme %d is %c \n", count , token_ptr);
                           count++;
                           break;

                case '<':
                           printf("Lexeme %d is %c \n", count , token_ptr);
                           count++;
                           break;
                case '>':
                           printf("Lexeme %d is %c \n", count , token_ptr);
                           count++;
                           break;
 		case '!':
                           printf("Lexeme %d is %c \n", count , token_ptr);
                           count++;
                           break;
                case ';':
                           printf("Lexeme %d is %c \n", count , token_ptr);
                           count = 0;
                           statement++;
                           printf("---------------------------- \n");
                           break;
                default:
                           printf("Lexical error %c is not a lexeme \n" , token_ptr);
                           break;
        }
}