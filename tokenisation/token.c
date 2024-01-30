#include "fileCleaner.h"
#include "token.h"

/*
Input:
{"MOV", "R1", "#5"}

Output:
{Token("instruction", "MOV", 1, 1), Token("register", "R1", 1, 2), Token("immediate", "#5", 1, 3)},
*/

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

    char line[1000];
    char cleanedLines[100][3][1000];
    int numLines = 0;

    // Read the file line by line, clean each line, and tokenize each line
    int i = 0;
    while (fgets(line, sizeof(line), file)) {
        removeCommentsAndEmptyLines(line);
        splitLine(line, cleanedLines, &numLines);
    }

    fclose(file);

    // Print out the cleaned lines
    for (int i = 0; i < numLines; i++) {
        printf("%s \t %s \t %s \n", cleanedLines[i][0], cleanedLines[i][1], cleanedLines[i][2]);
    }

    return 0;
}