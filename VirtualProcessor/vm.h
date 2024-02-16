// copyright 2017 Philip Bohun
#ifndef VM_H
#define VM_H
#define NUM_REGS 4
#define byte signed int 
#define i32 int
#define i64 long long 


#include "instruction.h"
#include <stdio.h>
#include <stdlib.h>

int regs [NUM_REGS] ;
int aregs [NUM_REGS];

typedef struct {
	i64 *mem;
	i64 max_mem;

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

#include "flag.h"

void execute(vcpu *c);
void fetch(vcpu *c);

vcpu *new_vcpu(i64 *memory, i64 mem_size) {
	vcpu *c = malloc(sizeof(vcpu));
	c->mem = memory;
	c->sp = mem_size - 1;
	c->max_mem = mem_size;
	c->pc = -1;
	c->inst = 0;
	return c;
}

void free_vcpu(vcpu *c) {
	free(c);
}

void run_vcpu(vcpu *c) {
	while (c->inst != INSTRUCTION_NOP) {
		fetch(c);
		// execute(c);
	}
}

void fetch(vcpu *c) {
	c->pc++;
    int temp = c->mem[c->pc];
	c->inst = (temp & 0xF0) >> 4;
    printf("inst: %d\n", c->inst);
	c->dest = (temp & 0x0F);
    printf("dest: %d\n", c->dest);
	c->src = (temp & 0x0FFF);
    printf("src: %d\n", c->src);
}

void execute(vcpu *c) {
	switch (c->inst) {
		 
	}
}

#endif // VM_H
