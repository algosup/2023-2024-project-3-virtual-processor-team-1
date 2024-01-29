#ifndef TOKEN_H
#define TOKEN_H
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

#define int long // work with 32bit target

// Define the file extention name
#define FILE_EXTENTION ".asm2"

// Define the maximal size of a program file
#define MAX_PROGRAM_SIZE 100
// MAX value of a register
#define MAX_REGISTER_VALUE 3

// Define separatorand signed characters
#define SEPARATOR ',' // separator character
#define COMMENT ';' // comment character
#define NEWLINE '\n' // newline character
#define ENDLINE '\0' // endline character
#define SPACE ' ' // space character
#define IMMEDIATE '#' // immediate character
#define NEGATIVE '-' // negative character
#define LABEL '.' // label character
#define END 'e', 'n', 'd' // end character
#define STRING '"' // string character

// Define the maximal size of a token
int token; // current token
char *src, *old_src; // pointer to source code string
int poolsize; // default size of text/data/stack
int line; // line number

// Define the data
typedef enum DATA
{
    // operators
    MOV,
    ADD, 
    SUB, 
    MUL,
    DIV,
    JMP,
    JE,
    JNE,
    JG,
    JGE,
    JL,
    JLE,
    RET,
    CMP,
    CALL,
    AND,
    OR,
    XOR,
    NOT,
    GAD,
    DISP,
    // registers
    R1,
    R2,
    R3,
    R4,
    // address registers
    A1,
    A2,
    A3,
    A4,
    // Value (integer or string)
    VAL,
} data;

// define token structure
typedef struct Token
{
    data type; // register, operator, address register, value
    data value; // value of the token (register, operator, address register, value)
    data line; // line number 
    data column; // column number
} token_t;

// define instruction structure
typedef struct Output
{
    int dest; // destination
    int src; // source
    
} output_t; 

#endif