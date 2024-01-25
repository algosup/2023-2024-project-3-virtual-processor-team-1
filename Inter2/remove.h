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
#endif