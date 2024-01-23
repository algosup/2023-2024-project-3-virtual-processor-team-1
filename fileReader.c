#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    // Open the file for reading
    FILE *file = fopen("test.algoasm", "r");
    
    // Check if the file was opened successfully
    if (file == NULL) {
        perror("Error opening file");
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
