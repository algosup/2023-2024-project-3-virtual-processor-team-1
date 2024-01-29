#ifndef SETDATA_H
#define SETDATA_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"
#include "logicalOperator.h"
// Define the instruction structure
typedef struct {
    char *opcode;
    char *destination;
    char *source;
} instruction;
// define value of the register
typedef struct value
{
    int integer;
    char *str;
} value_t;

// Define the structure of registers
typedef struct
{
    value_t Value;
    char *registerName;
} MixedType;

// 
void setInstruction(instruction inst,char *op, char* des, char* src)
{
    inst.opcode = op;
    inst.destination = des;
    inst.source = src;
};

void setRegister(MixedType (*reg)[MAX_REGISTER_VALUE]) {
    for (data i = R1; i <= R4; i++) {
        for (int j = 0; j <= MAX_REGISTER_VALUE; j++) {
            reg[i][j].Value.integer = NULL;
            reg[i][j].Value.str = NULL;
            strcpy(reg[i][j].registerName, generalRegisterToString(i));
        }
    }
}

void setAregister( MixedType (*areg)[MAX_REGISTER_VALUE])
{
    for(data i = A1; i <= A4; i++)
    {
        for(int j = 0; j <= MAX_REGISTER_VALUE; j++)
        {
            areg[i][j].Value.integer = NULL;
            areg[i][j].Value.str = NULL;
            strcpy(areg[i][j].registerName, addressRegisterToString(i));
        }
    }
}



#endif