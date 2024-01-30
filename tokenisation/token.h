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

typedef struct token
{
    typeofdata_t type; // register, operator, address register, value
    typeofdata_t parameter; // parameter of the token (register, operator, address register, value)
    int row; // row number 
    int column; // column number

}token_t;

int column = 0;
int row = 0;

void getEnum(char cleanedLines[1000], token_t *token){      // This function permitte to find the type of instruction
    if (strcmp(cleanedLines, "MOV") == 0){
        token->type = INSTRUCTION;
        token->parameter = MOV;
    } else {
        token->type = VALUE;
        token->parameter = A1;
    }
}

// Output:
// {Token("instruction", "MOV", 1, 1), Token("register", "R1", 1, 2), Token("immediate", "#5", 1, 3)}
void tokenizationFunction(char cleanedLines[][3][1000], int numLines){
    for(int i = 0; i < numLines; i++){
        int stockedFirstType;
        int stockedFirstParameter;
        int stockedSecondType;
        int stockedSecondParameter;
        int stockedThirdType;
        int stockedThirdParameter;
        for(int c = 0; c < 3; c++){
            switch(c){
                token_t token;
                case 0:  
                    token.row = i;
                    token.column = c;
                    getEnum(cleanedLines[c][i], &token);
                    stockedFirstType = token.type;
                    stockedFirstParameter = token.parameter;
                    break;
                case 1:
                    token.row = i;
                    token.column = c;
                    getEnum(cleanedLines[c][i], &token);
                    stockedSecondType = token.type;
                    stockedSecondParameter = token.parameter;
                    break;
                case 2:
                    token.row = i;
                    token.column = c;
                    getEnum(cleanedLines[c][i], &token);
                    stockedThirdType = token.type;
                    stockedThirdParameter = token.parameter;
                    break;
                default:
                    printf("ERROR");
                    break;
            }
            // printf("Line %d\nColumn %d\nType %d\nParameter %d\n\n", token.row, token.column, token.type, token.parameter);
        }
        printf("1. Type %d\nParameter %d", stockedFirstType, stockedFirstParameter);
        printf("\n2. Type %d\nParameter %d", stockedSecondType, stockedSecondParameter);
        printf("\n3. Type %d\nParameter %d", stockedThirdType, stockedThirdParameter);
    }
}