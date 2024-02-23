#include <stdio.h>

typedef enum errors {
    // Errors related to file reading
    FILE_NOT_FOUND = 0x01,
    FILE_SECURED_WITH_PASSWORD = 0x02,
    INCORRECT_FILE_EXTENSION = 0x03,
    FILE_CORRUPTED = 0x04,
    EMPTY_FILE = 0x05,

    // Errors related to parsing
    UNKNOWN_INSTRUCTION_OR_OPERATOR = 0xA0,
    UNKNOWN_VARIABLE_OR_REGISTER = 0xA1,
    UNKNOWN_FUNCTION_OR_SUBROUTINE = 0xA2,

    // Errors related to syntax
    UNEXPECTED_CHARACTER = 0xB0,

    // Errors related to execution
    SYNTAX_ERROR = 0xC0,
    MISSING_END_OR_RETURN = 0xC1,
    DIVISION_BY_ZERO = 0xC2,
    FLOAT_NUMBER = 0xC3,

    // Errors related to memory
    OVERFLOW_ERROR = 0xD0,
} errors_t;

void printErrorMessage(errors_t errorCode, int lineNumber, const char* codeOnLine) {
    const char* errorMessage;
    char formattedMessage[256]; // Adjust the size as needed

    switch (errorCode) {
        case FILE_NOT_FOUND:
            errorMessage = "The file was not found. Check the name and/or directory in which the file is located.";
            break;
        case FILE_SECURED_WITH_PASSWORD:
            errorMessage = "Unable to access the file, which is password-protected";
            break;
        case INCORRECT_FILE_EXTENSION:
            errorMessage = "The file you are trying to open is not a recognised file.";
            break;
        case FILE_CORRUPTED:
            errorMessage = "The file you are trying to open appears to be corrupted.";
            break;
        case EMPTY_FILE:
            errorMessage = "The file you are trying to open contains no data.";
            break;
        case UNKNOWN_INSTRUCTION_OR_OPERATOR:
            sprintf(formattedMessage, "The operator or instruction does not exist in line %d: \n\t -> %s", lineNumber, codeOnLine);
            errorMessage = formattedMessage;
            break;
        case UNKNOWN_VARIABLE_OR_REGISTER:
            sprintf(formattedMessage, "The function or subroutine you are trying to CALL does not exist in line %d: \n\t -> %s", lineNumber, codeOnLine);
            errorMessage = formattedMessage;
            break;
        case UNKNOWN_FUNCTION_OR_SUBROUTINE:
            sprintf(formattedMessage, "The function or subroutine you are trying to CALL does not exist in line %d: \n\t -> %s", lineNumber, codeOnLine);
            errorMessage = formattedMessage;
            break;
        case UNEXPECTED_CHARACTER:
            sprintf(formattedMessage, "An unexpected character was spotted on the line in line %d: \n\t -> %s", lineNumber, codeOnLine);
            errorMessage = formattedMessage;
            break;
        case SYNTAX_ERROR:
            sprintf(formattedMessage, "Too many parameters have been added. Syntax should be : ARGUMENT PARAM1, PARAM2 %d: \n\t -> %s", lineNumber, codeOnLine);
            errorMessage = formattedMessage;
            break;
        case MISSING_END_OR_RETURN:
            errorMessage = "An END or RET instruction is missing from the program.";
            break;
        case DIVISION_BY_ZERO:
            sprintf(formattedMessage, "It is impossible to divide by 0, check the operation in line %d: \n\t -> %s", lineNumber, codeOnLine);
            errorMessage = formattedMessage;
            break;
        case FLOAT_NUMBER:
            sprintf(formattedMessage, "The language does not take floats into account, check the number in line %d: \n\t -> %s", lineNumber, codeOnLine);
            errorMessage = formattedMessage;
            break;
        case OVERFLOW_ERROR:
            errorMessage = "The programme was halted due to an overflow.";
            break;
        default:
            errorMessage = "An unknown error has occurred. Go to GitHub Issues to report it.";
            break;
    }

    printf("Error: %d\n", errorCode);
    printf("Message: %s\n", errorMessage);
}

int main() {
    printErrorMessage(FILE_NOT_FOUND, 0, "test");
    printErrorMessage(FILE_SECURED_WITH_PASSWORD, 0, "test");
    printErrorMessage(INCORRECT_FILE_EXTENSION, 0, "test");
    printErrorMessage(FILE_CORRUPTED, 0, "test");
    printErrorMessage(EMPTY_FILE, 0, "test");
    printErrorMessage(UNKNOWN_INSTRUCTION_OR_OPERATOR, 0, "test");
    printErrorMessage(UNKNOWN_VARIABLE_OR_REGISTER, 0, "test");
    printErrorMessage(UNKNOWN_FUNCTION_OR_SUBROUTINE, 0, "test");
    printErrorMessage(UNEXPECTED_CHARACTER, 0, "test");
    printErrorMessage(SYNTAX_ERROR, 0, "test");
    printErrorMessage(MISSING_END_OR_RETURN, 0, "test");
    printErrorMessage(DIVISION_BY_ZERO, 0, "test");
    printErrorMessage(FLOAT_NUMBER, 0, "test");
    printErrorMessage(OVERFLOW_ERROR, 0, "test");
    return 0;
}
