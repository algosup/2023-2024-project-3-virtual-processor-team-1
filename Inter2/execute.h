#ifndef EXECUTE_H
#define EXECUTE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"parse.h"
#include "token.h"

void exucuteInstruction(instruction inst)
{
    if (strcmp(inst.opcode,"ADD") == 0)
    {
        if(inst.destination != "R1" || inst.destination != "R2" || inst.destination != "R3" || inst.destination != "R4" || inst.destination !="A1" || inst.destination != "A2" || inst.destination != "A3" || inst.destination != "A4")
        {
            printf("Error: Invalid destination register\n");
            return 1;
        }
        else if (inst.source == NULL)
        {
            printf("Error: Invalid source register or value\n");
            return 1;
        }
        else if(inst.source == "R1" || inst.source == "R2" || inst.source == "R3" || inst.source == "R4" || inst.source =="A1" || inst.source == "A2" || inst.source == "A3" || inst.source == "A4")
        {
            
        }
        
    }
    else if(strcmp(inst.opcode,"SUB") == 0)
    {

    }
    else if (strcmp(inst.opcode,"MUL") == 0)
    {

    }
    else if (strcmp(inst.opcode,"DIV") == 0)
    {

    }
    else if (strcmp(inst.opcode,"JMP") == 0)
    {

    }
    else if (strcmp(inst.opcode,"JE") == 0)
    {

    }
    else if (strcmp(inst.opcode,"JNE") == 0)
    {

    }
    else if (strcmp(inst.opcode,"JG") == 0)
    {

    }
    else if (strcmp(inst.opcode,"JGE") == 0)
    {

    }
    else if (strcmp(inst.opcode,"JL") == 0)
    {

    }
    else if (strcmp(inst.opcode,"JLE") == 0)
    {

    }
    else if (strcmp(inst.opcode,"RET") == 0)
    {

    }
    else if (strcmp(inst.opcode,"CMP") == 0)
    {

    }
    else if (strcmp(inst.opcode,"CALL") == 0)
    {

    }
    else if (strcmp(inst.opcode,"AND") == 0)
    {

    }
    else if (strcmp(inst.opcode,"OR") == 0)
    {

    }
    else if (strcmp(inst.opcode,"XOR") == 0)
    {

    }
    else if (strcmp(inst.opcode,"NOT") == 0)
    {

    }
    else if (strcmp(inst.opcode,"GAD") == 0)
    {

    }
    else if (strcmp(inst.opcode,"DISP") == 0)
    {

    }
    else
    {
        printf("Error: Invalid instruction\n");
        return 1;
    }
}
#endif