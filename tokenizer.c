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
char* token_category[TSIZE];
int count = 0;
int ind = 0;
int tok_num = 0;
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
        print_output(out_file);
   }

   fclose(in_file);
   fclose(out_file);
   return 0;
}


void get_chars(char c){
        token[ind] = c;
        printf("%c" , token[ind]);
        ind++;
}

void print_output(FILE *out){
        if(count == 0 ){
                fprintf(out , "Statement  # %d \n" , statement);
        }
        if(token[count] == ';'){
                fprintf(out , "Lexeme %d is %c and is a %s \n" , count , token[count] , token_category[count]);
                fprintf(out , "-------------------------- \n");
                statement++;
                count = 0;
        }
        else{
                fprintf(out , "Lexeme %d is %c and is a %s \n" , count , token[count] , token_category[count]);
                count++;
        }
}
/**
*
*/
void get_token(char token_ptr){
        // token_ptr is the token at index i;


        switch (token_ptr){


                case '0'... '9':
                           token_category[tok_num] = INT_LITERAL;
                           tok_num++;
                           break;

                case '(':
                           token_category[tok_num] = LEFT_PAREN;
                           tok_num++;
                           break;

                case ')':
                           token_category[tok_num] = RIGHT_PAREN;
                           tok_num++;
                           break;
                case '+':
                           token_category[tok_num] = ADD_OP;
                           tok_num++;
                           break;

                case '-':
                           token_category[tok_num] = SUB_OP;
                           tok_num++;
                           break;

                case '*':
                           token_category[tok_num] = MULT_OP;
                           tok_num++;
                           break;

                case '/':
                           token_category[tok_num] = DIV_OP;
                           tok_num++;
                           break;

                case '^':
                           token_category[tok_num] = EXPON_OP;
                           tok_num++;
                           break;
		case '=':
                           token_category[tok_num] = ASSIGN_OP;
                           tok_num++;
                           break;

                case '<':
                           token_category[tok_num] = LESS_THAN_OP;
                           tok_num++;
                           break;
                case '>':
                           token_category[tok_num] = GREATER_THAN_OP;
                           tok_num++;
                           break;
                case '!':
                           token_category[tok_num] = NOT_OP;
                           tok_num++;
                           break;
                case ';':
                           token_category[tok_num] = SEMI_COLON;
                           tok_num++;
                           break;
                default:
                           token_category[tok_num] = "ERROR NOT LEXEME";
                           tok_num++;
                           break;
        }
}

