#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "instruction.h"
#include "flag.h"

// void execute(vcpu *c);
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
	//while (c->inst != INSTRUCTION_NOP) {
		fetch(c);
		// execute(c);
	//}
}

void fetch(vcpu *c) {
	c->pc++;
    int temp = c->mem[c->pc];
	// print the binary version of the instruction
	printf("inst: %llu\n", c->mem[c->pc]);
	// extract the instruction parts
	c->inst = (temp >> 24) & 0xFF; 
    printf("inst: %d\n", c->inst);
	c->dest = (temp >> 12) & 0x0FFF;
    printf("dest: %d\n", c->dest);
	c->src = temp & 0x0FFF;
    printf("src: %d\n", c->src);

}

// void execute(vcpu *c) {
// 	switch (c->inst) {
		 
// 	}
// }
