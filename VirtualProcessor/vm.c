#include <stdio.h>
#include <stdlib.h>
#include "vm.h"

int main() {
	i64 b[] = {
		0b000100000000000100000000000000001110011100001001, // MOV R1, 2535
        0b001000100000000100000000000000001110011100001001, // ADD R1 , 2535
        0b100000000000000100000000000000000000000000000000, // DISP R1
        0b000000000000000000000000000000000000000000000000, // NOP
	};


	// create new cpu with the given i64 array for memory
	vcpu *c = new_cpu(b, 3);

	run_cpu(c);
	free_cpu(c);

	return 0;
}
