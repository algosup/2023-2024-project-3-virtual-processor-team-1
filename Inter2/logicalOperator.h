#ifndef LOGICALOPERATOR_H
#define LOGICALOPERATOR_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"
#include"setData.h"

// Check if str is an immediate or negative value 
// return 1 if immediate, 2 if negative
int isImmediateOrNegative(char *str)
{
    if (str[0] == IMMEDIATE)

        return 1;
    else if (str[0] == NEGATIVE)
        return 2;
    else
        return 0;
}
// Remove the immediate or negative sign from str
char* removeSigned(char *str)
{
    if(isImmediateOrNegative(str) == 1 || isImmediateOrNegative(str) == 2)
    {
        str++;
    }
    else
    {
        printf("Error in removeToken function\n");
    }
        
    return str;
}
// Function to convert enum to string
const char* operatorToString(data dt) {
    switch (dt) {
        case MOV: return "MOV";
        case ADD: return "ADD";
        case SUB: return "SUB";
        case MUL: return "MUL";
        case DIV: return "DIV";
        case JMP: return "JMP";
        case JE: return "JE";
        case JNE: return "JNE";
        case JG: return "JG";
        case JGE: return "JGE";
        case JL: return "JL";
        case JLE: return "JLE";
        case RET: return "RET";
        case CMP: return "CMP";
        case CALL: return "CALL";
        case AND: return "AND";
        case OR: return "OR";
        case XOR: return "XOR";
        case NOT: return "NOT";
        case GAD: return "GAD";
        case DISP: return "DISP";
        default: return NULL;
    }
}
// Function to convert enum to string
const char* generalRegisterToString(data dt) {
    switch (dt) {
        case R1: return "R1";
        case R2: return "R2";
        case R3: return "R3";
        case R4: return "R4";
        default: return NULL;
    }
}
// Function to convert enum to string
const char* addressRegisterToString(data dt) {
    switch (dt) {
        case A1: return "A1";
        case A2: return "A2";
        case A3: return "A3";
        case A4: return "A4";
        default: return NULL;
    }
}
// Function to check if str is a label
int isLabel(char* str)
{
    if (str[0] == LABEL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// Function to check if str is an operator
int isOperator(char* str)
{
    for (data dt = MOV; dt <= DISP; dt++) {
        if (strcmp(str, operatorToString(dt)) == 0) {
            return 1;  // inst.opcode is in the operators enum
        }
    }
    return 0;  // inst.opcode is not in the operators enum

}
// Function to check if str is a general register
int isGeneralRegister(char* str)
{
        for (data dt = R1; dt <= R4; dt++) {
        if (strcmp(str, operatorToString(dt)) == 0) {
            return 1;  // inst.opcode is in the operators enum
        }
    }
    return 0;  // inst.opcode is not in the operators enum
}
// Function to check if str is an address register
int isAddressRegister(char* str)
{
    for (data dt = A1; dt <= A4; dt++) {
        if (strcmp(str, operatorToString(dt)) == 0) {
            return 1;  // inst.opcode is in the operators enum
        }
    }
    return 0;  // inst.opcode is not in the operators enum
}
// Function to check if str is a string
int isString(char* str)
{
    int len = strlen(str);
    if (len >= 2 && str[0] == STRING && str[len - 1] == STRING) {
        return 1;
    }
    return 0;
}

#endif
