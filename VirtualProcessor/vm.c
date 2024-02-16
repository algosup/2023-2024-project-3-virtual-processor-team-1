#include <stdio.h>
#include <stdlib.h>
#include "vcpu.h"

int main() {
	i64 b[] = {
		0B000100000000000100000000000000001110011100001001, // MOV R1, 2535
        0B001000100000000100000000000000001110011100001001, // ADD R1 , 2535
        0B100000000000000100000000000000000000000000000000, // DISP R1
        0B000000000000000000000000000000000000000000000000, // NOP
	};


	// create new cpu with the given i64 array for memory
	vcpu *c = new_vcpu(b, 4);

	run_vcpu(c);
	free_vcpu(c);

	return 0;
}
