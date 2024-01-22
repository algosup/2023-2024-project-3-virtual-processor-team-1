#ifndef LANG_H
#define LANG_H
#include <stdio.h>
#include <stdlib.h>
// Add your language definitions here <--
// ...

// Define the file extention name
#define FILE_EXTENTION ".algoasm"

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

//Define register names
#define R0 0x0A
#define R1 0x0B
#define R2 0x0C
#define R3 0x0D

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
        default:
            printf("Error: Invalid opcode %d\n", instruction.opcode);
            break;
    }
}

#endif // LANG_H
