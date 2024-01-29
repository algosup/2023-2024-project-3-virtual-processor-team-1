#include "header.h"

int main(void) {
    // Check if the user passed in a file name
    char *arg = "C:/Users/SalaheddineNAMIR/Documents/GitHub/2023-2024-project-3-virtual-processor-team-1/Inter2/test.asm2";
    if (arg == NULL) {
        printf("Error: Please pass in a file name\n");
        return 1;
    }

    // Open the file
    FILE *file = fopen(arg, "r");
    // Check if the file exists
    if (file == NULL) {
        printf("Error: File does not exist\n");
        return 1;
    }
    
    // Read the file line by line and remove comments, empty lines, and newline characters
    char line[1000]; // Adjust the size based on your needs
    char cleanedLines[100][3][1000]; // Adjust the size based on your needs
    int numLines = 0;

    // Iterate over the file line by line to remove comments, empty lines, and newline characters
    while (fgets(line, sizeof(line), file)) {
        removeCommentsAndEmptyLines(line);
        tokenizeLine(line, cleanedLines, &numLines);
    }

    // Close the input file
    fclose(file);
    // Define the instruction structure
    instruction inst;
    output_t output;
    data dt;
    MixedType registers [3][3];
    int aregisters [3][3];
    setRegister(registers);
    setAregister(aregisters);
    // Print the cleaned content in the desired format
    for (int i = 0; i < numLines; i++) {
        // Check if the line is not empty before printing
        if (strcmp(cleanedLines[i][0], "") != 0) {
            printf("{\"%s\", \"%s\", \"%s\"}\n", cleanedLines[i][0], cleanedLines[i][1], cleanedLines[i][2]);
            setInstruction(inst, cleanedLines[i][0], cleanedLines[i][1], cleanedLines[i][2]);
            //interpreteInstruction(inst, output);
        }
    }
    
    //exucuteInstruction(inst, output);

    

    return EXIT_SUCCESS;
}
