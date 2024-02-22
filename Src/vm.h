#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define byte unsigned char 
#define i32 int
#define i64 unsigned long long
#define DEFAULT 255

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


typedef struct {
	i64 *mem;
	i64 max_mem;

	i32 stack[100];

	// registers
	i32 pc;
	i32 sp;
	i32 r[4];
	i32 ar[4];

	// instruction parts
	byte inst;
	byte dest;
	i32 src;


	// flags
	i32 zero;
	i32 ltz;
	i32 gtz;
} vcpu;


i32 labelTable[100];
i32 addressTable[100];
i64 program[1000];
i64 arrayTableLenght = sizeof(labelTable) / sizeof(labelTable[0]); 

void execute(vcpu *c);
void fetch(vcpu *c);
void executeFunction(vcpu *c);
i32 littleEndianToRealValue(i32 value);
i64 searchLabel(i32 label);
void clear_flags(vcpu *c);
void set_flags(vcpu *c, i32 a, i32 b);
int searchingForTheFirstJumpCallofAFunction(vcpu *c, i32 label);


vcpu *new_vcpu(i64 *memory, i64 mem_size) {
	vcpu *c = malloc(sizeof(vcpu));
	c->mem = memory;
	c->sp = mem_size - 1;
	c->max_mem = mem_size;
	c->pc = -1;
	c->inst = DEFAULT;
	return c;
}

void free_vcpu(vcpu *c) {
	free(c);
}

void run_vcpu(vcpu *c) {
	printf("Running vcpu\n");
	while (c->inst != INSTRUCTION_NOP) {
		fetch(c);
		execute(c);
	}
}


void fetch(vcpu *c) {
	c->pc++;
    i64 temp = c->mem[c->pc];
	// extract the instruction parts
	c->inst = (temp >> 40) & 0xFF; 
    //printf("inst: %d\n", c->inst);
	c->dest = (temp >> 32) & 0xFF;
    //printf("dest: %d\n", c->dest);
	c->src = littleEndianToRealValue(temp & 0xFFFFFFFF);
	//printf("src: %d\n", c->src);
}

void execute(vcpu *c) {
 	switch (c->inst) {
		case INSTRUCTION_MOV1:
		printf("MOV1\n");
			c->r[c->dest] = c->src;
			break;
		case INSTRUCTION_MOV2:
		printf("MOV2\n");
			c->ar[c->dest] = c->mem[c->src];
			break;
		case INSTRUCTION_MOV3:
		printf("MOV3\n");
			c->r[c->dest] = c->r[c->src];
			break;
		case INSTRUCTION_ADD1:
		printf("ADD1\n");
			c->r[c->dest] += c->r[c->src];
			break;
		case INSTRUCTION_ADD2:
		printf("ADD2\n");
			c->r[c->dest] += c->src;
			break;
		case INSTRUCTION_SUB1:
		printf("SUB1\n");
			c->r[c->dest] -= c->r[c->src];
			break;
		case INSTRUCTION_SUB2:
		printf("SUB2\n");
			c->r[c->dest] -= c->src;
			break;
		case INSTRUCTION_MUL1:
		printf("MUL1\n");
			c->r[c->dest] *= c->r[c->src];
			break;
		case INSTRUCTION_MUL2:
		printf("MUL2\n");
			c->r[c->dest] *= c->src;
			break;
		case INSTRUCTION_DIV1:
		printf("DIV1\n");
			c->r[c->dest] /= c->r[c->src];
			break;
		case INSTRUCTION_DIV2:
		printf("DIV2\n");
			c->r[c->dest] /= c->src;
			break;
		case INSTRUCTION_LABEL:
		printf("LABEL\n");
			if (c->inst == INSTRUCTION_RET || c->inst == INSTRUCTION_END) {
				break;
			}
			else {
				c->pc++;
				i64 temp = c->mem[c->pc];
				c->inst = (temp >> 40) & 0xFF;
			}
			break;
		case INSTRUCTION_END:
		printf("END\n");
			break;
		case INSTRUCTION_RET:
		printf("RET\n");
			break;
		case INSTRUCTION_CALL:
		printf("CALL\n");
            c->sp = c->pc; // Save the return address
            c->pc = searchLabel(c->src); // Jump to the function
            executeFunction(c); // Execute the function
            c->pc = c->sp; // Return to the line after the call
            break;
		case INSTRUCTION_CMP1:
		printf("CMP1\n");
			set_flags(c, c->r[c->dest], c->r[c->src]);
			break;
		case INSTRUCTION_CMP2:
		printf("CMP2\n");
			set_flags(c, c->r[c->dest], c->src);
			break;
		case INSTRUCTION_JMP:
		printf("JMP\n");
			c->pc = searchLabel(c->src);
			break;
		case INSTRUCTION_JE:
		printf("JE\n");
			if (c->zero == 0) {
				c->pc = c->src;
				clear_flags(c);
			}
			else {
				c->pc = searchingForTheFirstJumpCallofAFunction(c, c->src);
			}
			break;
		case INSTRUCTION_JNE:
		printf("JNE\n");
			if (c->zero == 0) {
				c->pc = searchLabel(c->src);
				clear_flags(c);
			}
			else {
				c->pc = searchingForTheFirstJumpCallofAFunction(c, c->src);
			}
			break;
		case INSTRUCTION_JG:
		printf("JG\n");
			if (c->gtz == 0) {
				c->pc = c->src;
				clear_flags(c);
			}
			else {
				c->pc = searchingForTheFirstJumpCallofAFunction(c, c->src);
			}
			break;
		case INSTRUCTION_JGE:
		printf("JGE\n");
			if (c->gtz == 0 || c->zero == 0) {
				c->pc = c->src;
				clear_flags(c);
			}
			else {
				c->pc = searchingForTheFirstJumpCallofAFunction(c, c->src);
			}
			break;
		case INSTRUCTION_JL:
		printf("JL\n");
			if (c->ltz == 0) {
				c->pc = searchLabel(c->src);
				clear_flags(c);
			}
			else {
				c->pc = searchingForTheFirstJumpCallofAFunction(c, c->src);
			}
			break;
		case INSTRUCTION_JLE:
		printf("JLE\n");
			if (c->ltz == 0 || c->zero == 0) {
				c->pc = c->src;
				clear_flags(c);
			}
			else {
				c->pc = searchingForTheFirstJumpCallofAFunction(c, c->src);
			}
			break;
		case INSTRUCTION_AND1:
		printf("AND1\n");
			c->r[c->dest] &= c->r[c->src];
			break;
		case INSTRUCTION_AND2:
		printf("AND2\n");
			c->r[c->dest] &= c->src;
			break;
		case INSTRUCTION_XOR1:
		printf("XOR1\n");
			c->r[c->dest] ^= c->r[c->src];
			break;
		case INSTRUCTION_XOR2:
		printf("XOR2\n");
			c->r[c->dest] ^= c->src;
			break;
		case INSTRUCTION_OR1:
		printf("OR1\n");
			c->r[c->dest] |= c->r[c->src];
			break;
		case INSTRUCTION_OR2:
		printf("OR2\n");
			c->r[c->dest] |= c->src;
			break;
		case INSTRUCTION_DISP1:
			printf("R%d: %d\n", c->dest, c->r[c->dest]);
			break;
		case INSTRUCTION_DISP2:
			
			break;
		case INSTRUCTION_NOP:
			break;
		 
 	}
 }

