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

// Define separator characters
#define SEPARATOR ','
#define COMMENT ';'
#define NEWLINE '\n'
#define ENDLINE '\0'
#define SPACE ' '
#define IMMEDIATE '#'
#define NEG '-'
#define LABEL ':'
#define END 'e', 'n', 'd'
#define STRING '"'

// Define the maximal size of a token
int token;
char *src, *old_src;  
int poolsize;        
int line;

// Define the instruction structure
typedef enum OPERATOR 
{
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
    DISP
} operators;

// Define the register structure
typedef enum GENERAL_REGISTER
{
    RA,
    RB,
    RC,
    RD
} general_registers;

// Define the address register structure
typedef enum ADDRESSE_REGISTER
{
    ARA,
    ARB,
    ARC,
    ARD
} address_registers;

#endif