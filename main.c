#include "header.h"

int main(void)
{
    C_version();
    // Define the registers
    int registers[4] = {0, 0, 0, 0};
    // Define the instruction pointer
    int instructionPointer = 0;
    // Define the instruction register
    Instruction instructionRegister;
    // Define the program
    Instruction program[] = {
    {MOV, R0, 0x05, 1},  // MOV R0, 5
    {MOV, R1, 0x07, 1},  // MOV R1, 7
    {ADD, R0, R1, 0},    // ADD R0, R1
    {SUB, R1, 0x03, 1}   // SUB R1, 3
    };
    // Define the program length
    int programLength = 4;
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
    // Print the registers
    printf("Registers:\n");
    printf("R0: %d\n", registers[R0]);
    printf("R1: %d\n", registers[R1]);
    printf("R2: %d\n", registers[R2]);
    printf("R3: %d\n", registers[R3]);

    return 0;
}