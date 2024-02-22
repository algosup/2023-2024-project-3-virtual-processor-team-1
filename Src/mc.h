int jmpLabelProcessed = 0;

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

void labelToMachineCode(const char *label, char *output) {
    // Skip the leading '.' to start directly with label name
    const char *labelName = label + 1;
    int asciiSum = 0;
    for (int i = 0; labelName[i] != '\0'; ++i) {
        asciiSum += labelName[i];
    }
    intToLittleEndianBinary(asciiSum, output);
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
    } else if (strcmp(node->token.value, "DIV") == 0) {
        if (strcmp(node->children[1]->token.type, "REGISTER") == 0) {
            return "01000000"; // DIV REGISTER, REGISTER
        } else if (strcmp(node->children[1]->token.type, "IMMEDIATE") == 0) {
            return "01000001"; // DIV REGISTER, IMMEDIATE
        }
    } else if(strcmp(node->token.value, "AND") == 0) {
        if (strcmp(node->children[1]->token.type, "REGISTER") == 0) {
            return "01110000"; // AND REGISTER, REGISTER
        } else if (strcmp(node->children[1]->token.type, "IMMEDIATE") == 0) {
            return "01110001"; // AND REGISTER, IMMEDIATE
        }
    } else if (strcmp(node->token.value, "OR") == 0) {
        if (strcmp(node->children[1]->token.type, "REGISTER") == 0) {
            return "01110100"; // OR REGISTER, REGISTER
        } else if (strcmp(node->children[1]->token.type, "IMMEDIATE") == 0) {
            return "01110101"; // OR REGISTER, IMMEDIATE
        }
    } else if (strcmp(node->token.value, "XOR") == 0) {
        if (strcmp(node->children[1]->token.type, "REGISTER") == 0) {
            return "01110010"; // XOR REGISTER, REGISTER
        } else if (strcmp(node->children[1]->token.type, "IMMEDIATE") == 0) {
            return "01110011"; // XOR REGISTER, IMMEDIATE
        }
    } else if (strcmp(node->token.value, "DISP") == 0) {
        if (strcmp(node->children[0]->token.type, "REGISTER") == 0) {
            return "10000000"; // DISP REGISTER
        }
    } else if (strcmp(node->token.value, "CMP") == 0) {
        if (strcmp(node->children[1]->token.type, "REGISTER") == 0) {
            return "01010000"; // CMP REGISTER, REGISTER
        } else if (strcmp(node->children[1]->token.type, "IMMEDIATE") == 0) {
            return "01010001"; // CMP REGISTER, IMMEDIATE
        }
    } // END opcode
    else if (strcmp(node->token.value, "END") == 0) {
        return "1001100000000000"; // END
    } // RET opcode
    else if (strcmp(node->token.value, "RET") == 0) {
        return "1001011100000000"; // RET
    } else if (strcmp(node->token.value, "JMP") == 0) {
        return "0110000000000000"; // JMP
    } else if (strcmp(node->token.value, "JE") == 0) {
        return "0110000100000000"; // JE
    } else if (strcmp(node->token.value, "JNE") == 0) {
        return "0110001000000000"; // JNE
    } else if (strcmp(node->token.value, "JG") == 0) {
        return "0110001100000000"; // JG
    } else if (strcmp(node->token.value, "JGE") == 0) {
        return "0110010000000000"; // JGE
    } else if (strcmp(node->token.value, "JL") == 0) {
        return "0110010100000000"; // JL
    } else if (strcmp(node->token.value, "JLE") == 0) {
        return "0110011000000000"; // JLE
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
        if (node == NULL) return;
    
    if (strcmp(node->token.type, "INSTRUCTION") == 0 && (strcmp(node->token.value, "JMP") == 0 
    || strcmp(node->token.value, "JE") == 0
    || strcmp(node->token.value, "JNE") == 0
    || strcmp(node->token.value, "JG") == 0
    || strcmp(node->token.value, "JGE") == 0
    || strcmp(node->token.value, "JL") == 0
    || strcmp(node->token.value, "JLE") == 0) && node->numChildren > 0) {
        char targetCode[33];
        memset(targetCode, '0', sizeof(targetCode) - 1);
        targetCode[32] = '\0'; // Ensure null termination

        labelToMachineCode(node->children[0]->token.value, targetCode);
        if(strcmp(node->token.value, "JMP") == 0){
            printf("0b0110000000000000%s\n", targetCode); // Print opcode and targetCode for JMP .label
        } else if (strcmp(node->token.value, "JE") == 0) {
            printf("0b0110000100000000%s\n", targetCode); // Print opcode and targetCode for JE .label
        } else if(strcmp(node->token.value, "JNE") == 0) {
            printf("0b0110001000000000%s\n", targetCode); // Print opcode and targetCode for JNE .label
        } else if(strcmp(node->token.value, "JG") == 0) {
            printf("0b0110001100000000%s\n", targetCode); // Print opcode and targetCode for JG .label
        } else if(strcmp(node->token.value, "JGE") == 0) {
            printf("0b0110010000000000%s\n", targetCode); // Print opcode and targetCode for JGE .label
        } else if(strcmp(node->token.value, "JL") == 0) {
            printf("0b0110010100000000%s\n", targetCode); // Print opcode and targetCode for JL .label
        } else if(strcmp(node->token.value, "JLE") == 0) {
            printf("0b0110011000000000%s\n", targetCode); // Print opcode and targetCode for JLE .label
        }

        jmpLabelProcessed = 1; // Mark that we've processed a label as part of a JMP instruction
    } else if (strcmp(node->token.type, "LABEL") == 0 && !jmpLabelProcessed) {
        // Handle label if it hasn't been processed as part of a JMP
        char targetCode[33];
        memset(targetCode, 0, sizeof(targetCode));
        labelToMachineCode(node->token.value, targetCode);
        printf("0b1001100100000000%s\n", targetCode); // Print the machine code for the label
    } else if (strcmp(node->token.type, "INSTRUCTION") == 0) {
        char *opcode = NULL; // Will be set according to the instruction type
        char regCode[9], targetCode[33]; // For register and target (register or immediate) in binary
        memset(regCode, 0, sizeof(regCode));
        memset(targetCode, '0', sizeof(targetCode) - 1); // Initialize with '0's for 32 bits, leaving last byte for null terminator
        targetCode[32] = '\0'; // Ensure null termination

        // Determine the type of instruction and its arguments
        opcode = determineOpcode(node);
        int lastValue = determineLastValue(node);

        if (strcmp(node->token.value, "JMP") == 0 && node->numChildren > 0) {
            // Special handling for JMP instruction
            char targetCode[33];
            memset(targetCode, '0', sizeof(targetCode) - 1);
            targetCode[32] = '\0'; // Ensure null termination

            // Assume the label is in the first child of JMP instruction node
            labelToMachineCode(node->children[0]->token.value, targetCode);
            printf("0b%s%s\n", opcode, targetCode); // Print opcode and targetCode for JMP .label
        } else if (strcmp(node->token.value, "DISP") == 0 && strcmp(node->children[0]->token.type, "IMMEDIATE") == 0) {
            // For DISP IMMEDIATE, convert the immediate value to little endian binary directly
            intToLittleEndianBinary(lastValue, targetCode);
            printf("0b%s%s\n", opcode, targetCode); // Print opcode and targetCode for DISP IMMEDIATE
        } else {
            // For other instructions or DISP REGISTER, process normally
            if (node->numChildren > 0 && strcmp(node->children[0]->token.type, "REGISTER") == 0) {
                int regNum = atoi(&node->children[0]->token.value[1]); // Convert "Rn" to integer
                for (int i = 7; i >= 0; --i) {
                    regCode[i] = (regNum & 1) + '0';
                    regNum >>= 1;
                }
                regCode[8] = '\0'; // Ensure null termination
            }

            if (!(strcmp(node->token.value, "DISP") == 0 && strcmp(node->children[0]->token.type, "REGISTER") == 0)) {
                // Only convert the last value for non-DISP REGISTER instructions
                intToLittleEndianBinary(lastValue, targetCode); // Convert last token to little endian format
            }
            
            printf("0b%s%s%s\n", opcode, regCode, targetCode); // Print for instructions other than DISP IMMEDIATE
        }
    } else {
        // Reset the flag if the current node is not a JMP-targeted label
        jmpLabelProcessed = 0;
    } 

    // Recursively process children nodes
    for (int i = 0; i < node->numChildren; i++) {
        generateMachineCode(node->children[i]);
    }
}