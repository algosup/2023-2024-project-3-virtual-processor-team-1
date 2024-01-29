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

void tokenizeLine(char *line, char cleanedLines[][3][1000], int *numLines) {
    int inQuotedString = 0;
    int numTokens = 0;
    char token[1000] = "";

    if (line[0] == '\0' || (line[0] == '\n' && line[1] == '\0')) {
        // Skip empty lines
        return;
    }

    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == '"' && (i == 0 || line[i - 1] != '\\')) {
            // Toggle inQuotedString when an unescaped double quote is encountered
            inQuotedString = !inQuotedString;
        } else if (isspace(line[i]) && !inQuotedString) {
            // If space is encountered and not within quoted string, store token and reset
            strcpy(cleanedLines[*numLines][numTokens], token);
            memset(token, 0, sizeof(token));
            numTokens++;
        } else {
            // Append character to the current token
            strncat(token, &line[i], 1);
        }
    }

    // Store the last token
    strcpy(cleanedLines[*numLines][numTokens], token);

    // If inQuotedString is still set, store the entire quoted string as a single element
    if (inQuotedString) {
        strcpy(cleanedLines[*numLines][0], "");
        strcpy(cleanedLines[*numLines][1], "");
        strcpy(cleanedLines[*numLines][2], "");
        (*numLines)++;
    } else {
        // Increment numLines if there are tokens
        if (numTokens > 0) {
            (*numLines)++;
        }
    }
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
    char cleanedLines[100][3][1000]; // Adjust the size based on your needs
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
            printf("{\"%s\", \"%s\", \"%s\"}\n", cleanedLines[i][0], cleanedLines[i][1], cleanedLines[i][2]);
        }
    }

    return EXIT_SUCCESS;
}
