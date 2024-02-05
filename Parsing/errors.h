typedef enum errors {
    // General errors
    UNEXPECTED_ERROR = 0x00,

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

// File not found, line 1: print la ligne\n
