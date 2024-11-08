#include <stdio.h>
#include <stdbool.h>

enum TokenType {
    SYMBOL, // '@', '+', '-', '&'....
    KEYWORD, //'A', 'D', 'M', 'KBD', 'SCREEN', 'R0' to 'R15'
    INTEGER_LITERAL, // base-10 integer 0-32767
    IDENTIFIER, // any string containing no whitespace and not a keyword
    NEWLINE
}; typedef enum TokenType TokenType;

enum Keyword {
    JGT, JEQ, JLT, JGE, JNE, JLE, JMP,
    SCREEN, KBD, SP, LCL, ARG, THIS, THAT,
    R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, R13, R14, R15,
    KW_A, KW_D, KW_M
}; typedef enum Keyword Keyword;

/*
A union is a special type that uses one spot in memory to store one of several
 * different variables of different types. Here, TokenData can store either a Keyword,
 * an int, a character, or a string. Assigning to e.g. key_val will overwrite what's
 * stored in int_val, and there's no built-in way to tell whether what's currently stored
 * there is e.g. an int or a string --- we'll keep track of that with the TokenType enum.
 *
 * Usage examples: Suppose data is a TokenData variable.
 *      data.int_val = 42; printf("%d", data.int_val); // Prints 42.
 *      data.char_val = '@'; printf("%c", data.char_val); // Prints '@'.
 *      data.char_val = '@'; printf("%d", data.int_val); // Prints 64 (the ASCII value of @).
 * 
 * ME:
 * replacing the value of TokenData object 
 * 
*/



union TokenData {
    Keyword key_val;
    int int_val;
    char char_val;
    char *str_val;
}; typedef union TokenData TokenData;


/*
Token looks like:
Token1: (type=Keyword, value=D)
Token2: (type=Symbol, value=;)
Token3: (type=Keyword, value=JGT)
Token4: (type=Newline, value=None)

*/




struct Token {
    TokenType type;
    TokenData value;
}; typedef struct Token Token;

// Returns a pointer to a newly-allocated Token object.
Token *malloc_token();
// Frees a Token pointer and everything associated with it.
void free_token(Token *);
// Writes a token to [output] in the form "type,value".
void write_token(Token *, FILE *);
// Returns false if there are no more tokens in input, otherwise stores the next token in dest and returns true.
bool read_token(Token *, FILE *);

// Maximum token length
#define MAX_LINE_LENGTH 256