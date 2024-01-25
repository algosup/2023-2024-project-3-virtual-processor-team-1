#ifndef TOKENLINE_H
#define TOKENLINE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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