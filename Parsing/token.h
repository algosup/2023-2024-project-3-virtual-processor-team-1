#ifndef TOKEN_H
#define TOKEN_H
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
    DISP,
    END
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
    char value[100];   // String representation of the value
    int row;          // Row number 
    int column;       // Column number
} token_t;


token_t tokens[MAX_LINES][MAX_TOKENS];
int column = 0;
int row = 0;

void handleString(char *source, char *destination){
    int length = strlen(source);
    if (length > 98){
        printf("Error: String too long\n");
        strcpy(destination, "ERREUR");
        return;
    }
    int j = 0;
    for(int i = 1; i < length - 1; i++){
        if (source[i] == '\\'){
            i++;
            switch (source[i])
            {
            case 'n':
                destination[j] = '\n';
                break;
            case 't':
                destination[j] = '\t';
                break;
            case 'r':
                destination[j] = '\r';
                break;
            case '0':
                destination[j] = '\0';
                break;
            case '\\':
                destination[j] = '\\';
                break;
            case '"':
                destination[j] = '"';
                break;
            default:
                printf("Error: Invalid escape sequence\n");
                strcpy(destination, "ERREUR");
                return;
            }
        } else {
            destination[j] = source[i];
        }
        j++; // Incrémentation de j
    }
    destination[j] = '\0';
}


void getEnum(char cleanedLines[1000], token_t *token) {
    // Instructions
    if (strcmp(cleanedLines, "MOV") == 0) {
        strcpy(token->type, "INSTRUCTION");
        strcpy(token->value, "MOV");
    } else if (strcmp(cleanedLines, "ADD") == 0) {
        strcpy(token->type, "INSTRUCTION");
        strcpy(token->value, "ADD");
    } else if (strcmp(cleanedLines, "SUB") == 0) {
        strcpy(token->type, "INSTRUCTION");
        strcpy(token->value, "SUB");
    } else if (strcmp(cleanedLines, "MUL") == 0) {
        strcpy(token->type, "INSTRUCTION");
        strcpy(token->value, "MUL");
    } else if (strcmp(cleanedLines, "DIV") == 0) {
        strcpy(token->type, "INSTRUCTION");
        strcpy(token->value, "DIV");
    } else if (strcmp(cleanedLines, "JMP") == 0) {
        strcpy(token->type, "INSTRUCTION");
        strcpy(token->value, "JMP");
    } else if (strcmp(cleanedLines, "JE") == 0) {
        strcpy(token->type, "INSTRUCTION");
        strcpy(token->value, "JE");
    } else if (strcmp(cleanedLines, "JNE") == 0) {
        strcpy(token->type, "INSTRUCTION");
        strcpy(token->value, "JNE");
    } else if (strcmp(cleanedLines, "JG") == 0) {
        strcpy(token->type, "INSTRUCTION");
        strcpy(token->value, "JG");
    } else if (strcmp(cleanedLines, "JGE") == 0) {
        strcpy(token->type, "INSTRUCTION");
        strcpy(token->value, "JGE");
    } else if (strcmp(cleanedLines, "JL") == 0) {
        strcpy(token->type, "INSTRUCTION");
        strcpy(token->value, "JL");
    } else if (strcmp(cleanedLines, "JLE") == 0) {
        strcpy(token->type, "INSTRUCTION");
        strcpy(token->value, "JLE");
    } else if (strcmp(cleanedLines, "RET") == 0) {
        strcpy(token->type, "INSTRUCTION");
        strcpy(token->value, "RET");
    } else if (strcmp(cleanedLines, "CMP") == 0) {
        strcpy(token->type, "INSTRUCTION");
        strcpy(token->value, "CMP");
    } else if (strcmp(cleanedLines, "CALL") == 0) {
        strcpy(token->type, "INSTRUCTION");
        strcpy(token->value, "CALL");
    } else if (strcmp(cleanedLines, "AND") == 0) {
        strcpy(token->type, "INSTRUCTION");
        strcpy(token->value, "AND");
    } else if (strcmp(cleanedLines, "OR") == 0) {
        strcpy(token->type, "INSTRUCTION");
        strcpy(token->value, "OR");
    } else if (strcmp(cleanedLines, "XOR") == 0) {
        strcpy(token->type, "INSTRUCTION");
        strcpy(token->value, "XOR");
    } else if (strcmp(cleanedLines, "NOT") == 0) {
        strcpy(token->type, "INSTRUCTION");
        strcpy(token->value, "NOT");
    } else if (strcmp(cleanedLines, "GAD") == 0) {
        strcpy(token->type, "INSTRUCTION");
        strcpy(token->value, "GAD");
    } else if (strcmp(cleanedLines, "DISP") == 0) {
        strcpy(token->type, "INSTRUCTION");
        strcpy(token->value, "DISP");
    } else if(strcmp(cleanedLines, "END") == 0){
        strcpy(token->type, "INSTRUCTION");
        strcpy(token->value, "END");
    }
    else if (strcmp(cleanedLines, "R1") == 0) {
        strcpy(token->type, "REGISTER");
        strcpy(token->value, "R1");
    } else if (strcmp(cleanedLines, "R2") == 0) {
        strcpy(token->type, "REGISTER");
        strcpy(token->value, "R2");
    } else if (strcmp(cleanedLines, "R3") == 0) {
        strcpy(token->type, "REGISTER");
        strcpy(token->value, "R3");
    } else if (strcmp(cleanedLines, "R4") == 0) {
        strcpy(token->type, "REGISTER");
        strcpy(token->value, "R4");
    } else if (strcmp(cleanedLines, "A1") == 0) {
        strcpy(token->type, "ADDRESS_REGISTER");
        strcpy(token->value, "A1");
    } else if (strcmp(cleanedLines, "A2") == 0) {
        strcpy(token->type, "ADDRESS_REGISTER");
        strcpy(token->value, "A2");
    } else if (strcmp(cleanedLines, "A3") == 0) {
        strcpy(token->type, "ADDRESS_REGISTER");
        strcpy(token->value, "A3");
    } else if (strcmp(cleanedLines, "A4") == 0) {
        strcpy(token->type, "ADDRESS_REGISTER");
        strcpy(token->value, "A4");
    } else if (cleanedLines[0] == '-') {
        strcpy(token->type, "NE");
        strcpy(token->value, cleanedLines);
    } else if (cleanedLines[0] == '"') {
        strcpy(token->type, "STR");
        handleString(cleanedLines, token->value);
    }
    else if (cleanedLines[0] == '#') {
        strcpy(token->type, "IMMEDIATE");
        strcpy(token->value, cleanedLines);
    }
    // Default case if none matched
    else {
        strcpy(token->type, "VOID");
        strcpy(token->value, "VOID");
    }
}



