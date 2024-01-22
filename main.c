#include "header.h"

int main(int argc, char *argv[])
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
    {DISP, R0, 0, 0},    // DISP R0
    {MOV, R1, 0x07, 1},  // MOV R1, 7
    {DISP, R1, 0, 0},    // DISP R1
    {ADD, R0, R1, 0},    // ADD R0, R1
    {DISP, R0, 0, 0},    // DISP R0
    {SUB, R1, 0x03, 1},   // SUB R1, 3
    {DISP, R1, 0, 0},     // DISP R1
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