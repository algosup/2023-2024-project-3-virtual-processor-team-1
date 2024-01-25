#include "../NotWorking/header.h"

// Function to remove comments, empty lines, and newline characters from a given string
// This function modifies the input string in-place.
void removeCommentsAndEmptyLines(char *str) {
    int inCommentLine = 0;

    // Iterate over the string and remove comments, empty lines, and newline characters
    for (int i = 0; str[i] != '\0'; i++) {
        if (inCommentLine) {
            // Inside a comment, look for newline characters to end the comment
            if (str[i] == '\n' || str[i] == '\r') {
                inCommentLine = 0;
                str[i] = '\0';  // Terminate the string at the end of the comment line
            }
        } else {
            // Check if the current character is the start of a comment line (;)
            if (str[i] == ';') {
                inCommentLine = 1;
                // Trim trailing whitespace before the comment marker
                while (i > 0 && isblank(str[i - 1])) {
                    i--;
                }
                str[i] = '\0';  // Terminate the string at the end of the comment line
            } else if (str[i] == '\n' || str[i] == '\r') {
                str[i] = ' ';  // Replace newline characters with space
            }
        }
    }
}

// Function to tokenize a line based on spaces and commas
// This function tokenizes the input line and stores the tokens in a 2D array.
void tokenizeLine(char *line, char cleanedLines[][4][1000], int *numLines) {
    const char delimiters[] = " ,";
    int numTokens = 0;

    // Tokenize the line only if it is not empty
    if (line[0] == '\0' || line[0] == '\n' || line[0] == '\r') {
        return;
    }

    // Tokenize the line and store each token in the 2D array
    char *token = strtok(line, delimiters);
    while (token != NULL && numTokens < 4) {
        strcpy(cleanedLines[*numLines][numTokens], token);
        numTokens++;
        token = strtok(NULL, delimiters);
    }

    // If fewer than 4 tokens are found, pad the remaining elements with empty strings
    while (numTokens < 4) {
        strcpy(cleanedLines[*numLines][numTokens], "");
        numTokens++;
    }

    (*numLines)++;
}

int main(int argc, char *argv[]) {
    // Check if the user passed in a file name
    if (argc != 2) {
        printf("Error: Please pass in a file name\n");
        return 1;
    }

    // Open the file
    FILE *file = fopen(argv[1], "r");
    // Check if the file exists
    if (file == NULL) {
        printf("Error: File does not exist\n");
        return 1;
    }

    // Read the file line by line and remove comments, empty lines, and newline characters
    char line[1000]; // Adjust the size based on your needs
    char cleanedLines[100][4][1000]; // Adjust the size based on your needs
    int numLines = 0;

    // Iterate over the file line by line to remove comments, empty lines, and newline characters
    while (fgets(line, sizeof(line), file)) {
        removeCommentsAndEmptyLines(line);
        tokenizeLine(line, cleanedLines, &numLines);
    }

    // Close the input file
    fclose(file);

    // Print the cleaned content in the desired format
    for (int i = 0; i < numLines; i++) {
        // Check if the line is not empty before printing
        if (strcmp(cleanedLines[i][0], "") != 0) {
            printf("{\"%s\", \"%s\", \"%s\", \"%s\"}\n", cleanedLines[i][0], cleanedLines[i][1], cleanedLines[i][2], cleanedLines[i][3]);
        }
    }

    return EXIT_SUCCESS;
}
