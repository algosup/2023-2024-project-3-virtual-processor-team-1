#ifndef INSTRUCTION_H
#define INSTRUCTION_H

typedef enum {
    INSTRUCTION_NOP = 0x00, // No operation
    INSTRUCTION_MOV1 = 0x10, // MOV register, immediate 
    INSTRUCTION_MOV2 = 0x11, // MOV adress register, adress
    INSTRUCTION_MOV3 = 0x12, // MOV register, register 

    INSTRUCTION_ADD1 = 0x20, // Add register , register 
    INSTRUCTION_ADD2 = 0x22, // Add register , immediate 
    INSTRUCTION_SUB1 = 0x21, // Sub register, register
    INSTRUCTION_SUB2 = 0x23, // Sub register , immediate
    INSTRUCTION_MUL1 = 0x30, // Mul register, register
    INSTRUCTION_MUL2 = 0x31, // Mul register , immediate 
    INSTRUCTION_DIV1 = 0x40, // Div register, register 
    INSTRUCTION_DIV2 = 0x41, // Div register , immediate 

    INSTRUCTION_LABEL = 0X99,
    INSTRUCTION_END = 0x98,
    INSTRUCTION_RET = 0x97,
    INSTRUCTION_CALL = 0x96,

    INSTRUCTION_CMP1 = 0x50, // CMP register , register
    INSTRUCTION_CMP2 = 0x51, // CMP register, immediate

    INSTRUCTION_JMP = 0x60,
    INSTRUCTION_JE = 0x61,
    INSTRUCTION_JNE= 0x62,
    INSTRUCTION_JG = 0x63,
    INSTRUCTION_JGE = 0x64,
    INSTRUCTION_JL = 0x65,
    INSTRUCTION_JLE = 0x66,

    INSTRUCTION_AND1 = 0x70, // AND register , register 
    INSTRUCTION_AND2 = 0x71, // AND register , immediate
    INSTRUCTION_XOR1 = 0x72, // XOR register , register 
    INSTRUCTION_XOR2 = 0x73, // XOR register , immediate 
    INSTRUCTION_OR1 = 0x74, // OR register , register 
    INSTRUCTION_OR2 = 0x75, // OR register , immediate 
    INSTRUCTION_DISP1 = 0x80, // DISP register
    INSTRUCTION_DISP2 = 0x81 // DISP immediate

} Instruction;

#endif // INSTRUCTIONS_H




