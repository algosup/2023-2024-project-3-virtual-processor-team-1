#ifndef PARSE_H
#define PARSE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char *opcode;
    char *destination;
    char *source;
} instruction;


void getInstruction(instruction inst,char *op, char* des, char* src)
{
    inst.opcode = op;
    inst.destination = des;
    inst.source = src;
};


#endif