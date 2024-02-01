#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void removeCommentsAndEmptyLines(char *str) {

    /* 
    Removes comments and empty lines from a line.
    */

    int inCommentLine = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (inCommentLine) {
            if (str[i] == '\n' || str[i] == '\r') {
                inCommentLine = 0;
                str[i] = '\0';
            }
        } else {
            if (str[i] == ';') {
                inCommentLine = 1;
                while (i > 0 && isblank(str[i - 1])) {
                    i--;
                }
                str[i] = '\0';
            } else if (str[i] == '\n' || str[i] == '\r') {
                str[i] = ' ';
            }
        }
    }
}

void removeTrailingComma(char *token) {

    /*
    Removes trailing commas from tokens. This is necessary because the
    tokenizer will treat "hello," and "hello" as two different tokens.

    This function is called after the tokenizer has finished tokenizing
    a line.
    */

    int length = strlen(token);
    while (length > 0 && token[length - 1] == ',') {
        token[length - 1] = '\0';
        length--;
    }
}

void splitLine(char *lengthLine, char cleanedLines[][3][1000], int *numLines) {

    /*
    Tokenizes a line. This function is called after the line has been
    cleaned of comments and empty lines.

    Each line is tokenized into three tokens. If there are less than
    three tokens, the remaining tokens are set to empty strings.
    */

    int inQuotedString = 0;
    int numTokens = 0;
    char token[1000] = "";

    int i = 0;
    while (lengthLine[i] == ' ' || lengthLine[i] == '\t') {
        i++;
    }

    // Check for empty lines
    if (lengthLine[i] == '\0' || (lengthLine[i] == '\n' && lengthLine[i + 1] == '\0')) {
        // Add an empty line to cleanedLines
        strcpy(cleanedLines[*numLines][0], "");
        strcpy(cleanedLines[*numLines][1], "");
        strcpy(cleanedLines[*numLines][2], "");
        (*numLines)++;
        return;
    }

    for (; lengthLine[i] != '\0'; i++) {
        if (lengthLine[i] == '"' && (i == 0 || lengthLine[i - 1] != '\\')) {
            inQuotedString = !inQuotedString;
            strncat(token, &lengthLine[i], 1);
        } else if (isspace(lengthLine[i]) && !inQuotedString) {
            removeTrailingComma(token);
            strcpy(cleanedLines[*numLines][numTokens], token);
            memset(token, 0, sizeof(token));
            numTokens++;
        } else {
            strncat(token, &lengthLine[i], 1);
        }
    }

    removeTrailingComma(token);
    strcpy(cleanedLines[*numLines][numTokens], token);

    if (inQuotedString) {
        // Reset tokens if the line ends with an open quote
        strcpy(cleanedLines[*numLines][0], "");
        strcpy(cleanedLines[*numLines][1], "");
        strcpy(cleanedLines[*numLines][2], "");
    }

    // Increment numLines even if there's only one token
    (*numLines)++;
}
