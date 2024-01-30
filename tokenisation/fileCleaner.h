#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void removeCommentsAndEmptyLines(char *str) {

    /* 
    Pretty simple function that removes comments and empty lines to make
    parsing easier. It also removes trailing whitespace and newlines.

    ; = start of comment
    \n or \r = end of a line

    Small special case: if a line ends with a comment, the comment is
    removed and all trailing whitespace is removed. This is to make
    parsing easier.
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

void tokenizeLine(char *line, char cleanedLines[][3][1000], int *numLines) {

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
    while (line[i] == ' ' || line[i] == '\t') {
        i++;
    }

    if (line[i] == '\0' || (line[i] == '\n' && line[i + 1] == '\0')) {
        // Skip empty lines
        return;
    }

    for (; line[i] != '\0'; i++) {
        if (line[i] == '"' && (i == 0 || line[i - 1] != '\\')) {
            inQuotedString = !inQuotedString;
        } else if (isspace(line[i]) && !inQuotedString) {
            removeTrailingComma(token);
            strcpy(cleanedLines[*numLines][numTokens], token);
            memset(token, 0, sizeof(token));
            numTokens++;
        } else {
            strncat(token, &line[i], 1);
        }
    }

    removeTrailingComma(token);
    strcpy(cleanedLines[*numLines][numTokens], token);

    if (inQuotedString) {
        strcpy(cleanedLines[*numLines][0], "");
        strcpy(cleanedLines[*numLines][1], "");
        strcpy(cleanedLines[*numLines][2], "");
        (*numLines)++;
    } else {
        // Increment numLines even if there's only one token
        (*numLines)++;
    }
}
