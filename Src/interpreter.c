#include "global.h"

int error = 0; // Define error variable

void incrementError() {
    error++; // Increment error count
}

int main(int argc, char *argv[]) {

    // Check if a file name was passed as an argument to the program
    if (argc != 2) {
        printf("Error: Please pass in a file name\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: File does not exist\n");
        return 1;
    }

    // Check if the file is in the correct format (ends with .asm2)
    char *fileExtension = strrchr(argv[1], '.');
    if (fileExtension == NULL || strcmp(fileExtension, ".asm2") != 0) {
        printf("Error: File must have a .asm2 extension\n");
        return 1;
    }

    char lenghtLine[1000];
    char cleanedLines[100][3][1000];
    int numLines = 0;

    

    // Read the file line by line, clean each line, and tokenize each line
    int i = 0;
    while (fgets(lenghtLine, sizeof(lenghtLine), file)) {
        removeCommentsAndEmptyLines(lenghtLine);
        splitLine(lenghtLine, cleanedLines, &numLines);
    }

    fclose(file);

    token_t tokens[MAX_LINES * MAX_TOKENS];
    tokenizationFunction(cleanedLines, numLines, tokens);
    // printTokenization(tokens, numLines * MAX_TOKENS);

    // printf("\n");

    // Build the AST
    astNode_t *root = buildAST(tokens, numLines * MAX_TOKENS);
    //printAST(root, 0);

    syntaxCheck(root, 0);

    // If there is some errors, stop the access.
    if (error != 0) {
        if (error == 1) {
            printf("1 error generated\n");
        } else {
            printf("%d errors generated\n", error);
        }
        return EXIT_FAILURE;
    }

    int codeLength = 0; 

    // Define programInBinary as a 2D array of characters
    char programInBinary[numLines][MAX_PROGRAM_LENGTH];

    generateMachineCode(root, programInBinary, &codeLength);

    unsigned long long programInInt[numLines];

    // Convert each binary string to an unsigned long long and store it
    for (int i = 0; i < numLines; i++) {
        // Assuming binary strings are formatted as "0bXXXX", skip the first 2 characters ("0b")
        programInInt[i] = strtoull(&programInBinary[i][2], NULL, 2);
    }

    // Print the converted binary code as unsigned long long integers
    for (int i = 0; i < numLines; i++) {
        printf("%llu\n", programInInt[i]);
    }

    freeAST(root);
    return 0;
}