char* remove_char(char* str, char to_remove) {
    char* src;
    char* dst;
    for (src = dst = str; *src != '\0'; src++) {
        *dst = *src;
        if (*dst != to_remove) dst++;
    }
    *dst = '\0';
    return str;
}

int* generateMachineCode(token_t *assemblyCode, int numTokens)
{
    // allocate memory for the machine code
    int *machineCode = (int *)malloc(sizeof(int) * (numTokens));
    // match token with the instruction set
    // token{type, value, line, column}
    int smc = 0; // set machine code --> {INSTRUCTION_MOV1, REGISTER_1, IMMEDIATE}
                 //       smc=                0 ,                1 ,          2
    // for each line
    for(int i = 0; i < numTokens; i++)
    {
        // token is MOV REGISTER, IMMEDIATE
        if (strcmp(assemblyCode[i].value,"MOV")==0
            && strcmp(assemblyCode[i+2].type,"IMMEDIATE")==0) 
        {
            // match the instruction
            machineCode[smc] = 0x10; // INSTRUCTION_MOV1
            // match the register
            if(strcmp(assemblyCode[i+1].value,"R1")==0)
            {
                machineCode[smc+1] = 0x01; // REGISTER_1
            }
            else if(strcmp(assemblyCode[i+1].value,"R2")==0)
            {
                machineCode[smc+1] = 0x02; // REGISTER_2
            }
            else if(strcmp(assemblyCode[i+1].value,"R3")==0)
            {
                machineCode[smc+1] = 0x03; // REGISTER_3
            }
            else if(strcmp(assemblyCode[i+1].value,"R4")==0)
            {
                machineCode[smc+1] = 0x04; // REGISTER_4
            }
            // match the immediate
            char* removeHash = remove_char(assemblyCode[i+2].value,'#');
            machineCode[smc+2] = atoi(removeHash);
        }
        
        // go to the next token line
        smc=+3;
    }

    // generate the machine code

    // return the machine code
    return machineCode;
}

void printMachineCode(int *machineCode, int numTokens)
{
    for(int i = 0; i < numTokens; i++)
    {
        printf("%d\n", machineCode[i]);
    }
}

// convert int to binary 
int binary(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    return (n % 2) + 10 * binary(n / 2);
}

// convert the machine code to binary
char** generateBinary(int *machineCode, int numTokens)
{
    // Allocate memory for the array of strings
    char **binaryStrings = malloc(numTokens * sizeof(char*));

    for(int i = 0; i < numTokens; i+=3)
    {
        // Allocate memory for each string
        binaryStrings[i] = malloc(49 * sizeof(char));  // 16 digits * 3 + 2 for "0B" + 1 for '\0'

        // Generate the binary string
        sprintf(binaryStrings[i], "0B%016d%016d%016d", binary(machineCode[i]), binary(machineCode[i+1]), binary(machineCode[i+2]));
    }

    return binaryStrings;
}







