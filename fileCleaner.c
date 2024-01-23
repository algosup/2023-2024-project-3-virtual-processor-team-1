#include "header.h"

// Function to remove comments and empty lines from a given string
void removeCommentsAndEmptyLines(char *str) {
    int inCommentLine = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (inCommentLine) {
            if (str[i] == '\n' || str[i] == '\r') {
                inCommentLine = 0;
                str[i] = '\0';  // Terminate the string at the end of the comment line
            }
        } else {
            // Check if the current character is the start of a comment line (;), and if yes, change the line for a line without the comment
            if (str[i] == ';') {
                inCommentLine = 1;
                str[i] = '\n';
                str[i + 1] = '\0';  // Terminate the string at the end of the comment line
            }
        } 
    }
}


int main(int argc, char *argv[]) {
    // check if the user passed in a file name
    if (argc != 2) {
        printf("Error: Please pass in a file name\n");
        return 1;
    }

    // open the file
    FILE *file = fopen(argv[1], "r");
    // check if the file exists
    if (file == NULL) {
        printf("Error: File does not exist\n");
        return 1;
    }

    // Read the file line by line and remove comments and empty lines
    char line[1000]; // Adjust the size based on your needs
    char cleanedContent[10000]; // Adjust the size based on your needs
    cleanedContent[0] = '\0';

    while (fgets(line, sizeof(line), file)) {
        removeCommentsAndEmptyLines(line);
        if (line[0] != '\0' && line[0] != '\n' && line[0] != '\r') {
            strcat(cleanedContent, line);
        }
    }

    // Close the input file
    fclose(file);

    // Create a new file with the same extension and "Clean" appended to the name
    char *dot = strrchr(argv[1], '.');
    if (dot == NULL) {
        printf("Error: File has no extension\n");
        return 1;
    }

    // Create a new file name with "Clean" appended
    char newFileName[100];
    snprintf(newFileName, sizeof(newFileName), "%.*sClean%s", (int)(dot - argv[1]), argv[1], dot);

    // Open the new file for writing
    FILE *cleanedFile = fopen(newFileName, "w");
    if (cleanedFile == NULL) {
        printf("Error: Could not create the cleaned file\n");
        return 1;
    }

    // Write the cleaned content to the new file
    fprintf(cleanedFile, "%s", cleanedContent);

    // Close the new file
    fclose(cleanedFile);

    printf("File cleaned successfully. Cleaned file saved as: %s\n", newFileName);

    return 0;
}
