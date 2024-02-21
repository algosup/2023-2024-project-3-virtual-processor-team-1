void intToLittleEndianBinary(int value, char *output) {
    char temp[33];
    for (int i = 0; i < 32; i++) {
        temp[i] = (value & 1) + '0';
        value >>= 1;
    }
    temp[32] = '\0'; // Ensure null termination
    
    // Swapping the bytes as per the requirement
    for (int i = 0; i < 32; i++) {
        output[i] = temp[(i / 8) * 8 + (7 - (i % 8))]; // Swap bytes
    }
}

char* determineOpcode(astNode_t *node) {
    if (strcmp(node->token.value, "MOV") == 0) {
        if (strcmp(node->children[1]->token.type, "REGISTER") == 0) {
            return "00010010"; // MOV REGISTER, REGISTER
        } else if (strcmp(node->children[1]->token.type, "IMMEDIATE") == 0) {
            return "00010000"; // MOV REGISTER, IMMEDIATE
        }
    } else if (strcmp(node->token.value, "ADD") == 0) {
        if (strcmp(node->children[1]->token.type, "REGISTER") == 0) {
            return "00100000"; // ADD REGISTER, REGISTER
        } else if (strcmp(node->children[1]->token.type, "IMMEDIATE") == 0) {
            return "00100010"; // ADD REGISTER, IMMEDIATE
        }
    } else if (strcmp(node->token.value, "SUB") == 0) {
        if (strcmp(node->children[1]->token.type, "REGISTER") == 0) {
            return "00100001"; // SUB REGISTER, REGISTER
        } else if (strcmp(node->children[1]->token.type, "IMMEDIATE") == 0) {
            return "00100011"; // SUB REGISTER, IMMEDIATE
        }
    } else if (strcmp(node->token.value, "MUL") == 0) {
        if(strcmp(node->children[1]->token.type, "REGISTER") == 0) {
            return "00110000"; // MUL REGISTER, REGISTER
        } else if (strcmp(node->children[1]->token.type, "IMMEDIATE") == 0) {
            return "00110001"; // MUL REGISTER, IMMEDIATE
        }
    }
    return NULL; // In case of an unrecognized instruction or operand type
}

int determineLastValue(astNode_t *node) {
    if (strcmp(node->children[1]->token.type, "REGISTER") == 0) {
        return atoi(&node->children[1]->token.value[1]); // Convert "Rn" to integer
    } else if (strcmp(node->children[1]->token.type, "IMMEDIATE") == 0) {
        // Adjusted to handle immediate values correctly by removing the '#' prefix
        char *immediateValue = node->children[1]->token.value;
        if (immediateValue[0] == '#') {
            return atoi(immediateValue + 1); // Convert immediate value to integer, skipping the '#' character
        }
        return atoi(immediateValue); // Fallback, in case there's no '#' but it's still an immediate value
    }
    return 0; // In case of an unrecognized operand type
}

void generateMachineCode(astNode_t *node) {
    if (node == NULL) return;

    if (strcmp(node->token.type, "INSTRUCTION") == 0) {
        char *opcode = NULL; // Will be set according to the instruction type
        char regCode[9], targetCode[33]; // For register and target (register or immediate) in binary
        memset(regCode, 0, sizeof(regCode));
        memset(targetCode, '0', sizeof(targetCode) - 1); // Initialize with '0's for 32 bits, leaving last byte for null terminator
        targetCode[32] = '\0'; // Ensure null termination

        // Convert first argument (register) to binary if present
        if (node->numChildren > 0 && strcmp(node->children[0]->token.type, "REGISTER") == 0) {
            int regNum = atoi(&node->children[0]->token.value[1]); // Convert "Rn" to integer
            for (int i = 7; i >= 0; --i) {
                regCode[i] = (regNum & 1) + '0';
                regNum >>= 1;
            }
            regCode[8] = '\0'; // Ensure null termination
        }

        // Determine the type of instruction and its arguments
        opcode = determineOpcode(node);
        int lastValue = determineLastValue(node);

        intToLittleEndianBinary(lastValue, targetCode); // Convert last token to little endian format

        printf("0b%s%s%s\n", opcode, regCode, targetCode);
    }

    // Recursively process children nodes
    for (int i = 0; i < node->numChildren; i++) {
        generateMachineCode(node->children[i]);
    }
}
