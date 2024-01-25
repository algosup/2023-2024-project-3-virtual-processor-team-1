#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


    // Count the number of lines in the file and print the content
    int line_count = 0;
    char buffer[256]; // Adjust the buffer size as needed

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        line_count++;
        printf("Line %d: %s", line_count, buffer);
    }

    // Close the file
    fclose(file);

    // Print the total number of lines
    printf("Number of lines in the file: %d\n", line_count);

    return 0;
}
