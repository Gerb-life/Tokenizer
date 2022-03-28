/**
 * tokenizer.c - A simple token recognizer.
 *
 * NOTE: The terms 'token' and 'lexeme' are used interchangeably in this
 *       program.
 *
 * @author Gabriel Rodriguez
 * @version 1.0
 * @date 3/25/2022
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "tokenizer.h"

//declaring global variables
char* line;
char token[TSIZE]; // array of tokens
char* token_category[TSIZE]; // array of token categories
int count = 0; // token at given index
int ind = 0; // char at given index
int tok_num = 0; // number of tokens
int statement = 1; // statment counter
/**
* This function is being used to call the get_chars to populate the token and token_category arrays then call the print to output function
* @params argc - number of command line arguments
*         argv[] - array of command line arguments
* @return 0 - to show complete
*/
int main(int argc, char* argv[]) {
   char  input_line[LINE];  /* Line of input, fixed size        */
   FILE  *in_file = NULL;        /* File pointer                     */
   FILE  *out_file = NULL;
   int   line_count,        /* Number of lines read             */
         start;    /* is this the start of a new statement? */

  // Checking to  make sure the correct numebr of command line arguments are being used.

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

 //getting input from input file line by line.
  while (fgets(input_line, LINE, in_file) != NULL){
        line = input_line;  // Sets a global pointer to the memory location

        // removing spaces from input and passing to get_char
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
   // populating token category array and printing to ouput file
   for(int i = 0  ; i < strlen(token); i++){
        get_token(token[i]);
        print_output(out_file);
   }

   fclose(in_file);
   fclose(out_file);
   return 0;
}

/*
 *This function is used to populate the token array with characters from input.
 *@params c - character from input
 *@returns none;
 */
void get_chars(char c){
        token[ind] = c;
        ind++;
}
/*
 *This function is used to print the token and token category arrays
 *@params out - the file to write to.
 *@returns none;
 */

void print_output(FILE *out){
        static int counter = 0;
        //printing new line for statement
        if(counter == 0 ){
                fprintf(out , "Statement  # %d \n" , statement);
        }
        //Printing token  and token category at a given index and incrementing counters.
        //if token is a ; start new statement
        if(token[count] == ';'){
                fprintf(out , "Lexeme %d is %c and is a %s \n" , counter , token[count] , token_category[count]);
                fprintf(out , "-------------------------- \n");
                statement++;
                count++;
                counter = 0 ;

        }
        //Printing token  and token category at a given index and incrementing counters.
        else{
                fprintf(out , "Lexeme %d is %c and is a %s \n" , counter , token[count] , token_category[count]);
                count++;
                counter++;
        }
}
/**
*This function is used to populate the token_category array for all cases within the language
*@params  token_ptr - token at a given index
*@returns none;
*/
void get_token(char token_ptr){



        switch (token_ptr){


                case '0'... '9':
                           token_category[tok_num] = INT_LITERAL; // adding INT_LITERAL to array
                           tok_num++;
                           break;

                case '(':
                           token_category[tok_num] = LEFT_PAREN;// adding LEFT_PAREN to array
                           tok_num++;
                           break;

                case ')':
                           token_category[tok_num] = RIGHT_PAREN;// adding RIGHT_PAREN to array
                           tok_num++;
                           break;
                case '+':
                           token_category[tok_num] = ADD_OP;// adding ADD_OP to array
                           tok_num++;
                           break;

                case '-':
                           token_category[tok_num] = SUB_OP; // adding SUB_OP to array
                           tok_num++;
                           break;

                case '*':
                           token_category[tok_num] = MULT_OP; // adding MULT_OP to array
                           tok_num++;
                           break;

                case '/':
                           token_category[tok_num] = DIV_OP; // adding DIV_OP to array
                           tok_num++;
                           break;

                case '^':
                           token_category[tok_num] = EXPON_OP; // adding EXPON_OP to array
                           tok_num++;
                           break;
                case '=':
                           token_category[tok_num] = ASSIGN_OP; // adding ASSIGN_OP to array
                           tok_num++;
                           break;

                case '<':
                           token_category[tok_num] = LESS_THAN_OP; // adding LESS_THAN_OP to array
                           tok_num++;
                           break;
                case '>':
                           token_category[tok_num] = GREATER_THAN_OP; //adding GREATER_THAN_OP to array
                           tok_num++;
                           break;
 		case '!':
                           token_category[tok_num] = NOT_OP; //adding NOT_OP to array
                           tok_num++;
                           break;
                case ';':
                           token_category[tok_num] = SEMI_COLON; //adding SEMI_COLON to array
                           tok_num++;
                           break;
                default:
                           token_category[tok_num] = "ERROR NOT LEXEME"; //catching errors
                           tok_num++;
                           break;
        }
}
