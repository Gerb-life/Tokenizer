/**
 * Header file for the tokenizer project
 * @author your_name
 * @version date
 */
/* Constants */
#define LINE 100
#define TSIZE 100
#define TRUE 1
#define FALSE 0
#define ADD_OP "ADD_OP"
#define INT_LITERAL "INT_LITERAL"
#define ADD_OP "ADD_OP"
#define SUB_OP "SUB_OP"
#define MULT_OP "MULT_OP"
#define DIV_OP "DIV_OP"
#define LEFT_PAREN "LEFT_PAREN"
#define RIGHT_PAREN "RIGHT_PAREN"
#define EXPON_OP "EXPON_OP"
#define ASSIGN_OP "ASSIGN_OP"
#define LESS_THAN_OP "LESS_THAN_OP"
#define GREATER_THAN_OP "GREATER_THAN_OP"
#define NOT_OP "NOT_OP"
#define SEMI_COLON "SEMI_COLON"
/**
* add comment
*/
void get_token(char);
void get_chars(char);
void print_output(FILE*);