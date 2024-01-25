#ifndef ASM2_H
#define ASM2_H
#include "token.h"

typedef union {
    general_registers gr;
    address_registers ar;
    int imm;
    int neg;
} destination_source;

void executeInstruction( operators *op, destination_source de, destination_source so);

#endif




