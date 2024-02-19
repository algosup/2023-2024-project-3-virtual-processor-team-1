#include "global.h"



#if _WIN32
#include <windows.h>
#endif

#if _MACOS
#include <mach-o/dyld.h>
#endif

/*
Input:
{"MOV", "R1", "#5"}

Output:
{Token("instruction", "MOV", 1, 1), Token("register", "R1", 1, 2), Token("immediate", "#5", 1, 3)},
*/

int main(void)
{
    // DEBUG WIN32 PART
    #if _WIN32
    char path [MAX_PATH];
    if (GetModuleFileName(NULL, path, sizeof(path)) == 0) 
    {
        printf("Error: Could not get executable path\n");
        return 1;
    }
    char *lastSlash = strrchr(path, '\\');
    if (lastSlash != NULL) 
    {  // put here the name of the file you want to open 
       // in the same folder as the executable
    strcpy(lastSlash + 1, "machineCodeTest.asm2");
    } 
    else 
    {
    // Handle error: path does not contain a backslash
    }
    #endif
    // END WIN32 DEBUG PART
    // DEBUG MACOS PART
    #if _MACOS
        char path [MAX_PATH];
        uint32_t size = sizeof(path);
        if (_NSGetExecutablePath(path, &size) == 0)
        {
            printf("executable path is %s\n", path);
        }
        else
        {
            printf("buffer too small; need size %u\n", size);
        }
        char *lastSlash = strrchr(path, '/');
        if (lastSlash != NULL) 
        {  // put here the name of the file you want to open
        strcpy(lastSlash + 1, "test.asm2");
        } 
        else 
        {
        }
    #endif
    // END MACOS DEBUG PART
    FILE *file = fopen(path, "r");
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
    int numTokens = numLines * MAX_TOKENS;
    int numNode = numTokens;
    //astNode_t *root = buildAST(tokens, numLines * MAX_TOKENS);
    //printAST(root, 0);
    //syntaxCheck(root,0);
    //freeAST(root);
    int* machineCode = generateMachineCode(tokens, numTokens);
    printMachineCode(machineCode, numTokens);
    printBinary(machineCode, numTokens);
    free(machineCode);
    return 0;
}