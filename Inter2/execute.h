#ifndef EXECUTE_H
#define EXECUTE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"parse.h"
#include "token.h"
#include"isImmOrNeg.h"

// Function to convert enum to string
const char* operatorToString(operators op) {
    switch (op) {
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

const char* generalRegisterToString(general_registers reg) {
    switch (reg) {
        case R1: return "R1";
        case R2: return "R2";
        case R3: return "R3";
        case R4: return "R4";
        default: return NULL;
    }
}

const char* addressRegisterToString(address_registers reg) {
    switch (reg) {
        case A1: return "A1";
        case A2: return "A2";
        case A3: return "A3";
        case A4: return "A4";
        default: return NULL;
    }
}

int isOperator(char* str)
{
    for (operators op = MOV; op <= DISP; op++) {
        if (strcmp(str, operatorToString(op)) == 0) {
            return 1;  // inst.opcode is in the operators enum
        }
    }
    return 0;  // inst.opcode is not in the operators enum

}

int isGeneralRegister(char* str)
{
        for (general_registers reg = R1; reg <= R4; reg++) {
        if (strcmp(str, operatorToString(reg)) == 0) {
            return 1;  // inst.opcode is in the operators enum
        }
    }
    return 0;  // inst.opcode is not in the operators enum
}


int isAddressRegister(char* str)
{
    for (address_registers reg = A1; reg <= A4; reg++) {
        if (strcmp(str, operatorToString(reg)) == 0) {
            return 1;  // inst.opcode is in the operators enum
        }
    }
    return 0;  // inst.opcode is not in the operators enum
}


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


void interpreteInstruction(instruction inst)
{
    if (isOperator(inst.opcode) == 0)
    {
        printf("Error: Invalid Operator\n");
        return 1;
    }
    else if (isGeneralRegister(inst.destination) == 0 && isOperator(inst.opcode) != operatorToString(DISP))
    {
        printf("Error: Invalid Destination\n");
        return 1;
    }

}

#endif