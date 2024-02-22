#include "global.h"

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

    // Print out the cleaned lines
    // for (int i = 0; i < numLines; i++) {
    //     printf("%s \t %s \t %s \n", cleanedLines[i][0], cleanedLines[i][1], cleanedLines[i][2]);
    // }

    token_t tokens[MAX_LINES * MAX_TOKENS];
    tokenizationFunction(cleanedLines, numLines, tokens);
    printTokenization(tokens, numLines * MAX_TOKENS);

    // printf("\n");
    // Build the AST
    astNode_t *root = buildAST(tokens, numLines * MAX_TOKENS);
    // printAST(root, 0);
    syntaxCheck(root, 0);
    // generateMachineCode(root);
    freeAST(root);
    return 0;
}
