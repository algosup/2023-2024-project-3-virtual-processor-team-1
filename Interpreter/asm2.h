#ifndef ASM2_H
#define ASM2_H
#include "token.h"

typedef union {
    general_registers gr;
    address_registers ar;
    int imm;
    int neg;
    char* str;
} destination_source;

typedef struct instruction
{
    operators op;
    destination_source de;
    destination_source so;
} instruction_t;



void executeInstruction( operators *op, destination_source de, destination_source so);

void executeInstruction( operators *op, destination_source de, destination_source so) 
{
    instruction_t instruction;
    switch (*op) 
    {
        instruction.op = *op;
        instruction.de = de;
        instruction.so = so;
        case MOV:
            instruction.de = instruction.so;
        case ADD:
            //instruction.de = instruction.de + instruction.so; 
        case SUB:
            //instruction.de = instruction.de - instruction.so;    
        case MUL:
            //instruction.de = instruction.de * instruction.so;
        case DIV:
            //instruction.de = instruction.de / instruction.so;
        case JMP:
        case JE:
        case JNE:
        case JG:
        case JGE:
        case JL:
        case JLE:
        case CMP:
        case AND:
        case OR:
        case XOR:
        case NOT:
        case GAD:
        case DISP:
            // printf("",instruction.de);
    }

}

#endif




