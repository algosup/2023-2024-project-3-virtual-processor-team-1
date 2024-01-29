#ifndef EXECUTE_H
#define EXECUTE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"setData.h"
#include "token.h"
#include"logicalOperator.h"


void interpreteInstruction(instruction inst, output_t output, data dt)
{
    if (isOperator(inst.opcode) == 0)
    {
        printf("Error: Invalid Operator\n");
        exit(1);
    }
    else if (isGeneralRegister(inst.destination) == 0 && isOperator(inst.opcode) != operatorToString(DISP))
    {
        printf("Error: Invalid Destination\n");
        exit(1);
    }

    switch (dt)
    {
        case MOV:
            if(isImmediateOrNegative(inst.source) == 1 || isImmediateOrNegative(inst.source) == 2 || isGeneralRegister(inst.source) == 1)
            {   
                // take the value of the immediate or negative value
                if(isImmediateOrNegative(inst.source) == 1 || isImmediateOrNegative(inst.source) == 2)
                {
                output.src = (int)removeSigned(inst.source);
                output.dest = output.src;
                }
                // take the value of the register
                else
                {
                    // output.src = (int)inst.source;
                    // output.dest = output.src;
                }
            
            
            }
            else
            {
                printf("Error: Invalid Source\n");
                exit(1);
            }
            break;
        case ADD:
            if(isImmediateOrNegative(inst.source) == 1 || isImmediateOrNegative(inst.source) == 2 || isGeneralRegister(inst.source) == 1)
            {
                if(isImmediateOrNegative(inst.source) == 1 || isImmediateOrNegative(inst.source) == 2)
                {
                    // take the value of the immediate or negative value
                    output.src = (int)removeSigned(inst.source);
                    output.dest = output.dest + output.src;
                }
                else
                {
                    // take the value of the register
            
                }            
            }
            else
            {
                printf("Error: Invalid Source\n");
                exit(1);
            }   
    
        default:
            break;
    }
    
}

#endif