#define MAX_LINES 1000
#define MAX_TOKENS 3

typedef enum instruction
{
    ADD, 
    MOV,
    SUB, 
    MUL,
    DIV,
    JMP,
    JE,
    JNE,
    JG,
    JGE,
    JL,
    JLE,
    RET,
    CMP,
    CALL,
    AND,
    OR,
    XOR,
    NOT,
    GAD,
    DISP
} instruction_t;

typedef enum registers
{
    R1,
    R2,
    R3,
    R4,

} registers_t;

typedef enum address_registers
{
    A1,
    A2,
    A3,
    A4,

} address_registers_t;

typedef enum values
{
    IM,
    NE,
    STR

} values_t;

typedef union data
{
    instruction_t instruction;
    registers_t registers;
    address_registers_t address_registers;
    values_t values;
} data_t;

typedef enum typeofdata
{
    REGISTER,
    ADDRESS_REGISTER,
    INSTRUCTION,
    VALUE

} typeofdata_t;

typedef struct token {
    char type[20];    // String representation of the type
    char value[20];   // String representation of the value
    int row;          // Row number 
    int column;       // Column number
} token_t;


token_t tokens[MAX_LINES][MAX_TOKENS];
int column = 0;
int row = 0;

void getEnum(char cleanedLines[1000], token_t *token) {
    // Instructions
    if (strcmp(cleanedLines, "MOV") == 0) {
        strcpy(token->type, "instruction");
        strcpy(token->value, "MOV");
    } else if (strcmp(cleanedLines, "ADD") == 0) {
        strcpy(token->type, "instruction");
        strcpy(token->value, "ADD");
    } else if (strcmp(cleanedLines, "SUB") == 0) {
        strcpy(token->type, "instruction");
        strcpy(token->value, "SUB");
    } else if (strcmp(cleanedLines, "MUL") == 0) {
        strcpy(token->type, "instruction");
        strcpy(token->value, "MUL");
    } else if (strcmp(cleanedLines, "DIV") == 0) {
        strcpy(token->type, "instruction");
        strcpy(token->value, "DIV");
    } else if (strcmp(cleanedLines, "JMP") == 0) {
        strcpy(token->type, "instruction");
        strcpy(token->value, "JMP");
    } else if (strcmp(cleanedLines, "JE") == 0) {
        strcpy(token->type, "instruction");
        strcpy(token->value, "JE");
    } else if (strcmp(cleanedLines, "JNE") == 0) {
        strcpy(token->type, "instruction");
        strcpy(token->value, "JNE");
    } else if (strcmp(cleanedLines, "JG") == 0) {
        strcpy(token->type, "instruction");
        strcpy(token->value, "JG");
    } else if (strcmp(cleanedLines, "JGE") == 0) {
        strcpy(token->type, "instruction");
        strcpy(token->value, "JGE");
    } else if (strcmp(cleanedLines, "JL") == 0) {
        strcpy(token->type, "instruction");
        strcpy(token->value, "JL");
    } else if (strcmp(cleanedLines, "JLE") == 0) {
        strcpy(token->type, "instruction");
        strcpy(token->value, "JLE");
    } else if (strcmp(cleanedLines, "RET") == 0) {
        strcpy(token->type, "instruction");
        strcpy(token->value, "RET");
    } else if (strcmp(cleanedLines, "CMP") == 0) {
        strcpy(token->type, "instruction");
        strcpy(token->value, "CMP");
    } else if (strcmp(cleanedLines, "CALL") == 0) {
        strcpy(token->type, "instruction");
        strcpy(token->value, "CALL");
    } else if (strcmp(cleanedLines, "AND") == 0) {
        strcpy(token->type, "instruction");
        strcpy(token->value, "AND");
    } else if (strcmp(cleanedLines, "OR") == 0) {
        strcpy(token->type, "instruction");
        strcpy(token->value, "OR");
    } else if (strcmp(cleanedLines, "XOR") == 0) {
        strcpy(token->type, "instruction");
        strcpy(token->value, "XOR");
    } else if (strcmp(cleanedLines, "NOT") == 0) {
        strcpy(token->type, "instruction");
        strcpy(token->value, "NOT");
    } else if (strcmp(cleanedLines, "GAD") == 0) {
        strcpy(token->type, "instruction");
        strcpy(token->value, "GAD");
    } else if (strcmp(cleanedLines, "DISP") == 0) {
        strcpy(token->type, "instruction");
        strcpy(token->value, "DISP");
    } 
    else if (strcmp(cleanedLines, "R1") == 0) {
        strcpy(token->type, "register");
        strcpy(token->value, "R1");
    } else if (strcmp(cleanedLines, "R2") == 0) {
        strcpy(token->type, "register");
        strcpy(token->value, "R2");
    } else if (strcmp(cleanedLines, "R3") == 0) {
        strcpy(token->type, "register");
        strcpy(token->value, "R3");
    } else if (strcmp(cleanedLines, "R4") == 0) {
        strcpy(token->type, "register");
        strcpy(token->value, "R4");
    } else if (strcmp(cleanedLines, "A1") == 0) {
        strcpy(token->type, "address_register");
        strcpy(token->value, "A1");
    } else if (strcmp(cleanedLines, "A2") == 0) {
        strcpy(token->type, "address_register");
        strcpy(token->value, "A2");
    } else if (strcmp(cleanedLines, "A3") == 0) {
        strcpy(token->type, "address_register");
        strcpy(token->value, "A3");
    } else if (strcmp(cleanedLines, "A4") == 0) {
        strcpy(token->type, "address_register");
        strcpy(token->value, "A4");
    } else if (cleanedLines[0] == '-') {
        strcpy(token->type, "NE");
        strcpy(token->value, cleanedLines);
    } else if (cleanedLines[0] == '"') {
        strcpy(token->type, "STR");
        strcpy(token->value, cleanedLines);
    }
    else if (cleanedLines[0] == '#') {
        strcpy(token->type, "immediate");
        strcpy(token->value, cleanedLines);
    }

    // Default case if none matched
    else {
        strcpy(token->type, "void");
        strcpy(token->value, "void");
    }
}



// Output:
// {Token("instruction", "MOV", 1, 1), Token("register", "R1", 1, 2), Token("immediate", "#5", 1, 3)}
void tokenizationFunction(char cleanedLines[][3][1000], int numLines, token_t *tokens) {
    int tokenIndex = 0;
    for(int i = 0; i < numLines; i++){
        for(int c = 0; c < 3; c++){
            tokens[tokenIndex].row = i +1;
            tokens[tokenIndex].column = c +1;
            getEnum(cleanedLines[i][c], &tokens[tokenIndex]);
            tokenIndex++;
        }
    }
}

void printTokenization(token_t *tokens, int numTokens){
    for (int i = 0; i < numTokens; i++){
            printf("Token(\"%s\", \"%s\", %d, %d)", tokens[i].type, tokens[i].value, tokens[i].row, tokens[i].column);
            if (i % MAX_TOKENS < MAX_TOKENS - 1){
                printf(", ");
            }
            else{
                printf("\n");
            }
    }
}