// Output:
// {Token("instruction", "MOV", 1, 1), Token("register", "R1", 1, 2), Token("immediate", "#5", 1, 3)}
void tokenizationFunction(char cleanedLines[][3][1000], int numLines, token_t *tokens) {
    int tokenIndex = 0;
    for(int i = 0; i < numLines; i++){
        // Vérifier si le premier token de la ligne est "VOID"
        if (strcmp(cleanedLines[i][0], "VOID") == 0) {
            continue;
        }
        for(int c = 0; c < 3; c++){
            tokens[tokenIndex].row = i + 1;
            tokens[tokenIndex].column = c + 1;
            getEnum(cleanedLines[i][c], &tokens[tokenIndex]);
            tokenIndex++;
        }
    }
}

void printTokenization(token_t *tokens, int numTokens) {
    for (int i = 0; i < numTokens; i += MAX_TOKENS) {
        bool allVoid = true;
        for (int j = 0; j < MAX_TOKENS; j++) {
            if (strcmp(tokens[i + j].type, "VOID") != 0) {
                allVoid = false;
                break;
            }
        }

        if (!allVoid) {
            for (int j = 0; j < MAX_TOKENS; j++) {
                printf("Token(\"%s\", \"%s\", %d, %d)", tokens[i + j].type, tokens[i + j].value, tokens[i + j].row, tokens[i + j].column);
                if (j < MAX_TOKENS - 1) {
                    printf(", ");
                }
            }
            printf("\n");
        }
    }
}
#endif