void executeFunction(vcpu *c) {
	if (c->inst == INSTRUCTION_RET || c->inst == INSTRUCTION_END) {
		return;
	}
	else {
		fetch(c);
		execute(c);
	}
}

i32 littleEndianToRealValue(i32 value){
    i32 result = 0;
    result |= (value & 0x000000FF) << 24;
    result |= (value & 0x0000FF00) << 8;
    result |= (value & 0x00FF0000) >> 8;
    result |= (value & 0xFF000000) >> 24;
    return result;
}

i64 searchLabel(i32 label){
	for(i64 i = 0; i < arrayTableLenght; i++){
		i64 temp = littleEndianToRealValue(labelTable[i]);
		if(temp == label){
			return addressTable[i];
		}
	}
	return -1;
}

void clear_flags(vcpu *c) {
	c->zero = 0;
	c->ltz = 0;
	c->gtz = 0;
}

void set_flags(vcpu *c, i32 a, i32 b) {
	i32 res = a - b;
	c->zero = (res == 0);
	c->ltz = (res <= 0);
	c->gtz = (res >= 0);
}


int searchingForTheFirstJumpCallofAFunction(vcpu *c, i32 label) {
	c -> pc = 0;
	while (c->pc < c->max_mem) {
		fetch(c);
		if (c->inst == INSTRUCTION_JMP && c->src == label) {
			return c->pc;
		}
		else if (c->inst == INSTRUCTION_JE && c->src == label) {
			return c->pc;
		}
		else if (c->inst == INSTRUCTION_JG && c->src == label) {
			return c->pc;
		}
		else if (c->inst == INSTRUCTION_JGE && c->src == label) {
			return c->pc;
		}
		else if (c->inst == INSTRUCTION_JL && c->src == label) {
			return c->pc;
		}
		else if (c->inst == INSTRUCTION_JLE && c->src == label) {
			return c->pc;
		}
		else if (c->inst == INSTRUCTION_JNE && c->src == label) {
			return c->pc;
		}
		else if (c->inst == INSTRUCTION_CALL && c->src == label) {
			return c->pc;
		}
	}
	return -1;
}