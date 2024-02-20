
void generateMachineCode(astNode_t *node);

void generateMachineCode(astNode_t *node) {
    if (node == NULL) return;

    if (strcmp(node->token.type, "INSTRUCTION") == 0 && strcmp(node->token.value, "MOV") == 0) {
        char *opcode = NULL; // Will be set according to MOV type
        char regCode[9], targetCode[33]; // For register and immediate/address value in binary
        memset(regCode, 0, sizeof(regCode));
        memset(targetCode, 0, sizeof(targetCode));

        // Determine the type of MOV instruction
        if (node->numChildren == 2) {
            if (strcmp(node->children[0]->token.type, "REGISTER") == 0) {
                if (strcmp(node->children[1]->token.type, "IMMEDIATE") == 0) {
                    opcode = "00010000"; // MOV REGISTER, IMMEDIATE
                    int regNum = atoi(&node->children[0]->token.value[1]); // Convert "Rn" to integer
                    // Convert register number to binary
                    for (int i = 7; i >= 0; --i) {
                        regCode[i] = (regNum & 1) + '0';
                        regNum >>= 1;
                    }
                    int immValue = atoi(&node->children[1]->token.value[1]); // Convert "#value" to integer
                    // Convert to binary string and little endianness
                    char tempCode[33];
                    for (int i = 31; i >= 0; --i) {
                        tempCode[31-i] = (immValue & 1) + '0';
                        immValue >>= 1;
                    }
                    // Swap bytes for endianness
                    for (int i = 0; i < 32; i += 8) {
                        for (int j = 0; j < 8; ++j) {
                            targetCode[i + j] = tempCode[i + (7 - j)];
                        }
                    }
                } else if (strcmp(node->children[1]->token.type, "REGISTER") == 0) {
                    opcode = "00010010"; // MOV REGISTER, REGISTER
                }
            } else if (strcmp(node->children[0]->token.type, "ADDRESS_REGISTER") == 0) {
                opcode = "00010001"; // MOV ADDRESS_REGISTER, ADDRESS
            }
        }
        regCode[8] = '\0'; // Ensure null termination
        targetCode[32] = '\0'; // Ensure null termination
        printf("0b%s\n%s\n%s\n", opcode, regCode, targetCode);
    }

    for (int i = 0; i < node->numChildren; i++) {
        generateMachineCode(node->children[i]);
    }
}