#include <stdio.h>
#include <stdlib.h>
#include "format.h"
#include "instruction.h"
#include "flag.h"

void execute(vcpu *c);
void fetch(vcpu *c);
void executeFunction(vcpu *c);


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
			c->pc = c->src;
			break;
		case INSTRUCTION_JE:
		printf("JE\n");
			if (c->zero == 0) {
				c->pc = c->src;
				clear_flags(c);
			}
			break;
		case INSTRUCTION_JNE:
		printf("JNE\n");
			if (c->zero == 0) {
				c->pc = searchLabel(c->src);
				clear_flags(c);
			}
			break;
		case INSTRUCTION_JG:
		printf("JG\n");
			if (c->gtz == 0) {
				c->pc = c->src;
				clear_flags(c);
			}
			break;
		case INSTRUCTION_JGE:
		printf("JGE\n");
			if (c->gtz == 0 || c->zero == 0) {
				c->pc = c->src;
				clear_flags(c);
			}
			break;
		case INSTRUCTION_JL:
		printf("JL\n");
		printf("c->ltz: %d\n", c->ltz);
			if (c->ltz == 0) {
				printf("c->src: %d\n", c->src);
				c->pc = searchLabel(c->src);
				clear_flags(c);
			}
			break;
		case INSTRUCTION_JLE:
		printf("JLE\n");
			if (c->ltz == 0 || c->zero == 0) {
				c->pc = c->src;
				clear_flags(c);
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
