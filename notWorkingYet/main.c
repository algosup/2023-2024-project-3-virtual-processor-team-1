#include "header.h"

int main(int argc, char *argv[])
{
    C_version();

    // Read a file from the one passed in as an argument
    FILE *file = fopen(argv[1], "r");
    // Check if the file exists
    if (file == NULL)
    {
        printf("Error: File does not exist\n");
        return 1;
    }
    
    // Define the registers
    int registers[4] = {0, 0, 0, 0};
    // Define the instruction pointer
    int instructionPointer = 0;
    // Define the instruction register
    Instruction instructionRegister;
    // Define the program
    Instruction program[] = {
    {MOV, RA, 0x05, 1},  // MOV RA, 5
    {DISP, RA, 0, 0},    // DISP RA
    {MOV, RB, 0x07, 1},  // MOV RB, 7
    {DISP, RB, 0, 0},    // DISP RB
    {ADD, RA, RB, 0},    // ADD RA, RB
    {DISP, RA, 0, 0},    // DISP RA
    {SUB, RB, 0x03, 1},   // SUB RB, 3
    {DISP, RB, 0, 0},     // DISP RB
    };
    // Define the program length
    int programLength = sizeof(program) / sizeof(program[0]);
    // Execute the program
    while (instructionPointer < programLength) 
    {
        // Fetch the instruction
        instructionRegister = program[instructionPointer];
        // Execute the instruction
        executeInstruction(instructionRegister, registers);
        // Increment the instruction pointer
        instructionPointer++;
    }

    return 0;
}