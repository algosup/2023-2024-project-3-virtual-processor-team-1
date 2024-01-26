#ifndef EXECUTE_H
#define EXECUTE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"parse.h"
#include "token.h"
#include"logicalOperator.h"


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
    // Addition, Subtraction, Multiplication and Division
    for(operators op = ADD; op <= DIV; op++)
    {
        if (operatorToString(op) == inst.opcode)
        {
            if( isImmediateOrNegative(inst.source) || isString(inst.source))
            {
                
            }
        }
    }
}

#endif