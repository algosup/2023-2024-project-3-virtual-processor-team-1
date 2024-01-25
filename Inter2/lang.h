#ifndef LANG_H
#define LANG_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// Add your language definitions here <--
// ...

// Define the file extention name
#define FILE_EXTENTION ".algoasm"

// Define the maximal size of a program file
#define MAX_PROGRAM_SIZE 100

// Define separator characters
#define SEPARATOR ','
#define COMMENT ';'
#define NEWLINE '\n'
#define ENDLINE '\0'
#define SPACE ' '

// Define instruction codes
#define MOV 0x00
#define ADD 0x01
#define SUB 0x02
#define DISP 0x03

//Define register names
#define RA 0x0A
#define RB 0x0B
#define RC 0x0C
#define RD 0x0D

// Define the structure for an instruction
typedef struct 
{
    int opcode;
    int operand1;
    int operand2;
    int isImmediate;
} Instruction;

// Program logic --> {INTRUCTION, OPERAND1, OPERAND2, ISIMMEDIATE}

void executeInstruction(Instruction instruction, int* registers) 
{
    switch (instruction.opcode) 
    {
        case MOV:
        if (instruction.isImmediate) 
            {
                // If operand2 is an immediate value, move it to the register specified by operand1
                registers[instruction.operand1] = instruction.operand2;
            } else 
            {
                // If operand2 is a register, move its value to the register specified by operand1
                registers[instruction.operand1] = registers[instruction.operand2];
            }
            break;
        case ADD:
            // ADD instruction: Add the values in the registers specified by operand1 and operand2, and store the result in the register specified by operand1
            if (instruction.isImmediate) 
            {
                // If operand2 is an immediate value, add it to the register specified by operand1
                registers[instruction.operand1] += instruction.operand2;
            } else 
            {
                // If operand2 is a register, add its value to the register specified by operand1
                registers[instruction.operand1] += registers[instruction.operand2];
            }
            break;
        case SUB:
            // SUB instruction: Subtract the value in the register specified by operand2 from the value in the register specified by operand1, and store the result in the register specified by operand1
            if (instruction.isImmediate) 
            {
                // If operand2 is an immediate value, subtract it from the register specified by operand1
                registers[instruction.operand1] -= instruction.operand2;
            } else 
            {
                // If operand2 is a register, subtract its value from the register specified by operand1
                registers[instruction.operand1] -= registers[instruction.operand2];
            }
            break;
        case DISP:
            // DISP instruction: Display the value in the register or the immediate value specified by operand1
            if (instruction.isImmediate) 
            {
                // If operand1 is an immediate value, display it
                printf("%d\n", instruction.operand1);
            } else 
            {
                // If operand1 is a register, display its value
                printf("%d\n", registers[instruction.operand1]);
            }
            break;
        default:
            printf("Error: Invalid opcode %d\n", instruction.opcode);
            break;
    }
}

#endif // LANG_H
