#include <stdio.h>
#include <stdlib.h>
#include "format.h"
#include "instruction.h"
#include "flag.h"

void execute(vcpu *c);
void fetch(vcpu *c);



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
}

void execute(vcpu *c) {
 	switch (c->inst) {
		case INSTRUCTION_MOV1:
			c->r[c->dest] = c->src;
			break;
		case INSTRUCTION_MOV2:
			c->ar[c->dest] = c->mem[c->src];
			break;
		case INSTRUCTION_MOV3:
			c->r[c->dest] = c->r[c->src];
			break;
		case INSTRUCTION_ADD1:
			c->r[c->dest] += c->r[c->src];
			break;
		case INSTRUCTION_ADD2:
			c->r[c->dest] += c->src;
			break;
		case INSTRUCTION_SUB1:
			c->r[c->dest] -= c->r[c->src];
			break;
		case INSTRUCTION_SUB2:
			c->r[c->dest] -= c->src;
			break;
		case INSTRUCTION_MUL1:
			c->r[c->dest] *= c->r[c->src];
			break;
		case INSTRUCTION_MUL2:
			c->r[c->dest] *= c->src;
			break;
		case INSTRUCTION_DIV1:
			c->r[c->dest] /= c->r[c->src];
			break;
		case INSTRUCTION_DIV2:
			c->r[c->dest] /= c->src;
			break;
		case INSTRUCTION_LABEL:
			break;
		case INSTRUCTION_END:
			break;
		case INSTRUCTION_RET:
			break;
		case INSTRUCTION_CALL:
			break;
		case INSTRUCTION_CMP1:
			if (c->r[c->dest] == c->r[c->src]) {
				c->zero = 1;
			} else {
				c->zero = 0;
			}
			if (c->r[c->dest] < c->r[c->src]) {
				c->ltz = 1;
			} else {
				c->ltz = 0;
			}
			if (c->r[c->dest] > c->r[c->src]) {
				c->gtz = 1;
			} else {
				c->gtz = 0;
			}
			break;
		case INSTRUCTION_CMP2:
			if (c->r[c->dest] == c->src) {
				c->zero = 1;
			} else {
				c->zero = 0;
			}
			if (c->r[c->dest] < c->src) {
				c->ltz = 1;
			} else {
				c->ltz = 0;
			}
			if (c->r[c->dest] > c->src) {
				c->gtz = 1;
			} else {
				c->gtz = 0;
			}
			break;
		case INSTRUCTION_JMP:
			c->pc = c->src;
			break;
		case INSTRUCTION_JE:
			if (c->zero == 1) {
				c->pc = c->src;
			}
			break;
		case INSTRUCTION_JNE:
			if (c->zero == 0) {
				c->pc = c->src;
			}
			break;
		case INSTRUCTION_JG:
			if (c->gtz == 1) {
				c->pc = c->src;
			}
			break;
		case INSTRUCTION_JGE:
			if (c->gtz == 1 || c->zero == 1) {
				c->pc = c->src;
			}
			break;
		case INSTRUCTION_JL:
			if (c->ltz == 1) {
				c->pc = c->src;
			}
			break;
		case INSTRUCTION_JLE:
			if (c->ltz == 1 || c->zero == 1) {
				c->pc = c->src;
			}
			break;
		case INSTRUCTION_AND1:
			c->r[c->dest] &= c->r[c->src];
			break;
		case INSTRUCTION_AND2:
			c->r[c->dest] &= c->src;
			break;
		case INSTRUCTION_XOR1:
			c->r[c->dest] ^= c->r[c->src];
			break;
		case INSTRUCTION_XOR2:
			c->r[c->dest] ^= c->src;
			break;
		case INSTRUCTION_OR1:
			c->r[c->dest] |= c->r[c->src];
			break;
		case INSTRUCTION_OR2:
			c->r[c->dest] |= c->src;
			break;
		case INSTRUCTION_NOT:
			c->r[c->dest] = ~c->r[c->dest];
			break;
		case INSTRUCTION_GAD:
			c->r[c->dest] = c->r[c->dest] + c->src;
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


