#ifndef REMOVE_H
#define REMOVE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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
    const char delimiters[] = ", ";
    int numTokens = 0;

    // Tokenize the line only if it is not empty
    if (line[0] == '\0' || line[0] == '\n' || line[0] == '\r') {
        return;
    }

    // Tokenize the line and store each token in the 2D array
    char *token = strtok(line, delimiters);
    while (token != NULL && numTokens < 3) {
        strcpy(cleanedLines[*numLines][numTokens], token);
        numTokens++;
        token = strtok(NULL, delimiters);
    }

    // If fewer than 3 tokens are found, pad the remaining elements with empty strings
    while (numTokens < 3) {
        strcpy(cleanedLines[*numLines][numTokens], "");
        numTokens++;
    }
    (*numLines)++;
}
#endif